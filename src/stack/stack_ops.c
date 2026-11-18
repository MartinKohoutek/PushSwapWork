/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 09:21:20 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 09:21:31 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = tmp;
}

void	push(t_stack *dst, t_stack *src)
{
	size_t	i;

	if (src->size == 0 || dst->size >= dst->cap)
		return ;
	i = dst->size;
	while (i > 0)
	{
		dst->arr[i] = dst->arr[i - 1];
		i--;
	}
	dst->arr[0] = src->arr[0];
	dst->size++;
	i = 0;
	while (i + 1 < src->size)
	{
		src->arr[i] = src->arr[i + 1];
		i++;
	}
	src->size--;
}

void	rotate(t_stack *stack)
{
	int		tmp;
	size_t	i;

	if (stack->size < 2)
		return ;
	tmp = stack->arr[0];
	i = 0;
	while (i + 1 < stack->size)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->size - 1] = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	int		tmp;
	size_t	i;

	if (stack->size < 2)
		return ;
	tmp = stack->arr[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = tmp;
}
