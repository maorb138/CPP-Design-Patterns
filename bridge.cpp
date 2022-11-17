
#include <iostream>

using namespace std;

class HouseImplementor {
public:
    virtual void printImplementation()=0;
};
class WoodHouse : public HouseImplementor {
    void printImplementation() override {
        cout << "wood house" << endl;
    }
};
class BrickHouse : public HouseImplementor {
    void printImplementation() override {
        cout << "brick house" << endl;
    }
};
class House {
protected:
    HouseImplementor* _houseImplementor;
public:
    virtual void print()=0;
};

class BigHouse : public House {
public:
    BigHouse(HouseImplementor* houseImplementor) {
        _houseImplementor = houseImplementor;
    }
    void print() override {
        cout << "big ";
        _houseImplementor->printImplementation();
    }
};
class SmallHouse : public House {
public:
    SmallHouse(HouseImplementor* houseImplementor) {
        _houseImplementor = houseImplementor;
    }
    void print() override {
        cout << "small ";
        _houseImplementor->printImplementation();
    }
};


int main() {
    House* h1 = new BigHouse(new WoodHouse());
    h1->print();
    House* h2 = new SmallHouse(new BrickHouse());
    h2->print();
}
