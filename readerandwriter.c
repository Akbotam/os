#include<stdio.h>ŝ
#include<stdbool.h>

struct Semaphore
{
    int mutex;
    int reader_count;
    int reader_wait;
    bool wrt;
} s;

   struct Semaphore s = {1, 0,0 };

void addR()
{
    if (s.mutex == 0 && s.reader_count == 0)
{
    printf("\nSorry, File open in Write mode.\nNew Reader added to queue.\n");
    s.reader_wait++;
}
    else
{
    printf("\nReader Process added.\n");
    s.reader_count++;
    s.mutex--;
}
    return ;
}

void addW()
{
    if(s.mutex==1)
{
    s.mutex--;
    s.wrt=1;
    printf("\nWriter Process added.\n");
}
    else if(s.wrt) printf("\nSorry, Writer already operational.\n");
    else printf("\nSorry, File open in Read mode.\n");
    return ;
}
    void remR()

{
    if(s.reader_count == 0) printf("\nNo readers to remove.\n");

    else
    {
    printf("\nReader Removed.\n");
    s.reader_count--;
    s.mutex++;
    }
    return ;
}

    void remW ()

{
    if(s.wrt==0) printf("\nNo Writer to Remove");

    else
    {
    printf("\nWriter Removed\n");

    s.mutex++;
    s.wrt=0;
    }

    if(s.reader_wait!=0)

    {
    s.mutex-=s.reader_wait;
    s.reader_count=s.reader_wait;
    s.reader_wait=0;

    printf("%d waiting Readers Added.",s.reader_count);

    }
}

int main()

{
    while(1)
{
    printf("Options :-\n1.Add Reader.\n2.Add Writer.\n3.Remove Reader.\n4.Remove Writer.\n5.Exit.\n\n\tChoice : ");
    int n;
    scanf("%d",&n);

    switch(n)

{
        case 1: addR(); break;

        case 2: addW(); break;

        case 3: remR(); break;

        case 4: remW(); break;

        case 5: printf("\n\tGoodBye!");  return 0;

        default: printf("\nInvalid Entry!"); continue;

}

system("pause");

}
}
