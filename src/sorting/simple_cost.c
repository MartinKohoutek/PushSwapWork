/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 07:36:41 by marti             #+#    #+#             */
/*   Updated: 2026/11/18 08:02:23 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "types.h"

size_t	pos_min_a(t_stack *a)
{
	size_t	min_i;
	size_t	i;

	min_i = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->arr[i] < a->arr[min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}

size_t	insert_pos_a(t_stack *a, int rank_b)
{
	size_t	i;

	i = 0;
	while (i < a->size)
	{
		if (i > 0 && a->arr[i - 1] < rank_b
			&& rank_b < a->arr[i])
			return (i);
		if (i == 0 && a->arr[a->size - 1] < rank_b
			&& rank_b < a->arr[i])
			return (i);
		i++;
	}
	return (pos_min_a(a));
}

static size_t	rot_cost(size_t i, size_t size)
{
	if (i <= size / 2)
		return (i);
	return (size - i);
}

static size_t	move_cost(t_context *ctx, size_t i_b)
{
	size_t	i_a;
	size_t	cost_a;
	size_t	cost_b;

	i_a = insert_pos_a(&ctx->a, ctx->b.arr[i_b]);
	cost_a = rot_cost(i_a, ctx->a.size);
	cost_b = rot_cost(i_b, ctx->b.size);
	if ((i_a <= ctx->a.size / 2) == (i_b <= ctx->b.size / 2))
	{
		if (cost_a > cost_b)
			return (cost_a + 1);
		return (cost_b + 1);
	}
	return (cost_a + cost_b + 1);
}

size_t	best_pos_b(t_context *ctx)
{
	size_t	best_i_b;
	size_t	best_cost;
	size_t	cost;
	size_t	i;

	best_i_b = 0;
	best_cost = move_cost(ctx, 0);
	i = 1;
	while (i < ctx->b.size)
	{
		cost = move_cost(ctx, i);
		if (cost < best_cost)
		{
			best_i_b = i;
			best_cost = cost;
		}
		i++;
	}
	return (best_i_b);
}
