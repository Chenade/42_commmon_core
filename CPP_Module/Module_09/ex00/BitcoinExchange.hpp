#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange(const std::string &filename);
		void ProcessInput(const std::string &filename);

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &rhs);

		std::map<std::string, double> data_;
		double GetExchangeRate(const std::string &date);
		bool ValidateDate(const std::string &date);
		bool ValidateValue(const double &value);

		/* ---------------- Exception Classes ---------------- */                
		class BtcParseException : public std::exception {                 
			public:                                                              
				virtual const char* what() const throw(){ return "Parsing failure."; }
		};
};

#endif
