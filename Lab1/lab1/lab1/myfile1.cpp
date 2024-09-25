
#include "myfile1.h"
int main()
{
	//showing all data type sizes using sizeof() fnct
	std::cout << "Size in bytes of a character: " << sizeof(char) << std::endl;
	std::cout << "Size in bytes of a Integer: " << sizeof(int) << std::endl;
	std::cout << "Size in bytes of a float: " << sizeof(float) << std::endl;
	std::cout << "Size in bytes of a double: " << sizeof(double) << std::endl;
	std::cout << "Size in bytes of a short Integer: " << sizeof(short) << std::endl;
	std::cout << "Size in bytes of a unsigned Integer: " << sizeof(unsigned) << std::endl;

	//declaring
	int holder;
	std::cout << "Enter an Integer: ";
	std::cin >> holder;

	//method 1
	std::cout << "number in decimal " << std::dec << holder << std::endl;
	std::cout << "number in octal " << std::oct << holder << std::endl;
	std::cout << "number in hexa " << std::hex << holder << std::endl;
	//method 2

	
	return 0;
}