/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 08:16:28 by marti             #+#    #+#             */
/*   Updated: 2026/11/18 08:47:45 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "types.h"
#include "operations.h"
#include "stack.h"
#include "sorting.h"

static size_t	find_min(t_stack *a)
{
	size_t	i;
	size_t	pos_min;

	i = 1;
	pos_min = 0;
	while (i < a->size)
	{
		if (a->arr[i] < a->arr[pos_min])
			pos_min = i;
		i++;
	}
	return (pos_min);
}

static void	rotate_min_to_top(t_context *ctx, size_t pos_min)
{
	size_t	rev;

	rev = ctx->a.size - pos_min;
	if (pos_min <= rev)
	{
		while (pos_min-- > 0 && !ctx->ops_error)
			ra(ctx);
	}
	else
	{
		while (rev-- > 0 && !ctx->ops_error)
			rra(ctx);
	}
}

void	sort_easy(t_context *ctx)
{
	size_t	size;
	size_t	pos_min;

	size = ctx->a.size;
	if (is_sorted(&ctx->a))
		return ;
	if (size <= 5)
	{
		sort_small(ctx);
		return ;
	}
	while (size > 0 && !ctx->ops_error)
	{
		pos_min = find_min(&ctx->a);
		rotate_min_to_top(ctx, pos_min);
		if (!ctx->ops_error)
			pb(ctx);
		size--;
	}
	while (ctx->b.size > 0 && !ctx->ops_error)
		pa(ctx);
}
