#pragma once
# include <fstream>
# include <iostream>
# include "zbiorosi.h"

class Wykres : private ZbiorOsi
{
    std::string nazwaWykresu;

    enum typ
    {
        XY, Column, Sunburst, Treemap
    };



    Wykres(int rozmiarK, std::string nazwaWykresuK, typ typK)
    {
        rozmiar = rozmiarK;
        nazwaWykresu = nazwaWykresuK;
        typ nowyTyp = typK;

    };

    Wykres(): Wykres(10, "Wykres", typ::XY)
    {}
    ~Wykres();


};
