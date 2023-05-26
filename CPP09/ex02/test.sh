#!/bin/sh

RED='\033[31m'
RESET='\033[0m'
YELLOW='\033[33m'
make re


echo "${YELLOW}100 random numbers${RESET}"
./PmergeMe `jot -r 100 1 1000 | tr '\n' ' '`

echo "${YELLOW}200 random numbers${RESET}"
./PmergeMe `jot -r 200 1 1000 | tr '\n' ' '`

echo "${YELLOW}500 random numbers${RESET}"
./PmergeMe `jot -r 500 1 1000 | tr '\n' ' '`

echo "${YELLOW}1000 random numbers${RESET}"
./PmergeMe `jot -r 1000 1 1000 | tr '\n' ' '`

echo "${YELLOW}3000 random numbers${RESET}"
./PmergeMe `jot -r 3000 1 1000 | tr '\n' ' '`

echo "${YELLOW}10000 random numbers${RESET}"
./PmergeMe `jot -r 10000 1 1000 | tr '\n' ' '`

echo "${YELLOW}1 2 3 4 5 (already sorted)${RESET}"
./PmergeMe 1 2 3 4 5

echo "${YELLOW}1${RESET}"
./PmergeMe 1

echo "${YELLOW}1 3 2${RESET}"
./PmergeMe 1 3 2

echo "${YELLOW}1 4 3 5 2${RESET}"
./PmergeMe 1 4 3 5 2

echo "${YELLOW}1 4 3 5${RESET}"
./PmergeMe 1 4 3 2

echo "${YELLOW}9 7 8 6 5 1 4 2 3 10${RESET}"
./PmergeMe 9 7 8 6 5 1 4 2 3 10

echo "${RED}Errors:${RESET}"
./PmergeMe 1 3 2 6 5 a
./PmergeMe 1 3 2 6 -5
./PmergeMe 1 3 2 ! 5
./PmergeMe 1 3 2147483648 6 5
./PmergeMe 1 3 -2147483649 6 5

make fclean