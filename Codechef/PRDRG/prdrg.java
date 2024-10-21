import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	 public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();  

        while (T-- > 0) {
            int N = sc.nextInt(); 
            int num = 0, denum = 1;

            for (int n = 1; n <= N; n++) {
                num *= 2;
                denum *= 2;
                if (n % 2 == 1) {  
                    num += 1;
                } else {         
                    num -= 1;
                }
            }

            System.out.print(num + " " + denum + " ");
        }
        System.out.println();
        sc.close();
    }
}