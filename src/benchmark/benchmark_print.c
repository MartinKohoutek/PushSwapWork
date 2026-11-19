#include <unistd.h>
#include "types.h"
#include "benchmark.h"
#include "output.h"

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