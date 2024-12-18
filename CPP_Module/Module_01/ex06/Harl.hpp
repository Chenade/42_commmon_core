# ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

using namespace std;

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	
	public:
		Harl( void );
		~Harl( void );
		void complain( string level );
};

typedef void (Harl::*t_func) ( void );

#endif