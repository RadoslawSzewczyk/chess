#pragma once
# include <fstream>
# include <iostream>
# include "zbiorosi.h"
# include "series.h"
# include "name.h"
class Wykres : public ZbiorOsi, public virtual name
{
public:
    void drawName();

    virtual void draw() = 0;


    enum typ
    {
        XY, Column, Sunburst, Treemap
    };



    Wykres(int rozmiarK, std::string nazwaWykresuK, typ typK)
    {
        rozmiar = rozmiarK;
        objectName = nazwaWykresuK;
        typ nowyTyp = typK;

    };

    Wykres() : Wykres(10, "Wykres", typ::XY)
    {};
    //~Wykres();


};

class column : public Wykres
{
public:
    virtual void draw();
    column(std::string nazwaK,int rozmiarK)
    {
        rozmiar = rozmiarK;
        objectName = nazwaK;
    };
};

class treemap : public Wykres
{
public:
    virtual void draw();
    treemap(std::string nazwaK, int rozmiarK)
    {
        rozmiar = rozmiarK;
        objectName = nazwaK;
    };
    treemap();
};

class RealChart : public treemap, public series
{
    void printReal();
    RealChart(std::string nazwaC, int liczbaC);
    RealChart();
    ~RealChart();

    friend std::ostream& operator<<(std::ostream& RealOs, const series& RealChart);

};