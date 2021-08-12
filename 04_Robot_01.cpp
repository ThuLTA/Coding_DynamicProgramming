//Cho một bảng nRows*nCols gồm các giá trị {0,1}
//    0 - Các ô trống
//    1 - Các ô có chướng ngại vật
//Robot mỗi lần chỉ có thể di chuyển xuống dưới hoặc qua phải. Không thể đi vào các ô có chướng ngại vật.
//Tìm số cách đi từ ô đầu dòng trên cùng bên trái đến ô cuối dòng dưới cùng bên phải.

//cách 2: dùng mảng phụ lưu lại các ô đã tính.

#include <iostream>
#include <map>
#include<algorithm>
#include <vector>
using namespace std;

void input(int[][100], int);
int ways(int[][100], int, map<pair<int, int>, int>&, int, int);
int count(int[][100], int);


int main()
{
    int arr[100][100], n = 5;
    input(arr, n);
    cout << "Cach di chuyen: " << count(arr, n);
    return 0;
}

void input(int arr[][100], int n) {
    //để tiết kiệm thời gian trong việc test, tạo sẵn giá trị cho mảng.
    //Lưu ý: thay đổi giá trị n tương ứng tại main()
    int temp[] = { 0,0,1,0,0,
                    1,0,0,0,0,
                    0,1,0,0,0,
                    0,0,0,0,0,
                    0,1,0,0,0 };
    int x = 0;
    for (int rows = 0; rows < n; rows++)
        for (int cols = 0; cols < n; cols++) {
            arr[rows][cols] = temp[x];
            x++;
        }
}

int count(int arr[][100], int n) {
    int c = 0, r = 0;
    map<pair<int, int>, int> check{};
    return ways(arr, n, check, r, c);
}

int ways(int arr[][100], int n, map<pair<int, int>, int>& check, int r, int c) {
    if (arr[r][c] == 1)
        return 0;
    if (r == n || c == n)
        return 0;
    if (r == (n - 1) && c == (n - 1) && arr[r][c] == 0)
        return 1;
    map<pair<int, int>, int>::const_iterator it = check.find(make_pair(r,c)); //it: lưu vị trí của pair{r,c}
    if (it == check.end()) { //nếu duyệt đến cuối vấn chưa xác định đc vị trí <==> chưa tồn tại pair{}
        check[{r, c}] = ways(arr, n, check, r + 1, c) + ways(arr, n, check, r, c + 1);
    }
    return check[{r,c}];
}