// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Factory.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/28 16:08:12 by tlutsyk           #+#    #+#             //
//   Updated: 2018/07/28 16:08:15 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

# include "Factory.hpp"
# include "Operands.hpp"
#include <cfloat>

Factory::Factory() {};
Factory::Factory(Factory const &src) { *this = src; };
Factory &Factory::operator=(Factory const &src) { static_cast<void>(src); return *this; };
Factory::~Factory() {};

const IOperand * Factory::createOperand( eOperandType type, std::string const & value ) const {
IOperand const * (Factory::*func[5])( std::string const & ) const = {
        &Factory::createInt8,
        &Factory::createInt16,
        &Factory::createInt32,
        &Factory::createFloat,
        &Factory::createDouble
};
    return  dynamic_cast<const IOperand *>((this->*func[static_cast<int>(type)])( value ));
};

const IOperand * Factory::createInt8( const std::string & value ) const {
    long double  nb;
    std::stringstream tmp(value);
    tmp >> nb;

    if (tmp.fail() || !tmp.eof())
        throw (myException(strdup("Too big nb to be calculated")));
    if (nb > CHAR_MAX)
        throw (myException(strdup("Int8 overflow")));
    if (nb < CHAR_MIN)
        throw (myException(strdup("Int8 underflow")));

    return (new Operand<char>(Int8, static_cast<char>(std::stoi(value)), value));
};

const IOperand * Factory::createInt16( const std::string & value ) const {
    long double  nb;
    std::stringstream tmp(value);
    tmp >> nb;

    if (tmp.fail() || !tmp.eof())
        throw (myException(strdup("Too big nb to be calculated")));
    if (nb > SHRT_MAX)
        throw (myException(strdup("Int16 overflow")));
    if (nb < SHRT_MIN)
        throw (myException(strdup("Int16 underflow")));

    return (new Operand<short>(Int16, static_cast<short>(std::stoi(value)), value));
};

const IOperand * Factory::createInt32( const std::string & value ) const {
    long double  nb;
    std::stringstream tmp(value);
    tmp >> nb;

    if (tmp.fail() || !tmp.eof())
        throw (myException(strdup("Too big nb to be calculated")));
    if (nb > INT32_MAX)
        throw (myException(strdup("Int32 overflow")));
    if (nb < INT32_MIN)
        throw (myException(strdup("Int32 underflow")));

    return (new Operand<int>(Int32, std::stoi(value), value));
};

const IOperand * Factory::createFloat( const std::string & value ) const {
    long double  nb;
    std::stringstream tmp(value);
    tmp >> nb;
    if (tmp.fail() || !tmp.eof())
        throw (myException(strdup("Too big nb to be calculated")));
    if (nb > FLT_MAX)
        throw (myException(strdup("Float overflow")));
    if (nb < -FLT_MAX)
        throw (myException(strdup("Float underflow")));

    return (new Operand<float>(Float, std::stof(value), value));
};

const IOperand * Factory::createDouble( const std::string & value ) const {
    double  nb;
    std::stringstream tmp(value);
    tmp >> nb;

    if (tmp.fail() || !tmp.eof())
        throw (myException(strdup("Double overflow")));
    return (new Operand<double>(Double, std::stod(value), value));
};