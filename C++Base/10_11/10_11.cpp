#include <iostream>

int main() {
	std::cout << "Hello" << std::endl;
	int len = 10;
	char* chars = new char(len);
	chars[0] = 'a';
	chars[2] = 'b';
	chars[3] = 'c';
	chars[4] = '3';

	std::cout << sizeof(chars) << " " << chars[0] << chars[2] << chars[3] << chars[4] << std::endl;

	char chars_2[6];
	std::cout << sizeof(chars_2) << std::endl;

	return 0;
}