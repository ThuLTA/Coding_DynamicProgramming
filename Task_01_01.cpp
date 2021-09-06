//Task 01: Tìm dãy con tăng dài nhất.
//Sử dụng hàm lower_bound()

#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int solution(vector<int>);

int main()
{
    vector<int> arr = { 4,1,2,3,4,2,7,5,3,6,1 };
    cout << "Res: " << solution(arr) << endl;
    return 0;
}

int solution(vector<int> arr) {
    //khởi tạo b[] lưu dãy con. Dãy b[] = {-infinity , infinity, ..., infinity}
    //khởi tạo infinity, vì:
    // --> mọi phần tử của arr đều lớn hơn -inf ==> trường hợp b[] chứa ít nhất 1 phần tử của arr
    // --> mọi phần tử của arr đền nhỏ hơn inf ==> trường hợp b[] chứa được nhiều nhất là toàn bộ arr
    vector<int> b(arr.size(), INT_MAX);
    b[0] = INT_MIN;

    int res = 0; //đếm phần tử
    for (int i = 0; i < arr.size(); i++) {
        int k = lower_bound(b.begin(), b.end(), arr[i]) - b.begin(); //trả về k=index với b[index]<=arr[i] (index từ: 1 ..n end())
        b[k] = arr[i]; //lưu phần tử của arr đang xét vào mảng tạm
        res = max(res, k); //so sánh res-index
    }
    return res;
    //res: tương ứng với index của đoạn chứa các phần tử con của arr <=> b[res-1] = max, b[res] = inf

    //****Giải thích***
    // arr = {...., 7 , ... , 4 , ...}
    // Ta thấy giữa đoạn (7 - 4) còn các giá trị khác.
    // 7 sẽ được thêm vào b[] trước, 4 thêm sau
    // (TH1): (7,N,...4) có chứa phần tử N > 7 ==> đoạn đoạn b[] = infi sẽ giảm, thay vào đó là giá trị N
    // (TH2): (7,M,...4) chứa M < 7 ==> đoạn b[] có thể giữ nguyên,b[k]=7 đổi thành b[k] = M.
    //      --> M và 7 đều thỏa mãn, ta chọn M vì nếu còn những phần tử M < ...< 7, ta có thể tăng b[] lên.
    //      ==> hay dễ hiểu, chọn phần tử nhỏ hơn, để tăng khả năng chứa cho b[]
}

int max(int a, int b) {
    return (a > b) ? a : b;
}