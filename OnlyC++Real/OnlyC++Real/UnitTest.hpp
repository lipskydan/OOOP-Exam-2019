//
//  UnitTest.hpp
//  OnlyC++Real
//
//  Created by Danial on 6/17/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#ifndef UnitTest_hpp
#define UnitTest_hpp

#include <stdio.h>
#include <vector>

#include "SL.hpp"

class Test{
public:
    Test();
    void RunAll();
    
    bool CopyToVecTest();
    bool SortingTest();
    bool HashingTest();
    
private:
    vector<int> TestVec;
    const int TestListSize;
    DoubleList TestList;
    Sorting sort;
    Hash hash;
};

#endif /* UnitTest_hpp */



