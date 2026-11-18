/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:02:34 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 16:08:39 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

double	calculate_disorder(const t_stack *stack)
{
	size_t	i;
	size_t	j;
	size_t	disordered;
	size_t	total;

	if (stack->size < 2)
		return (0.0);
	disordered = 0;
	total = stack->size * (stack->size - 1) / 2;
	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->arr[i] > stack->arr[j])
				disordered++;
			j++;
		}
		i++;
	}
	return ((double)disordered / (double)total);
}
