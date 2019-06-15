//
//  SL.hpp
//  OnlyC++Real
//
//  Created by Danial on 6/15/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#ifndef SL_hpp
#define SL_hpp

#include <stdio.h>

struct DoubleList
{
    int data;
    DoubleList *next;
    DoubleList *prev;
    
    void AddList(int value);
    void DeleteList(int position);
    void PrintList();
    void GenerateRandomList(int size);
};

#endif /* SL_hpp */
