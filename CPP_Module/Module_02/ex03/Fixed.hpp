#include <iostream>

class Fixed
{
	private:
		static int const _fraction = 8;
		int _fixedPoint;

	public:
		// Constructors/Destructors
		Fixed(void);
		Fixed(int const val);
		Fixed(float const val);
		Fixed(const Fixed& fixed);
		~Fixed(void);

		Fixed& operator=(const Fixed& rhs);

		//Comparison operators
		bool operator>(const Fixed& rhs)
		bool operator<(const Fixed& rhs);
		bool operator>=(const Fixed& rhs);
		bool operator<=(const Fixed& rhs);
		bool operator==(const Fixed& rhs);
		bool operator!=(const Fixed& rhs);

		//Arithmetic operators
		Fixed operator+(const Fixed& rhs);
		Fixed operator-(const Fixed& rhs);
		Fixed operator*(const Fixed& rhs);
		Fixed operator/(const Fixed& rhs);

		//Increment/decrement
		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		// Function
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static			Fixed& min(Fixed& a, Fixed& b);
		static const	Fixed& min(const Fixed& a, const Fixed& b);
		static			Fixed& max(Fixed& a, Fixed& b);
		static const	Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);