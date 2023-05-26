#include "RPN.hpp"

RPNCalc::RPNCalc(const std::string &input)
{
	std::string tmp;
	std::string cpy(input);
	std::string valid_chars("0123456789+-*/");
	if (cpy[0] == ' ')
		throw(std::logic_error("Error: invalid character"));
	std::istringstream stream(cpy);
	while (std::getline(stream, tmp, ' '))
	{
		if (!(isValidNumber(tmp) || isSign(tmp)))
			throw(std::logic_error("Error: invalid character"));
		else if (this->_stack.size() < 2 && isSign(tmp))
			throw(std::logic_error("Error: wrong operation"));
		else if (isSign(tmp))
			calculate(tmp);
		else if (isValidNumber(tmp))
			this->_stack.push(atoi(tmp.c_str()));
		else
			throw(std::logic_error("Error: stack size"));
	}
	if (this->_stack.size() > 1)
		throw(std::logic_error("Error: more than one items left on stack"));
	std::cout << this->_stack.top() << std::endl;
}

bool RPNCalc::isValidNumber(const std::string &input)
{
	int nbr = atoi(input.c_str());
	std::stringstream ss;
	ss << nbr;
	if (!(ss.str() == input) || (nbr > 9 || nbr < -9))
		return false;
	return (true);
}

bool RPNCalc::isSign(const std::string &input)
{
	std::string valid_chars("+-*/");
	if (valid_chars.find(input[0]) == input.npos || input.length() > 1)
		return (false);
	return (true);
}

void RPNCalc::calculate(const std::string &operand)
{
	int nbr2 = this->_stack.top();
	this->_stack.pop();
	int nbr1 = this->_stack.top();
	this->_stack.pop();
	if (operand[0] == '+')
		this->_stack.push(nbr1 + nbr2);
	else if (operand[0] == '-')
		this->_stack.push(nbr1 - nbr2);
	else if (operand[0] == '*')
		this->_stack.push(nbr1 * nbr2);
	else if (operand[0] == '/')
	{
		if (nbr2 == 0)
			throw (std::logic_error("Error: divide by zero"));
		this->_stack.push(nbr1 / nbr2);
	}
}

RPNCalc::~RPNCalc()
{

}


RPNCalc::RPNCalc()
{

}

RPNCalc::RPNCalc(const RPNCalc &rhs): _stack(rhs._stack)
{

}

RPNCalc &RPNCalc::operator=(const RPNCalc &rhs)
{
	this->_stack = rhs._stack;
	return (*this);
}
