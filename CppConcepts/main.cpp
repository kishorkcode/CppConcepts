
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	//"Kishor is name My"

	std::stack<std::string> stack;

	char str[] = "My name is Kishor";
	const char *delim = " ";

	char *next_token;
	auto *token = strtok_s(str, delim, &next_token);
	while (token) {
		stack.push(std::string(token));
		token = strtok_s(nullptr, delim, &next_token);
	}
	
	while (!stack.empty())
	{
		cout << stack.top() << " ";
		stack.pop();
	}
	
	cin.get();

	return 0;
}