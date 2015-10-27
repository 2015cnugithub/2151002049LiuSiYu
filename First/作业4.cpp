#include<iostream>
using namespace std;

class CGoods{
public:
	CGoods(long a,char * b,double c);//构造函数
	CGoods(CGoods &p);//复制构造函数
	~CGoods(){cout<<"调用了析构函数"<<endl;};//析构函数
	void Printf();//打印函数
private:
	long no;//商品号
	char * p_name;//商品名字
	double price;//商品价格；
};
CGoods::CGoods(long a,char * b,double c){
	no=a;
	p_name=b;
	price=c;
}
CGoods::CGoods(CGoods &p){
	no=p.no;
	p_name=p.p_name;
	price=p.price;
}
void CGoods::Printf(){
	cout<<no<<" "<<p_name<<" "<<price<<endl;
}
class CClothes:public CGoods{
public:
	CClothes(char *p,long a,char * b,double c):CGoods(a,b,c),p_brand(p){}
	~CClothes(){}
	void usefor(){cout<<"衣服"<<endl;}
private:
  char *p_brand;
};


class CFood:public CGoods{
public:
	CFood(char *p,long a,char * b,double c):CGoods(a,b,c),p_brand(p){}
	~CFood(){}
	void usefor(){cout<<"食物"<<endl;}
private:
  char *p_brand;
};


int main()
{
  char gname[10]="lsy";//给商品命名
  CClothes clothes1(gname,1,gname,1);
  CFood Food1(gname,1,gname,1); 
  return 0;

}