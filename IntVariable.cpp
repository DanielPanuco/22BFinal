
#include "IntVariable.h"
#include "VarNameException.h"
 // #include <sstream> would need this if I wanted to override toString()


bool IntVariable::isGreater(IntVariable compare) {
    if(m_intValue > compare.getIntValue())
    {
        return true;
    }
    else
    {
        return false;
    }
}

IntVariable::IntVariable(std::string name, int value): BoolVariable(name)
{
    if ( isdigit(name[0])) {
        throw VarNameException(name, "Starts with digit"); // throwing two different exceptions depending on if the string is empty
    }
    else if( name[0] == ' ' || name.empty())
        //I'm not sure if it's better practice to test the string for emptiness here in the constructor or if this should have been done in the exception class
        //so please let me know in the comments for the final.
    {
        throw VarNameException("Empty string");
    }
    m_intValue = value;
}

int IntVariable::getIntValue() const {
    return m_intValue;
}

std::string IntVariable::getVariableString() {
    return std::to_string(m_intValue);
}
//This was my original way to use toString with IntVariable's integer value. I'm keeping it as a comment to show that I know I could have done it this way.
/*std::string IntVariable::toString() {
    std::stringstream ss;
    ss << getName() << '(' << m_intValue << ')';
    return ss.str();
}*/
