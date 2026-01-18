#include<iostream>
#include<iostream>
using namespace std;



void decrypt (string str , int key)
{
  for (int i = 0 ; i < str.length() ; i++)
  {
    str[i] -= key ;
    if (0 <= str[i] <= 32)
    {
      int num = str[i];
      int add = 32 - num ;
      str[i] += add ;
    }
  }
  cout<<"The decrypted massage is"<<endl;
  cout<<str;
}
int main()
{
  string str;
  cout<<"Enter a String"<<endl;
  cin>>str;
  char op;
  cout<<"Enter 'E' to be encrypted of 'D' to be decrypted"<<endl;
  cin>>op;
  int key;
  cout<<"Enter the encryption or decryption key (1 - 128)"<<endl;
  cin>>key;
  
  if (op == 'e' || op == 'E')
  {
    cout<<"hi";
  }
  else if (op == 'd' || op == 'D')
  {
    decrypt(str , key);
  }
  else
  {
    cout<<"please enter the correct input"<<endl;
  }
}
