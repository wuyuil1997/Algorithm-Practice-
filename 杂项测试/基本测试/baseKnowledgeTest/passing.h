#pragma once
#include<iostream>
using std::endl;
using std::cout;

void valueSwap(int a, int b) {
	cout << "ֵ���ݣ�" << endl;
	int temp = a;
	a = b;
	b = temp;
	cout << "���ú����У�" << endl;
	cout << "a:" << a << " address:" << &a << endl;
	cout << "b:" << b << " address:" << &b << endl;
}
void pointerSwap(int* a, int* b) {
	//�β�ָ��ʵ�εĵ�ַ������ͨ�������ַ���Ըı�ʵ�ε�ֵ
	cout << "ָ�봫�ݣ�" << endl;
	int temp = *a;
	*a = *b;
	*b = temp;
	cout << "���ú����У�" << endl;
	cout << "a:" << *a << " address:" << a << endl;
	cout << "b:" << *b << " address:" << b << endl;
}

void referenceSwap(int& a, int& b) {
	//�β���ʵ�ε����ã�Ҳ����Ϊʵ����������һ�����������Ըı��βο��Ըı�ʵ��
	cout << "���ô��ݣ�" << endl;
	int temp = a;
	a = b;
	b = temp;
	cout << "���ú����У�" << endl;
	cout << "a:" << a << " address:" << &a << endl;
	cout << "b:" << b << " address:" << &b << endl;
}