//
//  RBTree.cpp
//  OnlyC++Real
//
//  Created by Danial on 6/16/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#include "RBTree.hpp"

RBTree::RBTree(){
    root = NULL;
    parent = NULL;
}

NodeRB*& RBTree::getRoot(){ 
    return root;
}

void RBTree::Copy()
{
    DoubleList *p=head;
    if (p == NULL){
        cout << "EMPTY";
        return;
    }
    
    do {
        AddToTree(root, p->data);
        p = p->next;
    }while (p!=head);
}

void RBTree::CreateTree(const int& data)
{
    NodeRB* root = new NodeRB;
    root->data = data;
    root->left = root->right = NULL;
    root->color = BLACK;
    root->size = 1;
    this->root = root;
    this->parent = root;
}

void RBTree::AddToTree(NodeRB* &root, int data)
{
    if (!root) {
        root = new NodeRB;

        root->data = data;
        root->size = 1;
        
        root->left = root->right = NULL;
        root->color = RED;
        root->parent = parent;
        
        SetColor(root);
        
        return;
    }
   
    if (data > root->data) {
        root->size++;
        parent = root;
        AddToTree(root->right, data);
    }
    else if (data < root->data){
        root->size++;
        parent = root;
        AddToTree(root->left, data);
    }
    else cout << "Число уже существует\n";
}

void RBTree::RotateLeft(NodeRB *x)
{
    NodeRB *y = x->right;
    
    x->right = y->left;
    if (y->left != NULL) y->left->parent = x;
    
    if (y != NULL) y->parent = x->parent;
    if (x->parent) {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    } else {
        root = y;
    }
    
    y->left = x;
    if (x != NULL) x->parent = y;
}

void RBTree::RotateRight(NodeRB *x)
{
    NodeRB *y = x->left;
    
    x->left = y->right;
    if (y->right != NULL) y->right->parent = x;
    
    if (y != NULL) y->parent = x->parent;
    if (x->parent) {
        if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
    } else {
        root = y;
    }
    
    y->right = x;
    if (x != NULL) x->parent = y;
}

void RBTree::SetColor(NodeRB* node)
{
    while (node != root && node->parent->color == RED) {
        
        if (node->parent == node->parent->parent->left) {
            NodeRB* uncle = node->parent->parent->right;
            if (uncle && uncle->color == RED ) {
                
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                
                if (node == node->parent->right) {
                    node = node->parent;
                    RotateLeft(node);
                }
                
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                RotateRight(node->parent->parent);
            }
        } else {
            
            NodeRB* uncle = node->parent->parent->left;
            if (uncle && uncle->color == RED) {
                
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                
                if (node == node->parent->left) {
                    node = node->parent;
                    RotateRight(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                RotateLeft(node->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void RBTree::ShowTree(NodeRB* root, int p)
{
    if (root == NULL){
        return;
    }else {
        ShowTree(root->right,++p);
        if (!root->right)
        {
            for (int i = 0; i < p; i++){
                cout << " - ";
            }
            cout << " - NIL {BLACK}" <<endl;
        }
        for (int i = 0; i < p; i++){
            cout << " - ";
        }
        
        cout << root->data << " ";
        
        if (root->color == RED){
            cout << "{RED}" <<endl;
        }else{
            cout << "{BLACK}" <<endl;
        }
        
        if (!root->left)
        {
            for (int i = 0; i < p; i++){
                cout << " - ";
            }
            cout << " - NIL {BLACK}" <<endl;
        }
        
        p--;
    }
    ShowTree(root->left, ++p);
}

