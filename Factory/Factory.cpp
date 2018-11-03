#include "Factory.h"
#include <vector>

using namespace std;

char* sl[] = {
	"Circle", "Circle", "Square",  "Square", "Square"
};
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
	return 0;
}