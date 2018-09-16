// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Controller.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/28 16:08:12 by tlutsyk           #+#    #+#             //
//   Updated: 2018/07/28 16:08:15 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Controller.hpp"
#include <string>

Controller::Controller() {
    commands = new Commands();
    *_correct_exit = false;
    _from = 0;
    _flag_exit = false;
    _count = 0;
    _stop_exit = "\\s*exit\\s*(;.*)?";
    _ful_exit = "\\s*;;\\s*";
    _push_int8 = "push\\sint8\\(([-]?\\d{1,3})\\)\\s*(;.*)?";
    _push_int16 = "push\\sint16\\(([-]?\\d{1,5})\\)\\s*(;.*)?";
    _push_int32 = "push\\sint32\\(([-]?\\d{1,10})\\)\\s*(;.*)?";
    _push_float = "push\\sfloat\\(([-]?\\d+(\\.\\d+)?)\\)\\s*(;.*)?";
    _push_double = "push\\sdouble\\(([-]?\\d+(\\.\\d+)?)\\)\\s*(;.*)?";
    _assert_int8 = "assert\\sint8\\(([-]?\\d{1,3})\\)\\s*(;.*)?";
    _assert_int16 = "assert\\sint16\\(([-]?\\d{1,5})\\)\\s*(;.*)?";
    _assert_int32 = "assert\\sint32\\(([-]?\\d{1,10})\\)\\s*(;.*)?";
    _assert_float = "assert\\sfloat\\(([-]?\\d+(\\.\\d+)?)\\)\\s*(;.*)?";
    _assert_double = "assert\\sdouble\\(([-]?\\d+(\\.\\d+)?)\\)\\s*(;.*)?";
    _pop = "\\s*pop\\s*(;.*)?";
    _dump = "\\s*dump\\s*(;.*)?";
    _full_dump = "\\s*full_dump\\s*(;.*)?";
    _add = "\\s*add\\s*(;.*)?";
    _sub = "\\s*sub\\s*(;.*)?";
    _mul = "\\s*mul\\s*(;.*)?";
    _div = "\\s*div\\s*(;.*)?";
    _mod = "\\s*mod\\s*(;.*)?";
    _print = "\\s*print\\s*(;.*)?";
    _comments = "\\s*;.*";
    _last = "\\s*last\\s*(;.*)?";
    _min = "\\s*min\\s*(;.*)?";
    _max = "\\s*max\\s*(;.*)?";
    _power = "\\s*power\\s*(;.*)?";
};

Controller::Controller(int from, bool *exit_check) {
    commands = new Commands();
    _correct_exit = exit_check;
    _from = from;
    _count = 0;
    _stop_exit = "\\s*exit\\s*(;.*)?";
    _ful_exit = "\\s*;;\\s*";
    _push_int8 = "push\\sint8\\(([-]?\\d{1,3})\\)\\s*(;.*)?";
    _push_int16 = "push\\sint16\\(([-]?\\d{1,5})\\)\\s*(;.*)?";
    _push_int32 = "push\\sint32\\(([-]?\\d{1,10})\\)\\s*(;.*)?";
    _push_float = "push\\sfloat\\(([-]?\\d+(\\.\\d+)?)\\)\\s*(;.*)?";
    _push_double = "push\\sdouble\\(([-]?\\d+(\\.\\d+)?)\\)\\s*(;.*)?";
    _assert_int8 = "assert\\sint8\\(([-]?\\d{1,3})\\)\\s*(;.*)?";
    _assert_int16 = "assert\\sint16\\(([-]?\\d{1,5})\\)\\s*(;.*)?";
    _assert_int32 = "assert\\sint32\\(([-]?\\d{1,10})\\)\\s*(;.*)?";
    _assert_float = "assert\\sfloat\\(([-]?\\d+(\\.\\d+)?)\\)\\s*(;.*)?";
    _assert_double = "assert\\sdouble\\(([-]?\\d+(\\.\\d+)?)\\)\\s*(;.*)?";
    _pop = "\\s*pop\\s*(;.*)?";
    _dump = "\\s*dump\\s*(;.*)?";
    _full_dump = "\\s*full_dump\\s*(;.*)?";
    _add = "\\s*add\\s*(;.*)?";
    _sub = "\\s*sub\\s*(;.*)?";
    _mul = "\\s*mul\\s*(;.*)?";
    _div = "\\s*div\\s*(;.*)?";
    _mod = "\\s*mod\\s*(;.*)?";
    _print = "\\s*print\\s*(;.*)?";
    _comments = "\\s*;.*";
    _last = "\\s*last\\s*(;.*)?";
    _min = "\\s*min\\s*(;.*)?";
    _max = "\\s*max\\s*(;.*)?";
    _power = "\\s*power\\s*(;.*)?";
}

bool Controller::getFlagExit() const { return _flag_exit; }

Controller::~Controller() {};
Controller::Controller(Controller const & src) { *this = src; };
Controller &Controller::operator=(Controller const &src) { _flag_exit = src.getFlagExit(); return *this; };

//**************************************//
//check input functions

bool Controller::check_stop_exit(std::string & input) {
    if (std::regex_match(input, _base_match, _stop_exit)) {
        if (_from == 1) {
            *_correct_exit = true;
            commands->free_vector();
            delete commands;
            exit(0);
        }
        else
            std::cout << "Error. When you are reading from std::cin, the correct <exit> command is ;;" << std::endl;
        return  true;
    }
    return  false;
};

bool Controller::check_ful_exit(std::string &input) {
    if (std::regex_match(input, _base_match, _ful_exit)) {
        if (_from == 0) {
            *_correct_exit = true;
            commands->free_vector();
            delete commands;
            exit(0);
        }
        else
            std::cout << "Error. When you are reading from file, the correct <exit> command is ;;" << std::endl;
        return  true;
    }
    return  false;
}

bool Controller::check_push(std::string & input) {
    if (std::regex_match(input, _base_match, _push_int8)) {
        if (!_flag_exit)
            commands->push("int8", _base_match[1], 0);
        return true; }
        else if (std::regex_match(input, _base_match, _push_int16)) {
            if (!_flag_exit)
                commands->push("int16", _base_match[1], 1);
            return true; }
        else if (std::regex_match(input, _base_match, _push_int32)) {
            if (!_flag_exit)
                commands->push("int32", _base_match[1], 2);
            return true; }
        else if (std::regex_match(input, _base_match, _push_float)) {
        if (!_flag_exit)
            commands->push("float", _base_match[1], 3);
            return true; }
        else if (std::regex_match(input, _base_match, _push_double)) {
            if (!_flag_exit)
                commands->push("double", _base_match[1], 4);
            return true; }
    return false;
};

bool Controller::check_pop(std::string & input) {
    if (std::regex_match(input, _base_match, _pop)) {
        if (!_flag_exit)
            commands->pop();
        else
            std::cout << "print ignore" << std::endl;
        return true;
    }
    return false;
};

bool Controller::check_dump(std::string & input) {
    if (std::regex_match(input, _base_match, _dump)) {
        if (!_flag_exit)
            commands->dump();
        return true;
    }
    return false;
};

bool Controller::check_full_dump(std::string & input) {
    if (std::regex_match(input, _base_match, _full_dump)) {
            commands->full_dump();
        return true;
    }
    return false;
};

bool Controller::check_assert(std::string & input) {
    if (std::regex_match(input, _base_match, _assert_int8)) {
        if (!_flag_exit)
            commands->assert(Int8, _base_match[1]);
        return true; }
    if (std::regex_match(input, _base_match, _assert_int16)) {
        if (!_flag_exit)
            commands->assert(Int16, _base_match[1]);
        return true; }
    if (std::regex_match(input, _base_match, _assert_int32)) {
        if (!_flag_exit)
            commands->assert(Int32, _base_match[1]);
        return true; }
    if (std::regex_match(input, _base_match, _assert_float)) {
        if (!_flag_exit)
            commands->assert(Float, _base_match[1]);
        return true; }
    if (std::regex_match(input, _base_match, _assert_double)) {
        if (!_flag_exit)
            commands->assert(Double, _base_match[1]);
        return true; }
    return false;
};

bool Controller::check_add(std::string & input) {
    if (std::regex_match(input, _base_match, _add)) {
        if (!_flag_exit)
            commands->add();
        return true;
    }
    return false;
};

bool Controller::check_sub(std::string & input) {
    if (std::regex_match(input, _base_match, _sub)) {
        if (!_flag_exit)
            commands->sub();
        return true;
    }
    return false;
};

bool Controller::check_mul(std::string & input) {
    if (std::regex_match(input, _base_match, _mul)) {
        if (!_flag_exit)
            commands->mul();
        return true;
    }
    return false;
};

bool Controller::check_div(std::string & input) {
    if (std::regex_match(input, _base_match, _div)) {
        if (!_flag_exit)
            commands->div();
        return true;
    }
    return false;};

bool Controller::check_mod(std::string & input) {
    if (std::regex_match(input, _base_match, _mod)) {
        if (!_flag_exit)
            commands->mod();
        return true;
    }
    return false;
};

bool Controller::check_print(std::string & input) {
    if (std::regex_match(input, _base_match, _print)) {
        if (!_flag_exit)
            commands->print();
        return true;
    }
    return false;
}

bool Controller::check_comments(std::string & input) {
    if (std::regex_match(input, _base_match, _comments)) {
        return true;
    }
    return false;
};

bool Controller::check_last(std::string & input) {
    if (std::regex_match(input, _base_match, _last)) {
        commands->last();
        return true;
    }
    return false;
};

bool Controller::check_min(std::string & input) {
    if (std::regex_match(input, _base_match, _min)) {
        commands->min();
        return true;
    }
    return false;
};

bool Controller::check_max(std::string & input) {
    if (std::regex_match(input, _base_match, _max)) {
        commands->max();
        return true;
    }
    return false;
};

bool Controller::check_power(std::string & input) {
    if (std::regex_match(input, _base_match, _power)) {
        commands->power();
        return true;
    }
    return false;
};

void Controller::controller(std::string &input) {
    ++_count;
    if (check_ful_exit(input))
        ;
    else if (check_stop_exit(input))
;
    else if (check_push(input))
;
    else if (check_pop(input))
;
    else if (check_dump(input))
;
    else if (check_assert(input))
;
    else if (check_add(input))
;
    else if (check_sub(input))
;
    else if (check_mul(input))
;
    else if (check_div(input))
;
    else if (check_mod(input))
;
    else if (check_print(input))
;
    else if (check_comments(input))
;
    else if (check_full_dump(input))
;
    else if (check_last(input))
;
    else if (check_min(input))
;
    else if (check_max(input))
;
    else if (check_power(input))
;
    else if (input.empty())
        ;
    else
        search_error(input);
};

//**************************************//
//psevdo lexer
void Controller::print_error(std::string error) {
    std::stringstream ss;
    ss << "Error!!! Not valid " << error << " command on line " << std::to_string(_count);
    std::string str = ss.str();
    char *a = (char *)malloc(str.length() + 1);
    a = strcpy(a, str.c_str());
    throw myException(static_cast<const char *>(a));
}

void Controller::search_error(std::string & input) {
    if (std::regex_search(input, _base_match, std::regex("pop")))
        print_error(std::string("pop"));
    else if (std::regex_search(input, _base_match, std::regex("exit")))
        print_error(std::string("exit"));
    else if (std::regex_search(input, _base_match, std::regex("push(\\s+)?int8")))
        print_error(std::string("push int8"));
    else if (std::regex_search(input, _base_match, std::regex("push(\\s+)?int16")))
        print_error(std::string("push int16"));
    else if (std::regex_search(input, _base_match, std::regex("push(\\s+)?int32")))
        print_error(std::string("push int32"));
    else if (std::regex_search(input, _base_match, std::regex("push(\\s+)?float")))
        print_error(std::string("push float"));
    else if (std::regex_search(input, _base_match, std::regex("push(\\s+)?double")))
        print_error(std::string("push double"));
    else if (std::regex_search(input, _base_match, std::regex("push")))
        print_error(std::string("push"));
    else if (std::regex_search(input, _base_match, std::regex("dump")))
        print_error(std::string("dump"));
    else if (std::regex_search(input, _base_match, std::regex("assert")))
        print_error(std::string("assert"));
    else if (std::regex_search(input, _base_match, std::regex("add")))
        print_error(std::string("add"));
    else if (std::regex_search(input, _base_match, std::regex("sub")))
        print_error(std::string("sub"));
    else if (std::regex_search(input, _base_match, std::regex("mul")))
        print_error(std::string("mul"));
    else if (std::regex_search(input, _base_match, std::regex("div")))
        print_error(std::string("div"));
    else if (std::regex_search(input, _base_match, std::regex("mod")))
        print_error(std::string("mod"));
    else if (std::regex_search(input, _base_match, std::regex("print")))
        print_error(std::string("print"));
    else if(std::regex_search(input, _base_match, std::regex("last")))
        print_error(std::string("last"));
    else if(std::regex_search(input, _base_match, std::regex("min")))
        print_error(std::string("min"));
    else if(std::regex_search(input, _base_match, std::regex("max")))
        print_error(std::string("max"));
    else if(std::regex_search(input, _base_match, std::regex("power")))
        print_error(std::string("power"));
    else if(std::regex_search(input, _base_match, std::regex("full_dump")))
        print_error(std::string("full_dump"));
    else
        print_error(std::string(""));
};
