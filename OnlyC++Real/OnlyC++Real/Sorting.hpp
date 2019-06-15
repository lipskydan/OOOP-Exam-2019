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
    void Save(int from, int to, bool full);
    void ShowVec();
    void CleanVec();
    
    void QuickSort();
    void SelectSort();
    void HeapSort();
    void RadixSort();

private:
    void quickSortAlg(int low, int high);
    
    void selectionSortAlg(int size);
    
    void heapHelp(int n, int i);
    void heapSortAlg(int n);
    
    vector<int> radixHelper (vector<int> arr, int spot);
    void radixSortAlg();
};

#endif /* Sorting_hpp */
