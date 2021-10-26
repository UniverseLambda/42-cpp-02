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
	int scalingFactor = 1 << sFractionalBits;

	std::cout << "Float constructor called" << std::endl;

	mValue = static_cast<int>(roundf(value * scalingFactor));
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

Fixed::operator float() const {
	return toFloat();
}

Fixed::operator int() const {
	return toInt();
}

int Fixed::toInt() const {
	return mValue >> sFractionalBits;
}

float Fixed::toFloat() const {
	int scalingFactor = 1 << sFractionalBits;

	return static_cast<float>(mValue) / scalingFactor;
}

int Fixed::getRawBits() const {
	return mValue;
}

void Fixed::setRawBits(int const raw) {
	mValue = raw;
}

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs) {
	return (lhs << rhs.toFloat());
}
