class Solution {
  public:
    void merge(vector<int>& arr, int l, int m, int h){
        int n1 = m-l+1, n2 = h-m;
        vector<int> L(n1), R(n2);
        
        for(int i=0; i<n1; i++)
            L[i] = arr[l+i];
        for(int i=0; i<n2; i++)
            R[i] = arr[m+i+1];
        
        int i=0, j=0, k=l;
        while(i<n1 && j<n2){
            if(L[i] < R[j])
                arr[k] = L[i++];
            else
                arr[k] = R[j++];
            k++;
        }
        while(i<n1)
            arr[k++] = L[i++];
        while(j<n2)
            arr[k++] = R[j++];
    }
    void mergeSort(vector<int>& arr, int l, int h){
        if(l < h){
            int m = l + (h - l)/2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, h);
            merge(arr, l, m , h);
        }
    }
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        mergeSort(arr, 0, arr.size()-1);
    }
};