/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:58:54 by mbico             #+#    #+#             */
/*   Updated: 2025/11/21 15:58:56 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	RPN::rpn_operator(std::stack<int> &stack, char op)
{
	int	nb1;
	int	nb2;

	if (stack.size() < 2)
	throw (ErrorInvalidSyntax());
	nb2 = stack.top();
	stack.pop();
	nb1 = stack.top();
	stack.pop();
	switch (op)
	{
	case '+':
		stack.push(nb1 + nb2);
		break;
	case '-':
		stack.push(nb1 - nb2);
		break;
	case '*':
		stack.push(nb1 * nb2);
		break;
	case '/':
		if (nb2 == 0)
			throw (ErrorDivisonByZero());
		stack.push(nb1 / nb2);
		break;
	default:
		throw (ErrorInvalidSyntax());
		break;
	}
}

void	RPN::calculate(std::string str)
{
	std::stack<int>	stack;

	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (*it != ' ')
		{
			if (std::isdigit(*it))
				stack.push(static_cast<int>(*it - '0'));
			else if (*it == '-' && it + 1 != str.end() && std::isdigit(*(it + 1)))
				stack.push(static_cast<int>((*(++it) - '0') * -1));
			else
				RPN::rpn_operator(stack, *it);
		}
	}
	if (stack.size() != 1)
		throw(ErrorInvalidSyntax());
	std::cout << stack.top() << std::endl;
}

// Constructors
RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
	(void) copy;
}


// Destructor
RPN::~RPN()
{
}


// Operators
RPN & RPN::operator=(const RPN &assign)
{
	(void) assign;
	return *this;
}

// Exceptions
const char	*RPN::ErrorDivisonByZero::what() const throw()
{
	return ("Error: Division by Zero");
}

const char	*RPN::ErrorInvalidSyntax::what() const throw()
{
	return ("Error: Invalid syntax");
}