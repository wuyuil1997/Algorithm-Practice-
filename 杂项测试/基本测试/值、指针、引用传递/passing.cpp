#include<iostream>
using std::cout;
using std::endl;

void valueSwap(int a, int b) {
	cout << "值传递：" << endl;
	int temp = a;
	a = b;
	b = temp;
	cout << "调用函数中：" << endl;
	cout << "a:" << a << " address:" << &a << endl;
	cout << "b:" << b << " address:" << &b << endl;
}
void pointerSwap(int* a, int* b) {
	//形参指向实参的地址，所以通过这个地址可以改变实参的值
	cout << "指针传递：" << endl;
	int temp = *a;
	*a = *b;
	*b = temp;
	cout << "调用函数中：" << endl;
	cout << "a:" << *a << " address:" << a << endl;
	cout << "b:" << *b << " address:" << b << endl;
}

void referenceSwap(int& a, int& b) {
	//形参是实参的引用，也就是为实参数据起了一个别名，所以改变形参可以改变实参
	cout << "引用传递：" << endl;
	int temp = a;
	a = b;
	b = temp;
	cout << "调用函数中：" << endl;
	cout << "a:" << a << " address:" << &a << endl;
	cout << "b:" << b << " address:" << &b << endl;
}


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
	return 0;
}