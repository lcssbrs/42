
NAME = bsq

SRCS = gen_ans.c getchar.c getchar2.c iter_ans.c launch_bsq.c main.c verif.c verif2.c garbage_norm.c

OBJS = ${SRC:.c=.o}

FLAGS = -Wall -Werror -Wextra

all:	${NAME}

${NAME}: ${OBJS}
	gcc -o ${NAME} ${SRCS} ${FLAGS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean
