/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 08:38:31 by marti             #+#    #+#             */
/*   Updated: 2026/11/18 08:39:31 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "operations.h"
#include "stack.h"

static void	sort_three(t_context *ctx)
{
	int	a;
	int	b;
	int	c;

	a = ctx->a.arr[0];
	b = ctx->a.arr[1];
	c = ctx->a.arr[2];
	if (a > b && b < c && a < c)
		sa(ctx);
	else if (a > b && b > c)
	{
		sa(ctx);
		rra(ctx);
	}
	else if (a > b && b < c && a > c)
		ra(ctx);
	else if (a < b && b > c && a < c)
	{
		sa(ctx);
		ra(ctx);
	}
	else if (a < b && b > c && a > c)
		rra(ctx);
}

static size_t	find_min(t_stack *a)
{
	size_t	i;
	size_t	min_i;

	i = 1;
	min_i = 0;
	while (i < a->size)
	{
		if (a->arr[i] < a->arr[min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}

static void	rotate_min(t_context *ctx, size_t min_i)
{
	size_t	rev;

	rev = ctx->a.size - min_i;
	if (min_i <= ctx->a.size / 2)
	{
		while (min_i-- > 0 && !ctx->ops_error)
			ra(ctx);
	}
	else
	{
		while (rev-- > 0 && !ctx->ops_error)
			rra(ctx);
	}
}

int	sort_small(t_context *ctx)
{
	size_t	min_i;

	if (ctx->a.size < 2)
		return (1);
	if (ctx->a.size == 2)
	{
		if (ctx->a.arr[0] > ctx->a.arr[1])
			sa(ctx);
	}
	else
	{
		while (ctx->a.size > 3 && !ctx->ops_error)
		{
			min_i = find_min(&ctx->a);
			rotate_min(ctx, min_i);
			if (!ctx->ops_error)
				pb(ctx);
		}
		if (!ctx->ops_error)
			sort_three(ctx);
		while (ctx->b.size > 0 && !ctx->ops_error)
			pa(ctx);
	}
	return (!ctx->ops_error && is_sorted(&ctx->a));
}
