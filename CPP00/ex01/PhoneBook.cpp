/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 09:11:28 by jsubel            #+#    #+#             */
/*   Updated: 2022/09/05 13:11:33 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->nbr_of_contacts = 0;
}

PhoneBook::~PhoneBook()
{

}

/* void	PhoneBook::AddContact()
{
	Contact NewContact;
	std::string	input;

	std::cout << "Enter first name: ";
	getline(std::cin, input);
	while(input.empty())
	{
		std::cout << "Fields can't be empty! Please input something." << std::endl;
		getline(std::cin, input);
	}
	NewContact.SetFirstName(input);
	std::cout << "Enter last name: ";
		getline(std::cin, input);
	while(input.empty())
	{
		std::cout << "Fields can't be empty! Please input something." << std::endl;
		getline(std::cin, input);
	}
	NewContact.SetLastName(input);
	std::cout << "Enter nickname: ";
		getline(std::cin, input);
	while(input.empty())
	{
		std::cout << "Fields can't be empty! Please input something." << std::endl;
		getline(std::cin, input);
	}
	NewContact.SetNickname(input);
	std::cout << "Enter phonenumber: ";
		getline(std::cin, input);
	while(input.empty())
	{
		std::cout << "Fields can't be empty! Please input something." << std::endl;
		getline(std::cin, input);
	}
	NewContact.SetPhoneNumber(input);
	std::cout << "And now, just between us squirrel friends, what's that persons darkest secret...? ";
		getline(std::cin, input);
	while(input.empty())
	{
		std::cout << "Fields can't be empty! Please input something." << std::endl;
		getline(std::cin, input);
	}
	NewContact.SetSecret(input);
	if (this->nbr_of_contacts >= 8)
		NewContact.SetIndex(nbr_of_contacts % 8);
	else
		NewContact.SetIndex(this->nbr_of_contacts);
	std::cout << "Great - adding new contact with that info." << std::endl;
	this->contacts[NewContact.GetIndex()] = NewContact;
	this->nbr_of_contacts += 1;
	std::cout << "Please enter one of the following commands: ADD, SEARCH or EXIT" << std::endl;
} */

void	PhoneBook::AddContact()
{
	Contact NewContact;
	std::string	input;

	std::cout << "Enter first name: ";
	while(getline(std::cin, input))
	{
		if (input.empty())
			std::cout << "Fields can't be empty! Please input something." << std::endl;
		else
			break;
	}
	NewContact.SetFirstName(input);
	std::cout << "Enter last name: ";
	while(getline(std::cin, input))
	{
		if (input.empty())
			std::cout << "Fields can't be empty! Please input something." << std::endl;
		else
			break;
	}
	NewContact.SetLastName(input);
	std::cout << "Enter nickname: ";
	while(getline(std::cin, input))
	{
		if (input.empty())
			std::cout << "Fields can't be empty! Please input something." << std::endl;
		else
			break;
	}
	NewContact.SetNickname(input);
	std::cout << "Enter phonenumber: ";
	while(getline(std::cin, input))
	{
		if (input.empty())
			std::cout << "Fields can't be empty! Please input something." << std::endl;
		else
			break;
	}
	NewContact.SetPhoneNumber(input);
	std::cout << "And now, just between us squirrel friends, what's that persons darkest secret...? ";
	while(getline(std::cin, input))
	{
		if (input.empty())
			std::cout << "Fields can't be empty! Please input something." << std::endl;
		else
			break;
	}
	NewContact.SetSecret(input);
	if (this->nbr_of_contacts >= 8)
		NewContact.SetIndex(nbr_of_contacts % 8);
	else
		NewContact.SetIndex(this->nbr_of_contacts);
	std::cout << "Great - adding new contact with that info." << std::endl;
	this->contacts[NewContact.GetIndex()] = NewContact;
	this->nbr_of_contacts += 1;
	std::cout << "Please enter one of the following commands: ADD, SEARCH or EXIT" << std::endl;
}

void	PhoneBook::StartScreen()
{
	std::cout << "Allocating paper, boop beep... Initializing pages, beep boop... " << std::endl;
	std::cout << "(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ Welcome to your Phonebook ✧ﾟ･: *ヽ(◕ヮ◕ヽ)" << std::endl;
	std::cout << "Please enter one of the following commands: ADD, SEARCH or EXIT" << std::endl;
}

void	PhoneBook::SearchContact()
{
	std::string	input;
	int			index = 0;

	std::cout << std::right << std::setw(10) << "Index" << "|" << std::right << std::setw(10) << "First Name" << "|" << std::right << std::setw(10) << "Last Name" << "|" << std::right << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
		contacts[i].PrintSummary(i + 1);
	std::cout << "Which contact would you like to access?" << std::endl;
	while (getline(std::cin, input))
	{
		index = atoi(input.c_str());
		if (index < 1 || index > 8 || index > nbr_of_contacts)
			std::cout << "No! That is the wrong input." << std::endl;
		else
		{
			contacts[index - 1].DisplayInfo();
			break ;
		}
	}
	std::cin.clear();
	std::cout << "Please enter one of the following commands: ADD, SEARCH or EXIT" << std::endl;
}
