#include<stdio.h>
void hanoi(int n,char s,char m, char d){
if(n>0)
{
    hanoi(n-1,s,d,m);
    printf("move %d from %c to %c\n",n,s,d);
    hanoi(n-1,m,s,d);
}}
int main(){
printf("enter the no of disk : ");
int n;
scanf("%d",&n);
char s='a';
char m='b';
char d='d';
hanoi(n,s,m,d);
}
