#ifndef NOTFOUNDEXCEPTION_H_
#define NOTFOUNDEXCEPTION_H_

#include <iostream>
#include <string>
#include <stdexcept>

class NotFoundException: public std::out_of_range{
    public:

        explicit NotFoundException(const std::string& message = "") : 
                                            std::out_of_range(message.c_str()){

        }

        virtual ~NotFoundException() noexcept = default;
};

#endif