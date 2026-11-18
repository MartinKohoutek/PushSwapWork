
NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iinclude
DEPFLAGS = -MMD -MP

RM = rm -f
RMDIR = rm -rf

BUILD_DIR = build

SRCS = \
	src/main.c \
	src/stack/stack.c \
	src/stack/stack_ops.c \
	src/stack/normalize.c \
	src/operations/operations.c \
	src/operations/operations_swap.c \
	src/operations/operations_push.c \
	src/operations/operations_rotate.c \
	src/operations/operations_rev_rotate.c \
	src/parser/parser.c \
	src/parser/capacity.c \
	src/parser/duplicates.c \
	src/context/context.c \
	src/utils/utils.c \
	src/utils/memory.c \
	src/utils/disorder.c \
	src/sorting/dispatch.c \
	src/sorting/simple.c \
	src/sorting/simple_cost.c \
	src/sorting/simple_push.c \
	src/sorting/simple_rotate.c \
	src/sorting/medium.c \
	src/sorting/complex.c \
	src/sorting/easy.c \
	src/sorting/small.c \
	src/output/output.c \
	src/benchmark/benchmark.c \
	src/optimizer/optimize.c \
	src/optimizer/optimize_rot.c 

	
OBJS = $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

include config/colors.mk
include config/banners.mk

all: banner $(NAME)

banner:
	@printf "$$BANNER"

#$(NAME): $(OBJS)
#	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
$(NAME): $(OBJS)
	@printf "\r\033[K$(C_YELLOW)$(C_BOLD)🔧 Linking: $(C_WHITE)%s$(C_RESET)\n" "$(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@printf "$(C_GREEN)$(C_BOLD)✔ Push_swap built successfully!$(C_RESET)\n"

$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@printf "\r\033[K$(C_BLUE)  ›  Compiling: $(C_WHITE)$<...$(C_RESET)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(DEPS)
	@printf "$(C_YELLOW)○ Object files cleaned.$(C_RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(C_RED)✗ Executable removed.$(C_RESET)\n"

re: fclean
	@$(MAKE) --no-print-directory all

-include $(DEPS)

.PHONY: all clean fclean re