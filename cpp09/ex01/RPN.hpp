/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:59:18 by mbico             #+#    #+#             */
/*   Updated: 2025/11/21 15:59:35 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{
	public:
		static void	calculate(std::string str);

		// Destructor
		~RPN();
		
		// Operators
		RPN & operator=(const RPN &assign);
		
		// Exceptions
		class ErrorDivisonByZero : public std::exception {
			virtual const char* what() const throw();
		};
		class ErrorInvalidSyntax : public std::exception {
			virtual const char* what() const throw();
		};
		
	private:
		// Constructors
		RPN();
		RPN(const RPN &copy);
		static void	rpn_operator(std::stack<int> &stack, char op);
};

#endif