#include<iostream>
using namespace std;


// Abstract class    ....
class Burger {
public:
	virtual void prepare() = 0;
	virtual ~Burger() = default;
};

// Concrete Classes
class BasicBurger : public Burger {
public:
	void prepare() {
		cout << "The Basic burger is ready!!!! " << endl;
	}
};

class StandardBurger :public Burger {
public:
	void prepare() {
		cout << "The standard burger is ready!!! " << endl;
	}
};

class PremiumBurger :public Burger {
public:
	void prepare() {
		cout << "The Premium burger is ready!!! " << endl;
	}
};

// Factory Class
class BurgerFactory {
public:
	Burger* createburger(string& type) {
		if (type == "Basic")
			return new BasicBurger();
		else if (type == "Standard")
			return new StandardBurger();
		else if (type == "Premium")
			return new PremiumBurger();
		else{
			cout << "Not Valid!!";
			return nullptr;
		}

	}
};

int main2() {
	
	string type = "Standard";

	BurgerFactory* factory = new BurgerFactory();
	Burger* burger1 = factory->createburger(type);
	burger1->prepare();

	return 0;
}




