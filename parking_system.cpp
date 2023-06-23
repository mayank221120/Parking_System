#include<iostream>
using namespace std;
class Time
{
	public:
		int hr,min,sec;
		void setValue();
};
class Arrival:public Time
{
	public:
		void setValue()
		{
			cout<<"Enter Arrival Time  :\n";
			cin>>hr;
			if(hr<0||hr>23)
			{
		   		cout<<"Invalid Input\nTry again....."<<endl;
				setValue();
				return;
			}
			cin>>min;
			if(min<0||min>59)
			{
				cout<<"Invalid Input\nTry again....."<<endl;
				setValue();
				return;
			}
			cin>>sec;
			if(sec<0||sec>59)
			{
				cout<<"Invalid Input\nTry again....."<<endl;
				setValue();
				return;
			}
		}
};
class Departure:public Time
{
	public:
		void setValue()
		{
			cout<<"Enter Departure Time:\n";
			cin>>hr;
			if(hr<0||hr>23)
			{
				cout<<"Invalid Input\nTry again....."<<endl;
				setValue();
				return;
			}
			cin>>min;
			if(min<0||min>59)
			{
				cout<<"Invalid Input\nTry again....."<<endl;
				setValue();
				return;
			}
			cin>>sec;
			if(sec<0||sec>59)
			{
				cout<<"Invalid Input\nTry again....."<<endl;
				setValue();
				return;
			}
		}
}; 
class Calculate:public Arrival,public Departure
{
	public:
		int TimeAndDuration()
		{
			int h,m,dr,t;
			Arrival a;
			a.setValue();
			Departure d;
			d.setValue();
			m=d.min-a.min;
			t=d.hr;
			if(m<0)
			{
				m+=60;
				d.hr--;
			}
			h=d.hr-a.hr;
			if(h<0)
			h+=24;
			dr=h*60+m;
			cout<<endl<<endl<<"Arrival Time      :\t"<<a.hr<<":"<<a.min<<":"<<a.sec<<endl;
			cout<<"Departure Time    :\t"<<t<<":"<<d.min<<":"<<d.sec<<endl;
			cout<<"Duration          :\t"<<h<<" hours, "<<m<<" minutes"<<endl;
			return dr;
		}
		int Fare(float rate)
		{
			int rem,f;
			int d=TimeAndDuration();
			rem=d%30;
			if(rem>15)
			{
				d+=30-rem;
				f=(d/30)*(rate/2);
				return f;
			}
			f=(d/30)*(rate/2);
			return f;	
		}	
};
class vehicle:public Calculate
{
	public:
		string vecNo,nameOfOwner,nameOfVec;
		float rate;
};
class TwoWheeler:public vehicle
{
	public:
		void details(string vn,string n_own,string n_vec,float r)
		{
			int F=Fare(r);
			cout<<"Vehicle no.       :\t"<<vn<<endl;
			cout<<"Name of Owner     :\t"<<n_own<<endl;
			cout<<"Name of Vehicle   :\t"<<n_vec<<endl;
			cout<<"Fare              :\tRs."<<F<<endl;
		}
};
class FourWheeler:public vehicle
{
	public:
		void details(string vn,string n_own,string n_vec,float r)
		{
			int F=Fare(r);
			cout<<"Vehicle no.       :\t"<<vn<<endl;
			cout<<"Name of Owner     :\t"<<n_own<<endl;
			cout<<"Name of Vehicle   :\t"<<n_vec<<endl;
			cout<<"Fare              :\tRs."<<F<<endl;
		}
};
class Truck:public vehicle
{
	public:
		void details(string vn,string n_own,string n_vec,float r)
		{
			int F=Fare(r);
			cout<<"Vehicle no.       :\t"<<vn<<endl;
			cout<<"Name of Owner     :\t"<<n_own<<endl;
			cout<<"Name of Vehicle   :\t"<<n_vec<<endl;
			cout<<"Fare              :\tRs."<<F<<endl;
		}
};

void two_wheeler()
{
	TwoWheeler t;
	cout<<"Enter Vehicle no.:"<<endl;
	getline(cin,t.vecNo);
	cout<<"Enter Owner's Name:"<<endl;
	getline(cin,t.nameOfOwner);
	cout<<"Enter Vehicle's Name:"<<endl;
	getline(cin,t.nameOfVec);
	t.rate=10;
	t.details(t.vecNo,t.nameOfOwner,t.nameOfVec,t.rate);
}
void four_wheeler()
{
	FourWheeler f;
	cout<<"Enter Vehicle no.:"<<endl;
	getline(cin,f.vecNo);
	cout<<"Enter Owner's Name:"<<endl;
	getline(cin,f.nameOfOwner);
	cout<<"Enter Vehicle's Name:"<<endl;
	getline(cin,f.nameOfVec);
	f.rate=20;
	f.details(f.vecNo,f.nameOfOwner,f.nameOfVec,f.rate);
}
void truck()
{
	Truck t;
	cout<<"Enter Vehicle no.:"<<endl;
	getline(cin,t.vecNo);
	cout<<"Enter Owner's Name:"<<endl;
	getline(cin,t.nameOfOwner);
	cout<<"Enter Vehicle's Name:"<<endl;
	getline(cin,t.nameOfVec);
	t.rate=40;
	t.details(t.vecNo,t.nameOfOwner,t.nameOfVec,t.rate);
}
int main()
{
	int ch;
	char c;
	cout<<"Rate for parking two wheeler vehicles are Rs. 10 per hour"<<endl;
	cout<<"Rate for parking four wheeler vehicles are Rs. 20 per hour"<<endl;
	cout<<"Rate for parking trucks are Rs. 40 per hour"<<endl;
	cout<<endl<<"NOTE:-The fare will be charged for the duration estimated to nearest half hour. For example, 1 hr, 10 min will be estimated to 1 hr and 1hr, 21 min will be estimated to 1 hr, 30 min."<<endl<<endl;
	do
	{
		cout<<"Press 1 for two wheeler."<<endl;
		cout<<"Press 2 for four wheeler."<<endl;
		cout<<"Press 3 for truck."<<endl;
		cout<<"Press 0 to exit."<<endl;
		cout<<endl<<"Enter your choice:"<<endl;
		cin>>ch;
		fflush(stdin);
		switch(ch)
		{
			case 1:
				two_wheeler();
				break;
			case 2:
				four_wheeler();
				break;
			case 3:
				truck();
				break;
			case 0:
				break;
			default:
				cout<<"Invalid Choice"<<endl;
				break;
		}
		cout<<endl<<"Do you want to continue? Press Y/y to continue or any key to exit."<<endl;
		cin>>c;
	}
	while(c=='Y'||c=='y');
}
