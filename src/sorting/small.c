/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 08:38:31 by marti             #+#    #+#             */
/*   Updated: 2026/11/19 09:56:05 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_context *ctx)
{
	int	a;
	int	b;
	int	c;

	a = ctx->a.arr[0];
	b = ctx->a.arr[1];
	c = ctx->a.arr[2];
	if (a > b && b < c && a < c)
		exec(ctx, OP_SA);
	else if (a > b && b > c)
	{
		exec(ctx, OP_SA);
		exec(ctx, OP_RRA);
	}
	else if (a > b && b < c && a > c)
		exec(ctx, OP_RA);
	else if (a < b && b > c && a < c)
	{
		exec(ctx, OP_SA);
		exec(ctx, OP_RA);
	}
	else if (a < b && b > c && a > c)
		exec(ctx, OP_RRA);
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
			exec(ctx, OP_RA);
	}
	else
	{
		while (rev-- > 0 && !ctx->ops_error)
			exec(ctx, OP_RRA);
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
			exec(ctx, OP_SA);
	}
	else
	{
		while (ctx->a.size > 3 && !ctx->ops_error)
		{
			min_i = find_min(&ctx->a);
			rotate_min(ctx, min_i);
			if (!ctx->ops_error)
				exec(ctx, OP_PB);
		}
		if (!ctx->ops_error)
			sort_three(ctx);
		while (ctx->b.size > 0 && !ctx->ops_error)
			exec(ctx, OP_PA);
	}
	return (!ctx->ops_error && is_sorted(&ctx->a));
}
