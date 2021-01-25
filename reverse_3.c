#include stdio.h
#define Zero
int main(){
    int a,b;
    scanf("%d",&a);
    #ifdef Zero
    printf("%d %d %d\n",a%10,a/10%10,a/100);
    #endif

    #ifdef NoZero
    b = a%10 *100+ a/10%10 *10 + a/100;
    printf("%d %d %d\n",b/100,b/10%10,b%10);
    #endif

    #ifdef otherway
    b = a%10 *100+ a/10%10 *10 + a/100;
    printf("%03d\n",b);
    #endif

    return 0;
}