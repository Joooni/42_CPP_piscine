/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:04:04 by jsubel            #+#    #+#             */
/*   Updated: 2022/09/30 13:15:47 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->index = 0;
}

Contact::~Contact()
{

}

void	Contact::DisplayInfo()
{
	std::cout << "First name: " << this->GetFirstName() << std::endl;
	std::cout << "Last name: " << this->GetLastName() << std::endl;
	std::cout << "Nickname: " << this->GetNickname() << std::endl;
	std::cout << "Phone number: " << this->GetPhoneNumber() << std::endl;
	std::cout << "Their darkest secret... " << this->GetSecret() << std::endl;
}

std::string Contact::TrimString(std::string str)
{
	if (str.length() >= 10)
		str = str.substr(0, 9).append(".");
	return (str);
}

void	Contact::PrintSummary(int index)
{
	std::cout << std::setfill(' ') << std::setw(10) << index;
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << TrimString(first_name);
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << TrimString(last_name);
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << TrimString(nickname);
	std::cout << "|";
	std::cout << std::endl;
}