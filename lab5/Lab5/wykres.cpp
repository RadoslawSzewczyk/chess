# include "wykres.h"
# include <iostream>


void Wykres::draw()
{
	std::cout << nazwaWykresu << std::endl;
}

void column::draw()
{
	std::cout << "WYKRESWYKRESWYKRESWYKRESWYKRESWYKRESWYKRESWYKRES" << std::endl;;
}

void treemap::draw()
{
	std::cout << "@WYKRESWYKRESWYKRESWYKRESWYKRESWYKRESWYKRESWYKRES" << std::endl;;
}

treemap::treemap()
{
}

void RealChart::printReal()
{
	std::cout << nazwaWykresu << std::endl;
}

RealChart::RealChart(std::string nazwaC, int liczbaC)
{
	nazwa = nazwaC;
	liczbaPunktow = liczbaC;
}

RealChart::~RealChart()
{
}
RealChart::RealChart() :RealChart{ "nazwa", 10 }
{
}

std::ostream& operator<<(std::ostream& RealOS, const series& RealChart)
{
	RealOS << (treemap&)RealChart << (series&)RealChart;
	return RealOS;
}
