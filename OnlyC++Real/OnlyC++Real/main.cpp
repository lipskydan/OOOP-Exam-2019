//
//  main.cpp
//  OnlyC++Real
//
//  Created by Danial on 6/15/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#include <iostream>
#include "SL.hpp"
#include "SL.cpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    DoubleList a;
    int value, position, x;
    do
    {
        cout<<"1. Добавить элемент"<<endl;
        cout<<"2. Удалить элемент"<<endl;
        cout<<"3. Вывести список"<<endl;
        cout<<"4. Генерация списка"<<endl;
        cout<<"0. Выйти"<<endl;
        cout<<"\nНомер операции > "; cin>>x;
        switch (x)
        {
            case 1:
                cout<<"Значение > "; cin>>value;
                a.AddList(value);
                break;
            case 2:
                cout<<"Позиция > "; cin>>position;
                a.DeleteList(position);
                break;
            case 3:
                a.PrintList();
                break;
            case 4:
                
                break;
        }
    } while (x!=0);
    return 0;
}
