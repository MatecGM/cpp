/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 05:33:14 by mateo             #+#    #+#             */
/*   Updated: 2025/06/20 06:16:18 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AForm.hpp"

class Intern {
public:
  Intern(const Intern &ref);
  Intern(void);
  ~Intern(void);

  Intern &operator=(Intern const &src);

  AForm	*makeForm(std::string name, std::string target);

  class	UnknownFormException: public std::exception {
		const char *what() const throw();
  };
};
