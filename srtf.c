#include<stdio.h>
#include<unistd.h>

int main()
{
  int at[10],bt[10],rt[10],endTime,i,smallest;
  int remain=0,n,time,sum_wait=0,sum_turnaround=0;
  printf("Enter no of Processes : ");
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
  {
    printf("Enter arrival time for Process P%d : ",i+1);
    scanf("%d",&at[i]);
    printf("Enter burst time for Process P%d : ",i+1);
    scanf("%d",&bt[i]);
    rt[i]=bt[i];
  }
}
