// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Commands.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/28 16:08:12 by tlutsyk           #+#    #+#             //
//   Updated: 2018/07/28 16:08:15 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <climits>
#include <cfloat>
#include <cmath>
#include <vector>
#include "Ioperand.hpp"
#include "Factory.hpp"
#include <memory>
class  Commands {
    public:
        Commands (void);
        Commands (Commands const & src);
        ~Commands();
        Commands & operator=(Commands const & rhs);
        void push(std::string type, std::string const & value, int nb);
        void pop(void);
        void dump(void);
        void full_dump(void);
        void assert(eOperandType type, std::string const & value);
        void add(void);
        void sub(void);
        void mul(void);
        void div(void);
        void mod(void);
        void print(void);
        void free_vector(void);
        void last(void);
        void max(void);
        void min(void);
        void power(void);
    private:
        std::vector<IOperand const * > myStack;
        Factory factory;
        bool check_nb_size(std::string & type, std::string const & value);
};

#endif
