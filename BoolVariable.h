
#ifndef BOOLVARIABLE_H
#define BOOLVARIABLE_H

#include <string>

class BoolVariable
{
private:
    std::string m_name;
    bool m_value;
public:
    BoolVariable(std::string, bool);

    BoolVariable(std::string);

    virtual std::string getVariableString();

    std::string toString();

    bool containsIgnoreCase(std::string);

    std::string getName() const;

};


#endif
