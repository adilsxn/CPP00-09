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
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a is " << a << "\n";
    std::cout << "b is " << b << "\n";
    std::cout << "c is " << c << "\n";
    std::cout << "d is " << d << "\n";
    std::cout << "\n" << "As Integer\n\n";
    std::cout << "a is " << a.toInt() << " as integer\n";
    std::cout << "b is " << b.toInt() << " as integer\n";
    std::cout << "c is " << c.toInt() << " as integer\n";
    std::cout << "d is " << d.toInt() << " as integer\n";

	return (0);
}
