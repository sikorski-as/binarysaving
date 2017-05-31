#include "binary.h"
#include "container.h"

int main()
{
    Container cont1("Ala ma kota.", 2017);
    Container cont2;
    std::cout << "Cont2:\n";
    cont2.printMe();
    cont1.saveMe("dane.txt");
    cont2.loadMe("dane.txt");
    std::cout << "Cont2:\n";
    cont2.printMe();

}
