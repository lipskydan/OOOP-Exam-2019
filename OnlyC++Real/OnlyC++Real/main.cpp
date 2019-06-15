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
#include "Sorting.hpp"
#include "Sorting.cpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    DoubleList a;
    Sorting sort;
    int value, position, x, y;
    int size;
    do
    {
        cout<<"1. Добавить элемент"<<endl;
        cout<<"2. Удалить элемент"<<endl;
        cout<<"3. Вывести список (only data)"<<endl;
        cout<<"4. Вывести список (only key)"<<endl;
        cout<<"5. Вывести список (key & data)"<<endl;
        cout<<"6. Генерация списка"<<endl;
        cout<<"7. Найти елемент списка по ключу"<<endl;
        cout<<"8. Изменить елемент списка по ключу"<<endl;
        cout<<"9. Сортировка"<<endl;
        cout<<"0. Выйти"<<endl;
        cout<<"\nНомер операции > "; cin>>x;
        switch (x)
        {
            case 1:
                cout<<"Значение > "; cin>>value;
                cout<<"Позиция (если выбрать 0, то елемент вставится в конец ) > "; cin>>position;
                a.AddList(value, position);
                break;
            case 2:
                cout<<"Позиция > "; cin>>position;
                a.DeleteList(position);
                break;
            case 3:
                a.PrintList(false, true);
                break;
            case 4:
                a.PrintList(true, false);
                break;
            case 5:
                a.PrintList(true, true);
                break;
            case 6:
                cout<<"Количество элементов > "; cin>>size;
                a.GenerateRandomList(size);
                break;
            case 7:
                cout<<"Номер ключа > "; cin>>value;
                cout << "Елемент < ";
                if (a.GetValueByKey(value).first == a.GetValueByKey(value).second == -1) {
                    cout << "не найден";
                }else{
                    cout << a.GetValueByKey(value).second;
                }
                cout << "\n\n";
                break;
            case 8:
                cout<<"Номер ключа > "; cin>>position;
                cout<<"Значение > "; cin>>value;
                
                cout<<"Операция < ";
                a.ChangeValueByKey(position, value);
                break;
            case 9:
                sort.CopyToVec();
                do{
                    cout<<"1. Quick Sort"<<endl;
                    cout<<"2. Сохранить очередность и выйти с меню сортировки"<<endl;
                    cout<<"0. Выйти"<<endl;
                    cout<<"\nНомер операции > "; cin>>y;
                    
                    switch (y) {
                        case 1:
                            sort.QuickSort();
                            break;
                        case 2:
                            sort.Save();
                            y = 0;
                            break;
                    }
                }while (y!=0);
                break;
        }
    } while (x!=0);
    return 0;
}
