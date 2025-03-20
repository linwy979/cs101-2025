#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    FILE *fp = fopen("lotto.txt", "w");

    scanf("%d", &N);
    srand(1); 

    fprintf(fp, "========= lotto649 =========\n");

    for (int i = 0; i < 5; i++) {
        fprintf(fp, "[%d]:", i + 1);
        if (i < N) {
            int used[70] = {0};
            for (int j = 0; j < 7; j++) {
                int num;
                do {
                    num = rand() % 69 + 1;
                } while (used[num]);
                used[num] = 1;
                fprintf(fp, " %02d", num);
            }
        } else {
            fprintf(fp, " __ __ __ __ __ __ __");
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);
    return 0;
}
