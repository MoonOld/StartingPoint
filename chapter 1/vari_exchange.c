#include stdio.h
#define way1
int main(){
    int a,b,c;
    scanf("%d %d",&a,&b);
    #ifdef way1
    c = a;
    a = b;
    b = c;
    printf("%d %d\n",a,b);
    #endif

    #ifdef way2
    printf("%d %d\n",b,a);
    #endif

    #ifdef way3
    a += b;
    b = a-b;
    a -= b;
    printf("%d %d\n",a,b);
    #endif
        #ifdef way
    #endif
    return 0;
}