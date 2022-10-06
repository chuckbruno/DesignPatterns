#include <typeinfo>
#include <iostream>
#define classname typeid(this).name()

class Engine;

class State {
protected:
	Engine* _engine;
public:
	virtual ~State(){}
	void SetEngine(Engine* engine) {
		_engine = engine;
	}

	virtual void DoWorkA() = 0;
	virtual void DoWordB() = 0;
};

class Engine {
public:
	Engine(State* state) : _state(nullptr)
	{
		TransitionTo(state);
	}

	~Engine()
	{
		delete _state;
	}

	void TransitionTo(State* state)
	{
		if (_state) delete _state;
		_state = state;
		_state->SetEngine(this);
	}

	void RequestA()
	{
		_state->DoWorkA();
	}

	void RequestB()
	{
		_state->DoWordB();
	}

private:
	State* _state;
};

class ConcreteStateA : public State
{
public:
	void DoWorkA() override
	{
		std::cout << classname << " called DoWordA()\n";
	}

	void DoWordB() override
	{
		std::cout << classname << " called DoWorkB()\n";
	}
};

class ConcreteStateB : public State
{
public:
	void DoWorkA() override
	{
		std::cout << classname << " called DoWorkA()\n";
		_engine->TransitionTo(new ConcreteStateA);
	}

	void DoWordB() override
	{
		std::cout << classname << " called DoWorkB()\n";
	}
};