
#include<windows.h>
#include<iomanip>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include"randomnumbers.h"
using namespace std;
class memory_game
{
    char __default__Table[4][4];            ///for displaying default value on screen
    char __set__Table[4][4];
    char __current__Table[4][4];
    int cmpr1,cmpr2;
    int _attempt;
    int t1,t2,check;                           ///will Hold the Cell Numbers
    int flag1,flag2;                           ///will Hold the Cell Numbers
public:
    memory_game()
    {
        check=8;
        t1=t2=-1;
        flag1=flag2=0;
        cmpr1=cmpr2=-1;
        _attempt=0;
    }
    void current_status_of_Table();
    void createTable();                                 ///this function will create displaying board i.e default board.                                ///this function will create displaying board i.e default board.
    void fillValue();                                 ///this function will hold actual character(behind mask) of board
    void game_on();                                ///function to proceed on the game flow.
    int trace_location(int ,int);


};
void memory_game::game_on()
{

          char cell_no[2];
    int cellno_1,cellno_2;
//while(true)
do
  {
     cnt:
        cout<<"\nEnter Cell No:\t";
        cin>>cell_no;
        if(strlen(cell_no)!=2)
        {
            if(cell_no[0]==48)
              {
                    system("cls");
                    cout<<"\n\n\n\n\n\t\t\t\t You're Welcome For next time.";
                    getch();
                    break;
              }
            cout<<" Invalid Cell No, Try Again";
            goto cnt;
        }
        switch(cell_no[0])
        {
        case 'A':case 'a':
                    cellno_1=0;  break;
        case 'B':case 'b':
                    cellno_1=1;  break;
        case 'C':case 'c':
                    cellno_1=2;  break;
        case 'D':case 'd':
                    cellno_1=3;  break;
        default:
               cout<<"\nInvalid Cell Number, Try Again";
               goto cnt;
        }
        switch(cell_no[1])
        {
        case '1':
                 cellno_2=0; break;
        case '2':
                 cellno_2=1; break;
        case '3':
                 cellno_2=2; break;
        case '4':
                 cellno_2=3; break;
        default :
               cout<<"\nInvalid Cell Number, Try Again";
               goto cnt;
        }
       t1=cellno_1; t2=cellno_2;
       if(__current__Table[t1][t2]!='@')
        {
            cout<<"\nCell is already Opened.";
           getch();
            goto cnt;
        }
        else
     {
        system("cls");
        check= trace_location(t1,t2);
     }
   }while(check!=0);
 system("cls");
 if(cell_no[0]!=48)
   {
    cout<<"\n\n\n\n\n\n\t\t\t\t\t"<<"CONGRATULATION!!! You Completed the Table in "<<_attempt<<" attempts";
      if(_attempt>=8 && _attempt<=12)
        cout<<"\n\t\t\t\t\t You got a Genuine Mind.";
       if(_attempt>12 && _attempt<=20)
        cout<<"\n\t\t\t\t\t Your Perfomance is Average.";
    getch();
   }
}

int memory_game::trace_location(int t1,int t2)
{

     int j,k;
     char c;
     cout<<"Press '0' to Quit."<<"\t"<<setw(100)<<__DATE__<<"\n\n\n\n";
     cout<<setw(40)<<"Tries:"<<_attempt<<endl;
        cout<<"\n\n\n\n\t\t  ";
        for(int j=1;j<5;j++)
          cout<<"\t  "<<j;
        cout<<"\n\t\t\t  ";
        for(int j=0;j<13;j++)
            cout<<"- ";
        cout<<"\n\n\t  ";
        char row='A';
        for(j=0;j<4;j++)
  {
            cout<<"\t   "<<row;
            for( k=0;k<4;k++)
    {
            if((flag2!=0) && (j==t1 && k==t2))
            {
                 if(__set__Table[t1][t2]==__set__Table[cmpr1][cmpr2])
                   {
                      __current__Table[j][k]=__set__Table[t1][t2];                  ///to set value in __current__table permanently
                      check--;                                                      ///to ensure if all characters has been shown up.
                      cout<<"\t[ "<<__set__Table[j][k]<<" ]";
                      c='y';
                  }
                   else
                  {
                      cout<<"\t[ "<<__set__Table[j][k]<<" ]";
                    __current__Table[cmpr1][cmpr2]=__default__Table[t1][t2];
                       c='n';
                   }
                 flag2=0;
            }
           else
        {
               if(j==t1 && k==t2)
               {
                   if(flag2==0)    ///this condition will assure that cell is not opened previously in 1st attempt.
                    {
                       cmpr1=t1;cmpr2=t2;
                       flag2++;      ///this will not allow to change the value of cmpr1 and cmpr2 variables in case character of both cell matches.
                      _attempt++;
                     __current__Table[j][k]=__set__Table[t1][t2];   ///to view content of __set__table temporarily in second attempt.
                    }
                   cout<<"\t[ "<<__set__Table[j][k]<<" ]";
               }
               else
               cout<<"\t  "<<__current__Table[j][k];
         }
    }
           cout<<endl<<endl<<"\t  ";
            row++;
}
               if(flag2==0 && c=='y')
              {
                cout<<"\n Matched";
                getch();
                }
            if(flag2==0 && c=='n')
               {
                cout<<"\n Not Matched";
                getch();
                system("cls");
                 current_status_of_Table();
                }
    flag1=0;
    return check;
}
void memory_game::fillValue()
{
    char  __COPY_randNo[8];       /// This array will store copied __random_number value,
    int a=0,__randNo[8],_rNo;
    __random_number *rg;
     rg=new __random_number();
    _rNo=rg->draw_random_numbers();
   //cout<<endl;
    for(int j=0;j<8;j++)
    {
        __randNo[j]=_rNo*j;
        __COPY_randNo[j]=__randNo[j];
       //     cout<<"\t"<<__COPY_randNo[j];
       if(__COPY_randNo[j]=='\0' )
             __COPY_randNo[j]='%';
       if(__COPY_randNo[j]==' ')
                __COPY_randNo[j]=176;
       if(__COPY_randNo[j]=='@')
                __COPY_randNo[j]='+';
    }
//cout<<endl;
    for(int j=0;j<4;j++)
    {
        for(int k=0;k<4;k++)
        {
            __set__Table[j][k]=__COPY_randNo[a];
    //    cout<<"\t"<<__set__Table[j][k];
            if(a==7)
                a=0;
                else
                    a++;
        }
    }
}
void memory_game::current_status_of_Table()
{
    cout<<"Press '0' to Quit."<<"\t"<<setw(100)<<__DATE__<<"\n\n\n\n";
    cout<<setw(40)<<"Tries:"<<_attempt<<endl;
        cout<<"\n\n\n\n\t\t  ";
        for(int j=1;j<5;j++)
            cout<<"\t  "<<j;
        cout<<"\n\t\t\t  ";
        for(int j=0;j<13;j++)
            cout<<"- ";
        cout<<"\n\n\t  ";
        char row='A';
        for(int j=0;j<4;j++)
        {
            cout<<"\t"<<row;
            for(int k=0;k<4;k++)
                cout<<"\t  "<<__current__Table[j][k];
            cout<<endl<<endl<<"\t  ";
            row++;

        }

}
void memory_game::createTable()
    {
        int a=0;
        cout<<"Press '0' to Quit."<<"\t"<<setw(100)<<__DATE__<<"\n\n\n\n";
        cout<<setw(40)<<"Tries:"<<_attempt<<endl;
        cout<<"\n\n\n\n\t\t  ";
        for(int j=1;j<5;j++)    ///will print the column Heading
          cout<<"\t  "<<j;
        cout<<"\n\t\t\t  ";
        for(int j=0;j<13;j++)
            cout<<"- ";
        cout<<"\n\n\t  ";
        char row='A';
        for(int j=0;j<4;j++)
        {
            cout<<"\t"<<row;
            for(int k=0;k<4;k++)
            {
                __default__Table[j][k]='@';
                __current__Table[j][k]=__default__Table[j][k];
                cout<<"\t  "<<__default__Table[j][k];
            }
            cout<<endl<<endl<<"\t  ";
            row++;

        }
    }
