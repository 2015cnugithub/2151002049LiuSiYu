#include<iostream>
using namespace std;

class CGoods{
public:
	CGoods(long a,char * b,double c);//���캯��
	CGoods(CGoods &p);//���ƹ��캯��
	~CGoods(){cout<<"��������������"<<endl;};//��������
	void Printf();//��ӡ����
private:
	long no;//��Ʒ��
	char * p_name;//��Ʒ����
	double price;//��Ʒ�۸�
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
	void usefor(){cout<<"�·�"<<endl;}
private:
  char *p_brand;
};


class CFood:public CGoods{
public:
	CFood(char *p,long a,char * b,double c):CGoods(a,b,c),p_brand(p){}
	~CFood(){}
	void usefor(){cout<<"ʳ��"<<endl;}
private:
  char *p_brand;
};


int main()
{
  char gname[10]="lsy";//����Ʒ����
  CClothes clothes1(gname,1,gname,1);
  CFood Food1(gname,1,gname,1); 
  return 0;

}