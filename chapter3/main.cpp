#define asg9
#define eg3_2_way1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
/* digit generator */
int main(){
#define MAXN 1000005
    int n,table[MAXN];
    int x,sum;
    memset(table,0,sizeof(table));
    for(int i = 1;i<MAXN-5;i++){
        x = sum = i;
        while(x){
            sum += x%10;
            x = x-x%10;
            x /= 10;
        }
        if(table[sum]==0|| i<table[sum] ){
            table[sum ] = i;
        }
    }
    while(scanf("%d",&n)==1){
        printf("%d\n",table[n]);
    }
    return 0;
}
#endif


#ifdef eg3_10
/* circular sequence */
int main(){
    char s[102];
    char * p,*buffer;
    int length,current;
    while(scanf("%s",s)==1){
        current = 0;
        length = strlen(s);
        p= s;
        buffer = p+1;
        while(buffer < s+length){
            if(*buffer < *p )p = buffer;
            else if(* buffer == *p) {
                for (int i; i < length; i++) {
                    if (current + buffer >= s + length) {
                        if (current + p >= s + length) {
                            if (*(current + buffer - length) < *(current + p - length)) {
                                p = buffer;
                                break;
                            } else if (*(current + buffer - length) > *(current + p - length))break;
                        } else {
                            if (*(current + buffer - length) < *(current + p - length)) {
                                p = buffer;
                                break;
                            } else if (*(current + buffer - length) > *(current + p - length)) {
                                break;
                            }
                        }
                    } else if (*(current + buffer) < *(current + p)) {
                        p = buffer;
                        break;
                    } else if (*(current + buffer) > *(current + p)) {
                        break;
                    }
                    current++;
                }
            }
            buffer++;
        }
        for(int i=0;i<length;i++){
            if( p+i >= s+length)putchar(*(p+i-length));
            else putchar (*(p+i));
        }
        putchar('\n');
    }
    return 0;
}
#endif


#ifdef eg3_11
/* store */
int main(){
#ifdef total
    int sum,buffer;// sum=0; scanf("%d",&buffer);sum +=buffer;
#endif

#ifdef MAX_MIN_AVER
    int max,min,sum,buffer,nums;//if(buffer>max) etc. average = buffer/(float)nums;
#endif

#ifdef approximate
    int nums[],i,n,m,degree; // i for iterate while nums for storing numbers to look up
    //n,m for the pair found ,degree for showing the degree of approximation
#endif

#ifdef second
    int buffer,first,second,flag=0; //flag for whether numbers are the same
    // first=buffer_1> buffer_2  ? buffer_1:buffer_2 , if(buffer_k!= first )flag=1
    // if(buffer_k >= second && buffer_k<=first)second = buffer_k;
    // else if( buffer_k>first )first = buffe_k;
#endif

#ifdef varience
    int nums[];
    int sum;
    //because have to use numbers after having got  average number
#endif

#ifdef nums_above_aver
    int nums[];
    int sum;
    //the same reason as above
#endif
    return 0;
}
#endif

#ifdef eg3_12
/* stat the nums of 1 */
#define maxn 10000000 + 10
int main(){
    char s[maxn];
    scanf("%s",s);
    int tot=0;
    for(int i = 0; i<strlen(s);i++)//havent INLCUDE <STRING.H> &HAVE TO EXECUTE STELEN(S) MANY TIMES
        if(s[i]==1)tot++;//should compare with '1'
        printf("%d\n",tot);
    return 0;
}
#endif

#ifdef asg1
/* Score */
int main(){
    char buffer;
    int score=0,last=0;
    while((buffer = getchar())!='\n'){
        if(buffer=='O'){
            last++;
            score+=last;
        }
        else last=0;
    }
    printf("%d\n",score);
    return 0;
}
#endif

#ifdef asg2
/* Molar Mass */
int main(){
    enum {C,H,O,N};
    float Masstable[]={12.01,1.008,16.00,14.01},total=0;
    char substance[20];
    scanf("%s",substance);
    for(int i = 0;substance[i];i++){
        switch (substance[i]) {
            case 'C':{
                if(substance[i+1]>='1'&&substance[i+1]<='9'){
                    total += Masstable[C]* (substance[i+1]-'0') ;
                }
                else total+= Masstable[C];
                break;
            }
            case 'H':{
                if(substance[i+1]>='1'&&substance[i+1]<='9'){
                    total += Masstable[H]* (substance[i+1]-'0') ;
                }
                else total+= Masstable[H];
                break;
            }
            case 'O':{
                if(substance[i+1]>='1'&&substance[i+1]<='9'){
                    total += Masstable[O]* (substance[i+1]-'0') ;
                }
                else total+= Masstable[O];
                break;
            }
            case 'N':{
                if(substance[i+1]>='1'&&substance[i+1]<='9'){
                    total += Masstable[N]* (substance[i+1]-'0') ;
                }
                else total+= Masstable[N];
                break;
            }

        }
    }
    printf("%fg/mol\n",total);
    return 0;
}
#endif

#ifdef asg3
/* Digit Counting */
int main(){
    int n,count[10],place,buf=1,placeafterbase=1,placeafter=0;
    memset(count,0,sizeof(count));
    scanf("%d",&n);
    do {
        buf = n / placeafterbase/10 ; //the forward take base
        place = (n-buf*placeafterbase*10)/placeafterbase;
        for (int i = 0; i < 10; i++) {
            count[i]+=buf;
            if (i < place)
            {
                if(buf||i!=0)count[i] += placeafterbase;
            }
            else if(i==place)
            {
                if(placeafterbase!=1)count[i] += placeafter+1;
                else count[i]+=1;
            }
        }
        placeafterbase *=10;
        placeafter= n%(placeafterbase);
    }while(buf);
    count[0]-=1;
    for(int i = 0;i<10;i++)
    {
        printf("%d", count[i]);
        if(i!=9 )printf(" ");
    }
    printf("\n");
    return 0;
}
#endif

#ifdef asg4
/* Periodic Strings */
int main(){
    char s[30],*p1,*p2=p1=s;
    int flag=1;
    scanf("%s",s);
    while(*p2&&flag){
        if(p2==p1)p2++;
        if(*p2== *p1 ){
            for(int i =1;;i++){
                if(*(p2+i)!=*(p1+i)){
                    p2++;
                    break;
                }
                else if(p1+i+1==p2){
                    flag = 0;
                    break;
                }
                else if(*(p2+i+1)==0){
                    flag = 2;
                    break;
                }
            }
        }
        else p2++;
    }
    if(flag==2) p2=p1+strlen(s)-1;
    printf("%ld\n",p2-p1);
    return 0;
}
#endif

#ifdef asg5
/* Puzzle */
int main(){
    char puzzletable[5][5],order[20],*blank=*puzzletable,flag=1;
    for(int i =0;i<5;i++)scanf("%s",*(puzzletable+i));//read table
    scanf("%s",order);
    for(int i = 0;i<25;i++)
    {
        if(*blank=='*')break;
        else blank++;
    }//find blank

    for(int i = 0;order[i]!='0';i++){
        switch(order[i]){
            case 'A':{
                if(*(puzzletable)+5>blank){
                    flag=0;
                    printf("This puzzle has no final configuration.\n");
                    order[i+1]='0';
                }
                else {
                    *blank= *(blank-5);
                    blank -=5;
                    *(blank)='*';
                }
                break;
            }
            case 'B':{
                if(*(puzzletable+4)<blank){
                    flag=0;
                    printf("This puzzle has no final configuration.\n");
                    order[i+1]='0';
                }
                else {
                    *blank= *(blank+5);
                    blank +=5;
                    *(blank)='*';
                }
                break;
            }
            case 'L':{
                if((blank-*puzzletable)%5==0){
                    flag=0;
                    printf("This puzzle has no final configuration.\n");
                    order[i+1]='0';
                }
                else {
                    *blank= *(blank-1);
                    blank -=1;
                    *blank = '*';
                }
                break;
            }
            case 'R':{
                if((blank-*puzzletable)%5==4){
                    flag=0;
                    printf("This puzzle has no final configuration.\n");
                    order[i+1]='0';
                }
                else {
                    *blank= *(blank+1);
                    blank +=1;
                    *blank ='*';
                }
                break;
            }

        }
    }
    if(flag)for(int i =0;i<25;i++){
        putchar(*(*(puzzletable+i/5)+i%5));
        if(i%5==4)putchar('\n');
        else putchar(' ');
    }
    return 0;
}
#endif

#ifdef asg6
/* Crossword Answers */
enum{Not,Down,Across,Both};
typedef struct puzzle{
    char data;
    char flag=Not;
    char num=0;
}Puzzle;
int find(Puzzle *table, char length, char c);
int output(Puzzle* table,char length,char c);

int main(){
    puzzle table[100],*p=table;
    char buffer,r,c,Case=0;
    while((buffer = getchar())!='0'){
        if((buffer >='A'&&buffer<='Z' )|| buffer== '*'){
            (p++)->data=buffer;
        }
        if(buffer>='1'&&buffer<='9')
        {
            r = buffer-'0';
            while((buffer=getchar())==' '||buffer =='\n');
            if(buffer>='1'&&buffer<='9')
                c=buffer-'0';
            else printf("Wrong input\n");
        }
        if(p-table==r*c){
            //process
            Case++;
            find(table,c*r,c);
            printf("Puzzle #%d:\n",Case);
            output(table,c*r,c);
            printf("\n");
            p=table;
        }
    }
    return 0;
}

int find(Puzzle *table, char length, char c){
    int i=0;
    char number=0;
    while(i<length){
        if((table+i)->data!='*') {
            if (i < c) {
                number++;
                (table + i)->num = number;
                (table + i)->flag += Down;
            }
            if ((table + i - 1)->data == '*' && i % c) {
                if (!(table + i)->num) {
                    number++;
                    (table + i)->num = number;
                }
                (table + i)->flag += Across;
            }
            if ((table + i - c)->data == '*' && i >= c) {
                if (!(table + i)->num) {
                    number++;
                    (table + i)->num = number;
                }
                (table + i)->flag += Down;
            }
            if (i % c == 0) {
                if (!(table + i)->num) {
                    number++;
                    (table + i)->num = number;
                }
                (table + i)->flag += Across;
            }
        }
        i++;
    }
    return 0;
}

int output(Puzzle* table,char length,char c){
    Puzzle *p=table,*p2;
    printf("Across:\n");
    while(p<table+length){
        if((p->flag)>=Across){
                p->flag -= Across;
                printf("%d.",p->num);
                do{
                    putchar(p->data);
                    p++;
                }while((p)->data!='*' && ((p-table)%c ));
                putchar('\n');
            }
        else p++;
    }
    p = table;
    printf("Down:\n");
    while(p<table+length){
        if((p->flag)==Down){
            printf("%d.",p->num);
            p2 = p++;
            do{
                putchar(p2->data);
                p2+=c;
            }while( p2->data !='*' && ((p2-table)<= length ));
            putchar('\n');
        }
        else p++;
    }
    return 0;
}
#endif

#ifdef asg7
/* DNA Consensus String */
#define MAXN  51002
enum{A,C,G,T};
int main(){
    char DNA[MAXN],solution[1001],dict[4];
    int m,n,i,j,buf,most;
    scanf("%d %d",&m,&n);
    for( i = 0; i<n;i++){
        scanf("%s",DNA+i*m);
    }//read
    for( i = 0;i<m;i++){
        buf = 0;
        memset(dict,0,sizeof(dict));
        for(j=0;j<n;j++){
            switch(DNA[i+m*j]){
                case 'A':{
                    dict[0]+=1;
                    break;
                }
                case 'C':{
                    dict[1]+=1;
                    break;
                }
                case 'G':{
                    dict[2]+=1;
                    break;
                }
                case 'T':{
                    dict[3]+=1;
                    break;
                }
            }
        }
        for( j= 0;j<4;j++){
            if(dict[j]>buf){
                most=j;
                buf = dict[j];
            }
        }
        switch (most) {
            case A:{
                solution[i]='A';
                break;
            }
            case C:{
                solution[i]='C';
                break;
            }
            case G:{
                solution[i]='G';
                break;
            }
            case T:{
                solution[i]='T';
                break;
            }
            default:{
                printf("Wrong input\n");
            }

        }
    }
    solution[i]='\0';
    printf("%s\n",solution);
    return 0;
}
#endif

#ifdef  asg8
/* Repeating Decimals */
int main(){
    int a,b,num=0,flag=1,bufa,bufb,start;
    char decimal[200];
    scanf("%d %d",&a,&b);
    memset(decimal,0,sizeof(decimal));
    printf("%d.",a/b);
    if(a/b)a -= a/b*b;
    while(flag){
        a *=10;
        decimal[num++]= a/b+'0';
        a -= a/b*b;
        for(int i =0;i<num-1;i++){
            if(decimal[i]==decimal[num-1]){
                bufa=a;
                bufb=b;
                for(int j=1;j+i<num;j++){
                    bufa *=10;
                    decimal[num-1+j]= bufa/bufb+'0';
                    bufa -= bufa/bufb*bufb;
                    if(decimal[i+j]!=decimal[num-1+j]){
                        break;
                    }
                    else if(j+i==num-1&&bufa==a&&bufb==b)
                    {
                        start=i;
                        flag=0;
                    }
                }
                if(!flag)break;
            }
        }
    }
    decimal[num-1]='\0';
    for(int i=0;decimal[i];i++){
        if(i==start){
            printf("(%c",decimal[i]);
        }
        else putchar(decimal[i]);
    }
    printf(")\n");
    printf("Repeating length:%lu\n",strlen(decimal)-start);
    return 0;
}
#endif

#ifdef asg9
#endif