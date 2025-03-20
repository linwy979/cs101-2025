#include <stdio.h>
#include <string.h>

int main()
{
    FILE*input =fopen("main.c","r");
    FILE*output =fopen("main.txt","w");
    
    char line[256];
    int line_number =0;
    
    while(fgets(line,sizeof(line),input)){
        line_number++;
        if(strstr(line, "int main()")){
            fprintf(output, "%d\n",line_number);
            break;
        }
    }
    
    fclose(input);
    fclose(output);

    return 0;
}
