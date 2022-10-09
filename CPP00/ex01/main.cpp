/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 09:31:22 by jsubel            #+#    #+#             */
/*   Updated: 2022/09/05 11:56:39 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	phonebook.StartScreen();
	while (std::getline(std::cin, cmd))
	{
		if (cmd == "ADD")
			phonebook.AddContact();
		else if (cmd == "SEARCH" && phonebook.GetNbrOfContacts() > 0)
			phonebook.SearchContact();
		else if (cmd == "SEARCH")
			std::cout << "Sorry, no contacts to search through :(" << std::endl;
		else if (cmd == "EXIT")
		{
			break;
		}
		else
			std::cout << "No! That's not a correct command." << std::endl << "Please enter one of the following commands: ADD, SEARCH or EXIT" << std::endl;
	}
	std::cout << "Closing Phonebook, beep boop." << std::endl;
	return (0);
}
