#include <iostream>

namespace General { namespace MoveConstructor {

	class String
	{
	public:
		String() = default;

		String(const char* data)
		{
			std::cout << "Created" << std::endl;
			m_length = static_cast<unsigned>(strlen(data));
			m_data = new char[m_length];
			memcpy(m_data, data, m_length);
		}

		String(const String& other)
		{
			std::cout << "Copied" << std::endl;
			m_length = other.m_length;
			m_data = new char[m_length];
			memcpy(m_data, other.m_data, m_length);
		}

		String(String&& other) noexcept
		{
			std::cout << "Moved" << std::endl;
			m_length = other.m_length;
			m_data = other.m_data;

			other.m_length = 0;
			other.m_data = nullptr;
		}

		String& operator=(String&& other) noexcept
		{
			std::cout << "Move assignment" << std::endl;

			if(this != &other)
			{
				delete[] m_data;
				
				m_length = other.m_length;
				m_data = other.m_data;

				other.m_length = 0;
				other.m_data = nullptr;
			}

			return *this;
		}

		~String()
		{
			std::cout << "Destroyed" << std::endl;
			delete[] m_data;
		}

		void Print()
		{
			for (unsigned i = 0; i < m_length; i++)
				std::cout << m_data[i];
			std::cout << std::endl;
		}
		
	private:
		unsigned m_length;
		char *m_data;
	};

	class Entity
	{
	public:
		Entity(const String& string) : m_name(string)
		{}

		Entity(String&& string) : m_name(std::move(string))
		{}

		void PrintName()
		{
			m_name.Print();
		}
		
	private:
		String m_name;
	};
	
	static void TestMoveConstructor()
	{
		//Entity entity("Abc");
		//entity.PrintName();

		//String string = "Hello";
		//String dest = string; //copy constructor
		//String destination = std::move(string); //move constructor

		String source = "Apple";
		String destination;

		std::cout << "Before Moving" << std::endl;
		std::cout << "Source : ";
		source.Print();
		std::cout << "Destination : ";
		destination.Print();

		destination = std::move(source);
		std::cout << "After Moving" << std::endl;
		std::cout << "Source : ";
		source.Print();
		std::cout << "Destination : ";
		destination.Print();
		
		std::cin.get();
	}
	
}}
