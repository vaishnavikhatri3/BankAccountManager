#include<iostream>
#include<math.h>
using namespace std;
class account
{
protected:
    char customername[20];
   long long int accountno;
    char typeofaccount[6];
    int balance;
public:
    account()
    {
        balance=5000;

    }
 void input(){
        cout<<"Enter customer name";
        cin>>customername;
        cout<<"Enter account no";
        cin>>accountno;
        cout<<"Enter type of account";
        cin>>typeofaccount;

 }
    void withdraw();
    void updatebal();
    void display()
     {
         cout<<"\n Customer Name "<<customername;
            cout<<"\n Account Number "<<accountno;
            cout<<"\n Type "<<typeofaccount;
            cout<<"\n Balance "<<balance;
      }
    void deposit()
    {
        int amount;
        cout<<"\nenter amount which is to be deposited";
        cin>>amount;
        balance=balance+amount;
    }
};
class currentaccount:public account
{
    int penalty;
    char chequebook;
    public:
     void issueCheque()
     {
         cout<<"your chequebook will be issued shortly";
     }

     void withdrawal(){
          int amount;
          cout<<"\n\n Enter the amount to withdrawn";
          cin>>amount;
          if(balance>=amount){
            balance-=amount;
            if(balance<500){
                    cout<<"penalty imposed\n";
                balance-=50;
            }
            else{cout<<"no penalty imposed";}
          }

          else{
              cout<<"\n The amount cannot be withdrawn";
          }

      }

};
class savingaccount:public account
{
    int interest;
public:


      void updatebalance()
      {
          int time1,rate1=10;
          cout<<"\nEnter time";
         cin>>time1;
         balance=balance+(balance*pow(1+rate1/100.0,time1)-balance);
         cout<<"\nupdated balance"<<balance;
      }

      void withdrawal()
      {
         int amount;
         cout<<"\n Enter amount to withdrawn";
         cin>>amount;
         if(balance>=amount)
            {
               balance=balance-amount;
         }
         else{
               cout<<"\n The amount cannot be withdrawn";
         }
      }

};
int main(){
      currentaccount c1;
      savingaccount s1;
      cout<<"For Current Account\n";
      c1.input();
      c1.display();
      c1.deposit();
      c1.display();
      c1.withdrawal();
      c1.display();
      cout<<"\nFor Saving Account\n";
      s1.input();
      s1.display();
      s1.deposit();
      s1.display();
      s1.updatebalance();
      s1.withdrawal();
      s1.display();
      return 0;
}



