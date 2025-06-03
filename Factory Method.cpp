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

class BasicWheatBurger : public Burger {
public:
	void prepare() {
		cout << "The Basic Wheat burger is ready!!!! " << endl;
	}
};

class StandardWheatBurger :public Burger {
public:
	void prepare() {
		cout << "The standard Wheat burger is ready!!! " << endl;
	}
};

class PremiumWheatBurger :public Burger {
public:
	void prepare() {
		cout << "The Premium Wheat burger is ready!!! " << endl;
	}
};


// Factory Class + Abstract class
class BurgerFactory {
public:
	virtual Burger* createburger(string& type) = 0;
	
};

//Normal Burger
class SinghBurger :public BurgerFactory {
public:
	Burger* createburger(string& type) {
		if (type == "Basic")
			return new BasicBurger();
		else if (type == "Standard")
			return new StandardBurger();
		else if (type == "Premium")
			return new PremiumBurger();
		else {
			cout << "Not Valid!!";
			return nullptr;
		}

	}
};

class KingBurger :public BurgerFactory {
public:
	Burger* createburger(string& type) {
		if (type == "Basic Wheat")
			return new BasicWheatBurger();
		else if (type == "Standard Wheat")
			return new StandardWheatBurger();
		else if (type == "Premium Wheat ")
			return new PremiumWheatBurger();
		else {
			cout << "Not Valid!!";
			return nullptr;
		}

	}
};

int main3() {

	string type = "Standard Wheat";

	BurgerFactory* factory = new KingBurger();
	Burger* burger1 = factory->createburger(type);
	burger1->prepare();

	return 0;
}




