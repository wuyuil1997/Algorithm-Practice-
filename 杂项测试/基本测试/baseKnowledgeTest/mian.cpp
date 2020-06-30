#include<iostream>
#include"static_test.h"
#include"passing.h"
using std::cout;
using std::endl;

int main() {
	int a = 1, b = 2;
	cout << "主体函数中：" << endl;
	cout << "a:" << a << " address:" << &a << endl;
	cout << "b:" << b << " address:" << &b << endl;
	valueSwap(a, b);
	cout << "主体函数中：" << endl;
	cout << "a:" << a << " address:" << &a << endl;
	cout << "b:" << b << " address:" << &b << endl;
	pointerSwap(&a, &b);
	cout << "主体函数中：" << endl;
	cout << "a:" << a << " address:" << &a << endl;
	cout << "b:" << b << " address:" << &b << endl;
	referenceSwap(a, b);
	cout << "主体函数中：" << endl;
	cout << "a:" << a << " address:" << &a << endl;
	cout << "b:" << b << " address:" << &b << endl;
	int result = sum(0, 2);
	cout << "sum(0, 2)=" << result << endl;
	result = sum(3, 5);
	cout << "sum(3, 5)=" << result << endl;
	return 0;
}
