#ifndef OPERANDS_HPP
#define OPERANDS_HPP

# include "Ioperand.hpp"
# include "Factory.hpp"
# include <iostream>
# include <sstream>
# include <string>

template <typename  T>
class Operand : public IOperand {
private:
    const eOperandType _type;
    T _number;
    Factory _factory;

public:
    Operand(const eOperandType type, const T &value) : _type(type), _number(value) {
//        std::cout << "eoperand " << (int)_type << " <> " << std::to_string(value) << " lala" << std::endl;
    };
    Operand() : _type(Double), _number(0) {};
    Operand(const Operand &src) : _type(src.getType()), _number(src.getValue()) {}
    Operand &operator=(const Operand &src) { return (*new Operand(src)); };
    ~Operand() {};

    int getPrecision() const { return static_cast<int>(_type); }
    eOperandType getType() const { return _type; }
    T getValue() const { return _number; };

    const std::string &toString() const {
        std::ostringstream tmp;
        tmp << ((_type != Int8) ? _number : static_cast<int>(_number));
        return *new std::string(tmp.str());
    }

    IOperand const *operator+(IOperand const &src) const {
        eOperandType _hight;
        _hight = (_type >= src.getType() ? _type : src.getType());
        std::string a = "123";
        if (_hight == 1 || _hight == 2 || _hight == 3)
            a = std::to_string(_number + std::stoi(src.toString()));
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
        else
            a = std::to_string(_number * std::stod(src.toString()));
        return (_factory.createOperand(_hight, a));
    };

    IOperand const *operator/(IOperand const &src) const {
        eOperandType _hight;
        if (static_cast<int>(_number) == 0)
            throw myException("Error. Division by zero!");
        _hight = (_type >= src.getType() ? _type : src.getType());
        std::string a = "123";
        if (_hight == Int8 || _hight == Int16 || _hight == Int32)
            a = std::to_string(std::stoi(src.toString()) / _number);
        else
            a = std::to_string(std::stod(src.toString()) / _number);
        return (_factory.createOperand(_hight, a));
    };

    IOperand const *operator%(IOperand const &src) const {
        eOperandType _hight;
        if (static_cast<int>(_number) == 0)
            throw myException("Error. Modulo by zero!");
        _hight = (_type >= src.getType() ? _type : src.getType());
        std::string a = "123";
        if (_hight == Int8 || _hight == Int16 || _hight == Int32)
            a = std::to_string(static_cast<int>(std::stoi(src.toString())) % static_cast<int>(_number));
        else
            throw (myException("Modulo by floating pointer"));
        return (_factory.createOperand(_hight, a));
    };
};

#endif
