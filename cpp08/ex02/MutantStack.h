/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:22:24 by mateo             #+#    #+#             */
/*   Updated: 2025/09/26 11:23:07 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <stack>

template<typename T>
class	MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(MutantStack const &ms);
		~MutantStack();
		MutantStack	&operator=(MutantStack const &ms);
		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin();
		iterator	end();
};

template<typename T>
MutantStack<T>::MutantStack(): std::stack<T>() {}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const &ms) : std::stack<T>(ms) {}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack const &ms) {
	std::stack<T>::operator=(ms);
	return *this;
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return std::stack<T>::c.end();
}
