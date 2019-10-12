#include<stdio.h>
struct Patients{
int Pid;
int CheckUpTime;
int Priority;
int ArrivalHour;
int CheckUpTimeLeft;
int WaitTimeRoundRobin;
int TurnAroundTimeRoundRobin;
int DoneRoundRobin;
}Temp1,Temp,DocTemp;
int main()
{	
	int PatNo;
	int DocNo;
	int Option;
	int Time=0;	
	int Count=0;
	int PatLeft;
	int SumPriority=0;
	printf("\nNo. of patients? ");
	scanf("%d",&PatNo);
	PatLeft=PatNo;
	struct Patients Pat[PatNo];	
	double AvgWT=0,AvgTAT=0;
	for(int i=0;i<PatNo;i++)
	{
		Pat[i].Priority=0;
		printf("\nPatient ID? ");
		scanf("%d",&Pat[i].Pid);
		printf("CheckUp Time? ");
		scanf("%d",&Pat[i].CheckUpTime);
		printf("ArrivalHour? ");
		scanf("%d",&Pat[i].ArrivalHour);
		Pat[i].CheckUpTimeLeft=Pat[i].CheckUpTime;
		Pat[i].DoneRoundRobin=0;
		Pat[i].WaitTimeRoundRobin=0;
		Pat[i].TurnAroundTimeRoundRobin=0;
	}
	
	int Done=0;	
	printf("\nEnter \n1.for RoundRobin");
	scanf("%d",&Option);
	if(Option==1 || 1)
	{	
		int Quantum;
		printf("Quantum?");
		scanf("%d",&Quantum);
		printf("\n***********For RoundRobin************");
		for(Time=0,Count=0;PatLeft!=0;) 
 		{ 
    		if(Pat[Count].CheckUpTimeLeft<=Quantum && Pat[Count].CheckUpTimeLeft>0) 
    			{ 
      				Time+=Pat[Count].CheckUpTimeLeft; 
      				Pat[Count].CheckUpTimeLeft=0; 
      				Done=1; 
    			} 
    		else if(Pat[Count].CheckUpTimeLeft>0) 
    			{		 
      				Pat[Count].CheckUpTimeLeft-=Quantum; 
      				Time+=Quantum; 
    			}	 
    		if(Pat[Count].CheckUpTimeLeft==0 && Done==1) 
    			{		 
      				PatLeft--; 
      				Pat[Count].WaitTimeRoundRobin+=Time-Pat[Count].ArrivalHour-Pat[Count].CheckUpTime; 
			        Pat[Count].TurnAroundTimeRoundRobin+=Time-Pat[Count].ArrivalHour; 
      				Done=0; 
    			}	 
    		if(Count==PatNo-1) 
      				Count=0; 
    		else if(Pat[Count+1].ArrivalHour<=Time) 
      				Count++; 
    		else 
      				Count=0; 
 	   } 
	   for(int i=0;i<PatNo;i++)
 	   { 	
			printf("\n------------------------- \nFor Patient Number %d \n-------------------------",i);
			printf("\nWaiting Time= %d",Pat[i].WaitTimeRoundRobin); 
  			printf("\nTurnaround Time = %d \n*-*-*-*-*-*-*-*-*-*-*-*-*-",Pat[i].TurnAroundTimeRoundRobin); 
			AvgWT+=Pat[i].WaitTimeRoundRobin;
			AvgTAT+=Pat[i].TurnAroundTimeRoundRobin;
	   }
	   printf("\nAverage Waiting Time= %f",AvgWT/PatNo); 
  	   printf("\nAverage Turnaround Time = %f",AvgTAT/PatNo);
	}		
return 0;
}	