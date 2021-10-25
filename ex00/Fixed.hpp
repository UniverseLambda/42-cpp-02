#pragma once

class Fixed {
private:
	int mValue;
	static const int sFractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &cpy);
	~Fixed();

	Fixed &operator=(const Fixed &rhs);

	int getRawBits() const;
	void setRawBits(int const raw);
};
