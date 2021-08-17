//1 Task 01: Tìm dãy con tăng dài nhất.

#include <iostream>
#include<vector>
using namespace std;

vector<int> solution(vector<int>);

int main()
{
    vector<int> arr = { 4,1,2,5,3,7,7,8,6,9 };
    vector<int> temp = solution(arr);
    cout << endl;
    for (int i = 0; i < temp.size(); i++)
        cout << temp[i] << "\t";

    return 0;
}

vector<int> solution(vector<int> arr) {
    
    vector<int> length(arr.size(), 1); //khởi tạo vector tính độ dài tại mỗi điểm trên arr
    for (int i = 0; i < arr.size() - 1; ++i) {
        for (int j = i+1; j < arr.size(); ++j) { //xét các phần tử sau i
            if ((arr[i] < arr[j]) && (length[j] < length[i] + 1))
                length[j] = length[i] + 1;
        }
    }
    //(arr[i] < arr[j]) --> giá trị lớn hơn so với a[i] đang xét
    //(length[j] < length[i] + 1) --> chưa thuộc dãy nào có độ dài lớn hơn thì tạo dãy với a[i]

    cout << "Length: ";
    for (int i = 0; i < length.size(); i++)
        cout << length[i] << "\t";

    //in ra dãy con.
    vector<int> temp;
    int lmax = 1;
    for (int i = 1; i < length.size(); i++) {
        if (length[i] == lmax) {
            //temp.insert(temp.begin(),arr[i]);
            temp.push_back(arr[i]);
            lmax++;
        }
    }
    return temp;
}