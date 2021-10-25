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

	int toInt() const;
	float toFloat() const;

	int getRawBits() const;
	void setRawBits(int const raw);

private:
	static int getFractionalMask();
};

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs);
