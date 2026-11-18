/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:56:20 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 19:15:14 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

# include <stddef.h>
# include "types.h"

void	ft_write(int fd, const char *s, size_t len);
void	put_str(int fd, const char *s);
void	put_nbr(int fd, long n);
void	print_operations(const t_context *ctx);
void	print_bench(const t_context *ctx);

#endif