/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 09:18:04 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 09:18:04 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "types.h"

int		init_stack(t_stack *stack, size_t capacity);
void	free_stack(t_stack *stack);
int		normalize_stack(t_stack *stack);

void	swap(t_stack *stack);
void	push(t_stack *dst, t_stack *src);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

int		is_sorted(const t_stack *stack);

#endif