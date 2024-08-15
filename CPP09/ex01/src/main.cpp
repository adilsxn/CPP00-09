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

#include <stack>
#include <string>
#include <cctype>
#include <iostream> 
#include <algorithm>
#include <stdexcept>

void parser(const char *input){
    long a, b;
    std::stack<long> st;
    std::string::iterator it;
    std::string s(input);

    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), 
            s.end());
    if (s.find_first_not_of("0123456789+-*/") != std::string::npos)
        throw std::runtime_error("Error: invalid operand\n");
    for(it = s.begin(); it < s.end(); it++)
    {
        std::string ss = "+-*/";
        if (std::isdigit(*it))
            st.push((*it - '0'));
        else if (ss.find(*it) != std::string::npos)
        {
            if (st.size() < 2)
                throw std::runtime_error("Error: insufficient operands\n");
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            if (*it == '+')
                st.push(a + b);
            else if (*it == '-')
                st.push(a - b);
            else if (*it == '*')
                st.push(a * b);
            else if (*it == '/')
            {
                if ( b == 0)
                    throw std::runtime_error("Error: division by zero\n");
                st.push(a / b);
            }
        }
        else
        {
            std::cout <<*it<<std::endl;
            throw std::runtime_error("Error: invalid operand\n");
        }
    }
    if (st.size() != 1)
        throw std::runtime_error("Error: invalid expression\n");
    std::cout <<st.top()<<"\n";
}

int	main(int ac, char **av)
{
    if (ac != 2)
        return std::cout <<"Usage: RPN <postfix expr>\n", 0;
    try{
        parser(av[1]);
    }
    catch(std::exception& e)
    {
        std::cerr <<e.what();
    }
    return 0;
}
