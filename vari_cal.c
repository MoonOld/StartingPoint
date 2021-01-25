#include stdio.h
#include math.h
#define exp1

#ifdef exp1
int main()
{
    float a,b;
    scanf("%f %f",&a,&b);
    printf("%f\n",a+b);
    return 0;
}
#endif

#ifdef area
int main(){
    float r,h;
    scanf("%f %f",&r,&h);
    printf("Area = %.3f\n",2*PI*r*r+2*PI*r*h);
}
#endif

