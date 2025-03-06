#include <stdio.h>

int main(){
    int i = 12345;
    int sum = 0;
    int first=0;
    int last=i%10;
    while(i>=10){
        i/=10;
        first = i%10;
    }
    sum=first+last;
    printf("Sum=%d",sum);
    return 0;
}
