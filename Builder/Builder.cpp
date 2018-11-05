#include "Builder.h"
#include <assert.h>
using namespace std;

std::string BicyclePart::name[NPARTS] = {
	"Frame", "Wheel", "Seat", "Derailleur",
	"Handlebar", "Sprocket", "Rack", "Shock"
}	;

void MoutianBikeBuilder::buildFrame()
{
	product->AddPart(new BicyclePart(BicyclePart::FRAME));
}

void MoutianBikeBuilder::buildWheel()
{
	product->AddPart(new BicyclePart(BicyclePart::WHEEL));
}
void MoutianBikeBuilder::buildSeat()
{
	product->AddPart(new BicyclePart(BicyclePart::SEAT));
}

void MoutianBikeBuilder::buildDerailleur()
{
	product->AddPart(new BicyclePart(BicyclePart::DERAILLEUR));
}

void MoutianBikeBuilder::buildHandleBar()
{
	product->AddPart(new BicyclePart(BicyclePart::HANDLEBAR));
}

void MoutianBikeBuilder::buildSprocket()
{
	product->AddPart(new BicyclePart(BicyclePart::SPROCKET));
}

void MoutianBikeBuilder::buildRack()
{
	product->AddPart(new BicyclePart(BicyclePart::RACK));
}

void MoutianBikeBuilder::buildShock()
{
	product->AddPart(new BicyclePart(BicyclePart::SHOCK));
}



void TouringBikeBuilder::buildFrame()
{
	product->AddPart(new BicyclePart(BicyclePart::FRAME));
}

void TouringBikeBuilder::buildWheel()
{
	product->AddPart(new BicyclePart(BicyclePart::WHEEL));
}
void TouringBikeBuilder::buildSeat()
{
	product->AddPart(new BicyclePart(BicyclePart::SEAT));
}

void TouringBikeBuilder::buildDerailleur()
{
	product->AddPart(new BicyclePart(BicyclePart::DERAILLEUR));
}

void TouringBikeBuilder::buildHandleBar()
{
	product->AddPart(new BicyclePart(BicyclePart::HANDLEBAR));
}

void TouringBikeBuilder::buildSprocket()
{
	product->AddPart(new BicyclePart(BicyclePart::SPROCKET));
}

void TouringBikeBuilder::buildRack()
{
	//product->AddPart(new BicyclePart(BicyclePart::RACK));
}

void TouringBikeBuilder::buildShock()
{
	//product->AddPart(new BicyclePart(BicyclePart::SHOCK));
}

void BicycleTechnician::construct()
{
	assert(builder);
	builder->createProduct();
	builder->buildFrame();
	builder->buildWheel();
	builder->buildSeat();
	builder->buildDerailleur();
	builder->buildHandleBar();
	builder->buildSprocket();
	builder->buildRack();
	builder->buildShock();
}
Bicycle* buildMeABike(BicycleTechnician&t, Bicyclebuilder* builder)
{
	t.setBuilder(builder);
	t.construct();
	Bicycle* b = builder->getProduct();

	cout << "built a " << builder->getBickName() <<endl;
	return b;
}
#include <map>
int main()
{
	map<string ,size_t> order;

	order["mountain"] = 2;
	order["touring"] = 3;
	
	vector<Bicycle*> bikes;

	Bicyclebuilder* m = new MoutianBikeBuilder;
	Bicyclebuilder* t = new TouringBikeBuilder;

	BicycleTechnician tech;

	for each(auto& orderitem in order)
	{
		Bicyclebuilder* builder;
		if (orderitem.first == "mountain")
		{
			builder = m;
		}
		else if(orderitem.first == "touring")
		{
			builder = t;
		}

		for (size_t i = 0; i < orderitem.second; ++i)
		{
			bikes.push_back(buildMeABike(tech, builder));
		}
	}
	delete m;
	delete t;

	for each( auto& bike in bikes)
	{
		cout << "Bicycle: " << *bike <<endl;
	}
	return 0;
}