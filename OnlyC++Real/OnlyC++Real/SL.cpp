//
//  SL.cpp
//  OnlyC++Real
//
//  Created by Danial on 6/15/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#include "SL.hpp"

using namespace std;

DoubleList *head;

//**********************ДОБАВЛЕНИЕ ЭЛЕМЕНТА**********************

void DoubleList::AddList(int value)
{
    DoubleList *node=new DoubleList;
    node->data=value;
    if (head==NULL)
    {
        node->next=node;
        node->prev=node;
        head=node;
    }
    else
    {
        DoubleList *p=head;
        while(p!=head) p=p->next;
        //        for(int i=position; i>1; i--) p=p->next;
        p->prev->next=node;
        node->prev=p->prev;
        node->next=p;
        p->prev=node;
    }
    cout<<"\nЭлемент добавлен...\n\n";
}

//***********************УДАЛЕНИЕ ЭЛЕМЕНТА***********************

void DoubleList::DeleteList(int position)
{
    if (head==NULL) { cout<<"\nСписок пуст\n\n"; }
    if (head==head->next)
    {
        delete head;
        head=NULL;
    }
    else
    {
        DoubleList *a=head;
        for (int i=position; i>1; i--) a=a->next;
        if (a==head) head=a->next;
        a->prev->next=a->next;
        a->next->prev=a->prev;
        delete a;
    }
    cout<<"\nЭлемент удален...\n\n";
}

//*************************ВЫВОД СПИСКА*************************

void DoubleList::PrintList()
{
    if (head==NULL) cout<<"\nСписок пуст\n\n";
    else
    {
        DoubleList *a=head;
        cout<<"\nЭлементы списка: ";
        do
        {
            cout<<a->data<<" ";
            a=a->next;
        } while(a!=head); cout<<"\n\n";
    }
}

//*************************РАНДОМНЫЙ СПИСОК*************************
