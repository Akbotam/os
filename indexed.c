#include<stdio.h>
#define TB 110

void create_file();
void delete_file();
void display_file();
int BFull();

struct Indexed
{
    char n[50];
    int lenght;
    int indexblock;
    int *IB[TB];
}F[50];
int Table[TB+1],pos=0,r,i,j,choice,B=0,indexblock,k=0;
char fn[50];
main()
{
     printf("\n Indexed File Allocation \n\n");
     while(1){
     printf("\n\n1.Create file\n2.Delete file\n3.Display file\n4.Exit");
     printf("\n\nEnter Your choice : ");
     scanf("%d",&choice);

     switch(choice)
     {
                case 1:
                    pos++;
                    create_file();
                    break;

                case 2:
                    k--;
                    delete_file();
                    break;

                case 3:
                    display_file();
                    break;

                case 4:
                    exit(1);

                default:
                    printf("\nInvalid Choice ");
        }
     }

}
void create_file()
{
   printf("\nEnter File Name : ");
   scanf("%s",&(F[pos].n));
   printf("\nEnter File Length : ");
   scanf("%d",&(F[pos].lenght));
   if(BFull())
   {
        pos--;
       printf("\n\nNo Enough Free Space Available \n");
       return;
   }
    F[pos].indexblock=rand()%TB+1;
    Table[F[pos].indexblock]=1;
   for(i=1;i<=F[pos].lenght;i++)
   {
        while(1)
        {

            r=rand()%TB+1;
            if(Table[r]==0)
            {

                    F[pos].IB[i]=&Table[r];
                    Table[r]=r;
                    break;
            }
        }
    }
    printf("\n\tDirectory\n");
    printf("\nFileName\tIndexBlock\n");
    for(i=1;i<=pos;i++)
    {
        printf("\n%s\t\t%d",F[i].n,F[i].indexblock);
        printf("\n");
    }

}
void delete_file()
{
   printf("\nEnter The File Name : ");
   scanf("%s",&fn);
   for(i=1;i<=pos;i++)
   {
            if(strcmp(F[i].n,fn)==0)
            {
                for(j=1;j<=F[pos].lenght;j++)
                   *F[pos].IB[j]=0;
                Table[F[pos].indexblock]=0;
                strcpy(F[i].n,"NULL");
                F[i].indexblock=-1;
                F[i].lenght=0;
                printf("\nFile (%s) Deleted Successfully \n",fn);
                break;
            }
            else
                printf("\nDeletion Unsuccessful\n");
    }
    printf("\n\tDirectory\n");
    printf("\nFileName\tIndexBlock\n");
    for(i=1;i<=pos;i++)
    {
        printf("\n%s\t\t%d",F[i].n,F[pos].indexblock);
        printf("\n");
    }
}
void display_file()
{
    printf("\nEnter The File Name : ");
    scanf("%s",fn);
    printf("\nBlocks Allocated Are : \n");
    for(i=1;i<=pos;i++)
    {
        if(strcmp(F[i].n,fn)==0)
        {
            printf("\n\t IndexBlock\n");
            printf("\n\t     %d\n",F[pos].indexblock);
            printf("\t------------");
            for(j=1;j<=F[pos].lenght;j++)
            {
                printf("\n\t|    %d\t   |\n",*F[pos].IB[j]);
            }
            printf("\t------------");

            break;
        }
    }
    if(i==pos+1)
    {
        printf("\n\nNo File Found\n");
    }
}
int BFull()
{
    for(i=1,B=0;i<=pos;i++)
        B=B+F[i].lenght;
    if(B>TB-pos-k)
        return 1;
    else
        return 0;
}
