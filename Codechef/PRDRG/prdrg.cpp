#include <bits/stdc++.h>
using namespace std;

/*
 * The main difficulty of the problem is to understand it!
 * Take a sheet of paper, fold it exactly as described, and
 *   write each time in the back side the number of the current folding.
 * Report them in the front end, like this:
 * |       | | |   |               |
 * 0       2 4 3   1                
 * ----------------                  length: 1/2
 *          --------                         1/4
 *         ----                              1/8
 *            --                             1/16
 * Once the problem understood, we can see that the width
 *   is divided by two each time, once in left, once in the right...
 * As we fold left first and the ridge moves right with first n (1 is odd)
 *   the init ridge is 0
 */

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int T, N; cin >> T;
  while(T--) {
    cin >> N;
    int num = 0, denum = 1, width;
    for(int n = 1; n<=N; n++) {
      num *= 2;
      denum *= 2;
      if(n%2==1) // fold left
        num += 1;
      else       // fold right
        num -= 1;
    }
    cout << num << ' ' << denum << ' ';
  }
  cout << endl;
}