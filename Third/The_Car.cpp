#include"iostream.h"
#include "graphics.h"     
#include "conio.h"
#include"windows.h"
#include "math.h" 
class Figure//����ͼ�λ���
{
public:
	virtual void chage()=0;
	virtual void hide()=0;//��������ͼ��
	virtual void draw()=0;//���ڻ滭ͼ��
};
typedef struct Figurelink;
struct Figurelink//��ͼ�ε�����
{
Figure *qq;
Figurelink  * next;
};
class Circle:public Figure
{
int x,y,radius;//Բ��Բ�� x ����,Բ��Բ�� y����,Բ�İ뾶��
public:
	Circle(int a,int b,int c)//���캯��
	{x=a;y=b;radius=c;}
	 void chage()//�������1
	 {x=x+1;}
     void hide()//����ͼ��
	 {
	  setcolor(BLACK);
	  circle(x,y,radius);
	 }
	 void draw()//�滭ͼ��
	 {
       setcolor(WHITE);
	   circle(x,y,radius);
	 }
};
class Rectangl:public Figure
{
	int left,right,top,bottom;
 public:
     Rectangl(int a,int b,int c,int d)//���캯��
	 {
		 left=a;
		 top=b;
		 right=c;
		 bottom=d;
	 }
	 void chage()//�ƶ�
	{
		 left=left+1;
		 right=right+1;
	}
     void hide()//����ͼ��
	 {
		setcolor(BLACK);
	    rectangle(left,top,right,bottom);
	 }
	 void draw()//�滭ͼ��
	 {
       	setcolor(WHITE);
		rectangle(left,top,right,bottom);
	 }
};
class Triangle:public Figure
{
int x[6];
public:
	Triangle(int a,int b,int c,int d,int e,int f)//���캯����x[0]Ϊ��һ����ĺ����꣬x[1]Ϊ�ڶ�����������ꡣ����������
	{
	x[0]=a;
	x[1]=b;
	x[2]=c;
	x[3]=d;
	x[4]=e;
	x[5]=f;
	}
	 void chage()//������������1
	 {
		 x[0]=x[0]+1;
		 x[2]=x[2]+1;
		 x[4]=x[4]+1;
	 }
     void hide()//����ͼ��
	 {
       setcolor(BLACK);
	   polygon((POINT*)x, 3);
	 }
	 void draw()//�滭ͼ��
	 {
	   setcolor(WHITE);
	   polygon((POINT*)x, 3);
	 }
};
class Vehicle
{
	private:
	Figurelink *first;
	int wheel_size,xstart,ystart;
	public:
	Vehicle(int a, int b, int c)
	{
	 first=new Figurelink; 
	 wheel_size=c;
	 xstart=a;
	 ystart=b;
	}
	void setcar()//����С��������ͼ������
	{
		 Figure *p;
		 Figurelink *t1,*t2,*t3,*t4,*t5,*t6;
		 t1=new Figurelink;
		 t2=new Figurelink;
		 t3=new Figurelink;
		 t4=new Figurelink;
		 t5=new Figurelink;
		 t6=new Figurelink;
		 p=new Rectangl(xstart, ystart-2*wheel_size,xstart+8*wheel_size,ystart-wheel_size); 
		 t1->qq=p;
		 p=new Rectangl(xstart+2.25*wheel_size, ystart-3*wheel_size,xstart+5.75*wheel_size,ystart-wheel_size*2);
		 t2->qq=p;
		 p=new Circle(xstart+1.75*wheel_size,ystart-0.5*wheel_size,0.5*wheel_size);
		 t3->qq=p;
		 p=new Circle(xstart+6.25*wheel_size,ystart-0.5*wheel_size,0.5*wheel_size);
		 t4->qq =p;
		 p=new Triangle(xstart+1.25*wheel_size,ystart-2*wheel_size,xstart+2.25*wheel_size,ystart-2*wheel_size,xstart+2.25*wheel_size,ystart-3*wheel_size);
		 t5->qq=p;
		 p=new Triangle(xstart+5.75*wheel_size,ystart-2*wheel_size,xstart+5.75*wheel_size,ystart-3*wheel_size,xstart+6.75*wheel_size,ystart-2*wheel_size);
		 t6->qq=p;
		 first->next=t1;
		 t1->next=t2;
		 t2->next=t3;
		 t3->next=t4;
		 t4->next=t5;
		 t5->next=t6;
		 t6->next=NULL;    
	}
	 void settruck()//������������ͼ������
	 {
		 Figure *p;
		 Figurelink *t1,*t2,*t3,*t4,*t5,*t6,*t7;
		 t1=new Figurelink;
		 t2=new Figurelink;
		 t3=new Figurelink;
		 t4=new Figurelink;
		 t5=new Figurelink;
		 t6=new Figurelink;
         t7=new Figurelink;
		 p=new Rectangl(xstart, ystart-5*wheel_size,xstart+9*wheel_size,ystart-wheel_size); 
		 t1->qq=p;
		 p=new Rectangl(xstart+9*wheel_size, ystart-4*wheel_size,xstart+11*wheel_size,ystart-wheel_size);
		 t2->qq=p;
		 p=new Circle(xstart+wheel_size,ystart-0.5*wheel_size,0.5*wheel_size);
		 t3->qq=p;
		 p=new Circle(xstart+2.25*wheel_size,ystart-0.5*wheel_size,0.5*wheel_size);
		 t4->qq =p;
		 p=new Circle(xstart+6.75*wheel_size,ystart-0.5*wheel_size,0.5*wheel_size);
		 t5->qq=p;
		 p=new Circle(xstart+8*wheel_size,ystart-0.5*wheel_size,0.5*wheel_size);
		 t6->qq=p;
         p=new Circle(xstart+10*wheel_size,ystart-0.5*wheel_size,0.5*wheel_size);
		 t7->qq=p;
		 first->next=t1;
		 t1->next=t2;
		 t2->next=t3;
		 t3->next=t4;
		 t4->next=t5;
		 t5->next=t6;
		 t6->next=t7;
		 t7->next=NULL;  
	 }
	 void Delete()//ɾ��С�����򿨳�����ͼ���б�
	 {
        Figurelink *u,*t;
		u=first->next;
		while(u!=NULL)
		{
			t=u;
			u=u->next;
			delete t;
			
		}
	 }

	void Draw()//��С�����򿨳�����ͼ���б�
	{
		Figurelink *u;
		u=first->next;
		while(u!=NULL)
		{
			u->qq->draw();
			u=u->next;
		}
	}
	void Hide()//����С�����򿨳�����ͼ���б�
	{
		Figurelink *u;
		u=first->next;
		while(u!=NULL)
		{
			u->qq->hide();
			u->qq->chage();
			u=u->next;
		}
	}
};

class Car:public Vehicle
{
  public:
	  Car(int wheel_size, int xstart, int ystart):Vehicle(wheel_size,xstart,ystart){}
};

class Truck:public Vehicle
{
public:
	  Truck(int wheel_size, int xstart, int ystart):Vehicle(wheel_size,xstart,ystart){}
};

int main()
{
	int m=0;
	int i=0;
	char c;
	double x[8]={40,28,23,20,12,8,6,5};
	int t=3;

	//�����˵�
	initgraph(1500, 480);
	RECT r1 = {0, 0, 250, 30};
	drawtext(_T("Press <S> key to start moving"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r2 = {0, 0, 250, 60};
	drawtext(_T("Press <P> key to pause "), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r3 = {0, 0, 250, 90};
	drawtext(_T("Press <E> key to end moving "), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r4 = {0, 0, 250,120};
	drawtext(_T("Press <+> key to speed up"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r5 = {0, 0,250, 150};
	drawtext(_T("Press <-> key to speed down"), &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r6 = {0, 0,250, 180};
	drawtext(_T("1.CAR 2.TRUCK 0.EXIT"), &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    //�����ʼ��
	Car carcar(10,400,20);
	Truck trucktruck(10,400,20);

	//����С�����Ϳ�������
	carcar.setcar();
	trucktruck.settruck();


 while(1)
 {
	   if(kbhit())//�ж��Ƿ��а�������
	   {
			  c=getch();
			  if(c=='1')  {trucktruck.Hide();carcar.Draw();m=1;}//������
			  else if(c=='2') {carcar.Hide();trucktruck.Draw();m=2;}//������
			  while(1)
			  {
					  if(kbhit())
					  {
						  c=getch();
						  if(c=='s')//��ʼ��ʻ
						  {		 
								while((c!='e')&&(c!='0'))//��ʻ������
								{
						  			  if(i==0)
									  {
										  if(m==1){carcar.Hide();carcar.Draw();}
										  if(m==2){trucktruck.Hide();trucktruck.Draw();}
										  Sleep(x[t]);
									  }
									   if(kbhit())
									   {
										 c=getch();
										 if((c=='=')&&(t<=7)) t=t+1;//����
										 if((c=='-')&&(t>=0)) t=t-1;//����
										 if((c=='p')&&(i==0)) i=1;//��ͣ
										 else if((c=='p')&&(i==1)) i=0;//����
									   }
									    if(c=='e')//ֹͣ�˻ص���ʼ״̬
										{
											 t=3;
											 if(m==1) {carcar.Hide();carcar.Delete();carcar.setcar();carcar.Draw();}//ɾ����Ȼ�����¹�������
											 if(m==2) {trucktruck.Hide();trucktruck.Delete();trucktruck.settruck();trucktruck.Draw();}//ɾ����Ȼ�����¹�������
										}
									
								}
						  }
					  }
					  if(c=='e'||c=='0') break;
							
			  }
	   }
	    if(c=='0') break;//��������
	   
 }
	//ɾ������ͼ������
    carcar.Delete();
	trucktruck.Delete();
    closegraph();          // �ر�ͼ�ν���
	return 0;
}

