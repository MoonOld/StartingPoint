#include <stdio.h>
#define way1
int main(){
    int a,b,c,buf;
    #ifdef way1
    if(a<b)
        if(a<c)
            if(b<c)printf("%d %d %d\n",a,b,c);
            else printf("%d %d %d\n",a,c,b);
        else printf("%d %d %d\n",c,a,b);
    else{
        if(b<c)
            if(a<c)printf("%d %d %d\n",b,a,c);
            else printf("%d %d %d\n",b,c,a);
        else if(b<c)printf("%d %d %d\n",c,b,a);
    }
    #endif

    #ifdef way2
    if(a>b){
        buf = a;
        a = b;
        b = buf;
    }
    if(b>c){
        if(a>c){
            buf = a;
            a = c;
            c = buf; 
        }
        else {
            buf = b;
            b = c;
            c = buf;
        }
    }
    printf("%d %d %d\n",a,b,c);
    #endif
    return 0;
}