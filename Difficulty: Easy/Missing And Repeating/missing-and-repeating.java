// User function Template for Java

import java.util.ArrayList;

class Solution {
    // Function to find two elements in array
    ArrayList<Integer> findTwoElement(int arr[]) {
        int n = arr.length;
        int[] count = new int[n + 1];
        ArrayList<Integer> result = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) {
                result.add(i); // Repeating number
            }
        }

        for (int i = 1; i <= n; i++) {
            if (count[i] == 0) {
                result.add(i); // Missing number
            }
        }

        return result;
    }
}
