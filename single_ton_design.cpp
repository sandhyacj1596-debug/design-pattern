#include <bits/stdc++.h>
using namespace std;
#include<mutex>
#include<condition_variable>

class singleton
{
    singleton()
    {
        cout<<"Hi from singleton"<<endl;
    }
    singleton (singleton& obj)=delete;
    singleton & operator=(singleton & obj)=delete;
    
    public:
static singleton * instance;
static mutex mtx;
static condition_variable cv;
static bool initialized;

    static singleton* getinstance()
    {
        unique_lock<mutex>lock(mtx);
        if(!initialized)
        {
            instance= new singleton();
            initialized=true;
            cv.notify_all();
    }
        else
        {
            cv.wait(lock,[]{return initialized;});
    }
        return instance;
    }
};
singleton* singleton::instance;
mutex singleton ::mtx;
condition_variable singleton ::cv;
bool singleton:: initialized =false;
void task()
{
singleton *s1 =singleton::getinstance();
cout<<s1<<endl;
}
int main() 
{
    thread t1(task);
    thread t2(task);
    t1.join();
    t2.join();
    

    return 0;
}
