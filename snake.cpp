#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
char previous_Char;
int flag=0;
class food
{
    public :
    int fx,fy;
    char fvalue;
	void generate_food()
	{
		fx=rand()%50;
		fy=rand()%60;
	}
}milk;
class snake
{
    public :
    int sx,sy;
    char svalue;
};
void puts(char **board,int r,int c,vector<snake> &s)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==0||i==r-1)
            {
                board[i][j]='-';
            }
            else if(j==0||j==c-1)
            board[i][j]='|';
            else
            board[i][j]=' ';
        }
    }
    int s_len = s.size();

    for(int i=0;i<s_len;i++)
    {
        s[i].sx=4;
        s[i].sy=4+i+1;
        if(i==0)
         s[i].svalue='H';
         else if(i==s_len-1)
        s[i].svalue='T';
        else
        s[i].svalue='#';
    }
    for(int i=0;i<s.size();i++)
    {
        board[s[i].sx][s[i].sy]=s[i].svalue;
    }
    //food milk;
    milk.fx=20;
    milk.fy=30;
    milk.fvalue='M';
    board[milk.fx][milk.fy]=milk.fvalue;

}
void print(char **board,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<board[i][j];
        }
        cout<<endl;
    }
}
void move(char **board,vector<snake> &s,int r,int c,char ch)
{
    int prerow=s[0].sx;
    int precol=s[0].sy;
    if(ch=='w')
    {
		//if(board[s[0].sx-1][s[0].sy]==' ')
		s[0].sx=s[0].sx-1;
        if(s[0].sx==0)
        {
          s[0].sx=r-2;
        }
		
    }
    else if(ch=='s')
    {
        s[0].sx+=1;
        if(s[0].sx==r)
        {
            s[0].sx=1;
        }
		previous_Char='s';
    }
    else if(ch=='a')
    {
        s[0].sy-=1;
        if(s[0].sy==0)
        {
            s[0].sy=c-2;
        }
	
    }
    else if(ch=='d')
    {
         s[0].sy+=1;
         if(s[0].sy==c-1)
         {
             s[0].sy=1;
         }
	
    }
	for(int i=1;i<s.size();i++)
	{
		if((s[0].sx==s[i].sx)&&(s[0].sy==s[i].sy))
		{
			flag=1;
			return;
		}
	}
	
	if((s[0].sx==milk.fx)&&(s[0].sy==milk.fy))
	{
				int swapx,swapy;
			for(int i=1;i<s.size();i++)
			{
				swapx=s[i].sx;
				s[i].sx=prerow;
				prerow=swapx;
				 swapy=s[i].sy;
				s[i].sy=precol;
				precol=swapy;
			}
			snake ob;
			/*ob.sx=prerow;
			ob.sy=precol;
			ob.svalue='T';*/
				s.push_back(ob);
				int l = s.size();
				s[l-1].sx=prerow;
				s[l-1].sy=precol;
				s[l-1].svalue='T';
				s[l-2].svalue='#';
				milk.generate_food();
				board[milk.fx][milk.fy]=milk.fvalue;
	}
	else{
				int swapx,swapy;
				for(int i=1;i<s.size();i++)
				{
					swapx=s[i].sx;
					s[i].sx=prerow;
					prerow=swapx;
					 swapy=s[i].sy;
					s[i].sy=precol;
					precol=swapy;
				}
				board[prerow][precol]=' ';
	}
		for(int i=0;i<s.size();i++)
        {
			
        board[s[i].sx][s[i].sy]=s[i].svalue;
        }
}
int main()
{
    char **board = new char*[50];
    for(int i=0;i<50;i++)
    {
        *(board+i) = new char[80];
    }
    vector<snake> s(4);
     puts(board,50,80,s);
   print(board,50,80);
   char ch='a';
	previous_Char='a';
     while(1)
     {
         if(kbhit())
         {
			 previous_Char=ch;
             ch=getch();
         }
		  if(ch=='w'&&previous_Char=='s')
        ch=previous_Char;
	else if(ch=='s'&&previous_Char=='w')
		ch=previous_Char;
	else if(ch=='a'&&previous_Char=='d')
		ch=previous_Char;
	else if(ch=='d'&&previous_Char=='a')
		ch=previous_Char;
        move(board,s,50,80,ch);
		if(flag==1)
		{
			cout<<"ILLEGAL MOVE"<<endl;
			break;
		}
        print(board,50,80);
        Sleep(1);
        system("cls");
     }
}




