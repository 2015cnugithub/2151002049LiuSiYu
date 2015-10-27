#include <iostream>
#include <iomanip>
using namespace std;
void Printf(int i,int year,int month)
{
	int days,j;
	if(month==2)
	{
		if((year%4==0&&year%100!=0)||(year%400==0)) 
			days=29;
		else 
			days=28;
	}
	else if(month==4||month==6||month==9||month==11) 
		days=30;
	else
		days=31;
	cout<<"一  "<<"二  "<<"三  "<<"四  "<<"五  "<<"六  "<<"日  "<<endl;
	for(int a=1;a<i;a++) cout<<"    ";
	for(j=1;j<=days;j++)
	{
		cout<<left<<setw(4) <<j;
		if((j+i-1)%7==0)cout<<endl;
	}
}
int getxingqi(int year,int month)
{
	int sum=0,xingqi,i;
	for(i=1800;i<year;i++)
	{
      if((i%4==0&&i%100!=0)||(i%400==0)) 
		  sum=sum+366;
	  else
		  sum=sum+365;
	}
	for(i=1;i<month;i++)	{

        if(i==2)
			{
		      if((year%4==0&&year%100!=0)||(year%400==0)) 
		      sum=sum+29;
	     	  else 
	 		  sum=sum+28;
			}
		else if(i==4||i==6||i==9||i==11) 
		    sum=sum+30;
		else
            sum=sum+31;
	}
		sum=(sum+3)%7;
		if(sum==0) xingqi=7;
		else xingqi=sum;
		return xingqi;
}


int main()
{
	int year,month,i;
	cout<<"输入你要打印的年月"<<endl;
    cin>>year>>month;
	i=getxingqi(year,month);
	Printf(i,year,month);
	return 0;
}