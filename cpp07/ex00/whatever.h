/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:56:10 by mateo             #+#    #+#             */
/*   Updated: 2025/09/21 22:08:57 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

template <typename T>
void	swap(T &param1, T &param2) {
	T	tmp = param1;

	param1 = param2;
	param2 = tmp;
}

template <typename T>
T	min(T param1, T param2) {
	if (param1 < param2)
		return (param1);
	return (param2);
}

template <typename T>
T	max(T param1, T param2) {
	if (param1 > param2)
		return (param1);
	return (param2);
}
