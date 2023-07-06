#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
	std::cerr << "Error: required database file not found.\n";
	throw BtcParseException();
}

BitcoinExchange::BitcoinExchange(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	std::getline(file, line); // Skip header line
	if (!file.good())
	{
		std::cerr << "Error: Error: could not open file. " << filename << std::endl;
		throw BtcParseException();
	}
	while (std::getline(file, line)) {
		std::string::size_type delimiter_pos = line.find(',');
		if (delimiter_pos == std::string::npos)
		{
			std::cerr << "Error: Invalid format in database" << line << std::endl;
			throw BtcParseException();
		}

		std::string date = line.substr(0, delimiter_pos);
		std::string rate_str = line.substr(delimiter_pos + 1);

		if (!ValidateDate(date))
		{
			std::cerr << "Error: Invalid date format in line => " << line << std::endl;
			throw BtcParseException();
		}

		double rate;
		std::istringstream rate_stream(rate_str);
		if (!(rate_stream >> rate))
		{
			std::cerr << "Error: Invalid rate format in database => " << rate_str << std::endl;
			throw BtcParseException();
		}
		data_[date] = rate;
	}
}

double BitcoinExchange::GetExchangeRate(const std::string &date)
{
	std::map<std::string, double>::iterator it = --(data_.upper_bound(date));
	if (it != data_.end())
	{
		return it->second;
	} else if (!data_.empty())
	{
		return (--it)->second;
	}
	return (-1.0);
}

bool BitcoinExchange::ValidateDate(const std::string& date)
{
	struct tm tm;
	char date_str[11];

	memset(&tm, 0, sizeof(tm));
	strptime(date.c_str(), "%Y-%0m-%0d", &tm);
	strftime(date_str, sizeof(date_str), "%Y-%0m-%0d", &tm);
	if (strcmp(date.c_str(), date_str) != 0)
		return (false);
	return (true);
}

bool BitcoinExchange::ValidateValue(const double &value)
{
	if (value < 0 || value > 1000) {
		std::cerr << "Error: Value "
			  << value
			  << " is not a positive number between 0 and 1000.\n";
		return (false);
	}
	return (true);
}

void BitcoinExchange::ProcessInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	std::getline(file, line); // Skip header line
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date;
		double value;
		char delimiter;

		if (!(ss >> date >> delimiter >> value))
		{
			std::cerr << "Error: Unable to parse line => " << line << std::endl;
			continue;
		}

		if (delimiter != '|')
		{
			std::cerr << "Error: Expected '|' delimiter in line => " << line << std::endl;
			continue;
		}

		if (!ValidateDate(date)) 
		{
			std::cerr << "Error: Invalid date format in line => " << line << std::endl;
			continue;
		}

		if (!ValidateValue(value))
		{
			continue;
		}

		double exchangeRate = GetExchangeRate(date);
		if (exchangeRate == -1.0)
		{
			std::cerr << "Error: No exchange rate available for date => "
				  << date << std::endl;
			continue;
		}

		std::cout << date << " => "
			  << value << " = " << value * exchangeRate
			  << std::endl;
	}
}
