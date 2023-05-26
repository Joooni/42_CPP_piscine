/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:25:23 by jsubel            #+#    #+#             */
/*   Updated: 2023/03/20 11:02:29 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"
/**
 * Lots of unique values that you have to find -> map would make the most sense
 * class BitcoinExchange
 * 	* private members:
 * 		* map<std::string, float> - database from csv
 * 	* functions:
 * 		* read csv file into a map
 * 		* main function loop
 * 			* check input and throw corresponding errors
 * 			* find the closest eligible date
 * 			* print the correct output
 */

int	ft_error(const std::string &message)
{
	std::cerr << COLOR_RED << message << END << std::endl;
	return (1);
}


void	ft_input_checker(const std::pair<std::string, double> &pair, std::map<std::string, double> database)
{
	check_date_input(pair.first, database);
	check_value(pair.second);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error(ERR_MISSING_FILE));
	std::ifstream input_file(argv[1]);
	if (!input_file.good())
		return (ft_error(ERR_NOT_READABLE));

	Database	database;
	std::string line;
	// database.printDatabase();
	while (std::getline(input_file, line))
	{
		if (line.empty())
			continue;
		try
		{
			size_t pos = line.find(" | ");
			if (pos == line.npos)
				throw (std::logic_error("Error: Bad input: " + line));
			double		value;
			size_t str_begin = line.find_first_not_of(' ');
			std::string date = line.substr(str_begin, pos - str_begin);
			value = std::atof(line.substr(pos + 3, line.npos).c_str());
			std::stringstream ss;
			ss << value;
			if (ss.str() != line.substr(pos + 3, line.npos))
				throw(std::logic_error("Error: invalid value: " + line.substr(pos + 3, line.npos)));
			std::pair<std::string, double> pair = std::make_pair<std::string, double>(date, value);
			ft_input_checker(pair, database.getDatabase());
			std::cout << pair.first << " => " << pair.second << " = " << pair.second * database.find_eligible_date(pair.first)->second << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << COLOR_RED << e.what() << END << '\n';
			continue;
		}
	}
	input_file.close();
	return (0);
}
