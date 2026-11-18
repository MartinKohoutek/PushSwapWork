/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 07:31:22 by marti             #+#    #+#             */
/*   Updated: 2026/11/18 08:41:39 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "stack.h"
#include "sorting.h"

static int	lis(t_stack *a, int *incsub_len, int *prev)
{
	size_t	i;
	size_t	j;
	int		best_i;

	i = 0;
	best_i = 0;
	while (i < a->size)
	{
		incsub_len[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (a->arr[j] < a->arr[i] && incsub_len[j] + 1 > incsub_len[i])
			{
				incsub_len[i] = incsub_len[j] + 1;
				prev[i] = (int)j;
			}
			j++;
		}
		if (incsub_len[i] > incsub_len[best_i])
			best_i = (int)i;
		i++;
	}
	return (best_i);
}

int	mark_lis(t_stack *a, int *keep)
{
	int	*incsub_len;
	int	*prev;
	int	best_i;

	incsub_len = malloc(sizeof(int) * a->size);
	prev = malloc(sizeof(int) * a->size);
	if (!incsub_len || !prev)
	{
		free(incsub_len);
		free(prev);
		return (0);
	}
	best_i = lis(a, incsub_len, prev);
	while (best_i >= 0)
	{
		keep[a->arr[best_i]] = 1;
		best_i = prev[best_i];
	}
	free(incsub_len);
	free(prev);
	return (1);
}

static int	prepare_lis(t_context *ctx, int **keep)
{
	size_t	i;

	*keep = malloc(sizeof(int) * ctx->a.size);
	if (!*keep)
	{
		ctx->ops_error = 1;
		return (0);
	}
	i = 0;
	while (i < ctx->a.size)
		(*keep)[i++] = 0;
	if (!mark_lis(&ctx->a, *keep))
	{
		free(*keep);
		*keep = NULL;
		ctx->ops_error = 1;
		return (0);
	}
	push_non_lis_to_b(ctx, *keep);
	free(*keep);
	*keep = NULL;
	return (!ctx->ops_error);
}

static void	insert_all(t_context *ctx)
{
	while (ctx->b.size > 0 && !ctx->ops_error)
		prepare_and_pa(ctx, best_pos_b(ctx));
}

void	sort_simple(t_context *ctx)
{
	int	*keep;

	if (is_sorted(&ctx->a))
		return ;
	if (ctx->a.size <= 5)
	{
		sort_small(ctx);
		return ;
	}
	if (!prepare_lis(ctx, &keep))
		return ;
	insert_all(ctx);
	if (!ctx->ops_error)
		rotate_min_top(ctx);
}
