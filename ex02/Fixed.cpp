#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed(): mValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	mValue = (value << sFractionalBits);
}

Fixed::Fixed(const float value) {
	float fractional;
	float abs = (value > 0.0) ? value : -value;
	int fractMask = getFractionalMask();

	std::cout << "Float constructor called" << std::endl;

	mValue = static_cast<int>(value) << sFractionalBits;
	fractional = abs - static_cast<int>(abs);

	while (fractional - (static_cast<int>(fractional)) > 0.0) {
		if ((static_cast<int>(fractional * 10) & (~fractMask)) != 0) {
			break;
		}

		fractional *= 10;
	}

	mValue |= static_cast<int>(roundf(fractional)) & fractMask;
}

Fixed::Fixed(const Fixed &cpy) {
	std::cout << "Copy constructor called" << std::endl;
	mValue = cpy.getRawBits();
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Assignation operator called" << std::endl;
	mValue = rhs.getRawBits();
	return *this;
}

int Fixed::toInt() const {
	return mValue >> sFractionalBits;
}

float Fixed::toFloat() const {
	int integralPart;
	int fractPart;
	float fractDivider = 1;
	int fractMask = getFractionalMask();

	integralPart = mValue >> sFractionalBits;

	fractPart = mValue & fractMask;
	while ((fractPart / fractDivider) > 1.0f) {
		fractDivider *= 10;
	}

	return static_cast<float>(integralPart) + (static_cast<float>(fractPart) / fractDivider);
}

int Fixed::getRawBits() const {
	return mValue;
}

void Fixed::setRawBits(int const raw) {
	mValue = raw;
}

int Fixed::getFractionalMask() {
	int fractMask = 0x00;

	for (int i = 0; i < sFractionalBits; ++i) {
		fractMask |= 0x01 << i;
	}
	return fractMask;
}

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs) {
	return (lhs << rhs.toFloat());
}
