#include<stdio.h>

#define n 4

int finishedPhilosophers = 0,i;

struct fork{
    int taken;
}forkAvailable[n];

struct philosp{
    int left;
    int right;
}PhilosNum[n];

void DiningProcess(int philID){
    if(PhilosNum[philID].left==5 && PhilosNum[philID].right==5)//means that philosophers has finished dining process
        printf("Philosopher %d finished his dinner\n",philID+1);

    else if(PhilosNum[philID].left==1 && PhilosNum[philID].right==1)//means philosopher could bring enough resourses to start dining process
    {

            printf("Philosopher %d finished his dinner\n",philID+1);

            PhilosNum[philID].left = PhilosNum[philID].right = 5;
            int otherFork = philID-1;

            if(otherFork== -1)
                otherFork=(n-1);

           forkAvailable[philID].taken = forkAvailable[otherFork].taken = 0;
            printf("Philosopher %d released fork %d and fork %d\n",philID+1,philID+1,otherFork+1);
            finishedPhilosophers++;
        }
        else if(PhilosNum[philID].left==1 && PhilosNum[philID].right==0){ //left already taken, trying for right fork
                if(philID==(n-1)){
                    if(forkAvailable[philID].taken==0){
                        forkAvailable[philID].taken = PhilosNum[philID].right = 1;
                        printf("Fork %d taken by philosopher %d\n",philID+1,philID+1);
                    }else{
                        printf("Philosopher %d is waiting for fork %d\n",philID+1,philID+1);
                    }
                }else{
                        int dupphilID = philID;
                    philID-=1;

                    if(philID== -1)
                        philID=(n-1);

                    if(forkAvailable[philID].taken == 0){
                        forkAvailable[philID].taken = PhilosNum[dupphilID].right = 1;
                        printf("Fork %d taken by Philosopher %d\n",philID+1,dupphilID+1);
                    }else{
                        printf("Philosopher %d is waiting for Fork %d\n",dupphilID+1,philID+1);
                    }
                }
            }
            else if(PhilosNum[philID].left==0){ //means philosopher has no resources yet
                    if(philID==(n-1)){
                        if(forkAvailable[philID-1].taken==0){
                            forkAvailable[philID-1].taken = PhilosNum[philID].left = 1;
                            printf("Fork %d taken by philosopher %d\n",philID,philID+1);
                        }else{
                            printf("Philosopher %d is waiting for fork %d\n",philID+1,philID);
                        }
                    }else{
                        if(forkAvailable[philID].taken == 0){
                            forkAvailable[philID].taken = PhilosNum[philID].left = 1;
                            printf("Fork %d taken by Philosopher %d\n",philID+1,philID+1);
                        }else{
                            printf("Philosopher %d is waiting for Fork %d\n",philID+1,philID+1);
                        }
                    }
        }else{}
}

int main(){
    for(i=0;i<n;i++)
        forkAvailable[i].taken=PhilosNum[i].left=PhilosNum[i].right=0;

    while(finishedPhilosophers<n){
        for(i=0;i<n;i++)
            DiningProcess(i);
        printf("\nTill now num of philosophers finished dinner are %d\n\n",finishedPhilosophers);
    }

    return 0;
}
