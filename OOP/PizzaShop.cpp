#include <iostream>
using namespace std;

class Pizza
{
private:
	void MakeDough()
	{
		cout << "Making the dough of " << GetPizzaName() <<"pizza"<< endl;
	}
	void BakeDough()
	{
		cout << "Baking " << GetPizzaName() << "pizza" << endl;
	}
	void AddToppings()
	{
		cout << "Adding Toppings of " << GetPizzaName() << "pizza" << endl;
	}
protected:
	virtual const char* GetPizzaName() = 0;

public:
	void MakePizza()
	{
		MakeDough();
		BakeDough();
		AddToppings();
		cout << "The " << GetPizzaName() << " is ready!" << endl;

	}
};

class ChickenPizza : public Pizza
{
protected:
	const char* GetPizzaName()
	{
		return "Chicken";
	}
};
class CheesePizza : public Pizza
{
protected:
	const char* GetPizzaName()
	{
		return "Cheese";
	}
};
class BeefPizza : public Pizza
{
protected:
	const char* GetPizzaName()
	{
		return "Beef";
	}
};

/*void MakePizza(Pizza* ptr)
{
	ptr->MakePizza();
}*/

void main()
{
	int choice;
	cout << "Choose your preferred pizza, enter 1 for Chicken Pizza or 2 for cheese Pizza or 3 for Beef Pizza: ";
	cin >> choice;
	//Pizza ptr = nullptr;
	Pizza* ptr;
	ChickenPizza chicken;
	CheesePizza cheese;
	BeefPizza beef;

	ptr = &chicken;
	ptr = &cheese;
	ptr = &beef;

	switch (choice)
	{
	case 1:
		ptr = new ChickenPizza;
		break;
	case 2:
		ptr = new CheesePizza;
		break;
	case 3:
		ptr = new BeefPizza;
		break;
	default:
		cout << "Incorrect Choice!" << endl;
	}
	//MakePizza(ptr);

	ptr->MakePizza();   // When 'MakePizza' is called, it invokes 'GetPizzaName' is a pure virtual function in the base class, and it is overridden in the derived classes  'ChickenPizza, CheesePizza, or BeefPizza based on the user's choice.
	                    //if the user input first choice(Chicken Pizza) it will go to ChickenPizza class via its object(chicken) to which the pointer points and call "GetPizzaName' function existing in this class 
    delete ptr;
}
