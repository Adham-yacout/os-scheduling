#include<iostream>
#include<istream>
#include <queue>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
struct process{
  string pid;
  int tat=0;
 
  int wait_time=0;  
  int arrival_time=0;
  int service_time=0;
  int start_time=0;
  int finish_time=0;
  int condition[30]={ 0 };/* this array is used to store values either 0,1,2  0->no operation 1->working 2->wait*/
  bool working = false;
  int index=0;
  float ratio=0;
  string answer="";
    float normaltat=0;
  float meantat=0;
  float meannormal=0;
// process *p;
};
float totalturn=0; //used to calculate total turnaround time
float totalnorm=0; //used to calculate total normal turnaround time
int displaytype=0; //used to select which display type to use trace or stats
void totaltat(process p[],int number)
{
int i=0;
for(i=0;i<number;i++)
{
totalturn+=p[i].tat;
}
totalturn/=number;
}
void totalnormal(process p[],int number)
{
int i=0;
for(i=0;i<number;i++)
{
totalnorm+=p[i].normaltat;
}
totalnorm/=number;
}

//functions used to compare service time,index, ratio of two functions
bool comparesrt(process i1, process i2)
{
    return (i1.service_time < i2.service_time);
}
bool compareindex(process i1,process i2)
{
return (i1.index<i2.index);
}
bool compareratio(process i1, process i2)
{
    return (i1.ratio > i2.ratio);
}
void normtat(process *p){
p->normaltat=float(p->tat)/float(p->service_time);
}
  void tat2(process *p){
    p->tat=p->wait_time + p->service_time;
   
  // p.tat=p.finish_time - p.arrival_time;
}
void wait(process p,int j,int i){
    if (i== 1&& j!=0){
       
 // p[j].wait_time=p[j].finish_time - p[j].arrival_time - p[j].service_time;}
  p.wait_time=p.tat-p.service_time;
}}
void finish(process *p ){
  // if(type_s == "1")
   
 
   p->finish_time=p->arrival_time+p->service_time+p->wait_time;
 
   
}
//stats
void display2(process p[],int total_time,int noprocess,string display)
{  /*this function is used to represent the stats output we used an idea of printing row by row
    so you will find each row in the file is represente alone and handling all the possible outcomes of either integers
    or floats to be identical to our output format
*/
int i=0;
cout<<display;
printf("\n");
cout<<"Process";
cout<<"    |  ";
string spaces="\n";
for(i=0;i<noprocess;i++)
{
cout<<p[i].pid;
if(i==noprocess-1)
{
printf("  |");
}
else
{
printf("  |  ");
}

}
cout<<spaces;
cout<<"Arrival";
cout<<"    |  ";
for(i=0;i<noprocess;i++)
{
cout<<p[i].arrival_time;
if(i==noprocess-1)
{
printf("  |");
}
else
{
printf("  |  ");
}
}
cout<<spaces;
cout<<"Service";
cout<<"    |  ";
for(i=0;i<noprocess;i++)
{
cout<<p[i].service_time;
if(i==noprocess-1)
{
printf("  |");
}
else
{
printf("  |  ");
}
}
printf(" Mean|");
cout<<spaces;
cout<<"Finish ";
cout<<"    |";
for(i=0;i<noprocess;i++)
{

if(i==noprocess-1)
{
if(p[i].finish_time>=10)
{
printf(" ");
cout<<p[i].finish_time;
printf("  |");
}
else{

printf("  ");
cout<<p[i].finish_time;
printf("  |");
}

}
else
{
if(p[i].finish_time>10)
{
printf(" ");
cout<<p[i].finish_time;
printf("  |");
}
else{
printf("  ");
cout<<p[i].finish_time;
printf("  |");
}
}
}
printf("-----|");
cout<<spaces;
cout<<"Turnaround";
cout<<" |";
for(i=0;i<noprocess;i++)
{

if(i==noprocess-1)
{
if(p[i].tat>10)
{
printf(" ");
cout<<p[i].tat;
printf("  |");
}
else{
printf("  ");
cout<<p[i].tat;
printf("  |");
}

}
else
{
if(p[i].tat>10)
{
printf(" ");
cout<<p[i].tat;
printf("  |");
}
else{
printf("  ");
cout<<p[i].tat;
printf("  |");
}
}
}
if(totalturn>=10)
{
printf("%.2f|",totalturn);
}
else{
printf(" %.2f|",totalturn);
}


cout<<spaces;
cout<<"NormTurn";
cout<<"   |";
for(i=0;i<noprocess;i++)
{

if(i==noprocess-1)
{
if(p[i].normaltat>10)
{
printf(" ");
printf("%.2f",p[i].normaltat);

printf("|");
}
else{
printf(" ");
printf("%.2f",p[i].normaltat);
printf("|");
}

}
else
{
if(p[i].tat>10)
{
printf(" ");
printf("%.2f",p[i].normaltat);
printf("|");
}
else{
printf(" ");
printf("%.2f",p[i].normaltat);
printf("|");
}
}
}
printf(" %.2f|",totalnorm);

cout<<spaces;
cout<<spaces;

}
void display(process p[],int total_time,int noprocess,string display){
/*either display 1 or 2 have the same idea of printing row by row to reach the final structure*/
int num=0;
int i;
cout << display;
printf("  ");
for(i=0;i<=total_time;i++)
{

if(num==10)
{
//used to handle the print where we print from 0 -> 9 and repeat again
num=0;
}

cout<<num;
printf(" ");
num=num+1;
}
printf("\n");
for(i=0;i<2*total_time+8;i++)
{
printf("-");

}
printf("\n");
int j=0;
for(j=0;j<noprocess;j++)
{
cout<<p[j].pid;
printf("     |");
for (i=0;i<total_time;i++)
{

if(p[j].condition[i]==1)
{
printf("*|");
}
else if(p[j].condition[i]==2)
{
printf(".|");
}
else if(p[j].condition[i]==0)
{
printf(" |");
}


}
printf(" \n");
}
for(i=0;i<2*total_time+8;i++)
{
printf("-");

}
printf("\n");
printf("\n");

}
void fcfs(process p[],int total_time,int noprocess_int){
/* first come first serve has the idea of the process that arrives first will be executed first*/
    int i;
    int j;
    int k=0;
    int timetemp;
   
    for(i=0;i<noprocess_int;i++){
    // we take the service time of process in order
        timetemp=p[i].service_time;
        while(timetemp>0){
            timetemp--;
         //time temp -- represents that a process is running
            for(j=i+1;j<noprocess_int;j++){
                if(p[j].arrival_time<=k){
                p[j].wait_time++;
                p[j].condition[k]=2;
                //we loop around other processes if they have already arrived that means that they are waiting
                }
            }
            p[i].condition[k]=1;
             k++;
           
        }
         p[i].finish_time=k;
    }
    for(i=0;i<noprocess_int;i++)
{
//used to calculate turnaround time , normal turnaround for eac process
tat2(&p[i]);
normtat(&p[i]);

}
totaltat(p,noprocess_int);
totalnormal(p,noprocess_int);
    string type="FCFS";
    if(displaytype==1)
{
//trace
display(p,total_time,noprocess_int,type);

}
else{
//stats
display2(p,total_time,noprocess_int,type);

}
   
   
}
void srt(process p[],int total_time,int noprocess_int){
//the idea of srt is we want to see the shortest remaning time for a process to enter execution phase
    int i,j,k,w,a,x=99,y=88;
    vector <process> work;
   
    int st[noprocess_int];
    process hamada;
     
    process temp;
    int flaghamada=0;
    for(i=0;i<noprocess_int;i++)
{
//for loop used to store service times of processes as i will change them later on so i need them back
st[i]=p[i].service_time;
}

for(i=0;i<total_time;i++)
{
for(j=0;j<noprocess_int;j++)
{
if(p[j].arrival_time==i )
{       //if a process ariives we will push it in the working vector
work.push_back(p[j]);
}
}
sort(work.begin(),work.end(), comparesrt);
//after sorting by the smallest remaining time we will operate on the smallest vector[0]

hamada=work[0];



for(k=0;k<noprocess_int;k++)
{

if(!strcmp(p[k].pid.c_str(),hamada.pid.c_str()))
{  //looping until getting the original process not a copy to operate on it
break;
}
}
p[k].service_time--;
work[0].service_time--;
p[k].condition[i]=1;
for(w=1;w<work.size();w++)
{  //waiting area
p[work[w].index].condition[i]=2;
p[work[w].index].wait_time++;
}
if(p[k].service_time==0)
{  //if process finished working all of the service tim e remove from work and assign the finish time
  work.erase(work.begin());
  p[k].finish_time=i+1;
 
}

}
  for(i=0;i<noprocess_int;i++)
{

p[i].service_time=st[i];
}
   for(i=0;i<noprocess_int;i++)
{
tat2(&p[i]);
normtat(&p[i]);

}
totaltat(p,noprocess_int);
totalnormal(p,noprocess_int);

if(displaytype==1)

{string type ="SRT ";
display(p,total_time,noprocess_int,type);

}
else{
string type ="SRT";
display2(p,total_time,noprocess_int,type);

}

}
void roundrobin(process p[],int total_time,int noprocess_int,int userq)
{
//depending on the input quantum we will decide each process time in execution  
int i,j,k,w;
int st[noprocess_int];
process hamada;
vector <process> work;
int check=99;
//used to check if a new process will start or the old one still has quantum remaining
//int userq=0;
userq-=1;
int q=0;//keep track of the quantum of each process
process inverse;
for(i=0;i<noprocess_int;i++)
{ //storing of service time
st[i]=p[i].service_time;
}
for(i=0;i<total_time;i++)
{
for(j=0;j<noprocess_int;j++)
{
	if(j==check)
	{ 
	continue;
	}
	else if(p[j].arrival_time==i )
	{
	work.push_back(p[j]);
	}
}
if(check!=99)
	{ //if check changed then we will put the process again to work as still service time of it didnt reach zero
	work.push_back(p[check]);
	}
//the process that will execute
hamada = work[0];
// work.erase(work.begin());


for(k=0;k<noprocess_int;k++)
{
//to get actual process not a copy
	if(!strcmp(p[k].pid.c_str(),hamada.pid.c_str()))
	{
	break;
	}
}
p[k].service_time--;
p[k].condition[i]=1; //working
for(w=1;w<work.size();w++)
{	//wait section
	p[work[w].index].condition[i]=2;
	p[work[w].index].wait_time++;
}
if(q<userq && p[k].service_time>0)
{
	//while process still have remaming service time and still has a remaining q for it we wont remove thee process
	q++;
	check=99;
}
else if(p[k].service_time>0)
{
        //if the q dor process has ended but the process needs service time again then remove it from work and we will add it later after checking 
        //who will have the right to operate next
	work.erase(work.begin());
	q=0;
	check=k;
	inverse=p[k];
}
else{
//both service time and q has ended then we dont need the process again remove from worrking and assign finish time
	q=0;
	work.erase(work.begin());
	p[k].finish_time=i+1;
	check=99;
}

}
for(i=0;i<noprocess_int;i++)
{

p[i].service_time=st[i];
}
for(i=0;i<noprocess_int;i++)
{
tat2(&p[i]);
normtat(&p[i]);

}
totaltat(p,noprocess_int);
totalnormal(p,noprocess_int);
string hamada2=to_string(userq+1);
string salma ="RR-";
string type =salma+hamada2;
if(displaytype==1)
{display(p,total_time,noprocess_int,type);

}
else{
display2(p,total_time,noprocess_int,type);

}

}

void spn(process p[],int total_time,int noprocess_int){
//shortest process will be the next to work
    int i;
    int j;
    int k;
    int inner,h;
 vector <process> varrive;
 vector <process> vfinish;
  int m;
 process run;
// cout<<"1";
for ( i =0; i<total_time;i++)

{
    for( j=0; j<noprocess_int;j++){
       
        if (p[j].arrival_time==i ){
            varrive.push_back(p[j]);
           
          }}
          //sorting them accorfing to service time to select smallest one to work
          sort(varrive.begin(),varrive.end(), comparesrt);
           run =varrive[0];
           for(inner=0;inner<noprocess_int;inner++)
           {
            if(!(strcmp(p[inner].pid.c_str(),varrive[0].pid.c_str())))
            {
            p[inner].start_time=i;
           
            }
           }
          // cout<<run.index;
           //run a
            varrive.erase(varrive.begin());
            run.index=i;
           
           if(run.index==0){
                run.finish_time=run.arrival_time+run.service_time;
               
           }
           else{
                run.finish_time=vfinish[vfinish.size()-1].finish_time+run.service_time;
           }
           
           run.tat=run.finish_time-run.arrival_time;
           run.normaltat= float(run.tat)/float(run.service_time);
           
           
           
           vfinish.push_back(run);
           for(k=0;k<varrive.size();k++){
               varrive[k].wait_time= varrive[k].wait_time+run.service_time;
           }
           for(m=0;m<run.service_time-1;m++){
            i++;
            for( j=0; j<noprocess_int;j++){
       
        if (p[j].arrival_time==i){
            varrive.push_back(p[j]);
           
          }
           
            }
           }
          }
           for(inner=0;inner<noprocess_int;inner++)
            { //calculating wait time for processes 
            int waittime = p[inner].start_time-p[inner].arrival_time;
            for (h=p[inner].arrival_time;h<p[inner].arrival_time+waittime;h++)
            {
            p[inner].condition[h]=2;
            }
            int work=p[inner].start_time+p[inner].service_time;
            for(h=p[inner].start_time ; h< work ;h++ )
            {
            p[inner].condition[h]=1;
            }
            //amla fe array display el wait mn kam le kam
            }
              for(i=0;i<noprocess_int;i++)
{
p[i].finish_time=p[i].start_time+p[i].service_time;
}
    for(i=0;i<noprocess_int;i++)
{
p[i].wait_time=p[i].start_time-p[i].arrival_time;
}
         
                         for(i=0;i<noprocess_int;i++)
{
tat2(&p[i]);
normtat(&p[i]);
//cout<<p[i].normaltat;
//printf("\n");
}
totaltat(p,noprocess_int);
totalnormal(p,noprocess_int);
   
    if(displaytype==1)
{ string type="SPN ";
display(p,total_time,noprocess_int,type);

}
else{
string type="SPN";
display2(p,total_time,noprocess_int,type);

}
}

void hrrn(process p[],int total_time,int noprocess_int){
//highest ratio will be executed
vector <process> varrive;
vector <process> vfinish;
  int i,j,inner;
  int m,k;
 process run;

for ( i =0; i<total_time;)//quantum
{
 for( j=0; j<noprocess_int;j++)
{
         if (p[j].arrival_time==i ){
         //if a process arrives enter to arrive vector
             p[j].ratio=(p[j].wait_time+p[j].service_time)/p[j].service_time;
            varrive.push_back(p[j]);
          }
    sort(varrive.begin(),varrive.end(), compareratio);
           run =varrive[0];
           
           for(inner=0;inner<noprocess_int;inner++)
           {
            if(!(strcmp(p[inner].pid.c_str(),varrive[0].pid.c_str())))
            {
            p[inner].start_time=i;
           //adding start time to each process
            }
           }
         
           
            varrive.erase(varrive.begin());
            run.index=i;
            //get start quantum
           if(run.index==0){
                run.finish_time=run.arrival_time+run.service_time;
               
           }
           else{
                run.finish_time=vfinish[vfinish.size()-1].finish_time+run.service_time;
           }
           
           run.tat=run.finish_time-run.arrival_time;
           run.normaltat= float(run.tat)/float(run.service_time);
         
           
           
           vfinish.push_back(run);
           for(k=0;k<varrive.size();k++){
               varrive[k].wait_time= varrive[k].wait_time+run.service_time;
               varrive[k].ratio=(varrive[k].wait_time+varrive[k].service_time)/varrive[k].service_time;
           }
           for(m=0;m<run.service_time-1;m++){
            i++;
            for( j=0; j<noprocess_int;j++){
       
        if (p[j].arrival_time==i){
            varrive[k].ratio=(varrive[k].wait_time+varrive[k].service_time)/varrive[k].service_time;
            varrive.push_back(p[j]);}}}
           
        
          i++;
          }}
          int h;
            for(inner=0;inner<noprocess_int;inner++)
            { //calculating wait time
            int waittime = p[inner].start_time-p[inner].arrival_time;
            for (h=p[inner].arrival_time;h<p[inner].arrival_time+waittime;h++)
            {
            p[inner].condition[h]=2;
            }
            int work=p[inner].start_time+p[inner].service_time;
            for(h=p[inner].start_time ; h< work ;h++ )
            {
            p[inner].condition[h]=1;
            }
            //amla fe array display el wait mn kam le kam
            }
              for(i=0;i<noprocess_int;i++)
{
p[i].finish_time=p[i].start_time+p[i].service_time;
}
    for(i=0;i<noprocess_int;i++)
{
p[i].wait_time=p[i].start_time-p[i].arrival_time;
}
            string type = "HRRN";
            for(i=0;i<noprocess_int;i++)
{
tat2(&p[i]);
normtat(&p[i]);
//cout<<p[i].normaltat;
//printf("\n");
}
totaltat(p,noprocess_int);
totalnormal(p,noprocess_int);
   
    if(displaytype==1)
{display(p,total_time,noprocess_int,type);

}
else{
display2(p,total_time,noprocess_int,type);

}
          }
 void Feedback(process p[],int total_time,int noprocess_int)
{ //declaring 5 ready vectors
    vector<process> v1;
    vector<process> v2;
    vector<process> v3;
    vector<process> v4;
    vector<process> v5;
   process r1;
    int going=0; //used to determine the direction of moving the process after finishing processing
    vector<process> wait;
    int st[noprocess_int];
    int i,k,w,j;
     for(i=0;i<noprocess_int;i++)
{
//for loop used to store service times of processes as i will change them later on so i need them back
st[i]=p[i].service_time;
}
for(i=0;i<total_time;i++)
{
for(j=0;j<noprocess_int;j++)
{
if(p[j].arrival_time==i)
{

if(going==1)
{ 
v1.erase(v1.begin());
v2.push_back(p[k]);
}
v1.push_back(p[j]);
wait.push_back(p[j]);
}
}
//checking all ready vectors in sequence
if(!v1.empty())
{

r1=v1[0];
v1.erase(v1.begin());
if(v1.empty()&&v2.empty())
{ //if no other process arrives at next quantum then it will be stored again in v1
going=1;
}
else{
going=2;
}


}
else if(!v2.empty())
{

r1=v2[0];
v2.erase(v2.begin());
going=3;
}
else if(!v3.empty())
{

r1=v3[0];
v3.erase(v3.begin());
going=4;
}
else if(!v4.empty())
{

r1=v4[0];
v4.erase(v4.begin());
going=5;
}
else if(!v5.empty())
{

r1=v5[0];
v5.erase(v5.begin());
}

//run
for(k=0;k<noprocess_int;k++)
{

if(!strcmp(p[k].pid.c_str(),r1.pid.c_str()))
{  //looping until getting the original process not a copy to operate on it
break;
}
}
p[k].service_time--;
//work[0].service_time--;
p[k].condition[i]=1;
if(p[k].service_time==0)
{  //if process finished working all of the service tim e remove from work and assign the finish time
 
  p[k].finish_time=i+1;
 
}

for(w=0;w<wait.size();w++)
{  //waiting area
if(wait[w].index==r1.index)
{
continue;
}
if(p[wait[w].index].service_time>0)
{ //wait section
p[wait[w].index].condition[i]=2;
p[wait[w].index].wait_time++;
}


}
if(p[k].service_time>0)
{ //section where process goes to next vector
if(going==1)
{
v1.push_back(p[k]);
}
else if(going==2)
{
v2.push_back(p[k]);
}
else if(going==3)
{
v3.push_back(p[k]);
}
else if(going==4)
{
v4.push_back(p[k]);
}
else if(going==5)
{
v5.push_back(p[k]);
}
}



}
string type = "FB-1";
 for(i=0;i<noprocess_int;i++)
{
//for loop used to store service times of processes as i will change them later on so i need them back
p[i].service_time=st[i];
}
            for(i=0;i<noprocess_int;i++)
{
tat2(&p[i]);
normtat(&p[i]);
//cout<<p[i].normaltat;
//printf("\n");
}
totaltat(p,noprocess_int);
totalnormal(p,noprocess_int);

      if(displaytype==1)
{display(p,total_time,noprocess_int,type);

}
else{
display2(p,total_time,noprocess_int,type);

}

   
}

int main(){

    string type_v,total_time,no_process,x;
    string type_s;
    char type_temp[4];    
    int totaltime_int=0;
    int noprocess_int=0;
    cin >>type_v;
    cin >>type_temp;
    cin >>total_time;
    int quantum;
    string stats="stats";
    string trace="trace";
    if(!strcmp(trace.c_str(),type_v.c_str()))
    {
    displaytype=1;
    }
    else{
    displaytype=2;
    }
    totaltime_int=stoi(total_time);
    cin >>no_process;
    noprocess_int=stoi(no_process);
    process p[noprocess_int];
    if(sizeof(type_temp)>1)
    {
   
    if(type_temp[2]=='\0')
    {
    x="0";
   
    }
    else
    {
    x=type_temp[2];
      quantum=stoi(x);
    }
    type_s=type_temp[0];
   
   
    }
    else{
    type_s=type_temp[0];
    }
   
   
 
   
       for(int i=0;i<noprocess_int;i++){

string s;


cin>>s;
stringstream str(s);

string arr[3];
int j=0;
string ptr;  
   int in =0;
   p[i].index=i;
    while (getline(str,ptr,','))  
    {  
       if(in==0)
       {
    p[i].pid=ptr;
   
    }
    else if (in==1){
    p[i].arrival_time=stoi(ptr);
   
     
    }
    else{
    p[i].service_time=stoi(ptr);
   
    }
    in++;
    }  





}

if (type_s == "1"){
   
    fcfs( p,totaltime_int,noprocess_int);
   // cout<<p[2].finish_time;
}
if (type_s == "4"){
    srt( p,totaltime_int,noprocess_int);}
if (type_s == "3"){
    spn( p,totaltime_int,noprocess_int);}
   
    if (type_s == "2")
    {
    roundrobin( p,totaltime_int,noprocess_int,quantum);
    }
    if (type_s == "5"){
    hrrn( p,totaltime_int,noprocess_int);}
    if (type_s == "6"){
    Feedback( p,totaltime_int,noprocess_int);}

return 0;
}
	

