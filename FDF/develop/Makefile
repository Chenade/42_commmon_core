SRCS 			= $(addprefix srcs/, main.c)

OBJS 			= ${SRCS:.c=.o}

HEADERS			= $(addprefix includes/, retromfa.h)


CC  			=  cc


MINILIBXPATH		= minilibx-linux/

CFLAGS			= -I includes -I ${MINILIBXPATH} -Wall -Wextra -Werror -O3
LFLAGS			= -L ${MINILIBXPATH} -lmlx_Linux -lX11 -lXext -lm

NAME 			= retromfa

RM 			= rm -f

%.o:			%.c ${HEADERS}
			${CC} -c ${CFLAGS} -o $@ $<

all:			${NAME}
		
${NAME}:		${OBJS}
			make -C ${MINILIBXPATH}
			${CC} ${OBJS} ${CFLAGS} ${LFLAGS} -o $@

clean:
			make $@ -C ${MINILIBXPATH}
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:
			make clean -C ${MINILIBXPATH}
			${RM} ${OBJS} ${BONUS_OBJS} ${NAME}

re:			
			${MAKE} fclean 
			${MAKE}	all

.PHONY:			all clean fclean re
