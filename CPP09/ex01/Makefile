NAME	= RPN

CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
SRCS	=	main.cpp RPN.cpp

all:	${NAME}

${NAME}:
	${CC} ${SRCS} ${FLAGS} -o ${NAME}

# https://valgrind.org/docs/manual/faq.html#faq.reports
# for information on the valgrind leaky situation in consideration to STL


docker:
	docker run -ti -v $(PWD):/test memory-test:0.1 bash -c "cd /test/; make re && valgrind --leak-check=full --show-leak-kinds=all ./test.sh"

fclean:
	rm -f ${NAME}

re: fclean all

.PHONY: re fclean all

