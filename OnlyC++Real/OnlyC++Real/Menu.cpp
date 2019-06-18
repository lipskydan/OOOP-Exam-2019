//
//  Menu.cpp
//  OnlyC++Real
//
//  Created by Danial on 6/15/19.
//  Copyright © 2019 Danial. All rights reserved.
//

#include "Menu.hpp"


void menu::StartTimer(){
    start = clock();
}

void menu::CountTimeAndShowRes()
{
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    
    cout<<"\n(Время выполнения заняло "<< duration <<" секунд) \n";
}

void menu::Menu()
{
    DoubleList a;
    Sorting sort;
    BPTree bpt;
    RBTree rbt;
    Hash hash;
    int value, position, x, y, z, w;
    int size;
    
    string command;
    int xx;
    bool close = false;
    
    do
    {
        cout<<"1. Добавить элемент"<<endl;
        cout<<"2. Удалить элемент"<<endl;
        cout<<"3. Очистить список"<<endl;
        cout<<"4. Вывести список (only data)"<<endl;
        cout<<"5. Вывести список (only key)"<<endl;
        cout<<"6. Вывести список (key & data)"<<endl;
        cout<<"7. Генерация списка"<<endl;
        cout<<"8. Найти елемент списка по ключу"<<endl;
        cout<<"9. Изменить елемент списка по ключу"<<endl;
        cout<<"10. Сортировка"<<endl;
        cout<<"11. Трансформация в сбалансированое дерево поиска"<<endl;
        cout<<"12. Hashing"<<endl;
        cout<<"0. Выйти"<<endl;
        cout<<"\nНомер операции > "; cin>>x;
        cout<<"\n";
        switch (x)
        {
            case 1:
                cout<<"Значение > "; cin>>value;
                cout<<"Позиция (если выбрать 0, то елемент вставится в конец ) > "; cin>>position;
                StartTimer();
                a.AddList(value, position);
                CountTimeAndShowRes();
                cout<<"\nЭлемент добавлен...\n\n";
                break;
            case 2:
                cout<<"Позиция > "; cin>>position;
                StartTimer();
                a.DeleteList(position);
                CountTimeAndShowRes();
                cout<<"\nЭлемент удален...\n\n";
                break;
            case 3:
                StartTimer();
                a.СleanList();
                CountTimeAndShowRes();
                break;
            case 4:
                StartTimer();
                a.PrintList(false, true);
                CountTimeAndShowRes();
                break;
            case 5:
                StartTimer();
                a.PrintList(true, false);
                CountTimeAndShowRes();
                break;
            case 6:
                StartTimer();
                a.PrintList(true, true);
                CountTimeAndShowRes();
                break;
            case 7:
                cout<<"Количество элементов > "; cin>>size;
                StartTimer();
                a.GenerateRandomList(size);
                CountTimeAndShowRes();
                cout<<"\nЭлементы добавлены...\n\n";
                break;
            case 8:
                cout<<"Номер ключа > "; cin>>value;
                cout << "Елемент < ";
                if (a.GetValueByKey(value).first == a.GetValueByKey(value).second == -1) {
                    cout << "не найден";
                }else{
                    StartTimer();
                    cout << a.GetValueByKey(value).second;
                    CountTimeAndShowRes();
                }
                cout << "\n\n";
                break;
            case 9:
                cout<<"Номер ключа > "; cin>>position;
                cout<<"Значение > "; cin>>value;
                
                cout<<"Операция < ";
                StartTimer();
                a.ChangeValueByKey(position, value);
                CountTimeAndShowRes();
                break;
            case 10: // Sorting
                CopyToVec(a, sort.vec);
                do{
                    cout<<"1. Quick Sort"<<endl;
                    cout<<"2. Select Sort"<<endl;
                    cout<<"3. Heap Sort"<<endl;
                    cout<<"4. Radix Sort"<<endl;
                    cout<<"5. Сохранить очередность и выйти с меню сортировки"<<endl;
                    cout<<"6. Show"<<endl;
                    cout<<"0. Выйти с этого раздела"<<endl;
                    cout<<"\nНомер операции > "; cin>>y;
                    cout<<"\n";
                    switch (y) {
                        case 1:
                            cout<<"\nОтсортировано...\n\n";
                            StartTimer();
                            sort.QuickSort();
                            CountTimeAndShowRes();
                            break;
                        case 2:
                            cout<<"\nОтсортировано...\n\n";
                            StartTimer();
                            sort.SelectSort();
                            CountTimeAndShowRes();
                            break;
                        case 3:
                            cout<<"\nОтсортировано...\n\n";
                            StartTimer();
                            sort.HeapSort();
                            CountTimeAndShowRes();
                            break;
                        case 4:
                            cout<<"\nОтсортировано...\n\n";
                            StartTimer();
                            sort.RadixSort();
                            CountTimeAndShowRes();
                            break;
                        case 5:
                            bool full;
                            cout << " Сохранить полностью? (1 - yes / 0 - no): "; cin >> full;
                            int from, to;
                            if (!full){
                                cout << " Сохранить с елемента №"; cin >> from;
                                cout << " по елемента №"; cin >> to;
                            }
                            StartTimer();
                            sort.Save(from, to, full);
                            CountTimeAndShowRes();
                            y = 0;
                            break;
                        case 6:
                            StartTimer();
                            sort.ShowVec();
                            CountTimeAndShowRes();
                            break;
                    }
                    cout<<"\n";
                }while (y!=0);
                sort.CleanVec();
                break;
            case 11: // Trees
                do{
                    cout<<"1. R-B"<<endl;
                    cout<<"2. B+"<<endl;
                    cout<<"0. Выйти с этого раздела"<<endl;
                    cout<<"\nНомер операции > "; cin>>z;
                    cout<<"\n";
                    switch (z) {
                        case 1:
                            
                            StartTimer();
                            rbt.Copy();
                            CountTimeAndShowRes();
                            cout << "Список конвертирован в R-В дерево\n";
                            cout<<"\n";
                            rbt.ShowTree(rbt.getRoot());
                            cout<<"\n";
                            do{
                                cout<<"You choosed R-B\n";
                                cout<<"1. AddToTree"<<endl;
                                cout<<"2. ShowTree"<<endl;
                                cout<<"0. Выйти с этого раздела"<<endl;
                                cout<<"\nНомер операции > "; cin>>w;
                                switch (w) {
                                    case 1:
                                        cout<<"Значение > "; cin>>value;
                                        StartTimer();
                                        rbt.AddToTree(rbt.getRoot(), value);
                                        CountTimeAndShowRes();
                                        cout<<"\nЭлемент добавлен...\n\n";
                                        break;
                                    case 2:
                                        cout<<"\n";
                                        StartTimer();
                                        rbt.ShowTree(rbt.getRoot());
                                        CountTimeAndShowRes();
                                        cout<<"\n";
                                        break;
                                }
                            }while (w!=0);
                            break;
                            
                        case 2:
                            cout<<"You choosed B+"<<endl;
                            cout<<"Максимальное количество элементов в одном блоке? :";
                            cin>>command;
                            cout<<"\n";
                            stringstream max(command);
                            max>>MAX;
                            
                            StartTimer();
                            bpt.Copy();
                            CountTimeAndShowRes();
                            cout << "Список конвертирован в В+ дерево\n";
                            
                            do
                            {
                                cout<<"insert <value> - чтобы вставить\n";
                                cout<<"delete <value> - чтобы удалить\n";
                                cout<<"display - чтобы вывести информацию на экран\n";
                                cout<<"exit - чтобы выйти с этого раздела\n";
                                cout<<"Имя операции > \n";
                            
                                getline(cin,command);
                                if(!command.substr(0,6).compare("insert"))
                                {
                                    stringstream argument(command.substr(7));
                                    argument>>xx;
                                    StartTimer();
                                    bpt.insert(xx);
                                    CountTimeAndShowRes();
                                }
                                else if(!command.substr(0,6).compare("delete"))
                                {
                                    stringstream argument(command.substr(7));
                                    argument>>xx;
                                    StartTimer();
                                    bpt.remove(xx);
                                    CountTimeAndShowRes();
                                }
                                else if(!command.compare("display"))
                                {
                                    StartTimer();
                                    bpt.display(bpt.getRoot());
                                    CountTimeAndShowRes();
                                }
                                else if(!command.compare("exit"))
                                {
                                    close = true;
                                }
                            }while(!close);
                            break;
                    }
                    cout<<"\n";
                }while (z!=0);
                break;
            case 12:
                cout<<"Hashing"<<endl;
                CopyToVec(a, hash.vec);
                StartTimer();
                hash.Cuckoo();
                CountTimeAndShowRes();
                cout<<"\n";
                hash.printTable();
                cout<<"\n";
                break;
        }
        cout<<"\n";
    } while (x!=0);
}
