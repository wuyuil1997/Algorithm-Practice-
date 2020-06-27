#include<iostream>
#include<time.h>

//打印数组
void arr_print(int in_arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ":" << in_arr[i] << ' ';
	}
	std::cout << std::endl;
}

//构造大根堆
void heapBuild(int* in_arr, int size) {
	for (int i = 0; i < size; i++) {
		//当前插入的索引
		int currentIndex = i;
		//父节点索引
		int fatherIndex = (currentIndex - 1) / 2;
		while (in_arr[currentIndex] > in_arr[fatherIndex]) {
			std::cout << "当前节点：" << currentIndex + 1 << ":" << in_arr[currentIndex] << " 父节点：" << fatherIndex + 1 << ":" << in_arr[fatherIndex] << std::endl;
			int temp = in_arr[currentIndex];
			in_arr[currentIndex] = in_arr[fatherIndex];
			in_arr[fatherIndex] = temp;
			std::cout << "交换后数组：" << std::endl;
			arr_print(in_arr, size);
			currentIndex = fatherIndex;
			fatherIndex = (currentIndex - 1) / 2;
		}
	}
}
//将剩余的数构造成大根堆
void heapOfLeftArr(int* in_arr, int index, int size, int maxsize) {
	int leftchild = 2 * index + 1;
	int rightchild = 2 * index + 2;
	while (leftchild < size) {
		int compareIndex;
		//判断孩子中较大的值的索引
		if (in_arr[leftchild] < in_arr[rightchild] && rightchild < size) {
			compareIndex = rightchild;
		}
		else {
			compareIndex = leftchild;
		}
		//比较父节点与孩子节点中的最大值，并确定最大值的索引
		if (in_arr[index] > in_arr[compareIndex]) {
			compareIndex = index;
		}
		std::cout << "交换前数组：" << std::endl;
		arr_print(in_arr, maxsize);
		std::cout << "compare_index:" << compareIndex + 1 << "   root:" << index + 1 << std::endl;
		//若父节点已经是最大值，则不进行交换
		if (index == compareIndex) {
			std::cout << "父节点：" << index + 1 << "已经是最大值，不进行交换。" << std::endl;
			break;
		}
		//否则交换使得父节点为最大值，并更新索引指向较大的孩子
		int temp = in_arr[compareIndex];
		in_arr[compareIndex] = in_arr[index];
		in_arr[index] = temp;
		index = compareIndex;
		std::cout << "交换后数组：" << std::endl;
		arr_print(in_arr, maxsize);
		leftchild = 2 * index + 1;
		rightchild = 2 * index + 2;
	}
}

//堆排序
void heapSort(int* in_arr, int size) {
	heapBuild(in_arr, size);
	int maxsize = size;
	std::cout << std::endl << "堆建立完成。" << std::endl;
	while (size > 1) {
		int temp = in_arr[0];
		in_arr[0] = in_arr[size - 1];
		in_arr[size - 1] = temp;
		size--;
		heapOfLeftArr(in_arr, 0, size, maxsize);
	}
}

#define HASHSIZE  100
#define NULLKEY -1

typedef struct {
	int* elem; //数组元素存储地址，动态分配数组
	int count; //当前数据元素个数
}HashTable;

//哈希表初始化
void hashInit(HashTable* hashTable) {
	int i;
	hashTable->elem = new int[HASHSIZE];
	hashTable->count = HASHSIZE;
	for (i = 0; i < HASHSIZE; i++) {
		hashTable->elem[i] = NULLKEY;
	}
}

//哈希函数，除留余数法
int hashFunc(int data) {
	return data % HASHSIZE;
}

//哈希表插入函数
void hashInsert(HashTable* hashTable, int data) {
	int hashAddress = hashFunc(data);//求哈希地址
	//发生冲突
	while (hashTable->elem[hashAddress] != NULLKEY) {
		hashAddress = (++hashAddress) % HASHSIZE;
	}
	std::cout << data << "哈希表中插入位置：" << hashAddress << std::endl;
	hashTable->elem[hashAddress] = data;
}

//哈希表查找算法
int hashSearch(HashTable* hashTable, int data) {
	int hashAddress = hashFunc(data);//求哈希地址
	while (hashTable->elem[hashAddress] != data) {//发生冲突
		//利用开放定址法解决冲突
		hashAddress = (++hashAddress) % HASHSIZE;
		//如果地址中查到的数据为NULL，或者经过一圈后遍历后回到原位置，则查找失败
		if (hashTable->elem[hashAddress] == NULLKEY || hashAddress == hashFunc(data)) {
			return -1;
		}
	}
	return hashAddress;
}

int main()
{
	HashTable hashTable;
	int result;
	int searchNum = 18;
	int arr_size = 100;
	int *in_arr = new int[arr_size];
	srand((unsigned)time(NULL));
	for (int i = 0; i < arr_size; i++) {
		in_arr[i] = (rand() % 100);
	}
	arr_print(in_arr, arr_size);
	//初始化哈希表
	hashInit(&hashTable);
	//利用哈希函数构造哈希表
	for (int i = 0; i < arr_size; i++) {
		hashInsert(&hashTable, in_arr[i]);
	}
	//调用哈希查找算法
	result = hashSearch(&hashTable, searchNum);
	if (result == -1) {
		std::cout << "查找失败" << std::endl;
	}
	else {
		std::cout << searchNum << "在哈希表中的位置：" << result + 1 << std::endl;
		std::cout << std::endl << hashTable.elem[result] << std::endl;
	}
	//heapBuild(in_arr, arr_size);
	//heapOfLeftArr(in_arr, 0, arr_size);
	//heapSort(in_arr, arr_size);
	//std::cout << std::endl << "最终排序结果：" << std::endl;
	//arr_print(in_arr, arr_size);
}