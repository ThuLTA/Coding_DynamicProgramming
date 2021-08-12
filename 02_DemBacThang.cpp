//Chỉ có thể bước 1 hoặc 2 bước, hỏi có bao nhiêu cách bước khác nhau với số bậc thang n;
//********Phân tích*********
/*
    với n = 10
        (+) Nếu bước lùi 1b thì còn 9
        (+) Nếu lùi 2b thì còn 8
            ==> n=10 sẽ là tổng của số cách bước 8 bậc thang và 9 bậc thang
    Tương tự, n=9
        (+) Lùi 1b còn 8
        (+) Lùi 2b còn 7
            ==> n = 9 sẽ là tổng cách bước 8 và 7 bậc.
    Với n = 8, tượng tự là tổng (7) và (6)
        ==> Nhận thấy 8 đã được tính trên n=9, ta sẽ sử dụng lại kết quả.


*/

#include <iostream>
#include <map>
using namespace std;

long dembacthang(int, map<int,long>&);
void print_map(map<int, long>);

int main()
{
    int n;
    map<int, long> arr = { {0,0}, {1,1} };
    do {
        cout << "Input n:";
        cin >> n;
        cout << "So cach tuong ung voi " << n << " bac thang: " << dembacthang(n, arr) << endl;
    } while (n > 0);

    //cout << "So cach tuong ung voi " << n << " bac thang: " << dembacthang(n, arr) << endl;
    print_map(arr);
    return 0;
    
}

long dembacthang(int n, map<int,long> &arr) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    if (arr[n] == 0) { //Nếu chưa tính số cách bước tại bậc thang n (bậc thang hiện tại).
        //thì thực hiện tính bằng cách tính tổng số cách của n-1, và n-2
        arr[n] = dembacthang(n - 1, arr) + dembacthang(n - 2, arr); 
    }

    return arr[n];
}

void print_map(map<int, long> arr) {
    for (auto const& x : arr) {
        std::cout << "{" << x.first << ": " << x.second << "}\n";
    }
}
