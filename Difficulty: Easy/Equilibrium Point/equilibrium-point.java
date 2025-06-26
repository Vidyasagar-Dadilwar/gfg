class Solution {
    // Function to find equilibrium point in the array.
    public static int findEquilibrium(int arr[]) {
        // code here
        int n = arr.length;

        int[] pre = new int[n];
        int[] suff = new int[n];

        pre[0] = arr[0];
        suff[n - 1] = arr[n - 1];

        for (int i = 1; i < n; i++) {
            pre[i] = arr[i] + pre[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            suff[i] = arr[i] + suff[i + 1];
        }

        for (int i = 0; i < n; i++) {
            if (pre[i] == suff[i]) {
                return i; // 0-based index
            }
        }

        return -1;
    }
}
