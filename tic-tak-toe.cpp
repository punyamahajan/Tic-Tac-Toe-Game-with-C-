#include<bits/stdc++.h>
using namespace std;
void drawBoard(char *spaces){
	cout<<"     |     |     "<<endl;
	cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  "<<endl;
	cout<<"_____|_____|______"<<endl;
	cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  "<<endl;
	cout<<"_____|_____|______"<<endl;
	cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  "<<endl;
	cout<<"     |     |     "<<endl;
}
void playerMove(char *spaces,char player){
	int number;
	do{
		cout<<"enter the place to enterr your marker(0-8)";
		cin>>number;
		if(spaces[number]==' ')
		{
			spaces[number]=player;
			break; 
		}
	}while(!number>0||!number<8);
	
}
void computerMove(char *spaces,char computer){
	int number;
	srand(time(0));
	while(true){
		number=rand()%9;
		if(spaces[number]==' ')
		{
			spaces[number]=computer;
			break;
		}
	}
	
}
bool checkWinner(char *spaces,char player,char computer){
	if(spaces[0]!=' '&&spaces[0]==spaces[1]&&spaces[1]==spaces[2])//1st horizontal row
	{
		spaces[0]==player?cout<<"YOU Win":cout<<"YOU Loose"<<endl;
	}
	    else if(spaces[3]!=' '&&spaces[3]==spaces[4]&&spaces[4]==spaces[5])//2nd horizontal row
	{
		spaces[3]==player?cout<<"YOU Win":cout<<"YOU Loose"<<endl;
	}
		else if(spaces[6]!=' '&&spaces[6]==spaces[7]&&spaces[7]==spaces[8])//3rd horizontal row
	{
		spaces[6]==player?cout<<"YOU Win":cout<<"YOU Loose"<<endl;
	}
		else if(spaces[0]!=' '&&spaces[0]==spaces[3]&&spaces[3]==spaces[6])//1st vertical row
	{
		spaces[0]==player?cout<<"YOU Win":cout<<"YOU Loose"<<endl;
	}
		else if(spaces[1]!=' '&&spaces[1]==spaces[4]&&spaces[4]==spaces[7])//2nd vertical row
	{
		spaces[1]==player?cout<<"YOU Win":cout<<"YOU Loose"<<endl;
	}
		else if(spaces[2]!=' '&&spaces[2]==spaces[5]&&spaces[5]==spaces[8])//3rd vertical row
	{
		spaces[2]==player?cout<<"YOU Win":cout<<"YOU Loose"<<endl;
	}
	    else if(spaces[0]!=' '&&spaces[0]==spaces[4]&&spaces[4]==spaces[8])//0 index
	{
		spaces[0]==player?cout<<"YOU Win":cout<<"YOU Loose"<<endl;
	}
		else if(spaces[2]!=' '&&spaces[2]==spaces[4]&&spaces[4]==spaces[6])
	{
		spaces[2]==player?cout<<"YOU Win":cout<<"YOU Loose"<<endl;
	}
		else if(spaces[6]!=' '&&spaces[6]==spaces[4]&&spaces[4]==spaces[2])
	{
		spaces[6]==player?cout<<"YOU Win":cout<<"YOU Loose"<<endl;
	}
		else if(spaces[8]!=' '&&spaces[8]==spaces[4]&&spaces[4]==spaces[0])
	{
		spaces[8]==player?cout<<"YOU Win":cout<<"YOU Loose"<<endl;
	}
		else if(spaces[4]!=' '&&spaces[4]==spaces[0]&&spaces[0]==spaces[8])
	{
		spaces[4]==player?cout<<"YOU Win":cout<<"YOU Loose"<<endl;
	}
		else if(spaces[4]!=' '&&spaces[4]==spaces[2]&&spaces[2]==spaces[6])
	{
		spaces[4]==player?cout<<"YOU Win":cout<<"YOU Loose"<<endl;
	}
	else
	{
		return false;
	}
	return true;
}
bool checkTie(char *spaces){
	for(int i=0;i<9;i++)
	{
	  if(spaces[i]==' ')
	  {
	  	return false;
	  }
	}
	cout<<"It's a Tie"<<endl;
	return true;
}
int main()
{
	char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
	char player='X';
	char computer='O';
	bool running=true;
	
	drawBoard(spaces);
	
	while(running){
		playerMove(spaces,player);
		drawBoard(spaces);
		if(checkWinner(spaces,player,computer)){
			running=false;
			break;
		}
	    else if(checkTie(spaces)){
			running=false;
			break;
		}
		
		computerMove(spaces,computer);
		drawBoard(spaces);
		if(checkWinner(spaces,player,computer)){
			running=false;
			break;
		}
	    else if(checkTie(spaces)){
			running=false;
			break;
		}
	}
	cout<<endl<<"Thankyou for Playing";
	
return 0;
}
