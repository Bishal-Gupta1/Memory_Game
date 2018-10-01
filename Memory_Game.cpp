
                   /// connect File Handling method to record Players data of all time .
                   ///random character modification
                   ///mobile fristd::endly
                   ///make Zip folder
                   ///add sound

#include<iostream>
#include"Board.h"
#include<conio.h>
#include<windows.h>

    main()
    {
        char c;
        do
        {
                std::cout<<"Tips For Playing Game:\n";
                std::cout<<"----------------------\n";
                wait(1);
                std::cout<<"\n\n\t\t > You Are Required to enter Respective Cell Number(Ex: D1->\" Column 'D' and Row '1' \")"<<std::endl
                    <<"\t\t > Table Contains pair of each Character which you need to match up entering the correct Cell Number."<<std::endl
                    <<"\t\t > Remember the location, if characters in entered Cell Number are not identical,of each Character inside "<<std::endl
                    <<"\t\t > the Cell  in each attempt so that you can match up it in your next attempt."<<std::endl
                    <<"\t\t > The less the number of attempt the more stronger is your Memory. "<<std::endl<<std::endl;
                wait(2);
                std::cout<<"Game Flow:\n";
                std::cout<<"------------"<<std::endl<<std::endl
                    <<"In your first attempt when you enter cell number the character inside that cell will be shown up and "<<std::endl
                    <<"if this character matches with next character of your second attempt that means you have solved for the "<<std::endl
                    <<"two characters and required to follow same procedure for the rest of Fourteen characters.Your attempt will be "<<std::endl
                    <<"considered in both case either you succeeded or failed to match up the characters. Character inside entered Cell "<<std::endl
                    <<"Number shall be kept visible for your both attempt, if you succeeded to match up then it will remain visible till "<<std::endl
                    <<"game is over otherwise it will be made obscured with default character '@'."<<std::endl<<std::endl
                    <<"If You wish to quit game at any point press '0'."<<std::endl;
                wait(1);
                std::cout<<"\n\nEnjoy The Game!!!\n";
                std::cout<<"press any key to continue";
                getch();
                system("cls");
             memory_game _G1;
             _G1.createTable();
             _G1.fillValue();
             _G1.game_on();
             std::cout<<std::endl<<"Play Again(Y/N):\t";
             std::cin>>c;
             if(c=='n' || c=='N')
             {
                 system("cls");
                 std::cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!\n\n\n\n\n";
                 break;
             }
             else
             {
                 system("cls");
                 continue;
             }
        }while(c!= 'n' || c!='N');
   return 0;
    }

