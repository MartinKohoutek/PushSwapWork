/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:45:59 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 15:46:46 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	count_capacity(int ac, char **av)
{
	const char	*s;
	int			count;
	int			is_num;
	int			i;

	count = 0;
	i = 0;
	while (++i < ac)
	{
		s = av[i];
		is_num = 1;
		while (*s)
		{
			if (is_space(*s))
				is_num = 1;
			else if (!is_digit(*s) && !is_sign(*s))
				is_num = 0;
			if (!is_space(*s) && (!s[1] || is_space(s[1])))
				if (is_num)
					count++;
			s++;
		}
	}
	return (count);
}
