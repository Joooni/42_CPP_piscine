#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <algorithm>
# include <iostream>
# include <string>
# include <stdint.h>

class Data
{
	public:
		Data();
		Data(const Data &src);
		Data &operator=(const Data &rhs);
		~Data();

		uintptr_t serialize(Data *ptr);
		Data *deserialize(uintptr_t raw);

		std::string getString();
		char		getChar();
		int			getInt();
		float		getFloat();
		double		getDouble();

		void		setString(std::string str);
		void		setChar(char c);
		void		setInt(int i);
		void		setFloat(float f);
		void		setDouble(double d);

	private:
		std::string	_str;
		char		_c;
		int			_i;
		float		_f;
		double		_d;
};

#endif
