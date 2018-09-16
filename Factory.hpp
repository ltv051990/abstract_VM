// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Factory.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/28 16:08:12 by tlutsyk           #+#    #+#             //
//   Updated: 2018/07/28 16:08:15 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FACTORY_HPP
#define FACTORY_HPP

# include "Ioperand.hpp"
# include <string>
# include "Exception.hpp"

class Factory {
    public:
        Factory();
        Factory(Factory const &src);
        Factory &operator=(Factory const &src);
        ~Factory();
        IOperand const * createOperand( eOperandType type, std::string const & value ) const;
    private:
        IOperand const * createInt8( std::string const & value ) const;
        IOperand const * createInt16( std::string const & value ) const;
        IOperand const * createInt32( std::string const & value ) const;
        IOperand const * createFloat( std::string const & value ) const;
        IOperand const * createDouble( std::string const & value ) const;
};

#endif
