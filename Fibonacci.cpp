//Giải bào toán Fibonacci theo Quy hoạch động
#include <iostream>
using namespace std;

long Fibo(int);

int main()
{
    int n;
    do {
        cout << "Input n:";
        cin >> n;
    } while (n < 0);
    cout << "Fibonacci(" << n << ") = " << Fibo(n);
    return 0;
}

long Fibo(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    long first = 0, second = 1; //lưu 2 giá trị trước nó.

    for (int i = 2; i <= n; i++)
    {        
        //hoặc có thể sử dụng biến tạm
        long k = first;
        first = second;
        second = first + k;
    }
    return second;
}
