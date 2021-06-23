#include "SomeDesign.h"
#include <chrono>
#include <iostream>

int main()
{
	const auto start = std::chrono::high_resolution_clock::now();
	
	System::IController* controller = new System::Controller;
	controller->Print();
	controller->Store();

	const auto stop = std::chrono::high_resolution_clock::now();
	auto duration = stop - start;
	auto nanoseconds = duration.count();
	auto microseconds = nanoseconds * 0.001;
	auto seconds = microseconds * 0.001;
	std::cout << seconds  << std::endl;
	

	delete controller;
}
