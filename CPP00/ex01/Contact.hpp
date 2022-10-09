/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:57:43 by jsubel            #+#    #+#             */
/*   Updated: 2022/06/15 17:55:32 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>


class Contact {
	public:
		Contact();
		~Contact();

	private:
		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	secret;

	public:
		std::string	GetFirstName(){return first_name;};
		void		SetFirstName(std::string new_first_name){first_name = new_first_name;};
		std::string	GetLastName(){return last_name;};
		void		SetLastName(std::string new_last_name){last_name = new_last_name;};
		std::string	GetNickname(){return nickname;};
		void		SetNickname(std::string new_nickname){nickname = new_nickname;};
		std::string	GetPhoneNumber(){return phone_number;};
		void		SetPhoneNumber(std::string new_phonenumber){phone_number = new_phonenumber;};
		std::string	GetSecret(){return secret;};
		void		SetSecret(std::string new_secret){secret = new_secret;};
		void		DisplayInfo();
		int			GetIndex(){return index;};
		void		SetIndex(int new_index){index = new_index;};
		std::string TrimString(std::string str);
		void		PrintSummary(int index);
};