/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:17:12 by mateo             #+#    #+#             */
/*   Updated: 2025/09/26 11:17:13 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <algorithm>

class	NotFoundException : public std::exception {
	public:
		virtual const char	*what() const throw() {
			return ("not found");
		}
};

template<typename T>
typename T::iterator	easyfind(T &c, int i) {
	typename T::iterator	it = std::find(c.begin(), c.end(), i);
	if (it == c.end())
		throw NotFoundException();
	return (it);
}
