#include<iostream>
using namespace std;

class charstack
{
  public:
  void push(char val,charstack **top)
  {
    charstack *ptr=new charstack;
    ptr->value=val; 
        
    if(*top==NULL)
    {
      ptr->next=NULL;
      *top=ptr;
    } 
    else
    {
      ptr->next=*top;
      *top=ptr;
    }
  }

  char pop(charstack **top)
  {
    if(*top==NULL)
    {
      return 'a';
    }
    else
    {
      charstack *curr=*top;
      *top=curr->next;
      char temp=curr->value;
      curr=NULL;
      delete[]curr;
      return temp;
    }
  }
  char peak(charstack *top)
  {
    if(top==NULL)
    {
      return 'a';
    }
    else
    {
      return top->value;
    }
  }

int priority(char operate)
{
  if(operate=='|')
  {
    return 1;
  }
  else if(operate=='&')
  {
    return 2;
  }
  else if(operate=='<' || operate=='>' || operate=='~' || operate=='=')
  {
    return 3;
  }
  else if(operate=='+' || operate=='-')
  {
    return 4;
  }
  else if(operate=='*' || operate=='/')
  {
    return 5;
  }
  else
  {
    return 0;
  }
}
  private:
  char value;
  charstack *next;
};