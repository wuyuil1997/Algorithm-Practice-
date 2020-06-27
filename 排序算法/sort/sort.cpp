//���������㷨��ϰ
#include<iostream>
#include<time.h>

//��ӡ����
void arr_print(int in_arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ":" << in_arr[i] << ' ';
	}
	std::cout << std::endl;
}

//ֱ�Ӳ�������
/*
�ȶ�����
�ʼ�϶������������е�һ��Ԫ��Ϊ�������ҽ�֮��Ϊһ�����飬��������Ԫ�������������ɨ�裬
ÿɨ��һ��Ԫ�أ��ҵ�����������������Ӧ�ò����λ�ã����루����Ԫ�غ��ƣ���ɨ�������������������
������ϡ�
*/
void straightInsertSort(int* in_arr, int size)
{
	for (int i = 1; i < size; i++) {
		std::cout << "��ǰλ�ã�" << i + 1 << std::endl;
		int pos_insert = 0;
		bool mark_insert = false;
		for (int j = 0; j < i; j++) {
			//�϶���һ������Ϊ���������У��ӵڶ���λ�ÿ�ʼ����������������ɨ�裬�ҵ��ʵ�λ�ò��롣
			if (in_arr[i] < in_arr[j]) {
				pos_insert = j;
				mark_insert = true;
				break;
			}
			else {
				mark_insert = false;
			}
		}
		if (mark_insert == true) {
			std::cout << i + 1 << "��λ���ֲ���λ�ã�" << pos_insert + 1 << std::endl;
			int insert_num = in_arr[i];
			for (int k = i; k > pos_insert; k--) {
				in_arr[k] = in_arr[k - 1];
			}
			in_arr[pos_insert] = insert_num;
			std::cout << "��������飺";
			arr_print(in_arr, size);
		}
		else {
			std::cout << "��λ������Ϊ���������������ֵ����ִ�в��������" << std::endl;
		}
	}
}

//ϣ������
/*
���ȶ�����
����������򣬽������Ϊ���ΪN��len/N�����飬ÿ���������ֱ�Ӳ������򣬴˺�N�𽥼�����1��
ÿ�μ�����٣����ٴζԵõ���ÿ���������ֱ�Ӳ�������
*/
void shellSort(int* in_arr, int size) {
	int len = size / 2;
	while (len >= 1) {
		for (int i = 0; i < len; i++) {
			std::cout << "��ǰλ�ã�" << i + 1 << std::endl;
			int pos_insert = 0;
			bool mark_insert = false;
			for (int j = i + len; j < size; j += len) {
				std::cout << "�Ƚ�λ�ã�" << j + 1 << std::endl;
				for (int m = i; m < j; m += len) {
					if (in_arr[j] < in_arr[m]) {
						pos_insert = m;
						mark_insert = true;
						break;
					}
					else {
						mark_insert = false;
					}
				}
				if (mark_insert == true) {
					std::cout << i + 1 << "��λ���ֲ���λ�ã�" << pos_insert + 1 << std::endl;
					int insert_num = in_arr[j];
					for (int k = j; k > pos_insert; k -= len) {
						in_arr[k] = in_arr[k - len];
					}
					in_arr[pos_insert] = insert_num;
					std::cout << "��������飺";
					arr_print(in_arr, size);
				}
				else {
					std::cout << "��λ������Ϊ���������������ֵ����ִ�в��������" << std::endl;
				}
			}
		}
		len /= 2;
	}
}

//ð������
/*
�ȶ�����
ÿһ��ɨ�����飬���ζԱ�����Ԫ�صĴ�С�����ϴ�ֵ�������Ҳࣨ�±��λ�ã�������ð������
*/
void bubbleSort(int* in_arr, int size) {
	bool mark_sorted = false;
	for (int i = 0; i < size - 1; i++) {
		mark_sorted = true;
		for (int j = 0; j < size - 1 - i; j++) {
			if (in_arr[j] > in_arr[j + 1]) {
				mark_sorted = false;
				int temp = in_arr[j];
				in_arr[j] = in_arr[j + 1];
				in_arr[j + 1] = temp;
			}
		}
		if (mark_sorted == true) break;
	}
}

//��������
/*
��һ�������ҵ�һ����׼����ͨ��Ϊ������Ԫ�أ���
1��������β�����ײ�ɨ�裬�ҵ���һ���Ȼ�׼��С��Ԫ�أ��滻��׼��λ�ã���ָ��ָ��Ԫ��ԭλ��
2��Ȼ��������ײ���β��ɨ�裬�ҵ���һ���Ȼ�׼�����Ԫ�أ��滻�������滻�������µ�λ�ã���ָ��ָ��Ԫ��ԭλ�á�
3����1���滻Ԫ��λ�ÿ�ʼ�ظ�1�Ĳ�������2���滻Ԫ��λ���ظ�2�Ĳ�����ֱ�����ָ������ұ�ָ�롣
4����һ��������ϣ������Ϊ�������������飬�������������ظ�1-3�Ĳ�����
*/

void quickSort(int* in_arr, int l, int r, int size) {
	if (l < r) {
		int i = l, j = r, compare = in_arr[l];
		std::cout << "��׼��:" << compare << std::endl;
		while (i < j) {
			//��������ɨ�裬С�ڻ�׼������ֵ���滻����׼�������
			std::cout << "����:" << j + 1 << "����:" << i + 1 << "ɨ�衣" << std::endl;
			while (i < j && in_arr[j] >= compare) {
				j--;
			}
			if (i < j) {
				std::cout << i + 1 << "��" << in_arr[i] << "��" << j + 1 << "��" << in_arr[j] << "�滻��" << std::endl;
				in_arr[i++] = in_arr[j];
				std::cout << "�滻�����飺";
				arr_print(in_arr, size);
			}
			//��������ɨ�裬���ڻ�׼������ֵ���滻����׼�����Ҳ�
			std::cout << "����:" << i + 1 << "����:" << j + 1 << "ɨ�衣" << std::endl;
			while (i < j && in_arr[i] <= compare) {
				i++;
			}
			if (i < j) {
				std::cout << j + 1 << "��" << in_arr[j] << "��" << i + 1 << "��" << in_arr[i] << "�滻��" << std::endl;
				in_arr[j--] = in_arr[i];
				std::cout << "�滻�����飺";
				arr_print(in_arr, size);
			}
		}
		in_arr[i] = compare;
		quickSort(in_arr, l, i - 1, size);
		quickSort(in_arr, i + 1, r, size);
	}
}

//ѡ������
/*
��һ�ִ�������ɨ�裬��¼��СԪ��λ���±꣬ɨ����ɺ��滻δ����������Ԫ�أ���Ϊ���������飬
��һ��ɨ���δ���������ظ�����������
*/
void selectSort(int* in_arr, int size) {
	for (int i = 0; i < size -1; i++) {
		int min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (in_arr[j] < in_arr[min_index]) {
				min_index = j;
			}
		}
		std::cout << min_index + 1 << ":" << in_arr[min_index] << "��" << i + 1 << ":" << in_arr[i] << "����λ�á�" << std::endl;
		int temp = in_arr[i];
		in_arr[i] = in_arr[min_index];
		in_arr[min_index] = temp;
	}
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
		//heapOfLeftArr(in_arr, 0, size, maxsize);
		heapBuild(in_arr, size);
	}
}

//�鲢��������ϲ�����
void merge(int* arr, int low, int mid, int high, int size) {
	int *temp = new int[size]();
	int leftArr = low;
	int rightArr = mid + 1;
	int k = low;
	while (leftArr <= mid && rightArr <= high) {
		if (arr[leftArr] < arr[rightArr]) {
			temp[k++] = arr[leftArr++];
		}
		else {
			temp[k++] = arr[rightArr++];
		}
	}
	while (leftArr <= mid) {
		temp[k++] = arr[leftArr++];
	}
	while (rightArr <= high) {
		temp[k++] = arr[rightArr++];
	}
	while (low <= high) {
		arr[low] = temp[low++];
	}
}

//�鲢�����ڲ�����
void internalSort(int* arr, int left, int right, int size) {
	if (left < right) {
		int middle = (left + right) / 2;
		internalSort(arr, left, middle, size);
		internalSort(arr, middle + 1, right, size);
		merge(arr, left, middle, right, size);
	}
}

//�鲢����
void mergeSort(int* arr, int size) {
	internalSort(arr, 0, size - 1, size);
}

int main()
{
	int in_arr[10] = {};
	int arr_size = 10;
	srand((unsigned)time(NULL));
	for (int i = 0; i < arr_size; i++) {
		in_arr[i] = (rand() % 100);
	}
	arr_print(in_arr, arr_size);
	straightInsertSort(in_arr, arr_size);
	//shellSort(in_arr, arr_size);
	//bubbleSort(in_arr, arr_size);
	//quickSort(in_arr, 0, arr_size - 1, arr_size);
	//selectSort(in_arr, arr_size);
	//heapBuild(in_arr, 0, arr_size);
	//heapBuild(in_arr, arr_size);
	//heapOfLeftArr(in_arr, 0, arr_size);
	heapSort(in_arr, arr_size);
	//mergeSort(in_arr, arr_size);
	std::cout << std::endl << "������������" << std::endl;
	arr_print(in_arr, arr_size);
}