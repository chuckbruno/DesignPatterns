struct Hamberger
{
	bool hasBun = true;
	bool hasMeat = true;
	bool hasPickle = false;
	bool hasCatchup = false;
	bool hasMustard = false;
	bool hasOnion = false;
	bool hasTomato = false;
	bool hasMayo = false;
	bool hasLettuce = false;

};

struct Cheeseburger : Hamberger
{
	bool hasCheese = false;
};



class HamburgerMaker
{
public:
	virtual ~HamburgerMaker() = default;
	Hamberger MakeBurger()
	{
		Hamberger burger;
		return burger;
	}
};

class CheeseburgerMaker
{
private:
	HamburgerMaker* hbamber;
public:
	virtual ~CheeseburgerMaker() = default;
	CheeseburgerMaker(HamburgerMaker* hbm) { hbamber = hbm; }
	Cheeseburger MakeBurger()
	{
		//Cheeseburger cburger = static_cast<Cheeseburger>(hbamber->MakeBurger());
		//Hamberger te = hbamber->MakeBurger();
		Cheeseburger cburger;
		return cburger;
	}
};