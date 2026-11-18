/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 09:20:57 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 15:55:10 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "utils.h"
#include "types.h"

int	init_stack(t_stack *stack, size_t capacity)
{
	stack->arr = NULL;
	stack->size = 0;
	stack->cap = 0;
	if (capacity == 0)
		return (1);
	stack->arr = malloc(capacity * sizeof(*stack->arr));
	if (!stack->arr)
		return (0);
	stack->cap = capacity;
	return (1);
}

void	free_stack(t_stack *stack)
{
	free(stack->arr);
	stack->arr = NULL;
	stack->size = 0;
	stack->cap = 0;
}

int	is_sorted(const t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i + 1 < stack->size)
	{
		if (stack->arr[i] > stack->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
