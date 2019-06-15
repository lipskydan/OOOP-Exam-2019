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
int global_key = 1;

bool DoubleList::EmptyList(){
    if (head==NULL) {
        cout<<"\nСписок пуст\n\n";
        return true;
    }
    return false;
}

int DoubleList::GetGlobalKey(){
    return global_key;
}


//**********************ДОБАВЛЕНИЕ ЭЛЕМЕНТА**********************

void DoubleList::AddList(int value, int position)
{
    DoubleList *node=new DoubleList;
    node->data=value;
    node->key = global_key;
    global_key++;
    if (head==NULL)
    {
        node->next=node;
        node->prev=node;
        head=node;
    }
    else
    {
        DoubleList *p=head;
        if (position == 0) while(p!=head) p=p->next;
        else for(int i=position; i>1; i--) p=p->next;
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
//    if (head==NULL) { cout<<"\nСписок пуст\n\n"; }
    if (EmptyList()) return;
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

//***********************УДАЛЕНИЕ ВСЕХ ЭЛЕМЕНТОВ***********************

void DoubleList::СleanList()
{
    while(global_key!=1){
        DeleteList(global_key);
        global_key--;
    }
}

//*************************ВЫВОД СПИСКА*************************

void DoubleList::PrintList(bool bKey, bool bData)
{
//    if (head==NULL) cout<<"\nСписок пуст\n\n";
    if (EmptyList()) return;
    else
    {
        DoubleList *a=head;
        cout<<"\nЭлементы списка: \n";
        do
        {
            if (bKey == true) cout << "# " << a->key;
            if (bData && bKey) cout << " <-> ";
            if (bData == true) cout << a->data;
            a=a->next;
            cout<<"\n";
        } while(a!=head); cout<<"\n\n";
    }
}

//*************************РАНДОМНЫЙ СПИСОК*************************

void DoubleList::GenerateRandomList(int size)
{
    vector<int> vec;
    srand (time(NULL));
    for(int i = 0; i < size; i++){
        vec.push_back(rand());
    }
    for (int i = 0; i < vec.size(); i++) {
        AddList(vec[i], global_key);
    }
}

//*************************НАХОЖДЕНИЯ ЕЛЕМЕНТА ПО КЛЮЧУ*************************

pair<int,int> DoubleList::GetValueByKey(int keyForSerch)
{
    if (EmptyList()) return (pair<int,int>(-1,-1)); //return pair<-1, false>;
    
    DoubleList *p=head;

    while(p->key != keyForSerch){
        p=p->next;
        if (p == head || keyForSerch > global_key || keyForSerch < 1){
            return (pair<int,int>(-1,-1));
    }
    }
    return (pair<int,int>(p->key,p->data));//p->data;
}

//*************************ИЗМЕНЕНИЕ ЕЛЕМЕНТА ПО КЛЮЧУ*************************

void DoubleList::ChangeValueByKey(int keyForSerch, int valueForChange)
{
    if (GetValueByKey(keyForSerch).first == GetValueByKey(keyForSerch).second == -1){
        cout << " провалена \n\n";
        return;
    }
    DoubleList * a = head;
    
    while(a->key != keyForSerch){
        a=a->next;
    }
    
    a->data = valueForChange;
    cout << " успешна \n\n";
}
