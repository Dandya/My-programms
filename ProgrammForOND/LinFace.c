#include <stdio.h>
//-------------------------------------------------------------------
typedef struct{
    int num;
    int coef_1;
    int coef_2; 
} number;
//-------------------------------------------------------------------
number getGCD(number one, number two){
   if(one.num%two.num != 0){
      number first = one;
      int quotient = first.num/two.num;
      one = two;
      two.num = first.num%two.num;
      two.coef_1 = first.coef_1 - two.coef_1*quotient;
      two.coef_2 = first.coef_2 - two.coef_2*quotient;
      return getGCD(one,two);
   }else return two;
   printf("not ok\n");
}
//------------------------------------------------------------------
int main(int argc, char const *argv[]) {
   printf("Введите два числа, для которых хотите найти НОД\n");
   int sign_first = 1;
   int sign_second = 1;
   number first; first.num = 0; first.coef_1 = 1; first.coef_2 = 0;
   number second; second.num = 0; second.coef_1 = 0; second.coef_2 = 1; 
   number result; result.num = 0; 
   scanf("%d",&first.num);
   scanf("%d",&second.num);
   if (first.num<0){
      first.num*=-1;
      first.coef_1 = -1;
      sign_first = -1;
   }
   if (second.num<0){
      second.num*=-1;
      second.coef_2 =-1;
      sign_second = -1;
   } 
   if(first.num<second.num){
      first.num = first.num^second.num;
      second.num = first.num^second.num;
      first.num = first.num^second.num;
   }
   if(second.num == 0|| first.num == 0){
      printf("НОД = %d\n", second.num==0?first.num:second.num);
      return 0;
   }else if(second.num == 0&& first.num == 0){
      printf("НОД = %d\n", 0);
      return 0;
   }
   result = getGCD(first, second);
   printf("НОД\n%d = (%d)*(%d) + (%d)*(%d)\n", result.num, result.coef_1, first.num*sign_first, result.coef_2, second.num*sign_second );
   return 0;
}
