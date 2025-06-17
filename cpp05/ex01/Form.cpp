/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:46:08 by mateo             #+#    #+#             */
/*   Updated: 2025/06/16 16:29:57 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "log.h"

Form::Form(void): _name("Default"), _gradeSignIt(150), _gradeExecIt(150)
{
	LOG("Form Constructor Default : \"Default\" gradeSignIt 150, gradeExecIt 150");
	_signed = false;
}

Form::Form(const std::string name, const int gradeSignIt, const int gradeExecIt): _name(name), _gradeSignIt(gradeSignIt), _gradeExecIt(gradeExecIt)
{	
	LOG("Form Constructor : \"" << name << "\" gradeSignIt " << gradeSignIt << ", gradeExecIt " << gradeExecIt << " (Unsigned)");
	if (gradeSignIt < 1 || gradeExecIt < 1)
		throw Form::GradeTooHighException();
	else if (gradeSignIt > 150 || gradeExecIt > 150)
		throw Form::GradeTooLowException();
	_signed = false;
}

Form::~Form(void)
{
	LOG("Form Destructor : \"" << _name << "\" gradeSignIt " << _gradeSignIt << ", gradeExecIt " << _gradeExecIt << " (Unsigned)");
}

Form::Form(const Form &cpy): _name(cpy._name), _gradeSignIt(cpy._gradeSignIt), _gradeExecIt(cpy._gradeExecIt)
{
	LOG("Form Constructor Copy : \"" << _name << "\" gradeSignIt " << _gradeSignIt << ", gradeExecIt " << _gradeExecIt << " (Unsigned)");
	*this = cpy;	
}

Form	&Form::operator=(const Form &cpy)
{
	LOG("Form Operator = : \"" << _name << "\" => \"" << cpy._name << "\"");
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

void	Form::beSigned(Bureaucrat &bc)
{
	if (bc.getGrade() > _gradeSignIt)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}
