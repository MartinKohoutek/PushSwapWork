/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 07:08:30 by marti             #+#    #+#             */
/*   Updated: 2026/11/19 09:33:43 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_opcount(t_opcount *ops)
{
	*ops = (t_opcount){0};
}

static int	is_swap(t_operation op)
{
	return (op == OP_SA || op == OP_SB || op == OP_SS);
}

static void	remove_inverse_swaps(t_context *ctx)
{
	size_t	r;
	size_t	w;

	r = 0;
	w = 0;
	while (r < ctx->ops_size)
	{
		if (is_swap(ctx->ops[r]) && w > 0
			&& ctx->ops[w - 1] == ctx->ops[r])
		{
			w--;
			r++;
		}
		else
		{
			ctx->ops[w] = ctx->ops[r];
			w++;
			r++;
		}
	}
	ctx->ops_size = w;
}

static void	rebuild_opcount(t_context *ctx)
{
	size_t	i;

	init_opcount(&ctx->opcount);
	i = 0;
	while (i < ctx->ops_size)
	{
		op_count(&ctx->opcount, ctx->ops[i]);
		i++;
	}
}

void	optimize(t_context *ctx)
{
	size_t	old_size;

	if (ctx->ops_error)
		return ;
	while (1)
	{
		old_size = ctx->ops_size;
		remove_inverse_swaps(ctx);
		optimize_rotations(ctx);
		if (ctx->ops_size == old_size)
			break ;
	}
	rebuild_opcount(ctx);
}
