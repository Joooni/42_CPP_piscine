NAME	= Conversion

CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
SRCS	=	main.cpp

all:	${NAME}

${NAME}:
	${CC} ${SRCS} ${FLAGS} -o ${NAME}

docker:
	docker run -ti -v $(PWD):/test memory-test:0.1 bash -c "cd /test/; make re && valgrind --leak-check=full ./${NAME} %"


fclean:
	rm -f ${NAME}

re: fclean all

.PHONY: re fclean all

