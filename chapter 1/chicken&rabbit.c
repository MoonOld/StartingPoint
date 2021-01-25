#include stdio.h
int main(){
    int n,m,c,r;
    scanf("%d %d",&n,&m);
    r = (m-4*n)/2;
    c = n-r;
    if( (m-4*n)%2 || r< 0 || c<0 ) //invalid 
        printf("No answer\n");
    else printf("%d %d\n",c,r);
    return 0;
}