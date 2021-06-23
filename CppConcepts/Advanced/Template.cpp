#include <iostream>

namespace Advanced { namespace Templates {

	template<typename T>
	void Print(T t)
	{
		std::cout << t << std::endl;
	}

	template<typename T, int N>
	class Array
	{
	public:
		int getSize() const
		{
			return N;
		}

	private:
		T m_data[N];
	};

	static void TestTemplates()
	{
		Print(1);
		Print("Kishor");
		Print(1.4);

		Array<int, 10> intArray{};
		
	}

	template<typename T>
	class unique_pointer
	{
	public:
		unique_pointer() : m_data(nullptr) {}
		
		explicit unique_pointer(T* data) : m_data(data) {}

		~unique_pointer()
		{
			delete m_data;
		}

		unique_pointer(const unique_pointer& other) = delete;
		unique_pointer operator=(const unique_pointer& other) = delete;

	private:
		T* m_data;
	};
}}