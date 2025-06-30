// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    for(int i=0; i<mat.size(); i++){
        for(int j=i+1; j<mat[0].size(); j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    for(int i=0; i<mat.size(); i++){
        reverse(mat[i].begin(), mat[i].end());
    }
}
