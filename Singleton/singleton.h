
#pragma once

#include <vector>

struct Tea
{
	int cost;
	int length;
	int quantity;
};

class Manager
{
public:
	static Manager* Get()
	{
		static Manager* instance = nullptr;
		if (!instance)
			instance = new Manager();

		return instance;

	}

	void Add(Tea& tea)
	{
		teas.push_back(tea);
	}

	[[nodiscard]]const std::vector<Tea> GetTeaList() const
	{
		return teas;
	}

private:
	std::vector<Tea> teas;
};