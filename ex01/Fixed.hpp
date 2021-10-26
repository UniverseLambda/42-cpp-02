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

	operator float() const;
	operator int() const;

	int toInt() const;
	float toFloat() const;

	int getRawBits() const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs);
