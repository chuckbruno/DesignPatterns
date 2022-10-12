
#include <string>
#include <iostream>


class BaseComponent;

class IController {
public:
	virtual void Notify(BaseComponent* sender, std::string event) const = 0;
};

class BaseComponent {
protected:
	IController* _controller;
public:
	BaseComponent(IController* controller = nullptr) :_controller(controller) {}
	void SetController(IController* controller)
	{
		_controller = controller;
	}
};

class AirplaneComponent :public BaseComponent
{
public:
	void FlyForward() {
		std::cout << "AirplaneComponent is Flying Forward" << std::endl;
		_controller->Notify(this, "Forward");
	}

	void Landing() {
		std::cout << "AirplaneComponent is Landing" << std::endl;
		_controller->Notify(this, "Land");
	}
};

class WeatherComponent :public BaseComponent
{
public:
	void Raining()
	{
		std::cout << "WeatherComponent begins raning" << std::endl;
		_controller->Notify(this, "Rain");
	}
	
	void Sunshine()
	{
		std::cout << "WeatherComponent begins sun" << std::endl;
		_controller->Notify(this, "Sun");
	}
};

class ConcreteController : IController
{
public:
	ConcreteController(AirplaneComponent* ac, WeatherComponent* wc):
		airplanecomp(ac), weathercomp(wc){
		airplanecomp->SetController(this);
		weathercomp->SetController(this);
	}

	void Notify(BaseComponent* sender, std::string event) const override
	{
		std::cout << "event recieved: " << event << std::endl;
		if (event == "Sun")
		{
			airplanecomp->Landing();
		}
		if (event == "Land")
		{
			std::cout << "airplane is landing" << std::endl;
		}
	}

private:
	AirplaneComponent* airplanecomp;
	WeatherComponent* weathercomp;
};


int main()
{
	AirplaneComponent* airplane = new AirplaneComponent;
	WeatherComponent* weather = new WeatherComponent;

	ConcreteController* controller = new ConcreteController(airplane, weather);
	airplane->Landing();
	weather->Sunshine();
	weather->Raining();
	airplane->FlyForward();

	delete airplane;
	delete weather;
	delete controller;

	return 0;
}