//
//  RBTree.hpp
//  OnlyC++Real
//
//  Created by Danial on 6/16/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#ifndef RBTree_hpp
#define RBTree_hpp

#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <vector>
#include <fstream>

using namespace std;

typedef enum { BLACK, RED } nodeColor;

struct NodeRB {
    NodeRB* left;
    NodeRB* right;
    nodeColor color;
    NodeRB* parent;
    int data;
    int size;
    string name;
    string price;
};

class RBTree {
public:
    RBTree();
    void CreateTree(const int& data);
    void AddToTree(NodeRB* &root, int data);
    
    void RotateLeft(NodeRB *x);
    void RotateRight(NodeRB *x);
    void SetColor(NodeRB* node);

    void ShowTree(NodeRB* root, int p = -1);
    NodeRB*& getRoot();
    
    void Copy();
    
private:
    NodeRB *root;
    NodeRB *parent;
};

#endif /* RBTree_hpp */
