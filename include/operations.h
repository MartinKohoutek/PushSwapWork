/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 09:10:33 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 09:10:33 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "types.h"

void		sa(t_context *ctx);
void		sb(t_context *ctx);
void		ss(t_context *ctx);
void		pa(t_context *ctx);
void		pb(t_context *ctx);
void		ra(t_context *ctx);
void		rb(t_context *ctx);
void		rr(t_context *ctx);
void		rra(t_context *ctx);
void		rrb(t_context *ctx);
void		rrr(t_context *ctx);

void		op_run(t_context *ctx, t_operation op);
void		op_record(t_context *ctx, t_operation op);
void		op_count(t_opcount *count, t_operation op);
const char	*op_name(t_operation op);

#endif