#include<iostream>
#include<time.h>

//��ӡ����
void arr_print(int in_arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ":" << in_arr[i] << ' ';
	}
	std::cout << std::endl;
}

//��������
void heapBuild(int* in_arr, int size) {
	for (int i = 0; i < size; i++) {
		//��ǰ���������
		int currentIndex = i;
		//���ڵ�����
		int fatherIndex = (currentIndex - 1) / 2;
		while (in_arr[currentIndex] > in_arr[fatherIndex]) {
			std::cout << "��ǰ�ڵ㣺" << currentIndex + 1 << ":" << in_arr[currentIndex] << " ���ڵ㣺" << fatherIndex + 1 << ":" << in_arr[fatherIndex] << std::endl;
			int temp = in_arr[currentIndex];
			in_arr[currentIndex] = in_arr[fatherIndex];
			in_arr[fatherIndex] = temp;
			std::cout << "���������飺" << std::endl;
			arr_print(in_arr, size);
			currentIndex = fatherIndex;
			fatherIndex = (currentIndex - 1) / 2;
		}
	}
}
//��ʣ���������ɴ����
void heapOfLeftArr(int* in_arr, int index, int size, int maxsize) {
	int leftchild = 2 * index + 1;
	int rightchild = 2 * index + 2;
	while (leftchild < size) {
		int compareIndex;
		//�жϺ����нϴ��ֵ������
		if (in_arr[leftchild] < in_arr[rightchild] && rightchild < size) {
			compareIndex = rightchild;
		}
		else {
			compareIndex = leftchild;
		}
		//�Ƚϸ��ڵ��뺢�ӽڵ��е����ֵ����ȷ�����ֵ������
		if (in_arr[index] > in_arr[compareIndex]) {
			compareIndex = index;
		}
		std::cout << "����ǰ���飺" << std::endl;
		arr_print(in_arr, maxsize);
		std::cout << "compare_index:" << compareIndex + 1 << "   root:" << index + 1 << std::endl;
		//�����ڵ��Ѿ������ֵ���򲻽��н���
		if (index == compareIndex) {
			std::cout << "���ڵ㣺" << index + 1 << "�Ѿ������ֵ�������н�����" << std::endl;
			break;
		}
		//���򽻻�ʹ�ø��ڵ�Ϊ���ֵ������������ָ��ϴ�ĺ���
		int temp = in_arr[compareIndex];
		in_arr[compareIndex] = in_arr[index];
		in_arr[index] = temp;
		index = compareIndex;
		std::cout << "���������飺" << std::endl;
		arr_print(in_arr, maxsize);
		leftchild = 2 * index + 1;
		rightchild = 2 * index + 2;
	}
}

//������
void heapSort(int* in_arr, int size) {
	heapBuild(in_arr, size);
	int maxsize = size;
	std::cout << std::endl << "�ѽ�����ɡ�" << std::endl;
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
	int* elem; //����Ԫ�ش洢��ַ����̬��������
	int count; //��ǰ����Ԫ�ظ���
}HashTable;

//��ϣ���ʼ��
void hashInit(HashTable* hashTable) {
	int i;
	hashTable->elem = new int[HASHSIZE];
	hashTable->count = HASHSIZE;
	for (i = 0; i < HASHSIZE; i++) {
		hashTable->elem[i] = NULLKEY;
	}
}

//��ϣ����������������
int hashFunc(int data) {
	return data % HASHSIZE;
}

//��ϣ����뺯��
void hashInsert(HashTable* hashTable, int data) {
	int hashAddress = hashFunc(data);//���ϣ��ַ
	//������ͻ
	while (hashTable->elem[hashAddress] != NULLKEY) {
		hashAddress = (++hashAddress) % HASHSIZE;
	}
	std::cout << data << "��ϣ���в���λ�ã�" << hashAddress << std::endl;
	hashTable->elem[hashAddress] = data;
}

//��ϣ������㷨
int hashSearch(HashTable* hashTable, int data) {
	int hashAddress = hashFunc(data);//���ϣ��ַ
	while (hashTable->elem[hashAddress] != data) {//������ͻ
		//���ÿ��Ŷ�ַ�������ͻ
		hashAddress = (++hashAddress) % HASHSIZE;
		//�����ַ�в鵽������ΪNULL�����߾���һȦ�������ص�ԭλ�ã������ʧ��
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
	//��ʼ����ϣ��
	hashInit(&hashTable);
	//���ù�ϣ���������ϣ��
	for (int i = 0; i < arr_size; i++) {
		hashInsert(&hashTable, in_arr[i]);
	}
	//���ù�ϣ�����㷨
	result = hashSearch(&hashTable, searchNum);
	if (result == -1) {
		std::cout << "����ʧ��" << std::endl;
	}
	else {
		std::cout << searchNum << "�ڹ�ϣ���е�λ�ã�" << result + 1 << std::endl;
		std::cout << std::endl << hashTable.elem[result] << std::endl;
	}
	//heapBuild(in_arr, arr_size);
	//heapOfLeftArr(in_arr, 0, arr_size);
	//heapSort(in_arr, arr_size);
	//std::cout << std::endl << "������������" << std::endl;
	//arr_print(in_arr, arr_size);
}