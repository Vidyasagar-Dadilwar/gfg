// User function Template for Java
class Solution {
    public static long divide(long dividend, long divisor) {
     if(dividend==0)
     return 0;
    int sign=((dividend<0)^(divisor<0))?-1:1;
  long a=Math.abs(dividend);
   long b=Math.abs(divisor);
    long quotient=0;
    while(a>=b)
    {
       long temp=b,multiple=1;
       while(a>=(temp<<1))
       {
           temp<<=1;
           multiple<<=1;
       }
       a-=temp;
       quotient+=multiple;
       
    }
    return quotient*sign;
    }
}

