#include<iostream>

struct Student {
	int num;
	int age;
	char* name;
};

//void Student();
void f(struct Student me);

int main() {
	int arr[10] = {};
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		arr[i] = 10 -i;
	}
	int* p = NULL;
	p = &arr[0];
	//int* const p = arr;
	//p = &arr[1];
	std::cout << "sizeof(arr):" << sizeof(arr) << std::endl;
	std::cout << "sizeof(p):" << sizeof(p) << std::endl;
	std::cout << "*(p + 1):" << *(p + 1)  << std::endl;
	std::cout << "*std::begin(arr):" << *std::begin(arr) << std::endl;
	std::cout << "std::size(arr):" << std::size(arr) << std::endl;

}