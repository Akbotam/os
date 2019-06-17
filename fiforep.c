#include <stdio.h>

int main(){

    int pages[50], frame[10], num, no, avail, s, count = 0;
    printf("\n Enter the number of pages: \n");
    scanf("%d", &num);
    printf("\n Enter the page number: \n");
    for (int i = 1; i<=num; i++)
    scanf("%d", &pages[i]);
    printf("\n Enter the number of frames: \n");
    scanf("%D", &no);
    for (int i = 0; i<no; i++)
    frame[i] = -1;
    int j = 0;
    printf("\tReference string\t Page frames\n");
        for(int i=1;i<=num;i++)
        {
                printf("%d\t\t",pages[i]);
                avail=0;
                for(s=0;s<no;s++)
                    if(frame[s]==pages[i])
                        avail=1;
                            if (avail==0)
                                    {
                                      frame[j]=pages[i];
                                      j=(j+1)%no;
                                      count++;
                                      for(s=0;s<no;s++)
                                      printf("%d\t",frame[s]);
                                    }
                                    printf("\n");
        }
                        printf("Page Fault Is %d",count);

    return 0;
}









