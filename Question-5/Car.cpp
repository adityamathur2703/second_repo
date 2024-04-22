#include "Car.h"

Car::Car(std::string id, CarType cType, float price, float carLength, unsigned int carSeatCount)
:_id{id}, _cType{cType}, _price{price}, _carSeatCount{carSeatCount}
{
    if(carLength>5){
        throw AboveCarLengthException("Car Length is Not Applicable");
    }
    float temp=(float)(price*5)/100;
    setGstAmount(temp);
}


std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "Id: " << rhs._id<<std::endl
       << "Price: " << rhs._price<<std::endl
       << "Gst Amount: " << rhs._gstAmount<<std::endl
       << "Car Length: " << rhs._carLength<<std::endl
       << "Car Seat Count: " << rhs._carSeatCount<<std::endl;
    return os;
}
