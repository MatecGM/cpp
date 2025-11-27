/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:06:32 by mbico             #+#    #+#             */
/*   Updated: 2025/11/22 16:32:08 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

double	get_time_micro()
{
	return (static_cast<double>(std::clock()) * 1000000.0 / static_cast<double>(CLOCKS_PER_SEC));
}

int	main(int argc, char **argv)
{
	std::vector<long>	vec_tab;
	std::deque<long>	deq_tab;
	double				vec_start, vec_time, deq_start, deq_time;
	
	if (argc < 2)
	{
		std::cerr << "Error: no argument given\n";
		return (1);
	}

	try
	{
		vec_tab = parse<std::vector<long> >(argv + 1);
		deq_tab = parse<std::deque<long> >(argv + 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	
	PmergeMe<std::vector<long> >	vec_merger(vec_tab, 1);
	PmergeMe<std::deque<long> >		deq_merger(deq_tab, 1);

	std::cout << "Before: ";
	for (std::vector<long>::iterator it = vec_tab.begin(); it != vec_tab.end() ; it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	vec_start = get_time_micro();
	vec_merger.sort();
	vec_time = get_time_micro() - vec_start;
	
	deq_start = get_time_micro();
	deq_merger.sort();
	deq_time = get_time_micro() - deq_start;

	std::cout << "After: ";
	for (std::vector<long>::iterator it = vec_tab.begin(); it != vec_tab.end() ; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vec_time << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << deq_time << " us" << std::endl;
	//std::cout << "is sorted: vec: " << is_sorted<std::vector<long> >(vec_tab) << " deq: " << is_sorted<std::vector<long> >(vec_tab) << std::endl;
}
