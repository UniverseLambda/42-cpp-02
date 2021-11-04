#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed(): mValue(0) {
}

Fixed::Fixed(const int value) {
	mValue = (value << sFractionalBits);
}

Fixed::Fixed(const float value) {
	int scalingFactor = 1 << sFractionalBits;

	mValue = static_cast<int>(roundf(value * scalingFactor));
}

Fixed::Fixed(const Fixed &cpy) {
	mValue = cpy.getRawBits();
}

Fixed::~Fixed() {
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	mValue = rhs.getRawBits();
	return *this;
}

bool Fixed::operator==(const Fixed &rhs) const {
	return getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return !(*this == rhs);
}

bool Fixed::operator>(const Fixed &rhs) const {
	return getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const {
	return getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return *this > rhs || *this == rhs;
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return *this < rhs || *this == rhs;
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	Fixed result;

	result.setRawBits(getRawBits() + rhs.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed result;

	result.setRawBits(getRawBits() - rhs.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	Fixed result;

	result.setRawBits((getRawBits() * rhs.getRawBits()) >> sFractionalBits);
	return result;
}

// Lazy I am.
Fixed Fixed::operator/(const Fixed &rhs) const {
	return toFloat() / rhs.toFloat();
}

Fixed &Fixed::operator++() {
	setRawBits(getRawBits() + 0x01);
	return *this;
}

Fixed &Fixed::operator--() {
	setRawBits(getRawBits() - 0x01);
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed result(*this);

	++(*this);

	return result;
}

Fixed Fixed::operator--(int) {
	Fixed result(*this);

	--(*this);

	return result;
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

Fixed &Fixed::min(Fixed &first, Fixed &second) {
	return (first < second) ? first : second;
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second) {
	return (first < second) ? first : second;
}

Fixed &Fixed::max(Fixed &first, Fixed &second) {
	return (first > second) ? first : second;
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second) {
	return (first > second) ? first : second;
}

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs) {
	return (lhs << rhs.toFloat());
}
