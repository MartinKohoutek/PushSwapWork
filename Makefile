NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -I include
DEPFLAGS	= -MMD -MP

SRC_DIR		= src
OBJ_DIR		= obj

RM			= rm -f
RMDIR		= rm -rf

CORE_SRC = \
	src/stack/stack.c \
	src/stack/stack_ops.c \
	src/stack/normalize.c \
	src/operations/operations.c \
	src/parser/parser.c \
	src/parser/capacity.c \
	src/parser/duplicates.c \
	src/context/context.c \
	src/output/output.c \
	src/utils/utils.c \
	src/utils/memory.c \
	src/utils/disorder.c

PS_SRC = \
	src/main.c \
	src/sorting/dispatch.c \
	src/sorting/simple.c \
	src/sorting/simple_cost.c \
	src/sorting/simple_push.c \
	src/sorting/simple_rotate.c \
	src/sorting/medium.c \
	src/sorting/complex.c \
	src/sorting/easy.c \
	src/sorting/small.c \
	src/benchmark/benchmark.c \
	src/benchmark/benchmark_print.c \
	src/optimizer/optimize.c \
	src/optimizer/optimize_rot.c

BONUS_SRC = \
	src/bonus/checker_bonus.c \
	src/bonus/checker_read_bonus.c

CORE_OBJ	= $(addprefix $(OBJ_DIR)/, $(CORE_SRC:.c=.o))
PS_OBJ		= $(addprefix $(OBJ_DIR)/, $(PS_SRC:.c=.o))
BONUS_OBJ 	= $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

DEPS		= $(CORE_OBJ:.o=.d) \
			  $(PS_OBJ:.o=.d) \
			  $(BONUS_OBJ:.o=.d)

include config/colors.mk
include config/banners.mk

all: banner $(NAME)

banner:
	@printf "$$BANNER"

$(NAME): $(CORE_OBJ) $(PS_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(CORE_OBJ) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	$(RMDIR) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

-include $(DEPS)

.PHONY: all bonus clean fclean re banner