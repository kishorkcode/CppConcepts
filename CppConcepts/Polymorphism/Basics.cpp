#include <iostream>

namespace Polymorphism
{
	class Base
	{
	public:
		virtual void fun()
		{
			std::cout << "base";
		}
	};

	class Derived : public Base
	{
	public:
		void fun() //without virtual keyword on Base class method this wont override
		{
			std::cout << "derived";
		}
	};
}
