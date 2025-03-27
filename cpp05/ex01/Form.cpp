/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:46:08 by mateo             #+#    #+#             */
/*   Updated: 2025/03/19 00:32:12 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("Default"), _gradeSignIt(150), _gradeExecIt(150)
{
	std::cout << "Form Constructor Default : \"Default\" gradeSignIt 150, gradeExecIt 150" << std::endl;
	_signed = false;
}

Form::Form(const std::string name, const int gradeSignIt, const int gradeExecIt): _name(name), _gradeSignIt(gradeSignIt), _gradeExecIt(gradeExecIt)
{	
	std::cout << "Form Constructor : \"" << name << "\" gradeSignIt " << gradeSignIt << ", gradeExecIt " << gradeExecIt << " (Unsigned)" << std::endl;
	if (gradeSignIt < 1 || gradeExecIt < 1)
		throw Form::GradeTooHighException();
	else if (gradeSignIt > 150 || gradeExecIt > 150)
		throw Form::GradeTooLowException();
	_signed = false;
}

Form::~Form(void)
{
	std::cout << "Form Destructor : \"" << _name << "\" gradeSignIt " << _gradeSignIt << ", gradeExecIt " << _gradeExecIt << " (Unsigned)" << std::endl;
}

Form::Form(const Form &cpy): _name(cpy._name), _gradeSignIt(cpy._gradeSignIt), _gradeExecIt(cpy._gradeExecIt)
{
	std::cout << "Form Constructor Copy : \"" << _name << "\" gradeSignIt " << _gradeSignIt << ", gradeExecIt " << _gradeExecIt << " (Unsigned)" << std::endl;
	*this = cpy;	
}

Form	&Form::operator=(const Form &cpy)
{
	std::cout << "Form Operator = : \"" << _name << "\" => \"" << cpy._name << "\"" << std::endl;
	if (this != &cpy)
		_signed = cpy._signed;
	return (*this);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return("Form::GradeTooHighException");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return("Form::GradeTooLowException");
}

const std::string	&Form::getName(void) const {
	return (_name);
}

const bool	&Form::getSigned(void) const	{
	return (_signed);
}
const int	&Form::getGradeSignIt(void) const {
	return (_gradeSignIt);
}
const int	&Form::getGradeExecIt(void) const {
	return (_gradeExecIt);
}
std::ostream& operator<<(std::ostream& out, const Form& obj)
{
	out << obj.getName() << ", Form Signed " << obj.getSigned() << " gradeSignIt " << obj.getGradeSignIt() << " gradeExecIt " << obj.getGradeExecIt();	
	return (out);
}

void	Form::beSigned(Bureaucrat bc)
{
	if (bc.getGrade() > _gradeSignIt)
		throw;
	else
		_signed = true;
}
