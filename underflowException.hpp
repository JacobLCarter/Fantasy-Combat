/*******************************************************************************
 * Class Name: UnderflowException
 * Description: Handles exceptions that can be thrown from the Lineup and Losers
 * classes.
 * Implementation learned and sourced from accepted answer at:
 * https://stackoverflow.com/questions/13849431/catching-exceptions-thrown-by-class-functions
 * and from C++ documentation at:
 * http://www.cplusplus.com/reference/exception/exception/
 ******************************************************************************/

#ifndef UNDERFLOW_EXCEPTION
#define UNDERFLOW_EXCEPTION

#include <stdexcept>
class UnderflowException : public std::runtime_error
{
public:
    UnderflowException(const std::string& error) : std::runtime_error(error) {}
};
#endif
