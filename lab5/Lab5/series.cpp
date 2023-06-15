# include "series.h"

series::series(std::string nazwaC, int liczbaC)
{
	nazwa = nazwaC;
	liczbaPunktow = liczbaC;
}

series::series():series{"Series", 10}
{
}

series::~series()
{
}

std::ostream& operator<<(std::ostream& seriesOS, const series& series)
{
	seriesOS << "Nazwa: " << series.nazwa << std::endl << "liczba punktow: " <<series.liczbaPunktow;
	return seriesOS;
}
