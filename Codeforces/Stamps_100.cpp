#include <iostream>
#include <string>

using namespace std;

void solve() {
    long long int n, pos = -1;
    string s;
    cin >> n >> s;

    for (long long int i = 0; i < n; i++) {
        if (s[i] == '1') {
            pos = i;
            break;
        }
    }

    if (pos == -1 || pos == (n - 1) || pos == (n - 2)) {
        cout << s << '\n';
    } else {
        for (long long int i = 0; i < pos; i++) {
            cout << 0;
        }
        cout << 1;
        for (long long int i = pos + 1; i < n; i++) {
            cout << 0;
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
