//Cho Số tiền S, các loại tiền arr = {a,b,c,...,n}. Tìm cách đổi S từ các loại tiền có trong arr.
/*Ví dụ: S=5, arr = {5, 2 ,1} ==> có 4 cách đổi.
    5 = 5
    5 = 2 + 2 + 1
    5 = 2 + 1 + 1 + 1
    5 = 1 + 1 + 1 + 1
*/

#include <iostream>
#include <map>
#include<algorithm>
#include <vector>
using namespace std;

int atm(int, vector<int>); //Cách 1: không lưu kết quả

int main()
{
    int S = 500;
    vector<int> arr = { 5,2,1 };
    /*do {
        cout << "S = ";
        cin >> S;*/
        cout << "So cach: " << atm(S, arr) << endl;
    //} while (S > 0);

    return 0;
}

int atm(int S, vector<int> arr) {
    if (S == 0) //Nếu sau khi đổi == 0 thì ++1 cách
        return 1;
    if (S < 0 || arr.size() == 0) //Nếu sau khi đổi bị âm tiền, hoặc hết tiền để đổi
        return 0;
    vector<int> temp;
    temp.assign(arr.begin(), arr.end() - 1); //temp là mảng không chứa phần tử cuối của arr
    return atm(S - arr[arr.size() - 1], arr) + atm(S, temp);
    //S - arr[arr.size() - 1] ==> S - số tiền tại phần tử cuối. Nếu còn trừ được thì tiếp tục sử dụng phần tử đó.
    //temp : trường hợp không sử dụng số tiền tại phần tử cuối. 
}