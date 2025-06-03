#include<iostream>
using namespace std;


// Abstract class    ....
class Burger {
public:
	virtual void prepare() = 0;
	virtual ~Burger() = default;
};

class GarlicBread {
public:
	virtual void prepare() = 0;
	virtual ~GarlicBread() {};
};


class BasicGarlicBread : public GarlicBread {
public:
	void prepare() {
		cout << "The Basic GarlicBread is ready!!!! " << endl;
	}
};

class StandardGarlicBread :public GarlicBread {
public:
	void prepare() {
		cout << "The standard GarlicBread is ready!!! " << endl;
	}
};

class PremiumGarlicBread :public GarlicBread {
public:
	void prepare() {
		cout << "The Premium GarlicBread is ready!!! " << endl;
	}
};

class BasicWheatGarlicBread : public GarlicBread {
public:
	void prepare() {
		cout << "The Basic Wheat GarlicBread is ready!!!! " << endl;
	}
};

class StandardWheatGarlicBread :public GarlicBread {
public:
	void prepare() {
		cout << "The standard Wheat GarlicBread is ready!!! " << endl;
	}
};

class PremiumWheatGarlicBread :public GarlicBread {
public:
	void prepare() {
		cout << "The Premium Wheat GarlicBread is ready!!! " << endl;
	}
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
	virtual GarlicBread* createGarlicBread(string& type) = 0;

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

	GarlicBread* createGarlicBread(string& type) {
		if (type == "Basic1")
			return new BasicGarlicBread();
		else if (type == "Standard1")
			return new StandardGarlicBread();
		else if (type == "Premium1")
			return new PremiumGarlicBread();
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

	GarlicBread* createGarlicBread(string& type) {
		if (type == "Basic Wheat")
			return new BasicWheatGarlicBread();
		else if (type == "Standard Wheat")
			return new StandardWheatGarlicBread();
		else if (type == "Premium Wheat")
			return new PremiumWheatGarlicBread();
		else {
			cout << "Not Valid!!";
			return nullptr;
		}

	}
};

int main4() {

	string type = "Standard Wheat";
	string type1 = "Premium Wheat";

	BurgerFactory* factory = new KingBurger();
	Burger* burger1 = factory->createburger(type);
	GarlicBread* Garlic = factory->createGarlicBread(type1);

	burger1->prepare();
	Garlic->prepare();

	return 0;
}




