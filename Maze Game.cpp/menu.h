# include "bitmap_viewer.h"

void menu1()
{
	if(gamestate == intro)//menu options
	{
		iClear();
		iShowBMPAlternative(0,0,"introone.bmp");
	}
	if(gamestate == menu)
	{
		iClear();
		iShowBMPAlternative(0,0,"menulast.bmp");
	}
	if(gamestate == hall_of_fame)
	{
		iClear();
		iShowBMPAlternative(0,0,"halloffamelast.bmp");
		char serial[10];
		for(int i = counter - 1;i >= 0  ; i--)
		{
			//show score
			itoa(sortArray[i],ScoreShow[i - counter],10);
			itoa(i + 1,serial,10);
			iText(600 ,500 - (i*100),serial,GLUT_BITMAP_TIMES_ROMAN_24);
			iText(800 ,500 - (i*100),ScoreShow[i - counter],GLUT_BITMAP_TIMES_ROMAN_24);
		}

		//printf("%s\n",ScoreShow[counter-2]);
	}
	if(gamestate == instruction)
	{
		iClear();
		iShowBMPAlternative(0,0,"instructionslast.bmp");
	}
	if(gamestate == about)
	{
		iClear();
		iShowBMPAlternative(0,0,"aboutlast.bmp");
	}
	
	
	
}
void menubutton(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(gamestate == intro)//mouse click select
		{
			if(mx>=684 && mx<=873 && my>=190 && my<=280)
			{
				gamestate=menu;
				PlaySound("music\\menubgm.wav", NULL, SND_ASYNC);
			}
			
		}
		else if(gamestate == menu)//mouse click select
		{
			if(mx>=128 && mx<=458 && my>=527 && my<=627)
			{
				gamestate=level1;
				PlaySound("music\\menuoption.wav", NULL, SND_ASYNC);


			}
			if(mx>=128 && mx<=458 && my>=417 && my<=517)//mouse click select
			{
				gamestate=hall_of_fame;
				// main_halloffame();
					counter = 0;
					FILE *file3 = fopen("File//Score.txt","r");
					while(!feof(file3))
					{
						fscanf(file3,"%d", &sortArray[counter]);
						if(sortArray[counter] != 0)
							counter++;
					}
					fclose(file3);
				PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
				
					
			}
			if(mx>=128 && mx<=458 && my>=301 && my<=401)//mouse click select
			{
				gamestate=instruction;
				PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
			}
			if(mx>=128 && mx<=458 && my>=185 && my<=285)//mouse click select
			{
				gamestate=about;
				PlaySound("music\\collectkey.wav", NULL, SND_ASYNC);
			}
			if(mx>=128 && mx<=458 && my>=64 && my<=164)//mouse click select
			{
				exit(0);
			}
		}
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}