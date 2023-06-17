#include <iostream>
using namespace std;

class Singleton
{
public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton& getInstance()
	{
		static Singleton instance;
		return instance;
	}

private:
	Singleton() = default;
	~Singleton() = default;
};

int main()
{
	cout << &Singleton::getInstance() << endl;
	cout << &Singleton::getInstance() << endl;
	getchar();
}