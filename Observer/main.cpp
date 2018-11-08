
#include "Observable.h"
#include <string>
#include <iostream>
using std::string;
class Flower
{
	bool isOpen;
public:
	Flower():isOpen(false),
		openNotifier(this), closeNotifier(this)
	{

	}
	void open()
	{
		isOpen = true;
		openNotifier.notifyObservers();
		closeNotifier.open();
	}

	void close()
	{
		isOpen = false;
		closeNotifier.notifyObservers();
		openNotifier.close();
	}
	class OpenNotifier;
	friend class Flower::OpenNotifier;
	class OpenNotifier:public Observable
	{
		Flower* parent;
		bool alreadyOpen;
	public:
		OpenNotifier(Flower* f):parent(f)
		{
			alreadyOpen = false;
		}

		void notifyObservers(Argument* arg = 0)
		{
			if (parent->isOpen && !alreadyOpen)
			{
				setChanged();
				Observable::notifyObservers();
				alreadyOpen = true;
			}
		}

		void close()
		{
			alreadyOpen = false;
		}
	}openNotifier;

	class CloseNotifier;
	friend class Flower::CloseNotifier;
	class CloseNotifier:public Observable
	{
		Flower* parent;
		bool alreadyClose;
	public:
		CloseNotifier(Flower* f):parent(f)
		{
			alreadyClose = false;
		}

		void notifyObservers(Argument* arg = 0)
		{
			if (!parent->isOpen && !alreadyClose)
			{
				setChanged();
				Observable::notifyObservers();
				alreadyClose = true;
			}
		}

		void open()
		{
			alreadyClose = false;
		}
	}closeNotifier;
};

class Bee{
	string name;
	class OpenObserver;
	friend class Bee::OpenObserver;
	class OpenObserver :public Observer
	{
		Bee* parent;
	public:
		OpenObserver(Bee* b):parent(b)
		{

		}

		void update(Observable* subject, Argument* arg)
		{
			std::cout << "Bee " << parent->name << "'s breakfast time!" <<std::endl;
		}
	}openObsrv;

	class CloseObserver;
	friend class Bee::CloseObserver;
	class CloseObserver :public Observer
	{
		Bee* parent;
	public:
		CloseObserver(Bee* b):parent(b)
		{

		}

		void update(Observable* subject, Argument* arg)
		{
			std::cout << "Bee " << parent->name << "'s bed time!" <<std::endl;
		}
	}closeObsrv;

public:
	Bee(string nm):name(nm), openObsrv(this), closeObsrv(this)
	{

	}

	Observer& openObserver()
	{
		return openObsrv;
	}

	Observer& closeObserver()
	{
		return closeObsrv;
	}
};



class HummingBird{
	string name;
	class OpenObserver;
	friend class HummingBird::OpenObserver;
	class OpenObserver :public Observer
	{
		HummingBird* parent;
	public:
		OpenObserver(HummingBird* b):parent(b)
		{

		}

		void update(Observable* subject, Argument* arg)
		{
			std::cout << "HummingBird " << parent->name << "'s breakfast time!" <<std::endl;
		}
	}openObsrv;

	class CloseObserver;
	friend class HummingBird::CloseObserver;
	class CloseObserver :public Observer
	{
		HummingBird* parent;
	public:
		CloseObserver(HummingBird* b):parent(b)
		{

		}

		void update(Observable* subject, Argument* arg)
		{
			std::cout << "HummingBird " << parent->name << "'s bed time!" <<std::endl;
		}
	}closeObsrv;

public:
	HummingBird(string nm):name(nm), openObsrv(this), closeObsrv(this)
	{

	}

	Observer& openObserver()
	{
		return openObsrv;
	}

	Observer& closeObserver()
	{
		return closeObsrv;
	}
};
int main()
{
	Flower f;
	Bee ba("A"), bb("B");

	HummingBird ha("A"), hb("B");

	f.openNotifier.addObserver(ha.openObserver());
	f.openNotifier.addObserver(hb.openObserver());
	f.openNotifier.addObserver(ba.openObserver());
	f.openNotifier.addObserver(bb.openObserver());

	f.closeNotifier.addObserver(ha.closeObserver());
	f.closeNotifier.addObserver(hb.closeObserver());
	f.closeNotifier.addObserver(ba.closeObserver());
	f.closeNotifier.addObserver(bb.closeObserver());

	f.openNotifier.deleteObserver(hb.openObserver());

	f.open();

	f.open();

	f.closeNotifier.deleteObserver(ba.closeObserver());

	f.close();
	f.close();

	f.openNotifier.deleteObservers();
	f.open();

	f.close();
	return 0;
}