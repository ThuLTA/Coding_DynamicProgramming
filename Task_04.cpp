// Task 04: Cho n gói kẹo, gói thứ i có Ai viên. Hãy chia các gói thành 2 phần sao cho chênh lệch giữa 2 phần là ít nhất.

#include <iostream>
#include<vector>
#include<map>
using namespace std;

void input(vector<int>&, int&);
int caculate(vector<int>, int, int&, int[][100]);
void findsave(vector<int>,int[][100],vector<int>&, vector<int>&, int, int);
int max(int, int);

int main()
{
    int n, flag = 0;
    int temp[100][100];
    vector<int> candies, save1, save2;
    input(candies, n);
    int res = caculate(candies, n, flag, temp);
    cout << endl;
    cout << "Result: " << res << endl;
    findsave(candies, temp, save1, save2, res, flag);
    cout << "Day 1: ";
    for (int i = 0; i < save1.size(); i++)
        cout << candies[save1[i]] << "\t";
    cout << endl;
    cout << "Day 2: ";
    for (int i = 0; i < save2.size(); i++)
        cout << candies[save2[i]] << "\t";
    cout << endl;
    return 0;
}

void input(vector<int>& candies, int& n) {
    //candies = { 2,9,6,3,4,5};
    //candies = { 5,11,9,6,8,4,1,7 };
    candies = { 5,6,4};
    n = candies.size();
}
//save1: lưu phần kẹo I
//save2: lưu phần kẹo II
int caculate(vector<int> candies, int n, int& flag, int temp[][100]) {
    int S = 0;
    for (int i = 0; i < n; i++)
        S += candies[i];
    S /= 2; //Trường hợp tốt nhất là 2 phần bằng nhau
    if(n>2) {
        //int temp[100][100];
        for (int i = 0; i < n; i++)
            for (int j = 1; j < S + 1; j++) {
                if (j < candies[i])
                    temp[i][j] = 0;
                else
                    temp[i][j] = candies[i];
            }

        int maxT = 0;
        flag = n - 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= S; j++) {
                if (candies[i] < j)
                    temp[i][j] = max(temp[i - 1][j], candies[i] + temp[i - 1][j - candies[i]]);
                else
                    temp[i][j] = max(temp[i][j], temp[i - 1][j]);
                maxT = max(maxT, temp[i][j]);
            }

            if (maxT == S) { //nếu maxT rơi vào trường hợp tố nhất thì thoát.
                flag = i;
                break;
            }
        }//không thì lấy kết quả tại temp[n-1][S]
      //print
        //for (int i = 0; i < n; i++) {
        //    cout << endl;
        //    for (int j = 1; j <= S; j++) {
        //        cout << temp[i][j] << "\t";
        //    }
        //}
        //cout << endl;
        return maxT;
    }
    else
        return candies[0];
}

void findsave(vector<int> candies, int temp[][100], vector<int>& save1, vector<int>& save2, int res, int flag) {
    //flag: vị trí tại max

    if (candies.size() > 2) {
        while (res > 0) {
            for (int i = 0; i <= flag; i++) {
                if (temp[i][res] == res) {
                    save1.push_back(i);
                    flag = i - 1;
                    res -= candies[i];
                    break;
                }
            }
        }

        for (int i = 0; i < candies.size(); i++) {
            vector<int>::const_iterator it = find(save1.begin(), save1.end(), i);
            if (it == save1.end())
                save2.push_back(i);
        }
    }
    else {
        save1.push_back(0);
        if (candies.size() == 2)
            save2.push_back(1);
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

