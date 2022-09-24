NAME    = cub3d
CC = gcc
INC = cub3d.h
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
RM = rm -rf
SRCS    =	main.c		\
			checks.c	\
			readfile.c	\

OBJS = $(SRCS:.c=.o)
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(NAME)

$(LIBFT):
	@make -C libft/

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) -o $(NAME) $(LIBFT)
	@echo $(B)cub3d is ready!

%.o: %.c $(INC)
	@echo $(R)Complining [$<]
	@${CC} $(CFLAGS) -c $< -o $@ $(CFLAGS)

clean:
	@$(RM) $(OBJS)
	@echo $(R)Removed [$(OBJS)]

fclean: clean
	@$(RM) $(NAME)
	@echo $(R)Removed [$(NAME)]
	@make fclean -C libft/

re: fclean all

.PHONY: all, clean, fclean, re