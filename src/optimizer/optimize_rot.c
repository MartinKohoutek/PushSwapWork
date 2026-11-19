/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marti <marti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 07:09:25 by marti             #+#    #+#             */
/*   Updated: 2026/11/19 09:33:27 by marti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	track(t_operation op, ptrdiff_t *na, ptrdiff_t *nb)
{
	if (op == OP_RA || op == OP_RR)
		(*na)++;
	if (op == OP_RB || op == OP_RR)
		(*nb)++;
	if (op == OP_RRA || op == OP_RRR)
		(*na)--;
	if (op == OP_RRB || op == OP_RRR)
		(*nb)--;
	return (op >= OP_RA && op <= OP_RRR);
}

static void	put_n(t_context *ctx, size_t *w,
		t_operation op, size_t count)
{
	while (count > 0)
	{
		ctx->ops[(*w)++] = op;
		count--;
	}
}

static void	merge_common(t_context *ctx, size_t *w,
		ptrdiff_t *na, ptrdiff_t *nb)
{
	ptrdiff_t	count;

	if (*na > 0 && *nb > 0)
	{
		count = *na;
		if (*nb < count)
			count = *nb;
		put_n(ctx, w, OP_RR, (size_t)count);
		*na -= count;
		*nb -= count;
	}
	else if (*na < 0 && *nb < 0)
	{
		count = -*na;
		if (-*nb < count)
			count = -*nb;
		put_n(ctx, w, OP_RRR, (size_t)count);
		*na += count;
		*nb += count;
	}
}

static void	emit_run(t_context *ctx, size_t *w,
		ptrdiff_t na, ptrdiff_t nb)
{
	merge_common(ctx, w, &na, &nb);
	if (na > 0)
		put_n(ctx, w, OP_RA, (size_t)na);
	else if (na < 0)
		put_n(ctx, w, OP_RRA, (size_t)(-na));
	if (nb > 0)
		put_n(ctx, w, OP_RB, (size_t)nb);
	else if (nb < 0)
		put_n(ctx, w, OP_RRB, (size_t)(-nb));
}

void	optimize_rotations(t_context *ctx)
{
	size_t		r;
	size_t		w;
	ptrdiff_t	na;
	ptrdiff_t	nb;

	if (ctx->ops_error)
		return ;
	r = 0;
	w = 0;
	while (r < ctx->ops_size)
	{
		na = 0;
		nb = 0;
		while (r < ctx->ops_size && track(ctx->ops[r], &na, &nb))
			r++;
		emit_run(ctx, &w, na, nb);
		if (r < ctx->ops_size)
			ctx->ops[w++] = ctx->ops[r++];
	}
	ctx->ops_size = w;
}
