#include <iostream>

namespace General { namespace FuntionPointer {

	void Hello()
	{
		std::cout << "Hello!" << std::endl;
	}


	void TestFunctionPointer()
	{
		//with auto
		auto hello = Hello;
		hello();

		//without using auto - looks confusing
		void(*funcName)(); // funcName is function pointer variable name here
		funcName = Hello; // assign function pointer to function
		funcName(); // call the function

		//clean way without auto
		typedef void(*funcPointer)(); // this can be re-used for same similar signature
		funcPointer f1 = Hello;
		f1();
		
		std::cin.get();
	}
}}
