/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:45:17 by mbico             #+#    #+#             */
/*   Updated: 2025/03/27 17:02:30 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Form;

class	Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &ref);
		~Bureaucrat(void);
		Bureaucrat	&operator=(const Bureaucrat &ref);

		const std::string	&getName() const;
		const int			&getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		void	signForm(Form &f);

	class GradeTooHighException: public std::exception
	{
		const char *what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		const char *what() const throw();
	};
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#include "Form.hpp"
