#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;



class Solution {
public:
    int FindDigit(int num) {
        int result = 0;
        while (num > 0) {
            result += num % 10;
            num /= 10;
        }
        return result;
    }
    int countSteps(int threshold, int rows, int cols, int i, int j, int* flag) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || flag[i * cols + j] == 1 || FindDigit(i) + FindDigit(j) > threshold) return 0; //�ýڵ㲻�����������Ҳ��ɸýڵ��������ڵ��ƶ���
        flag[i * cols + j] = 1; //�ýڵ��Ѿ�������
        return countSteps(threshold, rows, cols, i + 1, j, flag) + countSteps(threshold, rows, cols, i, j + 1, flag)
            + countSteps(threshold, rows, cols, i - 1, j, flag) + countSteps(threshold, rows, cols, i, j - 1, flag)
            + 1;
    }
    /*
    ������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
    ���ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� ���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
    ���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�*/
    int movingCount(int threshold, int rows, int cols)
    {
        int* flag = new int[rows * cols];
        return countSteps(threshold, rows, cols, 0, 0, flag);
    }
    /*
    �����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
    ·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
    ���һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ�
    */
    bool pathStep(int i, int j, int rows, int cols, int* flag, int pathLen, char* matrix, char* str) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || matrix[i * cols + j] != str[pathLen] || flag[i * cols + j] == 1) return false;
        flag[i * cols + j] = 1;
        if (pathLen == strlen(str) - 1)return true;
        if (pathStep(i + 1, j, rows, cols, flag, pathLen + 1, matrix, str) || pathStep(i, j + 1, rows, cols, flag, pathLen + 1, matrix, str)
            || pathStep(i - 1, j, rows, cols, flag, pathLen + 1, matrix, str) || pathStep(i, j - 1, rows, cols, flag, pathLen + 1, matrix, str)) {
            return true;
        }
        flag[i * cols + j] = 0;
        return false;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        int* flag = new int[strlen(matrix)]();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pathStep(i, j, rows, cols, flag, 0, matrix, str)) {
                    delete[] flag;
                    return true;
                }
            }
        }
        delete[] flag;
        return false;
    }

    /*
    ����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
    ���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ�
    ���ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� �������{2,3,4,2,6,2,5,1}�Ļ�������������6���� 
    {[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� {2,3,4,[2,6,2],5,1}�� 
    {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
    */
    int findMax(const vector<int>& num, int l, int r) {
        int maxNumIndex = l;
        for (int i = l + 1; i <= r; i++) {
            if (num[i] > num[maxNumIndex]) {
                maxNumIndex = i;
            }
        }
        return num[maxNumIndex];
    }
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {   
        vector<int> result;
        if (size == 0) {
            return result;
        }
        for (int i = 0; i < num.size() - size + 1; i++) {
            result.push_back(findMax(num, i, i + size - 1));
        }
        return result;
    }
};

int main() {
    Solution s1;
    //cout<<s1.movingCount(10, 1, 100);

    char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    int rows = 5;
    int cols = 8;
    char str[] = "SGGFIECVAASABCEHJIGQEM";
    //cout << s1.hasPath(matrix, rows, cols, str);

    const vector<int>& num = { 2,3,4,2,6,2,5,1 };
    int size = 3;
    vector<int> result = s1.maxInWindows(num, size);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}