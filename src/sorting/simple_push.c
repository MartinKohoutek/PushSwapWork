/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 07:35:11 by marti             #+#    #+#             */
/*   Updated: 2026/11/18 08:02:30 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "types.h"
#include "operations.h"

static size_t	count_non_lis(size_t n, int *keep)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < n)
	{
		if (!keep[i])
			count++;
		i++;
	}
	return (count);
}

static void	absorb_next_from_b(t_context *ctx, int *keep, int *last)
{
	int	next;
	int	rank;

	next = *last + 1;
	while (ctx->b.size > 0 && !ctx->ops_error)
	{
		rank = ctx->b.arr[0];
		if (rank != next)
			return ;
		pa(ctx);
		if (ctx->ops_error)
			return ;
		ra(ctx);
		if (ctx->ops_error)
			return ;
		keep[rank] = 1;
		*last = rank;
		next = *last + 1;
	}
}

void	push_non_lis_to_b(t_context *ctx, int *keep)
{
	size_t	count_to_push;
	int		rank;
	int		last;

	count_to_push = count_non_lis(ctx->a.size, keep);
	last = -1;
	while (count_to_push > 0 && !ctx->ops_error)
	{
		rank = ctx->a.arr[0];
		if (keep[rank])
		{
			last = rank;
			ra(ctx);
			if (ctx->ops_error)
				return ;
			absorb_next_from_b(ctx, keep, &last);
		}
		else
		{
			pb(ctx);
			if (ctx->ops_error)
				return ;
			count_to_push--;
		}
	}
}
