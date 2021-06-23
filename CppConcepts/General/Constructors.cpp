#include <iostream>

namespace General { namespace Constructors
{

	class Entity
	{
		Entity()
		{
			std::cout << " Default constructor";
		}

		Entity(const Entity& other) //copy constructor
		{
			
		}

		Entity(Entity&& other) noexcept // move constructor
		{
			
		}
	};
	
}}
