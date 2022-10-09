/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:43:49 by jsubel            #+#    #+#             */
/*   Updated: 2022/09/20 13:05:04 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	std::string	input;
	int	flag_only_upper = 1;

	if (argc == 1)
		return (0);
	for (int i = 1; i < argc; i++)
		input += argv[i];
	for (int i = 0; i < (int)input.size(); i++)
	{
		if (islower(input[i]))
		{
			input[i] = toupper(input[i]);
			flag_only_upper = 0;
		}
	}
	if (flag_only_upper == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		std::cout << input << std::endl;
	return (0);
}