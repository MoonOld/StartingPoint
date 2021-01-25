//exp1~4
#define exp1
#include stdio.h
int main(){
    printf("%f",
#ifdef exp1
3-4
#endif  
#ifdef exp2
5*6
#endif    
#ifdef exp3
8/4.0
#endif    
#ifdef exp4
8/5.0
#endif      
    )
    return 0;
}