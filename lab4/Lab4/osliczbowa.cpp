# include "osliczbowa.h"
# include <iostream>
# include <fstream>

int OsLiczbowa::_count = 0;

OsLiczbowa::OsLiczbowa()
    : _min(0), _max(10), _interval(1)
{
    std::cout << "OsLiczbowa - konstruktor bezargumentowy" << std::endl;
    ++_count;
}

OsLiczbowa::OsLiczbowa(double min, double max)
    : _min(min), _max(max), _interval((max - min) / 10)
{
    std::cout << "OsLiczbowa - konstruktor dwuargumentowy" << std::endl;
    ++_count;
}

OsLiczbowa::OsLiczbowa(const OsLiczbowa& os)
    : _min(os._min), _max(os._max), _interval(os._interval)
{
    std::cout << "OsLiczbowa - konstruktor kopiuj¹cy" << std::endl;
    ++_count;
}

OsLiczbowa::~OsLiczbowa()
{
    std::cout << "OsLiczbowa - destruktor" << std::endl;
    --_count;
}

void OsLiczbowa::print() const
{
    std::cout << "Oœ liczbowa: min = " << _min << ", max = " << _max << ", interval = " << _interval << std::endl;
}

void OsLiczbowa::printCount()
{
    std::cout << "Liczba obiektów klasy OsLiczbowa: " << _count << std::endl;
}

std::ostream& operator<<(std::ostream& os, const OsLiczbowa& osLicz) {
    os << "OsLiczbowa: min=" << osLicz._min << ", max=" << osLicz._max << ", interval=" << osLicz._interval;
    return os;
}



//5
OsLiczbowa& OsLiczbowa::operator=(const OsLiczbowa& os)
{
    std::cout << "Operator przypisania dla obiektu " << this << " zostal wywolany." << std::endl;
    std::cout << "Zawartosc lewego argumentu przed przypisaniem:" << std::endl;
    this->print();

    if (this != &os) {
        this->_min = os._min;
        this->_max = os._max;
        this->_interval = os._interval;
    }

    std::cout << "Zawartosc lewego argumentu po przypisaniu:" << std::endl;
    this->print();

    return *this;
}
//
OsLiczbowa OsLiczbowa::operator*=(const double a)
{
    _min -= 0.5 * (a * _interval);
    _max += 0.5 * (a * _interval);
    _interval *= a;

    return *this;
}

OsLiczbowa OsLiczbowa::operator/=(const double a)
{
    _min += 0.5 * (a * _interval);
    _max -= 0.5 * (a * _interval);
    _interval /= a;

    return *this;
}

