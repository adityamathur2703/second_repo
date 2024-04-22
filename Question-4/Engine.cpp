#include "Engine.h"

Engine::Engine(EngineType eType, unsigned int engineHorsePower, float engineTorque)
:_eType{eType}, _engineHorsePower{engineHorsePower}, _engineTorque{engineTorque}
{}

std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    std::string type;
    if(rhs._eType==EngineType::EV){
        type="EV";
    }
    else{
        type="IC";
    }
    os << "_eType: " << type
       << " _engineHorsePower: " << rhs._engineHorsePower
       << " _engineTorque: " << rhs._engineTorque;
    return os;
}
