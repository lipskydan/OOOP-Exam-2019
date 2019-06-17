//
//  Hashing.cpp
//  OnlyC++Real
//
//  Created by Danial on 6/16/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#include "Hashing.hpp"

void Hash::initTable()
{
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
    /* if function has been recursively called max number
     of times, stop and declare cycle. Rehash. */
    if (cnt==n)
    {
        printf("%d unpositioned\n", key);
        printf("Cycle present. REHASH.\n");
        return;
    }

    /* calculate and store possible positions for the key.
     * check if key already present at any of the positions.
     If YES, return. */
    for (int i=0; i<ver; i++)
    {
        pos[i] = hash(i+1, key);
        if (hashtable[i][pos[i]] == key)
            return;
    }

    /* check if another key is already present at the
     position for the new key in the table
     * If YES: place the new key in its position
     * and place the older key in an alternate position
     for it in the next table */
    if (hashtable[tableID][pos[tableID]]!=INT_MIN)
    {
        int dis = hashtable[tableID][pos[tableID]];
        hashtable[tableID][pos[tableID]] = key;
        place(dis, (tableID+1)%ver, cnt+1, n);
    }
    else //else: place the new key in its position
        hashtable[tableID][pos[tableID]] = key;
}

void Hash::printTable()
{
    printf("Final hash tables:\n");
    
    for (int i=0; i<ver; i++, printf("\n"))
        for (int j=0; j<MAXN; j++)
            (hashtable[i][j]==INT_MIN)? printf("- "):
            printf("%d ", hashtable[i][j]);
    
    printf("\n");
}

void Hash::CuckooAlg(vector<int> keys, int n)
{
    // initialize hash tables to a dummy value (INT-MIN)
    // indicating empty position
    initTable();
    
    // start with placing every key at its position in
    // the first hash table according to first hash
    // function
    for (int i=0, cnt=0; i<n; i++, cnt=0)
        place(keys[i], 0, cnt, n);
    
    //print the final hash tables
//    printTable();
}

void Hash::CopyToVec()
{
    DoubleList *p=head;
    if (p == NULL){
        cout << "EMPTY";
        return;
    }
    
    do {
        vec.push_back(p->data);
        p = p->next;
    }while (p!=head);
    
    MAXN = vec.size();
}

void Hash::Cuckoo()
{
    
}
