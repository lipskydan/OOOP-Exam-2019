//
//  main.cpp
//  OnlyC++Real
//
//  Created by Danial on 6/15/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#include <iostream>
#include "SL.hpp"
#include "SL.cpp"
#include "Sorting.hpp"
#include "Sorting.cpp"
#include "Menu.hpp"
#include "Menu.cpp"
#include "UnitTest.hpp"
#include "UnitTest.cpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    Test test;
    test.RunAll();
    
    menu m;
    m.Menu();
    return 0;
}
