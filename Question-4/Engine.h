#ifndef ENGINE_H
#define ENGINE_H

#include "EngineType.h"
#include <ostream>

class Engine
{
private:
    EngineType _eType{EngineType::EV};
    unsigned int _engineHorsePower{0};
    float _engineTorque{0.0f};

public:
    Engine()=default;          // Default constructor enabled 
    
    Engine(const Engine&)=delete;              // Copy constructor disabled
    
    Engine(Engine&&)=delete;                   // Move Constructor disabled
    
    Engine& operator=(const Engine&)=delete;      // Copy Assignment Operator diabled
    
    Engine& operator=(Engine&&)=delete;       // Move Assignment Operator disabled
    
    ~Engine()=default;                      // Default destructor enabled

    Engine(EngineType eType, unsigned int engineHorsePower, float engineTorque);

    EngineType eType() const { return _eType; }
    void setEType(const EngineType &eType) { _eType = eType; }

    unsigned int engineHorsePower() const { return _engineHorsePower; }
    void setEngineHorsePower(unsigned int engineHorsePower) { _engineHorsePower = engineHorsePower; }

    float engineTorque() const { return _engineTorque; }
    void setEngineTorque(float engineTorque) { _engineTorque = engineTorque; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

#endif // ENGINE_H
