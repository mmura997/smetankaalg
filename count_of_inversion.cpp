#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mergesort(vector<ll> &mas, int left, int right) {
    if (left == right) {
        return (ll)0;
    }
    if (left == right - 1) {
        if (mas[left] > mas[right]) {
            swap(mas[left], mas[right]);
            return (ll)1;
        }
        return (ll)0;
    }
    int mid = left + (right - left) / 2;
    ll c = mergesort(mas, left, mid) + mergesort(mas, mid + 1, right);
    int l = left, r = mid + 1, i = 0, n = right - left + 1;
    ll count = (ll)(mid + 1 - left);
    vector<int> tmp(n);
    while (l <= mid || r <= right) {
        if (l > mid) {
            tmp[i] = mas[r];
            r++;
            c += count;
        } else if (r > right) {
            tmp[i] = mas[l];
            l++;
        } else if (mas[l] <= mas[r]) {
            tmp[i] = mas[l];
            l++;
            count--;
        } else {
            tmp[i] = mas[r];
            r++;
            c += count;
        }
        i++;
    }
    for (int i = 0; i < n; i++) {
        mas[left + i] = tmp[i];
    }
    return c;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l;
    cin >> n >> l;
    vector<ll> mas(n);
    for (int i = 0; i < n; ++i) {
        ll w;
        cin >> w;
        mas[i] = (ll)(((ll)l) * w + (ll)i);
    }
    int left = 0, right = n - 1;
    cout << mergesort(mas, left, right);
}
