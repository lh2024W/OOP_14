// OOP_14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
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

    virtual void MealsHerbivores() {};
    virtual void NutritionCarnivores() {};
};

//////////////////////////////////////

class Herbivores : public AnimalWorld {
protected:
    virtual void MealsHerbivores() {};
};


class Carnivores : public AnimalWorld {
protected:
    virtual void NutritionCarnivores() {};
};

///////////////////////////////////////////

class Continent {};

///////////////////////////////////////////

class Africa : public Continent {};

class Lion : public Carnivores, Africa {
    int power;

    Lion() : Lion(25) {};
    //главный к-тор
    Lion(int power) {
        power=power;
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

class Wildebeest : public Herbivores, NorthAmerica {
public:
    int weight;

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

/////////////////////////////////////////////////

class NorthAmerica : public Continent {};

class Wolf : public Carnivores, NorthAmerica {
    int power;

    Wolf(): Wolf (20) {};
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

class Bison : public Herbivores, Africa {
public:
    int weight;

    Bison() : Bison (10) {};
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

int main()
{
    AnimalWorld animal;
    Bison bison(10);
    Wildebeest w(20);
   // Lion lion(25); // не работает
   // Wolf wolf(30);// не работает
    animal.SetAnimal(&bison);
    animal.SetAnimal(&w);
   // animal.SetAnimal(&lion);// не работает
   // animal.SetAnimal(&wolf);// не работает
    animal.GetAnimal();
    //animal.GetAnimal() -> MealsHerbivores();// не работает
   
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
