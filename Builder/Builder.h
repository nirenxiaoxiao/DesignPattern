#pragma once
#include <iostream>
#include <string>
#include <vector>
template<class Seq> void purge(Seq& c){
	typename Seq::iterator i;
	for(i = c.begin(); i != c.end(); ++i) {
		delete *i;
		*i = 0;
	}
}

// Iterator version:
template<class InpIt> void purge(InpIt begin, InpIt end) {
	while(begin != end) {
		delete *begin;
		*begin = 0;
		++begin;
	}
}
class BicyclePart
{
public:
	enum BPart{
		FRAME, WHEEL, SEAT, DERAILLEUR, HANDLEBAR, 
		SPROCKET, RACK, SHOCK, NPARTS};
private:
	BPart id;
	static std::string name [ NPARTS ];
public:
	BicyclePart(BPart bp):id(bp)
	{

	}

	friend std::ostream& operator<<( std::ostream& os, const BicyclePart& bp)
	{
		return os << bp.name[bp.id];
	}
};

class Bicycle
{
	std::vector<BicyclePart*> parts;
public:
	~Bicycle()
	{
		purge(parts);
	}

	void AddPart(BicyclePart* bp)
	{
		parts.push_back(bp);
	}

	friend std::ostream& operator<<(std::ostream& os, const Bicycle& bike)
	{
		os<< "{" ;
		for each(auto& bp in bike.parts)
		{
			os << *bp << ' ';
		}
		return os << "}";
	}
};

class Bicyclebuilder{
	protected:
		Bicycle* product;
public:
	Bicyclebuilder()
	{
		product = 0;
	}

	void createProduct()
	{
		product = new Bicycle;
	}

	virtual void buildFrame() = 0;
	virtual void buildWheel() = 0;
	virtual void buildSeat() = 0;

	virtual void buildDerailleur() = 0;
	virtual void buildHandleBar() = 0;
	virtual void buildSprocket() = 0;
	virtual void buildRack() = 0;

	virtual void buildShock() = 0;

	virtual std::string getBickName() const = 0;

	Bicycle* getProduct()
	{
		Bicycle* tmp = product;
		product = 0;
		return tmp;
	}
};


class MoutianBikeBuilder : public Bicyclebuilder{
public:
	void buildFrame();
	void buildWheel();
	void buildSeat();
	void buildDerailleur();
	
	void buildHandleBar();
	void buildSprocket();
	void buildRack();
	void buildShock();

	std::string getBickName() const{
		return "MountainBike";
	}
};

class TouringBikeBuilder : public Bicyclebuilder{
public:
	void buildFrame();
	void buildWheel();
	void buildSeat();
	void buildDerailleur();

	void buildHandleBar();
	void buildSprocket();
	void buildRack();
	void buildShock();

	std::string getBickName() const{
		return "TouringBike";
	}
};


class BicycleTechnician
{
	Bicyclebuilder* builder;
public:
	BicycleTechnician()
	{
		builder = 0;
	}
	void setBuilder(Bicyclebuilder* b)
	{
		builder = b;
	}

	void construct();
};
