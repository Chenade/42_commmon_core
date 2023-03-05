# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;

	public:
		// Constructor
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed& fixed);
		
		// Deconstructor
		~Fixed();
		
		// Operator
		Fixed& operator=(const Fixed& fixed);
		Fixed operator+(const Fixed& fixed);
		Fixed operator-(const Fixed& fixed);
		Fixed operator*(const Fixed& fixed);
		Fixed operator/(const Fixed& fixed);
		
		// Comparsion
		bool operator<(const Fixed& fixed);
		bool operator<=(const Fixed& fixed);
		bool operator>(const Fixed& fixed);
		bool operator>=(const Fixed& fixed);
		bool operator==(const Fixed& fixed);
		bool operator!=(const Fixed& fixed);

		// Increment / Decrement
		Fixed&   operator++ (void);
		Fixed   operator++ (int);
		Fixed&   operator-- (void);
		Fixed   operator-- (int);

		//Function
		static Fixed& 	min(Fixed& a, Fixed& b);
		static const Fixed& 	min(const Fixed& a, const Fixed& b);
		static Fixed& 	max(Fixed& a, Fixed& b);
		static const Fixed& 	max(const Fixed& a, const Fixed& b);
		
		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		float 	toFloat(void) const;
		int 	toInt(void) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif