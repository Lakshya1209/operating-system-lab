#include <stdio.h>

int main() {
    int n, frames, i, j, k;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int ref[n];
    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &ref[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frame[frames];

    for(i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    int index = 0, hit = 0, fault = 0, flag;

    printf("\nPage Replacement Process:\n\n");

    for(i = 0; i < n; i++) {
        flag = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                hit++;
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            frame[index] = ref[i];
            index = (index + 1) % frames;
            fault++;
        }

        printf("Page %d -> ", ref[i]);

        for(k = 0; k < frames; k++) {
            if(frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }

        if(flag == 0)
            printf("(Fault)");
        else
            printf("(Hit)");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d", fault);
    printf("\nTotal Hits = %d\n", hit);

    return 0;
}