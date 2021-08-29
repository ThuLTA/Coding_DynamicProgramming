// SMK.cpp : Cho một dãy A gồm n số nguyên và một số nguyên dương k. 
//Hãy tìm một dãy con (không nhất thiết phải liên tiếp nhau) dài nhất có tổng các số chia hết cho số k.

#include <iostream>
#include<vector>
using namespace std;

void input(vector<int>&, int&, int&);
int max(int, int);
void SubarrayModk(vector<int>, int, int, vector<int>&);


int main()
{
    vector<int> arr, save;
    int n, k;
    input(arr, n, k);
    SubarrayModk(arr, n, k, save);
    cout << "Lenght of sub-array: " << save.size() << endl;
    for (int i = 0; i < save.size(); i++) {
        cout << save[i] << "\t";
    }
    cout << endl;
    return 0;
}

void input(vector<int>& arr, int& n, int& k) {
    arr = { 5,6,11,2,4,13,21,9,7 };
    //arr = { 5,6,11,2,4,9,7 };
    n = arr.size();
    k = 11;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void SubarrayModk(vector<int> arr, int n, int k, vector<int>& save) {
    /*int temp[100][100];*/
    int** temp = new int* [n];
    for (int i = 0; i < n; ++i)
        temp[i] = new int[k];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++)
            if (arr[i] % k == j)
                temp[i][j] = 1; 
            else
                temp[i][j] = 0;
    }
    //temp[][]: mảng lưu độ dài
    for (int i = 1; i < n; i++) {
        int r = arr[i] % k;
        for (int j = 0; j < k; j++) {
            if (temp[i - 1][(k - abs(j-r)) % k] > 0) 
                temp[i][j] = max(temp[i - 1][j], temp[i - 1][(k - abs(j-r)) % k] + 1);
            //
            //ta có tính chất: a mod k = x; b mod k = y ==> (a+b) mod k = (x+y) mod k
            // (-r) mod k = (-r+k) mod k ****Lưu ý: phép mod trong thực tế khác với hàm mod số nguyên của Visual
            else
                temp[i][j] = max(temp[i - 1][j], temp[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++)
            cout << temp[i][j] << "\t";
        cout << endl;
    }

    int j = n - 1;
    int flag = 0;
    //Max-res = temp[n-1][flag] vì:
    //  (+) n-1: xét duyệt toàn bộ arr, trường hợp tốt nhất là Max-res = arr.siize()
    //  (+) flag=0: vì ta lấy kết quả chia hết, nên mod = 0.
    while (j > 0) {
        int r = arr[j] % k;
        if ((temp[j - 1][(k -abs(flag - r)) % k]>0) && (temp[j][flag] > temp[j - 1][(k - abs(flag - r)) % k])) {
            save.push_back(arr[j]);
            j--;
            flag = (flag - r + k) % k;
        }
        else {
            j--;
        }
    }
    if (temp[0][flag] > 0)
        save.push_back(arr[0]);
}
