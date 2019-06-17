//
//  Utils.cpp
//  OnlyC++Real
//
//  Created by Danial on 6/17/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#include "Utils.hpp"

void CopyToVec(DoubleList &a, vector<int> &vec)
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
    
}
