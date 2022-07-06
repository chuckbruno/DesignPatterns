#include "resource.h"
#include <list>

class Warehouse
{
public:
	static Warehouse* getInstance()
	{
		if (instance == 0)
		{
			instance = new Warehouse;
		}
		return instance;
	}

	Resource* getResource()
	{
		if (resources.empty())
		{
			std::cout << "Creating new." << std::endl;
			return new Resource();
		}
		else
		{
			std::cout << "Reusing existing." << std::endl;
			Resource* resource = resources.front();
			resources.pop_front();
			return resource;
		}
	}

	void returnResource(Resource* object)
	{
		object->reset();
		resources.push_back(object);
	}

private:
	static Warehouse* instance;
	std::list<Resource*> resources;
	Warehouse(){}
};


Warehouse* Warehouse::instance = nullptr;
