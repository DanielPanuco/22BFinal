#include "BoolVariable.h"
#include <sstream>
#include <algorithm>

std::string BoolVariable::toString() {
    std::stringstream ss;
    ss << m_name << '(' << getVariableString() << ')';
    // made a virtual getVariableString() method rather than overriding a virtual toString() in IntVariable since format is the same
    // for both. They just have different variable types
    return ss.str();
}

bool BoolVariable::containsIgnoreCase(std::string search)
{
    std::string description = m_name; // need description string so that my m_name's values aren't altered when I change to lowercase

    // Case in-sensitive
    transform(description.begin(), description.end(), description.begin(), ::tolower);
    transform(search.begin(), search.end(), search.begin(), ::tolower);

    if (description.find(search) != std::string::npos)
        return true;
    else
        return false;
}

BoolVariable::BoolVariable(std::string name, bool value): m_name(name), m_value(value) {

}

std::string BoolVariable::getName() const {
    return m_name;
}

BoolVariable::BoolVariable(std::string name): m_name(name) { //needed another constructor to only initialize name for when an IntVariable object is created
}

std::string BoolVariable::getVariableString()
{
    std::stringstream ss;
    ss << std::boolalpha << m_value;
    return ss.str();
}
