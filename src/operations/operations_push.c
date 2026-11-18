/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 09:29:09 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 09:50:03 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "stack.h"
#include "operations.h"
#include "push_swap.h"

void	pa(t_context *ctx)
{
	op_record(ctx, OP_PA);
	if (ctx->ops_error)
		return ;
	push(&ctx->a, &ctx->b);
}

void	pb(t_context *ctx)
{
	op_record(ctx, OP_PB);
	if (ctx->ops_error)
		return ;
	push(&ctx->b, &ctx->a);
}
