#include <stdio.h>
#include <malloc.h>
#include <locale.h>

int check (int* b);
void division(int* a, int*b);
int module(int* a);

int main()
{
   printf("Программа находит результат деления числа a на число b, где a,b принадлежат целым числам\n");
   int* a = (int*)malloc(1*sizeof(int));
   *a = 0;
   int* b = (int*)malloc(1*sizeof(int));
   *b = 0;
   while (1){
      fflush(stdin);
      printf("Введите a: ");
      scanf("%d", a);
      fflush(stdin);
      printf("Введите b: ");
      scanf("%d", b);
      int proverka = 0;
      while (proverka == 0){
         proverka = check (b);
         if (proverka == 1) break;
         fflush(stdin);
         printf("Введите b: ");
         scanf("%d", b);
      }
      division(a,b);
   }
    return 0;
}

int check (int* b){
   if (*b == 0){
        printf("Число b не должно быть равно 0!\n");
        return 0;
   }else  return 1;
}

void division(int* a, int* b){
   int q = (*a)/(*b);
   int r = *a - *b*q;
   if (r<0 || *b<0&&r>module(b)){
      q = q<=0&&(*b)>0?(q-1):(q+1);
      r = *a - *b*q;
   }
   printf("Результат деления с остатком: %d=",*a);
   if(*b>0) printf("%d*",*b);
   else printf("(%d)*",*b);
   if(q>0) printf("%d+",q );
   else  printf("(%d)+",q );
   printf("%d\n",r );
}

int module(int* a){
   return *a>=0?(*a):(*a)*(-1);
}
