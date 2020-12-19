
#ifndef VARNAMEEXCEPTION_H
#define VARNAMEEXCEPTION_H

#include <exception>
#include <iostream>

class VarNameException: public std::runtime_error
{
private:
    std::string m_badName;
public:
    VarNameException(std::string);

    VarNameException(std::string, std::string);

    std::string getBadName() const;

};


#endif
