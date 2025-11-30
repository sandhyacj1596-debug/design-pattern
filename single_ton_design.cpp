#include <bits/stdc++.h>
using namespace std;
class singleton
{
    singleton()
    {
        cout<<"Hi from singleton"<<endl;
    }
    singleton (singleton& obj)=delete;
    singleton & operator=(singleton & obj)=delete;
    
    public:
    static singleton& getinstance()
    {
        static singleton instance;
        return instance;
    }
};
int main() {
   singleton &s1 =singleton::getinstance();
   singleton &s2 =singleton::getinstance();
   cout<<(&s1== &s2)<<endl;
    

    return 0;
}
