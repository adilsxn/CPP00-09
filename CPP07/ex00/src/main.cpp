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

#include "../inc/whatever.hpp"
#include <ios>
#include <iostream>

int	main(void)
{
    // {
    //     std::cout <<"-------Test for Int-------------\n";
    //     int a = 10, b = 5;
    //     std::cout <<"Before the swap: "<<"\na: "<<a<<"\nb: "<<b<<std::endl;
    //     swap(a, b);
    //     std::cout <<"After the swap: "<<"\na: "<<a<<"\nb: "<<b<<std::endl;
    //     std::cout <<"The bigger int: \n\t"<<::max(a, b);
    //     std::cout <<"\nThe smaller int: \n\t"<<::min(a, b);
    // }
    // {
    //     std::cout <<"\n---------Test for Float--------\n";
    //     float a = 10.3973f, b = 5.3309f;
    //     std::cout <<"Before the swap: "<<"\na: "<<a<<"\nb: "<<b<<std::endl;
    //     swap(a, b);
    //     std::cout <<"After the swap: "<<"\na: "<<std::fixed<<a
    //         <<"\nb: "<<std::fixed<<b<<std::endl;
    //     std::cout <<"The bigger float: \n\t"<<std::fixed<<::max(a, b);
    //     std::cout <<"\nThe smaller float: \n\t"<<std::fixed<<::min(a, b);
    // }
    // {
    //     std::cout <<"\n----------Test for String------------\n";
    //     std::string a = "adilson", b = "adilso";
    //     std::cout <<"Before the swap: "<<"\na: "<<a<<"\nb: "<<b<<std::endl;
    //     swap(a, b);
    //     std::cout <<"After the swap: "<<"\na: "<<a<<"\nb: "<<b<<std::endl;
    //     std::cout <<"The bigger string: \n\t"<<::max(a, b);
    //     std::cout <<"\nThe smaller string: \n\t"<<::min(a, b);
    //     std::cout<<std::endl;
    // }
    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    
	return (0);
}
