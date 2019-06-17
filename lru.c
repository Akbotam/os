#include<stdio.h>

int main()
{
    int numf, nump, frames[10], pages[30], counter = 0, t[10];
    int flag1, flag2, i, j, pos, faults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &numf);

    printf("Enter the number of pages: ");
    scanf("%d", &nump);

    printf("Enter the reference string: ");

    for(i = 0; i < nump; ++i){
        scanf("%d", &pages[i]);
    }

    for(i = 0; i < numf; ++i){
        frames[i] = -1;
    }

    for(i = 0; i < nump; ++i){
        flag1 = flag2 = 0;

        for(j = 0; j < numf; ++j){
            if(frames[j] == pages[i]){
                counter++;
                t[j] = counter;
                   flag1 = flag2 = 1;
                   break;
               }
        }

        if(flag1 == 0){
            for(j = 0; j < numf; ++j){
                if(frames[j] == -1){
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    t[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0){
            pos = lru(t, numf);
            counter++;
            faults++;
            frames[pos] = pages[i];
            t[pos] = counter;
        }

        printf("\n");

        for(j = 0; j < numf; ++j){
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}


int lru(int t[], int n){
    int i, minimum = t[0], pos = 0;

    for(i = 1; i < n; ++i){
        if(t[i] < minimum){
            minimum = t[i];
            pos = i;
        }
    }

    return pos;
}
