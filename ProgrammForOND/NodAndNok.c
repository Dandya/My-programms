#include <stdio.h>

long long int getGCD(long long int one, long long int two){
   if(one%two != 0){
      long long int first = one;
      one = two;
      two = first%two;
      return getGCD(one,two);
   }else return two;
   printf("not ok\n");
}

long long int getLCM(long long int a, long long int b){
   long long int minus = 0;
   
   if (a<0&&b<0) minus = 1;
   else if (a<0^b<0) minus = -1;
   else minus = 1;
   
   if (a<0) a*=-1;
   if (b<0) b*=-1;
   if(a<b){
      a = a^b;
      b = a^b;
      a = a^b;
   }
   long long int result = getGCD(a,b);
   printf("NOD = %ld\t", result);
   return minus*a*b/result;
}

int main(int argc, char const *argv[]) {
   printf("Input two numbers\n");
   long long int first = 0;
   long long int second = 0;
   scanf("%ld",&first);
   scanf("%ld",&second);
   if(second == 0|| first == 0){
      printf("NOK = 0\n");
      return 0;
   }
   printf("NOK = %ld\n", getLCM(first,second));
   return 0;
}
