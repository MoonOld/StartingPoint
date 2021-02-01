#define UVa512
#define UVa512_way1
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
    int n,k,m,num[20],a,b,afind,bfind,flag=1,kbuffer,mbuffer;
    memset(num,0,sizeof(num));
    scanf("%d %d %d",&n,&kbuffer,&mbuffer);
    a = 0;b = n-1;
    for(int i =0;i<n;i++)num[i]=1;
    while(flag){
        afind=0;
        k=kbuffer;
        m = mbuffer;
        for(int i = 0;i<k &&  (i<n||afind) ;a++,i++){
            if(a>=n)a -=n;
            if(num[a])afind+=1;
            else k++;
        }
        if(afind==0)flag=0;
        if(flag){
            bfind = 0;
            printf("%d",a-1+1);
            for(int i = 0;i<m &&  (i<n||bfind) ;b--,i++){
                if(b<0)b +=n;
                if(num[b])bfind+=1;
                else m++;
            }
            if(bfind==0)flag=0;
            if(flag){
                if(b+1+1!= a-1+1)printf(" %d\n",b+1+1);
                else printf("\n");
                num[b+1]=0;
                num[a-1]=0;
            }
            else printf("\n");
        }
        else printf("\n");

        if(a>=n)a-=n;
        if(b<0)b+=n;
    }

    return 0;
}
#endif

#ifdef UVa213
/* Message Decoding */
int readcode(int length,int value){
    char buf;
    value *=2;
    while((buf=getchar())=='\n'); //ignore \n
    buf-='0';
    length--;
    if(length){
        return  readcode(length,value+buf);
    }
    else return value+ buf;
}
int main(){
    char key[50];
    int length,all,buf,flag=0,base,max;
    if(scanf("%s",key)){
        all = strlen(key);
        getchar();
        while((buf = getchar())!='\n')
        {
            length=readcode(2,buf-'0');
            max = pow(2,length);
            base = max-length-1;
            if(length){
                    flag=1;
                    while(flag){
                    buf = readcode(length,0);
                    if(buf == max-1){
                        flag=0;
                    }
                    else {
                        putchar(key[base +buf]);
                    }
                }
                printf("\n");
            }
        }

    }

    return 0;
}
#endif

#ifdef UVa512
/* Spreadsheet Tracking */
#ifdef UVa512_way1
enum{DC,DR,IC,IR,EX};
enum{Increase,Decline};
const char *table[5]={"DC","DR","IC","IR","EX"};
int findnum(int *dst,int target,int flag){
    int buffer=0;
    while(*dst){
        if(*dst==target&&flag==Decline)
            return -1;
        else if(*dst<=target){
            buffer +=1;                  //rows or columns after target will not make any influence
        }
        dst++;
    }
    return buffer;
}

int Exg(int *dst,int *r,int *c){
    for(int i = 0;i<2;i++){
        if(dst[2*i]==*r && dst[2*i+1]== *c){
            i = (i+1)%2;
            *r = dst[2*i];
            *c = dst[2*i+1];
        }
    }
    return 0;
}

int readcommand(char* dst){
    scanf("%s",dst);
    if( strcmp(dst,"EX") )
        return 0;//if not command "EX"
    return 1;
}
int readparameters(int * dst,int n){
    while(n--)scanf("%d",dst++);
    return 0 ;
}

int work(char *command,int *para,int*r,int*c){
    int i,buf;
    for(i =0;i<5;i++){
        if(!strcmp(command,table[i]))break;
    }
    switch(i){
        case DC:{
            buf = findnum(para,*c,Decline);
            if(buf!= -1)
                *c-=buf;
            else return 0;
            break;
        }
        case DR:{
            buf = findnum(para,*r,Decline);
            if(buf!=-1)
                *r-=buf;
            else return 0;
            break;
        }
        case IC:{
            buf = findnum(para,*c,Increase);
            *c+= buf;
            break;
        }
        case IR:{
            buf = findnum(para,*r,Increase);
            *r +=buf;
            break;
        }
        case EX:{
            Exg(para,r,c);
            break;
        }
    }
    return 1;
}

#endif
int main(){
#ifdef UVa512_way1
    int r,c,n,q,buf,para[50][12],bufr,bufc,flag,sheet=0;
    char command[50][4];
    memset(para,0,sizeof(para));
    memset(command,0,sizeof(command));
    scanf("%d %d %d",&r,&c,&n);
    for(int i=0;i<n;i++){
        if(!readcommand(command[i]))scanf("%d",&buf); //read the number of parameters
        else buf = 4;
        readparameters(para[i],buf);
    }//save all input
    scanf("%d",&q);
    printf("Spreadsheet #%d\n",++sheet);
    for(int i = 0;i<q;i++){
        scanf("%d %d",&r,&c);
        bufr = r;
        bufc = c;
        flag =1;
        for(int j = 0;j<n;j++){
            if(!work(command[j],para[j],&bufr,&bufc)){
                printf("Cell data in (%d,%d) GONE\n",r,c);
                flag =0;
                break;
            }
        }
        if(flag){
            printf("Cell data in (%d,%d) moved to (%d,%d)\n",r,c,bufr,bufc);
        }
    }

#endif



    return 0;
}
#endif