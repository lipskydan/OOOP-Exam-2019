#include "sl.h"

//**********************ДОБАВЛЕНИЕ ЭЛЕМЕНТА**********************
void DoubleList::AddList(int value)
{
    DoubleList *node=new DoubleList; //создание нового элемента
    node->data=value; //присвоение элементу значения
    if (head==nullptr) //если список пуст
    {
        node->next=node; //установка указателя next
        node->prev=node; //установка указателя prev
        head=node; //определяется голова списка
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
}
//***********************УДАЛЕНИЕ ЭЛЕМЕНТА***********************
void DoubleList::DeleteList(int position)
{
    if (head==nullptr) { }
    if (head==head->next)
    {
        delete head;
        head=nullptr;
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

}
////*************************ВЫВОД СПИСКА*************************
//void DoubleList::PrintList()
//{
//    if (head==nullptr) cout<<"\nСписок пуст\n\n";
//    else
//    {
//        DoubleList *a=head;
//        cout<<"\nЭлементы списка: ";
//        do
//        {
//            cout<<a->data<<" ";
//            a=a->next;
//        } while(a!=head); cout<<"\n\n";
//    }
//}



