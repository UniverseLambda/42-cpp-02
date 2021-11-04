#include "Fixed.hpp"
#include <iostream>

int main(void) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "==================================================" << std::endl;
	std::cout << "a:     " << a << std::endl;
	std::cout << "b:     " << b << std::endl;
	std::cout << "a + b: " << (a + b) << std::endl;
	std::cout << "a - b: " << (a - b) << std::endl;
	std::cout << "a * b: " << (a * b) << std::endl;
	std::cout << "a / b: " << (a / b) << std::endl;
	std::cout << "b + a: " << (b + a) << std::endl;
	std::cout << "b - a: " << (b - a) << std::endl;
	std::cout << "b * a: " << (b * a) << std::endl;
	std::cout << "b / a: " << (b / a) << std::endl;

	std::cout << "5 * 2: " << (Fixed(5) * Fixed(2)) << std::endl;
	std::cout << "5 / 2: " << (Fixed(5) / Fixed(2)) << std::endl;

	std::cout << "10.5 * 2: " << (Fixed(10.5f) * Fixed(2)) << std::endl;
	std::cout << "26.456 * 23.2: " << (Fixed(26.456f) * Fixed(23.2f)) << std::endl;
	return 0;
}
