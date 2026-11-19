/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:46:58 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 16:31:28 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n--)
		((unsigned char *)dest)[n] = ((const unsigned char *)src)[n];
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	while (n--)
		((unsigned char *)s)[n] = (unsigned char)c;
	return (s);
}

void	*ft_realloc(void *ptr, size_t size)
{
	return (realloc(ptr, size));
}
