/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:06:35 by mbico             #+#    #+#             */
/*   Updated: 2025/01/13 17:46:51 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "sed.hpp"

bool	check_parameter(int argc)
{
	bool	check = (argc != 4);

	if (check)
		std::cout << "Error parameter: ./sed {filename} (str1) (str2)" << std::endl;
	return (check);
}

bool	get_infile_str(char *infile_path, std::string *infile_str)
{
	std::ifstream	infile;
	std::stringstream	buffer;

	infile.open(infile_path, std::ifstream::in);
	if (!infile.is_open())
	{
		std::cout << "Error file: " << infile_path << ": No such file" << std::endl;
		return (true);
	}
	buffer << infile.rdbuf();
	*infile_str = buffer.str();
	return (false);
}

bool	get_outfile(char *infile_name, std::ofstream *outfile)
{
	std::string	outfile_name = infile_name;

	outfile_name += ".replace";
	outfile->open(outfile_name.c_str());
	if (!outfile->is_open())
	{
		std::cout << "Error file: " << outfile_name << ": impossible creation" << std::endl;
		return (true);
	}
	return (false);
}

void	sed(std::string infile, std::ofstream &outfile, char *s1, char *s2)
{
	std::size_t	i;
	std::string	str;
	std::string	s1_str = s1;

	i = infile.find(s1);
	while (i != std::string::npos)
	{
		str += infile.substr(0, i);
		str += s2;
		infile = &infile[i + s1_str.length()];
		i = infile.find(s1, s1_str.length());
	}
	str += infile;
	outfile << str;
}

int	main(int argc, char **argv)
{
	std::string		infile;
	std::ofstream	outfile;

	if (check_parameter(argc))
		return (1);
	if (get_infile_str(argv[FILENAME], &infile))
		return (1);
	if (get_outfile(argv[FILENAME], &outfile))
		return (1);
	sed(infile, outfile, argv[S1], argv[S2]);
	return (0);
}
