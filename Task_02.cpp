// Task 02:  có n đồ vật, vật thứ i có trọng lượng Ai và giá trị Bi. 
// Hãy chọn ra một số các đồ vật, mỗi vật một cái để xếp vào 1 vali có trọng lượng tối đa W 
// sao cho tổng giá trị của vali là lớn nhất.

#include <iostream>
#include<vector>
#define MAX 100
using namespace std;

void input(vector<int>&, vector<int>&, int&, int&);
int max(int, int);
int maxValue(vector<int>, vector<int>, int, int);


int main()
{
    int n, W;
    vector<int> val;
    vector<int> wei;
    input(val, wei, n, W);

    cout << "Max value: " << maxValue(val, wei, n, W) << endl;
    return 0; 
}

void input(vector<int>& val,vector<int>& wei, int& n, int& W) {
    n = 5;
    wei = { 7,10,2,3,1 };
    val = { 2,8,4,3,6 };
    W = 19;
}

int maxValue(vector<int> val, vector<int> wei, int n, int W) {
    int maxV[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = W; j >= 0; --j) {
            if (wei[i] <= j)
                maxV[i][j] = val[i]; //với từng vật i, giá trị maxV tại dòng nếu chứa vừa thì gán = val[i] 
            else
                maxV[i][j] = 0; //nếu không chứa vừa thì gán = 0
        }
    }

    //duyệt từ vật thứ 2 <=> i=1; vì maxV của vật đầu tiên đã được gán. Hay i=0 chỉ có 1 vật nên chỉ mang giá trị 0 hoặc val[0]
    for (int i = 1; i < n; i++) { // Bắt đầu tính toán khi có 2 vật trở lên
        for (int j = 1; j <= W; j++) { //chạy từ 1 đến W
            if(wei[i-1]<j){ //trường hợp vật trước đó nhẹ hơn <=> có thể thêm vào balo hoặc không
                if (wei[i - 1] + wei[i] > j) //trường hợp không thể cộng dồn vì vượt quá W
                    maxV[i][j] = max(maxV[i - 1][j], maxV[i][j]); //thì chỉ cần so sánh trên và dưới để tìm được trường hợp val lớn hơn
                else //trường hợp có thể cộng dồn
                    maxV[i][j] = max(maxV[i - 1][j], maxV[i][j] + maxV[i - 1][j - wei[i]]);
            }
            //****Giải thích****
            //maxV[i -1][j]: các maxV của dòng phía trên luôn là value_max [tại thời điểm xét i-1<->tại khối lượng đang xét j]
            //maxV[i][j] + maxV[i - 1][j - wei[i]]:
            //  (1) maxV[i][j] --> value của vật đang xét
            //  (2) maxV[i - 1][j - wei[i]] --> val_max của khối lượng bị dư ra. Lấy từ dòng phía trên.
            //==>Bởi vì các dòng phía trên đã được tính toán, nên tại mỗi j luôn là value_max 
            //      ==> nên ta chỉ cần xét giữa [i] với [i-1]
            else //nếu vật trước nặng hơn <=> không thể thêm vào balo
                maxV[i][j] = max(maxV[i - 1][j], maxV[i][j]);
        }
    }

    /*for (int i = 0; i < n; i++) {
        cout << endl;
        for (int j = 0; j <= W; j++) {
            cout << maxV[i][j] << "\t";
        }
    }*/
    return maxV[n - 1][W];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
