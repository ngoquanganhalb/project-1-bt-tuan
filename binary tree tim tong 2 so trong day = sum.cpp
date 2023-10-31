/*Description
Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

Dữ liệu
Dòng 1: ghi n và M (1 <= n, M <= 1000000)
Dòng 2: ghi a1, a2, ..., an
Kết quả
Ghi ra giá trị Q
Ví dụ
Dữ liệu
5 6
5 2 1 4 3
Kết quả
2*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
int cnt=0;
int binarySearch(set<int>& s, int target) {
    auto it = s.find(target);
    if (it != s.end()) {
        return target;
    }
    return -1;
}

int main() {
    int n, sum;
    cin >> n;
    cin >> sum;
    set<int> s;

    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        s.insert(b);
    }

    for (int x : s) {
        int complement = sum - x;
        int result = binarySearch(s, complement);
        if (result != -1) {
            cnt++;
        
        }
    }
    cout<< cnt;

    return 0;
}

//5 6
//5 2 1 4 3
