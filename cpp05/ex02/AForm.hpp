/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:25:14 by mateo             #+#    #+#             */
/*   Updated: 2025/06/16 16:37:30 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"


class	AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSignIt;
		const int			_gradeExecIt;
	public:
		AForm(void);
		AForm(const std::string name, const int gradeSignIt, const int gradeExecIt);
		AForm(const AForm &cpy);
		virtual	~AForm(void);
		AForm	&operator=(const AForm &cpy);
		
		const std::string	&getName(void) const;
		const bool			&getSigned(void) const;
		const int			&getGradeSignIt(void) const;
		const int			&getGradeExecIt(void) const;

		void	beSigned(Bureaucrat &bc);

		class	GradeTooHighException: public std::exception {
			const char	*what() const throw();
		};
		class	GradeTooLowException: public std::exception {
			const char	*what() const throw();
		};
};
std::ostream& operator<<(std::ostream& out, const AForm& obj);
