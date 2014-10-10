#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

 void call_random_bloc(char out_screen[][23]);
 void input_bloc_element(int,int);
 int touched(char out_screen[][23]);
 void check_game_over(char out_screen[][23]);
 void show_screen(char out_screen[][23]);
 void down_bloc(char out_screen[][23]);
 void left(char out_screen[][23]);
 void right(char out_screen[][23]);

 char out_screen[23][23];
 int numb=0,mode=0;
 int down_y=0,county=0,countx=11; /*countxについては初期値は１１に設定しておく*/
 int y=0,x=0,out_count=0;
 
 int main(void)
{
 signal(SIGINT,(void *)left);
 signal(SIGTSTP,(void *)right);

 /*変数の定義*/
 FILE *fd_long,*fd_right,*fd_left,*fd_carre;
 char c,long_bloc[4][1],right_bloc[3][2],left_bloc[3][2],carre_bloc[2][2];

 /* フレームを作成*/
 for(y=0;y<23;y++){
  for(x=0;x<23;x++){
   if(y==0 || y==22){
    out_screen[y][x]='*';
   }
   else{
    if(x==0 || x==22){
     out_screen[y][x]='*';
    }
    else{
     out_screen[y][x]=' ';
    }
   }
  }
 }
  
 /*ファイルを開く*/
 fd_long=fopen("components/long_bloc","r");
 fd_right=fopen("components/right_bloc","r");
 fd_left=fopen("components/left_bloc","r");
 fd_carre=fopen("components/carre","r");

 /*エラーチェック*/
 if(fd_long==NULL){
     printf("file open error");
     exit(1);
 }
 if(fd_long==NULL){
     printf("file open error");
     exit(1);
 }
 if(fd_long==NULL){
     printf("file open error");
     exit(1);
 }
 if(fd_long==NULL){
     printf("file open error");
     exit(1);
 }

 /*ファイルから形状を読み込む*/
        /* long_bloc */
  x=0,y=0;
         while(c!=EOF){
  c=fgetc(fd_long);
  /*if(c!=EOF){*/
   if(c!='\n'){
    long_bloc[y][x]=c;
    x++;
  }

  if(c=='\n'){
    x=0;
    y++;
   }
 }
 x=0;
 y=0;
	/*
	for(y=0;y<2;y++){
	 for(x=0;x<2;x++){
	  printf("%c",long_bloc[y][x]);
	 }
	 printf("\n");
	}
 printf("ji\n");
 printf("ji\n");
	*/
        /* right?bloc */
         while(c!=EOF){
  c=fgetc(fd_right);
  /*if(c!=EOF){*/
   if(c!='\n'){
    right_bloc[y][x]=c;
    x++;
  }

  if(c=='\n'){
    x=0;
    y++;
   }
 }
 x=0;
 y=0;
	/*
	for(y=0;y<3;y++){
	 for(x=0;x<2;x++){
	  printf("%c",long_bloc[y][x]);
	 }
	 printf("\n");
	}
 printf("ji\n");
 printf("ji\n");
	*/
        /* left_bloc */
         while(c!=EOF){
  c=fgetc(fd_left);
  /*if(c!=EOF){*/
   if(c!='\n'){
    left_bloc[y][x]=c;
    x++;
  }

  if(c=='\n'){
    x=0;
    y++;
   }
 }
x=0;
y=0;
	/*
	for(y=0;y<3;y++){
	 for(x=0;x<2;x++){
	  printf("%c",long_bloc[y][x]);
	 }
	 printf("\n");
	}
 printf("ji\n");
 printf("ji\n");
	*/
        /* carre_bloc */
         while(c!=EOF){
  c=fgetc(fd_carre);
  /*if(c!=EOF){*/
   if(c!='\n'){
    carre_bloc[y][x]=c;
    x++;
  }

  if(c=='\n'){
    x=0;
    y++;
   }
 }
x=0;
y=0;
	/*
	for(y=0;y<2;y++){
	 for(x=0;x<2;x++){
	  printf("%c",long_bloc[y][x]);
	 }
	 printf("\n");
	}
 printf("ji\n");
 printf("ji\n");
	*/
 /*４つのファイルを閉じる*/
 /* game bubun */
 while(1){
  call_random_bloc();
 /*
  while(county<20){
   if(touched()!=0){
    show_screen();
    down_bloc();
    sleep(1);
   }
  printf("ji\n");
  }
  x=0;
  y=0;
  numb=0;
  down_y=0;
  county=0;
 */
 }
 exit(1);
 fclose(fd_long);
 fclose(fd_right);
 fclose(fd_left);
 fclose(fd_carre);
 exit(1);
 /*ブロックを標示*/
	/* long */
	for(y=0;y<4;y++){
	 for(x=0;x<1;x++){
	  printf("%c",long_bloc[y][x]);
	 }
	 printf("\n");
	}
	/* right */

	for(y=0;y<3;y++){
	 for(x=0;x<2;x++){
	  printf("%c",long_bloc[y][x]);
	 }
	 printf("\n");
	}
	/* left */
	for(y=0;y<3;y++){
	 for(x=0;x<2;x++){
	  printf("%c",long_bloc[y][x]);
	 }
	 printf("\n");
	}
	/* carre */
	for(y=0;y<2;y++){
	 for(x=0;x<2;x++){
	  printf("%c",long_bloc[y][x]);
	 }
	 printf("\n");
	}

 return;
}


void call_random_bloc(/*char out_screen[][23]*/void)
{
 /* 乱数を発生させ、ブロックを呼び出す。*/
 srand(time(NULL));
 numb=rand()%3;
 /*発生したブロックをoutput_screen変数に、bloc_inity(x)から格納していく*/
 switch(numb){
  case 0:
         input_bloc_element(4,1);
         break;
  case 1:
         input_bloc_element(3,2);
         break;
  case 2:
         input_bloc_element(3,2);
         break;
  case 3:
         input_bloc_element(2,2);
         break;

 }
    show_screen();
    down_bloc();
    county=0;
 return;
}

void input_bloc_element(int iniy,int inix)
{
 int this_y,this_x;
 int y,x;
 switch(numb){
 /* long を初期位置に配置*/
  case 0:
  for(this_y=1;this_y<5;this_y++){
   for(this_x=11;this_x<12;this_x++){
    out_screen[this_y][this_x]='*'; 
   }
  }
  break;
 /* right を初期位置に配置*/
  case 1:
  for(this_y=1;this_y<4;this_y++){
   for(this_x=11;this_x<13;this_x++){
    out_screen[this_y][this_x]='*'; 
   }
  }
  /*
  show_screen(out_screen);
  exit(1);
  */
  break;
 /* left を初期位置に配置*/
  case 2:
  for(this_y=1;this_y<4;this_y++){
   for(this_x=11;this_x<13;this_x++){
    out_screen[this_y][this_x]='*'; 
   }
  } 
  /*
  show_screen(out_screen); 
  exit(1);
  */
  break;
 /* carre を初期位置に配置*/
  case 3:
  for(this_y=1;this_y<3;this_y++){
   for(this_x=11;this_x<13;this_x++){
    out_screen[this_y][this_x]='*'; 
   }
  }
  /*
  show_screen(out_screen);
  exit(1);
  */
  break;
 }
 return;
}

 int touched(/*char out_screen[][23*/ void)
{
 switch(numb){
  case 0:
	/*
	 printf("%d  numb %d\n",county+2,numb);
	 exit(1);
	 */
	 for(x=1;x<22;x++){
	  printf(" x county  y%d %d %d \n",x,county,y);
	  if(out_screen[county+4][x]=='*'){
	   return 1;
	  }
	 }
	 break;
  case 1:
	 /*
	 printf("%d numb %d\n",county+2,numb);
	 exit(1);
	*/ 
	 for(x=1;x<22;x++){
	  printf(" x county  y%d %d %d \n",x,county,y);
	  if(out_screen[county+3][x]=='*' || out_screen[county+3][x+1]=='*'){
	   return 1;
	  }
	 }
	 break;
  case 2: 
	/*
	 printf("%d numb %d\n",county+2,numb);
	 exit(1);
	 */
	 for(x=1;x<22;x++){
	  printf(" x county  y%d %d %d \n",x,county,y);
	  if(out_screen[county+3][x]=='*' || out_screen[county+3][x+1]){
	   return 1;
	  }
	 }
	 break;
  case 3: 
	/*	
	 printf("%d numb %d \n",county+2,numb);
	 exit(1);
	*/
	 for(x=1;x<22;x++){
	  printf(" x county  y%d %d %d \n",x,county,y);
	  if(out_screen[county+2][x]=='*' || out_screen[county+2][x+1]=='*'){
	   return 1;
	  }
	 }
	 break;
 }

 return 0;
}

 void down_bloc(/*char out_screen[][23]*/void)
{
 /* ブロックの現在地から一つ上の行を削除*/
 switch(numb){
  /* long------------------------------------- */
  /* long------------------------------------- */
  case 0:
 /* 表示　　ゲームオーバー判定 接触判定*//*フレームの深さを指定*/
 while(county<19){
 /*移動跡を消す*/
 for(y=1+county-1;y<4+county;y++){
  for(x=11;x<12;x++){
   out_screen[y][x]=' ';
  }
 }
 /*移動する*/
 for(y=1+county;y<5+county;y++){
  for(x=11;x<12;x++){
   out_screen[y][x]='*';
  }
 }
	/*表示部*/
 show_screen();
  /* gameover hantei */
  check_game_over();
  county++;
  sleep(1);
 /*  接触判定*/
  if(touched()==1){
   county=0;
   call_random_bloc();
  }
 }
 break;
 /* right -------------------------------------*/
  case 1:
 for(y=1+county-1;y<3+county; y++){
  for(x=11;x<13;x++){
   out_screen[y][x]=' ';
  }
 }

 for(y=1+county;y<4+county;y++){
  for(x=11;x<13;x++){
   out_screen[y][x]='*';
  }
 }
 /* 表示　　ゲームオーバー判定 接触判定*/
  show_screen();
  /* gameover hantei */
  check_game_over();
  county++;
  sleep(1);
 /*  接触判定*/
  if(touched()==1){
  /*接触したら次のブロックの動作に移る、その際ブロックの位置を覚えておく変数を初期化する。*/
   county=0;
   countx=11;
   call_random_bloc();
  }
 break;
 /* legt -------------------------------------*/
  case 2:
 for(y=1+county-1;y<3+county; y++){
  for(x=11;x<13;x++){
   out_screen[y][x]=' ';
  }
 }

 for(y=1+county;y<4+county;y++){
  for(x=11;x<13;x++){
   out_screen[y][x]='*';
  }
 }
 /* 表示　　ゲームオーバー判定 接触判定*/
 show_screen();
  /* gameover hantei */
  check_game_over();
  county++;
  sleep(1);
 /*  接触判定*/
  if(touched()==1){
   county=0;
   call_random_bloc();
  }
 break;
 /* carre -------------------------------------*/
  case 3:
 for(y=1+county-1;y<2+county; y++){
  for(x=11;x<13;x++){
   out_screen[y][x]=' ';
  }
 }

 for(y=1+county;y<3+county;y++){
  for(x=11;x<13;x++){
   out_screen[y][x]='*';
  }
 }
 /* 表示　　ゲームオーバー判定 接触判定*/
 show_screen();
  /* gameover hantei */
  check_game_over();
  county++;
  sleep(1);
 /*  接触判定*/
  if(touched()==1){
   county=0;
   call_random_bloc();
  }
 break;
 }

 return; 
}

 void show_screen(/*char out_screen[][23]*/void)
{
 printf("x %d y %d\n",x,y);
 /*
 if(mode==1){
  exit(1);
 }
 */
 for(y=0;y<23;y++){
   for(x=0;x<23;x++){
 if(mode==1){
 printf("x %d y %d\n",x,y);
 }
    printf("%c",out_screen[y][x]);
        if(mode==1){
	exit(1);
	}
   }
   printf("\n");
 }
 if(mode==1){
  printf("left desu \n");
  printf("left desu \n");
  printf("left desu \n");
  printf("left desu \n");
  exit(1);
 }
 return;
}

 void check_game_over(/*char out_screen[][23]*/void)
{
 out_count=0;
  for(x=1;x<22;x++){
   /*一行ずつ確認,一つの行に10以上 * があればゲームおーば０*/
   /* この高さ＝while(x<23)の部分の値である。*/
   for(y=1;y<22;y++){
    if(out_screen[y][x]=='*'){
     out_count++;
    }
   }
   if(out_count>20){
    printf("gameover\n");
    exit(1);
   }
   out_count=0;
  }

 return;
}

 void right(/*char out_screen[][23]*/void)
{
 int this_y,this_x;

 printf(" county  %d countx %d \n",county,countx); 
 switch(numb){
  case 0:
  /* 消す*/
  for(this_y=county;this_y<county+4;this_y++){
   for(this_x=countx;this_x<countx+1;this_x++){
    out_screen[this_y][this_x]=' ';
   }
  }
  /* 移動*/
  for(this_y=county;this_y<county+4;this_y++){
   for(this_x=countx-1;this_x<countx;this_x++){
    out_screen[this_y][this_x]='*';
   }
  }
  break;
  case 1:
  for(this_y=county;this_y<county+4;this_y++){
   for(this_x=countx;this_x<countx+1;this_x++){
    out_screen[this_y][this_x]=' ';
   }
  }

  for(this_y=county;this_y<county+4;this_y++){
   for(this_x=countx-1;this_x<countx;this_x++){
    out_screen[this_y][this_x]='*';
   }
  }
  break;
  case 2:
  for(this_y=county;this_y<county+4;this_y++){
   for(this_x=countx;this_x<countx+1;this_x++){
    out_screen[this_y][this_x]=' ';
   }
  }
  for(this_y=county;this_y<county+4;this_y++){
   for(this_x=countx-1;this_x<countx;this_x++){
    out_screen[this_y][this_x]='*';
   }
  }
  break;
  case 3:
  for(this_y=county;this_y<county+4;this_y++){
   for(this_x=countx;this_x<countx+1;this_x++){
    out_screen[this_y][this_x]=' ';
   }
  }

  for(this_y=county;this_y<county+4;this_y++){
   for(this_x=countx-1;this_x<countx;this_x++){
    out_screen[this_y][this_x]='*';
   }
  }
  break;
 }

 show_screen();
 return;
}

 void left(/*char out_screen[][23]*/void)
{
 int gen_y,gen_x;
 mode=1;
 /*左に移動するので-1する*/
 countx--;
 printf("left\n");
 printf(" county  %d countx %d \n",county,countx); 
 switch(numb){
  case 0:
  /* 消す*/
  fflush(stdin);
  show_screen();
   /* 今個々*/
    exit(1);
  for(gen_y=county;gen_y<county+3;gen_y++){
   for(gen_x=countx;gen_x<countx+2;gen_x++){
    out_screen[gen_y][gen_x]=' ';
   }
  }
  /* 移動*/
  for(gen_y=county;gen_y<county+4;gen_y++){
   for(gen_x=countx-1;gen_x<countx;gen_x++){
    out_screen[gen_y][gen_x]='*';
   }
  }
  break;
  case 1:
  /* 消す*/
  for(gen_y=county;gen_y<county+3;gen_y++){
   for(gen_x=countx;gen_x<countx+2;gen_x++){
    out_screen[gen_y][gen_x]=' ';
   }
  }
  /* 移動*/
  for(gen_y=county;gen_y<county+3;gen_y++){
   for(gen_x=countx-1;gen_x<countx;gen_x++){
    out_screen[gen_y][gen_x]='*';
   }
  }
  break;
  case 2:
  /* 消す*/
  for(gen_y=county;gen_y<county+4;gen_y++){
   for(gen_x=countx;gen_x<countx+1;gen_x++){
    out_screen[gen_y][gen_x]=' ';
   }
  }
  /* 移動*/
  for(gen_y=county;gen_y<county+4;gen_y++){
   for(gen_x=countx-1;gen_x<countx;gen_x++){
    out_screen[gen_y][gen_x]='*';
   }
  }
  break;
  case 3:
  /* 消す*/
  for(gen_y=county;gen_y<county+4;gen_y++){
   for(gen_x=countx;gen_x<countx+1;gen_x++){
    out_screen[gen_y][gen_x]=' ';
   }
  }
  /* 移動*/
  for(gen_y=county;gen_y<county+4;gen_y++){
   for(gen_x=countx-1;gen_x<countx;gen_x++){
    out_screen[gen_y][gen_x]='*';
   }
  }
  break;
 }

 show_screen();
 return;
}
