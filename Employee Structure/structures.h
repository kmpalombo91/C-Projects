#ifndef STRUCTURES_H
#define STRUCTURES_H



struct Address{
    char street[80];
    int zip;
    char* pCity;
    string state;
    
    Address(char street[80], int zip, char* pCity, string state){
        
       strcpy(this->street, street);
       this->zip = zip;
       this->pCity = new char(strlen(pCity) + 1);
       strcpy(this->pCity, pCity);
       this->state = state;
    }
    
    Address(){
        
    }
    ~Address(){
        if(this->pCity != nullptr)
            delete this->pCity;
    }
};

struct Employee{
    string name;
    int id;
    Address* pAddress;
    
    //int zip, char[80] street, char[80] pCity, string state
    Employee(int id, string name,int zip, char street[], char* pCity, string state ){
        this ->id = id;
        this->name = name;
        this->pAddress = new Address(street, zip, pCity, state);
        
    }
    
    Employee(){
        
    }
    ~Employee(){
        if (this->pAddress != nullptr)
            delete this->pAddress;
    }
    
    string toString()
    { return "{Employee: id =" 
            + std::to_string(id)
            + ", name = " + name 
            + ", city = " + pAddress->pCity
            + ", state = " + pAddress->state
            + ", Street= " + pAddress->street
            + ", zip = " + std::to_string(pAddress->zip)
            +"}";
    }
};

void loadArrayOfStructurePointers(Employee* ar[], int size);
void loadArrayOfStructures(Employee [] , int size);

void printArray(Employee*[], int);
void printArray(Employee [], int);


#endif /* STRUCTURES_H */

