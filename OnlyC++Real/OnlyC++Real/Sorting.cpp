//
//  Sorting.cpp
//  OnlyC++Real
//
//  Created by Danial on 6/15/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#include "Sorting.hpp"
#include <iostream>

//**********************АЛГОРИТМЫ СОРТИРОВОК**********************

void Sorting::quickSortAlg(int low, int high)
{
    int i = low;
    int j = high;
    int pivot = vec[(i + j) / 2];
    int temp;
    while (i <= j)
    {
        while (vec[i] < pivot)
            i++;
        while (vec[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSortAlg(low, j);
    if (i < high)
        quickSortAlg(i, high);
}

//**********************САМИ СОРТИРОВКИ**********************

void Sorting::QuickSort()
{
    quickSortAlg(0, vec.size()-1);
    cout<<"\nОтсортировано...\n\n";
}

//**********************ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ**********************

void Sorting::CopyToVec()
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

void Sorting::Save()
{
    DoubleList *p=head;
    if (p == NULL){
        cout << "EMPTY";
        return;
    }
    
    int i = 0;
    do {
        p->data = vec[i];
        p = p->next;
        i++;
    }while (p!=head);
    
    cout<<"\nСписок отсортирован и сохранен...\n\n";
}

void Sorting::ShowVec()
{
//    quickSort(0, vec.size()-1);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n\n";
}


