namespace General
{
	class B;

	class A
	{
	public:
		A(int x)
		{
			data_a = x;
		}
	private:
		int data_a;

	friend int fun(A, B);
	};
	
	class B
	{
	public:
		B(int x)
		{
			data_b = x;
		}

	private:
		int data_b;

	friend int fun(A, B);
	};
	
	int fun(A a, B b)
	{
		return a.data_a + b.data_b;
	}
}
