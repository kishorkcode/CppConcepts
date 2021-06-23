#include <memory>
#include <iostream>

namespace General { namespace SharedPointers {

	class Entity
	{
	public:
		Entity()
		{
			std::cout << "Entity created!" << std::endl;
		}

		~Entity()
		{
			std::cout << "Entity created!" << std::endl;
		}
	};

	static void TestSmartPointers()
	{
		//unique pointer
		{
			//std::unique_ptr<Entity> entity(new Entity()); //not recommended
			//if exception is raised while constructing the entity variable will have dangling pointer
			//so prefer std::make_unique<>
			std::unique_ptr<Entity> entity = std::make_unique<Entity>();
		}

		//shared pointer
		{
			std::shared_ptr<Entity> e0;
			{
				//std::shared_ptr<Entity> e1(new Entity());
				//prefer std::make_shared<> instead of using new passing, shared pointer needs to allocate control
				//block memory which will have reference counting mechanism
				//in the e1(new Entity()) way control block will be allocated only when e1 = e0
				//make_shared<> will allocate memory for class and control block together making it more efficient
				//also it has exception safety same as make_unique
				std::shared_ptr<Entity> e1 = std::make_shared<Entity>(); // reference count == 1
				e0 = e1; // reference count == 2
			}
			//object will be alive here also since reference count is 1
		}
		//object will be destroyed as reference count becomes 0

		//weak pointer
		{
			std::weak_ptr<Entity> e0;
			{
				std::shared_ptr<Entity> e1 = std::make_shared<Entity>(); // reference count == 1
				e0 = e1; // reference count == 1 // it weak pointer wont increase ref counter
			}
			auto isExpired = e0.expired(); // this will be true
		}
	}
	
}}
