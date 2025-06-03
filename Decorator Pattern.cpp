#include <iostream>
using namespace std;

// Component Interface
class Coffee {
public:
    virtual string getDescription() = 0;
    virtual int cost() = 0;
    virtual ~Coffee() = default;
};

// Concrete Component
class SimpleCoffee : public Coffee {
public:
    string getDescription() override {
        return "Simple Coffee";
    }
    int cost() override {
        return 100;
    }
};

// Base Decorator
class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;
public:
    CoffeeDecorator(Coffee* c) : coffee(c) {}
};

// Concrete Decorators
class Milk : public CoffeeDecorator {
public:
    Milk(Coffee* c) : CoffeeDecorator(c) {}
    string getDescription() override {
        return coffee->getDescription() + ", Milk";
    }
    int cost() override {
        return coffee->cost() + 20;
    }
};

class Chocolate : public CoffeeDecorator {
public:
    Chocolate(Coffee* c) : CoffeeDecorator(c) {}
    string getDescription() override {
        return coffee->getDescription() + ", Chocolate";
    }
    int cost() override {
        return coffee->cost() + 30;
    }
};

// Client
int main6() {
    Coffee* coffee = new SimpleCoffee();              // Simple Coffee: ?100
    coffee = new Milk(coffee);                        // Add Milk: ?120
    coffee = new Chocolate(coffee);                   // Add Chocolate: ?150

    cout << "Order: " << coffee->getDescription() << endl;
    cout << "Total Cost: ?" << coffee->cost() << endl;

    delete coffee;  // Cleanup
    return 0;
}
