#ifndef ABOVECARLENGTHEXCEPTION_H
#define ABOVECARLENGTHEXCEPTION_H

#include <stdexcept> 
#include <cstring>

class AboveCarLengthException : public std::exception
{
private:
    char* _msg;
public:
    AboveCarLengthException()=delete;                   // Default Constructor disabled
    AboveCarLengthException(const AboveCarLengthException&)=delete;              // Copy constructor disabled

    AboveCarLengthException(AboveCarLengthException&&)=default;                   // Move Constructor disabled

    AboveCarLengthException& operator=(const AboveCarLengthException&)=delete;         // Copy Assignment Operator diabled
    AboveCarLengthException& operator=(AboveCarLengthException&&)=delete;       // Move Assignment Operator disabled

    AboveCarLengthException(const char* msg) {   
        _msg=new char[strlen(msg)+1];         
        strcpy(_msg, msg);
    }

    ~AboveCarLengthException(){                  // Destructor
        delete _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // ABOVECARLENGTHEXCEPTION_H
