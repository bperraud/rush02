SRCS	= function.c function_str.c is_arg.c main.c parsing.c

OBJS	= ${SRCS:.c=.o}

NAME	= hello

CC+FLAGS		= gcc -Werror -Wall -Wextra -o
RM		= rm -f

${NAME}:	${OBJS}
			${CC+FLAGS}  ${NAME}  ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
