#include"levelone.h"
int back_image;

//x=screenWidth * (5.0/820.0);
//y=screenHeight * (260.0/510.0);
//int  xSpeed = 10;
//int ySpeed = 10;



int screen_width=screenWidth;
int screen_height=screenHeight;
double dex_x=screen_width * (5.0/820.0);
double dex_y=screen_height * (260.0/510.0);
double dx = 10;
double dy = 10;
int dexterwidth=64;
int dexterheight=64;
int k_gat=0;//variable for key
int enx2Speed=1;//enemy speed through x axis
int eny2Speed=1;
char backward2Run[7][20]={"RunB6.bmp","RunB5.bmp","RunB4.bmp","RunB3.bmp","RunB2.bmp","RunB1.bmp"};
char forkward2Run[5][20]={"RunF1.bmp","RunF2.bmp","RunF3.bmp","RunF4.bmp"};
bool char2stand = true,ch2forward=false,back2ward=false;
int stand2counter = 0;
int index2 = 0,time2counter=0;
long long time2remaining=60;
struct rectangel{//struct for showing rectangle bar in maze
	double rectpos_x;
	double rectpos_y;
    double rectwidth;
	double rectheight;

	

	rectangel(){
		
		;
	}
	rectangel(double x,double y,double w,double h){//constructor for stucture
		
		rectpos_x=x;
		rectpos_y=y;
		rectwidth=w;
		rectheight=h;
		

	}
	void valuerect(double x,double y,double w,double h){
		rectpos_x=x;
		rectpos_y=y;
		rectwidth=w;
		rectheight=h;

	}
	void drawrect(){
		iSetColor(99,172,180);
		iFilledRectangle(rectpos_x,rectpos_y,rectwidth,rectheight);
	}

}bar[100] ;//varible for bar


void puzzle()
{
  
	//maze bar
	bar[0] = rectangel(screenWidth * (10.0/820.0),screenHeight * (5.0/510.0),screenWidth * (800.0/820.0),screenHeight * (5.0/510.0)); 
	bar[0].drawrect();

	bar[1] = rectangel(screenWidth * (10.0/820.0),screenHeight * (5.0/510.0),screenWidth * (5.0/820.0),screenHeight * (250.0/510.0)); 
	bar[1].drawrect();
	
	bar[2] = rectangel(screenWidth * (10.0/820.0),screenHeight * (330.0/510.0),screenWidth * (5.0/820.0),screenHeight * (173.0/510.0)); 
	bar[2].drawrect();

	bar[3] = rectangel(screenWidth * (10.0/820.0),screenHeight * (500.0/510.0),screenWidth * (800.0/820.0),screenHeight * (5.0/510.0)); 
	bar[3].drawrect();

	
	bar[4] = rectangel(screenWidth * (810.0/820.0),screenHeight * (75.0/510.0),screenWidth * (5.0/820.0),screenHeight * (430.0/510.0)); 
	bar[4].drawrect();

	bar[5] = rectangel(screenWidth * (90.0/820.0),screenHeight * (75.0/510.0),screenWidth * (280.0/820.0),screenHeight * (5.0/510.0)); 
	bar[5].drawrect();

	bar[6] = rectangel(screenWidth * (290.0/820.0),screenHeight * (80.0/510.0),screenWidth * (5.0/820.0),screenHeight * (114.0/510.0)); 
	bar[6].drawrect();

	bar[7] = rectangel(screenWidth * (10.0/820.0),screenHeight * (145.0/510.0),screenWidth * (200.0/820.0),screenHeight * (5.0/510.0)); 
	bar[7].drawrect();

	bar[8] = rectangel(screenWidth * (210.0/820.0),screenHeight * (145.0/510.0),screenWidth * (5.0/820.0),screenHeight * (50.0/510.0)); 
	bar[8].drawrect();
	
	bar[9] = rectangel(screenWidth * (210.0/820.0),screenHeight * (193.0/510.0),screenWidth * (85.0/820.0),screenHeight * (5.0/510.0)); 
	bar[9].drawrect();

	bar[10] = rectangel(screenWidth * (10.0/820.0),screenHeight * (330.0/510.0),screenWidth * (210.0/820.0),screenHeight * (5.0/510.0)); 
	bar[10].drawrect();

	bar[11] = rectangel(screenWidth * (85.0/820.0),screenHeight * (210.0/510.0),screenWidth * (5.0/820.0),screenHeight * (120.0/510.0)); 
	bar[11].drawrect();

	bar[12] = rectangel(screenWidth * (85.0/820.0),screenHeight * (270.0/510.0),screenWidth * (300.0/820.0),screenHeight * (5.0/510.0)); 
	bar[12].drawrect();

	bar[13] = rectangel(screenWidth * (220.0/820.0),screenHeight * (330.0/510.0),screenWidth * (5.0/820.0),screenHeight * (50.0/510.0)); 
	bar[13].drawrect();

	bar[14] = rectangel(screenWidth * (380.0/820.0),screenHeight * (135.0/510.0),screenWidth * (5.0/820.0),screenHeight * (135.0/510.0)); 
	bar[14].drawrect();

	bar[15] = rectangel(screenWidth * (445.0/820.0),screenHeight * (75.0/510.0),screenWidth * (120.0/820.0),screenHeight * (5.0/510.0)); 
	bar[15].drawrect();

	
	bar[16] = rectangel(screenWidth * (445.0/820.0),screenHeight * (80.0/510.0),screenWidth * (5.0/820.0),screenHeight * (250.0/510.0)); 
	bar[16].drawrect();

	
    bar[17] = rectangel(screenWidth * (290.0/820.0),screenHeight * (330.0/510.0),screenWidth * (220.0/820.0),screenHeight * (5.0/510.0)); 
	bar[17].drawrect();

	bar[18] = rectangel(screenWidth * (290.0/820.0),screenHeight * (335.0/510.0),screenWidth * (5.0/820.0),screenHeight * (100.0/510.0)); 
	bar[18].drawrect();

	bar[19] = rectangel(screenWidth * (110.0/820.0),screenHeight * (435.0/510.0),screenWidth * (240.0/820.0),screenHeight * (5.0/510.0)); 
	bar[19].drawrect();

	bar[20] = rectangel(screenWidth * (110.0/820.0),screenHeight * (390.0/510.0),screenWidth * (5.0/820.0),screenHeight * (45.0/510.0)); 
	bar[20].drawrect();
	
	bar[21] = rectangel(screenWidth * (380.0/820.0),screenHeight * (135.0/510.0),screenWidth * (70.0/820.0),screenHeight * (5.0/510.0)); 
	bar[21].drawrect();
	
	bar[22] = rectangel(screenWidth * (580.0/820.0),screenHeight * (460.0/510.0),screenWidth * (5.0/820.0),screenHeight * (40.0/510.0)); 
	bar[22].drawrect();

	bar[23] = rectangel(screenWidth * (640.0/820.0),screenHeight * (5.0/510.0),screenWidth * (5.0/820.0),screenHeight * (135.0/510.0)); 
	bar[23].drawrect();

	bar[24] = rectangel(screenWidth * (525.0/820.0),screenHeight * (140.0/510.0),screenWidth * (120.0/820.0),screenHeight * (5.0/510.0)); 
	bar[24].drawrect();

	bar[25] = rectangel(screenWidth * (525.0/820.0),screenHeight * (140.0/510.0),screenWidth * (5.0/820.0),screenHeight * (120.0/510.0)); 
	bar[25].drawrect();

	bar[26] = rectangel(screenWidth * (525.0/820.0),screenHeight * (260.0/510.0),screenWidth * (130.0/820.0),screenHeight * (5.0/510.0)); 
	bar[26].drawrect();

	bar[27] = rectangel(screenWidth * (650.0/820.0),screenHeight * (220.0/510.0),screenWidth * (5.0/820.0),screenHeight * (220.0/510.0)); 
	bar[27].drawrect();

	bar[28] = rectangel(screenWidth * (390.0/820.0),screenHeight * (390.0/510.0),screenWidth * (265.0/820.0),screenHeight * (5.0/510.0)); 
	bar[28].drawrect();

    
	bar[29] = rectangel(screenWidth * (500.0/820.0),screenHeight * (390.0/510.0),screenWidth * (5.0/820.0),screenHeight * (50.0/510.0)); 
	bar[29].drawrect();

	bar[30] = rectangel(screenWidth * (575.0/820.0),screenHeight * (145.0/510.0),screenWidth * (5.0/820.0),screenHeight * (60.0/510.0)); 
	bar[30].drawrect();

	bar[31] = rectangel(screenWidth * (720.0/820.0),screenHeight * (5.0/510.0),screenWidth * (5.0/820.0),screenHeight * (425.0/510.0)); 
	bar[31].drawrect();

	bar[32] = rectangel(screenWidth * (775.0/820.0),screenHeight * (160.0/510.0),screenWidth * (35.0/820.0),screenHeight * (5.0/510.0)); 
	bar[32].drawrect();

	bar[33] = rectangel(screenWidth * (720.0/820.0),screenHeight * (80.0/510.0),screenWidth * (35.0/820.0),screenHeight * (5.0/510.0)); 
	bar[33].drawrect();

	bar[34] = rectangel(screenWidth * (720.0/820.0),screenHeight * (250.0/510.0),screenWidth * (35.0/820.0),screenHeight * (5.0/510.0)); 
	bar[34].drawrect();

	
	bar[35] = rectangel(screenWidth * (775.0/820.0),screenHeight * (330.0/510.0),screenWidth * (35.0/820.0),screenHeight * (5.0/510.0)); 
	bar[35].drawrect();

	
	bar[36] = rectangel(screenWidth * (720.0/820.0),screenHeight * (430.0/510.0),screenWidth * (20.0/820.0),screenHeight * (5.0/510.0)); 
	bar[36].drawrect();

	bar[37] = rectangel(screenWidth * (795.0/820.0),screenHeight * (430.0/510.0),screenWidth * (15.0/820.0),screenHeight * (5.0/510.0)); 
	bar[37].drawrect();

   
}
struct KEY//structure for keys
{
	int kx2,ky2,state2;
}key2[10];
//for setting the key positions of level2
void keypostionset()
{
	srand(time(0));
	for(int i=0;i<10;i++)
	{
		key2[i].kx2=rand()%1519;//random x-axis position of keys
		key2[i].ky2=rand()%757;//random y-axis position of keys
		key2[i].state2=1;//state 1 means key is visible
	}
}


void keyShow_level2()
{
	for(int i=0;i<10;i++)// 10 for 10 keys
	{
		if(key2[i].kx2+32<=dexterwidth && key2[i].kx2>=0 && key2[i].ky2>=screenHeight-dexterheight-4 && key2[i].ky2+32<=screenHeight)//check if key position in dexters initial position
		{
			key2[i].kx2=rand()%1519;//change the position
			key2[i].ky2=rand()%757;
		}
		if(key2[i].kx2+32<=screenWidth && key2[i].kx2>=1486 && key2[i].ky2>=0 && key2[i].ky2+32<=screenHeight-724)//check if key position in destination's initial position
		{
			key2[i].kx2=rand()%1519;//change the position
			key2[i].ky2=rand()%757;
		}
		if(key2[i].kx2+64>screenWidth)//check that if it is in the screen
		{
			key2[i].kx2=screenWidth-64;
		}
		if(key2[i].ky2+64>screenHeight)//check that if it is in the screen
		{
			key2[i].kx2=screenHeight-64;
		}
		for(int j=0;j<38;j++)//by loop check that the keys position overlap the bars position
		{
			if(key2[i].kx2+32>bar[j].rectpos_x && key2[i].kx2<bar[j].rectpos_x+bar[j].rectwidth && key2[i].ky2+32>bar[j].rectpos_y && key2[i].ky2<bar[j].rectpos_y+bar[j].rectheight)
			{
				key2[i].kx2=rand()%1519;
				key2[i].ky2=rand()%757;
				j=-1;
			}
		}
		if(key2[i].state2)//if key's state true show the image
		{
			iShowBMP2(key2[i].kx2,key2[i].ky2,"key.bmp",0);
		}
	}
}


struct ENEM_2//structure for enemy for level2
{
	int ex2,ey2,state2,dir2;
}enem_2[4];
void enemyposSet_LEVEL2()//setting enemy position
{
	for(int i=0;i<4;i++)
	{
		enem_2[i].ex2=rand()%1487;//random settings of enemy's x-axis position
		enem_2[i].ey2=rand()%724;
		enem_2[i].state2=1;
		enem_2[i].dir2=rand()%4;//random direction setting
	}
}


void enemyShow_level2()//showing enemy's
{
	for(int i=0;i<4;i++)
	{
		if(enem_2[i].ex2+64<=dexterwidth+100 && enem_2[i].ex2>=0 && enem_2[i].ey2>=screenHeight-dexterheight-4 && enem_2[i].ey2+64<=screenHeight)//check if the enemy's initial postion set in dexter's initial position then change the position in random place
		{
			enem_2[i].ex2=rand()%1487;
			enem_2[i].ey2=rand()%724;
		}
		if(enem_2[i].ex2+64<=1540 && enem_2[i].ex2>=1350 && enem_2[i].ey2>=0 && enem_2[i].ey2+64<=100)//check if the enemy's initial postion set in destination's initial position then change the position in random place
		{
			enem_2[i].ex2=rand()%1487;
			enem_2[i].ey2=rand()%724;
		}
		if(enem_2[i].ex2+64>screenWidth)//check that enemy is in the screen
		{
			enem_2[i].ex2=screenWidth-64;
			enem_2[i].dir2=rand()%4;
		}
		if(enem_2[i].ey2+64>screenHeight)//check that enemy is in the screen
		{
			enem_2[i].ey2=screenHeight-64;
			enem_2[i].dir2=rand()%4;
		}
		if(enem_2[i].ex2+64>=dex_x && enem_2[i].ex2<=dex_x+64 && enem_2[i].ey2+64>=dex_y && enem_2[i].ey2<=dex_y+64)//if enemy touch the dexter he lost
		{
			gamestate=lost;
			PlaySound("music\\gameover.wav", NULL, SND_ASYNC);
		    dex_x=screen_width * (5.0/820.0);
            dex_y=screen_height * (260.0/510.0);
			
			 keyShow_level2();
		
			keypostionset();//key postion function for level2
	//iSetTimer(150,movingEnemy_level2);
	enemyposSet_LEVEL2();
		}
		if(enem_2[i].ex2<0)//check that enemy is in the screen
		{
			enem_2[i].ex2=0;
			enem_2[i].dir2=rand()%4;
		}
		if(enem_2[i].ey2<0)//check that enemy is in the screen
		{
			enem_2[i].ey2=0;
			enem_2[i].dir2=rand()%4;
		}
		
		if(enem_2[i].state2)//
		{
			iShowBMP2(enem_2[i].ex2,enem_2[i].ey2,"enemy.bmp",0);
		}
	}
}
void movingEnemy_level2()//for enemy moving
{
	
	for(int i=0;i<5;i++)//loop for four enemy's
	{
		if(enem_2[i].dir2==0)//0 direction for right
		{
			enem_2[i].ex2+=enx2Speed;
		}
		else if(enem_2[i].dir2==1)//1 direction for left
		{
			enem_2[i].ex2-=enx2Speed;
		}
		else if(enem_2[i].dir2==2)//2 direction for up
		{
			enem_2[i].ey2+=eny2Speed;
		}
		else
		{
			enem_2[i].ey2-=eny2Speed;
		}
		/*if(enemy[i].ex+64<=screenWidth && enemy[i].ex>=1486 && enemy[i].ey>=0 && enemy[i].ey+64<=screenHeight-724)
		{
			enemy[i].ex;
			enemy[i].ey;
		}*/
		for(int j=0;j<38;j++)//for checking collision with bars
		{
			if(enem_2[i].ex2+64>bar[j].rectpos_x && enem_2[i].ex2<bar[j].rectpos_x+bar[j].rectwidth && enem_2[i].ey2+64>bar[j].rectpos_y && enem_2[i].ey2<bar[j].rectpos_y+bar[j].rectheight)
			{
				if(enem_2[i].dir2==0)//enemy direction
				{
					enem_2[i].ex2-=enx2Speed;
					enem_2[i].dir2=rand()%4;
					if(enem_2[i].dir2==0)
					{
						enem_2[i].dir2=rand()%5;
					}
					else if(enem_2[i].dir2==1)
					{
						enem_2[i].ex2-=enx2Speed;
					}
					else if(enem_2[i].dir2==2)
					{
						enem_2[i].ey2+=eny2Speed;
					}
					else
					{
						enem_2[i].ey2-=eny2Speed;
					}
				}
				else if(enem_2[i].dir2==1)//enemy direction
				{
					enem_2[i].ex2+=enx2Speed;
					enem_2[i].dir2=rand()%5;
					if(enem_2[i].dir2==0)
					{
						enem_2[i].ex2+=enx2Speed;
					}
					else if(enem_2[i].dir2==1)
					{
						enem_2[i].dir2=rand()%4;
					}
					else if(enem_2[i].dir2==2)
					{
						enem_2[i].ey2+=eny2Speed;
					}
					else
					{
						enem_2[i].ey2-=eny2Speed;
					}
				}
				else if(enem_2[i].dir2==2)
				{
					enem_2[i].ey2-=enx2Speed;
					enem_2[i].dir2=rand()%4;
					if(enem_2[i].dir2==0)
					{
						enem_2[i].ex2+=enx2Speed;
					}
					else if(enem_2[i].dir2==1)
					{
						enem_2[i].ex2-=enx2Speed;
					}
					else if(enem_2[i].dir2==2)
					{
						enem_2[i].dir2=rand()%4;
					}
					else
					{
						enem_2[i].ey2-=eny2Speed;
					}
				}
				else//enemy direction
				{
					enem_2[i].ey2+=enx2Speed;
					enem_2[i].dir2=rand()%5;
					if(enem_2[i].dir2==0)
					{
						enem_2[i].ex2+=enx2Speed;
					}
					else if(enem_2[i].dir2==1)
					{
						enem_2[i].ex2-=enx2Speed;
					}
					else if(enem_2[i].dir2==2)
					{
						enem_2[i].ey2+=eny2Speed;
					}
					else
					{
						enem_2[i].dir2=rand()%4;
					}
				}
				j=-1;
			}
		}
	}
}

void SpecialKeyBoardControl_Level2(unsigned char key)
	
	
{
	if(gamestate == 101)
	{
	
		if (key == GLUT_KEY_RIGHT)
	{			
			dex_x+=dx;
			PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
			stand2counter=0;
			index2++;
			ch2forward =true;
			char2stand=false;
			back2ward =false;
			if(index2>3)
			{
				index2=0;
			}
			if(dex_x>=screen_width-dexterwidth)
		{
			dex_x=screen_width-dexterwidth;
		}
			else{
				for(int i=0;i<38;i++)
			{
				if(dex_x+dexterwidth>bar[i].rectpos_x && dex_x<bar[i].rectpos_x+bar[i].rectwidth && dex_y+dexterheight>bar[i].rectpos_y && dex_y<bar[i].rectpos_y+bar[i].rectheight)
				{
					dex_x-=dx;
					break;
				}
			}
				for(int i=0;i<10;i++)
			{
				if(dex_x+dexterwidth>key2[i].kx2 && dex_x<key2[i].kx2+32 && dex_y+dexterheight>key2[i].ky2 && dex_y<key2[i].ky2+32)
				{
					if(key2[i].state2==1)
					{
						key2[i].state2=0;//collectkey
						PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
						k_gat++;
						totalscore += 50;
					}
				}
			}
			if(dex_x+64>screenWidth-64 && dex_x<=screenWidth && dex_y+64>=0 && dex_y<=screenHeight-724 && k_gat>=10)
			{
				gamestate=level3;//gateway to level 3
				PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);
				totalscore += 500;
				dex_x=screen_width * (5.0/820.0);//reset after level up
                dex_y=screen_height * (260.0/510.0);
			
				keyShow_level2();
		
				keypostionset();//key postion function for level2
				//iSetTimer(150,movingEnemy_level2);
				enemyposSet_LEVEL2();
			}
		}
	
	}
	 else if(key == GLUT_KEY_LEFT)
	{
			dex_x-=dx;
			PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
			index2++;
			stand2counter=0;
			ch2forward = false;
			char2stand=false;
			back2ward =true;
			if(index2>5)
			{
				index2=0;
			}
			if(dex_x<=0)
			{
				dex_x=0;
			}
			else
			{
				for(int i=0;i<38;i++)
				{
					if(dex_x+dexterwidth>bar[i].rectpos_x && dex_x<bar[i].rectpos_x+bar[i].rectwidth && dex_y+dexterheight>bar[i].rectpos_y && dex_y<bar[i].rectpos_y+bar[i].rectheight)
					{
						dex_x+=dx;
						break;
					}
				}
				for(int i=0;i<10;i++)
			{
				if(dex_x+dexterwidth>key2[i].kx2 && dex_x<key2[i].kx2+32 && dex_y+dexterheight>key2[i].ky2 && dex_y<key2[i].ky2+32)
				{
					if(key2[i].state2==1)
					{
						key2[i].state2=0;//collectkey
						PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
						k_gat++;
						totalscore += 50;
					}
				}
			}
			if(dex_x+64>screenWidth-64 && dex_x<=1486 && dex_y+64>=0 && dex_y<=screenHeight-710 && k_gat>=10)
			{
				gamestate=level3;//gateway to level 3
				PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);
				totalscore += 500;
				dex_x=screen_width * (5.0/820.0);//reset after level up
                dex_y=screen_height * (260.0/510.0);
			
				keyShow_level2();
		
				keypostionset();//key postion function for level2
				//iSetTimer(150,movingEnemy_level2);
				enemyposSet_LEVEL2();
			}
			}
	}
	else if(key ==  GLUT_KEY_UP)
	{
		dex_y+=dy ;
		PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
		char2stand =true;
		ch2forward =false;
		back2ward =false;
		if(dex_y>=screen_height-dexterheight)
		{
			dex_y=screen_height-dexterheight;
		}
		else
		{
			for(int i=0;i<38;i++)
			{
				if(dex_x+dexterwidth>bar[i].rectpos_x && dex_x<bar[i].rectpos_x+bar[i].rectwidth && dex_y+dexterheight>bar[i].rectpos_y && dex_y<bar[i].rectpos_y+bar[i].rectheight)
				{
					dex_y-=dy;
					break;
				}
			}
			for(int i=0;i<10;i++)
			{
				if(dex_x+dexterwidth>key2[i].kx2 && dex_x<key2[i].kx2+32 && dex_y+dexterheight>key2[i].ky2 && dex_y<key2[i].ky2+32)
				{
					if(key2[i].state2==1)
					{
						key2[i].state2=0;//collectkey
						PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
						k_gat++;
						totalscore += 50;
					}
				}
			}
			if(dex_x+64>screenWidth-64 && dex_x<=screenWidth && dex_y+64>=0 && dex_y<=screenHeight-724 && k_gat>=10)
			{
				gamestate=level3;//gateway to level 3
				PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);
				totalscore += 500;
				dex_x=screen_width * (5.0/820.0);//reset after level up
                dex_y=screen_height * (260.0/510.0);
			
				keyShow_level2();
		
				keypostionset();//key postion function for level2
				//iSetTimer(150,movingEnemy_level2);
				enemyposSet_LEVEL2();
			}
		}
 }

 else if(key == GLUT_KEY_DOWN)
	{
		dex_y-=dy;
		PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
		char2stand =true;
		ch2forward =false;
		back2ward =false;
		if(dex_y<=0)
		{
			dex_y=0;
		}
		else
		{
			for(int i=0;i<38;i++)
			{
				if(dex_x+dexterwidth>bar[i].rectpos_x && dex_x<bar[i].rectpos_x+bar[i].rectwidth && dex_y+dexterheight>bar[i].rectpos_y && dex_y<bar[i].rectpos_y+bar[i].rectheight)
				{
					dex_y+=dy;
					break;
				}
			}
			for(int i=0;i<10;i++)
			{
				if(dex_x+dexterwidth>key2[i].kx2 && dex_x<key2[i].kx2+32 && dex_y+dexterheight>key2[i].ky2 && dex_y<key2[i].ky2+32)
				{
					if(key2[i].state2==1)
					{
						key2[i].state2=0;//collectkey
						PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
						k_gat++;
						totalscore += 50;
					}
				}
			}
			if(dex_x+64>screenWidth-64 && dex_x<=screenWidth && dex_y+64>=0 && dex_y<=screenHeight-724 && k_gat>=10)
			{
				gamestate=level3;//gateway to level 3
				PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);
				totalscore += 500;
				dex_x=screen_width * (5.0/820.0);//reset after level up
                dex_y=screen_height * (260.0/510.0);
			
				keyShow_level2();
		
				keypostionset();//key postion function for level2
				//iSetTimer(150,movingEnemy_level2);
				enemyposSet_LEVEL2();
			}
		}
	}

  }



}



void iKeyBordControl_Level2(unsigned char key)
	
	
{
	if(gamestate == 101)
	{
	
		if (key == 'd')
	{			
			dex_x+=dx;
			PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
			stand2counter=0;
			index2++;
			ch2forward =true;
			char2stand=false;
			back2ward =false;
			if(index2>3)
			{
				index2=0;
			}
			if(dex_x>=screen_width-dexterwidth)
		{
			dex_x=screen_width-dexterwidth;
		}
			else{
				for(int i=0;i<38;i++)
			{
				if(dex_x+dexterwidth>bar[i].rectpos_x && dex_x<bar[i].rectpos_x+bar[i].rectwidth && dex_y+dexterheight>bar[i].rectpos_y && dex_y<bar[i].rectpos_y+bar[i].rectheight)
				{
					dex_x-=dx;
					break;
				}
			}
				for(int i=0;i<10;i++)
			{
				if(dex_x+dexterwidth>key2[i].kx2 && dex_x<key2[i].kx2+32 && dex_y+dexterheight>key2[i].ky2 && dex_y<key2[i].ky2+32)
				{
					if(key2[i].state2==1)
					{
						key2[i].state2=0;//collectkey
						PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
						k_gat++;
						totalscore += 50;
					}
				}
			}
			if(dex_x+64>screenWidth-64 && dex_x<=screenWidth && dex_y+64>=0 && dex_y<=screenHeight-724 && k_gat>=10)
			{
				gamestate=level3;//gateway to level 3
				PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);
				totalscore += 500;
				dex_x=screen_width * (5.0/820.0);//reset after level up
                dex_y=screen_height * (260.0/510.0);
			
				keyShow_level2();
		
				keypostionset();//key postion function for level2
				//iSetTimer(150,movingEnemy_level2);
				enemyposSet_LEVEL2();
			}
		}
	
	}
	 else if(key == 'a')
	{
			dex_x-=dx;
			PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
			index2++;
			stand2counter=0;
			ch2forward = false;
			char2stand=false;
			back2ward =true;
			if(index2>5)
			{
				index2=0;
			}
			if(dex_x<=0)
			{
				dex_x=0;
			}
			else
			{
				for(int i=0;i<38;i++)
				{
					if(dex_x+dexterwidth>bar[i].rectpos_x && dex_x<bar[i].rectpos_x+bar[i].rectwidth && dex_y+dexterheight>bar[i].rectpos_y && dex_y<bar[i].rectpos_y+bar[i].rectheight)
					{
						dex_x+=dx;
						break;
					}
				}
				for(int i=0;i<10;i++)
			{
				if(dex_x+dexterwidth>key2[i].kx2 && dex_x<key2[i].kx2+32 && dex_y+dexterheight>key2[i].ky2 && dex_y<key2[i].ky2+32)
				{
					if(key2[i].state2==1)
					{
						key2[i].state2=0;//collect key
						PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
						k_gat++;
						totalscore += 50;
					}
				}
			}
			if(dex_x+64>screenWidth-64 && dex_x<=1486 && dex_y+64>=0 && dex_y<=screenHeight-710 && k_gat>=10)
			{
				gamestate=level3;//gateway to level 3
				PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);
				totalscore += 500;
				dex_x=screen_width * (5.0/820.0);//reset after level up
                dex_y=screen_height * (260.0/510.0);
			
				keyShow_level2();
		
				keypostionset();//key postion function for level2
				//iSetTimer(150,movingEnemy_level2);
				enemyposSet_LEVEL2();
			}
			}
	}
	else if(key ==  'w')
	{
		dex_y+=dy ;
		PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
		char2stand =true;
		ch2forward =false;
		back2ward =false;
		if(dex_y>=screen_height-dexterheight)
		{
			dex_y=screen_height-dexterheight;
		}
		else
		{
			for(int i=0;i<38;i++)
			{
				if(dex_x+dexterwidth>bar[i].rectpos_x && dex_x<bar[i].rectpos_x+bar[i].rectwidth && dex_y+dexterheight>bar[i].rectpos_y && dex_y<bar[i].rectpos_y+bar[i].rectheight)
				{
					dex_y-=dy;
					break;
				}
			}
			for(int i=0;i<10;i++)
			{
				if(dex_x+dexterwidth>key2[i].kx2 && dex_x<key2[i].kx2+32 && dex_y+dexterheight>key2[i].ky2 && dex_y<key2[i].ky2+32)
				{
					if(key2[i].state2==1)
					{
						key2[i].state2=0;//collect key
						PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
						k_gat++;
						totalscore += 50;
					}
				}
			}
			if(dex_x+64>screenWidth-64 && dex_x<=screenWidth && dex_y+64>=0 && dex_y<=screenHeight-724 && k_gat>=10)
			{
				gamestate=level3;//gateway to level 3
				PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);
				totalscore += 500;
				dex_x=screen_width * (5.0/820.0);//reset after level up
                dex_y=screen_height * (260.0/510.0);
			
				keyShow_level2();
		
				keypostionset();//key postion function for level2
				//iSetTimer(150,movingEnemy_level2);
				enemyposSet_LEVEL2();
			}
		}
 }

 else if(key == 's')
	{
		dex_y-=dy;
		PlaySound("music\\keyboard.wav", NULL, SND_ASYNC);
		char2stand =true;
		ch2forward =false;
		back2ward =false;
		if(dex_y<=0)
		{
			dex_y=0;
		}
		else
		{
			for(int i=0;i<38;i++)
			{
				if(dex_x+dexterwidth>bar[i].rectpos_x && dex_x<bar[i].rectpos_x+bar[i].rectwidth && dex_y+dexterheight>bar[i].rectpos_y && dex_y<bar[i].rectpos_y+bar[i].rectheight)
				{
					dex_y+=dy;
					break;
				}
			}
			for(int i=0;i<10;i++)
			{
				if(dex_x+dexterwidth>key2[i].kx2 && dex_x<key2[i].kx2+32 && dex_y+dexterheight>key2[i].ky2 && dex_y<key2[i].ky2+32)
				{
					if(key2[i].state2==1)
					{
						key2[i].state2=0;//collect key
						PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
						k_gat++;
						totalscore += 50;
					}
				}
			}
			if(dex_x+64>screenWidth-64 && dex_x<=screenWidth && dex_y+64>=0 && dex_y<=screenHeight-724 && k_gat>=10)
			{
				gamestate=level3;//gateway to level 3
				PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);
				totalscore += 500;
				dex_x=screen_width * (5.0/820.0);//reset after level up
                dex_y=screen_height * (260.0/510.0);
			
				keyShow_level2();
		
				keypostionset();//key postion function for level2
				//iSetTimer(150,movingEnemy_level2);
				enemyposSet_LEVEL2();
			}
		}
	}

  }



}




