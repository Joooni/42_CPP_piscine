#include "Data.hpp"

int	main(void)
{
	std::cout << std::string(50, '-') << std::endl;
	std::cout << "\t\tTEST 1" << std::endl;
	{
		Data *original = new Data;
		Data *copy;
		uintptr_t uptr;
		original->setString("An iced coffee with Augenzwinkern and a good book.");
		std::cout << "original:\t" << original << ":\t" << original->getString() << std::endl;
		uptr = original->serialize(original);
		std::cout << "uptr:\t\t" << std::hex << "0x" << uptr << std::dec << std::endl;
		copy = original->deserialize(uptr);
		std::cout << "copy:\t\t" << copy << ":\t" << copy->getString() << std::endl;
		delete original;
	}
	std::cout << std::string(50, '-') << std::endl;
	std::cout << "\t\tTEST 2" << std::endl;
	{
		Data		*myData = new Data;
		uintptr_t	rawData;

		myData->setString("Bratan");
		myData->setChar('P');
		myData->setInt(15);
		myData->setFloat(08.15f);
		myData->setDouble(420.69);
		std::cout << "string : " << myData->getString() << std::endl;
		std::cout << "char   : " << myData->getChar() << std::endl;
		std::cout << "int    : " << myData->getInt() << std::endl;
		std::cout << "float  : " << myData->getFloat() << std::endl;
		std::cout << "double : " << myData->getDouble() << std::endl;
		std::cout << "Pointer to data structure before serialization: " << &myData << std::endl;

		rawData = myData->serialize(myData);

		std::cout << std::endl;

		myData = myData->deserialize(rawData);

		std::cout << "Pointer to data structure after deserialization: " << &myData << std::endl;
		std::cout << "string : " << myData->getString() << std::endl;
		std::cout << "char   : " << myData->getChar() << std::endl;
		std::cout << "int    : " << myData->getInt() << std::endl;
		std::cout << "float  : " << myData->getFloat() << std::endl;
		std::cout << "double : " << myData->getDouble() << std::endl;
		delete myData;
	}
	return (0);
}