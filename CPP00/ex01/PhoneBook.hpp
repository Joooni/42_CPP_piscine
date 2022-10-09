/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:31:43 by jsubel            #+#    #+#             */
/*   Updated: 2022/09/08 15:16:35 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();

	private:
		class Contact	contacts[8];
		int				nbr_of_contacts;

	public:
		void	AddContact();
		void	SearchContact();
		void	StartScreen();
		int		GetNbrOfContacts(){return nbr_of_contacts;};
};
