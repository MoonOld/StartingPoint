#define UVa133
#include <iostream>
#include "math.h"

#ifdef eg4_1
/* combination numbers*/
int main() {
    unsigned long results=1;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = n;i>n-m;i--){
        results*=i;
    }
    for(int i = 1;i<=m;i++)results/=i;
    printf("%lu",results);
    return 0;
}
#endif

#ifdef eg4_2
/* isprime */
int main(){
    int n;
    scanf("%d",&n);
    if(n<5){
        switch (n) {
            case 2:
            case 3:{
                printf("%d Is a prime\n",n);
                return 0;
            }
            default:{
                printf("%d Is not a prime\n",n);
                return 0;
            }
        }
    }
    else {
        for(int i = 1;i<sqrt(n);i++){
            if(! (n%(6*i-1))||!(n%(6*i+1))  )
            {
                printf("%d Is not a prime\n",n);
                return 0;
            }
        }
    }
    printf("%d Is a prime\n",n);
    return 0;
}
#endif

#ifdef eg4_3
/* pointer swap */
int swap(int*,int*);
int main(){
    int a=2,b=3;
    swap(&a,&b);
    printf("%d %d\n",a,b);
    return 0;
}
int swap(int* a,int*b){
    int buf;
    buf = *a;
    *a = *b;
    *b = buf;
    return 0;
}
#endif

#ifdef eg4_4
/* calculate sum */
int getsum(int* ,int);
int main(){
    int nums[]={1,2,3,4,5,6,7,8,9,10};
    printf("Sum:%d\n",getsum(nums,sizeof(nums)/sizeof(int)));
    return 0;
}
int getsum(int* num,int length){
    int sum=0;
    while(length){
        sum+=*(num + --length);
    }
    return sum;
}
#endif

#ifdef UVa1339
/* Ancient Cipher */
int count(char* s,int* num);
int compare(int *num1,int *num2);
int sort(int *num);
int main()
{
    char s1[50],s2[50],*( s[2])={s1,s2};
    int count1[27],count2[27],*(Count[2])={count1,count2};
    memset(count1,0,sizeof(count1));
    memset(count2,0,sizeof(count2));
    scanf("%s %s",s1,s2);
    for(int i =0;i<2;i++){
        count(s[i],Count[i]);
        sort(Count[i]);
    }
    if(compare(Count[0],Count[1]))
        printf("Yes\n");
    else printf("No\n");
    return 0;
}
int count(char* s,int* num){
    while(*s){
        *(num+ *s++ - 'A')+=1;
    }
    return 0;
}
int sort(int *num){
    int buf;
    for(int i = 0;i<26;i++){
        for(int j = i+1;j<26;j++){
            if( *(num+j)>*(num+i)){
                buf = *(num+i);
                *(num+i)=*(num+j);
                *(num+j) = buf;
            }
        }
    }
    return 0;
}

int compare(int *num1,int *num2){
    while(*num1){
        if(*num1!=*num2)return 0;
        num1++;
        num2++;
    }
    return 1;
}

#endif

#ifdef UVa489
/* Hangman Judge */
enum{win,lose,chick};
int solve(char* a,char*b,int length){
    int i,delength=0;
    for(i=0;i<length;i++){
            if(*(a+i)==*b){
                *(a+i)=0;
                delength++;
            }
        }
    return delength?delength:-1;
}
int main(){
    char dst[20],buf[20];
    char const *s[3]={"You win.\n","You lose.\n","You chickened out.\n"};
    int life,game,length,Allength,buffer;
    while(scanf("%d %s %s",&game,dst,buf),~game){
        life = 7;
        Allength = length = strlen(dst);
        for(int i=0;i<strlen(buf)&&life;i++)
        {

            buffer = solve(dst, buf+i, Allength);
            if (buffer > 0)length -= buffer;
            else life--;
        }
        printf("Round %d:\n",game);
        if(life){
            if(length)printf("%s\n",s[chick]);
            else printf("%s\n",s[win]);
        }
        else {
            printf("%s\n",s[lose]);
        }
    }

    return 0;
}
#endif

#ifdef UVa133
/* The Dole Queue */
#define max 20
int main(){
    int n,k,m,num[20];
    scanf("%d %d %d",&n,&k,&m);
    for(int i =0;i<max,i++)num[i]=[i+1];


    return 0;
}
#endif