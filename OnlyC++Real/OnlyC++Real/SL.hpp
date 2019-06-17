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
#include <cstdlib>
#include <vector>

struct DoubleList
{
    int data;
    int key;
    DoubleList *next;
    DoubleList *prev;
    
    void AddList(int value, int position = 0);
    void DeleteList(int position);
    
    void СleanList();
    
    void PrintList(bool bKey, bool bData);
    void GenerateRandomList(int size);
    
    std::pair<int,int> GetValueByKey(int keyForSerch);
    void ChangeValueByKey(int keyForSerch, int valueForChange);
    
    
    bool EmptyList();
    int GetGlobalKey();
    
};

DoubleList *head;
#endif /* SL_hpp */
