#define thinking

#define asg6_way1
#include <iostream>
#include <stdio.h>

#ifdef exp2_1
/* print 1~n */
int main() {
    int n,i;
    scanf("%d",&n);
    for(i = 1;i<=n;i++)
        printf("%d\n",i);
    return 0;
}
#endif

#ifdef exp2_2
/* aabb is perfect squares*/
int main(){
    for(int a = 1;a<10;a++)
        for(int b = 1;b<10;b++)
            if((a*100+b)%11)continue;
            else {
                for(int c = 1; c<10;c++)
                if(c*c==(a*100+b)/11)printf("%d\n",a*1100+b*11);}
    return 0;
}
#endif

#ifdef exp2_3
/* 3n+1 */
int main(){
    unsigned n,i;
    scanf("%u",&n);
    for( i = 0;n>1;i++){
        if(n%2)n=3*n+1;
        else n=n/2;
    }
    printf("%d\n",i);
    return 0;
}
#endif

#ifdef exp2_4
/*Approximation calculation*/
int main(){
    int i=1,c=1;
    double pi=0;
    do{
        pi += 1.0/c;
        i += 2;
        if(c>0)c = -i;
        else c = i;
    }while(i <1000000);
    printf("%lf",pi);
    return 0;
}
#endif

#ifdef exp2_5
/* sum of factorials*/
#include <time.h>
int main(){
    int n;
    long long unsigned sum=0;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        static int factorial = 1;
        factorial *= i;
        sum += factorial;
    }
    printf("%d\nTime used: %.2fs\n",sum%1000000,(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
#endif

#ifdef exp2_6
/* data statistics (file I/O)*/
int main(){
    int x,min,max,nums;
    float aver;
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    //      framework of fopen edition I/O
    //    FILE *fin,*fout;
    //    fin=fopen("data.in","rb");
    //    fout=fopen("data.out","wb");  //read&write use the binary way to operate
    //    scanf(fin,"%d",&x);
    //    printf(fout,"%d",x);
    //    fclose(fin);
    //    fclose(fout);                 //always remember to close file pointer in the end

    scanf("%d",&x);
    aver= min=max=x;
    nums=1;
    while(scanf("%d",&x)==1){
        if(x<min)min = x;
        if(x>max)max = x;
        aver=(aver*nums+x)/(nums+1);
        nums++;
    }
    printf("%d %d %.3f\n",min,max,aver);
    return 0;
}
#endif

#ifdef exp2_7
/* data statistics II */
int main(){
    int n,nums,Case=0;
    int min,max,sum,x;
    while(scanf("%d",&n)&&n){
        Case++;
        nums=n;
        n--;
        scanf("%d",&x);
        min=max=sum =x;
        while(n--){
            scanf("%d",&x);
            if(x<min)min=x;
            if(x>max)max=x;
            sum+=x;
        }
        printf("Case%d:%d %d %.3f\n",Case,min,max,sum/(float)nums);
    }
    return 0;
}
#endif

#ifdef asg1
/* 3 bit decimal daffodil */
int main(){
    int a ,b,c;
    for(a=1;a<10;a++)
        for(b=0;b<10;b++)
            for(c=0;c<10;c++){
                if(a*100+b*10+c==a*a*a+b*b*b+c*c*c)printf("%d\n",a*100+b*10+c);
            }
    return 0;
}
#endif

#ifdef asg2
/* hanxin */
int main (){
    int a,b,c,Case=0,nums;
    while(scanf("%d %d %d",&a,&b,&c)==3){
        Case++;
        if(a<0||a>2||b<0||b>4||c<0||c>6)printf("Case%d: No answer\n",Case);
        else
            for(nums=10;nums<=100;nums++){
                if(nums%3==a && nums%5==b && nums%7==c)
                {
                    printf("Case%d: %d\n",Case,nums);
                    break;
                }
                else if(nums==100)printf("Case%d: No answer\n",Case);
            }
    }
    return 0;
}
#endif

#ifdef asg3
/* triangle output */
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(int x=i;x>0;x--)printf(" ");
        for(int x = 2*n-1-2*i;x>0;x--)printf("#");
        printf("\n");
    }
    return 0;
}
#endif

#ifdef asg4
/* subsequence */
int main(){
    unsigned n,m;
    long long unsigned N,M;
    float sum;
    int Case=0;
    while(scanf("%u %u",&n,&m),n||m){
        if(n>m){
            n +=m;
            m =n-m;
            n -= m;
        }
        N = n;
        M = m;
        sum = 0;
        Case +=1;
        for(;N<=M;N++)sum += 1.0/N/N;
        printf("Case%d: %.5f\n",Case,sum);
    }
}
#endif

#ifdef asg5
/* decimal */
int main(){
    unsigned a,b,Case=0;
    char c;

#ifdef asg5_way1
    char *buffer,i,nums;
    unsigned INT;
#endif

    while(scanf("%u %u %d",&a,&b,&c),a||b||c){
        Case+=1;
#ifdef asg5_way1
        buffer = (char*)malloc(sizeof(char)*c+1);
        nums = 0;
        INT = a/b;
        do{
            a -= a/b*b;
            a *= 10;
            *(buffer+nums++) = a/b;
        }while(c--);
        if(*(buffer+ --nums)>=5){
            i = nums;
            while(i&&*(buffer+ --i)==9)*(buffer+i)=0;
            if(i)*(buffer+i)+=1;
            else if((*buffer+ i)==0) INT+=1;
        }
        printf("Case%d: %d.",Case,INT);
        for(i = 0; i<nums;i++)
            printf("%c",*(buffer+i)+'0');
        printf("\n");
#endif
#ifdef asg5_way2
        printf("Case%d: %.*f\n",Case,c,a/(float)b);
#endif
    }
    return 0;
}
#endif

#ifdef asg6
/* Permutation */
int main(){
#ifdef asg6_way1
    char a,b,c,d,e,f,g,h,i;
    for(a=1;a<10;a++)
        for(b = 1;b<10;b++){
            if(b==a)continue;
            for(c = 1;c<10;c++){
                if(c==b|| c==a)continue;
                for(d=1;d<10;d++){
                    if(d==b||d==c||d==a)continue;
                    for(e=1;e<10;e++){
                        if(e==a||e==b||e==c||e==d)continue;
                        for(f=1;f<10;f++){
                            if(f==a||f==b||f==c||f==d||f==e)continue;
                            for(g=1;g<10;g++){
                                if(g==a||g==b||g==c||g==d||g==e||g==f)continue;
                                for(h=1;h<10;h++){
                                    if(h==a||h==b||h==c||h==d||h==e||h==f||h==g)continue;
                                    for(i=1;i<10;i++){
                                        if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h)continue;
                                        if((a*100+b*10+c)*3 ==(g*100+h*10+i)&&(a*100+b*10+c)*2==(d*100+e*10+f))
                                            printf("%d%d%d %d%d%d %d%d%d\n",a,b,c,d,e,f,g,h,i);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
#endif
    return 0;
};
#endif

#ifdef thinking
int main(){
    double i;
    for(i=0;i!=10;i+=0.1)
        printf("%.1f\n",i);
    return 0;
}
#endif