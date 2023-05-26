/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:18:40 by jsubel            #+#    #+#             */
/*   Updated: 2023/03/20 11:19:09 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>
#include <limits>
#include <sstream>


typedef struct timeval	t_timeval;

#define TIMER_START		gettimeofday(&start, NULL)
#define TIMER_VECTOR	vectime = gettime(start)
#define TIMER_DEQ		deqtime = gettime(start)
#define TIMER_SETUP		setuptime = gettime(start)

#define VEC_PAIR		std::vector< std::pair<unsigned int, unsigned int> >
#define DEQ_PAIR		std::deque< std::pair<unsigned int, unsigned int> >


#define COLOR_RED			"\033[31m"
#define COLOR_GREEN			"\033[1;32m"
#define END					"\033[0m"

class PmergeMe {
	private:
		std::vector<unsigned int>	_vector;
		std::deque<unsigned int>	_deque;
		VEC_PAIR	_pairs_vec;
		DEQ_PAIR	_pairs_deq;
		PmergeMe(const PmergeMe &rhs);
		PmergeMe &operator=(const PmergeMe &rhs);

	public:
		PmergeMe();
		~PmergeMe();

		void splitIntoPairsVec(const std::vector<unsigned int> &input);
		void sortPairsVec();
		void mergeSortVec();
		void insertLeftoverVec(unsigned int n);
		void printVector();

		void splitIntoPairsDeque(const std::vector<unsigned int> &input);
		void sortPairsDeque();
		void mergeSortDeque();
		void insertLeftoverDeque(unsigned int n);
		void printDeque();

		template <class T>
		T jacobsthal_sequence(T sequence)
		{
			T	ret;
			unsigned int index = 3;
			ret.push_back(1);
			if (sequence.size() > 3)
			{
				while(jacobsthal_calc(index) < sequence.size() - 1)
				{
					ret.push_back(jacobsthal_calc(index));
					index++;
				}
			}
			return (ret);
		}
		unsigned int 				jacobsthal_calc(unsigned int n);
		template <class T>
		void printContainer(T &container)
		{
			typename T::iterator it_cont = container.begin();
			for (; it_cont != container.end(); it_cont++)
				std::cout << *it_cont << " ";
			std::cout << std::endl;
		}

		template<class T>
		void    InsertSort(T& to_sort, size_t diff)
		{
			if (to_sort.empty() == true || std::distance(to_sort.begin(), (to_sort.end() - diff)) == 1)
				return;
			std::pair<unsigned int, unsigned int> temp = *to_sort.begin();
			std::pair<unsigned int, unsigned int> last = temp;
			to_sort.erase(to_sort.begin());
			for (typename T::iterator it = to_sort.begin(); it != to_sort.end() - diff; it++) {
				if (it->first > last.first) {
					last = *it;
					*it = temp;
					temp = last;
				}
			}
			to_sort.insert(to_sort.begin() + std::distance(to_sort.begin(), (to_sort.end() - diff)), last);
			InsertSort(to_sort, ++diff);
		}
};

float	gettime(t_timeval start);
bool isValidNumber(char *input);
int	ft_error(const std::string &message);

template <class T>
bool isSorted(const T& container)
{
	typename T::const_iterator it = container.begin();
	typename T::const_iterator it_next = container.begin();
	it_next++;
	while (it_next != container.end())
	{
		if (*it > *it_next)
			return (false);
		++it;
		++it_next;
	}
	return (true);
}

#endif
