/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:55:48 by marti             #+#    #+#             */
/*   Updated: 2026/11/18 22:31:21 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "output.h"
#include "operations.h"
#include "types.h"
#include "benchmark.h"

void	ft_write(int fd, const char *s, size_t len)
{
	ssize_t	w;

	while (len > 0)
	{
		w = write(fd, s, len);
		if (w <= 0)
			return ;
		s += w;
		len -= (size_t)w;
	}
}

void	put_str(int fd, const char *s)
{
	const char	*end;

	end = s;
	while (*end)
		end++;
	ft_write(fd, s, end - s);
}

void	put_nbr(int fd, long n)
{
	char	c;

	if (n < 0)
	{
		put_str(fd, "-");
		n = -n;
	}
	if (n >= 10)
		put_nbr(fd, n / 10);
	c = '0' + n % 10;
	ft_write(fd, &c, 1);
}

void	print_operations(const t_context *ctx)
{
	const t_operation	*op;
	const char			*name;
	size_t				left;

	op = ctx->ops;
	left = ctx->ops_size;
	while (left > 0)
	{
		name = op_name(*op);
		if (name)
		{
			put_str(STDOUT_FILENO, name);
			put_str(STDOUT_FILENO, "\n");
		}
		op++;
		left--;
	}
}
