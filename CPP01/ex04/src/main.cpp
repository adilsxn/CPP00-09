/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:43:09 by acuva-nu          #+#    #+#             */
/*   Updated: 2024/04/27 16:43:09 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include <string>

static bool replace(std::string file, std::string tofind, std::string torepla)
{
    std::fstream ofile;
    std::fstream nfile; 
    std::string line;
    std::string tmp;
    size_t pos;

    ofile.open(file.c_str(), std::ios::in);
    nfile.open(std::string(file + ".replace").c_str(), std::ios::out);
    if (!ofile)
        std::cout << "The file " <<file << " couldn;t be opened";
    else if (!nfile)
        std::cout << "Output file creation failed\n";
    else
    {
        while(getline(ofile, line))
        {
            int last_pos = 0;
            while((pos = line.find(tofind, last_pos)) != std::string::npos)
            {
                tmp = line.substr(pos + tofind.length());
                line.erase(pos);
                line += torepla + tmp;
                last_pos = pos + torepla.length();
            }
            nfile << line;
            if (!ofile.eof())
                nfile << "\n";
        }
    }
    ofile.close();
    nfile.close();
    return true;
}

int	main(int ac, char **av)
{
   if (ac == 4) 
    {
        if (!av[2][0] || !av[3][0])
            std::cout << "String given are empty\n";
        else
            replace(av[1], av[2], av[3]);
    }
   else
       std::cout << "Wrong input\n";
   return 0;
}
