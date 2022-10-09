NAME	= ClapTrap

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS	=	main.cpp ClapTrap.cpp

all:	${NAME}

${NAME}:
	${CC} ${SRCS} ${FLAGS} -o ${NAME}

fclean:
	rm -f ${NAME}

re: fclean all

.PHONY: re fclean all

