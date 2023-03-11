# ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

enum e_type {
	NONE,
	INT,
	FLOAT,
	CHAR,
	DOUBLE,
	LITERALS
};

class ScalarConverter
{
	private:
		char	_c;
		int		_n;
		float	_f;
		double	_d;

		bool    _impossible;

		std::string _str;
		e_type      _type;

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter();

    	ScalarConverter& operator=(const ScalarConverter& src);

		char    	getC(void) const;
		int			getI(void) const;
		float		getF(void) const;
		double		getD(void) const;
		std::string	getStr(void) const;
		e_type		getType(void) const;

		void    setC(char c);
		void    setI(int n);
		void    setF(float f);
		void    setD(double d);
		void	setStr(std::string str);
		void	setType(void);

		bool   	isAlpha(void) const;
		bool	isInt( void ) const;
		bool   	isChar(void) const;
		bool	isDouble(void) const;
		bool   	isFloat (void) const;
		bool	isImpossible(void);
				
		void    printChar(void) const;
		void    printInt(void) const;
		void    printFloat(void) const;
		void    printDouble(void) const;

		void	convert(void);

		/* ---------------- Exception Classes ---------------- */
		class ScalarConverterException : public std::exception {
			public:
				virtual const char* what() const throw() { return "ScalarConverter convert failure."; }
		};

};

std::ostream&    operator<<(std::ostream& out, const ScalarConverter& rhs);

#endif
