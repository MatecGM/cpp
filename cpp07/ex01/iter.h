/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 07:24:37 by mateo             #+#    #+#             */
/*   Updated: 2025/09/26 12:57:18 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template<typename T>
void	printAddOne(T c) {
	std::cout << c + 1 << " ";
}


template<typename T, typename F>
void	iter(T *arr, const int len, F f) {
	if (!arr || !f)
		return ;
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

