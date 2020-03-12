#ifndef PERSON_H
#define PERSON_H

struct Person {
    char * pName;
    int age;

    Person() {
    }

    Person(char *pName, int age) {
        this->pName = new char[strlen(pName) + 1];
        std::strcpy(this->pName, pName);
        this->age = age;
    }

    ~Person() {
        if (this->pName != nullptr) {
            delete this->pName;
        }
    }

    string toString() {
        string s = "";
        s += "{ name=";
        s += pName;
        s += " age=";
        s += std::to_string(age);
        s += " }";
        return s;
    }
    // compares names

    int compareTo(Person* pPerson) {
        if (this->pName > pPerson->pName) {
            return 1;
        } else if (this->pName < pPerson->pName) {
            return -1;
        }
        return 0;
    };

    void sortPersons(Person* persons[], int size) {
        Person* temp = new Person(persons[0]->pName, persons[0]->age);
        for (int i = 0, j = (i + 1); i < size; i++) {
            if (temp->compareTo(persons[i]) > 0) {
                temp = new Person(persons[i]->pName, persons[i]->age);
                persons[i] = persons[j];
                persons[j] = temp;
            }
        }
    };

    void printPersons(Person* persons[], int size) {
        for (int i = 0; i < size; i++) {
            cout << persons[i]->toString() << endl;
        }
        cout << endl;
    }
};


#endif /* PERSON_H */

