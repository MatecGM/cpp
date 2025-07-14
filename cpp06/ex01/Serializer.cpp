/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 21:01:44 by mbico             #+#    #+#             */
/*   Updated: 2025/07/14 21:50:11 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"
#include "log.h"

Serializer::Serializer(void) {
}

Serializer::Serializer(const Serializer &src) {
  if (this != &src)
    *this = src;
}

Serializer::~Serializer(void) {
}

Serializer &Serializer::operator=(Serializer const &src) {
  if (this == &src)
    return (*this);
  return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr) {
	LOG("Serialize !")
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data			*Serializer::deserialize(uintptr_t raw) {
	LOG("Deserialize !")
	return (reinterpret_cast<Data *>(raw));

}
