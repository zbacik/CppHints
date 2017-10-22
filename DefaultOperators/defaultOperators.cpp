#include <iostream>

using namespace std;

class Widget {
public:
	Widget(const Widget& ref)
	{
		std::cout << "Widget copy constructor" << std::endl;
		i = ref.i;
	}

	Widget(Widget&& ref)
	{
		std::cout << "Widget move constructor" << std::endl;
		i = ref.i;
		ref.i = 0;
	}

	Widget& operator=(Widget&& other)
	{
		std::cout << "Widget assign move operator" << std::endl;
		i = other.i;
		other.i = 0;

		return *this;
	}


	Widget& operator=(const Widget& other)
	{
		std::cout << "Widget assign operator" << std::endl;
		if(&other == this)
			return *this;

		i = other.i;
		return *this;
	}


	Widget(int i) : i(i)
	{
	}

	int i;
};

class Default
{
public:
	Default(int i)
	:mWidget(i)
	{
	}

private:
	Widget mWidget;
};

class NonDefault
{
public:
	NonDefault(int i)
	:mWidget(i)
	{
	}

	//Copy consturcotr
	NonDefault(const NonDefault& ref)
	:mWidget(0)
	{
		std::cout << "NonDefault copy operator" << std::endl;
		mWidget = ref.mWidget;
	}

private:
	Widget mWidget;
};


int main() {

	//Compilator explicitly  declare move constructor, where widget will be moved
	std::cout << "Default class:" << std::endl;
	Default default_1(1);
	Default default_2(2);
	default_2 = std::move(default_1);

	std::cout << std::endl;
	//Compilator explicitly do not declare move constructor, widget will be copy
	//(because user define constructor is declare)
	std::cout << "NonDefault class::" << std::endl;
	NonDefault nonDefault_1(1);
	NonDefault nonDefault_2(2);
	nonDefault_2 = std::move(nonDefault_1);

	return 0;
}

