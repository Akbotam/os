#include<stdio.h>

int file_name[15],file_size[15],fstart[15],freest[15],freesize[15],m=0,n=0,start;


 void create_file(int nameOfFile,int size)
   {
     int i,flag=1,j,a;

      for(i=0;i<=m;i++)
    if( freesize[i] >= size)
       a=i,flag=0;
      if(!flag)
       {
     for(j=0;j<n;j++);
         n++;
     file_name[j]=nameOfFile;
     file_size[j]=size;
     fstart[j]=freest[a];
     freest[a]=freest[a]+size;
                freesize[a]=freesize[a]-size;

                printf("\n The memory map will now be: \n\n");
     display_file();
       }
      else
       {
        printf("\nNo enough space is available.System compaction......");

         flag=1;

         compaction();
         display_file();

        for(i=0;i<=m;i++)
           if( freesize[i] >= size)
        a=i,flag=0;
     if(!flag)
      {
       for(j=0;j<n;j++);
          n++;
       file_name[j]=nameOfFile;
       file_size[j]=size;
       fstart[j]=freest[a];
       freest[a]+=size;
       freesize[a]-=size;
       printf("\n The memory map will now be: \n\n");
       display_file();
      }
     else
     printf("\nNo enough space.\n");
       }
  }

void delete_file(int nameOfFile)
  {
    int i,j,k,flag=1;
     for(i=0;i<n;i++)
       if(file_name[i]==nameOfFile)
           break;
     if(i==n)
       {
    flag=0;
    printf("\nNo such process exists......\n");
       }
      else
       {
       m++;
       freest[m]=fstart[i];
       freesize[m]=file_size[i];
     for(k=i;k<n;k++)
                   {
           file_name[k]=file_name[k+1];
                      file_size[k]=file_size[k+1];
                      fstart[k]=fstart[k+1];
                   }
                   n--;
       }
      if(flag)
       {
     printf("\n\n After deletion of this process the memory map will be : \n\n");
     display_file();
       }
   }

void compaction()
  {
    int i,j,size1=0,f_size=0;
      if(fstart[0]!=start)
       {
    fstart[0]=start;
    for(i=1;i<n;i++)
      fstart[i]=fstart[i-1]+file_size[i-1];
      }
     else
       {
      for(i=1;i<n;i++)
       fstart[i]=fstart[i-1]+file_size[i-1];
       }
     f_size=freesize[0];

     for(j=0;j<=m;j++)
       size1+=freesize[j];
      freest[0]=freest[0]-(size1-f_size);
      freesize[0]=size1;
      m=0;
 }

void display_file()
    {
     int i;

     printf("\n\nNAME     SIZE    STARTING ADDRESS      \n\n");
      for(i=0;i<n;i++)
       printf(" %d%10d%10d\n\n",file_name[i],file_size[i],fstart[i]);
     printf("\n\n");
     printf("\n\n***  FREE SPACE TABLE  ***\n\n");
     printf("FREE START ADDRESS             FREE SIZE        \n\n");
     for(i=0;i<=m;i++)
     printf("      %d                          %d\n",freest[i],freesize[i]);
   }

   int main()
   {
     int nameOfFile,size,choice,i;
     int *ptr;
     ptr=(int *)malloc(sizeof(int)*100);// Here we allocate start space for file by the system
     start=freest[0]=(int)ptr;
     freesize[0]=1000;

     printf("\n\n");
     printf(" Free start address         Free Size        \n\n");

     for(i=0;i<=m;i++)
       printf("    %d                  %d\n",freest[i],freesize[i]);
       printf("\n\n");
      while(1)
    {

      printf("1.Create file.\n");
      printf("2.Delete file.\n");
      printf("3.Compaction.\n");
      printf("4.Exit.\n");
      printf("Enter your choice: ");
         scanf("%d",&choice);
      switch(choice)
       {
         case 1:
            printf("\nEnter the name of file: ");
              scanf("%d",&nameOfFile);
            printf("\nEnter the size of the file: ");
              scanf("%d",&size);
            create_file(nameOfFile,size);
            break;
         case 2:
            printf("\nEnter the file name which you want to delete: ");
              scanf("%d",&nameOfFile);
            delete_file(nameOfFile);
            break;
         case 3:
             compaction();
             printf("\nAfter compaction the tables will be:\n");
             display_file();
             break;
         case 4:
             exit(1);
         default:
             printf("\nYou have entered a wrong choice.\n");
       }
    }

 }
