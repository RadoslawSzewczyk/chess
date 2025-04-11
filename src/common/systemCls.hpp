#include <cstdlib>

inline void clearScreen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    std::system ("clear");
#endif
}