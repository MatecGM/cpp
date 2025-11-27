/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:07:17 by mbico             #+#    #+#             */
/*   Updated: 2025/11/22 16:30:51 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <cstdlib>
# include <climits>
# include <cerrno>
# include <algorithm>
# include <ctime>

template <class T>
class PmergeMe
{
	public:
		PmergeMe(T &tab, int size);
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe	&operator=(const PmergeMe &copy);

		T	get_tab() const;
		int	get_size() const;
		T	get_main() const;
		T	get_pend() const;
		T	get_index() const;

		void	merge_swap(int index);
		long	get_last(int index, T cont);
		int		get_right(long value);
		void	insert(int index);
		void	init_pend();
		int		next_jacob_index();
		void	sort();

		class WrongInputError : public std::exception
		{
			virtual const char* what() const throw();
		};
		class InvalidNumberError : public std::exception
		{
			virtual const char* what() const throw();
		};
	
	private:
		T	&_tab;
		T	_main;
		T	_pend;
		T	_index;
		int	_size;
		int	_cur_jacob;
		int	_nb_inserted;
		PmergeMe();
};

template <class T>
std::ostream&	operator<<(std::ostream& os, const PmergeMe<T>& obj);
template <class T>
T				parse(char **str);
std::vector<std::vector<long> >	get_def_tab(std::vector<long> full_tab);
template<typename T>
bool	is_sorted(T cont);

template<typename T>
PmergeMe<T>::PmergeMe()
{}

template<typename T>
PmergeMe<T>::~PmergeMe()
{}

template<typename T>
PmergeMe<T>::PmergeMe(T &tab, int size): _tab(tab), _size(size), _cur_jacob(1), _nb_inserted(0)
{}

template<typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

template<typename T>
T PmergeMe<T>::get_tab() const
{
	return (_tab);
}

template<typename T>
T PmergeMe<T>::get_main() const
{
	return (_main);
}

template<typename T>
T PmergeMe<T>::get_pend() const
{
	return (_pend);
}

template<typename T>
T PmergeMe<T>::get_index() const
{
	return (_index);
}

template<typename T>
int	PmergeMe<T>::get_size() const
{
	return (_size);
}

template<typename T>
PmergeMe<T>	&PmergeMe<T>::operator=(const PmergeMe &copy)
{
	_tab = copy.get_tab();
	_size = copy.get_size();
	return (*this);
}

template<typename T>
void	PmergeMe<T>::merge_swap(int index)
{
	typename T::iterator	it1 = _tab.begin() + index;
	typename T::iterator	it2 = it1 + _size;

	if (index + (_size * 2) > static_cast<int>(_tab.size()) || *(it1 + _size - 1) < *(it2 + _size - 1))
		return ;
	for (int i = 0; i < _size; i++)
	{
		std::swap(*it1, *it2);
		it1++, it2++;
	}
}

template<typename T>
std::ostream&	print_main_index(std::ostream& os, T tab, T index, int size)
{
	int		i = 0;
	typename T::iterator	index_it = index.begin();

	os << 'b' << *index_it + 1;
	index_it++;
	os << '[';
	for (typename T::iterator it = tab.begin(); it != tab.end(); it++)
	{
		if (i != 0 && i % size == 0)
		{
			os << "] ";
			if (std::find(index.begin(), index_it, *index_it) == index_it
				&& std::find(index_it + 1, index.end(), *index_it) != index.end())
				os << 'b';
			else
				os << 'a';
			os << *index_it + 1 << '[';
			index_it++;
		}
		else if (i != 0)
			os << ' ';
		os << *it;
		i++;
	}
	os << ']';
	return (os);
}

template<typename T>
std::ostream&	print_merger_cont(std::ostream& os, T tab, int size)
{
	int	i = 0;

	os << '[';
	for (typename T::iterator it = tab.begin(); it != tab.end(); it++)
	{
		if (i != 0 && i % size == 0)
			os << "] [";
		else if (i != 0)
			os << ' ';
		os << *it;
		i++;
	}
	os << ']';
	return (os);
}

template<typename T>
std::ostream&	operator<<(std::ostream& os, const PmergeMe<T>& obj)
{
	T		tab = obj.get_tab();
	T		main = obj.get_main();
	int		size = obj.get_size();

	if (tab.size())
		print_merger_cont(os, tab, size);
	if (main.size())
	{
		os << "\npend: ";
		print_merger_cont(os, obj.get_pend(), size);
		os << "\nmain: ";
		print_main_index(os, main, obj.get_index(), size);
	}
	return (os);
}

template<typename T>
long	PmergeMe<T>::get_last(int index, T cont)
{
	return *(cont.begin() + index + _size - 1);
}

template<typename T>
int	PmergeMe<T>::get_right(long value)
{
	int	i = 0;

	for (typename T::iterator it = _index.begin(); it != _index.end(); it++)
	{
		if (*it == value)
			return (i);
		i++;
	}
	return (_main.size() / _size - 1);
}

template<typename T>
void	PmergeMe<T>::insert(int index)
{
	long	inserted = this->get_last(index, _pend);
	int		value = index / _size + _nb_inserted;
	int		left = 0, right = this->get_right(value);
	
	//std::cout << *this << "\n" << "current Jacobsthal: " << _cur_jacob;
	//std::cout << " inserting element b" << index / _size + _nb_inserted + 1 << " (" << inserted << ")";
	//std::cout << " search zone from 0 to a" << *(_index.begin() + right) + 1 << " (" << this->get_last(right * _size, _main) << ")\n";

	while (left < right)
	{
		int		middle_ind = (left + right) / 2;
		long	middle_val = this->get_last(middle_ind * _size, _main);
		if (middle_val > inserted)
			right = middle_ind - 1;
		else
			left = middle_ind + 1;
	}
	typename T::iterator insert_pos = _main.begin() + left * _size;
	if (*(insert_pos + _size - 1) < inserted)
		insert_pos += _size;
	_main.insert(insert_pos, _pend.begin() + index, _pend.begin() + index + _size);
	_pend.erase(_pend.begin() + index, _pend.begin() + index + _size);
	_index.insert(_index.begin() + left, value);
}

template<typename T>
void	PmergeMe<T>::init_pend()
{
	int	ind = 0;
	_main.insert(_main.begin(), _tab.begin(), _tab.begin() + _size);
	_tab.erase(_tab.begin(), _tab.begin() + _size);
	_index.push_back(ind);
	while (static_cast<int>(_tab.size()) >= _size)
	{
		_main.insert(_main.end(), _tab.begin(), _tab.begin() + _size);
		_tab.erase(_tab.begin(), _tab.begin() + _size);
		_index.push_back(ind++);
		if (static_cast<int>(_tab.size()) >= _size)
		{
			_pend.insert(_pend.end(), _tab.begin(), _tab.begin() + _size);
			_tab.erase(_tab.begin(), _tab.begin() + _size);
		}
	}
}

template<typename T>
int	PmergeMe<T>::next_jacob_index()
{
	int	res;
	int	n1 = 1;
	int n2 = 1;
	int	tmp;

	while (n2 <= _cur_jacob)
	{
		tmp = n2;
		n2 = n1 * 2 + n2;
		n1 = tmp;
	}
	_cur_jacob = n2;
	res = (_cur_jacob - _nb_inserted - 1) * _size;
	return (std::min<int>(res, _pend.size() - _size));
}

template<typename T>
void	PmergeMe<T>::sort()
{
	//std::cout << std::endl;
	if (this->_size > static_cast<int>(this->_tab.size()) / 2)
		return ;

	//std::cout << *this << std::endl;
	for (int i = 0; i < static_cast<int>(_tab.size()); i += _size * 2)
		this->merge_swap(i);
	//std::cout << *this << std::endl;
	PmergeMe<T>	merger(_tab, _size * 2);
	merger.sort();

	//std::cout << "\n" << *this << std::endl;
	this->init_pend();
	_nb_inserted++;

	while (_pend.size() > 0)
	{
		int	index = this->next_jacob_index();
		int	inserted = 0;
		while (index >= 0)
		{
			this->insert(index);
			index -= _size;
			inserted++;
		}
		_nb_inserted += inserted;
	}
	//std::cout << *this << std::endl << std::endl;
	_tab.insert(_tab.begin(), _main.begin(), _main.end());
}

template<typename T>
bool	is_sorted(T cont)
{
	for (typename T::iterator it = cont.begin(); it != cont.end() - 1; it++)
	{
		if (*it > *(it + 1))
			return (false);
	}
	return (true);
}

template<typename T>
const char *PmergeMe<T>::WrongInputError::what() const throw()
{
	return ("Error: wrong inputs");
}

template<typename T>
const char *PmergeMe<T>::InvalidNumberError::what() const throw()
{
	return ("Error: invalid number");
}

template<typename T>
T	parse(char **str)
{
	T			res;
	long		current;
	int			i;

	while (*str)
	{
		i = 0;
		while ((*str)[i])
		{
			if (!std::isdigit((*str)[i]))
				throw(typename PmergeMe<T>::WrongInputError());
			i++;
		}
		current = std::strtol(*str, NULL, 10);
		if (current < 0 || (current == LONG_MAX && errno == ERANGE))
			throw(typename PmergeMe<T>::InvalidNumberError());
		res.push_back(current);
		str++;
	}
	return (res);
}

#endif
