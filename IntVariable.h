
#ifndef INTVARIABLE_H
#define INTVARIABLE_H
#include "BoolVariable.h"

class IntVariable: public BoolVariable
{
private:
    int m_intValue;
public:

    virtual std::string getVariableString() override; // overriding method from BoolVariable to return int value as a string

    bool isGreater(IntVariable);

    IntVariable(std::string, int);

    int getIntValue() const;

    /*This was my original way to use toString with IntVariable's integer value. I'm keeping it as a comment to show that I know I could have done it this way.

    virtual std::string toString() override;
    */
};


#endif
