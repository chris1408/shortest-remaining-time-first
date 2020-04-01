#include<stdio.h>
#include<unistd.h>

int main()
{
  int at[10],bt[10],rt[10],end,i,s;
  int r=0,n,time,sumw=0,sumt=0;
  printf("No of Processes : ");
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
  {
    printf("Arrival time for Process P%d : ",i+1);
    scanf("%d",&at[i]);
    printf("Enter burst time for Process P%d : ",i+1);
    scanf("%d",&bt[i]);
    rt[i]=bt[i];
  }

  printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
  rt[9]=9999;
  for(time=0;r!=n;time++)
  {
      s=9;
      
      for(i=0;i<n;i++)
      {
        if(at[i]<=time && rt[i]<rt[s] && rt[i]>0)
        {
          s=i;
        }
      }
      
      rt[s]--;
      
      if(rt[s]==0)
        {
          r++;
          end=time+1;
          printf("\nP[%d]\t|\t%d\t|\t%d",s+1,end-at[s],end-bt[s]-at[s]);
          sumw+=end-bt[s]-at[s];
          sumt+=end-at[s];
        }
   }
  

  printf("\n\nAverage waiting time = %f\n",sumw*1.0/n);
  printf("Average Turnaround time = %f",sumt*1.0/5);
  return 0;

}
