#include <iostream>
#include <vector>

namespace STL { namespace Vector {

	class Entity
	{
	public:
		Entity() = delete;
		Entity(int data) : m_data(data) {}
		Entity(const Entity& other)
		{
			std::cout << "Copied" << std::endl;
		}
		
	private:
		int m_data;
	};
	
	static void TestVectors()
	{
		//use 1
		std::vector<Entity> v1;
		v1.push_back(Entity(1));
		v1.push_back(Entity(2));
		v1.push_back(Entity(3));
		//result copied will be printed 6 times
		//because vector of vector resizing and push_back creates and copies the data

		std::cout << "-------- use 2 --------" << std::endl;

		std::vector<Entity> v2;
		v2.reserve(3);
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);

		//prints 3 copied statements

		//reserve the location before itself to avoid copying of the data
		
		std::cout << "-------- use 3 --------" << std::endl;
		
		std::vector<Entity> v3;
		v3.reserve(3);
		v3.emplace_back(1);
		v3.emplace_back(2);
		v3.emplace_back(3);

		//does not print copied

		//emplace_back will construct the object in vector allocated memory itself
		//push_back will create a temporary object and then it will copy that object to vector allocated memory

		std::cin.get();
	}
	
}}
