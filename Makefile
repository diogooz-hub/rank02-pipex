NAME = pipex
SRCS = pipex.c aux.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT_MAKEFILE)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

$(LIBFT_MAKEFILE):
	@make -C $(LIBFT_DIR)
