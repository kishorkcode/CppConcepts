#include <iostream>

namespace General
{
	//const usage in variable
	static void Test()
	{
		int b = 10;
		const int MAX = 90;
		//MAX = 3; //error

		//Make the value constant i.e. do not let content change
		const int* p1 = new int;
		//*p1 = 2; //error
		p1 = &b; //no error

		int const* p1a = new int;
		//*p1a = 2; //error
		//p1a = &b; //no error

		//Make the pointer constant i.e. do not let pointer address change
		int* const p2 = new int;
		*p2 = 2; //no error
		//p2 = &b; // error

		//Make pointer and its value also constant
		const int* const p3 = new int;
		//*p3 = 2; //error
		//p3 = &b; // error
	}

	//const in class

	class Blah
	{
	public:
		int m_x, m_y;

		int GetX() const
		{
			//m_x = 5; //error cannot change member variable because method is const
			//unless m_x is defined as mutable
			return m_x;
		}

		void SetX(int x)
		{
			m_x = x;
		}
	};

	static void PrintData(const Blah& b)
	{
		//b.SetX(3); // cannot call non-const method because b variable is const
		//here const variable b means it cannot be changed, non const method are not allowed here
		//because it breaks the const promise
		std::cout << b.GetX() << std::endl;
	}
}
