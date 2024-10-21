#include <iostream>
using namespace std;

int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int games = n*(n-1)/2;
    if (games%n!=0) printf("NO\n");
    else {
      printf("YES\n");
      int winPP = games/n;
      int m[n][n];
      int won[n];
      int cell;

      for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
          m[i][j] = -1;
        } 
        won[i] = 0;
      }
      
      for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
          if (i!=j) {
            if (m[i][j] == -1) {
              m[i][j] = won[i]<winPP?i:j;
              m[j][i] = won[i]<winPP?i:j;
              if (m[i][j] == i) won[i]++;
              else won[j]++;
            }
          }
        } 
      }

      for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
          cell = m[i][j];
          if (cell==i) printf("1");
          else printf("0");
        }
        printf("\n");
      }
      
    }
  }
}