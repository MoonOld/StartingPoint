#define UVa508
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

#ifdef UVa12412
/* A typical homework */
typedef struct{
    char SID[11];
    char CID[3];
    char name[12];
    short Chinese;
    short Mathematics;
    short English;
    short Progamming;
}STUDENT;

STUDENT student[500];
int currentlast=0;
int search(char* buf,int i){
    for(;i<currentlast;i++){
        if(strcmp(buf,student[i].SID)==0)
            return i;
    }
    return -1;
}

int gettotal(int j){
    int total=0;
    total+=student[j].Mathematics;
    total+=student[j].English;
    total+=student[j].Progamming;
    total+=student[j].Chinese;
    return total;
}
int rank(int torank){
    int num=1,total;
    for(int j=0;j<currentlast;j++){
        if(student[j].SID[0]){
            total=gettotal(j);
            if(total>torank)num++;
        }
    }
    return num;
}

int Add(){
    char buf[12];
    printf("Please enter the SID, CID, name, and four scores. Enter 0 to Finish.\n");
    while(1) {
        scanf("%s", buf);
        if (strcmp(buf,"0")!=0) {
            if (search(buf,0)==-1) {
                strcpy(student[currentlast].SID,buf);
                scanf("%s %s %hd %hd %hd %hd", student[currentlast].CID, student[currentlast].name,
                      &student[currentlast].Chinese, &student[currentlast].Mathematics,
                      &student[currentlast].English, &student[currentlast].Progamming);
                currentlast++;
            }
            else {
                printf("Duplicated SID\n");
                scanf("%*s %*s %*hd %*hd %*hd %*hd");
            }
        }
        else break;
    }
    return 0;
}
int Remove(){
    unsigned long long bufi,base,find;
    int num=0;
    char bufc[13];
    printf("Please enter SID or name. Enter 0 to finish.\n");
    while(1) {
        scanf("%s", bufc);
        if (bufc[0] >= '0' && bufc[0] <= '9') {
            if(bufc[1]==0)break;
            while (~(find = search(bufc,0))) {
                num++;
                student[find].SID[0] = 0;
            }
        }
        else {
            for(int i =0;i<currentlast;i++){
                if(student[i].SID[0]&& strcmp(student[i].CID,bufc)==0){
                    num++;
                    student[find].SID[0]=0;
                }
            }
        }
    }
    printf("%d student(s) were removed\n",num);
    return 0;
}

int Query(){
    int find=-1;
    char bufc[13];
    int total;
    printf("Please enter SID or name. Enter 0 to finish.\n");
    while(1) {
        scanf("%s",bufc);
        if (!(bufc[0] >= '0' && bufc[0] <= '9')) {
            for (int i = 0; i < currentlast; i++) {
                if (strcmp(student[i].name, bufc) == 0) {
                    total=gettotal(i);
                    printf("%d %s %s %s %hd %hd %hd %hd %d %.2f\n",rank(total),student[i].SID, student[i].CID,
                           student[i].name, student[i].Chinese,student[i].Mathematics,student[i].English,student[i].Progamming,total,
                           total/4.0);
                }
            }
        } else {
            if (strcmp(bufc,"0")==0)
                break;                           //end input and exit like this  "0\n"
            while ((find = search(bufc,find+1))!=-1) {
                total=gettotal(find);
                printf("%d %s %s %s %hd %hd %hd %hd %d %.2f\n",rank(total),student[find].SID, student[find].CID,
                       student[find].name, student[find].Chinese,student[find].Mathematics,student[find].English,student[find].Progamming,total,
                       total/4.0);
            }
        }
    }
    return 0;
}

int ShowRanking(){
    printf("Showing the ranklist hurts the students' self-esteem. Don't do that.\n");
    return 0;
}
int ShowStatistics(){
    char Class[3];
    int failed,flag=0,all=0;
    int statistics[13];//0~3 for subject total, 4~8 for failed man,9~12 for subject failed
    printf("Please enter class ID, 0 for the whole statistics.\n");
    scanf("%s",Class);
    memset(statistics,0,sizeof(statistics));
    if(strcmp(Class,"0")==0)flag=1;
    for(int i = 0;i<currentlast;i++){
        if(student[i].SID[0] && (flag||strcmp(student[i].CID,Class)==0)){
            failed=0;
            all++;
            statistics[0]+=student[i].Chinese;
            statistics[1]+=student[i].Mathematics;
            statistics[2]+=student[i].English;
            statistics[3]+=student[i].Progamming;
            if(student[i].Chinese<60){
                failed++;
                statistics[9]++;
            }
            if(student[i].Mathematics<60){
                failed++;
                statistics[10]++;
            }
            if(student[i].English<60){
                statistics[11]++;
                failed++;
            }
            if(student[i].Progamming<60){
                failed++;
                statistics[12]++;
            }
            statistics[4+failed]++;
        }
    }
    printf("Chinese\n"
           "Average Score: %.2f\n"
           "Number of passed students: %d \nNumber of failed students: %d\n\n", statistics[0]/(float)all,
           all-statistics[9],statistics[9]);
    printf("Mathematics\n"
           "Average Score: %.2f\n"
           "Number of passed students: %d \nNumber of failed students: %d\n\n", statistics[1]/(float)all,
           all-statistics[10],statistics[10]);
    printf("English\n"
           "Average Score: %.2f\n"
           "Number of passed students: %d \nNumber of failed students: %d\n\n", statistics[2]/(float)all,
           all-statistics[11],statistics[11]);
    printf("Programming\n"
           "Average Score: %.2f\n"
           "Number of passed students: %d \nNumber of failed students: %d\n\n",statistics[3]/(float)all,
           all-statistics[12],statistics[12]);
    printf("Overall:\n"
           "Number of students who passed all subjects: %d\n"
           "Number of students who passed 3 or more subjects: %d\n"
           " Number of students who passed 2 or more subjects: %d\n"
           " Number of students who passed 1 or more subjects: %d\n"
           " Number of students who failed all subjects: %d\n",statistics[4],statistics[5],
           statistics[6],statistics[7],statistics[8]);
    return 0;
}

int main(){
    int (*p[5])()={Add,Remove,Query,ShowRanking,ShowStatistics},input;
    do{
        printf("Welcome to Student Performance Management System (SPMS)\n");
        printf("\n");
        printf("1 - Add\n");
        printf("2 - Remove\n");
        printf("3 - Query\n");
        printf("4 - Show ranking\n");
        printf("5 - Show statistics\n");
        printf("0 - Exit\n");
        scanf("%d",&input);
        if(input)p[input-1]();
    }while(input);
    return 0;
}
#endif

#ifdef UVa1589
/* xiangqi */
enum{
    G,R,H,C
};
enum{
    no,UL1,UL2,UR1,UR2,DR2,DR1,DL2,DL1
};

typedef struct{
    int r;
    int c;
    int type;
}piece;
//black -> r as a sign of judging whether this place is banned

int is_blackvalid(piece* black) {
    if(!
    ((black->c )<=6 && (black->r )<=3&&
       (black->c )>=4 && (black->r )>=1 )
       )black->r=0;
    return 0;
}
int getblackroutes(piece* black,piece*dst){
    //get all the place where black could go
    int buf=1;
    for(int i =0;i<2;i++){
        buf=-buf;
        dst->r =black->r +buf;
        dst->c = black->c;
        is_blackvalid(dst);
        dst++;
    }
    for(int i =0;i<2;i++){
        buf=-buf;
        dst->c =black->c +buf;
        dst->r = black->r ;
        is_blackvalid(dst);
        dst++;
    }
    return 0;
}
int is_reachable_horse(piece* black,piece *horse){
    int flag=no;
    if(black->r > horse->r &&(black->r-2<=horse->r)){
        //the up situation
        if(black->r ==horse->r+1) {
            if (black->c == horse->c - 2)
                flag = UL1;
            else if (black->c == horse->c + 2)
                flag = UR2;
        }
        else {
            if (black->c == horse->c - 1)
                flag = UL2;
            else if (black->c == horse->c + 1)
                flag = UR1;
        }
    }
    else if(black->r < horse->r && (black->r+2 >= horse->r)){
        //the down situation
        if(black->r ==horse->r-1) {
            if (black->c == horse->c - 2)
                flag = DL1;
            else if (black->c == horse->c + 2)
                flag = DR2;
        }
        else {
            if (black->c == horse->c - 1)
                flag = DL2;
            else if (black->c == horse->c + 1)
                flag = DR1;
        }
    }
    return flag;
}

int judgeR(piece* black, piece *car,piece* red){
    int flag;
    piece* redbuf;
    for(int i = 0;i<4;i++){
        if(black->r&&(black->c == car-> c||black->r == car-> r)){
            flag=1;
            redbuf=red;
            if(black->r==car->r){
                while(redbuf->r){
                    if(redbuf->r == car->r&&
                    redbuf->c <  (black->c > car->c? black->c : car->c )&&
                    redbuf->c >  (black->c < car->c? black->c : car->c))flag =0;
                    red++;
                }
            }
            else if(black->c == car-> c){
                while(redbuf->r){
                if(redbuf->c == car->c&&
                   redbuf->r <  (black->r > car->r? black->r : car->r )&&
                   redbuf->r >  (black->r < car->r? black->r : car->r))flag =0;
                redbuf++;
            }
        }
        if(flag)black->r=0;
        }
        black++;
    }
    return 0;
}
int judgeC(piece * black,piece *cannon,piece* red ){
    int flag;
    //flag record the chess piece among cannon and black boss
    piece * redbuf;
    for(int i =0;i<4;i++){
        if(black->r&&(black->r==cannon->r||black->c==cannon->c)){
            redbuf = red;
            flag = 0;
            if(black->r==cannon->r){
                while(redbuf->r){
                    if(redbuf->r == cannon->r&&
                       redbuf->c <  (black->c > cannon->c? black->c : cannon->c )&&
                       redbuf->c >  (black->c < cannon->c? black->c : cannon->c))flag +=1;
                    redbuf++;
                }
            }
            else while(redbuf->r){
                if(redbuf->c == cannon->c&&
                      redbuf->r <  (black->r > cannon->r? black->r : cannon->r )&&
                      redbuf->r >  (black->r < cannon->r? black->r : cannon->r))flag +=0;
            }
            if(flag==1)black->r=0;
        }
        black++;
    }
    return 0;
}
int judgeG(piece * black,piece *boss,piece * red){
    int flag;
    piece * redbuf;
    for(int i = 0;i<4;i++) {
        if(black->r&&black->c == boss->c){
            flag=1;
            redbuf = red;
            while(redbuf->r){
                if(redbuf ->c==boss->c && redbuf->r > boss->r && redbuf->r < black->r)flag=0;
                redbuf++;
            }
            if(flag)black->r=0;
        }
        black++;
    }
        return 0;
}
int judgeH(piece * black,piece *horse,piece* red){
    int flag,buf,rbuf,cbuf;
    piece* redbuf;
    for(int i =0;i<4;i++){
        if(black->r){
            buf = is_reachable_horse(black,horse);
            if(buf){
                if(buf<=UR1&&buf>=UL2){
                    rbuf=-1;
                    cbuf=0;
                    if(buf==UL2)cbuf=-1;
                }
                else if(buf>=UR2&&buf<=DR2){
                    rbuf=0;
                    cbuf=1;
                }
                else if (buf>= DR1&&buf <=DL1){
                    rbuf=1;
                    cbuf=0;
                }
                else {
                    rbuf=0;
                    cbuf=-1;
                }
                redbuf=red;
                flag=1;
                while(redbuf->r){
                    if(redbuf->r==horse->r+rbuf&&redbuf->c==horse->c+cbuf)flag=0;
                    redbuf++;
                }
                if(flag)black->r=0;
            }
        }
        black++;
    }
    return 0;
}
int judgeEmpty(piece*black){
    for(int i=0;i<4;i++){
        if(black->r)return 0;
        black++;
    }
    return 1;
}

int main(){
    int n,rbuf,cbuf,(*p[5])(piece* ,piece* ,piece*)={judgeG,judgeR,judgeH,judgeC};
    char typebuf;
    piece black[4],red[7],original;
    memset(black,0,sizeof(black));
    memset(red,0,sizeof(red));
    scanf("%d %d %d",&n,&original.r,&original.c);
    for(int i =0;i<7;i++){
        getchar();
        scanf("%c %d %d",&typebuf,&rbuf,&cbuf);
        if(typebuf=='0')break;
        red[i].c=cbuf;
        red[i].r=rbuf;
        if(typebuf=='G')red[i].type=G;
        else if(typebuf=='R')red[i].type=R;
        else if(typebuf=='H')red[i].type=H;
        else if(typebuf=='C')red[i].type=C;
    }
    getblackroutes(&original,black);
    for(int i =0;i<7;i++){
        p[red[i].type](black,red+i,red);
    }
    if(judgeEmpty(black))printf("Yes\n");
    else printf("No\n");
    return 0;
}
#endif

#ifdef UVa201
/* Squares */
enum{
    null,horizontal,vertical
};
typedef struct{
    int type;
    int row;
    int column;
}line;
line all[81];
int searchclose(line* p,int length,int type,int flag){
    for(int i=1;i<length;i++){
        if(type == horizontal){
            if((p+i)->type==horizontal&&((p+i)->row != p->row || ((p+i)->column)!= p->column +i))return 0;
        }
        if(type == vertical){
            if((p+i)->type==vertical&&((p+i)->column != p->column || ((p+i)->row)!= p->row +i))return 0;
        }
    }
    if(flag)
    {
        if(type ==horizontal){
            for(int i =0; (p+i)->type;i++){
                if((p+i)->type==horizontal&& (p+i)->row== p->row+length&& (p+i)->column== (p->column))
                return searchclose(p+i,length,horizontal,0);
            }
            return 0;
        }
        if(type ==vertical){
            for(int i =0; (p+i)->type;i++){
                if((p+i)->type==vertical&& (p+i)->row== p->row&& (p+i)->column== (p->column)+length)
                    return searchclose(p+i,length,horizontal,0);
            }
            return 0;
        }
    }
    return 1;
}
int exchange(line* a, line*b){
    int buf;
    buf = a->column;
    a ->column = b->column;
    b->column = buf;
    buf = a->row;
    a -> row = b->row;
    b -> row = buf;
    return 0;
}
int sort(){
    for(int i = 0;all[i].type!=null;i++){
        if(all[i].type==horizontal){
            for(int j=i+1;all[j].type!=null;j++){
                if(all[j].type==horizontal&& ( all[i].row>all[j].row ||       (all[i].row==all[j].row&& all[i].column>all[j].column))){
                    exchange(all+i,all+j);
                }
            }
        }
        if(all[i].type==vertical){
            for(int j=i+1;all[j].type!=null;j++){
                if(all[j].type==vertical&& (all[i].column>all[j].column || (all[i].column==all[j].column&& all[i].row>all[j].column)) ){
                    exchange(all+i,all+j);
                }
            }
        }
    }
    return 0;
}
int searchsquares(int length){
    int nums=0;
    int flag;
    for(int i=0;all[i].type!=null;i++){
        if(all[i].type==horizontal){
            flag = searchclose(all+i,length,horizontal,1);
            if(flag){
                for(int j =0; all[j].type!=null;j++){
                    if(all[j].type == vertical && all[j].column==all[i].column&& all[j].row== all[i].row){
                        flag = searchclose(all+j,length ,vertical,1);
                        if(flag )nums++;
                        break;
                    }
                }
            }
        }
    }
    return nums;
}
int main(){
    int n,m,nums,flag;
    char buf;
    memset(all,0,sizeof(all));
    scanf("%d %d",&n,&m);
    for(int i =0;i<m;i++){
        getchar();
        buf = getchar();
        switch (buf) {
            case 'V':{
                all[i].type = vertical;
                scanf("%d %d",&all[i].column, &all[i].row);
                break;
            }
            case 'H':{
                all[i].type = horizontal;
                scanf("%d %d",&all[i].row,&all[i].column);
                break;
            }
            default:
                break;
        }
    }//read
    sort();
    for(int i = 1;i<m/2;i++){
        nums = searchsquares(i);
        if(nums){
            flag =1;
            printf("%d square(s) of size %d\n",nums,i);
        }
    }
    if(flag==0){
        printf("No completed squares can be found\n");
    }
    return 0;
}
#endif



#ifdef UVa220
/* Othello */
enum{
    listfunction ,movefunction,exitfunction
};
char board[9][9];
int readboard(){
    char buf;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            while((buf=getchar())=='\n');
            board[i][j]=buf;
        }
    }
    return 0;
}
int checklist(int r,int c,char side,int *nums){
    int rbuf,cbuf;
    for(int i=-1;i<2;i++){
        for(int j = -1;j<2;j++){
            if((r+i)>=0&&(r+i)<=7&&(c+j)>=0&&(c+j)<=7){
                if(board[r+i][c+j]!='-' && board[r+i][c+j]!= side) {
                    rbuf = 2*i; cbuf=2*j;
                    while ((r + rbuf) >= 0 && (r + rbuf) <= 7 && (c + cbuf) >= 0 && (c + cbuf) <= 7) {
                        if(board[r+rbuf][c+cbuf] == side)break;
                        else if(board[r+rbuf][c+cbuf]== '-'){
                            if(*nums)printf(" ");
                            printf("(%d,%d)",r+rbuf+1,c+cbuf+1);
                            (*nums)++;
                            break;
                        }
                        rbuf +=i;
                        cbuf +=j;
                    }
                }
            }
        }
    }
    return 0;
}
int list(char * side ){
    int nums=0;
    for(int i =0;i<8;i++){
        for(int j=0; j<8;j++){
            if(board[i][j]== *side){
                checklist(i,j,*side,&nums);
            }
        }
    }
    if(nums==0){
        *side = *side =='B'?'W':'B';
        printf("No Legal move.\n");
    }
    else printf("\n");
    return 0;
}

int checkmove(int r,int c){
    char side=board[r][c];
    int flag,rbuf,cbuf;
    for(int i=-1;i<2;i++){
        for(int j = -1;j<2;j++){
            if((r+i)>=0&&(r+i)<=7&&(c+j)>=0&&(c+j)<=7){
                if(board[r+i][c+j]!='-' && board[r+i][c+j]!= side) {
                    rbuf = 2*i; cbuf=2*j;flag=0;
                    while ((r + rbuf) >= 0 && (r + rbuf) <= 7 && (c + cbuf) >= 0 && (c + cbuf) <= 7) {
                        if(board[r+rbuf][c+cbuf] == side){
                            flag=1;
                            break;
                        }
                        else if(board[r+rbuf][c+cbuf] =='-'){
                            break;
                        }
                        rbuf +=i;
                        cbuf +=j;
                    }
                    if(flag){
                        rbuf-=i;
                        cbuf-=j;
                        while(rbuf||cbuf){
                            board[r+rbuf][c+cbuf]=side;
                            rbuf-=i;
                            cbuf-=j;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int statistics(){
    int n=0,m=0;
    for(int i =0;i<8;i++){
        for(int j =0;j<8;j++){
            if(board[i][j]=='B')n++;
            else if(board[i][j]=='W')m++;
        }
    }
    printf("Black - %d White - %d\n",n,m);
    return 0;
}
int move(char * side){
    char n,m;
    scanf("%c%c",&n,&m);
    n -='0';
    m -='0';
    board[n-1][m-1]=*side;
    checkmove(n-1,m-1);
    statistics();
    if(*side =='B')*side='W';
    else *side ='B';
    return 0;
}
int exit(char * side){
    for(int i =0;i<8;i++)printf("%s\n",board[i]);
    return 0;
}
int main(){
    int flag,n,(*p[3])(char* )={list,move,exit};
    char buf,side;
    scanf("%d",&n);
    while(n--){
        flag = 1;
        readboard();
        getchar();
        side = getchar();  //getside
        while(flag) {
            getchar();
            buf = getchar();
            switch (buf) {
                case 'L': {
                    p[listfunction](&side);
                    break;
                }
                case 'M': {
                    p[movefunction](&side);
                    break;
                }
                case 'Q': {
                    flag = 0;
                    p[exitfunction](&side);
                    break;
                }
                default:
                    break;
            }
        }
        printf("\n");
    }
    return 0;
}
#endif

#ifdef UVa253
/* Cube painting */
enum{
    tocheck,parallel,cross
};
int checkpair(int a1, int a2, int b1,int b2){
    if(a1==b1&&a2==b2){
        return parallel;
    }
    else if(a2==b1&&a1==b2){
        return cross;
    }
    else return 0;
}
int circulatecheck(char buf[2][5]){
    for(int i =0;i<4;i++){
        buf[0][4]=buf[0][0];
        for(int j=0;j<4;j++){
            buf[0][j]=buf[0][j+1];
        }
        buf[0][4]=0;
        if(strcmp(buf[0],buf[1])==0){
            printf("TRUE\n");
            return 0;
        }
    }
    printf("FALSE\n");
    return 0;
}
int checkround(char cube[2][6],int n[2]){
    char buf[2][5];
    memset(buf,0,sizeof(buf));
    for(int i=0;i<2;i++){
        if(*(n+i)==0 ||*(n+i)==5){
            buf[i][0]=cube[i][1];
            buf[i][3]=cube[i][4];
        }
        else {
            buf[i][0]=cube[i][0];
            buf[i][3]=cube[i][5];
        }
        if(*(n+i)==0 ||*(n+i)==4){
            buf[i][1]=cube[i][3];
            buf[i][2]=cube[i][2];
        }
        else if(*(n+i)==1 ||*(n+i)==5){
            buf[i][1]=cube[i][2];
            buf[i][2]=cube[i][3];
        }
        else if(*(n+i)==2){
            buf[i][1]=cube[i][4];
            buf[i][2]=cube[i][1];
        }
        else{
            buf[i][1]=cube[i][1];
            buf[i][2]=cube[i][4];
        }
    }
    circulatecheck(buf);
    return 0;
}
int main(){
    char cube[2][6];
    int flag[3],buf,i,j,n[2];
    for(char *p=cube[0];p<cube[1]+6;){
        buf =getchar();
        if(buf!='\n'){
            *p=buf;
            p++;
        }
    }
    flag[0]=flag[1]=flag[2]=tocheck;
    for( i =0;i<3;i++) {
        for ( j = 0; j < 3; j++) {
            if (flag[j] == tocheck) {
                buf = checkpair(cube[0][i], cube[0][5 - i], cube[1][j], cube[1][5 - j]);
                if (buf){
                    n[0]=i;
                    if(buf==parallel)n[1]=j;
                    else n[1]=5-j;
                    flag[j] = buf;
                    break;
                }
            }
        }
    }
    if(flag[0]&&flag[1]&& flag[2]){
        checkround(cube,n);
    }
    else printf("FALSE\n");
    return 0;
}
#endif


#ifdef UVa1590
/* IP Networks */
int main(){
    int m,i,flag=1,num;
    unsigned *p;
    scanf("%d",&m);
    p = (unsigned *)malloc(sizeof(unsigned )*m*4);
    if(p){
        memset(p,0,sizeof(unsigned)*m*4);
        for( i =0;i<m;i++){
            scanf("%u.%u.%u.%u",p+4*i,p+4*i+1,p+4*i+2,p+4*i+3);
        }
        for(i=0;i<32&&flag;i++){
            for(int j =1;j<m&&flag;j++){
                if(  (   *(p+4*j+i/8)& (    1<<(7-i%8)) ) != (    *(p+i/8)  &  (1<<(7-i%8))  )   )
                    flag =0;
            }
        }
        i--;
        for(int j=0;j<32;j+=8){
            if(i-j>7)
            {
                printf("%d",*(p+j/8));
            }
            else if(i-j>0){
                num=0;
                for(int x =i-j;x;x--){
                    num+= *(p+j/8)&(1<<(8-x));
                }
                printf("%d",num);
            }
            else {
                printf("0");
            }
            if(j<24)
                printf(".");
            else printf("\n");
        }

        for(int j=0;j<32;j+=8){
            if(i-j>7)
            {
                printf("%d",(1<<8)-1);
            }
            else if(i-j>0){
                num=0;
                for(int x =i-j;x;x--){

                    num+= 1<<(8-x);
                }
                printf("%d",num);
            }
            else {
                printf("0");
            }
            if(j<24)
                printf(".");
            else printf("\n");
        }
        free(p);
    }
    return 0;
}
#endif

#ifdef UVa508
/* Morse Mismatches */
#define MAX 200
typedef struct{
    char code[15];
    char character;
}TABLE;
enum{
    SUCCESS
};
int read(TABLE* root){
    char buf;
    buf = getchar();
    while(buf!= '*'){
        if(buf!=' ' && buf!='\n' ){
            root->character=buf;
            scanf("%s",root->code);
            root++;
        }
        buf =getchar();
    }
    return 0;
}
int getdict(TABLE *table ,char morsedict[15][30]){
    char text[20],*p;
    int flag=1;
    do{
        scanf("%s",text);
        if(strcmp(text,"*")==0)flag=0;
        else {
            for(int i =0;i<15;i++){
                if(text[i]==0)break;
                else{
                    for(int j=0;(table+j)->character;j++){
                        if((table+j)->character==text[i]){
                            p = *morsedict +strlen(*morsedict);
                            strcpy(p,(table+j)->code);
                        }
                    }
                }
            }
            morsedict++;
        }
    }while(flag);
    return 0;
}
int check(char *word,char buf[30]){
    int flag=0,i,length=strlen(word);
    for(i=0;i<30;i++){
        if( !buf[i] || !word[i])break;
        else if(buf[i]!=word[i])break;
    }
    return length-i-1;
}

int main(){
    int  num,length,tocheck;
    TABLE table[30];
    char morsedict[15][30],buf,bufstring[30];
    memset(table,0,sizeof(table));
    memset(morsedict,0,sizeof(morsedict));
    read(table);
    getdict(table,morsedict);
    getchar();
    buf=getchar();
    while(buf!='*'){
        scanf("%s",bufstring);
        num=length=MAX;
        for(int i =0;morsedict[i][0];i++){
            tocheck=check(morsedict[i],bufstring);
            if(tocheck==0){
                num = i;
                break;
            }
            else if(tocheck< length){
                length=tocheck;
                num=i;
            }
        }
        buf=getchar();
    }

    return 0;
}
#endif