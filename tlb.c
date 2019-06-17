#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int ptarray[101];
int ptl = 0;
int tlbarray[101];
int tlbl = 0;
int f;

int main(){

    int page, frame;
    printf("%d %d", page, frame);
    srand(time(NULL));
    page = rand()%15;
    frame = rand()%15;

    tlb();
    int exist = 0;

    for (int i = 0; i<tlbl; i++){
        if (page==tlbarray[i]){
        f = i;
        exist = 1;
    }
    }

    if (exist == 0) {
    page_table();
        for(int i = 0; i < ptl; i++){
            if(ptarray[i] == page){
                f = i;
                break;
            }
        }
        writeToTLB(page);

    }
    printf("\n%d + %d",f,frame);
    return 0;
}

void *page_table(){
    FILE *file1 = fopen("/home/akbota/Рабочий стол/pt.txt", "r");
    int i=0;
    int n;
    while(fscanf(file1, "%d", &n) > 0) {
        ptarray[i] = n;
        i++;
    }
    ptl = i;
    fclose(file1);
}

void *tlb(){
    FILE *file2 = fopen("/home/akbota/Рабочий стол/tlb.txt", "r");
    int i=0;
    int n;
    while(fscanf(file2, "%d", &n) > 0) {
        tlbarray[i] = n;
        i++;
    }
    tlbl = i;
    fclose(file2);
}

void *writeToTLB(int page){
    if(tlbl> 5){
        FILE *file3 = fopen("/home/akbota/Рабочий стол/tlb.txt","w");
        tlbarray[0] = page;
        for(int i=0;i<tlbl;i++) {
            fprintf(file3,"%d\n",tlbarray[i]);
        }
        fclose(file3);
        return;
    }
   FILE *file4 = fopen("/home/akbota/Рабочий стол/tlb.txt","a");
   if(file4 == NULL)
   {
      printf("fail");
      exit(1);
   }
   fprintf(file4,"\n%d",page);
   fclose(file4);
}
