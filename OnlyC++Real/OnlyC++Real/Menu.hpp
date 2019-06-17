//
//  Menu.hpp
//  OnlyC++Real
//
//  Created by Danial on 6/15/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include "Sorting.hpp"
#include "SL.hpp"
#include "BPlusTree.hpp"
#include "BPlusTree.cpp"
#include "RBTree.hpp"
#include "RBTree.cpp"
#include "Hashing.hpp"
#include "Hashing.cpp"
#include "Utils.hpp"
#include "Utils.cpp"
#include "UnitTest.hpp"
#include <ctime>

class menu{
public:
    void Menu();

private:
    void CountTimeAndShowRes();
    void StartTimer();
    
private:
    clock_t start;
    double duration;
};


#endif /* Menu_hpp */
