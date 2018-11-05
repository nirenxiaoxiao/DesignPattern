#pragma once

class Observable;

class Argument{

};

class Observer
{
public:
	virtual void update(Observable* o, Argument* arg) = 0;
	virtual ~Observer()
	{

	}
};