//Cho arr ={...} laf chi phí từng bậc thang. Tìm chi phí thấp nhất để đi từ đầu đến cuối.
//Mỗi lần chỉ có thể bước 1 hoặc 2 bước.
//Chú ý: điểm xuất phát và đích không phải là phần tử đầu tiên hay cuối cùng.
// Xuất phát || 0 - 1 - 2 - 3 - ... - n || Đích


#include <iostream>
#include<vector>
#include<map>
using namespace std;

int cost(vector<int>);
int calculate(vector<int>, int, map<int, int>&);
int min(int, int);

int main()
{
    //vector<int> arr = { 1,20,1,1,1,20,1,1,20,1 };
    vector<int> arr = { 4,2,1,3,5,6,1,7,5 };
    cout << "Chi phi thap nhat: " << cost(arr);
    return 0;
}

int cost(vector<int> arr) {
    map<int, int> check{};
    return calculate(arr, arr.size()-1, check);
}

int calculate(vector<int> arr, int n, map<int, int>& check) {
    if (n == 0 || n == 1)
        return arr[n]; //trả về chi phí tại vị trí đó
    map<int, int>::const_iterator it = check.find(n);
    if (it == check.end()) { //tìm xem ví trí đó đã tính chi phí chưa
        //chưa thì Sum = (chi phí vị trí hiện tại) + (chi phí thấp hơn của 2 vị trí trước đó)
        check[n] = arr[n] + min(calculate(arr, n-1, check), calculate(arr, n-2, check));
    }
    return check[n]; //trả về chi phí
}

int min(int a, int b) {
    if (a < b)
        return a;
    else 
        return b;
}


