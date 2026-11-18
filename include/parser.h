/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 09:12:32 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 09:12:32 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "types.h"

int				parse_args(int ac, char **av, t_args *args, int checker);
int				count_capacity(int ac, char **av);
t_parse_status	check_duplicates(const int *array, size_t size);
// void	print_error(t_parse_status status);

#endif