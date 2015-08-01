#include "include.h"

char ac_2[]="call \n";
char ac_3[]="raise100 \n";
char ac_4[]="all_in \n";
char ac_5[]="fold \n";
int steps=0;			/* Data_init */
int ac=0; 
int error=0;
int money=0;

char color[7][10];
char point[7][10];
char bet[7][10];
int pointInt[7][1];
int betInt[7];
int betInt_max=0;
int m=0;
int member_count=0;

void Data_init()        	/* Data_init */ 
{  
  int i=0,j=0;
  for(i=0;i<7;i++)
  {
    for(j=0;j<10;j++)
    {
      color[i][j]='\0';
      point[i][j]='\0';
      bet[i][j]='\0';
    }
    pointInt[i][0]=0;
  }
  for(i=0;i<7;i++)
  betInt[i]=0;
  betInt_max=0;
  ac=0;
  m=0;
  member_count=0;
  money=0;
}

void bet_Data_init(){		/* bet init */
  int i=0,j=0;
  for(i=0;i<7;i++)
  {
    for(j=0;j<10;j++)
    {
      bet[i][j]='\0';
    }
    pointInt[i][0]=0;
  }
  for(i=0;i<7;i++)
  betInt[i]=0;
  betInt_max=0;
}

int my_money(char *s)
{
  int a=0,b=0,c=0;//a:回车标志 b:空格标志 
  int pa=0,i=0,d=1;
  char id[10],my_money[10];
  int money=0;
  int p=0;
  while(s[pa]!='\n')
  pa++;
  a++;
  while(a)
  {
    if(a<=3 && c==0)
    {
      while(s[pa]!=':')
        pa++;
      pa+=2;
      c++;
    }
    if(s[pa]==' ')
      {	b++; pa++;}
    if(b==3)
      pa--;
    if(b==0 && p==0)
    {
      id[i]=s[pa];
      id[i+1]='\0';
      i++;
    }
    else if(b==1 && p==0)
    {
      if((strcmp(id,my_id_s)==0))
      {
       i=0;
       p=1;
       while(s[pa]!=' ')
       {
         my_money[i]=s[pa];
         my_money[i+1]='\0';
         i++;
         pa++;
       }
       pa--;
       while(i)
       {
         money+=(my_money[i-1]-48)*d;
         d*=10;
         i--;
       }
     }
   }
   pa++;
   if(s[pa]=='\n')
   {
    a++;
    b=0;
    i=0;
    c=0;
    if(a>3)
      pa++;
  }
  if(s[pa]=='/')
    break;
}
member_count=a-1;
return(money);
}

void inquire_explain(char *s)
{
  int a=0;//a用于标志牌子信息开始，b表示遇到的空格个数
  int b=0;
  int pa=0;
  int i=0;
  int j=0;
  int temp=0;
  int k=0;
  while(1)
  {
    if(s[pa]=='\n')
    {
      i=0;
      a=1;
      b=0;
      pa++;
      k++;
    }
    if(a==1 && s[pa]=='/')
    {
      k--;
    break;//到达包尾，跳出循环
  }
  else if(a==1 && s[pa]!='/')
  {
    if(s[pa]==' ')
    {
     b++;
	i=0;//遇到空格b加1，i置零
}
if(s[pa]!=' '&&b==3)
{
	bet[k-1][i]=s[pa];
	bet[k-1][i+1]='\0';
	i++;
}
  }//end if
  pa++;
    }//end while

    for(i=0;i<7;i++)
      betInt[i]=atoi(bet[i]);

    for(i=0;i<6;i++)
      for(j=i+1;j<7;j++)
      {
        if(betInt[i]<betInt[j])
        {
          temp=betInt[i];
          betInt[i]=betInt[j];
          betInt[j]=temp;
        }
      }

      betInt_max=betInt[0];

}//end inquire_explain

void card_explain(char *s)
{
  int a=0;//a用于标志牌子信息开始，b表示遇到的空格个数
  int b=0;
  int pa=0;
  int i;
  while(1)
  {
    if(s[pa]=='\n')
    {
      i=0;
      a=1;
      b=0;
      pa++;
      m++;
    }
    if(a==1 && s[pa]=='/')
    {
      m--;
    break;//到达包尾，跳出循环
  }
  else if(a==1 && s[pa]!='/')
  {
    if(s[pa]==' ')
    {
     b++;
	i=0;//遇到空格b加1，i置零
}
if(s[pa]!=' '&&b==0)
{
	color[m-1][i]=s[pa];
	color[m-1][i+1]='\0';
	i++;
}
else if(s[pa]!=' '&&b==1)
{
	point[m-1][i]=s[pa];
	point[m-1][i+1]='\0';
	i++;
}
  }//end if
  pa++;
    }//end while
}//end card_explain

void Char2Int(){
  int i;
  for (i=0; i<5; i++) {
    pointInt[i][0] = point[i][0] - '0';
    if(point[i][0]=='1')
      pointInt[i][0]=10;
    else if(point[i][0]=='J')
      pointInt[i][0]=11;
    else if(point[i][0]=='Q')
      pointInt[i][0]=12;
    else if(point[i][0]=='K')
      pointInt[i][0]=13;
    else if(point[i][0]=='A')
      pointInt[i][0]=14;
  }
}

void sort(int length){
  Char2Int();
  int i,j;
  for (i = 0; i < length; i++) {
    for (j = i; j< length; j++) {
      int tmp = pointInt[i][0];
      if (pointInt[i][0]>pointInt[j][0]) {
        tmp = pointInt[i][0];
        pointInt[i][0] = pointInt[j][0];
        pointInt[j][0] = tmp;
      }
    }
  }
}

int hold_strategy_1(){
  Char2Int();
  if(pointInt[0][0]==pointInt[1][0]&&pointInt[0][0]>7&&pointInt[1][0]>7)
    return 1;
  else if(pointInt[0][0]>9&&pointInt[1][0]>9&&color[0][0]==color[1][0])
    return 1;
  else if((pointInt[0][0]==14||pointInt[1][0]==14)&&pointInt[0][0]>11&&pointInt[1][0]>11)
    return 1; 
  else
    return 0;
}

int hold_strategy_2(){
  Char2Int();
  if(pointInt[0][0]==pointInt[1][0]&&pointInt[0][0]>2&&pointInt[1][0]>2)
    return 1;
  else if(pointInt[0][0]>3&&pointInt[1][0]>3&&color[0][0]==color[1][0])
    return 1;
  else if((pointInt[0][0]>11||pointInt[1][0]>11)&&pointInt[0][0]>4&&pointInt[1][0]>4)
    return 1; 
  else
    return 0;
}

int strategy_1()		/* 同花 */
{
  int i=0;
  int j_a=0;
  int j_b=0;
  char char_a=NULL;
  char char_b=NULL;

  if(color[0][0]==color[1][0])
    char_a=color[0][0];
  else if(color[2][0]==color[3][0])
    char_b=color[2][0];

  for(i=0;i<=4;i++)
  {
    if(color[i][0]==char_a)
      j_a++;
    else if(color[i][0]==char_b)
      j_b++;
  }

  if(j_a>=4||j_b>=4)
    return 1;
  else
    return 0;
}


int strategy_2()		/* 3同 */
{
  char char_a=NULL;
  char char_b=NULL;
  char char_c=NULL;
  int i=0;
  int j_a=0;
  int j_b=0;
  int j_c=0;

  char_a=point[0][0];
  char_b=point[1][0];
  char_c=point[2][0];

  for(i=0;i<=4;i++)
  {
    if(point[i][0]==char_a)
      j_a++;
    else if(point[i][0]==char_b)
      j_b++;
    else if(point[i][0]==char_c)
      j_c++;
  }

  if(j_a>=3||j_b>=3||j_c>=3)
    return 1;
  else
    return 0;
}

int strategy_3(){   //1对
  int i=0,j=0;
  int flag = 0;
  Char2Int();
  for (i=0;i<5;i++) {
    for (j=i+1;j<5;j++) {
      if (pointInt[j][0] == pointInt[i][0]) {
        flag ++ ;
}//end if
else
  continue;
    }//end infor
  }//end outfor
  if (flag >= 1) {
    return 1;
  }else
  return 0;
}

int strategy_4(){//  顺子
  int i;
  sort(5);
  for (i=1; i<5; i++) {
    if (pointInt[i][0] - pointInt[i-1][0] != 1) {
      break;
    }//end if
  }//end for
  if (i>= 5) {
    return 1;
  }else
  return 0;
}

int strategy()
{
  if(strategy_1()==1||strategy_2()==1||strategy_3()==1||strategy_4()==1)
    return 1;
  else
    return 0;
}