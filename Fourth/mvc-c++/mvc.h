class Observable
{
	bool changed;
public:
    Observable()
	{
       changed=false;
	}
	void notifyObservers()
	{
	}
    void setChanged() 
	{
        changed = true;
    }

};
class Observer
{
 virtual void update(Observable o)=0;
};
