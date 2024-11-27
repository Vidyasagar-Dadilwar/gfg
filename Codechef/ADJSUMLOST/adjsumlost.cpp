#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reconstruct_array(int t, vector<vector<int>>& test_cases) {
    for (int i = 0; i < t; ++i) {
        int n = test_cases[i][0]; // Size of array A
        vector<int> b(test_cases[i].begin() + 1, test_cases[i].end()); // Array B
        
        sort(b.begin(), b.end()); // Sort the shuffled array B

        // Create array A
        vector<int> a(n);

        // First element of A is the difference of the first two elements in sorted B
        a[0] = abs(b[0] - b[1]);

        // Compute the rest of the elements of A
        for (int j = 1; j < n - 1; ++j) {
            a[j] = abs(a[j - 1] - b[j]);
        }

        // Output the reconstructed array A
        for (int j = 0; j < n; ++j) {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;  // Number of test cases

    vector<vector<int>> test_cases(t);

    // Reading test cases
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;  
        test_cases[i].push_back(n);  
        for (int j = 0; j < n - 1; ++j) {
            int temp;
            cin >> temp;
            test_cases[i].push_back(temp); 
        }
    }

    reconstruct_array(t, test_cases);

    return 0;
}
