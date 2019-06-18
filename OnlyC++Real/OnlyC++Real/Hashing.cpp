//
//  Hashing.cpp
//  OnlyC++Real
//
//  Created by Danial on 6/16/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#include "Hashing.hpp"
#include <iomanip>

void Hash::initTable()
{
    hashtable.resize(ver);
    hashtable[0].resize(MAXN);
    hashtable[1].resize(MAXN);
    pos.resize(ver);
    
    for (int j=0; j < MAXN; j++)
        for (int i=0; i < ver; i++)
           hashtable[i][j] = INT_MIN;
}

int Hash::hash(int function, int key)
{
    switch (function)
    {
        case 1: return key%MAXN;
        case 2: return (key/MAXN)%MAXN;
    }
    return 0;
}

void Hash::place(int key, int tableID, int cnt, int n)
{
    if (cnt==n)
    {
//        printf("%d unpositioned\n", key);
//        printf("Cycle present. REHASH.\n");
        return;
    }

    for (int i=0; i<ver; i++)
    {
        pos[i] = hash(i+1, key);
        if (hashtable[i][pos[i]] == key)
            return;
    }

    if (hashtable[tableID][pos[tableID]]!=INT_MIN)
    {
        int dis = hashtable[tableID][pos[tableID]];
        hashtable[tableID][pos[tableID]] = key;
        place(dis, (tableID+1)%ver, cnt+1, n);
    }
    else
        hashtable[tableID][pos[tableID]] = key;
}

void Hash::printTable()
{
    printf("Final hash tables:\n");
    
    for (int i=0; i<ver; i++, printf("\n"))
        for (int j=0; j<MAXN; j++)
            (hashtable[i][j]==INT_MIN)? cout << setw(15) << "-":
            cout << setw(15) << hashtable[i][j];  //            printf("%d ", hashtable[i][j]);
    
    printf("\n");
}

void Hash::CuckooAlg(vector<int> keys, int n)
{
    MAXN = vec.size()+1;
    initTable();
    
    for (int i=0, cnt=0; i<n; i++, cnt=0)
        place(keys[i], 0, cnt, n);
}

void Hash::Cuckoo()
{
    CuckooAlg(vec, vec.size());
}
