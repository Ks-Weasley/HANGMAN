#include<ctype.h>
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>
int limit;
char ch;
int gd=DETECT;
int gm;
void hangman(char *guess)
 { if(limit==1)
	line(450,200,450,230); //rope
  else if(limit==2)
	circle(450,250,20);   //head
  else if(limit==3)
     line(450,270,450,330);//body
  else if(limit==4)
     line(450,330,425,350);//leg
  else if(limit==5)
     line(450,330,475,350);//leg
  else if(limit==6)
     line(450,300,425,315);//hand
  else
   {  int maxx=getmaxx();
      cleardevice();
      for(int i=0;i<maxx;i++)
      {setcolor(WHITE);
      outtextxy(218,138,"PLAYER LOST!!!");
      outtextxy(218,150,"THE WORD IS:");
      outtextxy(318,150,guess);
      outtextxy(0+i,100,"SORRY!!BETTER LUCK NEXT TIME!!");
      setcolor(GREEN);
      outtextxy(415,175,"HANGED");
      setcolor(WHITE);
      line(385,400,450,400);
      line(415,400,415,200);
      line(415,200,450,200);
      line(375,170,375,410);//SIDE L
      line(500,170,500,410);//SIDE R
      line(375,170,500,170);//TOP
      line(375,410,500,410);//BOTTOM
      line(450,200,450,230);//rope
      setcolor(RED);
      circle(450,250,20);   //head
      line(450,270,450,330);//body
      line(450,330,425,350);//leg
      line(450,330,475,350);//leg
      line(450,300,425,315);//hand
      line(450,300,475,315);//hand
      delay(10);cleardevice();}
      getch();exit(0);
    }

}
void vowel(char *g)
 {
  for(int i=0;i<strlen(g);i++)
     switch(tolower(g[i]))
       { case 'a':
	 case 'e':
	 case 'i':
	 case 'o':
	 case 'u':outtextxy(289+i*30,102,"X");
	 }
  }
void repeat(char *r)
  {
  Read:
  static j=0;
  cout<<"\nenter a character:";
    ch=getchar();
    fflush(stdin);
    if(j)
    for(int i=0;i<j;i++)
      if(r[i]==ch)
       { cout<<"letter already entered!!";
	 goto Read;
	 }

      r[j++]=ch;


   }

void match(char *g)
 { int correct=0;static limit=0;
   int maxy=getmaxy();
   char temp[2];
   for(int i=0;g[i];i++)
       if(toupper(ch)==toupper(g[i]))
	  {
	  temp[0]=toupper(ch);
	  temp[1]='\0';
	  correct++;limit++;
	  outtextxy(285+i*30,80,temp);
	   }
if(correct==0)
    { cout<<"letter not found!!";
      ::limit++; }
if(limit==strlen(g))
{ clrscr();
for(int i=0;i<maxy/2;i+=10)
   { for(int j=0;j<=30;j++)
      { outtextxy(415,205,"WANTED");
	outtextxy(415,215,"CONVICTED");
	line(400,190,500,190);//top
	line(400,385,500,385);//bottom
	line(400,190,400,385);//side l
	line(500,190,500,385);//side r
	circle(450-i,250,20);   //head
	line(450-i,270,450-i,330);//body
	line(450-i,300,425-i,315);//hand
	line(450-i,300,475-i,315);//hand
	line(450-i,330,435+j-i,360);//leg
	line(450-i,330,465-j-i,360);//leg
	outtextxy(218,138,"PLAYER WON!!!");
	outtextxy(218,150,"THE WORD IS:");
	outtextxy(318,150,g);
	outtextxy(402,370,"ABSCONDING...");
  setcolor(GREEN);
       circle(218-j,140+j+1,2);
       circle(210-j,130-j,2);
       circle(227+j,130,2);
       circle(218,119-j,2);
 setcolor(YELLOW);
       circle(318-j,140+j+1,2);
       circle(310-j,130-j,2);
       circle(327+j,130,2);
       circle(318,119-j,2);
 setcolor(RED);
       circle(418-j,140+j+1,2);
       circle(410-j,130-j,2);
       circle(427+j,130,2);
       circle(418,119-j,2);
 setcolor(WHITE);
 delay(10);
 cleardevice();
} }
getch();exit(0);
}

}

void main()
{
clrscr();
initgraph(&gd,&gm,"C:\\TC\\BGI");
char check[50]={'0'},theme[][50]={"beauxbatons","expelliarmus","krum","dumstrang","weasley","hogwarts"};
char guess[50];
randomize();
strcpy(guess,theme[random(6)]);
for(int i=0;i<strlen(guess);i++)//dash
   line(285+i*30,100,300+i*30,100);
setcolor(RED);
outtextxy(285,20,"NOTE:X-DEPICTS VOWELS");
vowel(guess); //vowels
setcolor(WHITE);
line(385,400,450,400);//stand
line(415,400,415,200);//stand
line(415,200,450,200);//stand
cout<<"\t WELCOME TO HANG THE MAN";
cout<<"\nTHEME:-HARRY POTTER";
setcolor(WHITE);
cout<<"\nPLAYER CAN START GUESSING:-\n";
  for(i=0; ;i++)
  { repeat(check);
    match(guess);
    if(::limit)
	hangman(guess);
  }

getch();

}

