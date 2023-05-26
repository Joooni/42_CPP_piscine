/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:25:20 by jsubel            #+#    #+#             */
/*   Updated: 2023/03/20 10:36:45 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>

#define ERR_MISSING_FILE	"Error - missing input file"
#define ERR_NOT_READABLE	"Error - input file not readable"
#define ERR_WRONG_FORMAT	"Error - bad input"
#define COLOR_RED			"\033[31m"
#define END					"\033[0m"

class Database
{
	public:
		Database();
		Database(const Database &rhs);
		Database &operator=(const Database &rhs);
		~Database();
		std::map<std::string, double>			getDatabase();
		std::map<std::string, double>::iterator find_eligible_date(const std::string &date);
		void printDatabase();


	private:
		std::map<std::string, double> _database;
};

void check_date(const std::string &date);
void check_date_input(const std::string &date, std::map<std::string, double> database);
void check_value(double value);

#endif
