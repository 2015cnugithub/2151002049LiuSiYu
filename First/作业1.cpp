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
int main()
{
  char name[10]="lsy";//����Ʒ����
  CGoods Goods(1,name,1);//���ø��ƹ��캯��
  Goods.Printf();//��ӡ
  CGoods Goods2(Goods);//������������
  Goods2.Printf();//��ӡ
  return 0;

}

