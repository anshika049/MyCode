#include<stdio.h>


char tic[3][3]={'1','2','3','4','5','6','7','8','9'};
void disp()
{
  int i,j;
   for(i=0;i<3;i++)
   {
       printf("\n\n");
	for(j=0;j<3;j++)
	{
			printf("%5c",tic[i][j]);
	}
   }
}
void assign(int p,char ch)
{
	switch(p)
	{
		case 1:
		tic[0][0]=ch;
		break;

		case 2:
		tic[0][1]=ch;
		break;

		case 3:
		tic[0][2]=ch;
		break;

		case 4:
		tic[1][0]=ch;
		break;

		case 5:
		tic[1][1]=ch;
		break;

		case 6:
		tic[1][2]=ch;
		break;

		case 7:
		tic[2][0]=ch;
		break;

		case 8:
		tic[2][1]=ch;
		break;

		case 9:
		tic[2][2]=ch;
		break;
	}


}
int v(int p)
{
	switch(p)
	{
		case 1:
		if(tic[0][0] !='1')
		return 0;
		else
		return 1;

		case 2:
		if(tic[0][1] !='2')
		return 0;
		else
		return 1;

		case 3:
		if(tic[0][2] !='3')
		return 0;
		else
		return 1;

		case 4:
		if(tic[1][0] !='4')
		return 0;
		else
		return 1;

		case 5:
		if(tic[1][1] !='5')
		return 0;
		else
		return 1;

		case 6:
		if(tic[1][2] !='6')
		return 0;
		else
		return 1;

		case 7:
		if(tic[2][0] !='7')
		return 0;
		else
		return 1;

		case 8:
		if(tic[2][1] !='8')
		return 0;
		else
		return 1;

		case 9:
		if(tic[2][2] !='9')
		return 0;
		else
		return 1;
   }
}
int win()
{      // row 1
	if((tic[0][0]==tic[0][1])&&(tic[0][0]==tic[0][2]))
	{
		return 1;
	}
		// condition 2
	else if((tic[1][0]==tic[1][1])&&(tic[1][0]==tic[1][2]))
	{
		return 1;
	}
	else if((tic[2][0]==tic[2][1])&&(tic[2][0]==tic[2][2]))
	{
		return 1;
	}

}
int fill()
{
	if(tic[0][0]=='1'|| tic[0][1]=='2'||tic[0][2]=='3'
	||tic[1][0]=='4'||tic[1][1]=='5'||tic[1][2]=='6'
	||tic[2][0]=='7'||tic[2][1]=='8'||tic[2][2]=='9')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
   int p,i=1,u=1,r=0;

   while(1)
   {
   
    disp();
    r=0;
    printf("\n\n Enter the position");

    while(r==0)
    {
     scanf("%d",&p);
     r=v(p);
    }
    if(u==1)
    {
     int k;
     assign( p,'X');
     k=win();
     if(k==1)
     {
	break;
     }
      u++;
    }
    else
    {
     int k;
     assign( p,'O');
     k=win();
     if(k==1)
     {
	break;
     }
     u--;
    }
    i++;
    if(i==9)
    {
      u=3;
      break;

    }
   }
 
   disp();
   if(u==1)
   {
      printf("\n\n 1st user won");
   }
   else if(u==2)
   {
      printf("\n\n 2nd user won");
   }
   else
   {
      printf("\n\n Both won");
   }

 return 0; 
}