#pragma once
# include <iostream>

class series
{
protected:
	std::string nazwa;
	int liczbaPunktow;

	int* tablica = new int[liczbaPunktow];

public:
	
	series(std::string nazwaC, int liczbaC);

	series();
	~series();

	friend std::ostream& operator<<(std::ostream& seriesOS, const series& series);
};