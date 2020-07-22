#include <iostream>
#include <dos.h>
using namespace std;

void SetTimeOutCplusplus(void *func, int time)
{
	delay(1000);
	func();
	
}

 void HelloWorld()
{
	cout << "Hello World" << endl;
}

 void(*funcPointer) = &HelloWorld;

int main()
{
	SetTimeOutCplusplus(funcPointer, 1000);
	
	return 0;
}
