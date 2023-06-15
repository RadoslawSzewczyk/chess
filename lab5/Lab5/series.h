#pragma once
# include <iostream>
# include "name.h"
class series: public virtual name
{
protected:

	int liczbaPunktow;

	int* tablica = new int[liczbaPunktow];

public:
	
	series(std::string nazwaC, int liczbaC);

	series();
	~series();

	friend std::ostream& operator<<(std::ostream& seriesOS, const series& series);
};