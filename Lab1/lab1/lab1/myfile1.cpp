
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
	std::cout << std::endl;

	//declaring
	int holder;
	float holderf;
	char holderc;
	std::cout << "Enter an Integer: ";
	std::cin >> holder;
	std::cout << std::endl;

	//method 1
	std::cout << "number in decimal " << std::dec << holder << std::endl;
	std::cout << "number in octal " << std::oct << holder << std::endl;
	std::cout << "number in hexa " << std::hex << holder << std::endl;
	std::cout << std::endl;
	//method 2
	std::cout << std::dec;
	std::cout << "number in decimal ";
	std::cout << holder << std::endl;
	std::cout << "Number in octal: ";
	std::cout << std::oct << holder << std::endl;                
	std::cout << "Number in hex: ";
	std::cout << std::hex << holder << std::endl;    
	std::cout << std::endl;

	//with and without power of 10 float input
	std::cout << "Enter a real number: ";
	std::cin >> holderf;
	std::cout << std::fixed << std::setprecision(3) <<  holderf << std::endl;
	std::cout << std::hexfloat << holderf << std::endl;
	std::cout << std::endl;

	//char entry and value display
	std::cout << "Enter a character: ";
	std::cin >> holderc;
	std::cout << holderc << std :: endl;
	std::cout << static_cast<int>(holderc) << std::endl;


	
	return 0;
}