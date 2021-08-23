// Task 03: Cho dãy A1,A2,…,An. Tìm một dãy con của dãy đó có tổng bằng S
//Cách giải với S!=0
//S=0 chưa có biết!!!!!

//Trường hợp arr chỉ tồn tại giá trị > 0

#include <iostream>
#include<vector>
#include<map>
using namespace std;

void input(vector<int>&, int&, int&);
vector<int> findsave(vector<int>, int, int);
bool caculate(vector<int>, int, int, int&, int[][100]);
int max(int, int);

int main()
{
    int n, S = 0;
    vector<int> arr, save{};
    input(arr, n, S);

    if (S == 0 && find(arr.begin(), arr.end(), 0) == arr.end())
        cout << "NOT FOUND SUB-ARRAY!!!!"<<endl;
    else {
        cout << "FOUND SUB-ARRAY!!!!" << endl;
        if (S == 0)
            cout << arr[find(arr.begin(), arr.end(), 0) - arr.begin()];
        else {
            save = findsave(arr, n, S);
            for (int i = 0; i < save.size(); i++)
                cout << arr[save[i]] << "\t";
        }
    }
    cout << endl;
    return 0;
}

void input(vector<int>& arr, int& n, int& S) {
    arr = { 2,9,6,3,0,5};
    n = arr.size();
    S = 8;
}
vector<int> findsave(vector<int> arr, int n, int S) {
    vector<int> save{};
    int flag;
    int temp[100][100];
    bool res = caculate(arr, n, S, flag, temp);
    if (res) {
        while (S > 0) {
            for (int i = 0; i <= flag; i++) {
                if (temp[i][S] == S) {
                    save.push_back(i);
                    flag = i - 1;
                    S -= arr[i];
                    break;
                }
            }
        }
    }
    return save;
}
bool caculate(vector<int> arr, int n, int S, int& flag, int temp[][100]) {
    bool res = false;
    
    if (n > 0) {
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= S; j++) {
                if (j < arr[i])
                    temp[i][j] = 0;
                else
                    temp[i][j] = arr[i];
            }

        int sum = 0;
        flag = n - 1;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= S; j++) {
                if (arr[i] < j)
                    temp[i][j] = max(temp[i - 1][j], arr[i] + temp[i - 1][j - arr[i]]);
                else
                    temp[i][j] = max(temp[i][j], temp[i - 1][j]);
                sum = max(sum, temp[i][j]);
            }

            if (sum == S) { //nếu sum=S thì không cần tính đến cuối
                flag = i;
                return true;
            }
        }

        //print
          /*for (int i = 0; i < n; i++) {
              cout << endl;
              for (int j = 1; j <= S; j++) {
                  cout << temp[i][j] << "\t";
              }
          }*/
          cout << endl;
    }
    return res;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}

