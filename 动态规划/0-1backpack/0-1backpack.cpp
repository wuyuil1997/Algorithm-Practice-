#include<iostream>
#include<math.h>
int max(int a, int b) {
	return a > b ? a : b;
}

void bigEndian() {
	int i = 0x12345678;
	
	if ((*(char*)&i) == 0x12) {
		std::cout << "��˴洢" << std::endl;
	}
	else {
		std::cout << "С�˴洢" << std::endl;
	}
}
int main() {
	int w[5 + 1] = { 0, 2, 2 , 6, 5, 4 };
	int v[5 + 1] = { 0, 6, 3, 5, 4, 6 };
	int maxv = 10;
	int n = 5;
	int dp[5 + 1][10 + 1];

	/*
	int n;
	int maxv;
	std::cout << "�����ѡȡ��Ʒ������";
	std::cin >> n;
	std::cout << "���뱳�����������";
	std::cin >> maxv;
	int* w = new int[n + 1];
	int* v = new int[n + 1];

	int** dp = new int* [n + 1];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[maxv + 1];
	}

	//��ʼ����Ʒ
	for (int i = 1; i <=  n; i++) {
		std::cout << "��" << i  << "����Ʒ������";
		std::cin >> w[i];
		std::cout << "��" << i << "����Ʒ��ֵ��";
		std::cin >> v[i];
	}
	*/

	for (int i = 0; i <= maxv; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = maxv; j >= w[i]; j--) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	std::cout << "����ֵ��" << dp[n][maxv] << std::endl;
	//bigEndian();
	return 0;
}