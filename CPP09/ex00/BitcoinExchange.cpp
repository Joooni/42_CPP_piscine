/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:25:27 by jsubel            #+#    #+#             */
/*   Updated: 2023/03/20 11:05:01 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Database::Database()
{
	std::ifstream input_file("data.csv");
	if (!input_file.good())
	{
		std::cerr << COLOR_RED << ERR_MISSING_FILE << END << std::endl;
		return ;
	}
	std::string	line;
	std::string	date;
	double		value;
	while (std::getline(input_file, line))
	{
		size_t pos = line.find(',');
		if (pos == line.npos)
			continue;
		date = line.substr(0, pos);
		value = std::atof(line.substr(pos + 1, line.npos).c_str());
		try
		{
			check_date(date);
		}
		catch(const std::exception& e)
		{
			std::cerr << COLOR_RED << e.what() << END << '\n';
			continue;
		}
		this->_database.insert(std::make_pair<std::string, float>(date, value));
	}
	input_file.close();
}

Database::Database(const Database &rhs): _database(rhs._database)
{
}

Database &Database::operator=(const Database &rhs)
{
	(*this)._database = rhs._database;
	return (*this);
}

Database::~Database()
{

}

void Database::printDatabase()
{
	for (std::map<std::string, double>::iterator it_beg = this->_database.begin(); it_beg != this->_database.end(); it_beg++)
		std::cout << (*it_beg).first << "/" << (*it_beg).second << std::endl;
}

std::map<std::string, double> Database::getDatabase()
{
	return (this->_database);
}

std::map<std::string, double>::iterator Database::find_eligible_date(const std::string &date)
{
	std::map<std::string, double>::iterator it = this->_database.upper_bound(date);
	return (--it);
}

void check_date(const std::string &date)
{
	int year = -1;
	int month = -1;
	int day = -1;

	sscanf(date.c_str(), "%d-%2d-%2d",&year,&month,&day);
	unsigned int leap;
	unsigned char mon_day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	std::stringstream ss;
	ss << "Date: '" << date << "': ";

	if (year < 1)
		throw (std::logic_error(ss.str() + "Date format is wrong"));
	if ((month < 1) || (month > 12))
		throw (std::logic_error(ss.str() + "Date format is wrong"));
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		leap = 1;
	else
		leap = 0;

	mon_day[1] += leap;
	if ((day > mon_day[month - 1]) || (day < 1))
		throw (std::logic_error(ss.str() + "Date format is wrong"));
}

void check_date_input(const std::string &date, std::map<std::string, double> database)
{
	int year = -1;
	int year_start = -1;
	int year_end = -1;
	int month = -1;
	int day = -1;
	int check = -1;

	sscanf(date.c_str(), "%d-%d-%d %n",&year,&month,&day, &check);
	std::stringstream ss;
	ss << "Error: Date: '" << date << "': ";
	if (check != 10)
		throw (std::logic_error(ss.str() + "Date format is wrong"));
	sscanf(database.begin()->first.c_str(), "%d-%*d-%*d",&year_start);
	sscanf(database.rbegin()->first.c_str(), "%d-%*d-%*d",&year_end);
	unsigned int leap;
	unsigned char mon_day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (year < 1 || year < year_start || year > year_end)
		throw (std::logic_error(ss.str() + "Date format is wrong"));
	if ((month < 1) || (month > 12))
		throw (std::logic_error(ss.str() + "Date format is wrong"));
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		leap = 1;
	else
		leap = 0;

	mon_day[1] += leap;

	if ((day > mon_day[month - 1]) || (day < 1))
		throw (std::logic_error(ss.str() + "Date format is wrong"));
}

void check_value(double value)
{
	std::stringstream ss;
	ss << value;

	if (value < 0 || value > 1000)
		throw (std::logic_error("Error: Invalid value - " + ss.str()));
}
