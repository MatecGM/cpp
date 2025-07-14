/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 21:01:41 by mbico             #+#    #+#             */
/*   Updated: 2025/07/14 22:10:36 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <string>

typedef	struct s_data {
	int			nb;
	std::string str;
}	Data;

class Serializer {
    private:
    Serializer(const Serializer &ref);
    Serializer(void);
    ~Serializer(void);

    Serializer &operator=(Serializer const &src);
	public:
	static uintptr_t	serialize(Data* str);
	static Data			*deserialize(uintptr_t raw);
};


