/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:31:06 by jsubel            #+#    #+#             */
/*   Updated: 2023/03/15 15:44:14 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	ft_error(const std::string &message)
{
	std::cerr << COLOR_RED << message << END << std::endl;
	return (1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error(ERR_MISSING_INPUT));
	std::string input(argv[1]);
		try
		{
			RPNCalc RPNCalc(input);
		}
		catch(const std::exception& e)
		{
			std::cerr << COLOR_RED << e.what() << END << '\n';
		}
}
