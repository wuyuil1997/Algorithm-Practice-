//基本排序算法练习
#include<iostream>
#include<time.h>

//打印数组
void arr_print(int in_arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ":" << in_arr[i] << ' ';
	}
	std::cout << std::endl;
}

//直接插入排序
/*
稳定排序
最开始认定待排序数组中第一个元素为已排序，且将之视为一个数组，从已排序元素数组向后依次扫描，
每扫描一个元素，找到其在已排序数组中应该插入的位置，插入（其他元素后移），扫描完整个待排序数组后，
排序完毕。
*/
void straightInsertSort(int* in_arr, int size)
{
	for (int i = 1; i < size; i++) {
		std::cout << "当前位置：" << i + 1 << std::endl;
		int pos_insert = 0;
		bool mark_insert = false;
		for (int j = 0; j < i; j++) {
			//认定第一个数字为已排序序列，从第二个位置开始，在已排序数组中扫描，找到适当位置插入。
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
			std::cout << i + 1 << "号位数字插入位置：" << pos_insert + 1 << std::endl;
			int insert_num = in_arr[i];
			for (int k = i; k > pos_insert; k--) {
				in_arr[k] = in_arr[k - 1];
			}
			in_arr[pos_insert] = insert_num;
			std::cout << "插入后数组：";
			arr_print(in_arr, size);
		}
		else {
			std::cout << "该位置数字为已排列数组中最大值，不执行插入操作。" << std::endl;
		}
	}
}

//希尔排序
/*
不稳定排序
分组插入排序，将数组分为间隔为N的len/N个数组，每个数组进行直接插入排序，此后N逐渐减少至1，
每次间隔减少，都再次对得到的每个数组进行直接插入排序。
*/
void shellSort(int* in_arr, int size) {
	int len = size / 2;
	while (len >= 1) {
		for (int i = 0; i < len; i++) {
			std::cout << "当前位置：" << i + 1 << std::endl;
			int pos_insert = 0;
			bool mark_insert = false;
			for (int j = i + len; j < size; j += len) {
				std::cout << "比较位置：" << j + 1 << std::endl;
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
					std::cout << i + 1 << "号位数字插入位置：" << pos_insert + 1 << std::endl;
					int insert_num = in_arr[j];
					for (int k = j; k > pos_insert; k -= len) {
						in_arr[k] = in_arr[k - len];
					}
					in_arr[pos_insert] = insert_num;
					std::cout << "插入后数组：";
					arr_print(in_arr, size);
				}
				else {
					std::cout << "该位置数字为已排列数组中最大值，不执行插入操作。" << std::endl;
				}
			}
		}
		len /= 2;
	}
}

//冒泡排序
/*
稳定排序
每一轮扫描数组，依次对比相邻元素的大小，将较大值交换到右侧（下标大位置），类似冒泡现象。
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

//快速排序
/*
第一次排序，找到一个基准数（通常为数组首元素），
1、从数组尾部向首部扫描，找到第一个比基准数小的元素，替换基准数位置，右指针指向元素原位置
2、然后从数组首部向尾部扫描，找到第一个比基准数大的元素，替换上述的替换操作留下的位置，左指针指向元素原位置。
3、从1中替换元素位置开始重复1的操作，从2中替换元素位置重复2的操作，直到左边指针大于右边指针。
4、第一轮排序完毕，数组分为两个待排序数组，对这两个数组重复1-3的操作。
*/

void quickSort(int* in_arr, int l, int r, int size) {
	if (l < r) {
		int i = l, j = r, compare = in_arr[l];
		std::cout << "基准数:" << compare << std::endl;
		while (i < j) {
			//从右往左扫描，小于基准数的数值被替换到基准数的左侧
			std::cout << "从右:" << j + 1 << "向左:" << i + 1 << "扫描。" << std::endl;
			while (i < j && in_arr[j] >= compare) {
				j--;
			}
			if (i < j) {
				std::cout << i + 1 << "：" << in_arr[i] << "被" << j + 1 << "：" << in_arr[j] << "替换。" << std::endl;
				in_arr[i++] = in_arr[j];
				std::cout << "替换后数组：";
				arr_print(in_arr, size);
			}
			//从左往右扫描，大于基准数的数值被替换到基准数的右侧
			std::cout << "从左:" << i + 1 << "向右:" << j + 1 << "扫描。" << std::endl;
			while (i < j && in_arr[i] <= compare) {
				i++;
			}
			if (i < j) {
				std::cout << j + 1 << "：" << in_arr[j] << "被" << i + 1 << "：" << in_arr[i] << "替换。" << std::endl;
				in_arr[j--] = in_arr[i];
				std::cout << "替换后数组：";
				arr_print(in_arr, size);
			}
		}
		in_arr[i] = compare;
		quickSort(in_arr, l, i - 1, size);
		quickSort(in_arr, i + 1, r, size);
	}
}

//选择排序
/*
第一轮从左向右扫描，记录最小元素位置下标，扫描完成后，替换未排序数组首元素，作为已排序数组，
下一轮扫描从未排序数组重复上述操作。
*/
void selectSort(int* in_arr, int size) {
	for (int i = 0; i < size -1; i++) {
		int min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (in_arr[j] < in_arr[min_index]) {
				min_index = j;
			}
		}
		std::cout << min_index + 1 << ":" << in_arr[min_index] << "与" << i + 1 << ":" << in_arr[i] << "交换位置。" << std::endl;
		int temp = in_arr[i];
		in_arr[i] = in_arr[min_index];
		in_arr[min_index] = temp;
	}
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
		//heapOfLeftArr(in_arr, 0, size, maxsize);
		heapBuild(in_arr, size);
	}
}

//归并排序数组合并函数
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

//归并排序内部排序
void internalSort(int* arr, int left, int right, int size) {
	if (left < right) {
		int middle = (left + right) / 2;
		internalSort(arr, left, middle, size);
		internalSort(arr, middle + 1, right, size);
		merge(arr, left, middle, right, size);
	}
}

//归并排序
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
	std::cout << std::endl << "最终排序结果：" << std::endl;
	arr_print(in_arr, arr_size);
}