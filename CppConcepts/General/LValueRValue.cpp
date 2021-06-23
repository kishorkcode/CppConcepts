#include <iostream>

namespace General { namespace LValueRValue {

	static void FunA(int i) { std::cout << i << std::endl; }

	static void FunB(int& i) { std::cout << i << std::endl; }

	static void PrintName(std::string& name) { std::cout << name.c_str() << std::endl; }
	
	static void PrintNameRValue(std::string&& name) { std::cout << name.c_str() << std::endl; }
	
	static void TestLValueRValue()
	{
		//lvalue - value which has a location
		//rvalue - value which does not have location

		int a = 10; //a - lvalue ; 10 - rvalue

		FunA(a);
		FunA(10);

		//rvalue cannot be assigned to lvalue reference - int& is lvalue reference
		//Fun1(10); // error

		//a rvalue can be assigned to lvalue reference
		const int& lv = 10; //compiler here might generate code like int temp = 10; const int& lv = temp;

		FunB(a);
		//FunB(10); // no error - rvalue can be assigned to const lvalue reference

		//So const lvalue reference can accept both lvalue and rvalue

		std::string firstName = "Kishor"; //firstName - lvalue ; Kishor - rvalue
		std::string lastName = "Kumar"; //lastName - lvalue ; Kumar - rvalue
		std::string fullName = firstName + lastName; //fullName - lvalue ; temporary string (firstName + lastName) is rvalue
		//(firstName + lastName) is a temporary variable - rvalue

		PrintName(firstName); //no error - lvalue
		PrintName(lastName); //no error - lvalue
		PrintName(fullName); //no error - lvalue
		PrintName(firstName + lastName); // error in C++11

		//rvalue reference
		//PrintNameRValue(fullName); //error - lvalue cannot be passed to rvalue reference
		PrintNameRValue(firstName + lastName); // no error

		//Conclusion
		//lvalue - values which have a storage location
		//rvalue - a temporary values or a value which does not have storage location
		//lvalue reference (int&)- can take only lvalues
		//const lvalue reference (const int&)- can take both lvalue and rvalue
		//rvalue reference (int&&)- can take only temporary rvalues
	}
	
}}
