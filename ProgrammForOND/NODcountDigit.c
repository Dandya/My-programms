#include <stdio.h>
#include <malloc.h>
int AlgorEvklida(int one, int two){
   while(1){
      if(one%two != 0 && one>two) one = one%two;
      else if (two%one != 0 && two>one) two = two%one;
      else if (one%two==0 && one>=two) return two;
      else if (two%one ==0 && two>=one) return one;
   }

   printf("not ok\n");
}
int main(int argc, char const *argv[]) {
   printf("Введите количество чисел\n");
   int count = 0;
   scanf("%d",&count);
   printf("Введите числа, для которых надо найти НОД\n");
   int Result = 0;
   scanf("%d",&Result);
   if (Result<0) Result*=-1;
   for(int i = 1; i<count; i++){
      int number = 0;
      scanf("%d",&number);
      if(number<0) number*=-1;
      Result=AlgorEvklida(Result,number);
   }
   printf("НОД = %d\n", Result);

   return 0;
}
