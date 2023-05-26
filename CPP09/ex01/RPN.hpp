/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:14:52 by jsubel            #+#    #+#             */
/*   Updated: 2023/03/20 11:59:48 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>

#define ERR_MISSING_INPUT	"Error - missing input"
#define COLOR_RED			"\033[31m"
#define END					"\033[0m"

class RPNCalc
{
	public:
		RPNCalc(const std::string &input);
		~RPNCalc();

		bool	isValidNumber(const std::string &input);
		bool	isSign(const std::string &input);
		void	calculate(const std::string &operand);
	private:
		RPNCalc();
		RPNCalc(const RPNCalc &rhs);
		RPNCalc &operator=(const RPNCalc &rhs);

		std::stack<int>	_stack;
};

#endif
