// OOP_14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

class AnimalWorld {
private:
    vector<Continent*> continents;
    vector<Herbivore*> herbivores;
    vector<Carnivore*> carnivores;

public:
    ~AnimalWorld() {
        cout << "Animal World destroyed\n";
        for (auto continent : continents) {
            delete continent;
        }
        for (auto herbivore : herbivores) {
            delete herbivore;
        }
        for (auto carnivore : carnivores) {
            delete carnivore;
        }
    }

    void AddContinent(Continent* continent) {
        continents.push_back(continent);
    }

    void PopulateWorld() {
        for (auto continent : continents) {
            continent->Populate(herbivores, carnivores);
        }
    }

    void MealsHerbivores() {
        cout << "Herbivores eat grass...\n";
        for (auto herbivore : herbivores) {
            if (herbivore->IsAlive()) {
                herbivore->EatGrass();
            }
        }
    }

    void NutritionCarnivores() {
        cout << "Harnivores hunting on herbivores...\n";
        for (auto carnivore : carnivores) {
            for (auto herbivore : herbivores) {
                if (herbivore->IsAlive()) {
                    carnivore->Eat(herbivore);
                }
            }
        }
    }
};

//////////////////////////////////////

class Herbivore : public AnimalWorld {
public:
    virtual bool IsAlive() {};
    virtual void EatGrass() {};
};


class Carnivore : public AnimalWorld {
public:
    virtual void Eat(Herbivore* herbivore) {};
};

///////////////////////////////////////////

class Continent {
public:
    virtual void Populate(Herbivore* herbivores, Carnivore* carnivores){}; // НЕ ПРАВИЛЬНО
};

///////////////////////////////////////////

class Africa : public Continent {};

class NorthAmerica : public Continent {};

/////////////////// Africa ///////////////////////

class Wildebeest : public Herbivore {
public:
    Africa* Africa;
    int weight = 10;

    Wildebeest() : Wildebeest(15) {};
    //главный к-тор
    Wildebeest(int weight) {
        weight = weight;
    };

    ~Wildebeest() {};

    void EatGrass() {
        weight = weight + 10;
        cout << "Wildebeest eat\n";
    };

    bool IsAlive() const {
        if (weight != 0) return true;
    };
};

class Lion : public Carnivore {
public:
    Africa* Africa;
    int power = 10;

    Lion() : Lion(25) {};
    //главный к-тор
    Lion(int power) {
        power = power;
    };

    ~Lion() {};

    void Eat(Wildebeest* w) {
        if (power > w->weight) {
            power = power + 10;
            cout << "Lion eat\n";
        }
        else {
            power = power - 10;
            cout << "Lion do not eat\n";
        }
    };
};


/////////////////////North America////////////////////////////

class Bison : public Herbivore {
public:
    NorthAmerica* NorthAmerica;
    int weight=10;

    Bison() : Bison(10) {};
    //главный к-тор
    Bison(int weight) {
        weight = weight;
    };

    ~Bison() {};

    void EatGrass() {
        weight = weight + 10;
        cout << "Bison eat\n";
    };
    bool IsAlive() const {
        if (weight != 0) return true;
    };
};

class Wolf : public Carnivore {
public:
    NorthAmerica* NorthAmerica;
    int power = 10;

    Wolf() : Wolf(20) {};
    //главный к-тор
    Wolf(int power) {
        power = power;
    };

    ~Wolf() {};

    void Eat(Bison* b) {
        if (power > b->weight) {
            power = power + 10;
            cout << "Wolf eat\n";
        }
        else {
            power = power - 10;
            cout << "Wolf do not eat\n";
        }
    };
};



int main()
{    
    Bison bison(10);
    Wildebeest w(20);
    Lion lion(15);
    Wolf wolf(20);
    

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
