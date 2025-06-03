#include<iostream>
using namespace std;


// Abstract class for walkable robot
class Walkable {
public:
	virtual void walk() = 0;
	virtual ~Walkable() {};
};

class Normalwalk :public Walkable {
public:
	void walk() {
		cout << "Robot can Walk!!" << endl;
	}
};

class Nowalk :public Walkable {
public:
	void walk() {
		cout << "Robot can not Walk!!" << endl;
	}
};


// Abstract class for talkable robot
class Talkable {
public:
	virtual void talk() = 0;
	virtual ~Talkable() {};
};

class Normaltalk :public Talkable {
public:
	void talk() {
		cout << "Robot can talk!!" << endl;
	}
};

class Notalk :public Talkable {
public:
	void talk() {
		cout << "Robot can not talk!!" << endl;
	}
};

// Abstract class for flyable robot
class Flyable {
public:
	virtual void fly() = 0;
	virtual ~Flyable() {};
};

class Normalfly :public Flyable {
public:
	void fly() {
		cout << "Robot can fly!!" << endl;
	}
}; 

class Nofly :public Flyable {
public:
	void fly() {
		cout << "Robot can not fly!!"<<endl;
	}
};


//Robot Base class
class Robot {
private:
	Walkable* walkbehaviour;
	Talkable* talkbehaviour;
	Flyable* flybehaviour;

public:
	Robot(Walkable* w, Talkable* t, Flyable* f) {
		this->walkbehaviour = w;
		this->talkbehaviour = t;
		this->flybehaviour = f;
	}

	void walk() {
		walkbehaviour->walk();
	}
	void talk() {
		talkbehaviour->talk();
	}
	void fly() {
		flybehaviour->fly();
	}
};

int main() {
	Robot* robot = new Robot(new Normalwalk(), new Normaltalk(), new Normalfly());
	cout << "Normal Behaviour" << endl;
	robot->walk();
	robot->talk();
	robot->fly();

	cout << "*************" << endl;
	Robot* robot2 = new Robot(new Nowalk(), new Notalk(), new Nofly());
	cout << "Changed Behaviour" << endl;
	robot2->walk();
	robot2->talk();
	robot2->fly();

	return 0;
}