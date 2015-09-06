


               /**************************************************************************
                *                       Project:Level-1,Term-2                           *
                *	                      Game name: Pacman                              *
                *	                Created By MD HABIBULLAH BIN ISMAIL                  *
                **************************************************************************/

# include "iGraphics.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<shellapi.h>
#include"stracture.h"

#define INFINITY INT_MAX
#define MAX_VERTEX 205
#define BLACK 1
#define GRAY 2
#define SEED 012345
#define HEIGHT 672
#define WIDTH 300

user player_cur,player[10];
sp spfood,death,dolar,life;
enm enm1,enm2,enm3,enm4;

FILE *fscore,*fedge,*fmaze;

char str[1000],username[40];
short int live_point=5;
long int point=0,point_level=0;
int rand_gen,name_count,name_len,welcome=0;
int level1_timer,level2_timer,level3_timer;
int pic_x1,pic_y1,display=-1;
int inc,t,pac_timer,sp_timer;
int food_flag,over,score_flag;
int pac_node[21][21],level=0,level_copelete=0;
int vertices;
int enem_control_timer,enem_control,enem_eye;
int enm_flag1,enm_flag2;
int edge[3][205][205];
int alevel[3][21][21];
int total[3][21][21];

void pacman_initial()                  //pacman initialize
{
	int i,j,count=1;
	pacn.move=0;
	pacn.rotate=0;
	if(level==0)
	{
    	pacn.len=1;
    	pacn.lin=19;

    	pacn.x=pic_x1-48+pacn.len*32;
	    pacn.y=pic_y1+144-pacn.lin*32;

    	vertices=204;
	}
	else if(level==1)
	{
		pacn.len=19;
	    pacn.lin=14;

	    pacn.x=pic_x1-48+pacn.len*32;
	    pacn.y=pic_y1+144-pacn.lin*32;

	    vertices=183;
	}
	else if(level==2)
	{
		pacn.len=2;
	    pacn.lin=19;

	    pacn.x=pic_x1-48+pacn.len*32;
	    pacn.y=pic_y1+144-pacn.lin*32;

	    vertices=201;
	}

	pacn.mode1=0;
	pacn.mode2=0;
	pacn.count1=0;
	pacn.count2=0;

	pacn.dx=8;
	pacn.dy=8;
	inc=8;

	enem_control_timer=0;
	enem_control=0;
	enem_eye=0;

	enm_flag1=1;
	enm_flag2=1;
	score_flag=0;

	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
			if(alevel[level][i][j]==1)
			{
				pac_node[i][j]=0;
			}
			if(alevel[level][i][j]==0)
			{

				pac_node[i][j]=count;
				count++;
				if(level==0)
				{
				if(i==7 && j>=0 && j<=3)
				{
					pac_node[i][j]=0;
					count--;
				}
				if(i==7 && j>=17 && j<=20)
				{
					pac_node[i][j]=0;
					count--;
				}
				if(i==11 && j>=0 && j<=3)
				{
					pac_node[i][j]=0;
					count--;
				}
				if(i==11 && j>=17 && j<=20)
				{
					pac_node[i][j]=0;
					count--;
				}
				}
			}
		}
	}
}

void emeny1_initial()                    //emeny1 initialize
{
	if(level==0)
	{
		enm1.elen=13;
	    enm1.elin=7;
	}
	else if(level==1)
	{
		enm1.elen=5;
	    enm1.elin=1;
	}
	else if(level==2)
	{
		enm1.elen=18;
	    enm1.elin=1;
	}
	enm1.edx=8;
	enm1.edy=8;
	enm1.enm_x=pic_x1-48+enm1.elen*32;
	enm1.enm_y=pic_y1+144-enm1.elin*32;
	enm1.pac_enm=1;
	enm1.flag=1;
    enm1.emode1=0;
    enm1.emode2=0;
	enm1.ecount1=0;
    enm1.ecount2=0;
	enm1.count=0;
	enm1.eye=0;
	enm1.eyeflag=0;
}

void emeny2_initial()                             //enemy2 initialize
{
	if(level==0)
	{
		enm2.elen=7;
	    enm2.elin=7;
	}
	else if(level==1)
	{
		enm2.elen=19;
	    enm2.elin=6;
	}
	else if(level==2)
	{
		enm2.elen=6;
	    enm2.elin=12;
	}
	enm2.edx=8;
	enm2.edy=8;
	enm2.enm_x=pic_x1-48+enm2.elen*32;
	enm2.enm_y=pic_y1+144-enm2.elin*32;
	enm2.count=0;
	enm2.flag=1;
	enm2.emode1=0;
    enm2.emode2=0;
	enm2.ecount1=0;
    enm2.ecount2=0;
	enm2.count=0;
    enm2.eye=0;
	enm2.eyeflag=0;
}

void emeny3_initial()                         //enemy2 initialize
{
	int i,j,count=1;

	if(level==0)
	{
		enm3.elen=18;
	    enm3.elin=1;
	}
	else if(level==1)
	{
		enm3.elen=10;
	    enm3.elin=10;
	}
	else if(level==2)
	{
		enm3.elen=10;
	    enm3.elin=10;
	}
	enm3.edx=8;
	enm3.edy=8;
	enm3.enm_x=pic_x1-48+enm3.elen*32;
	enm3.enm_y=pic_y1+144-enm3.elin*32;
	enm3.count=0;
    enm3.flag=1;
	enm3.emode1=0;
    enm3.emode2=0;
	enm3.ecount1=0;
    enm3.ecount2=0;
	enm3.count=0;
	enm3.eye=0;
	enm3.eyeflag=0;

	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
			if(alevel[level][i][j]==1)
			{
				enm3.node[i][j]=0;
			}
			if(alevel[level][i][j]==0)
			{

				enm3.node[i][j]=count;
				count++;
				if(level==0)
				{
				if(i==7 && j>=0 && j<=3)
				{
					enm3.node[i][j]=0;
					count--;
				}
				if(i==7 && j>=17 && j<=20)
				{
					enm3.node[i][j]=0;
					count--;
				}
				if(i==11 && j>=0 && j<=3)
				{
					enm3.node[i][j]=0;
					count--;
				}
				if(i==11 && j>=17 && j<=20)
				{
					enm3.node[i][j]=0;
					count--;
				}
				}
			}
		}
	}
}

void emeny4_initial()                        //enemy2 initialize
{
	if(level==0)
	{
		enm4.elen=1;
	    enm4.elin=1;
	}
	else if(level==1)
	{
		enm4.elen=1;
	    enm4.elin=14;
	}
	else if(level==2)
	{
		enm4.elen=6;
	    enm4.elin=1;
	}
	enm4.edx=8;
	enm4.edy=8;
	enm4.enm_x=pic_x1-48+enm4.elen*32;
	enm4.enm_y=pic_y1+144-enm4.elin*32;
	enm4.count=0;
	enm4.flag=1;
	enm4.emode1=0;
    enm4.emode2=0;
	enm4.ecount1=0;
    enm4.ecount2=0;
	enm4.count=0;
	enm4.eye=0;
	enm4.eyeflag=0;
}

void special_food_initial()                 //special food initialize
{
	spfood.count=0;
    spfood.flag=1;
	life.count=0;
    life.flag=1;
	death.count=0;
    death.flag=1;
	dolar.count=0;
    dolar.flag=1;
}

void total_initial()                         //all initialize function in one function
{
	pacman_initial();
	emeny1_initial();
	emeny2_initial();
	emeny3_initial();
	emeny4_initial();
	special_food_initial();
}

void Pause_timer()                               //pause function for all timer
{
     	iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		iPauseTimer(3);
}
void Resume_timer()                         //resume function for all timer
{
     	iResumeTimer(0);
		if(level==0) iResumeTimer(1);
		else if(level==1) iResumeTimer(2);
		else if(level==2) iResumeTimer(3);
}

void initial_timer()                          //initial value  for all timer
{
		pac_timer=150;
		level1_timer=200;
		level2_timer=150;
		level3_timer=100;
}

void score_show()                                 //high score show function
{
   int i,size;

		if((fscore=fopen("highscore.dat","rb"))!=NULL)
		{
			fseek(fscore,0,SEEK_END);
	    	size=ftell(fscore);
	    	name_count=size/sizeof(user);
	    	rewind(fscore);

			fseek(fscore,1*sizeof(user),SEEK_SET);

		    for(i=0;i<=name_count;i++)
			 {
	       	    fread(&player[i],sizeof(user),1,fscore);
		     	printf("\n%s :%d\n",player[i].name,player[i].score);
			}

    		fclose(fscore);
		}
		
    iShowBMP(200,50,"pictures/BACGROUND.bmp");
	iShowBMP(480,450,"pictures/high.bmp");

	for(i=2;i<=name_count;i++)
	{
    iSetColor(25,105,255);
	iText(555,450-30*i,player[name_count-i].name,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(556,450-30*i,player[name_count-i].name,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(557,450-30*i,player[name_count-i].name,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(555,451-30*i,player[name_count-i].name,GLUT_BITMAP_TIMES_ROMAN_24);

	itoa(player[name_count-i].score,str,10);

	iText(755,450-30*i,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(756,450-30*i,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(757,450-30*i,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(755,451-30*i,str,GLUT_BITMAP_TIMES_ROMAN_24);
	}	
}

void  high_score()                                 //high score function after game over
{
	int size,count=0,i=0,k=0;

	    if((fscore=fopen("highscore.dat","rb"))==NULL)
		{
		   fscore=fopen("highscore.dat","wb");
		}
		
		fseek(fscore,0,SEEK_END);
		size=ftell(fscore);
		count=size/sizeof(user);
		rewind(fscore);

		if(count==11) name_count=count;
		else name_count=count+1;

		printf("\n\n%d\n\n",count);

        if(count!=0)
		{
			if(count==11)
			{
				 fseek(fscore,1*sizeof(user),SEEK_SET);

				 for(i=0;i<count-1;i++)
				 {
	        	    fread(&player[i],sizeof(user),1,fscore);
			     	printf("\n%s :%d\n",player[i].name,player[i].score);
				 }
    			fclose(fscore);
				
				count=count-1;
				k=count-1;

			    while((player_cur.score<player[k].score) && k>=0)
				{
				    player[k+1].score=player[k].score;
					strcpy(player[k+1].name,player[k].name);
					k--;
				}

		     	player[k+1].score=player_cur.score;
                strcpy(player[k+1].name,player_cur.name);
			}
			else if(count!=11)
			{
				for(i=0;i<count;i++)
				 {
	        	    fread(&player[i],sizeof(user),1,fscore);
				 }

    			fclose(fscore);
				
				k=count-1;
			    while((player_cur.score<player[k].score) && k>=0)
				{
				    player[k+1].score=player[k].score;
					strcpy(player[k+1].name,player[k].name);
					k--;
				}

		     	player[k+1].score=player_cur.score;
                strcpy(player[k+1].name,player_cur.name);
			}
		}
		  player_cur.score=0;
		  point=0;

		  fscore=fopen("highscore.dat","wb");

		  for(i=0;i<name_count;i++)
		  {
	            fwrite(&player[i],sizeof(user),1,fscore);
				player_cur.score=0;
		  }
		  fclose(fscore);
}

void game_over()                   //game over condition function
{
	if(live_point==0)
	{
	   level_copelete=7;
	   player_cur.score=point;
	   Pause_timer();
	   high_score();
	}
	else if(live_point!=0 && level==2 && point_level==201)
	{
	    player_cur.score=point;
	    Pause_timer();
		high_score();
	    display=3;
	}
}
void   level_ok()                  // level complete show function
{
	if(level_copelete==1 || level_copelete==3 || level_copelete==5)
	{
		iShowBMP(400,200,"pictures/levelcomplete.bmp");

			if(welcome%4==0) iSetColor(255,255,0);
		else iSetColor(2,0,255);

		iText(pic_x1+140,pic_y1-400,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+141,pic_y1-400,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+142,pic_y1-400,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+143,pic_y1-400,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		
		PlaySound("sounds/game_over.wav",NULL,SND_ASYNC);
	}
	if(level_copelete==7)
	{
		iShowBMP(400,200,"pictures/lifelost.bmp");

			if(welcome%4==0) iSetColor(255,255,0);
		else iSetColor(2,0,255);

		iText(pic_x1+140,pic_y1-400,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+141,pic_y1-400,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+142,pic_y1-400,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+143,pic_y1-400,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);

		PlaySound("sounds/magnet.wav",NULL,SND_ASYNC);

	}

}


void level_initial()               //level complete condition function
{
	if(point_level==204 && level==0)
	{
		point_level=0;
		level=1;
		level_copelete=1;
		Pause_timer();
	}
	else if(point_level==183 && level==1)
	{
		point_level=0;
		level=2;
		level_copelete=3;
		Pause_timer();
	}
	else if(point_level==201 && level==2)
	{
		level_copelete=5;
	}
	else if(level_copelete==6)
	{
		total_initial();
	    game_over();
		point_level=0;
	}
}

void start_display1()             //starting display  No.1
{
	iShowBMP(150,50,"pictures/PACMAN.bmp");  

	if(welcome%4==0) iSetColor(255,255,0);
		else iSetColor(2,0,255);

		iText(pic_x1+140,pic_y1,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+141,pic_y1,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+142,pic_y1,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+143,pic_y1,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
}

void press_any_key(char num)                           // press any key function
{
	int i;
	for(i=32;i<=127;i++)
	{
		if(num==i)
		{
			if(display==0) display=1;
			if(display==2) display=1;
		}
	}
}

void start_display2()                                  //starting display no.2
{
	if(welcome>16 && welcome<32 || welcome>48 && welcome<64) iShowBMP(pic_x1-100,pic_y1-100,"pictures/pacman1.bmp");
    else iShowBMP(pic_x1-100,pic_y1-100,"pictures/PACMAN001.bmp");
	iShowBMP(pic_x1+100,pic_y1-150,"pictures/pacman5.bmp");
	iShowBMP(pic_x1+100,pic_y1-200,"pictures/pacman6.bmp");
	iShowBMP(pic_x1+100,pic_y1-250,"pictures/pacman7.bmp");
	iShowBMP(pic_x1+100,pic_y1-300,"pictures/pacman8.bmp");
	iShowBMP(pic_x1+100,pic_y1-350,"pictures/pacman9.bmp");
}

void level_1()                                        //Level-1 creation function
{
	int i=0,j=0;
	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
            if (alevel[level][i][j]==1)
			{
                iShowBMP(pic_x1-48+j*32,pic_y1+144-i*32,"pictures/pacman10.bmp");
			}
		}
	}
}

int rand_generator()                       //Random number generator function
{
	float x;
	int n;

	x=rand()/32768.0;
	n=1+(int)(4*x);
	return n;
}

void pacmanlevel_1()                                   //pacman movement show function
{
	switch(pacn.rotate)
	{
	case 0:
		if(pacn.bit==1)
		{
		iShowBMP(pacn.x,pacn.y,"pictures/pacman11.bmp");
		pacn.bit=0;
		}
		else
		{
		iShowBMP(pacn.x,pacn.y,"pictures/pacman114.bmp");
		pacn.bit=1;
		}
		break;
	case 1:
		if(pacn.bit==1)
		{
		iShowBMP(pacn.x,pacn.y,"pictures/pacman111.bmp");
		pacn.bit=0;
		}
		else
		{
		iShowBMP(pacn.x,pacn.y,"pictures/pacman116.bmp");
		pacn.bit=1;
		}
		break;
	case 2:
    	if(pacn.bit==1)
		{
		iShowBMP(pacn.x,pacn.y,"pictures/pacman112.bmp");
		pacn.bit=0;
		}
		else
		{
		iShowBMP(pacn.x,pacn.y,"pictures/pacman117.bmp");
        pacn.bit=1;
		}
		break;
	case 3:
		if(pacn.bit==1)
		{
		iShowBMP(pacn.x,pacn.y,"pictures/pacman113.bmp");
		pacn.bit=0;
		}
		else
		{
		iShowBMP(pacn.x,pacn.y,"pictures/pacman118.bmp");
		pacn.bit=1;
		}
		break;
	}
}

int dijstra(int shortestpath[MAX_VERTEX],int source,int destination)              // dijetra algorithom function
{
	vertexinfo pathInfo[MAX_VERTEX];
	int i=0;
	int nodes=0;
	int sourcenode=0;
	int mindistance=0;
	int temppath[MAX_VERTEX];

	for(i=1;i<=vertices;i++)
	{
		pathInfo[i].predecessor=0;
		pathInfo[i].distance=INFINITY;
		pathInfo[i].mark=GRAY;
	}

	pathInfo[source].predecessor=0;
	pathInfo[source].distance=0;
	pathInfo[source].mark=BLACK;

	sourcenode=source;

	do
	{
		for(i=1;i<=vertices;i++)
		{
			if((edge[level][sourcenode][i]>0) && (pathInfo[i].mark==GRAY))
			{
				if( (pathInfo[sourcenode].distance+edge[level][sourcenode][i])<pathInfo[i].distance)
				{
					pathInfo[i].predecessor=sourcenode;
					pathInfo[i].distance=pathInfo[sourcenode].distance+edge[level][sourcenode][i];
				}
			}
		}
		mindistance=INFINITY;
		sourcenode=0;

		for(i=1;i<=vertices;i++)
		{
			if((pathInfo[i].mark==GRAY) && (pathInfo[i].distance<mindistance))
			{
				mindistance=pathInfo[i].distance;
				sourcenode=i;
			}
		}

		if(sourcenode==0) return 0;

		pathInfo[sourcenode].mark=BLACK;
	}while(sourcenode!=destination);

	sourcenode=destination;

	do
	{
		nodes+=1;
		temppath[nodes]=sourcenode;
		sourcenode=pathInfo[sourcenode].predecessor;
	}while(sourcenode!=0);

	for(i=1;i<=nodes;i++)
	{
		shortestpath[i]=temppath[nodes-i+1];
	}

	return nodes;
}

void rand_position(int *a,int *b )     // random position function
{
	float x;
	int n,m;

	x=rand()/32768.0;
	m=1+(int)(20*x);

	x=rand()/32768.0;
	n=1+(int)(20*x);

	if(n==7 && m>=0 && m<=3) rand_position(a,b);
	else if(n==7 && m>=17 && m<=20) rand_position(a,b);
	else if(n==11 && m>=0 && m<=3) rand_position(a,b);
	else if(n==11 && m>=17 && m<=20) rand_position(a,b);
 	else if(alevel[level][n][m]==0)
	{
		*a=m;
		*b=n;
	}
	else rand_position(a,b);
}

void pacman_death()                          // pacman death condition function
{
	if(((death.len+1==pacn.len || death.len-1==pacn.len ) && death.lin==pacn.lin) || ((death.lin+1==pacn.lin || death.lin-1==pacn.lin ) && death.len==pacn.len))
		{
		    PlaySound("sounds/lose.wav",NULL,SND_ASYNC);
			death.count=0;
			live_point--;
			total_initial();
			iDelay(3);
		}
	else if(((enm1.elen+1==pacn.len || enm1.elen-1==pacn.len ) && enm1.elin==pacn.lin) || ((enm1.elin+1==pacn.lin || enm1.elin-1==pacn.lin ) && enm1.elen==pacn.len))
		{
		   if(enem_control==0)
		   {
			PlaySound("sounds/lose.wav",NULL,SND_ASYNC);
			death.count=0;
			live_point--;
			total_initial();
			iDelay(3);
		   }
		   else
		   {
			   point+=200;
			   enm1.eye=1;
			   PlaySound("sounds/drop.wav",NULL,SND_ASYNC);
		   }
		}
	else if(((enm2.elen+1==pacn.len || enm2.elen-1==pacn.len ) && enm2.elin==pacn.lin) || ((enm2.elin+1==pacn.lin || enm2.elin-1==pacn.lin ) && enm2.elen==pacn.len))
		{
		if(enem_control==0)
		   {
			PlaySound("sounds/lose.wav",NULL,SND_ASYNC);
			death.count=0;
			live_point--;
			total_initial();
			iDelay(3);
		}
		else
		   {
			   point+=200;
			   enm2.eye=1;
			   PlaySound("sounds/drop.wav",NULL,SND_ASYNC);
		   }
		}
	else if(((enm3.elen+1==pacn.len || enm3.elen-1==pacn.len ) && enm3.elin==pacn.lin) || ((enm3.elin+1==pacn.lin || enm3.elin-1==pacn.lin ) && enm3.elen==pacn.len))
		{
		   if(enem_control==0)
		   {
			PlaySound("sounds/lose.wav",NULL,SND_ASYNC);
			death.count=0;
			live_point--;
			total_initial();
			iDelay(3);
		   }
		   else
		   {
			   point+=800;
			   enm3.eye=1;
			   PlaySound("sounds/drop.wav",NULL,SND_ASYNC);
		   }
		}
	else if(((enm4.elen+1==pacn.len || enm4.elen-1==pacn.len ) && enm4.elin==pacn.lin) || ((enm4.elin+1==pacn.lin || enm4.elin-1==pacn.lin ) && enm4.elen==pacn.len))
		{
		   if(enem_control==0)
		   {
            PlaySound("sounds/lose.wav",NULL,SND_ASYNC);
			death.count=0;
			live_point--;
			total_initial();
			iDelay(3);
		   }
		   else
		   {
			   point+=400;
			   enm4.eye=1;
			   PlaySound("sounds/drop.wav",NULL,SND_ASYNC);
		   }
		}

}

void enemy_eye()                //ememy eye initialization after eating by pacman
{
	enm1.eye=0;
	enm2.eye=0;
	enm3.eye=0;
	enm4.eye=0;
}

void special_food()             //special food function
{
	if(spfood.count==48)
	{
		enem_control=0;
		enem_control_timer=0;
	}
	if(spfood.count==80)
	{
        enemy_eye();
	}
	if(spfood.count>=100 && spfood.count<300)
	{
		if(spfood.count==100)
		{
             rand_position(&spfood.len,&spfood.lin);
		}
		if(spfood.flag==1)
		{
		iSetColor(200,190,10);
		spfood.flag=0;
		}
		else
		{
		iSetColor(10,244,110);
		spfood.flag=1;
		}

		iFilledCircle(368+spfood.len*32+16,640-spfood.lin*32+16,10);

		if(((spfood.len+1==pacn.len || spfood.len-1==pacn.len ) && spfood.lin==pacn.lin) || ((spfood.lin+1==pacn.lin || spfood.lin-1==pacn.lin ) && spfood.len==pacn.len))
		{
			spfood.count=0;
			enem_control=1;
			PlaySound("sounds/drop.wav",NULL,SND_ASYNC);
		}
	}
	else if(spfood.count==250)
	{
		spfood.count=0;
	}
	if(life.count>=50 && life.count<150)             //bonus life food
	{
		if(life.count==50)
		{
             rand_position(&life.len,&life.lin);
		}
		if(life.flag==1)
		{
		iShowBMP(368+life.len*32,640-life.lin*32,"pictures/heart1.bmp");
		life.flag=0;
		}
		else
		{
		iShowBMP(368+life.len*32,640-life.lin*32,"pictures/heart2.bmp");
		life.flag=1;
		}
		if(((life.len+1==pacn.len || life.len-1==pacn.len ) && life.lin==pacn.lin) || ((life.lin+1==pacn.lin || life.lin-1==pacn.lin ) && life.len==pacn.len))
		{
			life.count=0;
			live_point++;
			PlaySound("sounds/drop.wav",NULL,SND_ASYNC);
		}
	}
	else if(life.count==150)
	{
		life.count=0;
	}

	if(death.count>=75 && death.count<175)                 //denger food
	{
		if(death.count==75)
		{
             rand_position(&death.len,&death.lin);
		}
		if(death.flag==1)
		{
			iShowBMP(368+death.len*32,640-death.lin*32,"pictures/death1.bmp");
		    death.flag=2;
		}
		else if(death.flag==2)
		{
			iShowBMP(368+death.len*32,640-death.lin*32,"pictures/death2.bmp");
		    death.flag=3;
		}
		else if(death.flag==3)
		{
			iShowBMP(368+death.len*32,640-death.lin*32,"pictures/death3.bmp");
		    death.flag=4;
		}
		else if(death.flag==4)
		{
			iShowBMP(368+death.len*32,640-death.lin*32,"pictures/death4.bmp");
		    death.flag=1;
		}
		
		pacman_death();
	}
	else if(death.count==175)
	{
		death.count=0;
	}

	if(dolar.count>=225 && dolar.count<325)             // bonus point food
	{
		if(dolar.count==225)
		{
             rand_position(&dolar.len,&dolar.lin);
		}
		if(dolar.flag==1)
		{
		iShowBMP(368+dolar.len*32,640-dolar.lin*32,"pictures/dolar1.bmp");
		dolar.flag=0;
		}
		else
		{
		iShowBMP(368+dolar.len*32,640-dolar.lin*32,"pictures/dolar2.bmp");
		dolar.flag=1;
		}

		if(((dolar.len+1==pacn.len || dolar.len-1==pacn.len ) && dolar.lin==pacn.lin) || ((dolar.lin+1==pacn.lin || dolar.lin-1==pacn.lin ) && dolar.len==pacn.len))
		{
			dolar.count=0;
			point+=50;
			PlaySound("sounds/drop.wav",NULL,SND_ASYNC);
		}
	}
	else if(dolar.count==325)
	{
		dolar.count=0;
	}
}

void sp_count()                  //specilal food variable increase function
{
	spfood.count++;
	life.count++;
	death.count++;
	dolar.count++;
	if(enem_control==1)
	{
         enem_control_timer++;
	}
}

void food()                   //General food function
{
	static int i=0,j=0;

	if(food_flag==1)
	{
		food_flag=0;
		iSetColor(255,200,247);
	}
	else
	{
		food_flag=1;
		iSetColor(100,144,210);
	}
	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
			if(alevel[level][i][j]==0)
			{
				  if(total[level][pacn.lin][pacn.len]==3)
				  {
					  point+=10;
					  point_level++;
					  PlaySound("sounds/jerk.wav",NULL,SND_ASYNC);
				  }
				  total[level][pacn.lin][pacn.len]=0;

	              iFilledCircle(368+j*32+16,640-i*32+16,total[level][i][j]);
			}
		}
	}
}

void pacman_limit()                //pacman limitation function for movement
{
	int i=0,j=0;
	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
        	if(alevel[level][i][j]==1)
			{
		    	if(pacn.x==pic_x1-48+j*32-32 && pacn.y==pic_y1+144-i*32 || pacn.x==pic_x1-48+j*32+32 && pacn.y==pic_y1+144-i*32 )
				{
				     pacn.dx=0;
				}
		        if(pacn.x==pic_x1-48+j*32 && pacn.y==pic_y1+144-i*32-32 || pacn.x==pic_x1-48+j*32 && pacn.y==pic_y1+144-i*32+32 )
				{
                     pacn.dy=0;
				}
			}
		}
	}
}

void pacman_wallout()                 //pacman wallout function
{
	if(level==0)
	{
	    if(pacn.x<pic_x1-48+0*32 && pacn.y==pic_y1+144-9*32)
		{
		pacn.x=pic_x1-48+20*32-pacn.dx;
		pacn.len=20;
		}
     	if(pacn.x>pic_x1-48+20*32 && pacn.y==pic_y1+144-9*32)
		{
		pacn.x=pic_x1-48+0*32+pacn.dx;
 		pacn.len=0;
		}
	}
	else
	{
		if(pacn.x<pic_x1-48+0*32 && pacn.y==pic_y1+144-10*32)
		{
		pacn.x=pic_x1-48+20*32-pacn.dx;
		pacn.len=20;
		}
    	if(pacn.x>pic_x1-48+20*32 && pacn.y==pic_y1+144-10*32)
		{
		pacn.x=pic_x1-48+0*32+pacn.dx;
		pacn.len=0;
		}
	}
}

int enemy1_move()                                                       //enemy1 move function
{
     int m;

	 m=rand_generator();

	 if(m==1)
	 {
		 if(alevel[level][enm1.elin][enm1.elen+1]==0) return 1;
		 else enemy1_move();
	 }
	 else if(m==2)
	 {
		 if(alevel[level][enm1.elin-1][enm1.elen]==0) return 2;
		 else enemy1_move();
	 }
	 else if(m==3)
	 {
		 if(alevel[level][enm1.elin][enm1.elen-1]==0) return 3;
		 else enemy1_move();
	 }
	 else if(m==4)
	 {
		 if(alevel[level][enm1.elin+1][enm1.elen]==0) return 4;
		 else enemy1_move();
	 }
}

void enemy1()                        //enemy1 main function
{
	pacman_death();
	if(enm1.count==64)
	{
        enm1.count=0;
	}

	if(enm1.pac_enm==1 && alevel[level][enm1.elin][enm1.elen+1]==1 && enm1.count%4==0) enm1.pac_enm=enemy1_move();
	else if(enm1.pac_enm==3 && alevel[level][enm1.elin][enm1.elen-1]==1 && enm1.count%4==0) enm1.pac_enm=enemy1_move();
  	else if(enm1.pac_enm==4 && alevel[level][enm1.elin+1][enm1.elen]==1 && enm1.count%4==0) enm1.pac_enm=enemy1_move();
	else if(enm1.pac_enm==2 && alevel[level][enm1.elin-1][enm1.elen]==1 && enm1.count%4==0) enm1.pac_enm=enemy1_move();

	if(enm1.elen==pacn.len && enm1.elin!=pacn.lin && enm1.count%4==0)
	{
		if(enm1.elin>pacn.lin)
		{
			if(enem_control==0)
			{
			       enm1.pac_enm=2;
			       if(alevel[level][enm1.elin-1][enm1.elen]==1) enm1.pac_enm=enemy1_move();
			}
			else
			{
				   enm1.pac_enm=4;
			       if(alevel[level][enm1.elin+1][enm1.elen]==1) enm1.pac_enm=enemy1_move();
			}
		}
		else if(enm1.elin<pacn.lin)
		{
			if(enem_control==0)
			{
		    	enm1.pac_enm=4;
			    if(alevel[level][enm1.elin+1][enm1.elen]==1) enm1.pac_enm=enemy1_move();
			}
			else
			{
				enm1.pac_enm=2;
			    if(alevel[level][enm1.elin-1][enm1.elen]==1) enm1.pac_enm=enemy1_move();

			}
		}
	}
	else if(enm1.elen!=pacn.len && enm1.elin==pacn.lin && enm1.count%4==0)
	{
		if(enm1.elen>pacn.len)
		{
			if(enem_control==0)
			{
			     enm1.pac_enm=3;
		         if(alevel[level][enm1.elin][enm1.elen-1]==1) enm1.pac_enm=enemy1_move();
			}
			else
			{
				enm1.pac_enm=1;
			    if(alevel[level][enm1.elin][enm1.elen+1]==1) enm1.pac_enm=enemy1_move();


			}
		}

		else if(enm1.elen<pacn.len)
		{
			if(enem_control==0)
			{
			enm1.pac_enm=1;
			if(alevel[level][enm1.elin][enm1.elen+1]==1) enm1.pac_enm=enemy1_move();
			}
			else
			{
				enm1.pac_enm=3;
	     		if(alevel[level][enm1.elin][enm1.elen-1]==1) enm1.pac_enm=enemy1_move();

			}
		}
	}

	switch(enm1.pac_enm)
	{
	case 1:
		enm1.enm_x+=enm1.edx;
		enm1.emode1+=enm1.edx;
		if(enm1.emode1==32)
		{
			enm1.emode1=0;
			enm1.elen++;
		}
		break;
	case 2:
        enm1.enm_y+=enm1.edy;
		enm1.ecount2+=enm1.edy;
		if(enm1.ecount2==32)
		{
			enm1.ecount2=0;
			enm1.elin--;
		}
		break;
	case 3:
		enm1.enm_x-=enm1.edx;
		enm1.emode2+=enm1.edx;
		if(enm1.emode2==32)
		{
			enm1.emode2=0;
			enm1.elen--;
		}
		break;
	case 4:
		enm1.enm_y-=enm1.edy;
		enm1.ecount1+=enm1.edy;
		if(enm1.ecount1==32)
		{
			enm1.ecount1=0;
			enm1.elin++;
		}
		break;
	}
	
	if(level==0)
	{
	if(enm1.enm_x<pic_x1-48+0*32 && enm1.enm_y==pic_y1+144-9*32)
	{
		enm1.enm_x=pic_x1-48+20*32-enm1.edx;
		enm1.elen=20;
	}
	if(enm1.enm_x>pic_x1-48+20*32 && enm1.enm_y==pic_y1+144-9*32)
	{
		enm1.enm_x=pic_x1-48+0*32+enm1.edx;
		enm1.elen=0;
	}
	}
	else
	{
		if(enm1.enm_x<pic_x1-48+0*32 && enm1.enm_y==pic_y1+144-10*32)
	{
		enm1.enm_x=pic_x1-48+20*32-enm1.edx;
		enm1.elen=20;
	}
	if(enm1.enm_x>pic_x1-48+20*32 && enm1.enm_y==pic_y1+144-10*32)
	{
		enm1.enm_x=pic_x1-48+0*32+enm1.edx;
		enm1.elen=0;
	}
	}
}

int enemy2_move()                                   //enemy2 move function
{
     int m;

	 m=rand_generator();

	 if(m==1)
	 {
		 if(alevel[level][enm2.elin][enm2.elen+1]==0) return 1;
		 else enemy2_move();
	 }
	 else if(m==2)
	 {
		 if(alevel[level][enm2.elin-1][enm2.elen]==0) return 2;
		 else enemy2_move();
	 }
	 else if(m==3)
	 {
		 if(alevel[level][enm2.elin][enm2.elen-1]==0) return 3;
		 else enemy2_move();
	 }
	 else if(m==4)
	 {
		 if(alevel[level][enm2.elin+1][enm2.elen]==0) return 4;
		 else enemy2_move();
	 }
}

void enemy2()                                    //enemy2 main function 
{
	pacman_death();

	if(enm2.count==16)
	{
    	enm2.pac_enm=enemy2_move();
        enm2.count=0;
	}
	
	if(enm2.pac_enm==1 && alevel[level][enm2.elin][enm2.elen+1]==1 && enm2.count%4==0) enm2.pac_enm=enemy2_move();
	else if(enm2.pac_enm==3 && alevel[level][enm2.elin][enm2.elen-1]==1 && enm2.count%4==0) enm2.pac_enm=enemy2_move();
  	else if(enm2.pac_enm==4 && alevel[level][enm2.elin+1][enm2.elen]==1 && enm2.count%4==0) enm2.pac_enm=enemy2_move();
	else if(enm2.pac_enm==2 && alevel[level][enm2.elin-1][enm2.elen]==1 && enm2.count%4==0) enm2.pac_enm=enemy2_move();

	if(enm2.elen==pacn.len && enm2.elin!=pacn.lin && enm2.count%4==0)
	{
		if(enm2.elin>pacn.lin)
		{
			if(enem_control==0)
			{
			enm2.pac_enm=2;
			if(alevel[level][enm2.elin-1][enm2.elen]==1) enm2.pac_enm=enemy2_move();
			}
			else
			{
				enm2.pac_enm=4;
			if(alevel[level][enm2.elin+1][enm2.elen]==1) enm2.pac_enm=enemy2_move();

			}
		}
		else if(enm2.elin<pacn.lin)
		{
			if(enem_control==0)
			{
			enm2.pac_enm=4;
			if(alevel[level][enm2.elin+1][enm2.elen]==1) enm2.pac_enm=enemy2_move();
			}
			else
			{
				enm2.pac_enm=2;
			    if(alevel[level][enm2.elin-1][enm2.elen]==1) enm2.pac_enm=enemy2_move();
			}
		}
	}
	else if(enm2.elen!=pacn.len && enm2.elin==pacn.lin && enm2.count%4==0)
	{
		if(enm2.elen>pacn.len)
		{
			if(enem_control==0)
			{
			enm2.pac_enm=3;
			if(alevel[level][enm2.elin][enm2.elen-1]==1) enm2.pac_enm=enemy2_move();
			}
			else
			{
				enm2.pac_enm=1;
			if(alevel[level][enm2.elin][enm2.elen+1]==1) enm2.pac_enm=enemy2_move();
			}
		}
		else if(enm2.elen<pacn.len)
		{
			if(enem_control==0)
			{
			enm2.pac_enm=1;
			if(alevel[level][enm2.elin][enm2.elen+1]==1) enm2.pac_enm=enemy2_move();
			}
			else
			{
				enm2.pac_enm=3;
			if(alevel[level][enm2.elin][enm2.elen-1]==1) enm2.pac_enm=enemy2_move();
			}
		}
	}
	
	switch(enm2.pac_enm)
	{
	case 1:
		enm2.enm_x+=enm2.edx;
		enm2.emode1+=enm2.edx;
		if(enm2.emode1==32)
		{
			enm2.emode1=0;
			enm2.elen++;
		}
		break;
	case 2:
        enm2.enm_y+=enm2.edy;
		enm2.ecount2+=enm2.edy;
		if(enm2.ecount2==32)
		{
			enm2.ecount2=0;
			enm2.elin--;
		}
		break;
	case 3:
		enm2.enm_x-=enm2.edx;
		enm2.emode2+=enm2.edx;
		if(enm2.emode2==32)
		{
			enm2.emode2=0;
			enm2.elen--;
		}
		break;
	case 4:
		enm2.enm_y-=enm2.edy;
		enm2.ecount1+=enm2.edy;
		if(enm2.ecount1==32)
		{
			enm2.ecount1=0;
			enm2.elin++;
		}
		break;
	}

   if(level==0)
   {

	if(enm2.enm_x<pic_x1-48+0*32 && enm2.enm_y==pic_y1+144-9*32)
	{
		enm2.enm_x=pic_x1-48+20*32-enm2.edx;
		enm2.elen=20;
	}
	if(enm2.enm_x>pic_x1-48+20*32 && enm2.enm_y==pic_y1+144-9*32)
	{
		enm2.enm_x=pic_x1-48+0*32+enm2.edx;
		enm2.elen=0;
	}
   }
   else
   {
	   if(enm2.enm_x<pic_x1-48+0*32 && enm2.enm_y==pic_y1+144-10*32)
	{
		enm2.enm_x=pic_x1-48+20*32-enm2.edx;
		enm2.elen=20;
	}
	if(enm2.enm_x>pic_x1-48+20*32 && enm2.enm_y==pic_y1+144-10*32)
	{
		enm2.enm_x=pic_x1-48+0*32+enm2.edx;
		enm2.elen=0;
	}

   }
}

int enemy3_move()                            //enemy3 move function
{
     int m;

	 m=rand_generator();

	 if(m==1)
	 {
		 if(alevel[level][enm3.elin][enm3.elen+1]==0) return 1;
		 else enemy3_move();
	 }
	 else if(m==2)
	 {
		 if(alevel[level][enm3.elin-1][enm3.elen]==0) return 2;
		 else enemy3_move();
	 }
	 else if(m==3)
	 {
		 if(alevel[level][enm3.elin][enm3.elen-1]==0) return 3;
		 else enemy3_move();
	 }
	 else if(m==4)
	 {
		 if(alevel[level][enm3.elin+1][enm3.elen]==0) return 4;
		 else enemy3_move();
	 }
}

void enemy3_dij()                  //enemy3 next move function by dijstra
{
	int i,j,nodes;
	int shortestpath[MAX_VERTEX];

 	nodes=dijstra(shortestpath,enm3.node[enm3.elin][enm3.elen],pac_node[pacn.lin][pacn.len]);

	if(enm3.count%4==0)
	{
		for(i=0;i<21;i++)
		{
		for(j=0;j<21;j++)
		{
            if (alevel[level][i][j]==0)
			{
				if(enm3.node[i][j]==shortestpath[2])
				{
					if(enm3.elen>j && enm3.elin==i)
					{
						enm3.pac_enm=3;
					}
					if(enm3.elen<j && enm3.elin==i)
					{
					 	enm3.pac_enm=1;
					}
					if(enm3.elen==j && enm3.elin>i)
					{
						enm3.pac_enm=2;
					}
					if(enm3.elen==j && enm3.elin<i)
					{
						enm3.pac_enm=4;
					}

				}
			}
		}
		}
	}
}

void enemy3()                   //enemy3 main function
{
	pacman_death();

	if(enm3.count==64)
	{
        enm3.count=0;
	}
	if(enem_control==0)
	{
	      enemy3_dij();
	}
	else
	{
		if(enm3.pac_enm==1 && alevel[level][enm3.elin][enm3.elen+1]==1 && enm3.count%4==0) enm3.pac_enm=enemy3_move();
    	else if(enm3.pac_enm==3 && alevel[level][enm3.elin][enm3.elen-1]==1 && enm3.count%4==0) enm3.pac_enm=enemy3_move();
  	    else if(enm3.pac_enm==4 && alevel[level][enm3.elin+1][enm3.elen]==1 && enm3.count%4==0) enm3.pac_enm=enemy3_move();
	    else if(enm3.pac_enm==2 && alevel[level][enm3.elin-1][enm3.elen]==1 && enm3.count%4==0) enm3.pac_enm=enemy3_move();

		if(enm3.elen==pacn.len && enm3.elin!=pacn.lin && enm3.count%4==0)
		{
		if(enm3.elin>pacn.lin)
		{
			enm3.pac_enm=4;
			if(alevel[level][enm3.elin+1][enm3.elen]==1) enm3.pac_enm=enemy3_move();
		}
		else if(enm3.elin<pacn.lin)
		{
			enm3.pac_enm=2;
			if(alevel[level][enm3.elin-1][enm3.elen]==1) enm3.pac_enm=enemy3_move();
		}
		}
	    else if(enm3.elen!=pacn.len && enm3.elin==pacn.lin && enm3.count%4==0)
		{
		if(enm3.elen>pacn.len)
		{
				enm3.pac_enm=1;
			if(alevel[level][enm3.elin][enm3.elen+1]==1) enm3.pac_enm=enemy3_move();
		}
		else if(enm3.elen<pacn.len)
		{
				enm3.pac_enm=3;
			if(alevel[level][enm3.elin][enm3.elen-1]==1) enm3.pac_enm=enemy3_move();
		}
		}

	}

	switch(enm3.pac_enm)
	{
	case 1:
		enm3.enm_x+=enm3.edx;
		enm3.emode1+=enm3.edx;
		if(enm3.emode1==32)
		{
			enm3.emode1=0;
			enm3.elen++;
		}
		break;
	case 2:
        enm3.enm_y+=enm3.edy;
		enm3.ecount2+=enm3.edy;
		if(enm3.ecount2==32)
		{
			enm3.ecount2=0;
			enm3.elin--;
		}
		break;
	case 3:
		enm3.enm_x-=enm3.edx;
		enm3.emode2+=enm3.edx;
		if(enm3.emode2==32)
		{
			enm3.emode2=0;
			enm3.elen--;
		}
		break;
	case 4:
		enm3.enm_y-=enm3.edy;
		enm3.ecount1+=enm3.edy;
		if(enm3.ecount1==32)
		{
			enm3.ecount1=0;
			enm3.elin++;
		}
		break;
	}

	if(level==0)
	{
	if(enm3.enm_x<pic_x1-48+0*32 && enm3.enm_y==pic_y1+144-9*32)
	{
		enm3.enm_x=pic_x1-48+20*32-enm3.edx;
		enm3.elen=20;
	}
	if(enm3.enm_x>pic_x1-48+20*32 && enm3.enm_y==pic_y1+144-9*32)
	{
		enm3.enm_x=pic_x1-48+0*32+enm3.edx;
		enm3.elen=0;
	}
	}
	else
	{
		if(enm3.enm_x<pic_x1-48+0*32 && enm3.enm_y==pic_y1+144-10*32)
	{
		enm3.enm_x=pic_x1-48+20*32-enm3.edx;
		enm3.elen=20;
	}
	if(enm3.enm_x>pic_x1-48+20*32 && enm3.enm_y==pic_y1+144-10*32)
	{
		enm3.enm_x=pic_x1-48+0*32+enm3.edx;
		enm3.elen=0;
	}
	}
}

int enemy4_move()                                     //enemy4 move function
{
     int m;

	 m=rand_generator();

	 if(m==1)
	 {
		 if(alevel[level][enm4.elin][enm4.elen+1]==0) return 1;
		 else enemy4_move();
	 }
	 else if(m==2)
	 {
		 if(alevel[level][enm4.elin-1][enm4.elen]==0) return 2;
		 else enemy4_move();
	 }
	 else if(m==3)
	 {
		 if(alevel[level][enm4.elin][enm4.elen-1]==0) return 3;
		 else enemy4_move();
	 }
	 else if(m==4)
	 {
		 if(alevel[level][enm4.elin+1][enm4.elen]==0) return 4;
		 else enemy4_move();
	 }
}

void enemy4_cease()                         //enemy4 without algorithom but about to algo function by condition
{
	if(enm4.elen!=pacn.len && enm4.elin!=pacn.lin && enm4.count%4==0)
	{
		if(pacn.len>pacn.lin)
		{
           if(enm4.elen>pacn.len)
		   {
			   if(enem_control==0)
			   {
		    	    enm4.pac_enm=3;
		        	if(alevel[level][enm4.elin][enm4.elen-1]==1)
					{
						enm4.pac_enm=enemy4_move();
					}
			   }
			   else
			   {
				   enm4.pac_enm=1;
		    	   if(alevel[level][enm4.elin][enm4.elen+1]==1) enm4.pac_enm=enemy4_move();
			   }
		   }
		   else if(enm4.elen<pacn.len)
		   {
			   if(enem_control==0)
			   {
		    	enm4.pac_enm=1;
		    	if(alevel[level][enm4.elin][enm4.elen+1]==1) enm4.pac_enm=enemy4_move();
			   }
			   else
			   {
				   enm4.pac_enm=3;
		    	   if(alevel[level][enm4.elin][enm4.elen-1]==1) enm4.pac_enm=enemy4_move();
			   }
		   }
		}
		else if(pacn.len<pacn.lin)
		{
            if(enm4.elin>pacn.lin)
			{
				if(enem_control==0)
				{
			    enm4.pac_enm=2;
		    	if(alevel[level][enm4.elin-1][enm4.elen]==1) enm4.pac_enm=enemy4_move();
				}
				else
				{
				enm4.pac_enm=4;
		    	if(alevel[level][enm4.elin+1][enm4.elen]==1) enm4.pac_enm=enemy4_move();
				}
			}
	    	else if(enm4.elin<pacn.lin)
			{
				if(enem_control==0)
				{
		    	enm4.pac_enm=4;
		    	if(alevel[level][enm4.elin+1][enm4.elen]==1) enm4.pac_enm=enemy4_move();
				}
				else
				{
				enm4.pac_enm=2;
		    	if(alevel[level][enm4.elin-1][enm4.elen]==1) enm4.pac_enm=enemy4_move();
				}
			}
		}
		else
		{
			enm4.pac_enm=enemy4_move();
		}
	}
	else if(enm4.elen==pacn.len && enm4.elin!=pacn.lin && enm4.count%4==0)
	{
		if(enm4.elin>pacn.lin)
		{
			if(enem_control==0)
			{
			enm4.pac_enm=2;
			if(alevel[level][enm4.elin-1][enm4.elen]==1) enm4.pac_enm=enemy4_move();
			}
			else
			{
			enm4.pac_enm=4;
			if(alevel[level][enm4.elin+1][enm4.elen]==1) enm4.pac_enm=enemy4_move();
			}
		}
		else if(enm4.elin<pacn.lin)
		{
			if(enem_control==0)
			{
			enm4.pac_enm=4;
			if(alevel[level][enm4.elin+1][enm4.elen]==1) enm4.pac_enm=enemy4_move();
			}
			else
			{
			enm4.pac_enm=2;
			if(alevel[level][enm4.elin-1][enm4.elen]==1) enm4.pac_enm=enemy4_move();
			}
		}
	}
	else if(enm4.elen!=pacn.len && enm4.elin==pacn.lin && enm4.count%4==0)
	{
		if(enm4.elen>pacn.len)
		{
			if(enem_control==0)
			{
			enm4.pac_enm=3;
			if(alevel[level][enm4.elin][enm4.elen-1]==1) enm4.pac_enm=enemy4_move();
			}
			else
			{
			enm4.pac_enm=1;
			if(alevel[level][enm4.elin][enm4.elen+1]==1) enm4.pac_enm=enemy4_move();
			}
		}
		else if(enm4.elen<pacn.len)
		{
			if(enem_control==0)
			{
			enm4.pac_enm=1;
			if(alevel[level][enm4.elin][enm4.elen+1]==1) enm4.pac_enm=enemy4_move();
			}
			else
			{
			enm4.pac_enm=3;
			if(alevel[level][enm4.elin][enm4.elen-1]==1) enm4.pac_enm=enemy4_move();
			}
		}
	}
}

void enemy4()                    //enemy4 main function
{
	pacman_death();

	if(enm4.count==64)
	{
        enm4.count=0;
	}
	
    enemy4_cease();

	switch(enm4.pac_enm)
	{
	case 1:
		enm4.enm_x+=enm4.edx;
		enm4.emode1+=enm4.edx;
		if(enm4.emode1==32)
		{
			enm4.emode1=0;
			enm4.elen++;
		}
		break;
	case 2:
        enm4.enm_y+=enm4.edy;
		enm4.ecount2+=enm4.edy;
		if(enm4.ecount2==32)
		{
			enm4.ecount2=0;
			enm4.elin--;
		}
		break;
	case 3:
		enm4.enm_x-=enm4.edx;
		enm4.emode2+=enm4.edx;
		if(enm4.emode2==32)
		{
			enm4.emode2=0;
			enm4.elen--;
		}
		break;
	case 4:
		enm4.enm_y-=enm4.edy;
		enm4.ecount1+=enm4.edy;
		if(enm4.ecount1==32)
		{
			enm4.ecount1=0;
			enm4.elin++;
		}
		break;
	}

	if(level==0)
	{
	if(enm4.enm_x<pic_x1-48+0*32 && enm4.enm_y==pic_y1+144-9*32)
	{
		enm4.enm_x=pic_x1-48+20*32-enm4.edx;
		enm4.elen=20;
	}
	if(enm4.enm_x>pic_x1-48+20*32 && enm4.enm_y==pic_y1+144-9*32)
	{
		enm4.enm_x=pic_x1-48+0*32+enm4.edx;
		enm4.elen=0;
	}
	}
	else
	{
		if(enm4.enm_x<pic_x1-48+0*32 && enm4.enm_y==pic_y1+144-10*32)
		{
		enm4.enm_x=pic_x1-48+20*32-enm4.edx;
		enm4.elen=20;
		}
    	if(enm4.enm_x>pic_x1-48+20*32 && enm4.enm_y==pic_y1+144-10*32)
		{
 		enm4.enm_x=pic_x1-48+0*32+enm4.edx;
		enm4.elen=0;
		}
	}
}

void pacman_enem()                 //all enemy timer function
{
     enemy1();
	 enm1.count++;

	 enemy2();
	 enm2.count++;

	 enemy3();
	 enm3.count++;

	 enemy4();
	 enm4.count++;
}

void pacman_change()                                 //pacman moving function
{
	switch(pacn.move)
	{
	case 1:
		pacn.x+=pacn.dx;
		pacn.mode1+=pacn.dx;
		if(pacn.mode1==32)
		{
			pacn.mode1=0;
			pacn.len++;
		}
		break;
	case 2:
        pacn.y+=pacn.dy;
		pacn.count2+=pacn.dy;
		if(pacn.count2==32)
		{
			pacn.count2=0;
			pacn.lin--;
		}
		break;
	case 3:
		pacn.x-=pacn.dx;
		pacn.mode2+=pacn.dx;
		if(pacn.mode2==32)
		{
			pacn.mode2=0;
			pacn.len--;
		}
		break;
	case 4:
		pacn.y-=pacn.dy;
		pacn.count1+=pacn.dy;
		if(pacn.count1==32)
		{
			pacn.count1=0;
			pacn.lin++;
		}
		break;
	}

	pacman_limit();
	pacman_wallout();

	sp_count();
	game_over();
}

void welcome_change()                            //welcome variable control function
{
	if(welcome==64) welcome=0;
	welcome++;
}

void pause_game()                                //pause game function
{
	iSetColor(245,245,245);
	iFilledRectangle(500,330,200,200);
	iSetColor(30,144,255);
	iFilledRectangle(510,450,180,50);
	iSetColor(30,144,255);
	iFilledRectangle(510,350,180,50);

	iSetColor(127,255,0);

     	iText(540,465,"CONTINUE",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(541,465,"CONTINUE",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(542,465,"CONTINUE",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(540,466,"CONTINUE",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(551,365,"MANU",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(552,365,"MANU",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550,365,"MANU",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550,366,"MANU",GLUT_BITMAP_TIMES_ROMAN_24);
}

void iWindow1()                       //opening window taking name from user
{
	    if(welcome%4) 
		{
			iShowBMP(275,400,"pictures/welcome2.bmp");
		}
		else
		{
			iShowBMP(275,400,"pictures/welcome1.bmp");
		}
		if(welcome%8==0) iSetColor(255,255,0);
		else iSetColor(2,0,255);

		iText(405,330,"ENTER YOUR NAME: ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(406,330,"ENTER YOUR NAME: ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(407,330,"ENTER YOUR NAME: ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(405,331,"ENTER YOUR NAME: ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(705,330,username,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(706,330,username,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(707,330,username,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(705,331,username,GLUT_BITMAP_TIMES_ROMAN_24);

		Pause_timer();
}

void point_count()         //point,lifes and level show function                    
{
	iShowBMP(1120,500,"pictures/pacman115.bmp");
	iSetColor(0,0,0);
	itoa(point,str,10);
	iText(1190,534,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1191,534,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1192,534,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1192,535,str,GLUT_BITMAP_TIMES_ROMAN_24);

	iShowBMP(1120,400,"pictures/lives.bmp");
	iSetColor(0,0,0);
	itoa(live_point,str,10);
	iText(1200,434,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1201,434,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1202,434,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1202,435,str,GLUT_BITMAP_TIMES_ROMAN_24);

	iShowBMP(1120,300,"pictures/level_score.bmp");
	iSetColor(0,0,0);
	itoa(level+1,str,10);
	iText(1200,334,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1201,334,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1202,334,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1202,335,str,GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(30,144,255);

	iSetColor(0,0,0);
    iText(80,534,"PLAYER NAME:",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80,534,"PLAYER NAME:",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80,534,"PLAYER NAME:",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80,535,"PLAYER NAME:",GLUT_BITMAP_TIMES_ROMAN_24);
	
	if(welcome%2==0) iSetColor(0,0,156);
	else iSetColor(155,105,0);
	iText(130,484,player_cur.name,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(131,484,player_cur.name,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(132,484,player_cur.name,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(130,485,player_cur.name,GLUT_BITMAP_TIMES_ROMAN_24);
}

void iWindow3()               //maze side design
{
	int i,j;
	for(i=30;i>0;i--)
	{
	    iSetColor((250-10*i),(250-10*i),(100-10*i));
        iFilledRectangle((1060+10-i),(20-i),(WIDTH-20-20+2*i),(HEIGHT-20+2*i));
    }
	for(j=30;j>0;j--)
	{
	    iSetColor((250-10*j),(250-10*j),(100-10*j));
        iFilledRectangle((20-j),(20-j),(WIDTH+40-20+2*j),(HEIGHT-20+2*j));
    }
	iShowBMP(120,600,"pictures/pause.bmp");
}

void iWindow4()               //after game over showing score board
{
	int i;

	iShowBMP(380,450,"pictures/gameover.bmp");
	
	for(i=1;i<name_count;i++)
	{
		if(strcmp(player[name_count-i].name,player_cur.name)==0)
		{
			iSetColor(127,255,0);
			printf("%s\n",player_cur.name);
		}
		else
		{
			iSetColor(0,255,255);
		}
		
	iText(555,450-30*i,player[name_count-i].name,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(556,450-30*i,player[name_count-i].name,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(557,450-30*i,player[name_count-i].name,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(555,451-30*i,player[name_count-i].name,GLUT_BITMAP_TIMES_ROMAN_24);

	itoa(player[name_count-i].score,str,10);

	iText(755,450-30*i,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(756,450-30*i,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(757,450-30*i,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(755,451-30*i,str,GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(welcome%4==0) iSetColor(255,255,0);
	else iSetColor(2,0,255);

		iText(pic_x1+140,pic_y1-450,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+141,pic_y1-450,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+142,pic_y1-450,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+143,pic_y1-450,"CLICK TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
}


/*
	function iDraw() is called again and again by the system.
*/
void enemy_draw()                  //all enemies movement function
{
	if(enm1.pac_enm==1)            //for enemy 1
	{
        if(enm1.flag==1)
		{
	       	iShowBMP(enm1.enm_x,enm1.enm_y,"pictures/enemy1.bmp");
		    enm1.flag=0;
			if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm1.enm_x,enm1.enm_y,32,32);
			}
		}
		else
		{
		   iShowBMP(enm1.enm_x,enm1.enm_y,"pictures/enemy11.bmp");
		   enm1.flag=1;
		   if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm1.enm_x,enm1.enm_y,32,32);
			}
		}
		if(enm1.eye==1)
		{
			if(enm1.eyeflag==1)
			{
                iShowBMP(enm1.enm_x,enm1.enm_y,"pictures/eye1.bmp");
		        enm1.eyeflag=0;
			}
			else
			{
                iShowBMP(enm1.enm_x,enm1.enm_y,"pictures/eye2.bmp");
		        enm1.eyeflag=1;
			}

		}
	}
	else if(enm1.pac_enm==3)
	{
        if(enm1.flag==1)
		{

	       	iShowBMP(enm1.enm_x,enm1.enm_y,"pictures/enemy12.bmp");
		    enm1.flag=0;

			if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm1.enm_x,enm1.enm_y,32,32);
			}
		}
		else
		{
		   iShowBMP(enm1.enm_x,enm1.enm_y,"pictures/enemy13.bmp");
	       enm1.flag=1;
		   if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm1.enm_x,enm1.enm_y,32,32);
			}
		}
		if(enm1.eye==1)
		{
			if(enm1.eyeflag==1)
			{
                iShowBMP(enm1.enm_x,enm1.enm_y,"pictures/eye1.bmp");
		        enm1.eyeflag=0;
			}
			else
			{
                iShowBMP(enm1.enm_x,enm1.enm_y,"pictures/eye2.bmp");
		        enm1.eyeflag=1;
			}
		}
	}
	else
	{
		if(enm1.flag==1)
		{
	       	iShowBMP(enm1.enm_x,enm1.enm_y,"pictures/enemy12.bmp");
		    enm1.flag=0;

			if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm1.enm_x,enm1.enm_y,32,32);
			}
		}

		else
		{
		   iShowBMP(enm1.enm_x,enm1.enm_y,"pictures/enemy13.bmp");
	       enm1.flag=1;
		   if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm1.enm_x,enm1.enm_y,32,32);
			}

		}
		if(enm1.eye==1)
		{
			if(enm1.eyeflag==1)
			{
                iShowBMP(enm1.enm_x,enm1.enm_y,"pictures/eye1.bmp");
		        enm1.eyeflag=0;
			}
			else
			{
                iShowBMP(enm1.enm_x,enm1.enm_y,"pictures/eye2.bmp");
		        enm1.eyeflag=1;
			}
		}
	}
	if(enm2.pac_enm==1)               //for enemy 2
	{
        if(enm2.flag==1)
		{
	       	iShowBMP(enm2.enm_x,enm2.enm_y,"pictures/enemy2.bmp");
		    enm2.flag=0;
			if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm2.enm_x,enm2.enm_y,32,32);
			}
		}
		else
		{

		iShowBMP(enm2.enm_x,enm2.enm_y,"pictures/enemy21.bmp");
		enm2.flag=1;
		if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm2.enm_x,enm2.enm_y,32,32);
			}

		}
		if(enm2.eye==1)
		{
			if(enm2.eyeflag==1)
			{
                iShowBMP(enm2.enm_x,enm2.enm_y,"pictures/eye1.bmp");
		        enm2.eyeflag=0;
			}
			else
			{
                iShowBMP(enm2.enm_x,enm2.enm_y,"pictures/eye2.bmp");
		        enm2.eyeflag=1;
			}
		}
	}
	else if(enm2.pac_enm==3)
	{
        if(enm2.flag==1)
		{
	       	iShowBMP(enm2.enm_x,enm2.enm_y,"pictures/enemy22.bmp");
		    enm2.flag=0;
			if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm2.enm_x,enm2.enm_y,32,32);
			}
		}
		else
		{
		   iShowBMP(enm2.enm_x,enm2.enm_y,"pictures/enemy23.bmp");
	       enm2.flag=1;
		   if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm2.enm_x,enm2.enm_y,32,32);
			}
		}
		if(enm2.eye==1)
		{
			if(enm2.eyeflag==1)
			{
                iShowBMP(enm2.enm_x,enm2.enm_y,"pictures/eye1.bmp");
		        enm2.eyeflag=0;
			}
			else
			{
                iShowBMP(enm2.enm_x,enm2.enm_y,"pictures/eye2.bmp");
		        enm2.eyeflag=1;
			}
		}
	}
	else
	{
		if(enm2.flag==1)
		{
	       	iShowBMP(enm2.enm_x,enm2.enm_y,"pictures/enemy22.bmp");
		    enm2.flag=0;
			if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm2.enm_x,enm2.enm_y,32,32);
			}
		}
		else
		{
		   iShowBMP(enm2.enm_x,enm2.enm_y,"pictures/enemy23.bmp");
	       enm2.flag=1;
		   if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm2.enm_x,enm2.enm_y,32,32);
			}
		}
		if(enm2.eye==1)
		{
			if(enm2.eyeflag==1)
			{
                iShowBMP(enm2.enm_x,enm2.enm_y,"pictures/eye1.bmp");
		        enm2.eyeflag=0;
			}
			else
			{
                iShowBMP(enm2.enm_x,enm2.enm_y,"pictures/eye2.bmp");
		        enm2.eyeflag=1;
			}
		}
	}
	if(enm3.pac_enm==1)                 // for enemy 3
	{
        if(enm3.flag==1)
		{
	       	iShowBMP(enm3.enm_x,enm3.enm_y,"pictures/enemy3.bmp");
		    enm3.flag=0;
			if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm3.enm_x,enm3.enm_y,32,32);
			}
		}
		else
		{
		iShowBMP(enm3.enm_x,enm3.enm_y,"pictures/enemy31.bmp");
		enm3.flag=1;
		if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm3.enm_x,enm3.enm_y,32,32);
			}
		}
		if(enm3.eye==1)
		{
			if(enm3.eyeflag==1)
			{
                iShowBMP(enm3.enm_x,enm3.enm_y,"pictures/eye1.bmp");
		        enm3.eyeflag=0;
			}
			else
			{
                iShowBMP(enm3.enm_x,enm3.enm_y,"pictures/eye2.bmp");
		        enm3.eyeflag=1;
			}
		}
	}
	else if(enm3.pac_enm==3)
	{
        if(enm3.flag==1)
		{
	       	iShowBMP(enm3.enm_x,enm3.enm_y,"pictures/enemy32.bmp");
		    enm3.flag=0;
			if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm3.enm_x,enm3.enm_y,32,32);
			}
		}
		else
		{
		   iShowBMP(enm3.enm_x,enm3.enm_y,"pictures/enemy33.bmp");
	       enm3.flag=1;
		   if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm3.enm_x,enm3.enm_y,32,32);
			}
		}

		if(enm3.eye==1)
		{
			if(enm3.eyeflag==1)
			{
                iShowBMP(enm3.enm_x,enm3.enm_y,"pictures/eye1.bmp");
		        enm3.eyeflag=0;
			}
			else
			{
                iShowBMP(enm3.enm_x,enm3.enm_y,"pictures/eye2.bmp");
		        enm3.eyeflag=1;
			}
		}
	}
	else
	{
		if(enm3.flag==1)
		{
	       	iShowBMP(enm3.enm_x,enm3.enm_y,"pictures/enemy32.bmp");
		    enm3.flag=0;
			if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm3.enm_x,enm3.enm_y,32,32);
			}
		}
		else
		{
		   iShowBMP(enm3.enm_x,enm3.enm_y,"pictures/enemy33.bmp");
	       enm3.flag=1;
		   if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm3.enm_x,enm3.enm_y,32,32);
			}
		}
		if(enm3.eye==1)
		{
			if(enm3.eyeflag==1)
			{
                iShowBMP(enm3.enm_x,enm3.enm_y,"pictures/eye1.bmp");
		        enm3.eyeflag=0;
			}
			else
			{
                iShowBMP(enm3.enm_x,enm3.enm_y,"pictures/eye2.bmp");
		        enm3.eyeflag=1;
			}
		}
	}
	if(enm4.pac_enm==1)                 //for enemy  4
	{
        if(enm4.flag==1)
		{
	       	iShowBMP(enm4.enm_x,enm4.enm_y,"pictures/enemy4.bmp");
		    enm4.flag=0;
			if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm4.enm_x,enm4.enm_y,32,32);
			}
		}
		else
		{
		iShowBMP(enm4.enm_x,enm4.enm_y,"pictures/enemy41.bmp");
		enm4.flag=1;
		if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm4.enm_x,enm4.enm_y,32,32);
			}
		}
		if(enm4.eye==1)
		{
			if(enm4.eyeflag==1)
			{
                iShowBMP(enm4.enm_x,enm4.enm_y,"pictures/eye1.bmp");
		        enm4.eyeflag=0;
			}
			else
			{
                iShowBMP(enm4.enm_x,enm4.enm_y,"pictures/eye2.bmp");
		        enm4.eyeflag=1;
			}
		}
	}
	else if(enm4.pac_enm==3)
	{
        if(enm4.flag==1)
		{
	       	iShowBMP(enm4.enm_x,enm4.enm_y,"pictures/enemy42.bmp");
		    enm4.flag=0;
			if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm4.enm_x,enm4.enm_y,32,32);
			}
		}
		else
		{
		   iShowBMP(enm4.enm_x,enm4.enm_y,"pictures/enemy43.bmp");
	       enm4.flag=1;
		   if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm4.enm_x,enm4.enm_y,32,32);
			}

		}
		if(enm4.eye==1)
		{
			if(enm4.eyeflag==1)
			{
                iShowBMP(enm4.enm_x,enm4.enm_y,"pictures/eye1.bmp");
		        enm4.eyeflag=0;
			}
			else
			{
                iShowBMP(enm4.enm_x,enm4.enm_y,"pictures/eye2.bmp");
		        enm4.eyeflag=1;
			}
		}
	}
	else
	{
		if(enm4.flag==1)
		{
	       	iShowBMP(enm4.enm_x,enm4.enm_y,"pictures/enemy42.bmp");
		    enm4.flag=0;
			if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm4.enm_x,enm4.enm_y,32,32);
			}
		}
		else
		{
		   iShowBMP(enm4.enm_x,enm4.enm_y,"pictures/enemy43.bmp");
	       enm4.flag=1;
		   if(enem_control==1)
			{
				iSetColor(135,206,250);
                iFilledRectangle(enm4.enm_x,enm4.enm_y,32,32);
			}
		}
		if(enm4.eye==1)
		{
			if(enm4.eyeflag==1)
			{
                iShowBMP(enm4.enm_x,enm4.enm_y,"pictures/eye1.bmp");
		        enm4.eyeflag=0;
			}
			else
			{
                iShowBMP(enm4.enm_x,enm4.enm_y,"pictures/eye2.bmp");
		        enm4.eyeflag=1;
			}
		}
	}
}

void food_initial()                    // food initialize for all function
{
	int i,j;

	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
            if (alevel[0][i][j]==1) total[0][i][j]=0;
			else total[0][i][j]=3;
			if(i==7 && j>=0 && j<=3) total[0][i][j]=0;
			if(i==7 && j>=17 && j<=20) total[0][i][j]=0;
			if(i==11 && j>=0 && j<=3) total[0][i][j]=0;
			if(i==11 && j>=17 && j<=20) total[0][i][j]=0;

			if (alevel[1][i][j]==1) total[1][i][j]=0;
			else total[1][i][j]=3;

			if (alevel[2][i][j]==1) total[2][i][j]=0;
			else total[2][i][j]=3;
		}
	}
}

void complete_initial()                // complete initialization
{
	int i=0;

	live_point=4;
	point=0;
	point_level=0;
	level=0;
	level_copelete=-1;
	total_initial();
	Pause_timer();
	initial_timer();
	food_initial();
}

void iDraw()                     
{
	iClear();

	switch(display)
	{
	case -1:
		//PlaySound("sounds/Assmau-Allah_006.wav",NULL,SND_ASYNC);
         iWindow1();
		 Pause_timer();
		 iResumeTimer(4);
		 break;
	case 0:
		complete_initial();
		start_display1();
		Pause_timer();
		break;
	case 1:
    //	PlaySound("sounds/mellmen.wav",NULL,SND_ASYNC);
		Pause_timer();
		if(level_copelete==10)
		{
			score_show();
		if(welcome%4==0) iSetColor(255,255,0);
		else iSetColor(2,0,255);

		iText(pic_x1+140,pic_y1+150,"CLICK HERE TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+141,pic_y1+150,"CLICK HERE TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+142,pic_y1+150,"CLICK HERE TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+143,pic_y1+150,"CLICK HERE TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if(level_copelete==11)
		{
			iShowBMP(200,25,"pictures/optionmanu.bmp");
			if(welcome%4==0) iSetColor(255,255,0);
		    else iSetColor(2,0,255);

		iText(pic_x1+140,pic_y1+150,"CLICK HERE TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+141,pic_y1+150,"CLICK HERE TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+142,pic_y1+150,"CLICK HERE TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(pic_x1+143,pic_y1+150,"CLICK HERE TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);		
		}
		else if(level_copelete==12)
		{
			iShowBMP(200,25,"pictures/about.bmp");
				if(welcome%4==0) iSetColor(255,255,0);
	        	else iSetColor(2,0,255);
	        	iText(pic_x1+140,pic_y1+150,"CLICK HERE TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
	        	iText(pic_x1+141,pic_y1+150,"CLICK HERE TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
	        	iText(pic_x1+142,pic_y1+150,"CLICK HERE TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
	        	iText(pic_x1+143,pic_y1+150,"CLICK HERE TO NEXT",GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else
		{
            start_display2();
		}
		break;
	case 2:
		if(level_copelete==1 || level_copelete==3 || level_copelete==7)
		{
	    	level_ok();
			PlaySound("sounds/Assmau-Allah_006.wav",NULL,SND_ASYNC);
		}
		else if(level_copelete==9)
		{
			pause_game();
		}
		else
		{
		Resume_timer();
        level_1();
		iWindow3();
		pacmanlevel_1();
		point_count();
		food();
		special_food();
		enemy_draw();
		level_initial();
		}

		break;
	case 3:
        if(level_copelete==5)
		{
	    	level_ok();
		}
	    else if(level_copelete==0)
		{
	    	display=0;
		}
		else
		{
		    iWindow4();
			level_copelete=8;
		}
		break;
	}
	
	welcome_change();
}

/*
	function iPassiveMouseMove() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/

void iPassiveMouseMove(int mx,int my)
{
	//place your codes here
}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}
/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   //to show start_display2
	{
	    if(display==0)
		{
			PlaySound("sounds/select.wav",NULL,SND_ASYNC);
			display=1;
			Resume_timer();
		}
		if(level_copelete==1)
		{
			level_copelete=2;
			Resume_timer();
			total_initial();
		}
		else if(level_copelete==3)
		{
			level_copelete=4;
			Resume_timer();
			total_initial();
		}
	    else if(level_copelete==5)
		{
			Pause_timer();
			level_copelete=6;
		}
		else if(level_copelete==7)
		{
			Pause_timer();
			display=3;
		}
		else if(level_copelete==8)
		{
			Pause_timer();
			level_copelete=0;
		}
		if(level_copelete==10)
		{
			Pause_timer();
			level_copelete=0;
		}
		else if(level_copelete==11)
		{
			Pause_timer();
			level_copelete=0;
		}
		else if(level_copelete==12)
		{
			Pause_timer();
			level_copelete=0;
		}
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
        if(mx>=516 && mx<=772 && my>=346 && my<=394)     //procede to new game
		{
			if(display==1)
			{
				PlaySound("sounds/select.wav",NULL,SND_ASYNC);
				display=2;
				level_copelete=20;
		    	Resume_timer();
			}
		}
		if(mx>=516 && mx<=772 && my>=146 && my<=194)      //exit
		{
	    	if(display==1)
			{
				PlaySound("sounds/select.wav",NULL,SND_ASYNC);
				exit(0);
			}
		}
		if(mx>=pic_x1+100 && mx<=pic_x1+356&& my>=pic_y1-250 && my<=pic_y1-202)      
		{
	    	if(display==1)
			{
				level_copelete=10;
			}
		}
		if(mx>=120&& mx<=220&& my>=600 && my<=650)     
		{
	    	if(display==2)
			{
				level_copelete=9;
				Pause_timer();
			}
		}
		if(mx>=510&& mx<=690&& my>=450 && my<=500)     
		{
	    	if(display==2 && level_copelete==9)
			{
				level_copelete=0;
				Resume_timer();
			}
		}
		else if(mx>=510&& mx<=690&& my>=350 && my<=400)      
		{
	    	if(display==2 && level_copelete==9)
			{
				display=1;
				complete_initial();
			}
		}
		else if(mx>=pic_x1+100&& mx<=pic_x1+356&& my>=pic_y1-200 && my<=pic_y1-152)     
		{
	    	if(display==1)
			{
				level_copelete=11;
			}
		}
		else if(mx>=pic_x1+100&& mx<=pic_x1+356&& my>=pic_y1-300 && my<=pic_y1-252)    
		{
	    	if(display==1)
			{
				level_copelete=12;
			}
		}
	}
}
/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
	int i;

	if(display==-1)
	{
		PlaySound("sounds/select.wav",NULL,SND_ASYNC);

		if(key=='\r')
		{
			username[name_len]='\0';
			strcpy(player_cur.name,username);
			name_len=0;
			for(i=0;i<strlen(username);i++)
			{
	            username[i]='\0';
			}
			printf("\n%s\n",username);
			display=0;
		}
		else if(key=='\b')
		{
			name_len--;
			username[name_len]='\0';
		}
		else
		{
			username[name_len]=key;
			printf("%s :%d\n",username,name_len);
            name_len++;
		}
	}
	else if(display==0)
	{
		press_any_key(key);
	}
}
/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if(key==GLUT_KEY_HOME)
	{
		if(display==2)
			{
				level_copelete=9;
				Pause_timer();
			}
	}
	if(alevel[level][pacn.lin][pacn.len]==0)
	{
              if(pacn.x==pic_x1-48+pacn.len*32 && pacn.y==pic_y1+144-pacn.lin*32)
			  {

				if(key == GLUT_KEY_LEFT)
				{
				     pacn.dx=inc;
				     pacn.move=3;
					 pacn.rotate=1;
					 if(alevel[level][pacn.lin][pacn.len-1]==1)
					 {
						 pacn.dx=0;
					 }
				}
            	if(key == GLUT_KEY_RIGHT)
				{
					pacn.dx=inc;
					pacn.move=1;
					pacn.rotate=0;
					if(alevel[level][pacn.lin][pacn.len+1]==1)
					{
						pacn.dx=0;
					}
				}
             	if(key == GLUT_KEY_UP)
				{
					pacn.dy=inc;
					pacn.move=2;
					pacn.rotate=2;
					if(alevel[level][pacn.lin-1][pacn.len]==1)
					{
						pacn.dy=0;
					}
				}
            	if(key == GLUT_KEY_DOWN)
				{
					pacn.dy=inc;
					pacn.move=4;
					pacn.rotate=3;
					if(alevel[level][pacn.lin+1][pacn.len]==1)
					{
						pacn.dy=0;
					}
				}
			   }
			}
}
void maze()
{
	int i,j,k;
    fmaze=fopen("maze.txt","r") ;

	 for(k=0;k<3;k++)
	 {
	 	for(i=0;i<21;i++)
	 	{
	 		for(j=0;j<21;j++)
	 	{
	 		fread(&alevel[k][i][j],sizeof(int),1,fmaze);
	 	}
	 	}
	 }
	 fclose(fmaze); 
}

void dijstra_read()
{
	int i,j,k;

	fedge=fopen("dijstra_level.txt","r") ;

	 for(k=0;k<3;k++)
	 {
	 	for(i=0;i<205;i++)
	 	{
	 		for(j=0;j<205;j++)
	 	{
	 		fread(&edge[k][i][j],sizeof(int),1,fedge);
	 	}
	 	}
	 }
}
int main()
{
    maze();
	food_initial();
    dijstra_read();

	pic_x1=416;
	pic_y1=496;

	total_initial();
    initial_timer();
	
	iSetTimer(pac_timer,pacman_change);
	iSetTimer(level1_timer,pacman_enem);
	iSetTimer(level2_timer,pacman_enem);
	iSetTimer(level3_timer,pacman_enem);

	iInitialize(1350,690, "PACMAN made by MD HABIBULLAH BIN ISMAIL");
	return 0;
}
