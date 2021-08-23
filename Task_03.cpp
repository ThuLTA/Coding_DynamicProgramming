// Task 03: Cho dãy A1,A2,…,An. Tìm một dãy con của dãy đó có tổng bằng S
//Cách giải với S!=0
//S=0 chưa có biết!!!!!

//tính theo phương pháp cây nhị phân, để xét trường hợp arr tồn tại phần tử âm
//nếu arr chỉ tồn tại >0, dùng temp[][] giống task04

#include <iostream>
#include<vector>
#include<map>
using namespace std;

void input(vector<int>&, int&, int&);
void output(vector<int>, int, int);
bool caculate(vector<int>, int, int, map<pair<int, int>, bool>&);
int max(int, int);

int main()
{
    int n,S = 0;
    vector<int> arr;
    input(arr, n, S);
    output(arr,n,S);
    /*int res = caculate(arr, n, temp);
    cout << "Result: " << res << endl;*/
    return 0;
}

void input(vector<int>& arr, int& n, int& S) {
    //arr = { 2,9,6,3,4,5};
    arr = { 2,9,-1,12,-3,8 };
    n = arr.size();
    S = 0;
}

void output(vector<int> arr, int n, int S) {
    map<pair<int, int>, bool> check{};
    bool res = caculate(arr, n, S, check);
    if (res == true)
        cout << "FOUND!!!!!";
    else
        cout << "NOT FOUND!!!!!";
}


bool caculate(vector<int> arr, int n,int S,map<pair<int,int>,bool>& check) {
    if (S == 0)
        return true;
    if (n == 0 || S < 0)
        return false;
    map<pair<int, int>, bool>::const_iterator it_check = check.find(make_pair(n,S));
    if (it_check == check.end()) {
        vector<int> temp(arr);
        temp.erase(temp.begin());
        if (caculate(temp, n - 1, S - arr[0], check) || caculate(temp, n - 1, S, check))
            check[{n, S}] = true;
    }
    return check[{n, S}];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

