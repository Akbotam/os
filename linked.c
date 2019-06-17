#include<stdio.h>
#define TB 110

void create_file();
void delete_file();
void display_file();
int BFull();

struct Link
{
    char n[50];
    int lenght;
    int st;

    struct node
    {
        int index;
        struct node *next;
    }*Start,*current,*newnode,*temp;
}F[50];
int Table[TB+1],pos=0,r,i,j,choice,B=0;
char fn[50];
main()
{
     printf("\n Linked File Allocation \n\n");
     while(1){
     printf("\n\n1.Create file\n2.Delete file\n3.Display\n4.Exit");
     printf("\n\nEnter Your choice : ");
     scanf("%d",&choice);

     switch(choice)
     {
                case 1:
                    pos++;
                    create_file();
                    break;

                case 2:
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
   F[pos].Start=NULL;
   if(BFull())
   {
        pos--;
       printf("\n\nNo Enough Free Space Available \n");
       return;
   }

   for(i=1;i<=F[pos].lenght;i++)
   {
        F[pos].newnode=(struct node *)malloc(sizeof(struct node));

        while(1)
        {

            r=rand()%TB+1;
            if(Table[r]==0)
            {
                    F[pos].newnode->index =r;
                    F[pos].newnode->next=NULL;
                    if(F[pos].Start==NULL)
                    {
                        F[pos].Start=F[pos].newnode;
                        F[pos].current=F[pos].newnode;
                    }
                    else
                    {
                        F[pos].current->next=F[pos].newnode;
                        F[pos].current=F[pos].newnode;
                    }

                    Table[r]=1;
                    break;
            }
        }
    }
    F[pos].st=F[pos].Start->index;
    for(i=r;i<r+F[pos].lenght;i++)
        Table[i]=1;
    printf("\n\tFile Allocation Table\n");
    printf("\nFileName\tStart\tEnd\tLength\n");
    for(i=1;i<=pos;i++)
    {
        printf("\n%s\t\t%d\t%d\t%d",F[i].n,F[i].st,F[pos].current->index,F[i].lenght);
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
                F[i].current=F[i].Start;
                while(F[i].current)
                {
                    Table[F[i].current->index]=0;
                    F[i].temp=F[i].current;
                    F[i].current=F[i].current->next;
                    free(F[i].temp);
                }

                strcpy(F[i].n,"NULL");
                F[i].st=0;
                F[i].lenght=0;
                printf("\nFile (%s) Deleted Successfully \n",fn);
                break;
            }
            else
                printf("\nDeletion Unsuccessful\n");
    }
    printf("\n\t\tFile Allocation Table\n");
    printf("\nFileName\tStart\tLength\n");
    for(i=1;i<=pos;i++)
    {
        printf("\n%s\t\t%d\t%d",F[i].n,F[i].st,F[i].lenght);
        printf("\n");
    }
}
void display_file()
{
    printf("\nEnter The File Name : ");
    scanf("%s",fn);
    printf("\nBlocks Allocated Are : ");
    for(i=1;i<=pos;i++)
    {
        if(strcmp(F[i].n,fn)==0)
        {
            F[i].current=F[i].Start;
            while(F[i].current)
            {
               printf(">--%d-->",F[i].current->index);
               F[i].current=F[i].current->next;
            }
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
    if(B>TB)
        return 1;
    else
        return 0;
}
