//Cho một bảng nRows*nCols mô phỏng cho chi phí đường lộ đi từ điểm xuất phát đến điểm đích.
//Một xe hơi cần đi từ điểm trên cùng bền trái (xuất phát) đến điểm dưới cùng bên phải (đích).
//Mỗi ô chứa một giá trị là chi phí.
//Tìm đường đi cho ô tô sao cho chi phí di chuyển là ít nhất.
//Ô tô chỉ có thể di chuyển qua phải hoặc xuống dưới.

#include <iostream>
#include <limits>
#include <map>
#include<algorithm>
#include <vector>
using namespace std;

void input(float[][100], int);
void output(float[][100], int);
float ways(float[][100], int, map<pair<int, int>, float>&, int, int);
float count(float[][100], int);
float min(float, float);


int main()
{
    float arr[100][100];
    int n = 4;
    input(arr, n);
    output(arr, n);
    cout << "Cach di chuyen: " << count(arr, n);
    return 0;
}

void input(float arr[][100], int n) {
    //để tiết kiệm thời gian trong việc test, tạo sẵn giá trị cho mảng.
    //Lưu ý: thay đổi giá trị n tương ứng tại main()
    float temp[] = {1,2,1,5,
                    1,3,1,4,
                    2,2,3,2,
                    2,1,4,1}; 
    int x = 0;
    for (int rows = 0; rows < n; rows++)
        for (int cols = 0; cols < n; cols++) {
            arr[rows][cols] = temp[x];
            x++;
        }
}

void output(float arr[][100], int n) {
    for (int rows = 0; rows < n; rows++) {
        for (int cols = 0; cols < n; cols++)
            cout << arr[rows][cols] << "\t";
        cout << endl;
    }
}

float count(float arr[][100], int n) {
    int c = 0, r = 0;
    map<pair<int, int>, float> check{};
    return ways(arr, n, check, r, c);
}

float ways(float arr[][100], int n, map<pair<int, int>, float>& check, int r, int c) {
    
    if (r == n || c == n)
        return numeric_limits<float>::infinity();
    if (r == (n - 1) && c == (n - 1))
        return arr[r][c];
    map<pair<int, int>, float>::const_iterator it = check.find(make_pair(r, c)); //it: lưu vị trí của pair{r,c}
    if (it == check.end()) { //nếu duyệt đến cuối vấn chưa xác định đc vị trí <==> chưa tính chi phí tại pair{}
        check[{r, c}] = arr[r][c] + min(ways(arr, n, check, r + 1, c), ways(arr, n, check, r, c + 1));
    }
    return check[{r, c}];
}

float min(float a, float b) {
    if (a < b)
        return a;
    else return b;
}