#include"iostream.h"
#include<vector>
#include<algorithm>
using namespace std;
class Observable;//提前声明被观察者类
class Sphere;//体腔声明实体类
class Observer//观察者类
{
public:
 virtual void update(Observable *o)=0;
};
class Observable//被观察者类
{
public:
	bool changed;
	vector<Observer*> obs;//存放观察者指针的容器
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
			 for(it=obs.begin();it!=obs.end();it++)//通知观察者更新
				(*it)->update(this);
		 }      
	}
    void setChanged() 
	{
        changed = true;
    }
	void addObserver(Observer *o) 
	{
       it=find(obs.begin(),obs.end(),o);//查看是否有重复
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
		//通知观察者更新
        setChanged();
        notifyObservers();
	}
	double volume() //计算球的体积
	{
        return (double)4/(double)3*3.14*radius*radius*radius;
    }
    double surfaceArea() //计算球的表面积
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
	void mouseDragged(double a,double b) //鼠标拖拽事件
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
         cout<<"图形视图界面已经建好"<<endl;
	  }
	  void update(Observable *o)
	{
	  Sphere *sphere=(Sphere *)o;
	  cout<<"GraphicsView:"<<endl;
      cout<<"画半径是 "<<(*sphere).getradius()<<" 的圆"<<endl;    
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
	  void actionPerformed(double r)//文本框窗口事件
	  {
         (*sphere).setRadius(r);
	  }
};
class TextView:public Observer
{
public:
	TextView()
	{
		cout<<"文本视图界面已经建好"<<endl;
	}
    void update(Observable *o)
	{
	  Sphere *sphere=(Sphere *)o;
	  cout<<"TextView："<<endl;
      cout<<"半径是："<<(*sphere).getradius()<<endl;
	  cout<<"体积是："<<(*sphere).volume()<<endl;
	  cout<<"表面积是:"<<(*sphere).surfaceArea()<<endl;
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
	  cout<<"1.更改textview半径"<<endl;
      cout<<"2.更改Graphicsview半径"<<endl;
	  cout<<"3.退出"<<endl;
	  cin>>i;
		  if(i==1)
		  {
			  cout<<"输入半径"<<endl;
			  cin>>r;
              textController.actionPerformed(r);
		  }
		  if(i==2)
		  {
			  cout<<"输入坐标x,y"<<endl;
			  cin>>x>>y;
              graphicsController.mouseDragged(x,y) ;
		  }
  }
  return 0;
}