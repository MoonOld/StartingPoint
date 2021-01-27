#define eg3_9
#define eg3_2_way1
#include <stdio.h>
#include <string.h>

#ifdef eg3_1
/* output in reverse order*/
int main() {
    int i=0 ,nums[100],x;
    while(scanf("%d",&x )==1)nums[i++]= x;
    while(i--){
        printf("%d ",nums[i]);
    }
    printf("\n");
    return 0;
}
#endif

#ifdef eg3_2
/* light */
int main(){
    int k,n,i,j;
    char *p;
    scanf("%d %d",&n,&k);
    p = (char*)malloc(sizeof(char)*n);
    for(i=0;i<n;i++)*(p+i)=0;
#ifdef eg3_2_way1
    for(i=1;i<=k;i++){
        for(j=i-1;j<n;j+=i){
            *(p+j)+=1;
        }
    }
#endif
    for(i=0,j=0;i<n;i++) {
        if (*(p + i) % 2)
            *(p + j++) = i+1;
    }
    j = 0;
    while(*(p+ j) < i)printf("%d ",*(p+j++));
    printf("%d\n",i);
    free(p);
    return 0;
}
#endif

#ifdef eg3_3
/* snake output */
int snake_input(int n,int x,int length,char*p);
int main(){
    int n,i,j,x,size;
    char *p;
    scanf("%d",&n);
    p=(char*)malloc(n*n*sizeof(char));
    memset(p,0,n*n*sizeof(char));
    snake_input(n,1,n,p+n-1);
    for(i=0;i<n*n;i++) {
        printf("%d", *(p + i));
        if(i%n != n-1){
            if(*(p+i)<10)printf(" ");
            printf(" ");
        }
        else printf("\n");
    }
    free(p);
    return 0;
}

int snake_input(int n,int x,int length,char* p){
    if(n==1) *p = x;
    else{
        int i =1;
        *p = x++;
        while(i<n){
            p+=length;
            *p = x++;
            i++;
        }//column down
        while(i>1){
            p--;
            *p= x++;
            i--;
        }//row left
        while(i<n){
            p -= length;
            *p= x++;
            i++;
        }//column up
        while(i>2){
            p++;
            *p = x++;
            i--;
        }//row left
    }
    if(n>2)snake_input(n-2,x,length,p+length);
    return 0;
}
#endif

#ifdef eg3_4
/* long division problem */
int judge_in(int a,int n, char* nums);
int print(int a,int b,int c,int d,int e);
int main(){
    char nums[10];
    int a,b,c,d,e,i,n,j,k,l,m,Case=0;
    scanf("%s",nums);
    n = strlen(nums);
    i = 0;
    for(a=nums[i]-'0';i++ < n;a=nums[i]-'0')
    {   j=0;
        for(b=nums[j]-'0';j++ <n;b=nums[j]-'0')
        {
            k=0;
            for(c=nums[k]-'0';k++<n;c=nums[k]-'0')
            {
                l = 0;
                for(d=nums[l]-'0';l++ <n;d=nums[l]-'0')
                {
                    m = 0;
                    for (e = nums[m] -'0'; m++ < n; e = nums[m]-'0') {
                        if (judge_in((a * 100 + b * 10 + c) * e, n, nums)
                        && judge_in((a * 100 + b * 10 + c) * d, n, nums)
                        && judge_in((a * 100 + b * 10 + c) * (e + d * 10), n, nums)) {
                            Case++;
                            printf("<%d>\n",Case);
                            print(a, b, c, d, e);
                        }
                    }
                }
            }
        }
    }
    printf("The number of solutions = %d\n",Case);
    return 0;
}
int judge_in(int a,int n, char* nums){
    int i,buffer;
    while(a>0){
        buffer = a%10;
        for(i = 0;i<n;i++){
            if(*(nums+i)-'0'==buffer)break;
            else if(i == n-1) return 0;
        }
        a -= a%10;
        a /= 10;
    }
        return 1;
}

int print(int a,int b,int c,int d,int e){
    printf("..%d%d%d\n"
           "X..%d%d\n"
           "-----\n",a,b,c,d,e);
    if((a*100+b*10+c)*e>1000)printf(".%d\n",(a*100+b*10+c)*e);
    else printf("..%d\n",(a*100+b*10+c)*e);
    if((a*100+b*10+c)*d>1000)printf("%d.\n",(a*100+b*10+c)*d);
    else printf(".%d.\n",(a*100+b*10+c)*d);
    printf("-----\n");
    if((a*100+b*10+c)*(e+10*d)>10000)printf("%d\n",(a*100+b*10+c)*(e+10*d));
    else printf(".%d\n",(a*100+b*10+c)*(e+10*d));
    printf("\n");
    return 0;
}
#endif

#ifdef eg3_5
/* quotes */
int main(){
    int flag=0;
    int buffer;
    while((buffer=getchar()) !='\n'){
        if(buffer != '"')putchar(buffer);
        else {
            flag++;
            if(flag%2)putchar('[');
            else putchar(']');
        }
    }
}
#endif

#ifdef eg3_6
/* WERTYU */
int main(){
    char s[]="1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./",buffer;
    int i;
    while((buffer=getchar())!=EOF||buffer!= '\n'){
        for(i=0;s[i];i++)
        {
            if(s[i]==buffer){
                putchar(s[i-1]);
                break;
            }
            else if(!s[i+1])putchar(buffer);
        }
    }
    return 0;
}
#endif

#ifdef eg3_7
/* Palindromes */
int main(){
    char s[30];
    char Mirror[]="AEHIJLMOSTUVWXYZ12358    A3HILJMO2TUVWXY51SEZ8";
    int length,left,right,regular,mirror;
    while(scanf("%s",s)==1){
        regular =mirror = 1;
        length= strlen(s);
        left = length/2-1;
        right = length%2 ? length/2+1 : length/2;
        while(left>=0){
            if(s[left]!=s[right])regular = 0;
            else if (left==0)regular =1;
            left--;
            right++;
        }//is regular
        left = length/2-1;
        right = length%2 ? length/2+1 : length/2;
        while(left>=0){
            for(int i=0;i<=20;i++){
                if(Mirror[i]==s[left]) {
                    if (s[right] == Mirror[i + 25])
                        mirror = 1;
                    break;
                }
                else if(i==20) {
                    mirror=0;
                    break;
                }
            }
            if(mirror==0)break;
            left--;
            right++;
        }
        if(regular){
            if(mirror){
                printf("%s -- is a mirrored palindrome.\n",s);
            }
            else printf("%s -- is a regular palindrome.\n",s);
        }
        else if(mirror){
            printf("%s -- is a mirrored string.\n",s);
        }
        else printf("%s -- is not a palindrome.\n",s);
    }
    return 0;
}

#endif

#ifdef eg3_8
/* Hints */
int main(){
    int dst[20],src[20],stat,right,game=0,c1,c2;
    int n,i,flag;
    while(scanf("%d",&n)){
        if(n==0)break;
        game++;
        i = n;
        while(i--){
            scanf("%d",dst+i);
        }
        flag=1;
        stat =right=0;
        printf("Game %d:\n",game);
        while(flag) {
            i = n-1;
            do {
                scanf("%d",  src+i);
                if (i == n && src[i] == 0)flag = 0;
                else if(src[i])flag = 1;
                if(src[i]==dst[i])right+=1;
            } while (i--);
            if(flag){
                for(i=0;i<10;i++){
                    c1=c2=0;
                    for(int m=n-1;m>=0;m--){
                        if(src[m]==i)c1++;
                        if(dst[m]==i)c2++;
                    }
                    stat += c1>c2? c2:c1;
                }
            }
            printf("(%d:%d)\n",right,stat-right);
        }
    }
    return 0;
}
#endif

#ifdef eg3_9
/*  */
#endif