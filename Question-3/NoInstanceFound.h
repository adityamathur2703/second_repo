#ifndef NOINSTANCEFOUND_H
#define NOINSTANCEFOUND_H

#include <future>
#include <cstring>

class NoInstanceFound : public std::future_error
{
private:
    char* _msg;
public:
    NoInstanceFound()=delete;                   // Default Constructor disabled
    NoInstanceFound(const NoInstanceFound&)=delete;              // Copy constructor disabled

    NoInstanceFound(NoInstanceFound&&)=default;                   // Move Constructor disabled

    NoInstanceFound& operator=(const NoInstanceFound&)=delete;         // Copy Assignment Operator diabled
    NoInstanceFound& operator=(NoInstanceFound&&)=delete;       // Move Assignment Operator disabled

    NoInstanceFound(const char* msg, std::future_errc ec)
    :std::future_error(ec){
        _msg=new char[strlen(msg)+1];            
        strcpy(_msg, msg);
    }

    ~NoInstanceFound(){                  // Destructor
        delete _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};


#endif // NOINSTANCEFOUND_H
