/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 09:28:52 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 09:51:03 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "stack.h"
#include "operations.h"
#include "push_swap.h"

void	ra(t_context *ctx)
{
	op_record(ctx, OP_RA);
	if (ctx->ops_error)
		return ;
	rotate(&ctx->a);
}

void	rb(t_context *ctx)
{
	op_record(ctx, OP_RB);
	if (ctx->ops_error)
		return ;
	rotate(&ctx->b);
}

void	rr(t_context *ctx)
{
	op_record(ctx, OP_RR);
	if (ctx->ops_error)
		return ;
	rotate(&ctx->a);
	rotate(&ctx->b);
}
