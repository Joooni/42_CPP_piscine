#!/bin/sh

GREEN='\033[1;32m'
RESET='\033[0m'

make re

echo "${GREEN}8 9 * 9 - 9 - 9 - 4 - 1 + = 42:${RESET}"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo "${GREEN}7 7 * 7 - = 42:${RESET}"
./RPN "7 7 * 7 -"

echo "${GREEN}1 + 1 = 2:${RESET}"
./RPN "1 1 +"

echo "${GREEN}1 = 1:${RESET}"
./RPN "1"

echo "${GREEN}9 + 9 = 18:${RESET}"
./RPN "9 9 +"

echo "${GREEN}9 + 9 + 9 = 27:${RESET}"
./RPN "9 9 + 9 +"

echo "${GREEN}5 * 5 = 25:${RESET}"
./RPN "5 5 *"

echo "${GREEN}5 * 5 * 5 = 125:${RESET}"
./RPN "5 5 * 5 *"

echo "${GREEN}5 * 5 / 6 = 4:${RESET}"
./RPN "5 5 * 6 /"

echo "${GREEN}9 * 9 / 7 + 5 - 2 + -8 = 6:${RESET}"
./RPN "9 9 * 7 / 5 + 2 - -8 +"

echo "${GREEN}invalid operands/operators:${RESET}"
./RPN "1 2 * 2 / 2 * 2 4 - +"
./RPN "(1 + 1)"
./RPN "1 1 1"
./RPN "+1 1 1"
./RPN "1 1+ 1"
./RPN "1 1 1+"
./RPN "1 + 1"
./RPN "+ 1 1"
./RPN "1 /1 1"
./RPN "1 / 1 1"
./RPN "1 + 1 1"
./RPN "1 1 + 1"
./RPN "1 1 1 1"
./RPN "1 1 + 1 + 1 + 1 1"
./RPN "1 1 + 1 1 + 1 + 1 +"
./RPN "1 . 1"
./RPN "1 1 + . +"
./RPN "1 1 + j +"
./RPN "1 1 + - +"
./RPN "1 1 + -"
./RPN "    "
./RPN "        1 1 +"

make fclean