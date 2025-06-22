/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:46:08 by mateo             #+#    #+#             */
/*   Updated: 2025/06/21 08:42:47 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "log.h"

AForm::AForm(void): _name("Default"), _gradeSignIt(150), _gradeExecIt(150)
{
	LOG("AForm Constructor Default : \"Default\" gradeSignIt 150, gradeExecIt 150");
	_signed = false;
}

AForm::AForm(const std::string name, const int gradeSignIt, const int gradeExecIt): _name(name), _gradeSignIt(gradeSignIt), _gradeExecIt(gradeExecIt)
{	
	LOG("AForm Constructor : \"" << name << "\" gradeSignIt " << gradeSignIt << ", gradeExecIt " << gradeExecIt << " (Unsigned)");
	if (gradeSignIt < 1 || gradeExecIt < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSignIt > 150 || gradeExecIt > 150)
		throw AForm::GradeTooLowException();
	_signed = false;
}

AForm::~AForm(void)
{
	LOG("AForm Destructor : \"" << _name << "\" gradeSignIt " << _gradeSignIt << ", gradeExecIt " << _gradeExecIt << " (Unsigned)");
}

AForm::AForm(const AForm &cpy): _name(cpy._name), _gradeSignIt(cpy._gradeSignIt), _gradeExecIt(cpy._gradeExecIt)
{
	LOG("AForm Constructor Copy : \"" << _name << "\" gradeSignIt " << _gradeSignIt << ", gradeExecIt " << _gradeExecIt << " (Unsigned)");
	*this = cpy;	
}

AForm	&AForm::operator=(const AForm &cpy)
{
	LOG("AForm Operator = : \"" << _name << "\" => \"" << cpy._name << "\"");
	if (this != &cpy)
		_signed = cpy._signed;
	return (*this);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return("AForm::GradeTooHighException");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return("AForm::GradeTooLowException");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return("AForm::FormNotSignedException");
}

const std::string	&AForm::getName(void) const {
	return (_name);
}

const bool	&AForm::getSigned(void) const	{
	return (_signed);
}
const int	&AForm::getGradeSignIt(void) const {
	return (_gradeSignIt);
}
const int	&AForm::getGradeExecIt(void) const {
	return (_gradeExecIt);
}
std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
	out << obj.getName() << ", AForm Signed " << obj.getSigned() << " gradeSignIt " << obj.getGradeSignIt() << " gradeExecIt " << obj.getGradeExecIt();	
	return (out);
}

void	AForm::beSigned(Bureaucrat &bc)
{
	if (bc.getGrade() > _gradeSignIt)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeExecIt)
		throw GradeTooLowException();
	executeAction();
}
