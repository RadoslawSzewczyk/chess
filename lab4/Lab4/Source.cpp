# include <iostream>
# include <fstream>
# include "osliczbowa.h"
# include "zbiorosi.h"
# include "wykres.h"

void auxFun_4(Wykres &wykres1)
{
    wykres1.draw();
    ((treemap&)wykres1).draw();
}

void auxFun_4_DC(Wykres *wykres1)
{
    if (wykres1 == nullptr)
    {
        std::cout << "NULLPTR";
        exit(0);
    }

    wykres1 = dynamic_cast <Wykres*>(wykres1);
    wykres1->draw();
}

int main()
{
    //5
    //OsLiczbowa os1(0.0, 10.0);
    //OsLiczbowa os2(20.0, 30.0);

    //std::cout << "Przed przypisaniem:" << std::endl;
    //std::cout << "os1: " << os1 << std::endl;
    //std::cout << "os2: " << os2 << std::endl;

    //os2 = os1;

    //std::cout << "Po przypisaniu:" << std::endl;
    //std::cout << "os1: " << os1 << std::endl;
    //std::cout << "os2: " << os2 << std::endl;
    Wykres wykres1, *pWykres1;

    auxFun_4_DC(pWykres1);
    
}

