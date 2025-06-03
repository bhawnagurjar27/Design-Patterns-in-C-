#include<iostream>
#include<vector>
using namespace std;


//Iobserver Interface
class Isubscriber {
public:
	virtual void update(const string& s) = 0;
	virtual ~Isubscriber() {};
};


//IObservable Interface
class IChannel {
public:
	virtual void subscribe(Isubscriber* obj) = 0;
	virtual void unsubscribe(Isubscriber* obj) = 0;
	virtual void notifysubscribers(const string& msg) = 0;
	virtual ~IChannel() {};
};

//Concrete Ichannel a YouTube channel that observers can subscribe to
class Channel : public IChannel {
	vector<Isubscriber*>subscribers;
public:
	void subscribe(Isubscriber* c) override {
		subscribers.push_back(c);
	}

	void unsubscribe(Isubscriber* subscriber) override{
		auto it = find(subscribers.begin(), subscribers.end(), subscriber);
		if (it != subscribers.end()) {
			subscribers.erase(it);
		}
	}

	void notifysubscribers(const string& obs)override {
		for (auto it : subscribers) {
			it->update(obs);
		}
	}

	void uploadvedio( const string& title) {
		cout << "Channel: Uploaded new video: " << title << endl;
		notifysubscribers(title);
	}
};

class Subscriber :public Isubscriber {
	string name;
public:
	Subscriber(string name) :name(name) {}

	void update(const string& videoTitle) override {
		cout << name << " got notified: New video uploaded - " << videoTitle << endl;
	}
};

int main7() {

	Channel channel1;

	Subscriber s1("Alice");
	Subscriber s2("BOB");

	channel1.subscribe(&s1);
	channel1.subscribe(&s2);

	channel1.uploadvedio("C++ Course");

	channel1.unsubscribe(&s1);
	channel1.uploadvedio("Design Patterns Crash Course");

	return 0;
}