NAME = push_swap
SRCS = algo_functions_0.c \
       algo_functions_1.c \
       algo_functions_2.c \
       algo_functions_3.c \
       cost_functions.c \
       ft_split.c \
       main.c \
       push_swap_utils_0.c \
       push_swap_utils_1.c \
       push_swap_utils_2.c \
       stack_fts_0.c \
       stack_fts_1.c \
       stack_fts_2.c \
       stack_fts_3.c \
       stack_fts_4.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
