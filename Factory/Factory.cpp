#include "Factory.h"
#include <vector>
#include "FactorySharedPtr.h"

using namespace std;

char* sl[] = {
	"Circle", "Circle", "Square",  "Square", "Square"
};


void test_withSharedPtr()
{
	vector<shared_ptr<myc11::Shape>> shapes;

	try
	{
		for (size_t i = 0; i < sizeof sl / sizeof(sl[0]); ++i)
		{
			shapes.push_back(myc11::ShapeFactory::CreateShape(sl[i]));
		}
	}
	catch (ShapeFactory::BadShapeCreation)
	{

	}

	for each (auto& sh in shapes )
	{
		sh->Draw();
	}
}
int main()
{
	vector<Shape*> shapes;

	try
	{
		for (size_t i = 0; i < sizeof sl / sizeof(sl[0]); ++i)
		{
			shapes.push_back(ShapeFactory::CreateShape(sl[i]));
		}
	}
	catch (ShapeFactory::BadShapeCreation)
	{
		
	}

	for each (auto& sh in shapes )
	{
		sh->Draw();
	}

	test_withSharedPtr();
	return 0;
}