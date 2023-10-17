#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    while (q--) {
        int x;
        cin >> x;
        int l = 0, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (numbers[mid] > x) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (numbers[l] == x) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
