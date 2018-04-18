#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int process_count,j,n,time,remain,flag=0,time_qnt; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  
  cout<<"\n \t\t     ROUND ROBIN CPU SCHEDULING \t\t\n";
  
  cout<<"\nEnter Number of Processes:\n";
  cin>>n;
  remain=n;
  for(process_count=0;process_count<n;process_count++)
  {
  	cout<<"\nEnter Arrival Time and Burst Time for Process Process Number "<<process_count+1<<" :\n"; 
   	cin>>at[process_count];
   	cin>>bt[process_count];
   	rt[process_count]=bt[process_count]; 
  }
  
  cout<<"\nEnter Time Quantum:\n";
  cin>>time_qnt;
  cout<<"\n\nPROCESS\t|TURNAROUND TIME|WAITING TIME\t\n\n";
 // time=0;
  //process_count=0;
for(time=0,process_count=0;remain!=0;)
  {
  	 if(rt[process_count]<=time_qnt && rt[process_count]>0) 
    { 
      time+=rt[process_count]; 
      rt[process_count]=0; 
      flag=1; 
    } 
    else if(rt[process_count]>0) 
    { 
      rt[process_count]-=time_qnt; 
      time+=time_qnt; 
    } 
     if(rt[process_count]==0 && flag==1) 
    {
		remain--;
		cout<<"P["<<process_count+1<<"]\t|\t"<<time-at[process_count]<<"\t|\t"<<time-at[process_count]-bt[process_count]<<"\n";
		 wait_time+=time-at[process_count]-bt[process_count]; 
      	turnaround_time+=time-at[process_count]; 
      	flag=0;  
	} 
    if(process_count==n-1) 
      process_count=0; 
    else if(at[process_count+1]<=time) 
      process_count++; 
    else 
      process_count=0; 
      
    
  } 
   cout<<"\nAverage Waiting Time= "<<wait_time*1.0/n; 
  cout<<"\nAverage Turnaround Time= "<<turnaround_time*1.0/n; 
  
  return 0; 
  
}


