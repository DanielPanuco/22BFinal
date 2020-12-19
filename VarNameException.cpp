#include "VarNameException.h"
VarNameException::VarNameException(std::string msg) : runtime_error(msg), m_badName("(EMPTY STRING)") // if there is no string or " " then a one variable constructor is thrown
{

}
VarNameException::VarNameException(std::string name, std::string msg) : runtime_error(msg), m_badName(name)
{

}
std::string VarNameException::getBadName() const
{
    return m_badName;
}