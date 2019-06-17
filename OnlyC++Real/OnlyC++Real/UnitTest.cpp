//
//  UnitTest.cpp
//  OnlyC++Real
//
//  Created by Danial on 6/17/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#include "UnitTest.hpp"
#include "Utils.hpp"
#include <iostream>


Test::Test(): TestListSize(8) {
    
    TestList.AddList(1);
    TestList.AddList(22);
    TestList.AddList(4363);
    TestList.AddList(35235);
    TestList.AddList(457474);
    TestList.AddList(5235);
    TestList.AddList(100);
    TestList.AddList(123);
    
}

bool Test::CopyToVecTest()
{
    vector<int> vec;
    //vec.resize(8);
    
    CopyToVec(TestList, vec);
    
    DoubleList *p = head;
    
    int i = 0;
    
    do {
        if (p->data != vec[i]) return false;
        //cout << p->data << " <-> " << vec[i] <<"\n";
        p = p->next;
        i++;
    } while (p != head);
    
    return true;
}

bool Test::SortingTest()
{
    bool quick, select, heap, radix;
    
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(22);
    tmp.push_back(100);
    tmp.push_back(123);
    tmp.push_back(4363);
    tmp.push_back(5235);
    tmp.push_back(35235);
    tmp.push_back(457474);
    
    CopyToVec(TestList, sort.vec);
    sort.QuickSort();
    for(int i = 0; i < sort.vec.size(); i++)
    {
        if (sort.vec[i] != tmp[i]) quick = false;
    }
    quick = true;
    if (quick) {
        std::cout << "QuickSort [✓ Success]";
    } else {
        std::cout << "QuickSort [- Failed]";
    }
    
    std::cout << " ....... ";
    
    CopyToVec(TestList, sort.vec);
    sort.HeapSort();
    for(int i = 0; i < sort.vec.size(); i++)
    {
        if (sort.vec[i] != tmp[i]) heap = false;
    }
    heap = true;
    if (heap) {
        std::cout << "HeapSort [✓ Success]";
    } else {
        std::cout << "HeapSort [- Failed]";
    }
    
    std::cout << " ....... ";
    
    CopyToVec(TestList, sort.vec);
    sort.SelectSort();
    for(int i = 0; i < sort.vec.size(); i++)
    {
        if (sort.vec[i] != tmp[i]) select = false;
    }
    select = true;
    if (select) {
        std::cout << "SelectSort [✓ Success]";
    } else {
        std::cout << "SelectSort [- Failed]";
    }
    
    std::cout << " ....... ";
    
    CopyToVec(TestList, sort.vec);
    sort.RadixSort();
    for(int i = 0; i < sort.vec.size(); i++)
    {
        if (sort.vec[i] != tmp[i]) radix = false;
    }
    radix = true;
    if (radix) {
        std::cout << "SelectSort [✓ Success]";
    } else {
        std::cout << "SelectSort [- Failed]";
    }
    
    if (!quick || !heap || !select || !radix) return false;
    return true;
}

bool Test::HashingTest()
{
   
    return true;
}


void Test::RunAll() {
    
    std::cout << "Starting test CopyToVecTest...\n\n";
    if (CopyToVecTest()) {
        std::cout << "CopyToVecTest [✓ Success]\n\n";
    } else {
        std::cout << "[Failed]\n\n";
    }

    std::cout << "Starting test SortingTest...\n\n";
    if (SortingTest()) {
        std::cout << "\n\nSortingTest [✓ Success]\n\n";
    } else {
        std::cout << "[Failed]\n";
    }
    std::cout << "_____________________________________________________ \n\n\n";
}
