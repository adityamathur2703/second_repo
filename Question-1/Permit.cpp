#include "Permit.h"

std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    os << "_permitNumber: " << rhs._permitNumber
       << " _permitDurationRemaining: " << rhs._permitDurationRemaining;
    return os;
}

Permit::Permit(std::string permitNumber, unsigned int permitDurationRemaining)
:_permitNumber{permitNumber}, _permitDurationRemaining{permitDurationRemaining}{}