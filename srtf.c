#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int at[10],bt[10],rt[10],end,i,s;
int r=0,n,t,sumw=0,sumt=0;
int ct[10],p[10],k=0,j;

void sort()
{
    int temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i] > p[j])
            {
                temp= p[i];
                p[i] = p[j];
                p[j] = temp;
                
                temp = ct[i];
                ct[i] = ct[j];
                ct[j] = temp;
            }
 
        }
    }
}

void *srtf()
{
  s=9;
  for(i=0;i<n;i++)
  {
    if(at[i]<=t && rt[i]<rt[s] && rt[i]>0)
    {
      s=i;
    }
  }
  
  rt[s]--;
  
  if(rt[s]==0)
  {
    r++;
    end=t+1;
    ct[k]=end;
    p[k]=s;
    k++;
    sumw+=end-bt[s]-at[s];
    sumt+=end-at[s];
  }
}

int main()
{
  printf("No of Processes : ");
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
  {
    printf("Arrival time for Process P%d : ",i+1);
    scanf("%d",&at[i]);
    printf("Enter burst time for Process P%d : ",i+1);
    scanf("%d",&bt[i]);
    if(bt[i]>10)
    {
      printf("\nBurst time should be less than 10\n");
      printf("Enter burst time for Process P%d : ",i+1);
      scanf("%d",&bt[i]);
    }
    rt[i]=bt[i];
  }

  printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
  rt[9]=9999;
  for(t=0;r!=n;t++)
  {
    if(t<3)
      sleep(1);
    else
    {
      pthread_create(&processes[r], NULL, srtf, NULL);
      pthread_join(processes[r], NULL);
    }
  }
  sort();
  
  for(i=0;i<k;i++)
    printf("\nP[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d",p[i]+1,at[i],bt[i],ct[p[i]],ct[p[i]]-at[p[i]],ct[p[i]]-bt[p[i]]-at[p[i]]);
  
  printf("\n\nAverage waiting time = %.2f\n",sumw*1.0/n);
  printf("Average Turnaround time = %.2f\n",sumt*1.0/5);
}

}
