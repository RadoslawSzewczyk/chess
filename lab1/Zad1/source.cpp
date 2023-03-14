# include <iostream>

class OsLiczbowa
{
public:
	double osMax = -10;
	double osMin = 10;
	double interval = 1;

	//bz arg 
	OsLiczbowa() {};
	// dwuarg
	OsLiczbowa(int i) {};
	//kopiuj¹cy
	OsLiczbowa(const OsLiczbowa& OsLiczbowa1);
	//dekonstuktor
	~OsLiczbowa();

};

OsLiczbowa::OsLiczbowa() {};

void auxFun(OsLiczbowa)
{
	OsLiczbowa* p1 = new OsLiczbowa;

}

int main()
{

}