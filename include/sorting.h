/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:17:04 by marti             #+#    #+#             */
/*   Updated: 2026/11/18 08:40:50 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "types.h"

t_strategy	choose_strategy(const t_context *ctx);
void		run_sort(t_context *ctx);

void		sort_medium(t_context *ctx);
void		sort_complex(t_context *ctx);
void		sort_easy(t_context *ctx);
int			sort_small(t_context *ctx);

int			mark_lis(t_stack *a, int *keep);
void		push_non_lis_to_b(t_context *ctx, int *keep);
size_t		pos_min_a(t_stack *a);
size_t		insert_pos_a(t_stack *a, int rank_b);
size_t		best_pos_b(t_context *ctx);
void		prepare_and_pa(t_context *ctx, size_t i_b);
void		rotate_min_top(t_context *ctx);
// void		insert_from_b(t_context *ctx);
void		sort_simple(t_context *ctx);

#endif