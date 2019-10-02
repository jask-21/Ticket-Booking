#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
vector<vector<pair<string,int> > >shows(3);
int siz=0;
vector<vector<int> > seats(siz,vector<int>(20,0));
//vector<string>timeseat(siz);
queue< int> users;

void movies()
{
	shows[0].push_back(make_pair("9:00 am",0));
    shows[0].push_back(make_pair("12:30 pm",1));
    shows[0].push_back(make_pair("5:00 pm",2));
    shows[0].push_back(make_pair("10:00 pm",3));
    shows[0].push_back(make_pair("9:00 pm",4));
    shows[1].push_back(make_pair("10:30 am",5));
    shows[1].push_back(make_pair("12:00 pm",6));
    shows[1].push_back(make_pair("5:30 pm",7));
    shows[2].push_back(make_pair("12:00 pm",8));
    shows[2].push_back(make_pair("5:00 pm",9));
    siz =  shows[0].size() + shows[1].size() + shows[2].size();
    seats.resize(siz,vector<int>(20,0));
    //timeseat.resize(siz);
    
}

//    void seatshow()
//{   
//    int t=0;
//
//    for(int i=0;i<shows.size();i++)
//    {   
//    	for(int j=0;j<shows[i].size();j++)
//    	{ 
//    		timeseat[t]=shows[i][j];
//    		
//    		t++;
//		}
//	}
//	
////	for(int i=0;i<siz;i++)
////	{
////		for(int j=0;j<20;j++)
////		{
////			seats[i].push_back(0);
////		}
////	}
//}
	
	void showseat(int in)
{
		
	cout<<endl;
	cout<<"******************************************************************************"<<endl<<"Gold (Rs 200) -> "<<endl<<endl;
    for(int i=0;i<10;i++)
    {
    	
    	
    		if( seats[in][i]==1)
    	    cout<<i+1<<":taken ";
    	    else
    	    cout<<i+1<<":free ";
		
	
	}
	cout<<endl;
	cout<<endl<<"Silver(Rs 100) -> "<<endl<<endl;
	for(int i=0;i<10;i++)
    {
    	
      if( seats[in][i+10]==1)
    	    cout<<i+11<<":taken ";
    	    else
    	    cout<<i+11<<":free ";
		
		
	}
	cout<<endl;
	cout<<endl<<"********************************************************************************"<<endl;
}
void bookedseats(int a[],int n,int ind)
{
	for(int i=0;i<n;i++)
	{
		seats[ind][a[i]-1]=1;
	}
		
}

int cost(int a[],int n)
{   int amt=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=1&&a[i]<=10)
		{
			amt=amt+200;
		}
		else if(a[i]>=11&&a[i]<=20)
		{
			amt=amt+100;
		}
	}
    return amt;
}

void payment()
{
	cout<<endl<<endl<<" Paying by Credit Card"<<endl<<endl;
	cout<<" Enter Name on Card:";
	string n;
	cin>>n;
	for(int i=0;i<n.length();i++)
	{
		if((n[i]>='A'&&n[i]<='Z')||(n[i]>='a'&&n[i]<='z'))
		{
			continue;
		}
		else
		{
			cout<<endl<<" Enter valid name";
		payment();
		break;
		}
	}
	cout<<endl<<" Enter Card No.:";
	string num;
	cin>>num;
	if(num.length()!=16)
	{
		cout<<endl<<" Enter valid card no.";
		payment();
	
	}
	for(int i=0;i<num.length();i++)
	{
		if(num[i]>='0'&&num[i]<='9')
		{
			continue;
		}
		else
		{
			cout<<endl<<" Enter valid card no.";
		payment();
		break;
		}
	}
	cout<<endl<<" Enter CVV:";
	string cvv;
	cin>>cvv;
	if(cvv.length()!=3)
	{
		cout<<endl<<" Enter valid CVV";
		payment();
	}
    for(int i=0;i<cvv.length();i++)
	{
		if(cvv[i]>='0'&&cvv[i]<='9')
		{
			continue;
		}
		else
		{
			cout<<endl<<" Enter valid CVV";
		payment();
		break;
		}
	}
	
	cout<<endl<<endl<<" Payment Done";
}
void showticket(int in,int ind,string name,int a[],int t)
{   cout<<endl<<endl;
    cout<<"******************YOUR TICKET**************************"<<endl<<endl;
    cout<<" Movie Name:"<< "                " <<"Show Time:"<<endl<<endl;
	if(in==0)
	{
		cout<<"  Kalank";
	}
	else if(in==1)
	{
		cout<<"  The curse of weeping woman";
		
	}
	else if(in==2)
	{
		cout<<"  Avengers";
	}
	cout<< "                          " <<shows[in][ind].first<<endl<<endl;
	cout<<" Name: "<<name<<endl<<endl;
	cout<<" Seat Numbers: ";
	for(int i=0;i<t;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl<<endl<<"*******************************************************";
}
void show(int in)
{
	for(int i=0;i<shows[in].size();i++)
	{
		cout<<" "<<i+1<<"."<<shows[in][i].first<<endl;
	}
	cout<<endl<<" Kindly select timings:"<<endl;
	int showtime;
	cin>>showtime;
	//vector<string>::iterator it;
//	it = find(timeseat.begin(),timeseat.end(),shows[in][showtime-1]);
	int ind=shows[in][showtime-1].second;
//	cout<<ind;
	showseat(ind);
	cout<<endl<<" Kindly enter no. of seats:"<<endl;
	int t;
	cin>>t;
	cout<<endl<<" Kindly enter seats:"<<endl;
	int a[t];
	for(int i=0;i<t;i++)
	{
		cin>>a[i];
	}
	bookedseats(a,t,ind);
	string name;
	int f=0;
	while(f==0)
	{   
        cout<<endl<<" Enter name:";
	    
	    cin>>name;
	 	for(int i=0;i<name.length();i++)
	{
		if((name[i]>='A'&&name[i]<='Z')||(name[i]>='a'&&name[i]<='z'))
		{
			f=1;
			continue;
		}
		else
		{
			cout<<endl<<" Enter valid name"<<endl;
		 f=0;
		break;
		}
	}
	}
	int amt = cost(a,t);
	cout<<endl<<" Amount to be paid: "<<amt;
	payment();
	showticket(in,showtime-1,name,a,t);
}
void bookticket()
{   
   	cout<<endl<<"      Welcome to Ticbook     "<<endl;
   cout<<" Enter UserID:"<<endl;
   int id;
   cin>>id;
   if (id!=0)
   {
   	users.push(id);
   }
   else
   cout<<" *Enter valid ID*"<<endl;
   
   if(!users.empty())
   
   { 
	
	cout<<endl<<" Movies : "<<endl;
	cout<<endl<<" 1. Kalank"<<endl;
	cout<<" 2. The curse of weeping woman"<<endl;
	cout<<" 3. Avengers"<<endl;
	cout<<endl<<" Kindly Enter choice -"<<endl;
	int choice;
	cin>>choice;
	cout<<endl;
	show(choice-1);
	users.pop();
  }
 bookticket();	
}

int main()
{   
    movies();
    //seatshow();
//    for(int i=0;i<=3;i++)
//    {   
//    	users.push(i+1);
//	}

bookticket();
	
}





