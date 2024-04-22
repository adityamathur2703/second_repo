#ifndef CAR_H
#define CAR_H

#include "CarType.h"
#include "AboveCarLengthException.h"
#include <iostream>

class Car
{
private:
    std::string _id{""};
    CarType _cType{CarType::SEDAN};
    float _price{0.0f};
    float _gstAmount{0.0f};
    float _carLength{0.0f};
    unsigned int _carSeatCount{0};

public:
    Car()=default;          // Default constructor enabled 
    
    Car(const Car&)=delete;              // Copy constructor disabled
    
    Car(Car&&)=delete;                   // Move Constructor disabled
    
    Car& operator=(const Car&)=delete;      // Copy Assignment Operator diabled
    
    Car& operator=(Car&&)=delete;       // Move Assignment Operator disabled
    
    ~Car()=default;                      // Default destructor enabled

    Car(std::string id, CarType cType, float price, float carLength, unsigned int carSeatCount);

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    CarType cType() const { return _cType; }
    void setCType(const CarType &cType) { _cType = cType; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    float gstAmount() const { return _gstAmount; }
    void setGstAmount(float gstAmount) { _gstAmount = gstAmount; }

    float carLength() const { return _carLength; }
    void setCarLength(float carLength) { _carLength = carLength; }

    unsigned int carSeatCount() const { return _carSeatCount; }
    void setCarSeatCount(unsigned int carSeatCount) { _carSeatCount = carSeatCount; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
