// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Exception.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/28 16:08:12 by tlutsyk           #+#    #+#             //
//   Updated: 2018/07/28 16:08:15 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ABSTRACTVM_EXCEPTION_HPP
#define ABSTRACTVM_EXCEPTION_HPP

# include <string>
# include <exception>

class myException : public std::exception {
    public:
        myException(void);
        void costyl(void) { delete _error; };
        myException(const char *error);
        virtual const char* what() const throw(); // my call to the std exception class function (doesn't nessasarily have to be virtual).
    private:
        const char *_error;
};

#endif
