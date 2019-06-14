#ifndef LIST_H
#define LIST_H

struct SL
{
  int field;
  struct SL *next;
  struct SL *prev;
};

SL *init(int a)
{
  struct SL *lst;
//  lst = (struct list*)malloc(sizeof(struct list));
  lst->field = a;
  lst->next = lst;
  lst->prev = lst;
  return(lst);
}

 SL * addelem(SL *lst, int number)
{
  struct SL *temp, *p;
//  temp = (struct list*)malloc(sizeof(list));
  p = lst->next;
  lst->next = temp;
  temp->field = number;
  temp->next = p;
  temp->prev = lst;
  p->prev = temp;
  return(temp);
}

 SL * deletelem(SL *lst)
{
  struct SL *prev, *next;
  prev = lst->prev;
  next = lst->next;
  prev->next = lst->next;
  next->prev = lst->prev;
  //free(lst);
  return(prev);
}

void listprint(SL *lst)
{
  struct SL *p;
  p = lst;
  do {
//    printf("%d ", p->field); // вывод значения элемента p
    p = p->next; // переход к следующему узлу
  } while (p != lst); // условие окончания обхода
}



#endif // LIST_H

