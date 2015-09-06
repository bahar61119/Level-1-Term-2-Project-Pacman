typedef struct {
	char name[40];
	long int score;
}user;

typedef struct {
	int predecessor;
	int distance;
	int mark;
}vertexinfo;

struct pacman{
	int x;
	int y;
	int len;
	int lin;
	int dx;
	int dy;
	int rotate;
	int mode1;
	int mode2;
	int count1;
	int count2;
	int move;
	int bit;
}pacn;

typedef struct{
	int enm_x;
	int enm_y;
	int elen;
	int elin;
	int edx;
	int edy;
	int pac_enm;
	int flag;
	int eye;
	int emode1;
	int emode2;
	int ecount1;
	int ecount2;
	int count;
	int eyeflag;
	int node[21][21];
}enm;

typedef struct{
	int len;
	int lin;
	int flag;
	int spflag;
	int count;

}sp;