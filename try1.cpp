#include <conio.h>
#include <iostream>
#include <string> 

using namespace std;

struct Horses
{
    string name;
    int years;
    double distance; //дистанция, которую пробежала лошадка за минуты 
    Horses *next;


    typedef Horses *PHorses;  //указатель на структуру
    PHorses Head = NULL;    //адрес начала списка

    PHorses CreateHorse(string NewName, int Newyears, double Newdistance)//имя нового предмета и их количество
    {
        Horses* NewHorses = new Horses;
        NewHorses->name = NewName;
        NewHorses->years = Newyears;
        NewHorses->distance = Newdistance;
        NewHorses->next = NULL;
        return NewHorses;
    }

    //Добавление в начало
    void Addbegin(Horses*& Head, string NewName, int Newyears, double Newdistance) {
        Horses* NewHorses = new Horses;
        NewHorses->name = NewName;
        NewHorses->years = Newyears;
        NewHorses->distance = Newdistance;
        NewHorses->next = Head;
        Head = NewHorses;
        return;
    }

    //Добавление в конец
    void AddLast(Horses* Head, string NewName, int Newyears, double Newdistance)
    {
        Horses *tmp = Head;
        if (Head == NULL)
        {
            Addbegin(Head, NewName, Newyears, Newdistance);
            return;
        }

        while (tmp->next)       //поиск полседнего узла
            tmp = tmp->next;
        
        Horses* NewHorses = new Horses;
        NewHorses->name = NewName;
        NewHorses->years = Newyears;
        NewHorses->distance = Newdistance;
        NewHorses->next = NULL;
        tmp->next = NewHorses;
        return;

        
    }

    //добавление лошадки после заданной
    int AddAfter(Horses *Head, string NewName, int Newyears, double Newdistance, string NameAfter)
    {
        if (Head == NULL)
            return 1;

        Horses* tmp = Head;
        while (tmp != NULL && tmp->name != NameAfter) {
            tmp = tmp->next;
        }
        if (tmp == NULL)return 1;
        Horses* NewHorses = new Horses;
        NewHorses->name = NewName;
        NewHorses->years = Newyears;
        NewHorses->distance = Newdistance;
        tmp->next = NewHorses;
        return 0;
    }

    int AddBefore(Horses*& Head, string NewName, int Newyears, double Newdistance, string NameBefore)
    {
        if (Head == NULL)
            return 1;
        if (Head->name == NameBefore)
        {
            Addbegin(Head, NewName, Newyears, Newdistance);
            return 0;
        }
        if (Head->next == NULL)
            return 1;
        Horses* prev = Head, * tmp = Head->next;
        while (tmp->next != NULL && tmp->name != NameBefore)
        {
            prev = prev->next; tmp = tmp->next;
        }
        if (tmp->next == NULL && tmp->name != NameBefore)
            return 1;
        Horses* NewHorses = new Horses;
        NewHorses->name = NewName;
        NewHorses->years = Newyears;
        NewHorses->distance = Newdistance;
        prev->next = NewHorses;
        return 0;
    }

    int DelHorses(Horses*& Head, string DelName)
    {
        if (Head == NULL)
            return 1;
        Horses* tmp = Head;
        if (Head->name == DelName)
        {
            Head = Head->next; delete tmp; return 0;
        }
        if (Head->next == NULL)return 1;
        Horses* prev = Head; tmp = Head->next;
        while (tmp->next != NULL && tmp->name != DelName)
        {
            prev = prev->next; tmp = tmp->next;
        }
        if (tmp->next == NULL && tmp->name != DelName)
            return 1;
        prev->next = tmp->next;
        delete tmp;
        return 0;
    }

    void PrintList(Horses* Head)
    {
        if (Head == NULL)
        {
            cout << "The list is empty"; return;
        }
        Horses* tmp = Head;
        while (tmp != NULL)
        {
            cout << "Horses : " << tmp->name <<
                "\nYears: " << tmp->years << endl;
                 cout << "Distance: " << tmp->distance;
                 cout << endl << endl;
            tmp = tmp->next;
        }
        return;
    }
};

int main() {

    Horses* Chaval = new Horses();
    Chaval->Addbegin(Chaval, "Kavalergard", 8, 66.6);
    Chaval->AddAfter(Chaval, "l", 12, 98.1, "Kavalergard");
    Chaval->AddAfter(Chaval, "A", 6, 55.5, "Kristal");
    //Chaval->Addbegin(Chaval, "Aff", 6, 55.5);
    Chaval->PrintList(Chaval);
    return 0;
}
