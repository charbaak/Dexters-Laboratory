



#define screenWidth 1550
#define screenHeight 788
#define dextersWidth 64
#define dextersHeigth 64
#define barWidth 4
#define xSpeed 10
#define ySpeed 10
#define enxSpeed 1
#define enySpeed 1
#define menu 1
#define intro 1000
#define hall_of_fame 2
#define instruction 3
#define about 4
#define level1 10
#define level2 101
#define level3 201
#define lost 20
#define finish 7
int gamestate=intro,disCnt=0;
#define sh screenHeight
#define bh barWidth
int counter=0,second1=0;

#include "halloffame.h"
#include "menu.h"



int barx[]={72,314,0,148,556,72,462,556,0,999,1200,1200,724,999,999,1076,76,148,420,894,1300,1230,550,72,386,242,658,923,1338,1124,1465,999,1359,72,321,1235,1086,790,890,1010,470};
//for looping x axis for bars of level1
int barDx[]={170,170,314,238,290,590,120,140,400,320,280,280,400,360,288,180,165,224,200,120,250,225,220,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh};
//for looping x axis length for bars of level1
int bary[]={sh-72,sh-72,sh-386,sh-304,sh-72,sh-464,sh-304,sh-148,sh-536,sh-72,sh-722,sh-648,sh-722,sh-386,sh-216,sh-298,sh-722,sh-648,sh-722,sh-612,sh-570,sh-480,sh-642,sh-304,sh-386,sh-228,sh-384,sh-295,sh-718,sh-722,sh-400,sh-384,sh-386,0,0,sh-212,sh-212,sh-525,sh-718,sh-612,sh-652};
//for looping y axis for bars of level1
int barDy[]={bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,bh,160,232,160,240,295,72,255,400,170,225,170,65,50,50,380,205,105,105};
//for looping y axis length for bars of level1
int mposx,  mposy,x=0,y=screenHeight-dextersHeigth-4;
//for drawing the bars of level1
char backwardRun[7][20]={"RunB6.bmp","RunB5.bmp","RunB4.bmp","RunB3.bmp","RunB2.bmp","RunB1.bmp"};
char forkwardRun[5][20]={"RunF1.bmp","RunF2.bmp","RunF3.bmp","RunF4.bmp"};
bool charstand = true,chforward=false,backward=false;
int standcounter = 0;
int index = 0,timecounter=0;
long long timeremaining=60;

void drawbars()
{
	//maze bar
	iSetColor(0,250,0);
	iFilledRectangle(72,screenHeight-72,170,barWidth);
	iFilledRectangle(314,screenHeight-72,170,barWidth);
	iFilledRectangle(0,screenHeight-386,314,barWidth);
	iFilledRectangle(148,screenHeight-304,238,barWidth);
	iFilledRectangle(556,screenHeight-72,290,barWidth);
	iFilledRectangle(72,screenHeight-464,590,barWidth);
	iFilledRectangle(462,screenHeight-304,120,barWidth);
	iFilledRectangle(556,screenHeight-148,140,barWidth);
	iFilledRectangle(0,screenHeight-536,400,barWidth);
	iFilledRectangle(999,screenHeight-72,320,barWidth);
	iFilledRectangle(1200,screenHeight-722,280,barWidth);
	iFilledRectangle(1200,screenHeight-648,280,barWidth);
	iFilledRectangle(724,screenHeight-722,400,barWidth);
	iFilledRectangle(999,screenHeight-386,360,barWidth);
	iFilledRectangle(999,screenHeight-216,288,barWidth);
	iFilledRectangle(1076,screenHeight-298,180,barWidth);
	iFilledRectangle(76,screenHeight-722,165,barWidth);
	iFilledRectangle(148,screenHeight-648,224,barWidth);
	iFilledRectangle(420,screenHeight-722,200,barWidth);
	iFilledRectangle(894,screenHeight-612,120,barWidth);
	iFilledRectangle(1300,screenHeight-570,250,barWidth);
	iFilledRectangle(1230,screenHeight-480,225,barWidth);
	iFilledRectangle(550,screenHeight-642,220,barWidth);//23 vertical bars


	iFilledRectangle(72,screenHeight-304,barWidth,160);
	iFilledRectangle(386,screenHeight-386,barWidth,232);
	iFilledRectangle(242,screenHeight-228,barWidth,160);
	iFilledRectangle(658,screenHeight-384,barWidth,240);
	iFilledRectangle(923,screenHeight-295,barWidth,295);
	iFilledRectangle(1338,screenHeight-718,barWidth,72);
	iFilledRectangle(1124,screenHeight-722,barWidth,255);
	iFilledRectangle(1465,screenHeight-400,barWidth,400);
	iFilledRectangle(999,screenHeight-384,barWidth,170);
	iFilledRectangle(1359,screenHeight-386,barWidth,225);
	iFilledRectangle(72,0,barWidth,170);
	iFilledRectangle(321,0,barWidth,65);
	iFilledRectangle(1235,screenHeight-212,barWidth,50);
	iFilledRectangle(1086,screenHeight-212,barWidth,50);
	iFilledRectangle(790,screenHeight-525,barWidth,380);
	iFilledRectangle(890,screenHeight-718,barWidth,205);
	iFilledRectangle(1010,screenHeight-612,barWidth,105);
	iFilledRectangle(470,screenHeight-652,barWidth,105);//18 horizontal bars
}
//keys for level1
struct KEYS
{
	int kx,ky,state;
}key1[5];
//for setting the key positions of level1
void keyposSet()
{
	srand(time(0));
	for(int i=0;i<5;i++)
	{
		key1[i].kx=rand()%1519;//random x-axis position of keys
		key1[i].ky=rand()%757;//random y-axis position of keys
		key1[i].state=1;//state 1 means key is visible
	}
}
//for showing keys
void keyShow()
{
	for(int i=0;i<5;i++)// 5 for 5 keys
	{
		if(key1[i].kx+32<=dextersWidth && key1[i].kx>=0 && key1[i].ky>=screenHeight-dextersHeigth-4 && key1[i].ky+32<=screenHeight)//check if key position in dexters initial position
		{
			key1[i].kx=rand()%1519;//change the position
			key1[i].ky=rand()%757;
		}
		if(key1[i].kx+32<=screenWidth && key1[i].kx>=1486 && key1[i].ky>=0 && key1[i].ky+32<=screenHeight-724)//check if key position in destination's initial position
		{
			key1[i].kx=rand()%1519;//change the position
			key1[i].ky=rand()%757;
		}
		if(key1[i].kx+64>screenWidth)//check that if it is in the screen
		{
			key1[i].kx=screenWidth-64;
		}
		if(key1[i].ky+64>screenHeight)//check that if it is in the screen
		{
			key1[i].kx=screenHeight-64;
		}
		for(int j=0;j<41;j++)//by loop check that the keys position overlap the bars position
		{
			if(key1[i].kx+32>barx[j] && key1[i].kx<barx[j]+barDx[j] && key1[i].ky+32>bary[j] && key1[i].ky<bary[j]+barDy[j])
			{
				key1[i].kx=rand()%1519;
				key1[i].ky=rand()%757;
				j=-1;
			}
		}
		if(key1[i].state)//if key's state true show the image
		{
			iShowBMP2(key1[i].kx,key1[i].ky,"key.bmp",0);
		}
	}
}
struct ENEMYES
{
	int ex,ey,state,dir;
}enemy[3];
void enemyposSet()//setting enemy position
{
	for(int i=0;i<3;i++)
	{
		enemy[i].ex=rand()%1487;//random settings of enemy's x-axis position
		enemy[i].ey=rand()%724;
		enemy[i].state=1;
		enemy[i].dir=rand()%4;//random direction setting
	}
}
void enemyShow()//showing enemy's
{
	second1++;
	if(second1>5)
	{
		second1=2;
	}
	for(int i=0;i<3;i++)
	{
		if(enemy[i].ex+64<=dextersWidth+100 && enemy[i].ex>=0 && enemy[i].ey>=screenHeight-dextersHeigth-4 && enemy[i].ey+64<=screenHeight && second1==1)//check if the enemy's initial postion set in dexter's initial position then change the position in random place
		{
			enemy[i].ex=rand()%1487;
			enemy[i].ey=rand()%724;
		}
		if(enemy[i].ex+64<=1540 && enemy[i].ex>=1350 && enemy[i].ey>=0 && enemy[i].ey+64<=100 && second1==1)//check if the enemy's initial postion set in destination's initial position then change the position in random place
		{
			enemy[i].ex=rand()%1487;
			enemy[i].ey=rand()%724;
		}
		if(enemy[i].ex+64>screenWidth)//check that enemy is in the screen
		{
			enemy[i].ex=screenWidth-64;
			enemy[i].dir=rand()%4;
		}
		if(enemy[i].ey+64>screenHeight)//check that enemy is in the screen
		{
			enemy[i].ey=screenHeight-64;
			enemy[i].dir=rand()%4;
		}
		if(enemy[i].ex+64>=x && enemy[i].ex<=x+64 && enemy[i].ey+64>=y && enemy[i].ey<=y+64)//if enemy touch the dexter he lost
		{
			gamestate=lost;

			PlaySound("music\\gameover.wav", NULL, SND_ASYNC);
			x=0;
			y=screenHeight-dextersHeigth-4;
			keyposSet();
			 keyShow();
			enemyposSet();
				
		}
		if(enemy[i].ex<0)//check that enemy is in the screen
		{
			enemy[i].ex=0;
			enemy[i].dir=rand()%4;
		}
		if(enemy[i].ey<0)//check that enemy is in the screen
		{
			enemy[i].ey=0;
			enemy[i].dir=rand()%4;
		}
		/*for(int j=0;j<41;j++)
		{
			if(enemy[i].ex+64>barx[j] && enemy[i].ex<barx[j]+barDx[j] && enemy[i].ey+64>bary[j] && enemy[i].ey<bary[j]+barDy[j])
			{
				enemy[i].ex=rand()%1487;
				enemy[i].ey=rand()%724;
				j=-1;
			}
		}*/
		if(enemy[i].state)//
		{
			iShowBMP2(enemy[i].ex,enemy[i].ey,"enemy.bmp",0);
		}
	}
}
void movingEnemy()//for enemy moving
{
	//printf("ENEMY");
	for(int i=0;i<3;i++)//loop for three enemy's
	{
		if(enemy[i].dir==0)//0 direction for right
		{
			enemy[i].ex+=enxSpeed;
		}
		else if(enemy[i].dir==1)//1 direction for left
		{
			enemy[i].ex-=enxSpeed;
		}
		else if(enemy[i].dir==2)//2 direction for up
		{
			enemy[i].ey+=enySpeed;
		}
		else
		{
			enemy[i].ey-=enySpeed;
		}
		/*if(enemy[i].ex+64<=screenWidth && enemy[i].ex>=1486 && enemy[i].ey>=0 && enemy[i].ey+64<=screenHeight-724)
		{
			enemy[i].ex;
			enemy[i].ey;
		}*/
		for(int j=0;j<41;j++)//for checking collision with bars
		{
			if(enemy[i].ex+64>barx[j] && enemy[i].ex<barx[j]+barDx[j] && enemy[i].ey+64>bary[j] && enemy[i].ey<bary[j]+barDy[j])
			{
				if(enemy[i].dir==0)//enemy direction
				{
					enemy[i].ex-=enxSpeed;
					enemy[i].dir=rand()%4;
					if(enemy[i].dir==0)
					{
						enemy[i].dir=rand()%4;
					}
					else if(enemy[i].dir==1)
					{
						enemy[i].ex-=enxSpeed;
					}
					else if(enemy[i].dir==2)
					{
						enemy[i].ey+=enySpeed;
					}
					else
					{
						enemy[i].ey-=enySpeed;
					}
				}
				else if(enemy[i].dir==1)//enemy direction
				{
					enemy[i].ex+=enxSpeed;
					enemy[i].dir=rand()%4;
					if(enemy[i].dir==0)
					{
						enemy[i].ex+=enxSpeed;
					}
					else if(enemy[i].dir==1)
					{
						enemy[i].dir=rand()%4;
					}
					else if(enemy[i].dir==2)
					{
						enemy[i].ey+=enySpeed;
					}
					else
					{
						enemy[i].ey-=enySpeed;
					}
				}
				else if(enemy[i].dir==2)//enemy direction
				{
					enemy[i].ey-=enxSpeed;
					enemy[i].dir=rand()%4;
					if(enemy[i].dir==0)
					{
						enemy[i].ex+=enxSpeed;
					}
					else if(enemy[i].dir==1)
					{
						enemy[i].ex-=enxSpeed;
					}
					else if(enemy[i].dir==2)
					{
						enemy[i].dir=rand()%4;
					}
					else
					{
						enemy[i].ey-=enySpeed;
					}
				}
				else//enemy direction
				{
					enemy[i].ey+=enxSpeed;
					enemy[i].dir=rand()%4;
					if(enemy[i].dir==0)
					{
						enemy[i].ex+=enxSpeed;
					}
					else if(enemy[i].dir==1)
					{
						enemy[i].ex-=enxSpeed;
					}
					else if(enemy[i].dir==2)
					{
						enemy[i].ey+=enySpeed;
					}
					else
					{
						enemy[i].dir=rand()%4;
					}
				}
				j=-1;
			}
		}
	}
}

void SpecialKeyBoardControl_Level1(unsigned char key)
{
	if(gamestate == 10)
	{	
		if(key == GLUT_KEY_RIGHT)//arrow key control
		{
			x+=xSpeed;
			PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
			standcounter=0;
			index++;
			chforward =true;
			charstand=false;
			backward =false;
			if(index>3)
			{
				index=0;
			}
			if(x>=screenWidth-dextersWidth)
			{
				x=screenWidth-dextersWidth;
			}
			else
			{
				for(int i=0;i<41;i++)
				{
					if(x+dextersWidth>barx[i] && x<barx[i]+barDx[i] && y+dextersHeigth>bary[i] && y<bary[i]+barDy[i])
					{
						x-=xSpeed;
						break;
					}
				}
				for(int i=0;i<5;i++)
				{
					if(x+dextersWidth>key1[i].kx && x<key1[i].kx+32 && y+dextersHeigth>key1[i].ky && y<key1[i].ky+32)
					{
						if(key1[i].state==1)
						{
							key1[i].state=0;//collect key
							PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
							disCnt++;
							totalscore += 50;
						}
					}
				}
				if(x+64>screenWidth-64 && x<=screenWidth && y+64>=0 && y<=screenHeight-724 && disCnt>=5)
				{
					gamestate=level2;//gatewayb to level 2
					PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);
					totalscore += 500;
					x=0;//reset after level up
					y=screenHeight-dextersHeigth-4;
					keyposSet();
					keyShow();
					enemyposSet();
				}
			}
		}
		else if(key == GLUT_KEY_LEFT)//arrow key control
		{
			x-=xSpeed;
			PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
			index++;
			standcounter=0;
			chforward = false;
			charstand=false;
			backward =true;
			if(index>5)
			{
				index=0;
			}
			if(x<=0)
			{
				x=0;
			}
			else
			{
				for(int i=0;i<41;i++)
				{
					if(x+dextersWidth>barx[i] && x<barx[i]+barDx[i] && y+dextersHeigth>bary[i] && y<bary[i]+barDy[i])
					{
						x+=xSpeed;
						break;
					}
				}
				for(int i=0;i<5;i++)
				{
					if(x+dextersWidth>key1[i].kx && x<key1[i].kx+32 && y+dextersHeigth>key1[i].ky && y<key1[i].ky+32)
					{
						if(key1[i].state==1)
						{
							key1[i].state=0;//collect key
							PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
							disCnt++;
							totalscore += 50;
						}
					}
				}
			}
		}
		else if(key ==  GLUT_KEY_UP)//arrow key control
		{
			y+=ySpeed ;
			PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
			charstand =true;
			chforward =false;
			backward =false;
			if(y>=screenHeight-dextersHeigth)
			{
				y=screenHeight-dextersHeigth;
			}
			else
			{
				for(int i=0;i<41;i++)
				{
					if(x+dextersWidth>barx[i] && x<barx[i]+barDx[i] && y+dextersHeigth>bary[i] && y<bary[i]+barDy[i])
					{
						y-=ySpeed;
						break;
					}
				}
				for(int i=0;i<5;i++)
				{
					if(x+dextersWidth>key1[i].kx && x<key1[i].kx+32 && y+dextersHeigth>key1[i].ky && y<key1[i].ky+32)
					{
						if(key1[i].state==1)
						{
							key1[i].state=0;//collect key
							PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
							disCnt++;
							totalscore += 50;
						}
					}
				}
			}
		}
		else if(key == GLUT_KEY_DOWN)//arrow key control
		{
			y-=ySpeed ;
			PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
			charstand =true;
			chforward =false;
			backward =false;
			if(y<=0)
			{
				y=0;
			}
			else
			{
				for(int i=0;i<41;i++)
				{
					if(x+dextersWidth>barx[i] && x<barx[i]+barDx[i] && y+dextersHeigth>bary[i] && y<bary[i]+barDy[i])
					{
						y+=ySpeed;
						break;
					}
				}
				for(int i=0;i<5;i++)
				{
					if(x+dextersWidth>key1[i].kx && x<key1[i].kx+32 && y+dextersHeigth>key1[i].ky && y<key1[i].ky+32)
					{
						if(key1[i].state==1)
						{
							key1[i].state=0;//collect key
							PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
							disCnt++;
							totalscore += 50;
						}
					}
				}
				if(x+64>screenWidth-64 && x<=screenWidth && y+64>=0 && y<=screenHeight-724 && disCnt>=5)
				{
					gamestate=level2;//gateway to level 2
					PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);
					totalscore += 500;
					x=0;//reset after level up
					y=screenHeight-dextersHeigth-4;
					keyposSet();
					keyShow();
					enemyposSet();
				}
			}
		}
	}
}

void iKeyBordControl_Level1(unsigned char key)
{
	if(gamestate == 10)
	{	
		if(key == 'd')//key
		{
			x+=xSpeed;
			PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
			standcounter=0;
			index++;
			chforward =true;
			charstand=false;
			backward =false;
			if(index>3)
			{
				index=0;
			}
			if(x>=screenWidth-dextersWidth)
			{
				x=screenWidth-dextersWidth;
			}
			else
			{
				for(int i=0;i<41;i++)
				{
					if(x+dextersWidth>barx[i] && x<barx[i]+barDx[i] && y+dextersHeigth>bary[i] && y<bary[i]+barDy[i])
					{
						x-=xSpeed;
						break;
					}
				}
				for(int i=0;i<5;i++)
				{
					if(x+dextersWidth>key1[i].kx && x<key1[i].kx+32 && y+dextersHeigth>key1[i].ky && y<key1[i].ky+32)
					{
						if(key1[i].state==1)
						{
							key1[i].state=0;//collect key
							PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
							disCnt++;
							totalscore += 50;
						}
					}
				}
				if(x+64>screenWidth-64 && x<=screenWidth && y+64>=0 && y<=screenHeight-724 && disCnt>=5)
				{
					gamestate=level2;//gateway to level 2
					PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);
					totalscore += 500;
					x=0;//reset after level up
					y=screenHeight-dextersHeigth-4;
					keyposSet();
					keyShow();
					enemyposSet();
				}
			}
		}
		else if(key == 'a')//keyboard control
		{
			x-=xSpeed;
			PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
			index++;
			standcounter=0;
			chforward = false;
			charstand=false;
			backward =true;
			if(index>5)
			{
				index=0;
			}
			if(x<=0)
			{
				x=0;
			}
			else
			{
				for(int i=0;i<41;i++)
				{
					if(x+dextersWidth>barx[i] && x<barx[i]+barDx[i] && y+dextersHeigth>bary[i] && y<bary[i]+barDy[i])
					{
						x+=xSpeed;
						break;
					}
				}
				for(int i=0;i<5;i++)
				{
					if(x+dextersWidth>key1[i].kx && x<key1[i].kx+32 && y+dextersHeigth>key1[i].ky && y<key1[i].ky+32)
					{
						if(key1[i].state==1)
						{
							key1[i].state=0;//collect  key
							PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
							disCnt++;
							totalscore += 50;
						}
					}
				}
			}
		}
		else if(key ==  'w')//keyboard control
		{
			y+=ySpeed ;
			PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
			charstand =true;
			chforward =false;
			backward =false;
			if(y>=screenHeight-dextersHeigth)
			{
				y=screenHeight-dextersHeigth;
			}
			else
			{
				for(int i=0;i<41;i++)
				{
					if(x+dextersWidth>barx[i] && x<barx[i]+barDx[i] && y+dextersHeigth>bary[i] && y<bary[i]+barDy[i])
					{
						y-=ySpeed;
						break;
					}
				}
				for(int i=0;i<5;i++)
				{
					if(x+dextersWidth>key1[i].kx && x<key1[i].kx+32 && y+dextersHeigth>key1[i].ky && y<key1[i].ky+32)
					{
						if(key1[i].state==1)
						{
							key1[i].state=0;//collect key
							PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
							disCnt++;
							totalscore += 50;
						}
					}
				}
			}
		}
		else if(key == 's')//keyboard control
		{
			y-=ySpeed ;
			PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
			charstand =true;
			chforward =false;
			backward =false;
			if(y<=0)
			{
				y=0;
			}
			else
			{
				for(int i=0;i<41;i++)
				{
					if(x+dextersWidth>barx[i] && x<barx[i]+barDx[i] && y+dextersHeigth>bary[i] && y<bary[i]+barDy[i])
					{
						y+=ySpeed;
						break;
					}
				}
				for(int i=0;i<5;i++)
				{
					if(x+dextersWidth>key1[i].kx && x<key1[i].kx+32 && y+dextersHeigth>key1[i].ky && y<key1[i].ky+32)
					{
						if(key1[i].state==1)
						{
							key1[i].state=0;//collect key
							PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
							disCnt++;
							totalscore += 50;
						}
					}
				}
				if(x+64>screenWidth-64 && x<=screenWidth && y+64>=0 && y<=screenHeight-724 && disCnt>=5)
				{
					gamestate=level2;//gateway to level 2
					PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);
					totalscore += 500;
					x=0;//reset after level up
					y=screenHeight-dextersHeigth-4;
					keyposSet();
					keyShow();
					enemyposSet();
				}
			}
		}
	}
}
