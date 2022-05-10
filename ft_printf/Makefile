NAME		= libftprintf.a

OBJ			= ${SRC:.c=.o}

CC 			= cc

CC_FLAGS 	= -Wall -Wextra -Werror

SRC			= ft_printf.c ft_put.c ft_puthex.c

.c.o:		
			${CC} ${CC_FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
			ar rcs ${NAME} ${OBJ}

all:		${NAME}

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
