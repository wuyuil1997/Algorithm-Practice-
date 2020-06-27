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
        if (i < 0 || j < 0 || i >= rows || j >= cols || flag[i * cols + j] == 1 || FindDigit(i) + FindDigit(j) > threshold) return 0; //该节点不满足条件，且不可该节点向其他节点移动。
        flag[i * cols + j] = 1; //该节点已经被访问
        return countSteps(threshold, rows, cols, i + 1, j, flag) + countSteps(threshold, rows, cols, i, j + 1, flag)
            + countSteps(threshold, rows, cols, i - 1, j, flag) + countSteps(threshold, rows, cols, i, j - 1, flag)
            + 1;
    }
    /*
    地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
    但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
    但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？*/
    int movingCount(int threshold, int rows, int cols)
    {
        int* flag = new int[rows * cols];
        return countSteps(threshold, rows, cols, 0, 0, flag);
    }
    /*
    请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
    路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
    如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
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
    给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
    例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
    他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
    {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， 
    {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
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