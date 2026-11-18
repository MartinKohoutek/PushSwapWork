/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 09:16:57 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 09:16:57 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "types.h"

int			init_context(t_context *ctx, t_args *args);
void		free_context(t_context *ctx);

// void		sort_small(t_context *ctx);
// void		sort_simple(t_context *ctx);
// int			tiny_sorting(t_context *ctx);

// void		optimize(t_context *ctx);

// void		count_operation(t_opcount *count, t_operation op);
// void		print_result(const t_context *ctx);

#endif