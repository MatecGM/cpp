/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 21:45:24 by mbico             #+#    #+#             */
/*   Updated: 2025/07/21 14:10:06 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"
#include <stdint.h>
#include <iostream>

int	main(void) {
	Data		*data = new Data();
	uintptr_t	ptr;

	data->nb = 5;
	data->str = "nice";
	ptr = Serializer::serialize(data);
	data = Serializer::deserialize(ptr);
	std::cout << data->nb << "\n";
	std::cout << data->str << std::endl;
	delete data;
}
