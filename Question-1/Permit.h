#ifndef PERMIT_H
#define PERMIT_H

#include <iostream>

class Permit
{
private:
    std::string _permitNumber{""};
    unsigned int _permitDurationRemaining{0};
public:
    Permit()=default;          // Default constructor enabled 
    
    Permit(const Permit&)=delete;              // Copy constructor disabled
    
    Permit(Permit&&)=delete;                   // Move Constructor disabled
    
    Permit& operator=(const Permit&)=delete;      // Copy Assignment Operator diabled
    
    Permit& operator=(Permit&&)=delete;       // Move Assignment Operator disabled
    
    ~Permit()=default;                      // Default destructor enabled

    Permit(std::string permitNumber, unsigned int permitDurationRemaining);

    std::string permitNumber() const { return _permitNumber; }
    void setPermitNumber(const std::string &permitNumber) { _permitNumber = permitNumber; }

    unsigned int permitDurationRemaining() const { return _permitDurationRemaining; }
    void setPermitDurationRemaining(unsigned int permitDurationRemaining) { _permitDurationRemaining = permitDurationRemaining; }

    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};

#endif // PERMIT_H
