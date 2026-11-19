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

CORE_SRC = stack.c stack_ops.c normalize.c operations.c parser.c \
	core.c context.c output.c utils.c memory.c benchmark.c

PS_SRC = main.c dispatch.c simple.c medium.c complex.c

BONUS_SRC = bonus/checker_bonus.c bonus/checker_read_bonus.c

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

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	$(RMDIR) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

-include $(DEPS)

.PHONY: all bonus clean fclean re banner