#include <stdio.h>
/* excecise 1: average*/
#ifdef exc1
int main(){
    int a ,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("%f\n",(a+b+c)/3.0);
    return 0;
}
#endif

/* excercise 2: temprature*/
#ifdef exc2
int main(){
    float f;
    scanf("%f",&f);
    printf("%f\n",5*(f-32)/9);
}
#endif

/* excercise 3: sum*/
#ifdef exc3
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",n*(n+1)/2);
    return 0;
}
#endif

/* excercise 4: sin&cos*/
#ifdef exc4
#include  <math.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n<360&&n>=0)
        printf("%f,%f\n",sin(n),cos(n));
    else printf("Wrong input\n");
    return 0;
}
#endif

/* excercise 5: discount*/
#ifdef exc5
int main(){
    int n;
    scanf("%d",&n);
    printf("%.2f\n",
    n*95>=300 ? n*95*0.85: n*95
    )
    return 0;
}
#endif

/* excercise 6: triangle*/
#ifdef exc6
int main(){
    int a,b,c;
    if(
        (c>a)?
        (c>b?(c*c==a*a+b*b):(b*b==c*c+a*a)):
        (a>b?(a*a==b*b+c*C):(b*b==c*c+a*a))
        /* to avoid to many if-elses use choice expression*/
    )printf("yes\n");
    else{
        if(c>(a-b>0? a-b:b-a) && c<a+b)printf("no\n");
        else printf("not a triangle\n");
    }
}
#endif

/* excercise 7: year*/
#ifdef exc7
int main(){
    int year;
    if(year%100){
        if(year%4)printf("no\n");
        else printf("yes\n");
    }
    else if(year%400)printf("no\n");
    else printf("yes\n");
}
#endif