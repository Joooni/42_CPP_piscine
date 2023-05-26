/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:18:45 by jsubel            #+#    #+#             */
/*   Updated: 2023/03/20 11:22:24 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		return (ft_error("Not enough arguments"));
	if (argc == 2)
		return (0);
	PmergeMe sorter;
	t_timeval start;
	float vectime;
	float deqtime;
	float setuptime;
	bool leftover_element;
	std::vector<unsigned int> input;
	(argc % 2 ? leftover_element = 0 : leftover_element = 1);


	TIMER_START;
	for (int i = 1; i < argc; i++)
	{
		if (!isValidNumber(argv[i]))
		{
			std::string msg("Error: not a valid number: ");
			msg.append(argv[i]);
			return (ft_error(msg));
		}
		input.push_back(atoi(argv[i]));
	}
	if (isSorted(input) && input.size() > 1)
	{
		std::cout << COLOR_GREEN << "Input is already sorted" << END << std::endl;
		return (0);
	}
	TIMER_SETUP;
	std::cout << "Before:\t";
	sorter.printContainer(input);
	TIMER_START;
	sorter.splitIntoPairsVec(input);
	sorter.sortPairsVec();
	sorter.mergeSortVec();
	if (leftover_element)
		sorter.insertLeftoverVec(input.back());
	std::cout << "After:\t";
	sorter.printVector();
	TIMER_VECTOR;
	std::cout << "\nInput reading time:\t" << COLOR_GREEN <<  setuptime << "µs" << END << std::endl;
	std::cout << "Time to process a range of " << input.size() << " with std::vector:\t" << COLOR_GREEN << vectime << "µs" << END;
	TIMER_START;
	sorter.splitIntoPairsDeque(input);
	sorter.sortPairsDeque();
	sorter.mergeSortDeque();
	if (leftover_element)
		sorter.insertLeftoverDeque(input.back());
	TIMER_DEQ;
	std::cout << "\nTime to process a range of " << input.size() << " with std::deque:\t" << COLOR_GREEN <<  deqtime << "µs" << END << std::endl;
	return (0);
}
