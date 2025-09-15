/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 07:00:52 by mateo             #+#    #+#             */
/*   Updated: 2025/07/21 14:09:35 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"
#include <stdlib.h>

int	main()
{
	Base	*base;

	base = generate();
	identify(base);
	identify(&(*base));
	delete	base;
	return (0);
}
