/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 10:03:00 by marti             #+#    #+#             */
/*   Updated: 2026/11/19 10:03:28 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	print_bench(const t_context *ctx)
{
	print_disorder(ctx->disorder);
	put_str(STDERR_FILENO, "[bench] strategy: ");
	put_str(STDERR_FILENO, strategy_name(ctx->config.strategy));
	put_str(STDERR_FILENO, " / ");
	put_str(STDERR_FILENO, complexity(ctx->used_strategy));
	print_count("\n[bench] total_ops", ctx->ops_size, "\n");
	print_opcount(ctx);
}
