NAME	= SedButWorse

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS	=	main.cpp sed.cpp

all:	${NAME}

${NAME}:
	${CC} ${SRCS} ${FLAGS} -o ${NAME}

docker:
	docker run -ti -v $(PWD):/test memory-test:0.1 bash -c "cd /test/; make re && valgrind --leak-check=full ./${NAME} test_standard.txt e 3e3"

fclean:
	rm -f ${NAME}
	rm -f *.replace

test:
	make re
	bash testscript.sh

re: fclean all

.PHONY: re fclean all

