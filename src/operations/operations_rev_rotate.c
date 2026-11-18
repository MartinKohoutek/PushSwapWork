/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 09:29:00 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 09:50:35 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "stack.h"
#include "operations.h"
#include "push_swap.h"

void	rra(t_context *ctx)
{
	op_record(ctx, OP_RRA);
	if (ctx->ops_error)
		return ;
	reverse_rotate(&ctx->a);
}

void	rrb(t_context *ctx)
{
	op_record(ctx, OP_RRB);
	if (ctx->ops_error)
		return ;
	reverse_rotate(&ctx->b);
}

void	rrr(t_context *ctx)
{
	op_record(ctx, OP_RRR);
	if (ctx->ops_error)
		return ;
	reverse_rotate(&ctx->a);
	reverse_rotate(&ctx->b);
}
