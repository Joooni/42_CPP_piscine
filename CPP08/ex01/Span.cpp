#include "Span.hpp"

Span::Span(): _N(0)
{
	if (M_DEBUG)
		std::cout << COLOR_GREEN  << "[Span]" << END << " Constructor called" << std::endl;
}

Span::Span(unsigned int N): _N(N)
{
	if (M_DEBUG)
		std::cout << COLOR_GREEN  << "[Span]" << END << " parameterized Constructor called" << std::endl;
}

Span::Span(const Span &src): _content(src._content), _N(src._N)
{
	if (M_DEBUG)
		std::cout << COLOR_GREEN  << "[Span]" << END << " Copy Constructor called" << std::endl;
}

Span &Span::operator=(const Span &rhs)
{
	this->_content.clear();
	this->_N = rhs._N;
	this->_content.insert(this->_content.begin(), rhs._content.begin(), rhs._content.end());
	if (M_DEBUG)
		std::cout << COLOR_YELLOW  << "[Span]" << END << " copy assignment operator called" << std::endl;
	return (*this);
}

Span::~Span()
{
		if (M_DEBUG)
			std::cout << COLOR_RED  << "[Span]" << END << " Destructor called" << std::endl;
}

void	Span::addNumber(int nbr)
{
	if (this->_content.size() >= this->_N)
		throw Span::OutOfCapacityException();
	this->_content.push_back(nbr);
}

void Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		if (this->_content.size() >= this->_N)
			throw Span::OutOfCapacityException();
		this->addNumber(*begin);
		begin++;
	}
}

void	Span::replace(int oldValue, int newValue)
{
	std::replace(this->_content.begin(), this->_content.end(), oldValue, newValue);
}

unsigned int Span::shortestSpan()
{
	if (this->_content.size() < 2)
		throw Span::SizeTooSmallException();
	std::vector<int> tmp = this->_content;
	std::sort(tmp.begin(), tmp.end());
	unsigned int	shortest = *(tmp.begin() + 1) - *tmp.begin();
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
		shortest = std::min(shortest, static_cast<unsigned int>(*(it + 1) - *it));
	return (shortest);
}

unsigned int Span::longestSpan()
{
	if (this->_content.size() < 2)
		throw Span::SizeTooSmallException();
	return (*max_element(this->_content.begin(), this->_content.end()) - *min_element(this->_content.begin(), this->_content.end()));
}

const char *Span::OutOfCapacityException::what() const throw()
{
	return ("\033[31mThis instance is out of capacity\033[0m");
}

const char *Span::SizeTooSmallException::what() const throw()
{
	return ("\033[31mNot enough elements in this instance\033[0m");
}
