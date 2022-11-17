
#include <iostream>
#include <cstring>

using namespace std;

class Shake {
public:
    virtual int getPrice()=0;
    virtual string getDescription()=0;
};

class BigShake : public Shake {
    int getPrice() {
        return 13;
    }
    string getDescription() {
        return "Big Shake";
    }
};

class SmallShake : public Shake {
    int getPrice() {
        return 6;
    }
    string getDescription() {
        return "Small Shake";
    }
};

class ShakeDecorator : public Shake {
protected:
    Shake* _shake;
public:
    virtual int getPrice()=0;
    virtual string getDescription()=0;
};

class Oreo : public ShakeDecorator {
public:
    Oreo(Shake* shake) {
        _shake = shake;
    }
    int getPrice() {
        return _shake->getPrice() + 3;
    }
    string getDescription() {
        return _shake->getDescription() + ", Oreo";
    }
};

class Caramel : public ShakeDecorator {
public:
    Caramel(Shake* shake) {
        _shake = shake;
    }
    int getPrice() {
        return _shake->getPrice() + 5;
    }
    string getDescription() {
        return _shake->getDescription() + ", Caramel";
    }
};

class Strawberry : public ShakeDecorator {
public:
    Strawberry(Shake* shake) {
        _shake = shake;
    }
    int getPrice() {
        return _shake->getPrice() + 1;
    }
    string getDescription() {
        return _shake->getDescription() + ", Strawberry";
    }
};

int main() {
    Shake* shake1 = new Strawberry(new Oreo(new BigShake()));
    cout << "shake1=" << shake1->getDescription() << endl;
    cout << "cost: " << shake1->getPrice() << endl;
    Shake* shake2 = new Caramel(new SmallShake());
    cout << "shake2=" << shake2->getDescription() << endl;
    cout << "cost: " << shake2->getPrice() << endl;
}
