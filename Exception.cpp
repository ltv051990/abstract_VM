// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Exception.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/28 16:08:12 by tlutsyk           #+#    #+#             //
//   Updated: 2018/07/28 16:08:15 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Exception.hpp"

myException::myException(void) : _error(nullptr) {};
myException::myException(const char * error) : _error(error) {};
const char* myException::what() const throw() // my call to the std exception class function (doesn't nessasarily have to be virtual).
{
    return _error; // my error message
}
