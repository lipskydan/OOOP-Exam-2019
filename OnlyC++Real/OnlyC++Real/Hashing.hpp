//
//  Hashing.hpp
//  OnlyC++Real
//
//  Created by Danial on 6/16/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#ifndef Hashing_hpp
#define Hashing_hpp

//#define MAXN 11
//#define ver 2

#include <stdio.h>
#include <vector>

class Hash{
public:
    void Cuckoo();
    void CopyToVec();
    void CuckooAlg(vector<int> keys, int n);
    void printTable();
    
    vector<int> getVec(){
        return vec;
    }
    
private:
    void initTable();
    int hash(int function, int key);
    void place(int key, int tableID, int cnt, int n);
    
    
    
public:
    int MAXN;
    const int ver = 2;
    
    vector<int> pos;
    vector<vector<int>> hashtable;
    vector<int> vec;
};

#endif /* Hashing_hpp */
