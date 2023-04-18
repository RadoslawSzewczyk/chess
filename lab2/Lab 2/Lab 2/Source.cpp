# include <iostream>
# include <fstream>


class OsLiczbowa
{
public:
    OsLiczbowa();
    OsLiczbowa(double min, double max);
    OsLiczbowa(const OsLiczbowa& os);
    ~OsLiczbowa();

    double getMin() const { return _min; }
    double getMax() const { return _max; }
    double getInterval() const { return _interval; }

    void setMin(double min) { _min = min; }
    void setMax(double max) { _max = max; }
    void setInterval(double interval) { _interval = interval; }

    void print() const;

    static void printCount();

    friend std::ostream& operator<<(std::ostream& os, const OsLiczbowa& osLicz);

private:
    double _min;
    double _max;
    double _interval;

    static int _count;



};

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
    std::cout << "OsLiczbowa - konstruktor kopiujący" << std::endl;
    ++_count;
}

OsLiczbowa::~OsLiczbowa()
{
    std::cout << "OsLiczbowa - destruktor" << std::endl;
    --_count;
}

void OsLiczbowa::print() const
{
    std::cout << "Oś liczbowa: min = " << _min << ", max = " << _max << ", interval = " << _interval << std::endl;
}

void OsLiczbowa::printCount()
{
    std::cout << "Liczba obiektów klasy OsLiczbowa: " << _count << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////

//ZAD 2

///////////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const OsLiczbowa& osLicz) {
    os << "OsLiczbowa: min=" << osLicz._min << ", max=" << osLicz._max << ", interval=" << osLicz._interval;
    return os;
}

class ZbiorOsi
{
    int rozmiar;
    OsLiczbowa* osie;
public:
    ZbiorOsi(int rozmiar);
    ZbiorOsi(const ZbiorOsi& zbior);
    ZbiorOsi(ZbiorOsi&& zbior);
    ~ZbiorOsi();

    ZbiorOsi(int rozmiar) : rozmiar(rozmiar) {
        if (rozmiar > 0) {
            osie = new OsLiczbowa[rozmiar];
        }
    }

    ZbiorOsi(const ZbiorOsi& other) : rozmiar(other.rozmiar) {
        if (rozmiar > 0) {
            osie = new OsLiczbowa[rozmiar];
            for (int i = 0; i < rozmiar; i++) {
                osie[i] = other.osie[i];
            }
        }
    }

    ZbiorOsi(ZbiorOsi&& other) : rozmiar(other.rozmiar), osie(other.osie) {
        other.rozmiar = 0;
        other.osie = nullptr;
    }

    ~ZbiorOsi() {
        if (osie != nullptr) {
            delete[] osie;
            osie = nullptr;
            rozmiar = 0;
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const ZbiorOsi& osLicz);
    //7
    ZbiorOsi& operator=(ZbiorOsi&& other) {
        if (this != &other) {
            if (osie != nullptr) {
                delete[] osie;
            }
            rozmiar = other.rozmiar;
            osie = other.osie;
            other.rozmiar = 0;
            other.osie = nullptr;
        }
        return *this;
    }

};

//4
//std::ostream& operator<<(std::ostream& os, const ZbiorOsi& osLicz) {
//    os << "OsLiczbowa: min=" << osLicz._min << ", max=" << osLicz._max << ", interval=" << osLicz._interval;
//    return os;
//}

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
//6

int main()
{
    //5
    //OsLiczbowa os1(0.0, 10.0);
    //OsLiczbowa os2(20.0, 30.0);

    //std::cout << "Przed przypisaniem:" << std::endl;
    //std::cout << "os1: " << os1 << std::endl;
    //std::cout << "os2: " << os2 << std::endl;

    //os2 = os1;

    //std::cout << "Po przypisaniu:" << std::endl;
    //std::cout << "os1: " << os1 << std::endl;
    //std::cout << "os2: " << os2 << std::endl;
}

