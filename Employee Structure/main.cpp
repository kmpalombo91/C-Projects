#include <iostream>
#include <fstream>
#include <cctype>
#include <windows.h>
#include <cstring>
#include <string>
#include <cstdlib>
#include <limits>

using namespace std;
#include "person.h"
#include "structures.h"

//<editor-fold>

void printEmployee(Employee e) {
    cout << e.toString() << endl;
}

void printEmployee(Employee * e) {
    cout << e->toString() << endl;
}
//</editor-fold>

void loadArrayOfStructurePointers(Employee* ar[], int size) {
    int id;
    char name[80];
    int zip;
    char street[80];
    char city[80];
    char state[80];
    for (int i = 0; i < size; i++) {
        cout << "Enter id: ";
        cin >> id;
        cin.ignore();
        cout << "\nEnter name: ";
        cin.getline(name, 80);
        cout << "\nEnter zip: ";
        cin >> zip;
        cin.ignore();
        cout << "\nEnter street: ";
        cin.getline(street, 80);
        cout << "\nEnter city: ";
        cin.getline(city, 80);
        cout << "\nEnter state: ";
        cin.getline(state, 80);
        ar[i] = new Employee(id, name, zip, street, city, state);
    }
}

void loadArrayOfStructures(Employee ar[], int size) {
    int id;
    char name[80];
    int zip;
    char street[80];
    char city[80];
    char state[80];
    for (int i = 0; i < size; i++) {
        cout << "Enter id: ";
        cin >> id;
        cin.ignore();
        cout << "\nEnter name: ";
        cin.getline(name, 80);
        cout << "\nEnter zip: ";
        cin >> zip;
        cin.ignore();
        cout << "\nEnter street: ";
        cin.getline(street, 80);
        cout << "\nEnter city: ";
        cin.getline(city, 80);
        cout << "\nEnter state: ";
        cin.getline(state, 80);
        ar[i] = *(new Employee(id, name, zip, street, city, state));
    }
}

void printArray(Employee* ar[], int size) {
    for (int i = 0; i < size; i++) {
        cout << ar[i]->toString() << endl;
    }
    cout << endl;
}

void printArray(Employee ar[], int size) {
    for (int i = 0; i < size; i++) {
        cout << ar[i].toString() << endl;
    }
    cout << endl;
}

void binaryFile(fstream& file, string name, Employee* employees[], Employee* dup[], int SIZE) {
    file.open(name, ios::out | ios::binary);
    for (int i = 0; i < SIZE; i++) {
        file.write(reinterpret_cast<const char *> (&(employees[i]->id)), sizeof (employees[i]->id));
        file.write(reinterpret_cast<const char *> (&(employees[i]->name)), sizeof (employees[i]->name));
        file.write(reinterpret_cast<const char *> (&(employees[i]->pAddress->pCity)), sizeof (employees[i]->pAddress->pCity));
        file.write(reinterpret_cast<const char *> (&(employees[i]->pAddress->zip)), sizeof (employees[i]->pAddress->zip));
        file.write(reinterpret_cast<const char *> (&(employees[i]->pAddress->street)), sizeof (employees[i]->pAddress->street));
        file.write(reinterpret_cast<const char *> (&(employees[i]->pAddress->state)), sizeof (employees[i]->pAddress->state));
    }
    cout << "Data written to file.\n";
    file.close();
    file.open(name, ios::in | ios::binary);
    for (int i = 0; i < SIZE; i++) {
        dup[i] = new Employee();
        cout << "Employee " << (i + 1) << " ---" << endl;
        file.read((reinterpret_cast<char *> (&(dup[i]->id))), sizeof(dup[i]->id));
        cout << "The id is: " << dup[i]->id << endl;
        file.read((reinterpret_cast<char *>(&(dup[i]->name))), sizeof(dup[i]->name));
        cout << "The name is: " << dup[i]->name << endl;
        dup[i]->pAddress = new Address();
        dup[i]->pAddress->pCity = new char[80];
        file.read((reinterpret_cast<char *> (&(dup[i]->pAddress->pCity))), sizeof(dup[i]->pAddress->pCity));
        cout << "The city is: " << dup[i]->pAddress->pCity << endl;
        file.read((reinterpret_cast<char *> (&(dup[i]->pAddress->zip))), sizeof(dup[i]->pAddress->zip));
        cout << "The zip is: " << dup[i]->pAddress->zip << endl;
        file.read((reinterpret_cast<char *> (&(dup[i]->pAddress->street))), sizeof(dup[i]->pAddress->street));
        cout << "The street is: " << dup[i]->pAddress->street << endl;
        file.read((reinterpret_cast<char *> (&(dup[i]->pAddress->state))), sizeof(dup[i]->pAddress->state));
        cout << "The state is: " << dup[i]->pAddress->state << endl; 
    }
    file.close();
}

int main() {
    fstream file;
    Employee * ar[2];
    ar[0] = new Employee(123456789, "mary poppins the great", 77777, "123 main street", "lafayette", "LA");
    ar[1] = new Employee(2, "john wayne", 77777, "444 hill road", "new orleans", "LA");
    Employee * dup[2];
    binaryFile(file, "testBinary.dat", ar, dup, 2);
    return 0;

}

int main2() {
    /*Employee e1;
    Employee *pE1 = new Employee();
    pE1->id = 2;
    pE1->name = "Mary Poppins";
    pE1->pAddress = new Address();
    pE1->pAddress->pCity = new char[80];
    std::strcpy(pE1->pAddress->pCity, "New Orleans");
    pE1->pAddress->state = "LA";
    pE1->pAddress->zip = 80101;
    e1.id = 1;
    e1.name = "James Woods";
    e1.pAddress = new Address();
    (*e1.pAddress).pCity = new char[80];
    std::strcpy(e1.pAddress->pCity,"Lafayette");
    //strcpy(e1.pAddress->pCity, "Lafayette"); // same as above;
    (* e1.pAddress).state = "LA";
    (* e1.pAddress).zip = 70504;
    printEmployee(e1);
    printEmployee(&e1);
    printEmployee(pE1);
     */
    //<editor-fold>
    /*Employee * ar[1];
    loadArrayOfStructurePointers(ar, 1);
    printArray(ar, 1);
    for (int i = 0; i < 1; i++) {
        delete ar[i];
    }
    loadArrayOfStructures(*ar, 1);
    printArray(ar, 1);*/
    //</editor-fold>
    /*Person * people[2];
    people[0] = new Person("Sally Smith", 19);
    people[1] = new Person("Billy Bob", 45);
    people[2] = new Person("Joe Black", 22);
    Person person;
    person.pName = people[0]->pName;
    person.age = people[0]->age;
    cout << "People array created: " << endl;
    person.printPersons(people, 3);
    cout << "CompareTo Test: " << endl;
    cout << person.pName << " <, >, = " << people[1]->pName << "? (-1, 1, 0): ";
    cout << person.compareTo(people[1]) << endl;
    person.sortPersons(people, 3);
    cout << "\nPeople array sorted: " << endl;
    person.printPersons(people, 3);
    for (int i = 0; i < 3; i++) {
        delete people[i];
    }*/
    return 0;
}