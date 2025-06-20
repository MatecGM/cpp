/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:45:35 by mbico             #+#    #+#             */
/*   Updated: 2025/06/20 04:53:19 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <log.h>

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	LOG("Bureaucrat Constructor : \"" << name << "\" grade " << grade);
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(void): _name("default")
{
	LOG("Bureaucrat Constructor : \"default\" grade 150");
	_grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref): _name(ref._name)
{
	LOG("Bureaucrat Constructor Copy : \"" << ref._name << "\" grade " << ref._grade);
	_grade = 150;
	*this = ref;
}

Bureaucrat::~Bureaucrat(void)
{
	LOG("Bureaucrat Destructor : \"" << _name << "\" grade " << _grade);
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &ref)
{
	LOG("Bureaucrat Operator '=' : \"" << _name << "\" grade " << _grade << "\" => \"" << ref._name << "\" grade " << ref._grade);
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
	LOG("Bureaucrat IncrementGrade : \"" << _name << "\" grade " << _grade << " => " << _grade - 1);
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade --;
}

void	Bureaucrat::decrementGrade()
{
	LOG("Bureaucrat DecrementGrade : \"" << _name << "\" grade " << _grade << " => " << _grade + 1);
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

void	Bureaucrat::signForm(AForm &f)
{
	if (_grade > f.getGradeSignIt())
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because him grade is too low !" << std::endl;
	else
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	f.beSigned(*this);
}

void	Bureaucrat::executeForm(AForm const &f) {
	f.execute(*this);
	std::cout << _name << " executed " << f.getName() << std::endl;
}
