//Cho một số tiền S và các loại tiền arr = {a1,a2,...,an}
//Tìm cách đổi S từ các loại tiền có trong arr sao cho số tờ tiền là ít nhất.


#include <iostream>
#include <map>
#include <algorithm>
#include<vector>
using namespace std;

int change(int, vector<int>);
int used(int, vector<int>, map<pair<int, int>, int>&, vector<int>);
int min(int, int);

int main()
{
    int S = 34;
    vector<int> arr = { 7,3,1 };
    vector<int> count{};
    cout << "So doi it nhat: " << change(S, arr) << endl;
    for (int i = 0; i < count.size(); i++)
        cout << count[i] << "\t";

    return 0;
}

int change(int S, vector<int> arr) {
    map<pair<int, int>, int> check{};
    vector<int> count{};
    return used(S, arr, check, count);
}

int used(int S, vector<int> arr, map<pair<int, int>, int>& check,vector<int> count) {
    if (S == 0) {
        return count.size(); //nếu = 0 thì trả về số tờ tiền đã dùng
    }
    if (S < 0 || arr.size() == 0)
        return 999999;
    //return numeric_limits<int>::max(); //nếu không thì trả về vô cực
    map<pair<int, int>, int>::const_iterator it = check.find(make_pair(S, arr.size()));

    //Vì theo cây nhị phân, chúng ta có 2 giá trị cần lưu
    //1. Số lượng tiền đã dùng từ đầu cho đến node hiện tại
    //2. Số lượng tiền nhỏ nhất tại node đó đến node cuối cùng của nhánh đó.
    if (it != check.end()) {
        return (check[{S, arr.size()}] += count.size());
    }
    else { //nếu node đó chưa tính <=> chưa lưu vào map.
        int currentCount;
        vector<int> temp(arr);
        temp.pop_back();

        vector<int> temp2(count); //các tờ tiền đã dùng trước đó
        temp2.push_back(arr[arr.size() - 1]); //lưu tờ tiền dùng trong lần này

        //currentCount: số tiền dùng ít nhất tại nhánh hiện tại. (có nghĩa là min<=>từ node đó trở xuống)
        currentCount = min(used(S - arr[arr.size() - 1], arr, check, temp2), used(S, temp, check, count));
        //check[{S, arr.size()}]: Số tiền dùng từ node đó đến node<=>min phía trên
        check[{S, arr.size()}] = currentCount - count.size();
        return currentCount;
    }
    //Tóm gọn:
    //currentCount: chi phí nhỏ nhất từ node đó xuống dưới
    //count: chi phí đã dùng từ node đó lên đầu nhánh
    //==> Ráp 2 nhánh trên và dưới, ta có được toàn diện một nhánh từ đỉnh đến ngọn.
}


int min(int a, int b) {
    return (a < b) ? a : b;
}
