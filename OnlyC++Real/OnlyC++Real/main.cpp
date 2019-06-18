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
    int tmp;
    setlocale(LC_ALL, "Rus");
    cout << "0. UnitTests\n";
    cout << "1. Программа\n";
    cout << "Номер команды > "; cin >> tmp;
    cout<<"\n";
    
    if (tmp == 0){
        Test test;
        test.RunAll();
    }else{
        menu m;
        m.Menu();
    }
    return 0;
}
