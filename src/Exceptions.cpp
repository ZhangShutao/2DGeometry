#include "Exceptions.h"
#include <exception>
#include <iostream>
#include <string>
using namespace std;

ElementException::ElementException(const string& s) throw()
    : exception()
{
    m_what = "Element error occurred.\n" + s;
}

ElementException::~ElementException() throw()
{

}

const char* ElementException::what() const throw()
{
    return m_what.c_str();
}

ElementNotExistException::ElementNotExistException(const string& s) throw()
    : ElementException("Element not exist.\n")
{
    m_what += s;
}

ElementNotExistException::~ElementNotExistException() throw ()
{

}

const char* ElementNotExistException::what() const throw()
{
    return m_what.c_str();
}
