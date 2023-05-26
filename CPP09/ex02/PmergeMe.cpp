/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:18:42 by jsubel            #+#    #+#             */
/*   Updated: 2023/03/20 11:18:30 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


//-*-*-*-*-*-*-*-*-*-//
//   Vector section  //
//-*-*-*-*-*-*-*-*-*-//


/**
 * split the input vector into arbitrary pairs
 * then, sort these pairs so that for pair (a/b), a >= b
*/
void PmergeMe::splitIntoPairsVec(const std::vector<unsigned int> &input)
{
	std::vector<unsigned int>::const_iterator it = input.begin();
	std::vector<unsigned int>::const_iterator it_next = it + 1;

	while (it != input.end() && it_next != input.end())
	{
		std::pair<unsigned int, unsigned int> paired_values = std::make_pair<unsigned int, unsigned int>(*it_next, *it);
		if (*it > *(it + 1))
			paired_values = std::make_pair<unsigned int, unsigned int>(*it, *it_next);
		this->_pairs_vec.push_back(paired_values);
		// std::cout << "pair: " << paired_values.first << "/" << paired_values.second << std::endl;
		++it;
		++it;
		it_next = it + 1;
	}
}

void PmergeMe::sortPairsVec()
{
	this->InsertSort(this->_pairs_vec, 0);
}

void PmergeMe::mergeSortVec()
{
	VEC_PAIR::iterator			it = this->_pairs_vec.begin();
	std::vector<unsigned int>	pend;
	while (it != this->_pairs_vec.end())
	{
		// std::cout << "sorted: " << (*it).first << "/" << (*it).second << std::endl;
		this->_vector.push_back((*it).first);
		pend.push_back((*it++).second);
	}
	this->_vector.insert(this->_vector.begin(), pend[0]);
	pend.erase(pend.begin());
	std::vector<unsigned int> jacob_insertion_sequence = jacobsthal_sequence(pend);
	unsigned int	item;
	for (std::vector<unsigned int>::iterator it_pend = pend.begin(); it_pend != pend.end(); it_pend++)
	{
		if (jacob_insertion_sequence.size() != 0)
		{
			item = *(pend.begin() + *(jacob_insertion_sequence.begin()) - 1);
			jacob_insertion_sequence.erase(jacob_insertion_sequence.begin());
		}
		else
			item = *it_pend;
		std::vector<unsigned int>::iterator insertionpoint = std::lower_bound(this->_vector.begin(), this->_vector.end(), item);
		// std::cout << "insert " << item <<  " before " << *insertionpoint << std::endl;
		this->_vector.insert(insertionpoint, item);
	}
}

void PmergeMe::insertLeftoverVec(unsigned int n)
{
	std::vector<unsigned int>::iterator it = this->_vector.begin();
	for (;it != this->_vector.end(); it++)
	{
		if (*it > n)
		{
			this->_vector.insert(it, n);
			return ;
		}
	}
	this->_vector.insert(this->_vector.end(), n);
	return ;
}
void PmergeMe::printVector()
{
	this->printContainer(this->_vector);
}


//-*-*-*-*-*-*-*-*-*-//
//   DEQUE section   //
//-*-*-*-*-*-*-*-*-*-//

void PmergeMe::splitIntoPairsDeque(const std::vector<unsigned int> &input)
{
	std::vector<unsigned int>::const_iterator it = input.begin();
	std::vector<unsigned int>::const_iterator it_next = it + 1;

	while (it != input.end() && it_next != input.end())
	{
		std::pair<unsigned int, unsigned int> paired_values = std::make_pair<unsigned int, unsigned int>(*it_next, *it);
		if (*it > *(it + 1))
			paired_values = std::make_pair<unsigned int, unsigned int>(*it, *it_next);
		this->_pairs_deq.push_back(paired_values);
		// std::cout << "pair: " << paired_values.first << "/" << paired_values.second << std::endl;
		++it;
		++it;
		it_next = it + 1;
	}
}

void PmergeMe::sortPairsDeque()
{
	this->InsertSort(this->_pairs_deq, 0);
}

void PmergeMe::mergeSortDeque()
{
	DEQ_PAIR::iterator			it = this->_pairs_deq.begin();
	std::deque<unsigned int>	pend;
	while (it != this->_pairs_deq.end())
	{
		// std::cout << "sorted: " << (*it).first << "/" << (*it).second << std::endl;
		this->_deque.push_back((*it).first);
		pend.push_back((*it++).second);
	}
	this->_deque.insert(this->_deque.begin(), pend[0]);
	pend.erase(pend.begin());
	std::deque<unsigned int> jacob_insertion_sequence = jacobsthal_sequence(pend);
	unsigned int	item;
	for (std::deque<unsigned int>::iterator it_pend = pend.begin(); it_pend != pend.end(); it_pend++)
	{
		if (jacob_insertion_sequence.size() != 0)
		{
			item = *(pend.begin() + *(jacob_insertion_sequence.begin()) - 1);
			jacob_insertion_sequence.erase(jacob_insertion_sequence.begin());
		}
		else
			item = *it_pend;
		std::deque<unsigned int>::iterator insertionpoint = std::lower_bound(this->_deque.begin(), this->_deque.end(), item);
		// std::cout << "insert " << item <<  " before " << *insertionpoint << std::endl;
		this->_deque.insert(insertionpoint, item);
	}
}

void PmergeMe::insertLeftoverDeque(unsigned int n)
{
	std::deque<unsigned int>::iterator it = this->_deque.begin();
	for (;it != this->_deque.end(); it++)
	{
		if (*it > n)
		{
			this->_deque.insert(it, n);
			return ;
		}
	}
	this->_deque.insert(this->_deque.end(), n);
	return ;
}
void PmergeMe::printDeque()
{
	this->printContainer(this->_deque);
}


//-*-*-*-*-*-*-*-*-*-//
//  Helper functions //
//-*-*-*-*-*-*-*-*-*-//


// std::vector<unsigned int> PmergeMe::jacobsthal_sequence(std::vector<unsigned int> sequence)
// {
// 	std::vector<unsigned int>	ret;
// 	unsigned int index = 3;
// 	unsigned int last = 1;
// 	unsigned int filler;
// 	while(jacobsthal_calc(index) < sequence.size() - 1)
// 	{
// 		ret.push_back(jacobsthal_calc(index));
// 		filler = jacobsthal_calc(index) - 1;
// 		while (filler > last)
// 		{
// 			ret.push_back(filler);
// 			filler--;
// 		}
// 		last = jacobsthal_calc(index);
// 		index++;
// 	}
// 	return (ret);
// }

unsigned int PmergeMe::jacobsthal_calc(unsigned int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return(jacobsthal_calc(n - 1) + 2 * (jacobsthal_calc(n - 2)));
}

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &rhs): _vector(rhs._vector), _deque(rhs._deque), _pairs_vec(rhs._pairs_vec), _pairs_deq(rhs._pairs_deq)
{

}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	this->_vector = rhs._vector;
	this->_deque = rhs._deque;
	this->_pairs_vec = rhs._pairs_vec;
	this->_pairs_deq = rhs._pairs_deq;
	return (*this);
}

PmergeMe::~PmergeMe()
{

}

float	gettime(t_timeval start)
{
	t_timeval	tv;
	float			time_diff;

	gettimeofday(&tv, NULL);
	time_diff = (tv.tv_sec - start.tv_sec) * 1000000;
	time_diff += (tv.tv_usec - start.tv_usec);
	return (time_diff);
}

bool isValidNumber(char *input)
{
	long nbr = atoi(input);
	std::stringstream ss;
	ss << nbr;
	if (!(ss.str() == std::string(input)) || nbr < 0 || nbr > std::numeric_limits<int>::max())
		return false;
	return (true);
}

int	ft_error(const std::string &message)
{
	std::cerr << COLOR_RED << message << END << std::endl;
	return (1);
}

