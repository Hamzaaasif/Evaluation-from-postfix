#include<iostream>
#include <stack> 
using namespace std;
#include"stack.h"
//#include"btstack.h"

int main()
{
  charstack s;
  charstack *top=new charstack;
  top=NULL;
  char prefix[]="a+b-c*d/e";
  char postfix[9];
  int i=0,j=0;
  //cout<<"Enter prefix expression (9 characters)"<<endl;
  //gets(prefix);
  while(i<9)
  {
    int prio1 = s.priority(prefix[i]);
    if(prio1 == 0)
    {
      postfix[j]=prefix[i];
      j++;
    }
    else if(prio1 > 0)
    {
      if(s.peak(top) == 'a')
      {
        s.push(prefix[i] , &top);
      }
      else
      {
        int prio2= s.priority(s.peak(top));
        if(prio2 >= prio1)
        {
          while(s.priority(s.peak(top)) >= prio1)
          {
            postfix[j]=s.pop(&top);
            j++;

          }
        }
         s.push(prefix[i] , &top);
      }
    }
    i++;
  }
 while(j<=i)
  {
    postfix[j]=s.pop(&top);
    j++;
  }
  cout<<"PostFix : ";
  for(i=0;i<9;i++)
  {
    cout<<postfix[i]<< " ";
  }

  stack<int> stemp ; 
  i=0;
  int a=4,b=1,c=2,d=3,e=2;
  while(i<9)
  {
    if(postfix[i]=='a')
    {
      stemp.push(a);
    }
    else if(postfix[i]=='b')
    {
      stemp.push(b);
    }
     else if(postfix[i]=='c')
    {
      stemp.push(c);
    }
     else if(postfix[i]=='d')
    {
      stemp.push(d);
    }
    else if(postfix[i]=='e')
    {
      stemp.push(e);
    }
    else
    {
      int temp1=stemp.top();
      stemp.pop();
      int temp2 =stemp.top();
      stemp.pop();
      if(postfix[i]=='+')
      {
        stemp.push(temp1+temp2);       
      }
      else if(postfix[i]=='*')
      {
        stemp.push(temp1*temp2);       
      }
      else if(postfix[i]=='-')
      {
        stemp.push(temp2-temp1);
      }
      else
      {
        stemp.push(temp2/temp1);
      }      
    }
    i++;
  }
  cout<<endl<<"After evaluation : "<<stemp.top()<<endl;
  //stemp.pop();

  system("pause");
}