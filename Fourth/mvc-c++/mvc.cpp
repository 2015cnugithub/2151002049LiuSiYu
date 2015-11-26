#include"iostream.h"
#include<vector>
#include<algorithm>
using namespace std;
class Observable;//��ǰ�������۲�����
class Sphere;//��ǻ����ʵ����
class Observer//�۲�����
{
public:
 virtual void update(Observable *o)=0;
};
class Observable//���۲�����
{
public:
	bool changed;
	vector<Observer*> obs;//��Ź۲���ָ�������
    vector<Observer*>::iterator it;
    Observable()
	{
       changed=false;
	}
	void notifyObservers()
	{
		 if (changed)
		 {
			 clearChanged();
			 for(it=obs.begin();it!=obs.end();it++)//֪ͨ�۲��߸���
				(*it)->update(this);
		 }      
	}
    void setChanged() 
	{
        changed = true;
    }
	void addObserver(Observer *o) 
	{
       it=find(obs.begin(),obs.end(),o);//�鿴�Ƿ����ظ�
	   if (it==obs.end())
	   {
		   obs.push_back(o);
	   }
	
    }
	void deleteObserver(Observer *o)
	{
        it=find(obs.begin(),obs.end(),o);
        if (it!=obs.end())
	    obs.erase(it);
    }

	void clearChanged() 
	{
        changed = false;
    }
	 bool hasChanged() 
	{
        return changed;
    }
	 int countObservers() 
	 {
        return obs.size();
	 }
};


class Sphere:public Observable
{
 double radius;
public:
	Sphere(double r)
	{
       radius=r;
	}
	double getradius()
	{
		return radius;
	}
	void setRadius(double r)
	{
		radius=r;
		//֪ͨ�۲��߸���
        setChanged();
        notifyObservers();
	}
	double volume() //����������
	{
        return (double)4/(double)3*3.14*radius*radius*radius;
    }
    double surfaceArea() //������ı����
	{
        return 4*3.14*radius*radius;
    }

};
class GraphicsController
{
    Sphere *sphere;
	
public:
	GraphicsController(Sphere *a) 
	{
		sphere=a;
	}
	void mouseDragged(double a,double b) //�����ק�¼�
	{
      if (a>b)
     (*sphere).setRadius(a/2);
	  else
      (*sphere).setRadius(b/2);
	}

};
class GraphicsView:public Observer
{
public:
      GraphicsView()
	  {
         cout<<"ͼ����ͼ�����Ѿ�����"<<endl;
	  }
	  void update(Observable *o)
	{
	  Sphere *sphere=(Sphere *)o;
	  cout<<"GraphicsView:"<<endl;
      cout<<"���뾶�� "<<(*sphere).getradius()<<" ��Բ"<<endl;    
	}

};
class TextController
{
  Sphere *sphere;
public:
      TextController(Sphere *a)
	  {
         sphere=a;
	  }
	  void actionPerformed(double r)//�ı��򴰿��¼�
	  {
         (*sphere).setRadius(r);
	  }
};
class TextView:public Observer
{
public:
	TextView()
	{
		cout<<"�ı���ͼ�����Ѿ�����"<<endl;
	}
    void update(Observable *o)
	{
	  Sphere *sphere=(Sphere *)o;
	  cout<<"TextView��"<<endl;
      cout<<"�뾶�ǣ�"<<(*sphere).getradius()<<endl;
	  cout<<"����ǣ�"<<(*sphere).volume()<<endl;
	  cout<<"�������:"<<(*sphere).surfaceArea()<<endl;
	}
};

int main()
{
  Sphere sphere(50);
  TextView textView;
  GraphicsView graphicsView;
  GraphicsController graphicsController(&sphere);
  TextController textController(&sphere);
  sphere.addObserver(&textView);
  sphere.addObserver(&graphicsView);
  textView.update(&sphere);
  graphicsView.update(&sphere);
  
  int i=0;
  double r,x,y;
  while(i!=3)
  {
	  cout<<"1.����textview�뾶"<<endl;
      cout<<"2.����Graphicsview�뾶"<<endl;
	  cout<<"3.�˳�"<<endl;
	  cin>>i;
		  if(i==1)
		  {
			  cout<<"����뾶"<<endl;
			  cin>>r;
              textController.actionPerformed(r);
		  }
		  if(i==2)
		  {
			  cout<<"��������x,y"<<endl;
			  cin>>x>>y;
              graphicsController.mouseDragged(x,y) ;
		  }
  }
  return 0;
}