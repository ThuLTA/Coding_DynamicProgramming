//Cho một bảng nRows*nCols gồm các giá trị {0,1}
//    0 - Các ô trống
//    1 - Các ô có chướng ngại vật
//Robot mỗi lần chỉ có thể di chuyển xuống dưới hoặc qua phải. Không thể đi vào các ô có chướng ngại vật.
//Tìm số cách đi từ ô đầu dòng trên cùng bên trái đến ô cuối dòng dưới cùng bên phải.



#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

void input(int[][100], int);
int dem(int[][100], int, int, int);

int main()
{
    int arr[100][100], n=5;
    input(arr, n);
    cout << "Cach di chuyen: " << dem(arr, n, 0, 0);
    return 0;
}

void input(int arr[][100], int n) {
    int temp[] = {  0,0,1,0,0,
                    1,0,0,0,0,
                    0,1,0,0,0,
                    0,0,0,0,0,
                    0,1,0,0,0};
    int x = 0;
    for(int rows=0;rows<n;rows++)
        for (int cols = 0; cols < n; cols++) {
            arr[rows][cols] = temp[x];
            x++;
        }
}

int dem(int arr[][100], int n, int r, int c) {
    if (arr[r][c] == 1)
        return 0;
    if (r == n || c == n)
        return 0;
    if (r == (n - 1) && c == (n - 1) && arr[r][c] == 0)
        return 1;
    return dem(arr, n, r + 1, c) + dem(arr, n, r, c + 1);
}


