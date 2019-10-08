#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <process.h>
#include <time.h>
#include <fstream>

using namespace std;



/*
 0 = Black       8 = Gray
    1 = Blue        9 = Light Blue
    2 = Green       A = Light Green
    3 = Aqua        B = Light Aqua
    4 = Red         C = Light Red
    5 = Purple      D = Light Purple
    6 = Yellow      E = Light Yellow
    7 = White       F = Bright White
    */


bool bad=false;



void gotoxy(int x,int y)
{
    COORD c;
    PCONSOLE_CURSOR_INFO j;
    c.X=x;
    c.Y=y;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h,c);
}



int random(int max_num)
{
    int r;
    r=(rand()%max_num);
    return(r);
}











class Sudoku
{
    char pos[10][10];
    char sol[10][10];
    int ques[10][10];
    int value;
    int solution;
    int i,j,k,l;
    int x,y;
    int gamecode;
    char status[10];
    static int totalgames;



public:



    void heading()
    {
        system("cls");
        cout<<"________________________________________________________________________________________________________________________________________________________________________";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\tSUDOKU\n";
        cout<<"________________________________________________________________________________________________________________________________________________________________________";
    }

    void board(int disp=0)
    {
        heading();

        if(disp==0 || disp==2 || disp==3)
        {
            if(disp==2 || disp==3)
            {
                if(disp==2)
                {
                    gotoxy(100,16);
                    cout<<"S - SOLUTION";
                }
                else
                {
                    gotoxy(100,16);
                    cout<<"SOLUTION NOT SAVED";
                }

                gotoxy(100,18);
                cout<<"Q - GIVE UP";
                gotoxy(100,12);
                cout<<"GAME CODE : "<<gamecode;
                gotoxy(0,3);
            }
            cout<<"\n";
            cout<<"\n            _______________________________________________________";
            cout<<"\n          ||_____ _____ _____  _____ _____ _____  _____ _____ _____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<pos[1][1]<<"  |  "<<pos[1][2]<<"  |  "<<pos[1][3]<<"  ||  "<<pos[1][4]<<"  |  "<<pos[1][5]<<"  |  "<<pos[1][6]<<"  ||  "<<pos[1][7]<<"  |  "<<pos[1][8]<<"  |  "<<pos[1][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<pos[2][1]<<"  |  "<<pos[2][2]<<"  |  "<<pos[2][3]<<"  ||  "<<pos[2][4]<<"  |  "<<pos[2][5]<<"  |  "<<pos[2][6]<<"  ||  "<<pos[2][7]<<"  |  "<<pos[2][8]<<"  |  "<<pos[2][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<pos[3][1]<<"  |  "<<pos[3][2]<<"  |  "<<pos[3][3]<<"  ||  "<<pos[3][4]<<"  |  "<<pos[3][5]<<"  |  "<<pos[3][6]<<"  ||  "<<pos[3][7]<<"  |  "<<pos[3][8]<<"  |  "<<pos[3][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||_____ _____ _____||_____ _____ _____||_____ _____ _____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<pos[4][1]<<"  |  "<<pos[4][2]<<"  |  "<<pos[4][3]<<"  ||  "<<pos[4][4]<<"  |  "<<pos[4][5]<<"  |  "<<pos[4][6]<<"  ||  "<<pos[4][7]<<"  |  "<<pos[4][8]<<"  |  "<<pos[4][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<pos[5][1]<<"  |  "<<pos[5][2]<<"  |  "<<pos[5][3]<<"  ||  "<<pos[5][4]<<"  |  "<<pos[5][5]<<"  |  "<<pos[5][6]<<"  ||  "<<pos[5][7]<<"  |  "<<pos[5][8]<<"  |  "<<pos[5][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<pos[6][1]<<"  |  "<<pos[6][2]<<"  |  "<<pos[6][3]<<"  ||  "<<pos[6][4]<<"  |  "<<pos[6][5]<<"  |  "<<pos[6][6]<<"  ||  "<<pos[6][7]<<"  |  "<<pos[6][8]<<"  |  "<<pos[6][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||_____ _____ _____||_____ _____ _____||_____ _____ _____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<pos[7][1]<<"  |  "<<pos[7][2]<<"  |  "<<pos[7][3]<<"  ||  "<<pos[7][4]<<"  |  "<<pos[7][5]<<"  |  "<<pos[7][6]<<"  ||  "<<pos[7][7]<<"  |  "<<pos[7][8]<<"  |  "<<pos[7][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<pos[8][1]<<"  |  "<<pos[8][2]<<"  |  "<<pos[8][3]<<"  ||  "<<pos[8][4]<<"  |  "<<pos[8][5]<<"  |  "<<pos[8][6]<<"  ||  "<<pos[8][7]<<"  |  "<<pos[8][8]<<"  |  "<<pos[8][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<pos[9][1]<<"  |  "<<pos[9][2]<<"  |  "<<pos[9][3]<<"  ||  "<<pos[9][4]<<"  |  "<<pos[9][5]<<"  |  "<<pos[9][6]<<"  ||  "<<pos[9][7]<<"  |  "<<pos[9][8]<<"  |  "<<pos[9][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||_________________||_________________||_________________||";
        }
        else
        {
            cout<<"\n";
            cout<<"\n            _______________________________________________________";
            cout<<"\n          ||_____ _____ _____  _____ _____ _____  _____ _____ _____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<sol[1][1]<<"  |  "<<sol[1][2]<<"  |  "<<sol[1][3]<<"  ||  "<<sol[1][4]<<"  |  "<<sol[1][5]<<"  |  "<<sol[1][6]<<"  ||  "<<sol[1][7]<<"  |  "<<sol[1][8]<<"  |  "<<sol[1][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<sol[2][1]<<"  |  "<<sol[2][2]<<"  |  "<<sol[2][3]<<"  ||  "<<sol[2][4]<<"  |  "<<sol[2][5]<<"  |  "<<sol[2][6]<<"  ||  "<<sol[2][7]<<"  |  "<<sol[2][8]<<"  |  "<<sol[2][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<sol[3][1]<<"  |  "<<sol[3][2]<<"  |  "<<sol[3][3]<<"  ||  "<<sol[3][4]<<"  |  "<<sol[3][5]<<"  |  "<<sol[3][6]<<"  ||  "<<sol[3][7]<<"  |  "<<sol[3][8]<<"  |  "<<sol[3][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||_____ _____ _____||_____ _____ _____||_____ _____ _____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<sol[4][1]<<"  |  "<<sol[4][2]<<"  |  "<<sol[4][3]<<"  ||  "<<sol[4][4]<<"  |  "<<sol[4][5]<<"  |  "<<sol[4][6]<<"  ||  "<<sol[4][7]<<"  |  "<<sol[4][8]<<"  |  "<<sol[4][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<sol[5][1]<<"  |  "<<sol[5][2]<<"  |  "<<sol[5][3]<<"  ||  "<<sol[5][4]<<"  |  "<<sol[5][5]<<"  |  "<<sol[5][6]<<"  ||  "<<sol[5][7]<<"  |  "<<sol[5][8]<<"  |  "<<sol[5][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<sol[6][1]<<"  |  "<<sol[6][2]<<"  |  "<<sol[6][3]<<"  ||  "<<sol[6][4]<<"  |  "<<sol[6][5]<<"  |  "<<sol[6][6]<<"  ||  "<<sol[6][7]<<"  |  "<<sol[6][8]<<"  |  "<<sol[6][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||_____ _____ _____||_____ _____ _____||_____ _____ _____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<sol[7][1]<<"  |  "<<sol[7][2]<<"  |  "<<sol[7][3]<<"  ||  "<<sol[7][4]<<"  |  "<<sol[7][5]<<"  |  "<<sol[7][6]<<"  ||  "<<sol[7][7]<<"  |  "<<sol[7][8]<<"  |  "<<sol[7][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<sol[8][1]<<"  |  "<<sol[8][2]<<"  |  "<<sol[8][3]<<"  ||  "<<sol[8][4]<<"  |  "<<sol[8][5]<<"  |  "<<sol[8][6]<<"  ||  "<<sol[8][7]<<"  |  "<<sol[8][8]<<"  |  "<<sol[8][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||     |     |     ||     |     |     ||     |     |     ||";
            cout<<"\n          ||  "<<sol[9][1]<<"  |  "<<sol[9][2]<<"  |  "<<sol[9][3]<<"  ||  "<<sol[9][4]<<"  |  "<<sol[9][5]<<"  |  "<<sol[9][6]<<"  ||  "<<sol[9][7]<<"  |  "<<sol[9][8]<<"  |  "<<sol[9][9]<<"  ||";
            cout<<"\n          ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
            cout<<"\n          ||_________________||_________________||_________________||";
        }
    }



    void INITIALIZE()
    {
        for(x=1;x<=9;x++)
        {
            for(y=1;y<=9;y++)
                pos[x][y]=' ';
        }
        strcpy(status,"CORRECT");
        i=0;
        j=1;
        k=0;
        l=1;
    }



    char INPUT(int add=0)
    {
        char key;
        char choice;

        if(add==2 || add==3)
            key=77;
        //if first of sol is filled

        if(add==1 || add==2 || add==3)
        {
            goto pos1;
            //else it get to first pos of sudoku after every entry.
        }

        i=0;
        j=1;
        k=0;
        l=1;

        pos1:
        gotoxy(8+(6*l)+(19*k),5+(3*j)+(10*i));
        ASSIGN_pos();
        if(add==2 || add==3)
        {

            if(ques[y][x]!=0)
            {
                if(key==77)
                    RIGHT();
                else if(key==80)
                    DOWN();
                else if(key==75)
                    LEFT();
                else if(key==72)
                    UP();

                goto pos1;
            }
        }

        key=getch();
        if(key==27 && add==1) //exit key (Esc.)
            return(key);
        if(key==72)
        {
            UP();
            goto pos1;
        }
        else if(key==75)
        {
            LEFT();
            goto pos1;
        }
        else if(key==77)
        {
            RIGHT();
            goto pos1;
        }
        else if(key==80)
        {
            DOWN();
            goto pos1;
        }
        else
        {
            value=key-48;
            if(value<1 || value>9)
            {
                if(add==1 && key==13)
                {
                    if(strcmpi(status,"WRONG")==0)
                    {
                        gotoxy(100,20);
                        cout<<"CAN NOT SAVE WHILE RED ";
                        gotoxy(100,22);
                        cout<<"RED -> CHECK FOR REPEATITIONS";
                        goto pos1;
                    }
                    else if(FILLED()<17)
                    {
                        gotoxy(100,20);
                        cout<<"CAN NOT SAVE WITH LESS THAN 17 HINTS ";
                        gotoxy(100,22);
                        cout<<"<17 -> MORE THAN 1 SOLUTION";
                        goto pos1;
                    }
                    else
                        goto addcomplete;
                }
                else if(add==2 && key==13)
                {
                    CHECK(1);
                    if(strcmpi(status,"WRONG")==0)
                    {
                        gotoxy(100,20);
                        cout<<"CAN NOT SAVE WHILE RED ";
                        gotoxy(100,22);
                        cout<<"RED -> CHECK FOR REPEATITIONS";
                        goto pos1;
                    }
                    else if(FILLED(1)<81)
                    {
                        gotoxy(100,20);
                        cout<<"SOLUTION NEEDS ALL CELLS FILLED ";
                        goto pos1;
                    }
                }
                else if(add==3)
                {
                    if(key=='s' || key=='S')
                    {
                        return('S');
                    }
                    else if(key=='q' || key=='Q')
                    {
                        gotoxy(100,20);
                        cout<<"ARE YOU SURE WANT TO EXIT?";
                        wrongchoice:
                        gotoxy(100,22);
                        cout<<"(y/n) ";
                        choice=getch();
                        choice=tolower(choice);
                        cout<<choice;
                        if(choice!='y' && choice!='n')
                        {
                             goto wrongchoice;
                        }

                        if(choice=='y')
                        {
                            key='Q';
                            return(key);
                        }
                        else
                        {
                            board();
                            goto pos1;
                        }
                    }
                    else if(key==8)
                    {
                        pos[y][x]=' ';
                        CHECK();
                    }
                    else
                        goto pos1;

                }
                if(key==8 && add==1)
                {
                    pos[y][x]=' ';
                    CHECK();
                    board();
                    goto pos1;
                }
                else if(key!=8)
                    goto pos1;
            }
            ASSIGN_pos();

            if(add!=2)
            {
                if(key==8)
                {
                    pos[y][x]=' ';
                    CHECK();
                }
                else
                {
                    pos[y][x]=key;
                    CHECK();
                    if(add==3)
                    {
                        if(solution==0)
                           board(3);
                        else
                           board(2);
                    }
                    else
                        board();
                    if(strcmpi(status,"WRONG")==0)
                    {
                        gotoxy(100,20);
                        cout<<"WRONG GOING... :(";
                        gotoxy(100,22);
                        cout<<"RED -> CHECK FOR REPEATITIONS";
                        goto pos1;
                    }
                }
            }
            else
            {
                if(key==8)
                    sol[y][x]=' ';
                else
                    sol[y][x]=key;
                CHECK(1);
            }
            addcomplete:
            if(add==2)
                board(1);
            else if(add==3)
            {
                if(solution==0)
                   board(3);
                else
                   board(2);
            }
        }
        if(add==1)
            return(key);
        else
            return(key);
    }



    void ASSIGN_pos()
    {
        int sumx,sumy;
        x=0;
        y=0;

        sumx=8+(6*l)+(19*k);

        sumy=5+(3*j)+(10*i);

        if(sumx==14)
        {
            x=1;
        }
        if(sumx==20)
        {
            x=2;
        }
        if(sumx==26)
        {
            x=3;
        }
        if(sumx==33)
        {
            x=4;
        }
        if(sumx==39)
        {
            x=5;
        }
        if(sumx==45)
        {
            x=6;
        }
        if(sumx==52)
        {
            x=7;
        }
        if(sumx==58)
        {
            x=8;
        }
        if(sumx==64)
        {
            x=9;
        }


        if(sumy==8)
        {
            y=1;
        }
        if(sumy==11)
        {
            y=2;
        }
        if(sumy==14)
        {
            y=3;
        }
        if(sumy==18)
        {
            y=4;
        }
        if(sumy==21)
        {
            y=5;
        }
        if(sumy==24)
        {
            y=6;
        }
        if(sumy==28)
        {
            y=7;
        }
        if(sumy==31)
        {
            y=8;
        }
        if(sumy==34)
        {
            y=9;
        }

    }



    void UP()
    {
        if(i==0)
        {
            if(j==1)
            {
                i=2;
                j=3;
            }
            else if(j==2)
                j--;
            else if(j==3)
                j--;
        }
        else if(i==1)
        {
            if(j==1)
            {
                i--;
                j=3;
            }
            else if(j==2)
                j--;
            else if(j==3)
                j--;
        }
        else if(i==2)
        {
            if(j==1)
            {
                i--;
                j=3;
            }
            else if(j==2)
                j--;
            else if(j==3)
                j--;
        }
    }



    void LEFT()
    {
        if(k==0)
        {
            if(l==1)
            {
                k=2;
                l=3;
            }
            else if(l==2)
                l--;
            else if(l==3)
                l--;
        }
        else if(k==1)
        {
            if(l==1)
            {
                k--;
                l=3;
            }
            else if(l==2)
                l--;
            else if(l==3)
                l--;
        }
        else if(k==2)
        {
            if(l==1)
            {
                k--;
                l=3;
            }
            else if(l==2)
                l--;
            else if(l==3)
                l--;
        }
    }



    void RIGHT()
    {
        if(k==0)
        {
            if(l==1)
                l++;
            else if(l==2)
                l++;
            else if(l==3)
            {
                l=1;
                k++;
            }
        }
        else if(k==1)
        {
            if(l==1)
                l++;
            else if(l==2)
                l++;
            else if(l==3)
            {
                l=1;
                k++;
            }
        }
        else if(k==2)
        {
            if(l==1)
                l++;
            else if(l==2)
                l++;
            else if(l==3)
            {
                l=1;
                k=0;
            }
        }
    }



    void DOWN()
    {
        if(i==0)
        {
            if(j==1)
                j++;
            else if(j==2)
                j++;
            else if(j==3)
            {
                j=1;
                i++;
            }
        }
        else if(i==1)
        {
            if(j==1)
                j++;
            else if(j==2)
                j++;
            else if(j==3)
            {
                j=1;
                i++;
            }
        }
        else if(i==2)
        {
            if(j==1)
                j++;
            else if(j==2)
                j++;
            else if(j==3)
            {
                j=1;
                i=0;
            }
        }
    }



    void CHECK(int solcheck=0)
    {
        //BOX CHECK
        if(BOX(solcheck)==1)
            goto pos2;

        //LINE DOWNWARDS
        if(LINE_DOWNWARDS(solcheck)==1)
            goto pos2;

        //LINE SIDEWAYS
        if(LINE_SIDEWAYS(solcheck)==1)
            goto pos2;

        strcpy(status,"CORRECT");

        pos2:
        if(strcmpi(status,"WRONG")==0)
            system("color 04");
        else
            system("color 0f");

    }



    int LINE_DOWNWARDS(int solcheck)
    {
        int cpointx,cpointy,a;

        for(cpointx=1;cpointx<=9;cpointx++)
        {
            for(cpointy=1;cpointy<=9;cpointy++)
            {
                for(a=1;a<=9;a++)
                {
                    if(solcheck==0)
                    {
                        if(cpointy==a || pos[cpointy][cpointx]==' ')
                            continue;
                        if(pos[cpointy][cpointx]==pos[a][cpointx])
                        {
                            strcpy(status,"WRONG");
                            return(1);
                        }
                        else
                            continue;
                    }
                    else
                    {
                        if(cpointy==a || sol[cpointy][cpointx]==' ')
                            continue;
                        if(sol[cpointy][cpointx]==sol[a][cpointx])
                        {
                            strcpy(status,"WRONG");
                            return(1);
                        }
                        else
                            continue;
                    }
                }
            }
        }
    }





    int LINE_SIDEWAYS(int solcheck)
    {
        int cpointx,cpointy,b;

        for(cpointy=1;cpointy<=9;cpointy++)
        {
            for(cpointx=1;cpointx<=9;cpointx++)
            {
                for(b=1;b<=9;b++)
                {
                    if(solcheck==0)
                    {
                        if(cpointx==b || pos[cpointy][cpointx]==' ')
                            continue;
                        if(pos[cpointy][cpointx]==pos[cpointy][b])
                        {
                            strcpy(status,"WRONG");
                            return(1);
                        }
                        else
                            continue;
                    }
                    else
                    {
                        if(cpointx==b || sol[cpointy][cpointx]==' ')
                            continue;
                        if(sol[cpointy][cpointx]==sol[cpointy][b])
                        {
                            strcpy(status,"WRONG");
                            return(1);
                        }
                        else
                            continue;
                    }
                }
            }
        }
    }





    int BOX(int solcheck)
    {
        int a,b,c,d,e,f;
        int cpointx,cpointy;
        int box_x,box_y;

        //BOX ALLOCATION
        for(box_x=1;box_x<=9;box_x+=2)
        {
            if(box_x<=3)
            {
                c=1;
                d=3;
            }
            else if(box_x<=6)
            {
                c=4;
                d=6;
            }
            else if(box_x<=9)
            {
                c=7;
                d=9;
            }

            for(box_y=1;box_y<=9;box_y+=2)
            {
                if(box_y<=3)
                {
                    a=1;
                    b=3;
                }
                else if(box_y<=6)
                {
                    a=4;
                    b=6;
                }
                else if(box_y<=9)
                {
                    a=7;
                    b=9;
                }


                for(cpointy=a;cpointy<=b;cpointy++)
                {
                    for(cpointx=c;cpointx<=d;cpointx++)
                    {
                        for(e=a;e<=b;e++)
                        {
                            for(f=c;f<=d;f++)
                            {
                                if(solcheck==0)
                                {
                                    if(pos[cpointy][cpointx]!=' ')
                                    {
                                        if(cpointx==f && cpointy==e)
                                            continue;
                                        if(pos[cpointy][cpointx]==pos[e][f])
                                        {
                                            strcpy(status,"WRONG");
                                            return(1);
                                        }
                                        else
                                            continue;
                                    }
                                }
                                else
                                {
                                    if(sol[cpointy][cpointx]!=' ')
                                    {
                                        if(cpointx==f && cpointy==e)
                                            continue;
                                        if(sol[cpointy][cpointx]==sol[e][f])
                                        {
                                            strcpy(status,"WRONG");
                                            return(1);
                                        }
                                        else
                                            continue;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }





    int FILLED(int solfill=0)
    {
        int cpointx,cpointy,filled=0;

        for(cpointy=1;cpointy<=9;cpointy++)
        {
            for(cpointx=1;cpointx<=9;cpointx++)
            {
                if(solfill==0)
                {
                    if(pos[cpointy][cpointx]!=' ')
                    {
                        filled++;
                    }
                }
                else
                {
                    if(sol[cpointy][cpointx]!=' ')
                    {
                        filled++;
                    }
                }
            }
        }

        // IF FILLED THEN 81 IS RETURNED
        return(filled);
    }






    int passkeyget(char pskeycheck[20])
    {
        ifstream pskeyread;

        pskeyread.open("PASSKEY.txt",ios::in);
        if(!pskeyread)
        {
            cout<<"\n\n\tFILE NOT FOUND CONTAINING PASSKEY\n\tADDING FAILED\n";
            getch();
            return(0);
        }

        pskeyread.getline(pskeycheck,20,' ');
        pskeyread.close();
        return(1);
    }



    int passkeyverify(char pskeycheck[20])
    {
        char psk;
        int pskcount;
        char pskey[20];

        pskcount=-1;

        do
        {
            pskcount++;

            psk=getch();
            cout<<"*";

            if(pskcount+1<=strlen(pskeycheck) && psk==13)
            {
                cout<<"\n\n\t  WRONG PASSKEY";
                getch();
                return(0);
            }

            pskey[pskcount]=psk;
            pskey[strlen(pskeycheck)]='\0';

            if(pskcount+1==strlen(pskeycheck))
            {
                if(strcmpi(pskeycheck,pskey)==0)
                {
                    cout<<"\n\t  CORRECT PASSKEY";
                    return(1);
                }
                else
                {
                    cout<<"\n\n\t  WRONG PASSKEY";
                    return(0);
                }
            }

        }while(pskcount+1<strlen(pskeycheck) && psk!=13);
    }



    void ADDGAME()
    {
        char enter;
        int cpointy,cpointx;

        char pskeycheck[20];

        char agree;
        char choice;

        int addingfailed=0;
        char addprocess;
        int continueadd;

        heading();

        if(passkeyget(pskeycheck)==0)
        {
            cout<<"\n\n\t ADDING FAILED";
            cout<<"\n\n\t PRESS ANY KEY TO RETURN..";
            getch();
            return;
        }

        heading();
        cout<<"\n\n\n\n\n\n\tCONDITIONS FOR ADDING A NEW GAME : ";
        cout<<"\n\n\n\t~ You must know passkey to verify admin rights.";
        cout<<  "\n\t  PASSKEY : ";

        if(passkeyverify(pskeycheck)==0)
        {
            cout<<"\n\n\t ADDING FAILED";
            cout<<"\n\n\t PRESS ANY KEY TO RETURN..";
            getch();
            return;
        }

        cout<<"\n\n\t~ You must enter atleast 17 hints(numbers). PRESS ENTER";
        do
        {
            enter=getch();
        }while(enter!=13);
        cout<<"\n\n\t~ Your game must go against the rules of SUDOKU : \n";
        cout<<  "\n\t   -No row or coloumn should have repeatitions. PRESS ENTER";
        do
        {
            enter=getch();
        }while(enter!=13);
        cout<<  "\n\t   -No box should have reeatitions. PRESS ENTER";
        do
        {
            enter=getch();
        }while(enter!=13);
        cout<<"\n\n\t~ Press ENTER when you are done adding your game. PRESS ENTER";
        do
        {
            enter=getch();
        }while(enter!=13);
        cout<<"\n\n\t~ PRESS Esc to quit adding the game. PRESS ENTER";
        do
        {
            enter=getch();
        }while(enter!=13);

        Sudoku s;
        s.INITIALIZE();
        s.board();
        for(continueadd=0;continueadd<=80;continueadd++)
        {
            addprocess=s.INPUT(1);
            if(addprocess==13)
                break;
            else if(addprocess==27) //escape key
                return;
        }
        for(cpointy=1;cpointy<=9;cpointy++)
        {
            for(cpointx=1;cpointx<=9;cpointx++)
            {
                if(s.pos[cpointy][cpointx]!=' ')
                    s.ques[cpointy][cpointx]=1;
                else
                    s.ques[cpointy][cpointx]=0;
            }
        }

        ofstream storegame;
        storegame.open("SUDOKU.dat",ios::app|ios::binary);

        heading();

        wrongchoice:
        cout<<"\n\n\t\t WOULD YOU LIKE TO ENTER THE SOLUTION OF THIS GAME (y/n) :";
        choice=getch();
        choice=toupper(choice);
        cout<<choice;

        if(choice!='Y' && choice!='N')
        {
            cout<<"\n\n\t\t INVALID CHOICE";
            goto wrongchoice;
        }

        if(choice=='Y')
        {
            for(cpointy=1;cpointy<=9;cpointy++)
            {
                for(cpointx=1;cpointx<=9;cpointx++)
                {
                    s.sol[cpointy][cpointx]=' ';
                }
            }

            s.solution=1;
            for(cpointy=1;cpointy<=9;cpointy++)
            {
                for(cpointx=1;cpointx<=9;cpointx++)
                {
                    s.sol[cpointy][cpointx]=s.pos[cpointy][cpointx];
                }
            }
            while(s.FILLED(1)<81)
            {
                s.board(1);
                addprocess=s.INPUT(2);
            }
            gotoxy(100,22);
            cout<<"SAVING...";
            Sleep(700);
        }
        heading();

        storegame.seekp(0,ios::end);
        s.gamecode=(storegame.tellp()/sizeof(Sudoku))+1;
        storegame.write((char*)&s,sizeof(Sudoku));

        cout<<"\n\n\n\n\n\n\n\t\t\t GAME SAVED ||  GAME CODE : "<<s.gamecode;
        cout<<"\n\t\t\t PRESS ANY KEY TO RETURN..";
        getch();


        storegame.close();
    }



    void DEL()
    {
        int code;
        int found=0;
        int nowcodecorrect=0;
        int delfailed=0;

        char pskeycheck[20];

        Sudoku s;

        heading();

        ifstream del;
        ofstream deltemp;

        del.open("SUDOKU.DAT",ios::in|ios::binary);
        if(!del)
        {
            cout<<"\n\n\t ERROR..FILE CONTAINING GAMES IS ABSENT\n\n\t DELETING FAILED";
            cout<<"\n\n\t PRESS ANY KEY TO RETURN..";
            getch();
            return;
        }

        if(passkeyget(pskeycheck)==0)
        {
            cout<<"\n\n\t DELETING FAILED";
            cout<<"\n\n\t PRESS ANY KEY TO RETURN..";
            getch();
            return;
        }

        anothercode:

        cout<<"\n\n\t\t Enter the code of the game which you want to delete : ";
        cin>>code;

        deltemp.open("SUDOKUTEMP.DAT",ios::out|ios::binary);

        while(!del.eof())
        {
            del.read((char*)&s,sizeof(Sudoku));
            if(del.eof())
                break;
            if(s.gamecode==code)
            {
                cout<<"\n\n\t FILE TO BE DELETED FOUND. BUT, YOU NEED TO ENTER THE PASS KEY : ";
                if(passkeyverify(pskeycheck)==0)
                {
                    cout<<"\n\n\t DELETING FAILED";
                    cout<<"\n\n\t PRESS ANY KEY TO RETURN..";
                    del.close();
                    deltemp.close();
                    remove("SUDOKUTEMP.DAT");
                    cin.clear();
                    cin.ignore(10,'\n');
                    code=0;
                    //else it remembers the last inout of char entered last time in del.
                    getch();
                    return;
                }
                found=1;
                nowcodecorrect=1;
            }
            else
            {
                if(nowcodecorrect==1)
                {
                    s.gamecode=s.gamecode-1;
                }
                deltemp.write((char*)&s,sizeof(Sudoku));
            }
        }

        del.close();
        deltemp.close();

        if(found==1)
        {
            cout<<"\n\n\t GAME WITH CODE "<<code<<" DELETED AND CODE REARRANGED";
            remove("SUDOKU.DAT");
            rename("SUDOKUTEMP.DAT","SUDOKU.DAT");
            getch();
        }
        else
        {
            cout<<"\n\n\t ERROR..NO GAME WITH THAT GAMECODE\n\n\t DELETING FAILED";
            cout<<"\n\n\t PRESS ANY KEY TO RETURN..";
            remove("SUDOKUTEMP.DAT");
            cin.clear();
            cin.ignore(10,'\n');
            //else it remembers the last inout of char entered last time in del.
            getch();
            return;
            getch();
        }
    }





    void PLAYGAME()
    {
        int code;
        int found=0;
        int solgamecheck=0;
        int nosolgamecheck=0;
        int nosolcont[100];
        int solcont[100];
        int total;
        int gameover;

        char choice;
        char uploadsol[10][10];

        heading();

        ifstream play;
        play.open("SUDOKU.DAT",ios::in|ios::binary);
        if(!play)
        {
            cout<<"\n\n\n\t\t ERROR.. FILE CONATINING GAMES NOT FOUND.";
            cout<<"\n\n\t PRESS ANY KEY TO RETURN..";
            getch();
            return;
        }

        Sudoku s;

        play.seekg(0,ios::end);
        total=play.tellg()/sizeof(Sudoku);
        play.seekg(0,ios::beg);
        if(total==0)
        {
            cout<<"\n\n\t PLAYING FAILED\n\n\t NO GAMES FOUND IN THE RECORD";
            cout<<"\n\n\t PRESS ANY KEY TO RETURN..";
            getch();
            return;
        }

        heading();
        anothercode:
        wrongchoicecode:
        solgamecheck=0;
        nosolgamecheck=0;
        cout<<"\n\n\n\n\n\t\t Do you want to enter the game code(press C)\n\n\t\t                   OR\n\n\t\t Want to play a randomly selected game(press R) \n\n\n\n\t\t                   ";
        choice=getch();
        choice=toupper(choice);
        cout<<choice;

        if(choice!='C' && choice!='R')
        {
            cout<<"\n\n\t\t WRONG CHOICE";
            goto wrongchoicecode;
        }

        if(choice=='C')
        {
            cout<<"\n\n\t\t ENTER THE GAME CODE : ";
            cin>>code;
        }
        else
        {
            play.seekg(0,ios::beg);
            while(!play.eof())
            {
                play.read((char*)&s,sizeof(Sudoku));
                if(play.eof())
                    break;
                if(s.solution==1)
                {
                    solcont[solgamecheck]=s.gamecode;
                    solgamecheck++;
                }
                else
                {
                    nosolcont[nosolgamecheck]=s.gamecode;
                    nosolgamecheck++;
                }
            }

            if(solgamecheck!=0)
            {
                code=solcont[random(solgamecheck)];
            }
            else
            {
                code=nosolcont[random(nosolgamecheck)];
            }

        }

        play.close();
        // need of closing and reopening -> tellg returns -1
        play.open("SUDOKU.DAT",ios::in|ios::binary);

        while(!play.eof())
        {
            play.read((char*)&s,sizeof(Sudoku));
            if(play.eof())
                break;
            if(s.gamecode==code)
            {
                if(s.solution==0)
                {
                    if(choice=='C')
                    {
                        cout<<"\n\n\t Your game has been found but its solution is not saved.";
                        wrongchoiceanothercode:
                        cout<<"\n\n\t Would you like to switch to another game : (y/n)";
                        choice=getch();
                        choice=toupper(choice);
                        cout<<choice;

                        if(choice!='Y' && choice!='N')
                        {
                            cout<<"\n\n\t\t WRONG CHOICE";
                            goto wrongchoiceanothercode;
                        }

                        if(choice=='Y')
                            goto anothercode;
                    }
                    else
                    {
                        cout<<"\n\n\t A game has been selected for you.";
                        cout<<"\n\n\t But, no games were found containing solutions.";
                        cout<<"\n\n\t So, you won't be able to view the solution";
                        cout<<"\n\n\t However if you solve this now, solution will be stored";
                        cout<<"\n\t permanently and can be viewed next time.";
                        getch();
                    }
                }
                gameover=s.STARTGAME(s.solution);
                if(s.solution==0)
                {
                    gameover++;
                    s.UPLOADSOLUTION(uploadsol);
                }
                found=1;
                break;
            }
        }
        if(found==0)
        {
            cout<<"\n\n\t NO GAME EXISTS WITH THAT CODE";
            cin.clear();
            cin.ignore(10,'\n');
            //else it remembers the last char inout in this func in code.
            goto anothercode;
        }

        play.close();

        if(gameover==2)
        {
            UPLOADSOLUTION(uploadsol,1,code);
        }
    }



    void UPLOADSOLUTION(char uploadsol[10][10],int cu=0,int code=0)
    {

        if(cu==0)
        {
            for(int i=1;i<=9;i++)
            {
                for(int j=1;j<=9;j++)
                {
                    uploadsol[i][j]=pos[i][j];
                }
            }
        }
        else if(cu==1)
        {
            fstream savesol;
            savesol.open("SUDOKU.DAT", ios::binary|ios::in|ios::out|ios::ate);
            savesol.seekg(0,ios::beg);

            Sudoku s;

            while(!savesol.eof())
            {
                savesol.read((char*)&s,sizeof(Sudoku));
                if(savesol.eof())
                    break;
                if(s.gamecode==code)
                {
                    for(int i=1;i<=9;i++)
                    {
                        for(int j=1;j<=9;j++)
                        {
                            s.sol[i][j]=uploadsol[i][j];
                        }
                    }
                    s.solution=1;
                    break;
                }
            }
            savesol.seekg(savesol.tellg()-sizeof(Sudoku),ios::beg);
            savesol.write((char*)&s,sizeof(Sudoku));
            savesol.close();
        }
    }





    int STARTGAME(int solegamecheck)
    {
        char entry;

        int wingreen;

        do
        {
            gamecontinue:
            if(solegamecheck==0)
                board(3);
            else
                board(2);
            entry=INPUT(3);
            if(FILLED()==81 && strcmpi(status,"CORRECT")==0)
            {
                board();
                gotoxy(95,17);
                cout<<"CONGRATULATIONS..!!! :)";
                for(wingreen=1;wingreen<=14;wingreen++)
                {
                    Sleep(100);
                    system("color 2f");
                    Sleep(500);
                    system("color 0f");
                }
                Sleep(5000);
                return(1);
            }
            if(entry=='S')
            {
                if(solegamecheck==0)
                    goto gamecontinue;
                board(1);
                gotoxy(100,16);
                cout<<"H - HIDE SOLUTION";
                do
                {
                    entry=getch();
                }while(entry!='H' && entry!='h');
            }
        }while(FILLED()!=81 && entry!='Q');

    }



    void HowToPlay()
    {
        char entry;
        heading();
        cout<<"\n";
        cout<<"________________________________________________________________________________________________________________________________________________________________________";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t     HOW TO PLAY ? \n";
        cout<<"________________________________________________________________________________________________________________________________________________________________________";
        cout<<"\n";
        cout<<"\n           _______________________________________________________";
        cout<<"\n         ||_______________________________________________________||";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||                      INSTRUCTIONS : ";
        cout<<"\n         ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||                      1. Use the arrow keys for accessing a particular cell.";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n         ||_____|_____|_____||_____|_____|_____||_____|_____|_____||                      2. You have to fill the cells with numbers(1-9) only.";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||                      3. In order to win, you must fill all th cells in such a way that:";
        cout<<"\n         ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n         ||_____ _____ _____||_____ _____ _____||_____ _____ _____||                         - No line should have repeatitions";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||                         - No box should have repeatitions";
        cout<<"\n         ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||                      4. You can view the solution of the game anytime by pressing S.";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n         ||_____|_____|_____||_____|_____|_____||_____|_____|_____||                      5. You can Quit anytime by pressing Q.";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n         ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n         ||_____ _____ _____||_____ _____ _____||_____ _____ _____||";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||             <----THE BOARD WILL LOOK LIKE THIS";
        cout<<"\n         ||_____|_____|_____||_____|_____|_____||_____|_____|_____||                  WAITING FOR YOU TO SOLVE IT";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||                  HAVING FEW HINTS TO HELP YOU.";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n         ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||                  PRESS ENTER KEY TO RETURN..";
        cout<<"\n         ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n         ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n         ||_____ _____ _____||_____ _____ _____||_____ _____ _____||";
        do
        {
            entry=getch();
        }while(entry!=13);
    }



    void ABOUT()
    {
        char entry;
        heading();
        cout<<"\n";
        cout<<"________________________________________________________________________________________________________________________________________________________________________";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t ABOUT \n";
        cout<<"________________________________________________________________________________________________________________________________________________________________________";
        cout<<"\n";
        cout<<"\n                                                                  _______________________________________________________";
        cout<<"\n                                                                ||_______________________________________________________||";
        cout<<"\n                                                                ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n    SUDOKU is alogic-based, combinatorial number placement      ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n                                                                ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n    puzzle. The objective is to fill a 9*9 grid with digits     ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n                                                                ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n    so that each column, each row, and each of the nine         ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n                                                                ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n    3*3 subgrids that compose the grid contains all of the      ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n                                                                ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n    digits from 1 to 9.                                         ||_____ _____ _____||_____ _____ _____||_____ _____ _____||";
        cout<<"\n                                                                ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n                                                                ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n                                                                ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n                                                                ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n                                                                ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n                                                                ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n                                                                ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n         PRESS ENTER KEY TO RETURN..                            ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n                                                                ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n                                                                ||_____ _____ _____||_____ _____ _____||_____ _____ _____||";
        cout<<"\n                                                                ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n                                                                ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n                                                                ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n                                                                ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n                                                                ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n                                                                ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n                                                                ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n                                                                ||     |     |     ||     |     |     ||     |     |     ||";
        cout<<"\n                                                                ||_____|_____|_____||_____|_____|_____||_____|_____|_____||";
        cout<<"\n                                                                ||_____ _____ _____||_____ _____ _____||_____ _____ _____||";
        do
        {
            entry=getch();
        }while(entry!=13);
    }



    void DRIVER()
    {
        char choice;

        int returnmain=0;

        do
        {
            wrongentry:
            heading();
            gotoxy(81,10);
            cout<<"MENU";
            gotoxy(76,13);
            cout<<"1. PLAY GAME";
            gotoxy(76,15);
            cout<<"2. ADD A GAME";
            gotoxy(76,17);
            cout<<"3. DELETE GAME";
            gotoxy(76,19);
            cout<<"4. HOW TO PLAY?";
            gotoxy(76,21);
            cout<<"5. ABOUT";
            gotoxy(76,23);
            cout<<"6. EXIT";
            gotoxy(79,28);
            cout<<"CHOICE : ";

            choice=getch();

            if(choice<49 || choice>56)
            {
                goto wrongentry;
            }
            else
            {
                cout<<choice;

                switch(choice)
                {
                    case '1': PLAYGAME();
                              break;

                    case '2': ADDGAME();
                              break;

                    case '3': DEL();
                              break;

                    case '4': HowToPlay();
                              break;

                    case '5': ABOUT();
                              break;

                    case '6': returnmain=1;
                              exit(0);
                }
            }
        }while(returnmain!=1);
    }



}game;




int main()
{
    char enter;

    srand(time(0));

    cout<<"\n\n\n\n\n\t\tPLEASE ENTER FULL SCREEN..AND PRESS ENTER THEN";
    do
    {
       enter=getch();
    }while(enter!=13);

    Sudoku s;
    system("color 1f");
    s.DRIVER();
}
