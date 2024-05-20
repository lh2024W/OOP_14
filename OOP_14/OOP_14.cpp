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
    Lion* lion = nullptr;
    Wildebeest* wildebeest = nullptr;
 };

class NorthAmerica : public Continent {
    Bison* bison = nullptr;
    Wolf* wolf = nullptr;
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
