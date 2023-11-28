#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="Muhammad ",ss="Milon";
    cout<<s+ss<<endl; //Concatenation

    cout<<s.substr(5,2)<<endl; //substring (initial point,length)

    cout<<ss.replace(2,3,"mi")<<endl; //replace (initial point,size of vuktovugi word,jeta asbe)

    cout<<ss.insert(0,"Hi")<<endl; //insert (initial point,substring to insert)

    cout<<ss.erase(4,2)<<endl; //erase (initial point,How much charecter to delete)

    if(s==ss)
    {
        cout<<"They are equal!"<<endl;
    }
    else                                      //string compare
    {
         cout<<"They are not equal."<<endl;
    }

    int pos=s.find("ma");
    if(pos!=string::npos)
    {
        cout<<"Found at "<<pos<<endl;
    }
    else                                   //find substring
    {
        cout<<"The sub-string is not found"<<endl;
    }
    return 0;
}
