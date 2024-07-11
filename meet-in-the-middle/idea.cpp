#include <bits/stdc++.h>
using namespace std;

vector<int> generate(vector<int> arr);

long long count(vector<int> arr, int x) {
    long long ans = 0;
    vector<int> newArr[2];
    for (int i = 0; i < arr.size(); i++) {
        newArr[i & 1].push_back(arr[i]);
    }
    vector<int> sub0 = generate(newArr[0]);
    vector<int> sub1 = generate(newArr[1]);
    for (auto v : sub0) {
        ans += upper_bound(sub1.begin(), sub1.end(), x - v) - sub1.begin();
    }
    return ans;
}

vector<int> generate(vector<int> arr) {
    int n = arr.size();
    vector<int> subval;
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if ((mask >> j) & 1) {
                sum += arr[j];
            }
        }
        subval.push_back(sum);
    }
    sort(subval.begin(), subval.end());
    return subval;
}

int main() {
    // Test case 1
    vector<int> arr1 = {1, 2, 3, 4};
    int x1 = 5;
    cout << "Count of subarrays with sum <= " << x1 << " is: " << count(arr1, x1) << endl;

    return 0;
}
