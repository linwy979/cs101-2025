#include <stdio.h>

int main()
{
    FILE*input =fopen("main.c","r");
    FILE*output =fopen("main.txt","w");
    
    char c;
    while((c=fgetc(input)) !=EOF){
        fputc(c,output);
    }
    
    fclose(input);
    fclose(output);

    return 0;
}
