#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // ham check element trong arr da xuat hien hay chua, insert vao set sau moi lan lap
    for (int i = 0; i < n; ++i) {
        if (s.count(a[i])!=0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        s.insert(a[i]);
    }
    return 0;
}
