#pragma once
# include <fstream>
# include <iostream>
# include "osliczbowa.h"


class ZbiorOsi
{

    OsLiczbowa* osie;
public:
    int rozmiar;
    ZbiorOsi() {};
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