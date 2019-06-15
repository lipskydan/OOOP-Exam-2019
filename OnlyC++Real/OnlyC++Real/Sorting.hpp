//
//  Sorting.hpp
//  OnlyC++Real
//
//  Created by Danial on 6/15/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#ifndef Sorting_hpp
#define Sorting_hpp


#include "SL.hpp"

class Sorting{
public:
    std::vector<int> vec;
public:
    void CopyToVec();
    void Save();
    void ShowVec();
    
    void QuickSort();

private:
    void quickSortAlg(int low, int high);
};

#endif /* Sorting_hpp */
