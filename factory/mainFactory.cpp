#include "FahrzeugFactory.hpp"
#include <list>
#include <iostream>

int main() {

    auto fzg = FahrzeugFactory::erstelle("auto");
    if (fzg) std::cout << fzg->info();
    auto fzg1 = FahrzeugFactory::erstelle("lkw");
    if (fzg1) std::cout << fzg1->info();


    return 0;
}