/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:19:53 by mateo             #+#    #+#             */
/*   Updated: 2025/09/26 11:20:34 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <vector>
# include <algorithm>

class	Span {
	private:
		std::vector<int>	v;
		unsigned int		N;
	public:
		Span(void);
		Span(unsigned int N);
		Span(Span const &sp);
		~Span(void);
		Span	&operator=(Span const &sp);
		void			addNumber(int n);
		void			addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);
		unsigned int	getN(void) const;
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		class	NoSpaceException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
		class	NoSpanException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
};
