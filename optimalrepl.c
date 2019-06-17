#include<stdio.h>

int main()
{
    int numf, nump, frames[10], pages[30], temp[10];
    int flag1, flag2, flag3, k, pos, max, faults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &numf);

    printf("Enter the number of pages: ");
    scanf("%d", &nump);

    printf("Enter the page reference string: ");

    for(int i = 0; i < nump; ++i){
        scanf("%d", &pages[i]);
    }

    for(int i = 0; i < numf; ++i){
        frames[i] = -1;
    }

    for(int i = 0; i < nump; ++i){
        flag1 = flag2 = 0;

        for(int j = 0; j < numf; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }

        if(flag1 == 0){
            for(int j = 0; j < numf; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0){
            flag3 =0;

            for(int j = 0; j < numf; ++j){
                temp[j] = -1;

                for(k = i + 1; k < nump; ++k){
                    if(frames[j] == pages[k]){
                        temp[j] = k;
                        break;
                    }
                }
            }

            for(int j = 0; j < numf; ++j){
                if(temp[j] == -1){
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if(flag3 ==0){
                max = temp[0];
                pos = 0;

                for(int j = 1; j < numf; ++j){
                    if(temp[j] > max){
                        max = temp[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            faults++;
        }

        printf("\n");

        for(int j = 0; j < numf; ++j){
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}
