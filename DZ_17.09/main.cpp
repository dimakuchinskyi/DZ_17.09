#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string _name;
    int _age;
public:
    Person() {
        _name = "";
        _age = 0;
    }

    Person(string name) : Person()
    {
        SetName(name);
    }
    Person(string name, int age) : Person(name)
    {
        SetAge(age);
    }

    void SetName(string name) {
        _name = name;
    }
    void SetAge(int age) {
        _age = age;
    }

    void Print() {
        cout << "Name: " << _name << endl;
        cout << "Age: " << _age << endl;
    }

    ~Person() {
        _name = "";
        _age = 0;
    }
};

class Apartment {
private:
    Person* _people = nullptr;
    int _countPeople;
    int _numApartment;
public:
    Apartment() {
        _numApartment = 0;
        _countPeople = 0;
        _people = new Person[_countPeople+1];
    }
    Apartment(int numApartment) : Apartment()
    {
       _numApartment = numApartment;
    }
    Apartment(int numApartment, int countPeople) : Apartment(numApartment)
    {
        _countPeople = countPeople;
        _people = new Person[_countPeople];
    }

    void AddPerson(Person person)
    {
        Person* temp = new Person[_countPeople + 1];
        for (size_t i = 0; i < _countPeople; i++)
        {
            temp[i] = _people[i];
        }
        temp[_countPeople] = person;
        delete[] _people;
        _people = temp;
        _countPeople++;
        //cout << "Person added: ";
        //cout << endl;
    }

    void PrintApartment()
    {
        cout << "Apartment: " << _numApartment << endl;
        if (_people != nullptr)
        {
            for (size_t i = 0; i < _countPeople; i++)
            {
                _people[i].Print();
            }
        }
    }

    ~Apartment() {
        delete[] _people;
    }
};

class Home
{
private:
    Apartment* _apartments = nullptr;
    int _countApartments;
    int _numHome;
public:
    Home() 
    {
        _numHome = 0;
        _countApartments = 0;
        _apartments = new Apartment[_countApartments + 1];
    }
    Home(int numHome) : Home()
    {
        _numHome = numHome;
    }
    Home(int numHome, int countApartments) : Home(numHome)
    {
        _countApartments = countApartments;
    }

    void AddApartment(Apartment apartment)
    {
        Apartment* temp = new Apartment[_countApartments + 1];
        for (size_t i = 0; i < _countApartments; i++)
        {
            temp[i] = _apartments[i];
        }
        temp[_countApartments] = apartment;
        delete[] _apartments;
        _apartments = temp;
        _countApartments++;
        //cout << "Apartment added: ";
        //cout << endl;
    }

    void PrintHome()
    {
        cout << "Home: " << _numHome << endl;
        if (_apartments != nullptr)
        {
            for (size_t i = 0; i < _countApartments; i++)
            {
                _apartments[i].PrintApartment();
            }
        }
    }

    ~Home() {
        delete[] _apartments;
    }
};

int main() {
    Person person1("John", 25);
    Person person2("Alice", 30);

    Apartment apartment1(101);
    apartment1.AddPerson(person1);
    apartment1.AddPerson(person2);

    Home home(2);
    home.AddApartment(apartment1);

    home.PrintHome();

    return 0;
}