//
//  BPlusTree.hpp
//  OnlyC++Real
//
//  Created by Danial on 6/16/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#ifndef BPlusTree_hpp
#define BPlusTree_hpp

#include <stdio.h>

#include<string>
#include<sstream>
#include<fstream>
#include <vector>
#include<climits>



int MAX; //size of each node
class BPTree; //self explanatory classes


class Node
{
public:
    bool IS_LEAF;
    int *key, size;
    Node** ptr;
    friend class BPTree;
public:
    Node();
};

class BPTree
{
public:
    Node *root;
    void insertInternal(int,Node*,Node*);
    void removeInternal(int,Node*,Node*);
    Node* findParent(Node*,Node*);
public:
    BPTree();
    void insert(int);
    void remove(int);
    void display(Node*);
    Node* getRoot();
    void cleanUp(Node*);
    ~BPTree();
    
public:
    void Copy();
};

#endif /* BPlusTree_hpp */
