#include<iostream>
#include<fstream>
#include<cstdlib>
#include <ctime>
#include <Windows.h>
#include<conio.h>

using namespace std;

char arr[32][64];

int p1=0, p2=0, p3=0, p4=0;

int i1= 13, j1= 6;
int i2= 3, j2= 36;
int i3= 18, j3= 57;
int i4= 28, j4= 26;

struct Ludo
{
char names[4][20];
 //for taking names and number of players
int NoOfPlayers;
};

void playludo(int n,Ludo& l);//from where the functions are called
void TurnDisplay(int player, Ludo& l);// To display player's turn
void Rules();//for displaying rules of games
void About();//About the author of code
void Menu();//Menu for selecting out of various choices
void Welcome(); //for displaying welcome screen
void StartScreen();//To Display starting screen
void Newgame();//for playing new game
void inputNames(Ludo& l);//inputing the names of players
void SavingGame(Ludo l);//for saving game on user choice
void SavedGamesDisplay(Ludo& l);//to display all the saved games
void OpenSaveGame();//for opening the saved games
int sustain(); //used when number generated is greater than number required to finish the token
int winmoves(int n, int p, int &js, int &is);//used when the number generated is the number required to finish the token
bool wins();//to check if a player has won or not
void designludo(int n);//for creation of ludo board
void displayludo();//for displaying ludo board created above
int moves(int &is, int &js, int &n, int p);//for editing the ludo board as a result of a chance
void moveahead2(int c);//if second player's token has to be moved
void moveahead3(int c);//if third player's token has to be moved
void moveahead4(int c);//if fourth player's token has to be moved
void moveahead(int n, int c);//for moving of token
void playludo_helper(int n);//Initialize the tokens and no. of players


int sustain() //used when number generated is greater than number required to finish the token
{
    cout<<"TOO FEW MOVES LEFT. CANNOT MOVE AHEAD!!"<<endl;
    return -1;
}
int winmoves(int n, int p, int &js, int &is)//used when the corresponding player has to go to its final lane
{
    int cnt=0;
    if(p==1)
        //when first token is going out
    {
        for(int j=js+4; j<=22; j+=4)
        {
            js=j;
            cnt++;
            if(cnt==n) return 0;
        }
        if(n-cnt==1)
        {
            p1++;
            return 1;
        }
        else
        {
            return sustain();
        }
    }
     if(p==2)
      //when second token is going out
    {
        for(int i=is+2; i<=11; i+=2)
        {
            is=i;
            cnt++;
            if(cnt==n) return 0;
        }
        if(n-cnt==1)
        {
            p2++;
            return 1;
        }
        else
        {
            return sustain();
        }
    }

     if(p==3)
        //when third token is going out
    {
        for(int j=js-4; j>=41; j-=4)
        {
            js=j;
            cnt++;
            if(cnt==n) return 0;
        }

        if(n-cnt==1)

        {
            p3++;
            return 1;
        }
        else
        {
            return sustain();
        }
    }
     if(p==4)//when the final token is going out(game finish)
    {
        for(int i=is-2; i>=20; i-=2)
        {
            is=i;
            cnt++;
            if(cnt==n) return 0;
        }
        if(n-cnt==1)
        {
            p4++;
            return 1;
        }
        else
        {
            return sustain();
        }
    }
}

bool wins()
//to check if a player has won or not
{
     system("CLS");
    if(p1==5)//if player 1 has won
    {
        cout<<"PLAYER 1 WINS"<<endl;
        cout<<"THANK YOU FOR PLAYING!"<<endl;
        return true;
    }
     if(p2==5)//if player 2 has won
    {
        cout<<"PLAYER 2 WINS"<<endl;
        cout<<"THANK YOU FOR PLAYING!"<<endl;
        return true;
    }
     if(p3==5)//if player 3 has won
    {
        cout<<"PLAYER 3 WINS"<<endl;
        cout<<"THANK YOU FOR PLAYING!"<<endl;
        return true;
    }
     if(p4==5)//if player 4 has won
    {
        cout<<"PLAYER 4 WINS"<<endl;
        cout<<"THANK YOU FOR PLAYING!"<<endl;
        return true;
    }
    return false;//if none of them won
}

void designludo(int n)
//for creation of ludo board
{
 for(int i=0;i<32;i++)
    {
        for(int j=0;j<64;j++)
        {
            if(i==0||i==31||j==0||j==63)
            {
               arr[i][j]='*';

            }
            else if((j==4||j==8||j==16||j==20||j==43||j==47||j==55||j==59)&&(i>=12&&i<=19)) arr[i][j]='*';

            else if((i==2||i==4||i==8||i==10||i==21||i==23||i==27||i==29)&&(j>=24&&j<=39)) arr[i][j]='*';

            else if((j==29||j==34)&&(i<=12||i>=19)) arr[i][j]='*';

            else if((i==14||i==17)&&(j<=24||j>=39)) arr[i][j]='*';

             else if(i==6||i==12||i==19||i==25) arr[i][j]='*';

             else if(j==12||j==24||j==39||j==51) arr[i][j]='*';

            else arr[i][j]='\0';
        }
    }
    if(n==4)
        //if 4 players are playing
    {
         arr[3][6]= '+';
             arr[3][18]= '+';
             arr[9][6]='+';
             arr[9][18]='+';
             arr[3][45]= 'X';
             arr[3][57]= 'X';
             arr[9][45]='X';
             arr[9][57]='X';
             arr[22][6]= '#';
             arr[22][18]= '#';
             arr[28][6]='#';
             arr[28][18]='#';
             arr[22][45]= '@';
             arr[22][57]= '@';
             arr[28][45]='@';
             arr[28][57]='@';
    }
    else if(n==3)
    //if 3 players are playing
    {
         arr[3][6]= '+';
             arr[3][18]= '+';
             arr[9][6]='+';
             arr[9][18]='+';
             arr[3][45]= 'X';
             arr[3][57]= 'X';
             arr[9][45]='X';
             arr[9][57]='X';
              arr[22][45]= '@';
             arr[22][57]= '@';
             arr[28][45]='@';
             arr[28][57]='@';
    }
    else
    //if 2 players are playing
    {
             arr[3][6]= '+';
             arr[3][18]= '+';
             arr[9][6]='+';
             arr[9][18]='+';
             arr[3][45]= 'X';
             arr[3][57]= 'X';
             arr[9][45]='X';
             arr[9][57]='X';

    }

}
  void displayludo()
  //for displaying ludo board created above
  {
       cout<<endl;

    for(int i=0;i<32;i++)
    {
        for(int j=0;j<64;j++)
        {

            cout<<arr[i][j];
        }

        cout<<endl;
    }
  }
  int moves(int &is, int &js, int &n, int p)
  //for editing the ludo board as a result of a chance
  {
      int cnt=0;
      if(cnt==n)
      return 0;
      if(is>=1&&is<=11)
      {
          if(js==26)
          {
              for(int i=is-2;i>=1; i-=2)
              {
                  is=i;
                  cnt++;
                  if(cnt==n) return 0;
              }
              is=1, js= 31;
              cnt++;
              if(cnt==n) return 0;

          }
          if(js==31)
          {
              if(p!=2)
              {
                  cnt++;
              js=36;
              if(cnt==n) return 0;
              }
              else
              {
                  int ans= winmoves(n-cnt,2, js, is);//for checking if this was a win move or not
                  return ans;
              }
          }
          if(js==36)
          {
              for(int i=is+2; i<=11; i+=2)
              {
                  is=i;
                  cnt++;
                  if(cnt==n) return 0;
              }

              is=13; js=41; cnt++;
              if(cnt==n) return 0;
          }
      }

      if(js>=41&&js<=61)
      {
          if(is==13)
          {
              for(int j=js+4;j<=61;j+=4)
              {
                  js=j;
                  cnt++;
                  if(cnt==n) return 0;
              }
              is=16;
              js=61;
              cnt++;
              if(cnt==n) return 0;
          }
         if(is==16)
         {
             if(p!=3)
             {
                 is=18;
             cnt++;
             if(cnt==n) return 0;
             }
             else
              {
                  int ans= winmoves(n-cnt,3, js, is);
                  //for checking if this was a win move or not

                  return ans;
              }
         }
         if(is==18)
         {
             for(int j=js-4;j>=41; j-=4)
             {
                 js=j;
                 cnt++;
                 if(cnt==n) return 0;
             }

             is=20;
             js=36;
             cnt++;

             if(cnt==n) return 0;

         }

      }

      if(is>=20&&is<=30)
      {
          if(js==36)
          {
              for(int i=is+2; i<=30; i+=2)
              {
                  is=i;
                  cnt++;
                  if(cnt==n) return 0;
              }
              is=30;
              js=31;
              cnt++;
              if(cnt==n) return 0;
          }
          if(js==31)
          {
              if(p!=4)
              {
                  cnt++;
              js=26;
              if(cnt==n) return 0;
              }
              else
              {
                  int ans= winmoves(n-cnt,4, js, is);//for checking if this was a win move or not
                  return ans;
              }
          }
          if(js==26)
          {
              for(int i=is-2;i>=20;i-=2)
              {
                  is=i;
                  cnt++;
                  if(cnt==n) return 0;
              }
              is=18;
              js=22;
              cnt++;
              if(cnt==n) return 0;
          }
      }
      if(js>=2&&js<=22)
      {
          if(is==18)
          {
              for(int j=js-4;j>=2;j-=4)
              {
                  js=j;
                  cnt++;
                  if(cnt==n) return 0;
              }
              is=16;
              js= 2;
              cnt++;
              if(cnt==n) return 0;
          }
              if(is==16)
              {
                  if(p!=1)
                  {
                      is=13;
                  cnt++;
                  if(cnt==n) return 0;
                  }
                  else
              {
                  int ans= winmoves(n-cnt,1, js, is);//for checking if this was a win move or not
                  return ans;
              }
              }
          if(is==13)
          {
              for(int j=js+4;j<=22;j+=4)
              {
                  cnt++;
                  js=j;
                  if(cnt==n) return 0;
              }
              is=11;
              js=26;
              cnt++;
              if(cnt==n) return 0;
          }
      }
      n= n-cnt;
      return moves(is,js,n,p);
  }
  void moveahead1(int c)//if first player's token has to be moved
  {
      if(p1==0&&c!=1) return;
      if(p1==0)
      {
          arr[3][18]='\0';
          arr[13][6]= '+';
          p1++;
          cout<<"PLAYER 1 ACTIVATED!!"<<endl;
          return;
      }
      int i=i1, j=j1;
      ///pass i1 and j1 by reference
     int ans= moves(i,j,c, 1);
     if(ans==0)
     {
        arr[i][j]='+';
        arr[i1][j1]='\0';
        i1=i;
        j1=j;
     }
     else if(ans==1)
     {
         cout<<"CONGRATULATIONS YOU COMPLETED ONE LEVEL"<<endl;
         arr[i1][j1]='\0';
         if(p1!=5)
         arr[13][6]= '+';
         i1=13;
         j1=6;
         if(p1==2)
         {
             arr[3][6]='\0';
         }
         else if(p1==3)
         {
             arr[9][6]= '\0';
         }
         else arr[9][18]= '\0';
     }
  }
  void moveahead2(int c)//if second player's token has to be moved
  {
      if(p2==0&&c!=1) return;
      if(p2==0)
      {
          arr[9][57]= '\0';
          arr[3][36]='X';
          p2++;
          cout<<"PLAYER 2 ACTIVATED!!"<<endl;
          return;
      }
      int i=i2, j=j2;
      int ans=moves(i,j,c,2);
      if(ans==0)
      {
          arr[i][j]='X';
      arr[i2][j2]='\0';
      i2=i;
      j2=j;
      }
      else if(ans==1)
     {
         cout<<"CONGRATULATIONS YOU COMPLETED ONE LEVEL"<<endl;
         arr[i2][j2]='\0';
         if(p2!=5)
         arr[3][36]= 'X';
         i2=3;
         j2= 36;
         if(p1==2)
         {
             arr[9][45]='\0';
         }
         else if(p1==3)
         {
             arr[3][45]= '\0';
         }
         else arr[3][57]= '\0';
     }
  }
  void moveahead3(int c)//if third player's token has to be moved
  {
      if(p3==0&&c!=1) return;
      if(p3==0)
      {
          arr[22][57]= '\0';
          arr[18][57]= '@';
          p3++;
          cout<<"PLAYER 3 ACTIVATED!!"<<endl;
          return;
      }
      int i=i3, j=j3;
      int ans=moves(i,j,c,3);
      if(ans==0)
      {
          arr[i][j]= '@';
      arr[i3][j3]='\0';
      i3=i;
      j3=j;
      }
      else if(ans==1)
      {
           if(ans==1)
     {
         cout<<"CONGRATULATIONS YOU COMPLETED ONE LEVEL"<<endl;
         arr[i3][j3]='\0';
         if(p3!=5)
         arr[18][57]= '@';
         i3= 18;
         j3=57;
         if(p1==2)
         {
             arr[22][45]='\0';
         }
         else if(p1==3)
         {
             arr[28][57]= '\0';
         }
         else arr[28][45]= '\0';
     }
      }
  }
  void moveahead4(int c)//if fourth player's token has to be moved
  {
      if(p4==0&&c!=1) return;
      if(p4==0)
      {
          arr[22][6]= '\0';
          arr[28][26]= '#';
          p4++;
          cout<<"PLAYER 4 ACTIVATED!!"<<endl;
          return;
      }
      int i=i4, j=j4;
      int ans= moves(i,j,c,4);
      if(ans==0)
      {
          arr[i][j]= '#';
      arr[i4][j4]='\0';
      i4=i;
      j4=j;
      }
       if(ans==1)
     {
         cout<<"CONGRATULATIONS YOU COMPLETED ONE LEVEL"<<endl;
         arr[i4][j4]='\0';
         if(p4!=5)
         arr[28][26]= '#';
         i4= 28;
         j4=26;
         if(p4==2)
         {
             arr[22][18]='\0';
         }
         else if(p4==3)
         {
             arr[28][6]= '\0';
         }
         else arr[28][18]= '\0';
     }
  }
  void moveahead(int i, int c)//for moving of token
  {
      if(i==1) moveahead1(c);
     else if(i==2) moveahead2(c);
      else if(i==3) moveahead3(c);
     else moveahead4(c);
  }

  void TurnDisplay(int player, Ludo& l) // To display player's turn
  {
	string name = l.names[player];
	short int length = name.length() + 11;
	cout << "\t\t\t\t\t\t ";
	for (int i = 0; i < length; i++)
		cout << '_'; cout << endl;
	cout << "\t\t\t\t\t\t|  " << name << "'s Turn  |\n";
	cout << "\t\t\t\t\t\t|";
	for (int i = 0; i < length; i++)
		cout << '_'; cout << "|\n";
}

  void playludo_helper(int n)
  {
      Ludo l;
      while(n<2 || n>4){
        cout<<"\n\t Warning:: Number of players should be atleast 2 and atmost 4";
        int p;
        cin>>p;
        n=p;
      }
      l.NoOfPlayers=n;
      inputNames(l);
      cout<<"\n\nPress 'S' for saving the Game: ";
      char ch;
      cin>>ch;
      if(ch=='S'){
      SavingGame(l);
      }
      playludo(n,l);
  }

  void playludo(int n,Ludo& l)//for playing ludo
  {

      for(int i=1;i<=n;i++)
      {

      system("CLS");
          TurnDisplay(i,l); // To display player's turn
          displayludo(); //to display ludo board
          cout<<"PLAYER "<<l.names[i]<<" PRESS '$' TO ROLL THE DIE AND '!' TO GO BACK TO THE MAIN MENU"<<endl;
          char ch;
          cin>>ch;
          //to exit to the main menu
          if(ch=='!'){
            cout<<"\n\nPress any key to go back to main menu:";
            getch();
            Menu();
          }
          int c= rand()%6 +1;//for generating a random number between 1 and 6
          if(c==6)//give a bonus point if the number generated is 6
          {
              cout<<"YOU GOT A SIX; ROLL AGAIN!!"<<endl;
              cin>>ch;
              c+= rand()%6 +1;
          }
          if(c==12)//give another bonus point if again 6 is generated
          {
              cout<<"YOU GOT A SIX; ROLL AGAIN!!"<<endl;
              c+= rand()%6 +1;
          }
          cout<<"NO. ON THE DIE: "<<c<<endl;
          if(c==18)//skipping of turn if number 6 is generated three times
          {
              Sleep(0.7);
              cout<<"18 ON THE DIE, TURN SKIPPED!!"<<endl;
              continue;
          }
           Sleep(2000);
          moveahead(i,c);

          if(wins()) return;//check if a player has won or not


      }
      if(!wins()) playludo(n,l);//if any player has not won then continue
  }

  void inputNames(Ludo& l)
  {
    //inputing the names of players
	for (int i = 1; i <= l.NoOfPlayers; i++)
  {      if(i>4)
        break;
		cout << "Enter Name of Player " << i << " : ";
		cin >> l.names[i];
	}
}

//use of file handling
void SavingGame(Ludo l) {
	ofstream save("SavedGames.ludo", ios::app | ios::binary);
	save.write((char*)& l, sizeof(l));
	save.close();
}

//Display saved database line by line
void SavedGamesDisplay(Ludo& l) {
	for (int i = 1; i <= l.NoOfPlayers; i++) {
            if(i>4)
            break;
		cout << l.names[i];
		if(i<l.NoOfPlayers) cout<<" VS ";
	}
	cout << endl;
}


void OpenSaveGame() {
	system("CLS");
	cout << "\n\n\n\n\n\t\tSAVED GAMES\n";
	ifstream read("SavedGames.ludo", ios::binary);
	read.seekg(0, ios::end);
	short int i = 0;
	Ludo savedludo;
	short int filesize = read.tellg();
	short int numberofGames = filesize / sizeof(Ludo);
	cout<<"\t\tNO. OF GAMES: "<<numberofGames<<endl;
	read.seekg(0, ios::beg);
	if (read.fail() or filesize < sizeof(Ludo)) {
		cout << "\t\t Saved Games\n\n";
		cout << "\t\tPress any key to back to Main Menu ";
		getch();
		Menu();
	}
	else {
		while (true)
		{
			read.read((char*)& savedludo, sizeof(Ludo));
			if (read.eof()) break;
			cout << "\t\t" << i + 1 << ". ";
			SavedGamesDisplay(savedludo);
			i++;
		}
		 read.close();
		cout << "\n\n\nPress any key to go back to Main Menu ";
	    getch();
	    Menu();
	}
}

  void StartScreen() //layout of starting screen
  {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t                        _________    _________\n";
	cout << "\t\t\t\t\t|          |        |  |         \\  |         |\n";
	cout << "\t\t\t\t\t|          |        |  |         |  |         |\n";
	cout << "\t\t\t\t\t|          |        |  |         |  |         |\n";
	cout << "\t\t\t\t\t|          |        |  |         |  |         |\n";
	cout << "\t\t\t\t\t|          |        |  |         |  |         |\n";
	cout << "\t\t\t\t\t|________  |________|  |_________/  |_________|\n";
	Sleep(2000);

}


void Welcome()//layout of welcome page
{
system("CLS");
 cout<<"\n\n\n\n\n\n\n\n\n";
 cout<<"\t\t\t\t                      WELCOME TO LUDO KING!!!"<<endl<<endl<<endl;
    cout << "\t\t\t\t\tLudo is a strategy board game for two to four players,\n";
	cout << "\t\t\t\t\tin which the players race their four tokens from start\n";
	cout << "\t\t\t\t\tto finish according to the rolls of a single die.\n";
	cout << "\t\t\t\t\tLike other cross and circle games, Ludo is derived\n";
	cout << "\t\t\t\t\tfrom the Indian game Pachisi, but simpler.\n";
 cout <<"\n\n\t\t\t\t\tPress any key to continue";
	getch();

    Menu();
}
void About()//layout of about page
 {
	system("CLS");
	cout << "\n\n\n\n\n\t\tABOUT\n\n";
	cout << "\t\tThis Game is Created By Ishika Goel   04701012018\n";
	cout << "\t\t                        Bhoomi Kohli  04901012018\n";
	cout << "\t\t                        Pranjli Singh 05001012018\n";
	cout << "\t\t                        Nandini Mehta 05901012018\n";
	cout << "\t\t                        Rhea Hooda    06001012018\n";
	cout << "\t\tPress any key to go to Menu Page";
	getch();
	Menu();
}
void Rules()//layout of page containing rules
{
	system("CLS");
	cout << "\n\n\n\n\n\t\tRULES\n";
	cout << "\t\t1. The Token will be out only when the Die Number is 1.\n";
	cout << "\t\t2. The Token can't be taken out when there is already a\n\t\tToken of same Player.\n";
    cout << "\t\t3. If the Token Moves to the Position where there is already a token Present then the chance of \n\t\tlatter player is skipped and token remains at previous position \n";
    cout << "\t\t4.if a player gets  a 6 on his die then he gets another chance but if a player gets three consecutive  6 then that chance is skipped\n";
	cout <<"\n\n\t\t\t\t\tPress any key to go back to Main Menu";
	getch();

    Menu();
}

void Newgame()//to start a new game
{
    system("CLS");
    cout<<"ENTER THE NUMBER OF PLAYERS(2-4)"<<endl;
    int n;//inputting the number of players
    cin>>n;
    designludo(n);
    playludo_helper(n);
}

void Menu()
{
	system("CLS");
	char choice;
  //creating menu
	cout << "\n\n\n\n\n\t\tMAIN MENU\n";
	cout << "\t\t1. RULES\n";
	cout << "\t\t2. ABOUT\n";
	cout << "\t\t3. NEWGAME\n";
	cout << "\t\t4. EXIT\n";
	cout << "\t\t5. DATABASE\n\n";
	cout << "\t\tPlease Select Your Option <1-5> : ";//taking choice from the user
	do {
		choice = getch();
		cout << endl;
		if (choice != '1' && choice != '2' && choice != '3' && choice!='4' && choice != '5')
			cout << "Please Select Correct Option <1-5> ";
	} while (choice != '1' && choice != '2' && choice != '3' && choice!='4' && choice != '5');

	 if (choice == '1')
     {
		Rules();
     }
	else if (choice == '2')
    {
		About();
    }
		else if(choice=='3')
        {
            Newgame();
        }
	else if (choice == '4')
    {
		exit(0);
    }
		else if (choice == '5')
        {
		OpenSaveGame();
        }
}
int main()
{
    srand((time(0)));
    //to create different sequence of numbers every time the program runs
    StartScreen();
    Welcome();
    Menu();
    system("pause");
    //used to execute pause command
    return 0;

}
