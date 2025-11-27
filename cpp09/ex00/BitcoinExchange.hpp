/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:27:25 by mbico             #+#    #+#             */
/*   Updated: 2025/11/27 15:24:14 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <cerrno>
# include <cmath>
# include <climits>
# include <cstdlib>

class BitcoinExchange
{
	public:
		void	open_input(const char *path);
		void	open_reference(const char *path);
		
		// Constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		
		// Destructor
		~BitcoinExchange();
		
		// Operators
		BitcoinExchange & operator=(const BitcoinExchange &assign);
		
		// Getter
		const std::map<long, std::map<long, std::map<long, double> > >	get_reference() const;
		
		// Exception
		class ErrorFileException : public std::exception {
			virtual const char* what() const throw();
		};
		class ErrorNotFound : public std::exception {
			virtual const char* what() const throw();
		};
		
	private:
		std::map<long, std::map<long, std::map<long, double> > >	_reference;

		void	add_to_reference(std::string line);
		bool	is_valid_value(std::string str);
		bool	is_valid_nb_date(std::string full_date, std::string str, int index);
		bool	is_valid_day(std::string full_date, std::string day, std::string month);
		bool	is_bisextile_valid(std::string full_date, std::string year, std::string month, std::string day);
		void	print_input_line(std::string line);
		double	closest_value(long year, long month, long day);
};

#endif
