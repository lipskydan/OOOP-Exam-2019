#ifndef SL_H
#define SL_H

struct DoubleList //описание узла списка
{
public:
    int data; //информационное поле
    DoubleList *next; //указатель на следующий элемент
    DoubleList *prev; //указатель на предыдущий элемент

    void AddList(int value);
    void DeleteList(int position);
    void PrintList();
};
DoubleList *head; //указатель на первый элемент списка

#endif // SL_H
