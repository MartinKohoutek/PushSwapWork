/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 19:11:28 by marti             #+#    #+#             */
/*   Updated: 2026/11/17 19:14:04 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
# define BENCHMARK_H

# include "types.h"

void		print_count(const char *name, size_t count, const char *end);
const char	*strategy_name(t_strategy strat);
const char	*complexity(t_strategy strat);
void		print_disorder(double disorder);
void		print_opcount(const t_context *ctx);

#endif