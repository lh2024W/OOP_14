// OOP_14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>
using namespace std;

class AnimalWorld {
    
    AnimalWorld* animal = nullptr;
    
public:
    void SetAnimal(AnimalWorld* animal_world) {
        animal = animal_world;
    }
    AnimalWorld* GetAnimal() const {
        return animal;
    }

    virtual void EatGrass() {};
    virtual void EatHerbivores() {};

    virtual void MealsHerbivores() {/*//не работает
        for (auto current : animals)
            current->animal;*/
    };
    virtual void NutritionCarnivores() {};
};

class Animal: public AnimalWorld {

};

//////////////////////////////////////

class Herbivores : public Animal {
protected:
    virtual void EatGrass() {};
};


class Carnivores : public Animal {
protected:
    virtual void EatHerbivores () {};
};

///////////////////////////////////////////

class Continent {};

///////////////////////////////////////////

class Africa : public Continent {
public:
    Lion* lion;
    Wildebeest* wildebeest;
 };

class NorthAmerica : public Continent {
public:
    Bison* bison;
    Wolf* wolf;
};

/////////////////// Africa ///////////////////////

class Wildebeest : public Herbivores {
public:
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

    bool Life() const {
        if (weight != 0) return true;
    };
};

class Lion : public Carnivores {
public:
    int power = 10;

    Lion() : Lion(25) {};
    //главный к-тор
    Lion(int power) {
        power = power;
    };

    ~Lion() {};

    void EatHerbivores(Wildebeest* w) {
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

class Bison : public Herbivores {
public:
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
    bool Life() const {
        if (weight != 0) return true;
    };
};

class Wolf : public Carnivores {
public:
    int power = 10;

    Wolf() : Wolf(20) {};
    //главный к-тор
    Wolf(int power) {
        power = power;
    };

    ~Wolf() {};

    void EatHerbivores(Bison* b) {
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
    AnimalWorld animal;
    
    Bison bison(10);
    animal.SetAnimal(&bison);
    animal.GetAnimal()->EatGrass();

    Wildebeest w(20);
    animal.SetAnimal(&w);
    animal.GetAnimal()->EatGrass();

    Lion lion(15);
    animal.SetAnimal(&lion);
    animal.GetAnimal()->EatHerbivores();

    Wolf wolf(20);
    animal.SetAnimal(&wolf);
    animal.GetAnimal()->EatHerbivores();

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
