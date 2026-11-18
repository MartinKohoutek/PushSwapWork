/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 09:28:33 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 11:16:47 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "operations.h"
#include "utils.h"

void	op_run(t_context *ctx, t_operation op)
{
	if (op == OP_SA)
		sa(ctx);
	else if (op == OP_SB)
		sb(ctx);
	else if (op == OP_SS)
		ss(ctx);
	else if (op == OP_PA)
		pa(ctx);
	else if (op == OP_PB)
		pb(ctx);
	else if (op == OP_RA)
		ra(ctx);
	else if (op == OP_RB)
		rb(ctx);
	else if (op == OP_RR)
		rr(ctx);
	else if (op == OP_RRA)
		rra(ctx);
	else if (op == OP_RRB)
		rrb(ctx);
	else if (op == OP_RRR)
		rrr(ctx);
}

const char	*op_name(t_operation op)
{
	static const char	*names[OP_COUNT] = {
		"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"
	};

	if (op < 0 || op >= OP_COUNT)
		return (NULL);
	return (names[op]);
}

static int	op_realloc(t_context *ctx)
{
	t_operation	*tmp;
	size_t		new_cap;

	if (ctx->ops_cap == 0)
		new_cap = 64;
	else
	{
		if (ctx->ops_cap > (size_t)(-1) / 2)
			return (0);
		new_cap = ctx->ops_cap * 2;
	}
	if (new_cap > (size_t)-1 / sizeof(*ctx->ops))
		return (0);
	tmp = ft_realloc(ctx->ops, sizeof(*ctx->ops) * new_cap);
	if (!tmp)
		return (0);
	ctx->ops = tmp;
	ctx->ops_cap = new_cap;
	return (1);
}

void	op_count(t_opcount *count, t_operation op)
{
	if (op == OP_SA)
		count->sa++;
	else if (op == OP_SB)
		count->sb++;
	else if (op == OP_SS)
		count->ss++;
	else if (op == OP_PA)
		count->pa++;
	else if (op == OP_PB)
		count->pb++;
	else if (op == OP_RA)
		count->ra++;
	else if (op == OP_RB)
		count->rb++;
	else if (op == OP_RR)
		count->rr++;
	else if (op == OP_RRA)
		count->rra++;
	else if (op == OP_RRB)
		count->rrb++;
	else if (op == OP_RRR)
		count->rrr++;
}

void	op_record(t_context *ctx, t_operation op)
{
	if (ctx->ops_error)
		return ;
	if (ctx->ops_size == ctx->ops_cap)
	{
		if (!op_realloc(ctx))
		{
			ctx->ops_error = 1;
			return ;
		}
	}
	ctx->ops[ctx->ops_size] = op;
	ctx->ops_size++;
	op_count(&ctx->opcount, op);
}
