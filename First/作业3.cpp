#include<iostream>
using namespace std;

class CGoods{
public:
	CGoods(long a,char * b,double c);//构造函数
	CGoods(CGoods &p);//复制构造函数
	~CGoods(){cout<<" 调用了析构函数 "<<endl;};//析构函数
	void Printf();//打印函数
	friend  char *getName(CGoods p);
	bool operator < (CGoods &g1);
	bool operator >= (CGoods &g1);
	int getprice(){return price;}
private:
	long no;//商品号
	char * p_name;//商品名字
	double price;//商品价格；
	static int count;
};
int CGoods::count=0;
CGoods::CGoods(long a,char * b,double c){
	no=a;
	p_name=b;
	price=c;
    count++;
}
CGoods::CGoods(CGoods &p){
	no=p.no;
	p_name=p.p_name;
	price=p.price;
}
void CGoods::Printf(){
	cout<<no<<" "<<p_name<<" "<<price<<endl;
}
char * getName(CGoods p)
{
	return p.p_name;
}
bool CGoods::operator <(CGoods &g1){
	return (price<g1.getprice());
}
bool CGoods::operator >=(CGoods &g1){
	return (price>=g1.getprice());
}
int main()
{
  char name[10]="lsy";//给商品命名
  CGoods Goods(3,name,3);//调用复制构造函数
  CGoods Goods2(2,name,2);//调用析构函数
  if(Goods<Goods2) cout<<"Goods小"<<endl;
  if(Goods>=Goods2)cout<<"Goods不小"<<endl;
  return 0;
}