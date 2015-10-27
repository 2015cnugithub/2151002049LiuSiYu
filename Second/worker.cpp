#include<iostream>
using namespace std;
class Worker;
ostream & operator<<(ostream &out,Worker& worker);
class Worker{
public:
	virtual void Compute_pay(double hours)=0;
	Worker(char *a,int b,char *c,int d);
	~Worker(){}
	 friend ostream & operator<<(ostream &out,Worker& worker);
	char * name;
	int age;
	char * sex;
	int pay_per_hour;
};
Worker::Worker(char *a,int b,char *c,int d){
      name=a;
	  age=b;
	  sex=c;
	  pay_per_hour=d;
}

class HourlyWorker:public Worker{
public:
	void Compute_pay(double hours);
	HourlyWorker(char *a,int b,char *c,int d):Worker(a,b,c,d){}
};
void HourlyWorker::Compute_pay(double hours)
{
  if(hours<=40)
	  cout<< pay_per_hour*hours<<endl;
  else
	  cout<< (pay_per_hour*40+1.5*pay_per_hour*(hours-40))<<endl;
}
class SalariedWorker:public Worker{
public:
	void Compute_pay(double hours);
	SalariedWorker(char *a,int b,char *c,int d):Worker(a,b,c,d){}
};
void SalariedWorker::Compute_pay(double hours)
{
	if(hours>=35)
		cout<< pay_per_hour*40<<endl;
	else
		cout<<(pay_per_hour*hours+0.5*pay_per_hour*(35-hours))<<endl;
}
ostream & operator<<(ostream &out,Worker  &worker){
	    cout<<"aaaa"<<endl;
        out<<"������"<<worker.name<<" ���䣺"<<worker.age<<" �Ա�"<<worker.sex<<" Сʱ���ʶ�:"<<worker.pay_per_hour<<endl;
        return out;
}
int main()
{
	Worker* workers[5];
	int m,n,i;
	char name[5][10];
	char sex[5][10];
	int a,b;

	cout<<"����5����ͬ���˵Ļ�����Ϣ"<<endl;
	for( i=0;i<5;i++)
	{
		cin>>name[i]>>a>>sex[i]>>b;
		if(b==10||b==20||b==40)
		{	workers[i]=new HourlyWorker (name[i],a,sex[i],b);}
		else
		{  workers[i]=new SalariedWorker (name[i],a,sex[i],b);}

	}
	m=0;
	while(m!=2)
	{
	  cout<<"1.���������Ϣ";
	  cout<<"2.�˳�"<<endl;
	  cin>>m;
	  if(m==1)
	  {
           cout<<"����Ա����ţ�"<<endl;
			   cin>>i;
           cout<<*workers[i-1]<<endl;
		   cout<<"����Сʱ����"<<endl;
			   cin>>n;
           cout<<"�����ǣ�"<<endl;
		   workers[i-1]->Compute_pay(n);
			  cout<<endl;

	  }
	}

		return 0;
}
