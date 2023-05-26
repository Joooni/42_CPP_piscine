NAME	= BSP

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS	=	main.cpp Fixed.cpp Point.cpp bsp.cpp

all:	${NAME}

${NAME}:
	${CC} ${SRCS} ${FLAGS} -o ${NAME}

docker:
	docker run -ti -v $(PWD):/test memory-test:0.1 bash -c "cd /test/; make re && valgrind --leak-check=full --show-leak-kinds=all ./${NAME}"

fclean:
	rm -f ${NAME}

re: fclean all

.PHONY: re fclean all

