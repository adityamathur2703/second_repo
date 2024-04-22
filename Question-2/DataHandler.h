#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <array>
#include <iostream>
#include <memory>
#include "EmptyContainerException.h"

class DataHandler;
using Pointeru = std::unique_ptr<DataHandler>;

class DataHandler
{
private:
    std::array<int, 5> _data;
    std::array<int, 5> _squareResults;
    std::array<int, 5> _factorialResults;
    static Pointer _solo_hero_obj;
    DataHandler(std::array<int, 5> data):_data{data}{};
    bool flag{false};

public:
    DataHandler()=default;
    DataHandler(const DataHandler&)=delete;              // Copy constructor disabled
    
    DataHandler(DataHandler&&)=delete;                   // Move Constructor disabled
    
    DataHandler& operator=(const DataHandler&)=delete;      // Copy Assignment Operator diabled
    
    DataHandler& operator=(DataHandler&&)=delete;       // Move Assignment Operator disabled
    
    ~DataHandler()=default;                      // Default destructor enabled

    std::array<int, 5> data() const { return _data; }
    void setData(const std::array<int, 5> &data) { _data = data; }

    std::array<int, 5> squareResults() const { return _squareResults; }
    void setSquareResults(const std::array<int, 5> &squareResults) { _squareResults = squareResults; }

    std::array<int, 5> factorialResults() const { return _factorialResults; }
    void setFactorialResults(const std::array<int, 5> &factorialResults) { _factorialResults = factorialResults; }

    bool getFlag() const { return flag; }
    void setFlag(bool flag_) { flag = flag_; }

    static Pointer getfirstInstances(std::array<int, 5> data){
        if(_solo_hero_obj){
            return _solo_hero_obj;
        }
        else{
            _solo_hero_obj.reset(new DataHandler(data));
            return _solo_hero_obj;
        }
        
    } 

    void TakeInput(std::array<int, 5>& data); 

    void ComputSquare();

    void ComputeFactorial();

    void AverageValue();
};

#endif // DATAHANDLER_H
