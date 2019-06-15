//
//  Sorting.cpp
//  OnlyC++Real
//
//  Created by Danial on 6/15/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#include "Sorting.hpp"
#include <iostream>

DoubleList a;
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

void Sorting::selectionSortAlg(int size)
{
    int min, temp;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (vec[j] < vec[min])
            {
                min = j;
            }
        }
        temp = vec[i];
        vec[i] = vec[min];
        vec[min] = temp;
    }
}

void Sorting::heapHelp(int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l < n && vec[l] > vec[largest])
        largest = l;
    
    if (r < n && vec[r] > vec[largest])
        largest = r;
    
    if (largest != i)
    {
        swap(vec[i], vec[largest]);
        heapHelp(n, largest);
    }
}

void Sorting::heapSortAlg(int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapHelp(n, i);
    
    for (int i=n-1; i>=0; i--)
    {
        swap(vec[0], vec[i]);
        heapHelp(i, 0);
    }
}

vector<int> Sorting::radixHelper (vector<int> arr, int spot)
{
    vector<int> count(10,0);
    
    vector<int> retVal(arr.size(),0);
    
    for (int i = 0; i < arr.size(); ++i)//Fill count array
    {
        int temp = arr[i];
        for (int j = 0; j < spot; ++j)
        {
            temp/=10;
        }
        count[temp%10]++;
    }
    
    for (int i = 1; i < count.size(); ++i)//Sum count array
    {
        count[i] += count[i-1];
    }
    
    for (int i = arr.size()-1; i >= 0; --i)//Find which values match what spots //complicated part
    {
        int temp = arr[i];
        for (int j = 0; j < spot; ++j)
        {
            temp/=10;
        }
        
        temp = temp%10;
        
        for (int j = 0; j < count.size(); ++j)
        {
            if(j==temp)
            {
                retVal[--count[j]]=arr[i];
            }
        }
    }
    
    return retVal;
}

void Sorting::radixSortAlg()
{
    for (int i = 0; i < 10; ++i)
    {
        vec = radixHelper(vec,i);
    }
}

//**********************САМИ СОРТИРОВКИ**********************

void Sorting::QuickSort()
{
    quickSortAlg(0, vec.size()-1);
    cout<<"\nОтсортировано...\n\n";
}

void Sorting::SelectSort()
{
    selectionSortAlg(vec.size());
    cout<<"\nОтсортировано...\n\n";
}

void Sorting::HeapSort()
{
    heapSortAlg(vec.size());
    cout<<"\nОтсортировано...\n\n";
}

void Sorting::RadixSort()
{
    radixSortAlg();
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

void Sorting::Save(int from, int to, bool full)
{
    DoubleList *p=head;
    if (p == NULL){
        cout << "EMPTY";
        return;
    }

    if (full == true){
        int i = 0;
        do {
            p->data = vec[i];
            p = p->next;
            i++;
        }while (p!=head);
    }
    
    
    if (full == false){
        a.СleanList();
        global_key = 1;
        
        for (int i = from-1; i < to; i++) {
            a.AddList(vec[i]);
            
        }
    }
    
    cout<<"\nСписок сохранен...\n\n";
}

void Sorting::ShowVec()
{
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " \n";
    }
    cout << "\n\n";
}

void Sorting::CleanVec()
{
    vec.clear();
}
