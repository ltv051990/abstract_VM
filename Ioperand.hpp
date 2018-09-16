// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ioperand.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/28 16:08:12 by tlutsyk           #+#    #+#             //
//   Updated: 2018/07/28 16:08:15 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include <string>

enum eOperandType {Int8, Int16, Int32, Float, Double};

class IOperand {
    public:
        virtual int getPrecision( void ) const = 0;
        virtual eOperandType getType( void ) const = 0;
        virtual IOperand const * operator+( IOperand const & rhs ) const = 0;
        virtual IOperand const * operator-( IOperand const & rhs ) const = 0;
        virtual IOperand const * operator*( IOperand const & rhs ) const = 0;
        virtual IOperand const * operator/( IOperand const & rhs ) const = 0;
        virtual IOperand const * operator%( IOperand const & rhs ) const = 0;
        virtual std::string const & toString( void ) const = 0;

        virtual IOperand const * operator^( IOperand const & rhs ) const = 0;
        virtual IOperand const * operator>( IOperand const & rhs ) const = 0;
        virtual IOperand const * operator<( IOperand const & rhs ) const = 0;

        virtual ~IOperand( void ) {};
};

#endif
