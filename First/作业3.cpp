#include<iostream>
using namespace std;

class CGoods{
public:
	CGoods(long a,char * b,double c);//���캯��
	CGoods(CGoods &p);//���ƹ��캯��
	~CGoods(){cout<<" �������������� "<<endl;};//��������
	void Printf();//��ӡ����
	friend  char *getName(CGoods p);
	bool operator < (CGoods &g1);
	bool operator >= (CGoods &g1);
	int getprice(){return price;}
private:
	long no;//��Ʒ��
	char * p_name;//��Ʒ����
	double price;//��Ʒ�۸�
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
  char name[10]="lsy";//����Ʒ����
  CGoods Goods(3,name,3);//���ø��ƹ��캯��
  CGoods Goods2(2,name,2);//������������
  if(Goods<Goods2) cout<<"GoodsС"<<endl;
  if(Goods>=Goods2)cout<<"Goods��С"<<endl;
  return 0;
}