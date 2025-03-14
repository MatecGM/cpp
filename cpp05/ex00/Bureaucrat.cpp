/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:45:35 by mbico             #+#    #+#             */
/*   Updated: 2025/03/11 19:30:05 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(void): _name("default")
{
	_grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref)
{
	*this = ref;
}

Bureaucrat::~Bureaucrat(void)
{}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this != &ref)
		_grade = ref._grade;
	return (*this);
}

const std::string	&Bureaucrat::getName() const
{
	return (_name);
}

const int	&Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade --;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade ++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high !");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low !");
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << ", Bureaucrat grade " << obj.getGrade() << std::endl;	
	return (out);
}
