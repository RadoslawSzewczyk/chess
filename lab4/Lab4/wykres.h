#pragma once
# include <fstream>
# include <iostream>
# include "zbiorosi.h"

class Wykres : public ZbiorOsi
{
public:
    void draw();

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

    Wykres() : Wykres(10, "Wykres", typ::XY)
    {};
    //~Wykres();


};

class column : public Wykres
{
public:
    void draw();
    column(std::string nazwaK,int rozmiarK)
    {
        rozmiar = rozmiarK;
        nazwaWykresu = nazwaK;
    };
};

class treemap : public Wykres
{
public:
    void draw();
    treemap(std::string nazwaK, int rozmiarK)
    {
        rozmiar = rozmiarK;
        nazwaWykresu = nazwaK;
    };
};