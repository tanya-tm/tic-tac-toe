#include<iostream>
#include<conio.h>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int ch;
int i,j;
char turn='X';
bool draw;
void display_board()
{    
    
	cout<<"\t\tplayer 1[X]\tplayer 2[O] \n\n";
	cout<<"\t\t    |           |       \n";
    cout<<"\t\t "<<board[0][0]<<"  |\t  "<<board[0][1]<<" \t|  "<<board[0][2]<<endl;
	cout<<"\t\t____|___________|_____\n";
	cout<<"\t\t    |           |       \n";
	cout<<"\t\t "<<board[1][0]<<"  |\t  "<<board[1][1]<<" \t|  "<<board[1][2]<<endl;
	cout<<"\t\t    |           |       \n";
	cout<<"\t\t____|___________|_____\n";
	cout<<"\t\t "<<board[2][0]<<"  |\t  "<<board[2][1]<<" \t|  "<<board[2][2]<<endl;
	cout<<"\t\t    |           |       \n";
    
}

void player_turn()
{  
   
   if (turn=='X')
   {
   	cout<<"\t\tplayer 1[X] choose your move"<<endl;
   	cout<<"\t\tenter position:  ";
   }
   else if(turn=='O')
   {
   	cout<<"\t\tplayer 2[O] choose your move"<<endl;
   	cout<<"\t\tenter position: ";
   }
   cin>>ch;
   
   switch(ch)
   {
   	case 1: i=0,j=0;
   	        break;
   	case 2: i=0,j=1;
   	        break;
   	case 3: i=0,j=2;
   	        break;
    case 4: i=1,j=0;
            break;
    case 5: i=1,j=1;
            break;
    case 6: i=1,j=2;
            break;
    case 7: i=2,j=0;
            break;
    case 8: i=2,j=1;
            break;
    case 9: i=2,j=2;
            break;
    default: cout<<"\t\tINVALID MOVE!!!\n";
   }

   if(turn=='X'&&board[i][j]!='X'&&board[i][j]!='O')
   {
	board[i][j]='X';
	turn='O';
   }
   else if(turn=='O'&&board[i][j]!='X'&&board[i][j]!='O')
   {
   	board[i][j]='O';
   	turn='X';
   }
   else
   {
   	cout<<"\t\tbox filled!!"<<endl;
   	cout<<"\t\tchoose another move----> "<<endl;
   	player_turn();
   }
   cout<<"\n";
}

bool result()
{   
    int i,j;
	for(i=0;i<3;i++)
	{
		if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]||board[0][i]==board[1][i]&&board[0][i]==board[2][i])
		return false;
	}

		if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]||board[0][2]==board[1][1]&&board[0][2]==board[2][2])
	    return false;
	    
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(board[i][j]!='X'&&board[i][j]!='O')
			return true;
		}
	}
	draw=true;
	return false;
	
}

int main()
{  
    system("color 0c");
	cout<<"\n\t\t\t\t\t\t |T I C  T A C  T O E  G A M E| \t\t\t\t\t\t\t\n";
	cout<<"\n\n\t\tNOW LETS BEGIN THE WAR!! :) \n";
	while(result())
	{
		display_board();
	    player_turn();
	    result();
    }
    display_board();
	if(turn=='O'&& draw==false)
	{
		cout<<"\n\t\tPLAYER 1[X] WINS!!!";
	}
	else if(turn=='X'&&draw==false)
	{
		cout<<"\n\t\tPLAYER 2[O] WINS!!!";
	}
	else 
	{
		cout<<"\n\t\t GAME DRAW!! :(";
	}
	return 0;
}
