# include <iostream>

class OsLiczbowa
{

	double osMax = -10;
	double osMin = 10;
	double interval = 1;
public:
	//bz arg 
	OsLiczbowa() {};
	// dwuarg
	OsLiczbowa(int i) {};
	//kopiuj¹cy
	OsLiczbowa(const OsLiczbowa& OsLiczbowa1);
	//dekonstuktor
	~OsLiczbowa();

	void setMax(int s) 
	{
		osMax = s;
	}

	void print()
	{
		std::cout << osMax << osMin << interval;
	}
};

OsLiczbowa::OsLiczbowa() {};

void auxFun(OsLiczbowa)
{
	OsLiczbowa* p1 = new OsLiczbowa;

}

int main()
{

}

OsLiczbowa::~OsLiczbowa()
{
}
