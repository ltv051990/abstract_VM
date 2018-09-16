// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Controller.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/28 16:08:12 by tlutsyk           #+#    #+#             //
//   Updated: 2018/07/28 16:08:15 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <iostream>
#include <regex>
#include "Commands.hpp"

class Controller {
    private:
        Commands *commands;
        std::smatch _base_match;

        std::regex _stop_exit;
        std::regex _ful_exit;
        std::regex _push_int8;
        std::regex _push_int16;
        std::regex _push_int32;
        std::regex _push_float;
        std::regex _push_double;
        std::regex _assert_int8;
        std::regex _assert_int16;
        std::regex _assert_int32;
        std::regex _assert_float;
        std::regex _assert_double;
        std::regex _pop;
        std::regex _dump;
        std::regex _add;
        std::regex _sub;
        std::regex _mul;
        std::regex _div;
        std::regex _mod;
        std::regex _print;
        std::regex _comments;

        std::regex _full_dump;
        std::regex _last;
        std::regex _min;
        std::regex _max;
        std::regex _power;

        bool _flag_exit;
        unsigned int _count;
        int _from;
        bool *_correct_exit;
        //**************************************//
        //check input functions

        bool getFlagExit() const;

        bool check_stop_exit(std::string & input);
        bool check_ful_exit(std::string & input);
        bool check_push(std::string & input);
        bool check_pop(std::string & input);
        bool check_dump(std::string & input);
        bool check_assert(std::string & input);
        bool check_add(std::string & input);
        bool check_sub(std::string & input);
        bool check_mul(std::string & input);
        bool check_div(std::string & input);
        bool check_mod(std::string & input);
        bool check_print(std::string & input);
        bool check_comments(std::string & input);

        bool check_full_dump(std::string & input);
        bool check_last(std::string & input);
        bool check_min(std::string & input);
        bool check_max(std::string & input);
        bool check_power(std::string & input);

        //lexer
        void search_error(std::string & input);
        void print_error(std::string error);
        //*************************************//

    public:

        Controller();
        Controller(int from, bool *exit_check);
        Controller(Controller const & src);
        ~Controller();

        Controller &operator=(Controller const &src);

        void controller(std::string & input);
};

#endif
