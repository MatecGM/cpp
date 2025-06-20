/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:31:03 by mbico             #+#    #+#             */
/*   Updated: 2025/06/20 04:38:34 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"


class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(const ShrubberyCreationForm &ref);
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
};
void	shrubberyExecuteAction(Bureaucrat const & executor);
