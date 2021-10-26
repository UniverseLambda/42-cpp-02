#pragma once

#include <iostream>

class Fixed {
private:
	int mValue;
	static const int sFractionalBits = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &cpy);
	~Fixed();

	Fixed &operator=(const Fixed &rhs);

	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;
	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;

	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	Fixed &operator++();
	Fixed &operator--();

	Fixed operator++(int) const;
	Fixed operator--(int) const;

	operator float() const;
	operator int() const;

	int toInt() const;
	float toFloat() const;

	int getRawBits() const;
	void setRawBits(int const raw);

	static Fixed &min(Fixed &first, Fixed &second);
	static const Fixed &min(const Fixed &first, const Fixed &second);
	static Fixed &max(Fixed &first, Fixed &second);
	static const Fixed &max(const Fixed &first, const Fixed &second);
};

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs);
