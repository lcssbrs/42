NAME = server

NAME2 = client

CC = gcc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= server.c minitalk_utils.c

SRCS2	= client.c minitalk_utils.c

OBJS	= $(SRCS:.c=.o)

OBJS2	= $(SRCS2:.c=.o)

all:	$(NAME) $(NAME2)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME2):	$(OBJS2)

			$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

clean:
			rm -f $(OBJS) $(OBJS2)

fclean:		clean
			rm -f $(NAME) $(NAME2)

re:			fclean all

.PHONY:		all clean fclean re

