SRCS = ft_puterror.c parse.c utils.c createphilo.c core.c waiting.c action.c

MAIN = main.c

DIRECTORYS = srcs/

SRCSD =	$(addprefix ${DIRECTORYS}, $(SRCS))

EFLAGS = -Wall -Wextra -Werror -g

OBJS =	${SRCSD:.c=.o}

OFLAGS = -c

NAME   = philo

%.o: %.c ${HEADER}
	gcc ${OFLAGS} ${EFLAGS} -o $@ $<

${NAME}: ${OBJS}
	gcc $(EFLAGS) -o $(NAME) $(MAIN) ${SRCSD}
			
all:	${NAME}

clean:
		rm  -f ${OBJS}

fclean:	clean
		rm  -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re