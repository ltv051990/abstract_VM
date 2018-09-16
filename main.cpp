// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/28 16:08:12 by tlutsyk           #+#    #+#             //
//   Updated: 2018/07/28 16:08:15 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <string>
#include <istream>
#include <iostream>
#include <regex>
#include "Controller.hpp"
#include "Exception.hpp"
#include <fstream>



void readData(std::istream& in, int from)
{
    bool exit_check = false;
    bool costyl = false;
    Controller *check = new Controller(from, &costyl);
    std::string input;

    while (std::getline(in, input) && !in.eof() && (exit_check = true)) {
        try {
                check->controller(input);
            }
        catch(myException &error) {
            std::cout << error.what() << std::endl;
            error.costyl();
        }
        catch(const std::runtime_error& re) {
            std::cerr << "Runtime error: " << re.what() << std::endl;
        }
        catch(const std::exception& ex) {
            std::cerr << "Error occurred: " << ex.what() << std::endl;
        }
        catch(...) {
            std::cerr << "Unknown failure occurred. Possible memory corruption" << std::endl;
        }
    }
    if (!exit_check) {
        std::cout << "Could read data from file or standart input" << std::endl;
        std::cout << "Usage [ ./abstractVM file]" << std::endl;
    }
    if (exit_check && !costyl) {
        std::cout << "Error. No exit in input" << std::endl;
    }
}

int main(int argc, char** argv)
{
    if ( argc > 1 )
    {
        std::ifstream infile(argv[1]);
        if ( infile && infile.good())
            readData(infile, 1);
        else {
            std::cout << "Could open file" << std::endl;
            std::cout << "Usage [ ./abstractVM file]" << std::endl;
            exit (0);
        }
    }
    else
        readData(std::cin, 0);
}
