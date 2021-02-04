#include <stdio.h>
#include <malloc.h>
int main()
{
    char *month[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    int *mtotal,*mavg;
    int ytotal=0,yavg=0;
    int inityear,finyear,duration;
    int i,j;
    printf("Enter the initial year: ");
    scanf("%d",&inityear);
    printf("Enter the final year: ");
    scanf("%d",&finyear);
    printf("\n");
    duration=finyear-inityear;
    int mspending[duration][12];
    mtotal=(int *)calloc(duration,sizeof(int));
    mavg=(int *)calloc(duration,sizeof(int));

    //calculation
    for(i=0;i<duration;i++)
    {
        printf("Enter the spendings for year %d:\n\n",inityear+i);
        for(j=0;j<12;j++)
        {
            printf("Spending in %s: ",month[j]);
            scanf("%d",&mspending[i][j]);
            mtotal[i]+=mspending[i][j];
            printf("\n");
        }
        mavg[i]=mtotal[i]/12;
        ytotal+=mtotal[i];
    }
    yavg=ytotal/duration;

    //printing the results

    for(i=0;i<duration;i++)
    {
        printf("In %d\n\n",inityear+i);
        for(j=0;j<12;j++)
        {
            printf("%s     ",month[j]);
        }

        printf("\n");

        for(j=0;j<12;j++)
        {
            printf("%d     ",mspending[i][j]);
        }
        printf("\n\n");
        printf("Total Expenditure: %d\n",mtotal[i]);
        printf("Average Expenditure: %d\n\n",mavg[i]);
    }
    printf("Your total spendings for %d years.\n\n",duration);
    printf("Total: %d\n",ytotal);
    printf("Average: %d\n",yavg);
    return 0;
}
