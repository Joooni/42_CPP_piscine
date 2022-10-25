#include "Data.hpp"


uintptr_t Data::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Data::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}


Data::Data()
{

}

Data::Data(const Data &src)
{
	this->_str = src._str;
	this->_c = src._c;
	this->_i = src._i;
	this->_f = src._f;
	this->_d = src._d;
}

Data &Data::operator=(const Data &rhs)
{
	this->_str = rhs._str;
	this->_c = rhs._c;
	this->_i = rhs._i;
	this->_f = rhs._f;
	this->_d = rhs._d;
	return (*this);
}

Data::~Data()
{

}

std::string Data::getString()
{
	return (this->_str);
}

char		Data::getChar()
{
	return (this->_c);
}

int			Data::getInt()
{
	return (this->_i);
}

float		Data::getFloat()
{
	return (this->_f);
}

double		Data::getDouble()
{
	return (this->_d);
}

void	Data::setString(std::string str)
{
	this->_str = str;
}

void	Data::setChar(char c)
{
	this->_c = c;
}

void	Data::setInt(int i)
{
	this->_i = i;
}

void	Data::setFloat(float f)
{
	this->_f = f;
}

void	Data::setDouble(double d)
{
	this->_d = d;
}
