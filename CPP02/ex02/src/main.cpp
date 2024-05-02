/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:34:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/08/06 20:29:18 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Fixed.hpp"

int	main(void)
{
    Fixed a;

    Fixed const b( Fixed(5.05f ) * Fixed( 2 ));
    std::cout << a << "\n";
    std::cout << ++a << "\n";
    std::cout << a << "\n";
    std::cout << a++ << "\n";
    std::cout << a << "\n";
    
    std::cout << b << "\n";
    std::cout << Fixed::max(a, b) << "\n";
	return (0);
}
