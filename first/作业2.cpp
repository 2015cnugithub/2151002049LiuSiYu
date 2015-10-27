#include<iostream>
using namespace std;

class CGoods{
public:
	CGoods(long a,char * b,double c);//构造函数
	CGoods(CGoods &p);//复制构造函数
	~CGoods(){cout<<" 调用了析构函数 "<<endl;};//析构函数
	void Printf();//打印函数
	friend  char *getName(CGoods p);
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

int main()
{
  char name[10]="lsy";//给商品命名
  CGoods Goods(1,name,1);//调用复制构造函数
  Goods.Printf();//打印
  CGoods Goods2(Goods);//调用析构函数
  Goods2.Printf();//打印
  cout<<getName(Goods)<<endl;//调用友元函数
  return 0;
}