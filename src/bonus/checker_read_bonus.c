#include <stdlib.h>
#include <unistd.h>
#include "checker_bonus.h"
#include "types.h"
#include "parser.h"

static int	append_op(t_context *ctx, t_operation op)
{
	t_operation	*new_ops;
	size_t		new_cap;
	size_t		i;

	if (ctx->ops_size == ctx->ops_cap)
	{
		new_cap = 16;
		if (ctx->ops_cap)
			new_cap = ctx->ops_cap * 2;
		new_ops = malloc(new_cap * sizeof(*new_ops));
		if (!new_ops)
			return (0);
		i = 0;
		while (i < ctx->ops_size)
		{
			new_ops[i] = ctx->ops[i];
			i++;
		}
		free(ctx->ops);
		ctx->ops = new_ops;
		ctx->ops_cap = new_cap;
	}
	ctx->ops[ctx->ops_size++] = op;
	return (1);
}

static int	parse_line(t_context *ctx, char *line, size_t len)
{
	t_operation	op;

	if (len < 2 || len > 3)
		return (0);
	line[len] = '\0';
	if (!get_operation(line, &op))
		return (0);
	return (append_op(ctx, op));
}

int	checker_read(t_context *ctx)
{
	char	line[4];
	char	c;
	size_t	len;
	ssize_t	r;

	len = 0;
	while (1)
	{
		r = read(0, &c, 1);
		if (r < 0)
			return (0);
		if (r == 0)
			break ;
		if (c == '\n')
		{
			if (!parse_line(ctx, line, len))
				return (0);
			len = 0;
		}
		else
		{
			if (len == 3)
				return (0);
			line[len++] = c;
		}
	}
	return (len == 0);
}