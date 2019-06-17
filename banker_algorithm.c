#include <stdio.h>

int current[10][10], maximum_claim[10][10], available[10];
int allocation[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int maxres[10], running[10], safe = 0;
int counter = 0, i, j, exec, m, n, k = 1;

int main()
{
	printf("\nEnter number of processes: ");
    	scanf("%d", &n);

    	for (i = 0; i < n; i++)
	{
        	running[i] = 1;
        	counter++;
    	}

    	printf("\nEnter number of resources: ");
    	scanf("%d", &m);

    	printf("\nEnter maximum number of instances of resources:");
    	for (i = 0; i < m; i++)
	{
	        scanf("%d", &maxres[i]);
    	}

   	printf("\nEnter Allocated Resource\n");
    	for (i = 0; i < n; i++)
	{
	        for(j = 0; j < m; j++)
		{
  			scanf("%d", &current[i][j]);
        	}
    	}

    	printf("\nEnter Maximum Claim to complete the work of processes:\n");
    	for (i = 0; i < n; i++)
	{
        	for(j = 0; j < m; j++)
		{
            		scanf("%d", &maximum_claim[i][j]);
        	}
    	}

    	for (i = 0; i < n; i++)
	{
        	for (j = 0; j < m; j++)
		{
            		allocation[j] += current[i][j];
        	}
    	}

    	printf("\nAllocated resources:");
    	for (i = 0; i < m; i++)
	{
        	printf("\t%d", allocation[i]);
    	}

    	for (i = 0; i < m; i++)
	{
	        available[i] = maxres[i] - allocation[i];
	}

    	printf("\nAvailable resources:");
    	for (i = 0; i < m; i++)
	{
        	printf("\t%d", available[i]);
    	}
    	printf("\n");

    	while (counter != 0)
	{
        	safe = 0;
        	for (i = 0; i < n; i++)
		{
            		if (running[i])
			{
                		exec = 1;
                		for (j = 0; j < m; j++)
				{
                    			if (maximum_claim[i][j] - current[i][j] > available[j])
					{
                        			exec = 0;
                        			break;
                    			}
                		}
                		if (exec)
				{
                    			printf("\nProcess%d is executing\n", i + 1);
                    			running[i] = 0;
                    			counter--;
                    			safe = 1;

                    			for (j = 0; j < m; j++)
					{
                        			available[j] += current[i][j];
                    			}
			                break;
                		}
            		}
        	}
        	if (!safe)
		{
            		printf("\nThe processes are in unsafe state.\n");
            		break;
        	}
		else
		{
            		printf("\nThe process is in safe state");
        	}
    	}
    	return 0;
}
