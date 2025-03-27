/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:45:35 by mbico             #+#    #+#             */
/*   Updated: 2025/03/18 23:14:39 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat Constructor : \"" << name << "\" grade " << grade << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(void): _name("default")
{
	std::cout << "Bureaucrat Constructor : \"default\" grade 150" << std::endl;
	_grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref): _name(ref._name)
{
	std::cout << "Bureaucrat Constructor Copy : \"" << ref._name << "\" grade " << ref._grade << std::endl;
	_grade = 150;
	*this = ref;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Destructor : \"" << _name << "\" grade " << _grade << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &ref)
{
	std::cout << "Bureaucrat Operator '=' : \"" << _name << "\" grade " << _grade << "\" => \"" << ref._name << "\" grade " << ref._grade << std::endl;
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
	std::cout << "Bureaucrat IncrementGrade : \"" << _name << "\" grade " << _grade << " => " << _grade - 1 << std::endl;
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade --;
}

void	Bureaucrat::decrementGrade()
{
	std::cout << "Bureaucrat DecrementGrade : \"" << _name << "\" grade " << _grade << " => " << _grade + 1 << std::endl;
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade ++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << ", Bureaucrat grade " << obj.getGrade();	
	return (out);
}
