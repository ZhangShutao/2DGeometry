#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <exception>
#include <stdexcept>
#include <string>
using namespace std;

class ElementException : public exception
{
    public:
        ElementException(const string& s) throw();
        ~ElementException() throw();
        virtual const char* what() const throw();
    protected:
        string m_what;
};

class ElementNotExistException : public ElementException
{
    public:
        ElementNotExistException(const string& s) throw();
        ~ElementNotExistException() throw();
        virtual const char* what() const throw();
};

#endif // EXCEPTIONS_H_INCLUDED
