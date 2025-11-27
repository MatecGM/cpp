/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:28:30 by mbico             #+#    #+#             */
/*   Updated: 2025/11/27 16:16:25 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	BitcoinExchange::is_valid_value(std::string str)
{
	double	nb;
	char	*endptr;

	nb = std::strtod(str.c_str(), &endptr);
	if (*endptr) {
		std::cerr << "Error: invalid number." << std::endl;
		return (false);
	}
	if (*endptr || nb < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (nb > 1000 || (nb == HUGE_VALF && errno == ERANGE))
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::is_valid_nb_date(std::string full_date, std::string str, int index)
{
	long	nb;
	long	max;
	char	*endptr;

	max = 12;
	if (index == 2)
		max = 31;
	nb = std::strtol(str.c_str(), &endptr, 10);
	if (str.empty() || *endptr || (nb == LONG_MAX && errno == ERANGE) || (index != 0 && (nb > max || nb < 0)))
	{
		std::cerr << "Error: bad input => " << full_date << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::is_valid_day(std::string full_date, std::string day, std::string month) {
	char	*endptr;
	long	nb_month = std::strtol(month.c_str(), NULL, 10);
	long	nb_day;
	int		max = 30;

	if (nb_month == 1 || nb_month == 3 || nb_month == 5 || nb_month == 7 || nb_month == 8 || nb_month == 10 || nb_month == 12)
		max = 31;
	else if (nb_month == 2)
		max = 29;
	
	nb_day = std::strtol(day.c_str(), &endptr, 10);
	if (day.empty() || *endptr || (nb_day == LONG_MAX && errno == ERANGE) || nb_day > max || nb_day < 0) {
		std::cerr << "Error: bad input => " << full_date << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::is_bisextile_valid(std::string full_date, std::string year, std::string month, std::string day) {
	long	nb_year;
	bool	bisextile;


	nb_year = std::strtol(year.c_str(), NULL, 10);
	bisextile = !(nb_year % 4) && (!(nb_year % 400) || (nb_year % 100));
	if (!bisextile && std::strtol(month.c_str(), NULL, 10) == 2 && std::strtol(day.c_str(), NULL, 10) == 29) {
		std::cerr << "Error: bad input (bisextile) => " << full_date << std::endl;
		return(false);
	}
	
	return (true);
}

void	BitcoinExchange::add_to_reference(std::string line)
{
	std::stringstream	sstream(line);
	std::string			year;
	std::string			month;
	std::string			day;
	std::string			value;

	getline(sstream, year, '-');
	getline(sstream, month, '-');
	getline(sstream, day, ',');
	getline(sstream, value);
	if (value.empty())
		return ;
	if (is_valid_nb_date(line, year, 0) && is_valid_nb_date(line, month, 1) && is_valid_day(line, day, month) && is_bisextile_valid(line, year, month, day))
		_reference[std::strtol(year.c_str(), NULL, 10)][std::strtol(month.c_str(), NULL, 10)][std::strtol(day.c_str(), NULL, 10)] = std::strtod(value.c_str(), NULL);
}

void	BitcoinExchange::open_reference(const char *path)
{
	std::fstream		file(path, std::ios::in);
	std::string			line;

	if (!file.is_open())
		throw (ErrorFileException());
	while (std::getline(file, line))
	{
		add_to_reference(line);
		line.clear();
	}
	file.close();
}

double	BitcoinExchange::closest_value(long year, long month, long day)
{
	std::map<long, std::map<long, std::map<long, double> > >::iterator	it_year;
	std::map<long, std::map<long, double> >::iterator					it_month;
	std::map<long, double>::iterator										it_day;
	
	it_year = _reference.lower_bound(year);
	if (it_year == _reference.end() || it_year->first > year)
	{
		if (it_year == _reference.begin())
			throw (ErrorNotFound());
		it_year--;
		month = 12;
		day = 31;
	}
	it_month = it_year->second.lower_bound(month);
	if (it_month == it_year->second.end() || it_month->first > month)
	{
		if (it_month == it_year->second.begin())
			return (closest_value(it_year->first - 1, 12, 31));
		it_month--;
		day = 31;
	}
	it_day = it_month->second.lower_bound(day);
	if (it_day == it_month->second.end() || it_day->first > day)
	{
		if (it_day == it_month->second.begin())
			return (closest_value(it_year->first, it_month->first - 1, 31));
		it_day--;
	}
	return (it_day->second);
}

void	BitcoinExchange::print_input_line(std::string line)
{
	std::stringstream	sstream(line);
	std::string			year;
	std::string			month;
	std::string			day;
	std::string			sep;
	std::string			value;
	double				coeff;

	getline(sstream, year, '-');
	getline(sstream, month, '-');
	getline(sstream, day, ' ');
	getline(sstream, sep, ' ');
	getline(sstream, value);
	if (value.empty() || sep.compare("|"))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	if (is_valid_nb_date(line, year, 0) && is_valid_nb_date(line, month, 1) && is_valid_day(line, day, month) && is_valid_value(value) && is_bisextile_valid(line, year, month, day))
	{
		try {
			coeff = closest_value(std::strtol(year.c_str(), NULL, 10), std::strtol(month.c_str(), NULL, 10), std::strtol(day.c_str(), NULL, 10));
			std::cout << year << "-" << month << "-" << day << " => " << value << " = " << std::strtod(value.c_str(), NULL) * coeff << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
}

void	BitcoinExchange::open_input(const char *path)
{
	std::fstream		file(path, std::ios::in);
	std::string			line;

	if (!file.is_open())
		throw (ErrorFileException());
	std::getline(file, line);
	if (line.compare("date | value"))
		print_input_line(line);
	line.clear();
	while (std::getline(file, line))
	{
		print_input_line(line);
		line.clear();
	}
	file.close();
}


// Constructors
BitcoinExchange::BitcoinExchange()
{
	//std::cout << "\e[0;33mDefault Constructor called of BitcoinExchange\e[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void) copy;
	//std::cout << "\e[0;33mCopy Constructor called of BitcoinExchange\e[0m" << std::endl;
}


// Destructor
BitcoinExchange::~BitcoinExchange()
{
	//std::cout << "\e[0;31mDestructor called of BitcoinExchange\e[0m" << std::endl;
}


BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign)
// Operators
{
	(void) assign;
	return *this;
}

// Getter
const std::map<long, std::map<long, std::map<long, double> > >	BitcoinExchange::get_reference() const
{
	return (_reference);
}

// Exception
const char	*BitcoinExchange::ErrorFileException::what() const throw()
{
	return ("Error: could not open file.");
}

const char	*BitcoinExchange::ErrorNotFound::what() const throw()
{
	return ("Error: No value could be found");
}
