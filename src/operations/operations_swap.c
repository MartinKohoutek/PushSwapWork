/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 09:28:43 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 09:51:35 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "stack.h"
#include "operations.h"
#include "push_swap.h"

void	sa(t_context *ctx)
{
	op_record(ctx, OP_SA);
	if (ctx->ops_error)
		return ;
	swap(&ctx->a);
}

void	sb(t_context *ctx)
{
	op_record(ctx, OP_SB);
	if (ctx->ops_error)
		return ;
	swap(&ctx->b);
}

void	ss(t_context *ctx)
{
	op_record(ctx, OP_SS);
	if (ctx->ops_error)
		return ;
	swap(&ctx->a);
	swap(&ctx->b);
}
