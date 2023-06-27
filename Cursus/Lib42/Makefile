NAME = lib42.a

INCLUDE		=	inc/
SRC_DIR 	=	src/
OBJ_DIR		=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I
RM			=	rm -f
AR			=	ar rcs
ECHO		=	echo -e

OBJS = ${SRCS:.c=.o}

RM = rm -f

CC = gcc

FLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:    clean
	${RM} ${NAME}

re: fclean all

bonus: ${OBJS_BONUS}
	ar -rcs ${NAME} ${OBJS_BONUS}

.PHONY: all clean fclean re