/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 07:38:28 by marti             #+#    #+#             */
/*   Updated: 2026/11/19 09:53:19 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "types.h"
#include "push_swap.h"

static void	rotate_a_b(t_context *ctx, size_t i_a, size_t i_b)
{
	while (i_a > 0 && i_b > 0)
	{
		exec(ctx, OP_RR);
		i_a--;
		i_b--;
	}
	while (i_a > 0)
	{
		exec(ctx, OP_RA);
		i_a--;
	}
	while (i_b > 0)
	{
		exec(ctx, OP_RB);
		i_b--;
	}
}

static void	rev_rotate_a_b(t_context *ctx, size_t i_a, size_t i_b)
{
	while (i_a > 0 && i_b > 0)
	{
		exec(ctx, OP_RRR);
		i_a--;
		i_b--;
	}
	while (i_a > 0)
	{
		exec(ctx, OP_RRA);
		i_a--;
	}
	while (i_b > 0)
	{
		exec(ctx, OP_RRB);
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
			exec(ctx, OP_RA);
	}
	else
	{
		min_i = ctx->a.size - min_i;
		while (min_i-- > 0)
			exec(ctx, OP_RRA);
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
	{
		rotate_a_b(ctx, i_a, i_b);
		exec(ctx, OP_PA);
		return ;
	}
	if (a_rev && b_rev)
	{
		i_a = ctx->a.size - i_a;
		i_b = ctx->b.size - i_b;
		rev_rotate_a_b(ctx, i_a, i_b);
		exec(ctx, OP_PA);
		return ;
	}
	while (!a_rev && i_a-- > 0)
		exec(ctx, OP_RA);
	while (a_rev && i_a++ < ctx->a.size)
		exec(ctx, OP_RRA);
	while (!b_rev && i_b-- > 0)
		exec(ctx, OP_RB);
	while (b_rev && i_b++ < ctx->b.size)
		exec(ctx, OP_RRB);
	exec(ctx, OP_PA);
}
