#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long n, m;

long long hashcode(const string& s, long long m) {
    long long k = s.length();
    long long h = 0;
    long long power = 1;

    for (long long j = 0; j < k; j++) {
        h = (h * 256 + s[j]) % m;
        power = (power * 256) % m;
    }

    return h;
}

int main() {
    cin >> n >> m;
    cin.ignore(1);
    vector<string> vs(n); // Store the input strings

    for (long long i = 0; i < n; i++) {
        getline(cin, vs[i]);
    }

    for (long long i = 0; i < n; i++) {
        cout << hashcode(vs[i], m) << endl;
    }

    return 0;
}
