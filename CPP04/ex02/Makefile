NAME	= Animals

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS	= main.cpp AAnimal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

all:	${NAME}

${NAME}:
	${CC} ${SRCS} ${FLAGS} -o ${NAME}

fclean:
	rm -f ${NAME}

re: fclean all

.PHONY: re fclean all

