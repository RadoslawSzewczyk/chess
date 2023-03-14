# include <iostream>

class OsLiczbowa
{
public:
	double osMax, osMin;

	OsLiczbowa() { osMin = -10; osMax = 10; };


};

OsLiczbowa Os1;

int main()
{
	std::cout << Os1.osMax;
}