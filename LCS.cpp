// Cho hai xâu ký tự. Tìm độ dài xâu con chung nhỏ nhất giữa chúng. 
//Ví dụ với 2 xâu “quetzalcoatl” và “tezcatlipoca” thì xâu con chung dài nhất sẽ là “ezaloa” với độ dài 6.

#include <iostream>
#include<string>
using namespace std;

int max(int, int);
void input(string&, string&);
void LongestCommonString(string, string, string&);

int main()
{
    string A, B;
    string save = "";
    int res;
    input(A, B);
    LongestCommonString(A, B, save);
    cout << "Size of Logest Common string is: " << save.size() << endl;
    cout << "LCS is: " << save << endl;
    
    return 0;
}

void input(string& A, string& B) {
    A = "adksbvmbyi gfd";
    B = "dncjkfihtbnmn dlk";
    A.erase(remove(A.begin(), A.end(), ' '), A.end());
    B.erase(remove(B.begin(), B.end(), ' '), B.end());
}
int max(int a, int b) {
    return (a > b) ? a : b;
}

void LongestCommonString(string A, string B, string& save) {
    int lA = A.size();
    int lB = B.size();

    //int temp[100][100];
    int** temp = new int* [lA+1];
    for (int i = 0; i < lA + 1; ++i)
        temp[i] = new int[lB+1];

    for (int i = 0; i <= lA; i++) {
        for (int j = 0; j <= lB; j++)
            if (i == 0 || j == 0)
                temp[i][j] = 0;
    }
    int res = 0;
    for (int i = 1; i <= lA; i++) {
        for (int j = 1; j <= lB; j++) {
            if (A[i-1] == B[j-1])
                temp[i][j] = temp[i - 1][j - 1] + 1;
            else {
                temp[i][j] = max(temp[i - 1][j], temp[i][j - 1]);
            }
        }
    }

    /*for (int i = 0; i <= lA; i++) {
        for (int j = 0; j <= lB; j++)
            cout << temp[i][j] << "\t";
        cout << endl;
    }*/
    res = temp[lA][lB];
    int i = lA;
    int j = lB;
    while (res > 0) {
        if (A[i-1] == B[j-1]) {
            //save += A[i-1];
            save = A[i - 1] + save;
            i--;
            j--;
            res--;
        }
        else
            if (temp[i][j-1] < temp[i-1][j])
                i--;
            else
                j--;
    }
}


