# include "zbiorosi.h"
# include <fstream>
# include <iostream>

//4
std::ostream& operator<<(std::ostream& os, const ZbiorOsi& osLicz) {
    for (int i = 0; i < osLicz.rozmiar; i++)
    {
        os << osLicz.osie[i] << std::endl;
    }
    return os;
}