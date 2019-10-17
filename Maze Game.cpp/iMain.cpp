/*
    Author: Tasnid Mahin, Dip Chowdhury, Shams-Al-Ahsan.
    Version: 2.0
*/



# include <iostream>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include <algorithm>
# include "iGraphics.h"
# include "levelthree.h"
using namespace std;
int BackGroundImag_Load[3];
char BackGroundImage[3][50] = {

				"backlastone.jpg","backlasttwo.jpg", "backlasttwo.jpg"
};
int finalscore;

void iDraw()
{
	//place your drawing codes here
	menu1();//call menu
	if(gamestate == level1)
	{
		iClear();
		iShowImage(0,0,screenWidth,screenHeight,BackGroundImag_Load[0]);
		drawbars();
		iShowBMP2(1486,0, "destinationlast.bmp",0);	
	
		movingEnemy();
		keyShow();
		enemyShow();
		if(!charstand)//character render
		{
			if(chforward ==true)
			{
				iShowBMP2(x,y,forkwardRun[index],0);
			}
			else if(backward == true)
			{
				iShowBMP2(x,y,backwardRun[index],0);
			}
			standcounter++;
			if(standcounter>30)
			{
				charstand = true;
				chforward =true;
				backward =true;
			}
		}
		else
		{
			iShowBMP2(x,y,"dex1.bmp",0);
		}	
	}
	if(gamestate==level2)
	{
		iClear();
		iShowImage(0,0,screenWidth,screenHeight,BackGroundImag_Load[2]);
		puzzle();
		iShowBMP2(1486,0, "destinationlast.bmp",0);
		
		movingEnemy_level2();
		keyShow_level2();
		enemyShow_level2();
		if(!char2stand)//character render
		{
			if(ch2forward ==true)
			{
				iShowBMP2(dex_x,dex_y,forkward2Run[index2],0);
			}
			else if(back2ward == true)
			{
				iShowBMP2(dex_x,dex_y,backward2Run[index2],0);
			}
			stand2counter++;
			if(stand2counter>30)
			{
				char2stand = true;
				ch2forward =true;
				back2ward =true;
			}
		}
		else
		{
			iShowBMP2(dex_x,dex_y,"dex1.bmp",0);
		}
	}
	if(gamestate==level3)
	{
		iClear();
		iShowImage(0,0,screenWidth,screenHeight,BackGroundImag_Load[1]);
		draw3bars();
		iShowBMP2(1486,0, "destinationlast.bmp",0);
	
		gem3Show();
		henemy3Show();
		moving3Enemy();
		if(!char3stand)//character render
		{
			if(ch3forward ==true)
			{
				iShowBMP2(x3,y3,forkward3Run[index3],0);
			}
			else if(back3ward == true)
			{
				iShowBMP2(x3,y3,backward3Run[index3],0);
			}
			stand3counter++;
			if(stand3counter>30)
			{
				char3stand = true;
				ch3forward =true;
				back3ward =true;
			}
		}
		else
		{
			iShowBMP2(x3,y3,"dex1.bmp",0);
		}
	}
	if(gamestate==lost)
	{
		iClear();
		int totalsecond=sec+(minit*60);
		score=totalscore-totalsecond;
		char ScoreShowGameOver[10];
		itoa(score,ScoreShowGameOver,10);
		iShowBMPAlternative(0,0,"lostlast.bmp");
		iSetColor(153,0,0);

	if(score>0){
		iFilledRectangle(730,300,200,80);
		iSetColor(255,255,255);
		iText(780,350,"Your Score",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(820,320,ScoreShowGameOver,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(score<=0){
		
		iFilledRectangle(730,300,200,80);
		iSetColor(255,255,255);
		iText(780,350,"Your Score",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(820,320,"0",GLUT_BITMAP_TIMES_ROMAN_24);
	
	}
		
	}
	if(gamestate==finish)
	{
		iClear();
		int totalsecond=sec+(minit*60);
		score=totalscore-totalsecond;
		char ScoreShowGameOver[10];
		itoa(score,ScoreShowGameOver,10);
		iShowBMPAlternative(0,0,"finish.bmp");
		
		if(score>0){
			iSetColor(0,255,0);
			iText(780,350,"Your Score",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(820,320,ScoreShowGameOver,GLUT_BITMAP_TIMES_ROMAN_24);
			iText(780,350,"Your Score",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(820,320,ScoreShowGameOver,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if(score<=0){
		
			iSetColor(0,255,0);
			iText(780,350,"Your Score",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(820,320,ScoreShowGameOver,GLUT_BITMAP_TIMES_ROMAN_24);
			iText(770,350,"Your Score",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(810,320,"0",GLUT_BITMAP_TIMES_ROMAN_24);
		}		
	}
	
	timedraw();//show time and score
}


void iMouseMove(int mx, int my)
{
	//place your codes here
}


void iMouse(int button, int state, int mx, int my)
{
	menubutton(button,state, mx,my);
}


void iPassiveMouseMove(int mx,int my)
{
	//place your code here
	 mposx = mx;
	 mposy = my;
	 if(mx== 2){}        /*Something to do with mx*/
	 else if(my== 2){}   /*Something to do with my*/

}
 

void iKeyboard(unsigned char key)
{
	//gamestate operation & navigation
	if(gamestate == hall_of_fame || gamestate == instruction || gamestate == about || gamestate == level1 || gamestate == level2 || gamestate==level3 || gamestate==lost || gamestate==menu || gamestate==finish)
	{
		if(key == '\b')
		{

			if(gamestate == lost || gamestate == finish)
			{
		//file operation
				iSetColor(0,250,0);
				int totalsecond=sec+(minit*60);
				score=totalscore-totalsecond;
				//score
				if(score>0){
					counter = 0;
					FILE *file3 = fopen("File//Score.txt","r");
					while(!feof(file3))
					{
						fscanf(file3," %d", &sortArray[counter]);
						if(sortArray[counter] != 0)
						counter++;
					} //high score sort
					fclose(file3);
					if(sortArray[counter-1] <= score)//high score sort
					{
						sortArray[counter -1] = score;
					}
					std::sort(sortArray , sortArray + counter );
					file3 = fopen("File/Score.txt","w");
					for(int i = counter - 1;i >= 0  ; i--)
					{
						fprintf(file3,"%d ",sortArray[i]);
					}
					fclose(file3);
				}
		
		}

			minit=0;
			sec=0;
			totalscore=0;
			score = 0;
			gamestate = menu;
			PlaySound("music\\menubgm.wav", NULL, SND_ASYNC);
		}
		else if(key == '2')
		{
			gamestate=level2;
			PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);
		}
		else if(key == '3')
		{
			gamestate=level3;
			PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);
		}

	}
	
	if(gamestate == level2)
	{
		iKeyBordControl_Level2(key);
	}
	if(gamestate == level1)
	{
		iKeyBordControl_Level1(key);
	}
	if(gamestate == level3)
	{
		iKeyBordControl_Level3(key);
	}
	
}


void iSpecialKeyboard(unsigned char key)
{

	
	if(gamestate == level1){//key control function call

		 SpecialKeyBoardControl_Level1( key);
	}
	else if(gamestate == level2){

		 SpecialKeyBoardControl_Level2( key);
	}
	else if(gamestate == level3){

		 SpecialKeyBoardControl_Level3( key);
	}
	

}


int main()
{

	main_halloffame();//function called from header file
	iSetTimer(1000,timecontol);	
	keyposSet();
	enemyposSet();
	
	keypostionset();//key postion function for level2
	enemyposSet_LEVEL2();
	
	keypos3Set();
	enemypos3Set();

	iInitialize(screenWidth, screenHeight, "Dexters' Laboratory");

	PlaySound("music\\gameopen.wav", NULL, SND_ASYNC);
	BackGroundImag_Load[0] = iLoadImage(BackGroundImage[0]);//jpg image load
	BackGroundImag_Load[1] = iLoadImage(BackGroundImage[1]);
	BackGroundImag_Load[2] = iLoadImage(BackGroundImage[2]);

	iStart();
	return 0;
}
