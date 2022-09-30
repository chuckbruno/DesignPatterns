#pragma once
#include <string>
#include <iostream>

struct Event
{
	int id = -1;
	std::string message = "";
};


class IHandler
{
public:
	virtual ~IHandler(){}
	virtual IHandler* SetNext(IHandler* handler) = 0;
	virtual Event Handle(Event event) = 0;

};

class BaseHandler : public IHandler
{
public:
	BaseHandler() :next_handler(nullptr) {}
	IHandler* SetNext(IHandler* handler) override
	{
		next_handler = handler;
		return handler;
	}

	Event Handle(Event event) override
	{
		if (next_handler)
		{
			return next_handler->Handle(event);
		}
		return event;
	}


private:
	IHandler* next_handler;
};

class HandleEvent1 : public BaseHandler
{
public:
	Event Handle(Event event) override
	{
		if (event.id == 1)
		{
			std::cout << "-> handling event with id 1" << std::endl;
			std::cout << "   event message: " << event.message << std::endl;
			return event;
		}
		return BaseHandler::Handle(event);
	}
};

class HandleEvent2 : public BaseHandler
{
public:
	Event Handle(Event event) override
	{
		if (event.id == 2)
		{
			std::cout << "-> handling event with id 2" << std::endl;
			std::cout << "   event message: " << event.message << std::endl;
			return event;
		}
		return BaseHandler::Handle(event);
	}
};

class HandleEvent3 : public BaseHandler
{
public:
	Event Handle(Event event) override
	{
		if (event.id == 3)
		{
			std::cout << "-> handling event with id 3" << std::endl;
			std::cout << "   event message: " << event.message << std::endl;
			return event;
		}
		return BaseHandler::Handle(event);
	}
};
