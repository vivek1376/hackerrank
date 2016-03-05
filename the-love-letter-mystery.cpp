#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int T, noOfOperations;
  string::size_type len,mid;
  string s;
  cin>>T;

  while(T--)
    {
      cin>>s;
      len=s.size();
      if(len%2==0)
      mid=len/2;
      else
        mid=len/2+1;

        //cout<<"mid "<<mid<<endl;

      noOfOperations=0;

      for(string::size_type ix=mid; ix!=0; --ix)
      {
      //cout<<"noof "<<noOfOperations<<endl; //d
      noOfOperations+=abs(((int)s[ix-1]-(int)s[len-ix]));
      }

      cout<<noOfOperations<<endl;

    }
}
