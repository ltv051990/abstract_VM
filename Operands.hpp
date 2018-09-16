// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Operands.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/28 16:08:12 by tlutsyk           #+#    #+#             //
//   Updated: 2018/07/28 16:08:15 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OPERANDS_HPP
#define OPERANDS_HPP

# include "Ioperand.hpp"
# include "Factory.hpp"
# include <iostream>
# include <sstream>
# include <string>
# include <cmath>

template <typename  T>
class Operand : public IOperand {
private:
    const eOperandType _type;
    T _number;
    Factory _factory;
    const std::string _strValue;

public:
    Operand(const eOperandType type, const T &value, const std::string & strValue) : _type(type), _number(value),
                                                       _strValue(strValue)  {
//        std::cout << "eoperand " << (int)_type << " <> " << std::to_string(value) << " lala" << std::endl;
    };
    Operand() : _type(Double), _number(0) {};
    Operand(const Operand &src) : _type(src.getType()), _number(src.getValue()), _strValue(src.toString()) { *this = src ;}
    Operand &operator=(const Operand &src) { return (*new Operand(src)); };
    ~Operand() {};

    int getPrecision() const { return static_cast<int>(_type); }
    eOperandType getType() const { return _type; }
    T getValue() const { return _number; };

    const std::string &toString() const { return _strValue; }

    IOperand const *operator+(IOperand const &src) const {
        eOperandType _hight;
        _hight = (_type >= src.getType() ? _type : src.getType());
        std::string a = "123";
        if (_hight == 1 || _hight == 2 || _hight == 3)
            a = std::to_string(_number + std::stoi(src.toString()));
        else if (_hight == Float)
            a = std::to_string(_number + std::stof(src.toString()));
        else
            a = std::to_string(_number + std::stod(src.toString()));
        return (_factory.createOperand(_hight, a));
    };

    IOperand const *operator-(IOperand const &src) const {
        eOperandType _hight;
        _hight = (_type >= src.getType() ? _type : src.getType());
        std::string a = "123";
        if (_hight == Int8 || _hight == Int16 || _hight == Int32)
            a = std::to_string(std::stoi(src.toString()) - _number);
        else if (_hight == Float)
            a = std::to_string(std::stof(src.toString()) - _number);
        else
            a = std::to_string(std::stod(src.toString()) - _number);
        return (_factory.createOperand(_hight, a));
    };

    IOperand const *operator*(IOperand const &src) const {
        eOperandType _hight;
        _hight = (_type >= src.getType() ? _type : src.getType());
        std::string a = "123";
        if (_hight == Int8 || _hight == Int16 || _hight == Int32)
            a = std::to_string(_number * std::stoi(src.toString()));
        else if (_hight == Float)
            a = std::to_string(_number * std::stof(src.toString()));
        else
            a = std::to_string(_number * std::stod(src.toString()));
        return (_factory.createOperand(_hight, a));
    };

    IOperand const *operator/(IOperand const &src) const {
        eOperandType _hight;
        if (static_cast<int>(_number) == 0)
            throw myException(strdup("Error. Division by zero!"));
        _hight = (_type >= src.getType() ? _type : src.getType());
        std::string a = "123";
        if (_hight == Int8 || _hight == Int16 || _hight == Int32)
            a = std::to_string(std::stoi(src.toString()) / _number);
        else if (_hight == Float)
            a = std::to_string(std::stof(src.toString()) - _number);
        else
            a = std::to_string(std::stod(src.toString()) / _number);
        return (_factory.createOperand(_hight, a));
    };

    IOperand const *operator%(IOperand const &src) const {
        eOperandType _hight;
        if (static_cast<int>(_number) == 0)
            throw myException(strdup("Error. Modulo by zero!"));
        _hight = (_type >= src.getType() ? _type : src.getType());
        std::string a = "123";
        if (_hight == Int8 || _hight == Int16 || _hight == Int32)
            a = std::to_string(static_cast<int>(std::stoi(src.toString())) % static_cast<int>(_number));
        else
            throw (myException(strdup("Modulo by floating pointer")));
        return (_factory.createOperand(_hight, a));
    };

    IOperand const *operator>(IOperand const &src) const {
        eOperandType _hight;
        _hight = (_type >= src.getType() ? _type : src.getType());
        return (_factory.createOperand(_hight, std::to_string((double)_number
                                                              >= std::stod(src.toString()) ? std::stod(src.toString()) : _number)));
    };

    IOperand const *operator<(IOperand const &src) const {
        eOperandType _hight;
        _hight = (_type >= src.getType() ? _type : src.getType());
        return (_factory.createOperand(_hight, std::to_string((double)_number
                                                              <= std::stod(src.toString()) ? std::stod(src.toString()) : _number)));
    };

    IOperand const *operator^(IOperand const &src) const {
        eOperandType _hight;

        _hight = (_type >= src.getType() ? _type : src.getType());
        std::string a = "123";
        try {
            a = std::to_string(pow(_number, std::stod(src.toString())));
        }
        catch (...) {
            throw myException(strdup("Sorry, problem in power operation. Try another service"));
        }
        return (_factory.createOperand(_hight, a));
    };
};

#endif
