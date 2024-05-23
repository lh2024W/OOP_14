// OOP_14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

class Animal {};

class Herbivore : public Animal {
public:
    virtual bool IsAlive() { return true; };
    virtual void EatGrass() {};
};

class Carnivore : public Animal {
public:
    virtual void Eat(Herbivore* herbivore) {};
};

class Continent {
public:
    virtual void Populate(vector<Herbivore*> herbivores, vector<Carnivore*> carnivores) {};
};

class AnimalWorld {
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

class Africa : public Continent {};

class NorthAmerica : public Continent {};

class Wildebeest : public Herbivore {
public:
    Africa* Africa;
    int weight = 10;

    Wildebeest() : Wildebeest(25) {};

    Wildebeest(int weight) {
        weight = weight;
    };

    ~Wildebeest() {};

    void EatGrass() {
        weight = weight + 10;
        cout << "Wildebeest eat. Her weight: " << weight << "\n";
    };

    bool IsAlive() const {
        if (weight != 0) return true;
    };
};

class Lion : public Carnivore {
public:
    Africa* Africa;
    int power = 40;

    Lion() : Lion(45) {};
    //главный к-тор
    Lion(int power) {
        power = power;
    };

    ~Lion() {};

    void Eat(Wildebeest* w) {
        if (power > w->weight) {
            power = power + 10;
            cout << "Lion eat. His power: " << power << "\n";
        }
        else {
            power = power - 10;
            cout << "Lion do not eat wildebeest. His power: " << power << "\n";
        }
    };
};

class Bison : public Herbivore {
public:
    NorthAmerica* NorthAmerica;
    int weight=30;

    Bison() : Bison(40) {};
    //главный к-тор
    Bison(int weight) {
        weight = weight;
    };

    ~Bison() {};

    void EatGrass() {
        weight = weight + 10;
        cout << "Bison eat. His weight: " << weight << "\n";
    };
    bool IsAlive() const {
        if (weight != 0) return true;
    };
};

class Wolf : public Carnivore {
public:
    NorthAmerica* NorthAmerica;
    int power=35;

    Wolf() : Wolf(50) {};
    //главный к-тор
    Wolf(int power) {
        power = power;
    };

    ~Wolf() {};

    void Eat(Bison* b) {
        if (power > b->weight) {
            power = power + 10;
            cout << "Wolf eat. His power: " << power << "\n";
        }
        else {
            power = power - 10;
            cout << "Wolf do not eat bison. His power: " << power << "\n";
        }
    };
};

int main()
{
    Bison bison(40);
    bison.EatGrass();
    Wildebeest w(30);
    w.EatGrass();
    Lion lion(30);
    lion.Eat(&w);
    Wolf wolf(20);
    wolf.Eat(&bison);

    
    AnimalWorld a;

    a.MealsHerbivores();
 
    a.NutritionCarnivores();
   
    
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
