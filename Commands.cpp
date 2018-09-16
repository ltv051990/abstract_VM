// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Commands.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/28 16:08:12 by tlutsyk           #+#    #+#             //
//   Updated: 2018/07/28 16:08:15 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iterator>
#include "Ioperand.hpp"
#include "Operands.tpp"
#include "Commands.hpp"
#include <limits>

Commands::Commands () {};
Commands::Commands (Commands const & src) { *this = src;};
Commands::~Commands() {};
Commands & Commands::operator=(Commands const & src) { (void)src; return *this; };

void Commands::free_vector() {
    if (!myStack.empty()) {
        std::vector<IOperand const *>::reverse_iterator p;
        for (p = myStack.rbegin(); p < myStack.rend(); p++) {
            delete (*p);
        }
    }
}

void Commands::pop(void) {
    const IOperand *arg = NULL;

    if (myStack.empty()) {
        throw myException(strdup("Error in command <POP>. Stack is empty"));
    }
    else {
        arg = *(myStack.rbegin());
        delete arg;
        myStack.pop_back();
    }
};

void Commands::last() {
    const IOperand *arg = NULL;

    if (myStack.empty())
        throw (myException(strdup("Error in command <LAST>. Empty stack")));
    arg = *(myStack.rbegin());
    std::cout << "Presicion : " << arg->getPrecision() << " Value = " << arg->toString() << std::endl;
}

void Commands::full_dump(void) {
    if (myStack.empty())
        throw (myException(strdup("Error in command <DUMP>. Empty stack")));
    std::vector<IOperand const *>::reverse_iterator p;
    for (p = myStack.rbegin(); p < myStack.rend(); p++) {
        switch ((*p)->getPrecision()) {
            case 0:
                std::cout << "char = " << std::stoi((*p)->toString()) << std::endl;
                break;
            case 1:
                std::cout << "short = "<< std::stoi((*p)->toString()) << std::endl;
                break;
            case 2:
                std::cout << "int = "<< std::stoi((*p)->toString()) << std::endl;
                break;
            case 3:
                std::cout << "float = "<< std::fixed << std::setprecision(2) << std::stof((*p)->toString()) << std::endl;
                break;
            case 4:
                std::cout << "double = "<< std::fixed << std::setprecision(2) << std::stod((*p)->toString()) << std::endl;
                break;
        }
    }
};

void Commands::dump(void) {
    if (myStack.empty())
        throw (myException(strdup("Error in command <DUMP>. Empty stack")));
    std::vector<IOperand const *>::reverse_iterator p;
    for (p = myStack.rbegin(); p < myStack.rend(); p++) {
        switch ((*p)->getPrecision()) {
            case 0:
                std::cout << std::stoi((*p)->toString()) << std::endl;
                break;
            case 1:
                std::cout << std::stoi((*p)->toString()) << std::endl;
                break;
            case 2:
                std::cout << std::stoi((*p)->toString()) << std::endl;
                break;
            case 3:
                std::cout << std::fixed << std::setprecision(2) << std::stof((*p)->toString()) << std::endl;
                break;
            case 4:
                std::cout << std::fixed << std::setprecision(2) << std::stod((*p)->toString()) << std::endl;
                break;
        }
    }
};

void Commands::assert(eOperandType type, std::string const & value) {
    const IOperand *arg = NULL;
    if (myStack.empty())
        throw (myException(strdup("Error in command <DUMP>. Empty stack")));
    arg = *(myStack.rbegin());
    if (type == arg->getType() && value == arg->toString()) {
        std::cout << "Values are equals 100%" << std::endl;
    }
    else
        throw myException(strdup("Error in assert instruction. Value aren't equals"));
};

void Commands::add(void) {
    const IOperand *arg1 = NULL;
    const IOperand *arg2 = NULL;

    if (myStack.empty())
        throw (myException(strdup("Error in command <ADD>. Empty stack")));
    else if ((int)myStack.size() < 2)
        throw (myException(strdup("Error in command <ADD>. Only one element is now in stack")));
        arg1 = *(myStack.end() - 1);
        arg2 = *(myStack.end() - 2);

        const IOperand *res = (*arg1 + *arg2);
        delete arg1;
        delete arg2;
        myStack.pop_back();
        myStack.pop_back();
        myStack.push_back(res);
};

void Commands::sub(void) {
    const IOperand *arg1 = NULL;
    const IOperand *arg2 = NULL;

    if (myStack.empty())
        throw (myException(strdup("Error in command <SUB>. Empty stack")));
    else if ((int)myStack.size() < 2)
        throw (myException(strdup("Error in command <SUB>. Only one element is now in stack")));
    arg1 = *(myStack.rbegin());
    myStack.pop_back();
    arg2 = *(myStack.rbegin());
    myStack.pop_back();

    const IOperand *res = (*arg1 - *arg2);
    myStack.push_back(res);
    delete arg1;
    delete arg2;
};

void Commands::mul(void) {
    const IOperand *arg1 = NULL;
    const IOperand *arg2 = NULL;

    if (myStack.empty())
        throw (myException(strdup("Error in command <MUL>. Empty stack")));
    else if ((int)myStack.size() < 2)
        throw (myException(strdup("Error in command <MUL>. Only one element is now in stack")));
    arg1 = *(myStack.rbegin());
    myStack.pop_back();
    arg2 = *(myStack.rbegin());
    myStack.pop_back();

    const IOperand *res = (*arg1 * *arg2);
    myStack.push_back(res);
    delete arg1;
    delete arg2;
};

void Commands::div(void) {
    const IOperand *arg1 = NULL;
    const IOperand *arg2 = NULL;

    if (myStack.empty())
        throw (myException(strdup("Error in command <DIV>. Empty stack")));
    else if ((int)myStack.size() < 2)
        throw (myException(strdup("Error in command <DIV>. Only one element is now in stack")));
    arg1 = *(myStack.rbegin());
    myStack.pop_back();
    arg2 = *(myStack.rbegin());
    myStack.pop_back();

    const IOperand *res = (*arg1 / *arg2);
    myStack.push_back(res);
    delete arg1;
    delete arg2;
};

void Commands::mod(void) {
    const IOperand *arg1 = NULL;
    const IOperand *arg2 = NULL;

    if (myStack.empty())
        throw (myException(strdup("Error in command <MOD>. Empty stack")));
    else if ((int)myStack.size() < 2)
        throw (myException(strdup("Error in command <MOD>. Only one element is now in stack")));
    arg1 = *(myStack.rbegin());
    myStack.pop_back();
    arg2 = *(myStack.rbegin());
    myStack.pop_back();
    const IOperand *res = (*arg1 % *arg2);
    myStack.push_back(res);
    delete arg1;
    delete arg2;
};

void Commands::min(void) {
    const IOperand *arg1 = NULL;
    const IOperand *arg2 = NULL;

    if (myStack.empty())
        throw (myException(strdup("Error in command <MIN>. Empty stack")));
    else if ((int)myStack.size() < 2)
        throw (myException(strdup("Error in command <MIN>. Only one element is now in stack")));
    arg1 = *(myStack.end() - 1);
    arg2 = *(myStack.end() - 2);

    const IOperand *res = (*arg2 > *arg1);
    delete arg1;
    delete arg2;
    myStack.pop_back();
    myStack.pop_back();
    myStack.push_back(res);
}

void Commands::max(void) {
    const IOperand *arg1 = NULL;
    const IOperand *arg2 = NULL;

    if (myStack.empty())
        throw (myException(strdup("Error in command <MAX>. Empty stack")));
    else if ((int)myStack.size() < 2)
        throw (myException(strdup("Error in command <MAX>. Only one element is now in stack")));
    arg1 = *(myStack.end() - 1);
    arg2 = *(myStack.end() - 2);

    const IOperand *res = (*arg2 < *arg1);
    delete arg1;
    delete arg2;
    myStack.pop_back();
    myStack.pop_back();
    myStack.push_back(res);
}

void Commands::power(void) {
    const IOperand *arg1 = NULL;
    const IOperand *arg2 = NULL;

    if (myStack.empty())
        throw (myException(strdup("Error in command <Power>. Empty stack")));
    else if ((int)myStack.size() < 2)
        throw (myException(strdup("Error in command <Power>. Only one element is now in stack")));
    arg1 = *(myStack.end() - 1);
    arg2 = *(myStack.end() - 2);

    const IOperand *res = (*arg2 ^ *arg1);
    delete arg1;
    delete arg2;
    myStack.pop_back();
    myStack.pop_back();
    myStack.push_back(res);
}

void Commands::print(void) {
    const IOperand *arg = NULL;

    if (myStack.empty())
        std::cout << "Stack is empty" << std::endl;
    arg = *(myStack.rbegin());
    if (arg->getPrecision() != 0)
        throw (myException(strdup("Error in the print instruction. The value isn.t char ( . ) ( . )")));
    else {
        char a = static_cast<char>(std::stoi(arg->toString()));
        if (isprint(a) && a > 32)
            std::cout << static_cast<char>(a) << std::endl;
        else if (a > 0)
            throw myException(strdup("Char is not visible"));
        else
            throw myException(strdup("Char is not printable"));
    }
};

void Commands::push(std::string type, std::string const & value, int nb) {
    if (check_nb_size(type, value))
        myStack.push_back(factory.createOperand(static_cast<eOperandType>(nb), value));
}

bool Commands::check_nb_size(std::string & type, std::string const & value) {
    double  nb;
    std::stringstream tmp(value);
    tmp >> nb;
    if (tmp.fail() || !tmp.eof()) {
        throw myException(strdup("To big nb for double"));
    }
    if (type == "int8") {
        if (nb > CHAR_MAX || nb < CHAR_MIN)
            throw myException(strdup("Not correct size of number for int8"));
    }
    else if (type == "int16") {
        if (nb > SHRT_MAX || nb < SHRT_MIN)
            throw myException(strdup("Not correct size of number for int16"));
    }
    else if (type == "int32")
    {
        if (nb > INT32_MAX || nb < INT32_MIN)
            throw myException(strdup("Not correct size of number for int32"));
    }
    else if (type == "float")
    {
        if ((nb > FLT_MAX || nb < -FLT_MAX) && !std::isinf(nb))
            throw myException(strdup("Not correct size of number for float"));
    }
    return true;
}
