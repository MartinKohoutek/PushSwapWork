/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:30:24 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 18:44:35 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include <stddef.h>

t_parse_status	check_duplicates(const int *array, size_t size)
{
	const int	*current;
	const int	*next;

	current = array;
	while (current < array + size)
	{
		next = current + 1;
		while (next < array + size)
		{
			if (*current == *next)
				return (PARSE_DUPLICATE);
			next++;
		}
		current++;
	}
	return (PARSE_OK);
}
