/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 07:38:28 by marti             #+#    #+#             */
/*   Updated: 2026/11/18 07:57:55 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "types.h"
#include "operations.h"
#include "sorting.h"

static void	rotate_a_b(t_context *ctx, size_t i_a, size_t i_b)
{
	while (i_a > 0 && i_b > 0)
	{
		rr(ctx);
		i_a--;
		i_b--;
	}
	while (i_a > 0)
	{
		ra(ctx);
		i_a--;
	}
	while (i_b > 0)
	{
		rb(ctx);
		i_b--;
	}
}

static void	rev_rotate_a_b(t_context *ctx, size_t i_a, size_t i_b)
{
	while (i_a > 0 && i_b > 0)
	{
		rrr(ctx);
		i_a--;
		i_b--;
	}
	while (i_a > 0)
	{
		rra(ctx);
		i_a--;
	}
	while (i_b > 0)
	{
		rrb(ctx);
		i_b--;
	}
}

void	rotate_min_top(t_context *ctx)
{
	size_t	min_i;

	min_i = pos_min_a(&ctx->a);
	if (min_i <= ctx->a.size / 2)
	{
		while (min_i-- > 0)
			ra(ctx);
	}
	else
	{
		min_i = ctx->a.size - min_i;
		while (min_i-- > 0)
			rra(ctx);
	}
}

void	prepare_and_pa(t_context *ctx, size_t i_b)
{
	size_t	i_a;
	int		a_rev;
	int		b_rev;

	i_a = insert_pos_a(&ctx->a, ctx->b.arr[i_b]);
	a_rev = (i_a > ctx->a.size / 2);
	b_rev = (i_b > ctx->b.size / 2);
	if (!a_rev && !b_rev)
		return (rotate_a_b(ctx, i_a, i_b), pa(ctx));
	if (a_rev && b_rev)
	{
		i_a = ctx->a.size - i_a;
		i_b = ctx->b.size - i_b;
		return (rev_rotate_a_b(ctx, i_a, i_b), pa(ctx));
	}
	while (!a_rev && i_a-- > 0)
		ra(ctx);
	while (a_rev && i_a++ < ctx->a.size)
		rra(ctx);
	while (!b_rev && i_b-- > 0)
		rb(ctx);
	while (b_rev && i_b++ < ctx->b.size)
		rrb(ctx);
	pa(ctx);
}
