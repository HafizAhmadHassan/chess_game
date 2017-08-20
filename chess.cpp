#include<iostream>
#include<Windows.h>
#include<conio.h>

using namespace std;
int const COLSIZE=8;
int king(char arr[][8],int fr,int fc,int tr,int tc)
{

	if(tr==fr+1 && tc==fc || tr==fr-1 && tc==fc || tr==fr && tc==fc+1 || tr==fr && tc==fc-1 || tr==fr+1 && tc==fc+1 || tr==fr-1 && tc==fc-1 || tr==fr-1 && tc==fc+1 || tr==fr+1 && tc==fc-1 )

	{
		//	cout<<"000";
		return 1;
	}
	else
	return 0;

}

int knight(char arr[][8],int fr,int fc,int tr,int tc)
{

	if(arr[tr][tc]<91 && arr[tr][tc]>65 && arr[fr][fc]<91  &&  arr[fr][fc]>65 )
	{
		return 0;
	}
	if(arr[tr][tc]>=97 && arr[tr][tc]<=122 && arr[fr][fc]>=91 && arr[fr][fc]<=122)
	{
		return 0;
	}
	if(  tc==fc || tr==fr)
	{
		return 0;
	}

	if(tr==fr+2 && tc==fc+1 || tr==fr+2 && tc==fc-1 || tr==fr+1 && tc==fc+2 || tr==fr-1 && tc==fc+2 || tr==fr-2 && tc==fc+1 || tr==fr-2 && tc==fc-1 || tr==fr-1 && tc==fc-2 || tr==fr+1 && tc==fc-2)
	{
		return 1;
	}

	else
	return 0;
}

int bishop(char arr[][8],int p1,int p2,int d1,int d2)
{
	if(d1==p1 && d2==p2)
	{
		return false;
	}

	if( arr[p1][p2]=='\0')
	{
		return false;
	}

	//if(arr[d1][d2]<91 && arr[p1][p2]<91)
	//{/
	//	return false;
	//}
	//if(arr[d1][d2]>91 && arr[p1][p2]>91)
	//{
	//	return false;
	//}

	if(  d2==p2 || d1==p1)
	{
		return false;
	}

	int v=1;
	int c=1;
	if(d1<p1 && d2 <p2)
	{
		v=-1;
		c=-1;
	}
	if(d1>p1 && d2 >p2)
	{
		v=1;
		c=1;
	}
	if(d1<p1 && d2 >p2)
	{
		v=-1;
		c=1;
	}
	if(d1>p1 && d2 <p2)
	{
		v=1;
		c=-1 ; 
	}




	int i=p1+(v);int j=p2+(c);

	for( i,j;i<8 && i>=0 && j<8 && j>=0 ; i=i+(v),j=j+(c))
	{

		//if(arr[p1][p2]>91 && arr[d1][d2] >91 || arr[p1][p2]<91 && arr[d1][d2] <91 )
		//{
		//return false;
		//}


		if(arr[i][j]!='\0' && i!=d1 && j!=d2  )
		{

			return false;


		}


		if(i==d1 && j==d2 )

		{


			return true;

		}




	}

	return false;
}

int pawnmover(char arr[][8],int p1,int p2,int d1, int d2 ,bool pawnmove)
{
	//,,,,,,,,,,,,            an---passant 

	if(arr[p1][p2]=='P' && p1==4 && arr[p1][p2+1]=='p' && d1 == p1+1 && d2 ==p2+1 && arr[d1][d2]=='\0' )
	{
		//cout<<"0003";
		//Sleep(3500);
		arr[p1][p2+1]='\0';
		return true;
	}

	if(arr[p1][p2]=='P' && p1==4 && arr[p1][p2-1]=='p' && d1 == p1+1 && d2 ==p2-1 && arr[d1][d2]=='\0'  )
	{

		//	cout<<"0004";

		//		Sleep(3500);
		arr[p1][p2-1]='\0';
		return true;
	}

	//.......                    as--passant
	if(arr[p1][p2]=='p' && p1==3 && arr[p1][p2-1]=='P' && d1 == p1-1 && d2 ==p2-1 )
	{
		//	cout<<"0005";
		//Sleep(3500);
		arr[p1][p2-1]='\0';
		return true;
	}

	if(arr[p1][p2]=='p' && p1==3 && arr[p1][p2+1]=='P' && d1 == p1-1 && d2 ==p2+1 )
	{
		//cout<<"0006";

		//	Sleep(3500);
		arr[p1][p2+1]='\0';
		return true;
	}


	//.............

	//,,,,,,,,,,,,,,,,,,,,PAWN CAN TOO KILL


	if(p1+1 ==d1&& p2-1==d2 && arr[d1][d2]!='\0' && arr[p1][p2]=='P' )
	{
		//c/out<<"0007";
		///Sleep(3500);
		return true;
	}


	if(p1+1 ==d1&& p2+1==d2 && arr[d1][d2]!='\0' && arr[p1][p2]=='P')
	{
		//cout<<"0008";
		//Sleep(3500);

		return true;
	}

	if( p1-1 == d1  && p2-1==d2 && arr[d1][d2] !='\0' && arr[p1][p2]=='p')
	{
		//	cout<<"0009";
		//Sleep(3500);

		return true;
	}

	if(p1-1 == d1&& p2+1==d2 && arr[d1][d2]!='\0' && arr[p1][p2]=='P')
	{
		//cout<<"0011";
		//Sleep(3500);
		return true;
	}





	//avoid jumping
	if( arr[p1][p2]=='P'  && d1 == p1+2 &&  arr[p1+1][p2]!='\0'&& pawnmove==false || arr[p1][p2]=='p' && d1 == p1-2  && arr[p1-1][p2]!='\0'&& pawnmove==false)

	{
		//cout<<"0002";
		//Sleep(3500);
		return false;

	}

	// first move change
	if( arr[p1][p2]=='P'  && pawnmove==false && p1 +2==d1 && p2==d2  && arr[d1][d2] =='\0' ||
		arr[p1][p2]=='P'&& pawnmove==false && p1 +1==d1&& arr[d1][d2] =='\0' && p2==d2  ||
		arr[p1][p2]=='p'&& arr[d1][d2] =='\0' && pawnmove==false && p1 -1==d1&& p2==d2   ||
		arr[p1][p2]=='p' &&  pawnmove==false && p1 -2==d1&& arr[d1][d2] =='\0'&& p2==d2   )
	{

		//cout<<"0001";

		//Sleep(3500);
		return true;


	}


	if(pawnmove==true && p1  + 1 == d1 && arr[p1][p2]=='P'&& arr[d1][d2] =='\0'&&p2==d2  ||arr[p1][p2]=='p'  && pawnmove==true && p1 - 1 == d1 && arr[d1][d2] =='\0'&&p2==d2)
	{
		///	cout<<"0000";

		//	Sleep(3500);
		return true;

	}

	else return false;



}

int rook(char arr[][8],int p1,int p2,int d1,int d2)
{

	if(d1==p1&&d2==p2)
	{
		return false;
	}

	if( arr[p1][p2]=='\0')
	{
		return false;
	}
	/*	if(arr[d1][d2]>91 && arr[p1][p2]>91)
	{
	return false;
	}


	*/


	int c;int v;

	int i;int j;



	if(d1 >= 0 && d1<8 && d2==p2 || d2>=0 && d2<8 && d1==p1)
	{
		if(d1>p1 && d2==p2)
		{
			v= 1;
			c= 0;
		}
		if(d1<p1 && d2==p2)
		{
			v= -1;
			c= 0;
		}
		if(d1==p1 && d2>p2)
		{
			v= 0;
			c= 1;
		}
		if(d1==p1 && d2<p2)
		{
			v= 0;
			c= -1;
		}

		i=p1+(v);
		j=p2+(c);

		for( i,j;i<8 && i>=0 && j<8 && j>=0 ; i=i+(v),j=j+(c))
		{




			if( arr[i][j]!='\0' && i!=d1 && j==d2  || i==d1 && j!=d2 && arr[i][j]!='\0'  )
			{

				return false;


			}

			if(i==d1 && j==d2 )

			{


				return true;

			}




		}

	}	
	else return false;


}


int queen(char arr[][8],int fr,int fc,int tr,int tc)
{

	int b = bishop(arr,fr,fc,tr,tc);
	int r = rook(arr,fr,fc,tr,tc);
	if(b==1  || r== 1)
	{
		return 1;
	}
	else 
	
		return 0;
	
}

void promotionP( char arr[][8],int fr,int fc,int tr, int tc )
{
	char ch;
	if(arr[fr][fc]=='p' && fr==7){
		system ("cls");
		cout<<"slectect your choice ..";

		cout<<endl<<" Q for queen"<<endl<<"B for bisup "<<endl<< " R for rook"<<endl<<"T for knight"<<endl;


		cin>>ch;

		switch(ch)
		{
		case 'Q':
			arr[fr][fc]='Q';
			break;
		case 'B':
			arr[fr][fc]='B';
			break;
		case 'T':
			arr[fr][fc]='T';
			break;
		case 'R':
			arr[fr][fc]='R';
			break;


			system ("cls");
			
		}
	}
	
	
}

void promotionp(char arr[][8],int fr,int fc,int tr, int tc )
{
	if(arr[fr][fc]=='p' && fr==7 /*&& fc >=0 && fc <8 && tr==0 &&  tc>=0 && tc <8 && arr[tr][tc]=='\0'*/ )
	{
		char ch;
		system ("cls");
		cout<<"slectect your choice ..";

		cout<<endl<<" Q for queen"<<endl<<"B for bisup "<<endl<< " R for rook"<<endl<<"T for knight"<<endl;


		cin>>ch;

		switch(ch)
		{
		case 'q':
			arr[fr][fc]='q';
			break;
		case 'b':
			arr[fr][fc]='b';
			break;
		case 't':
			arr[fr][fc]='t';
			break;
		case 'r':
			arr[fr][fc]='r';
			break;


			system ("cls");
			
		}
	}
	

}

int Pawn(char arr[][COLSIZE],int fr,int fc,int tr,int tc)
{
	
    	if(fr==tr && fc==tc)
			return 0;
		//if(tr!=tc && fr==fc)
			//return 0;
	if(arr[fr][fc]=='P'&& fr==6 && fc==tc)
	{
		
		{
		if(tr==fr-2 || tr==fr-1)
			return 1;
		else
			return 0;

		}
	}
		else
		{
			if(arr[fr][fc]=='p'&& fr!=6 && fc==tc)
			{
				if(tr==fr-1)
				{
				return 1;
				}
				else

				return 0;
			
			}
		
		}
		
	
		
				if (arr[fr][fc]=='P' && (arr[fr-1][fc-1]>97 && arr[fr-1][fc-1]<121) ||(arr[fr-1][fc+1]>97 && arr[fr-1][fc+1]<124))
	{
		if((tr==fr-1 && tc==fc-1) ||(tr==fr-1 && tc==fc+1))
		{
		return 1;
		}
		else
		{
		return 0;
		}
	}
			
				else
				{
					return 0;
				   }
				
		
				
				
		
	
	}

int pawn(char arr[][COLSIZE],int fr,int fc,int tr,int tc)
{
	
    	if(fr==tr && fc==tc)
			return 0;
		//if(tr!=tc && fr==fc)
			//return 0;
	if(arr[fr][fc]=='p')
	{
		if(fr==1 && fc==tc){
		
		if(tr==fr+2 || tr==fr+1){
			return 1;
		}
		else
			return 0;

		}
		else
		{
			if( arr[fr][fc]=='p' && fr!=1 && tc==fc)
			{
				if(tr==fr+1)
				{
				return 1;
				}
				else
					return 0;
			
			}
	
	
			else
			{
	
	if (arr[fr][fc]=='p' && (arr[fr+1][fc-1]<97 && arr[fr+1][fc-1]>64) ||(arr[fr+1][fc+1]<97 && arr[fr+1][fc+1]>64))
	{
		if((tr==fr+1 && tc==fc-1) ||(tr==fr+1 && tc==fc+1))
		{
		return 1;
		}
		else
		{
			return 0;
		}
	}

	else
	{
		return 0;
	}

			}
	
		}
	}
	else{return 0;}
		
}
		
	/*int Pawn(char arr[][COLSIZE],int fr,int fc,int tr,int tc)
{

		if(fr==tr && fc==tc)
			return 0;
		if(tr!=tc && fr==fc)
			return 0;
		if(fr==6){ if(tr==fr+1 ||)  
		
		}		
}*/
/*int pawn(char arr[][COLSIZE],int fr,int fc,int tr,int tc)
{

		if(fr==fc && tr==tc)
			return 0;
		if(tr!=tc && fr==fc)
			return 0;
			if(tr<=tc)
				return 0;
		if(arr[tr][tc]>64 && arr[tr][tc]<97 )
		{
			if(fc!=tc){
        if(abs(fr-tc)==1)
        {
        if(abs(fr-tr)==1 && (tr>fr))
        return 1;
        else 
        return 0;
        }
		else 
		return 0;
		}
	    else
	    return 0;
		}	
	
		else 
		if(fr==1)
	    {
	    	if(((abs(fr-tr)==2)&& (fc-tc==0)) ||((abs(fr-tr)==1)&& (fc-tc==0)))
	    	return 1;
	   	else
	    	return 0;
	    }
		else 
		if(fc==tc && abs(fr-tr)==1)
		return 1;
		else 
		return 0;
		
}*/






int pawnfinal(char arr[][COLSIZE],int fr,int fc,int tr,int tc){
	int a=Pawn(arr,fr,fc,tr,tc);
	int b=pawn(arr,fr,fc,tr,tc);
	//int c=promotionP(arr,fr,fc,tr,tc);
	//int d=promotionP(arr,fr,fc,tr,tc);
	if(a==1 || b==1 )
	{return 1;}
	else
	{return 0;}

}

void outputboard(char arr[][COLSIZE],int &  r ,int & c){
	
system("cls");
int i;
	int l;
	cout<<endl<<endl<<endl;
	cout << '.';
	for(int n=1;n<9;n++)
	{
	cout <<'.' << n-1<< '.';
	}
	cout << endl;cout << endl;
	for( i=0,l=0 ;i<8,l<8;i++,l++)
	 {
	 cout << l  << '.';
	 for( int j=0;j<8;j++)
	  {
	 cout << " " << arr[i][j]<<" "  << '|' << " ";
		 
	  }
cout << endl ; 
cout << "_________________________________________";
cout << endl ;

}
}

void board(char arr[][COLSIZE],int  r,int  c)
{

for(int i=0;i<r;i++){

for(int j=0;j<c;j++){

if(j==4   && i==0  ){
	arr[i][j]='k';
}else if(j==4 && i==7){
	arr[i][j]='K';
	
}
else
if(j==0   && i==0 ){
	arr[i][j]='r';
 
}
else
if(j==7   && i==0 ){
	arr[i][j]='r';
 
}else if(j==0 && i==7){
	
	arr[i][j]='R';
}
else if(j==7 && i==7){
	
	arr[i][j]='R';
}
else
if(j==1   && i==0  ){
	arr[i][j]='n';

}
else if(j==1 &&	 i==7){
	arr[i][j]='N';
	
}
else
if(j==2   && i==0 ){
	arr[i][j]='b';
}
else if(j==2 &&	 i==7){
	arr[i][j]='B';
	
}

else
if(j==3   && i==0 ){
	arr[i][j]='q';
}
else if(j==3 &&	 i==7){
	arr[i][j]='Q';
	
}
else
if(j==5   && i==0 )
{
		arr[i][j]='b';
		
}else if(j==5 && i==7){
	arr[i][j]='B';
	
}
else if(j==6 &&	 i==7){
	arr[i][j]='N';
	
}

else
if(j==6   && i==0  )
	{
	arr[i][j]='n';
}

	else 
	if(i==1 &&(j>=0 && j<=7))
	{
		arr[i][j]='p';
		
		
	}
	else
	if(i==6 &&(j>=0 && j<=7))
{
	arr[i][j]='P';
	
}
else{
arr[i][j]='.';

}
}
}


}

int pawnmove(char arr[][COLSIZE],int fr,int fc,int tr,int tc)
{

	if(arr[fr][fc]=='p')
	{
	if(tr==fr+1 && tc==fc )
	{
	return 1;
		}
	else
	if((arr[fr+1][fc+1]<64 && arr[fr+1][fc+1]>97) ||(arr[fr+1][fc-1]<64 && arr[fr+1][fc-1]>97)){
	if((tr==fr+1 && tc==fc+1) || ((tr==fr+1 && tc==fc-1)))
	return 1;
	else
	return 0;
	}
	else 
	return 0;
	}
	else{
	if(arr[fr][fc]=='P')
	{
	if(tr==fr-1 && tc==fc )
	{
	return 1;
	}
	else
	if((arr[fr-1][fc+1]<121 && arr[fr-1][fc+1]>97) ||(arr[fr-1][fc-1]<121 && arr[fr-1][fc-1]>97)){
	if((tr==fr-1 && tc==fc+1) || ((tr==fr-1 && tc==fc-1))){
	return 1;
	}
	else{
		return 0;
	}
	
	}
	
	else
	return 0;

}
	else
		return 0;
	
}
}
/*int validmove(char arr[8][8],int sx,int sy,int tx,int ty ,int m)
{
	int j=0;
	char source,target;
	source=arr[sx][sy];
	target=arr[tx][ty];
	 //////for player 1 black pieces
	if(m==0){
		if((source=='p'||source=='n'||source=='r'||source=='q'||source=='k'||source=='b' )&&(target=='P'||target=='N'||target=='R'||target=='Q'||target=='K'||target=='B'||target=='.' ))
		
		{
		if(source=='p')   ////////pawn
		{
		 if(ty==sy && (tx-sx==1||tx-sx==-1) && target=='.') return true;
          if((ty-sy==1||ty-sy==-1) && (tx-sx==1||tx-sx==-1) && target!= '.'&&target!='.'&&target!='p'&&target!='r'&&target!='q'&&target!='n'&&target!='k'&&target!='b') return true;
		  if( sx==1 && (sx-tx==2||sx-tx==-2) && target == '.') return true;
		  else return false;
		}

		if(source=='n')////for knight
		{
			 if((tx<8&&tx>=0)&&(ty>=0&&ty<8)||(sx>1&&sx<6&&sy>1&&sy<6)){
					if(((ty-sy==2||ty-sy==-2)&&(tx-sx==1||tx-sx==-1))||((ty-sy==1||ty-sy==-1)&&(target!='p'&&target!='r'&&target!='q'&&target!='n'&&target!='k'&&target!='b')))
			      return true;

					else	if(sx>1&&sx<6&&sy>1&&sy<6)
			{
				if(tx==sx+2&&ty==sy+1&&target!='p'&&target!='r'&&target!='q'&&target!='n'&&target!='k'&&target!='b')return true;
				else if(tx==sx-2&&ty==sy+1&&target!='p'&&target!='r'&&target!='q'&&target!='n'&&target!='k'&&target!='b')return true;
				else if(tx==sx+2&&ty==sy-1&&target!='p'&&target!='r'&&target!='q'&&target!='n'&&target!='k'&&target!='b')return true;
				else if(tx==sx-2&&ty==sy-1&&target!='p'&&target!='r'&&target!='q'&&target!='n'&&target!='k'&&target!='b')return true;
				else if(ty==sy+2&&tx==sx+1&&target!='p'&&target!='r'&&target!='q'&&target!='n'&&target!='k'&&target!='b')return true;
				else if(ty==sy+2&&tx==sx-1&&target!='p'&&target!='r'&&target!='q'&&target!='n'&&target!='k'&&target!='b')return true;
				else if(ty==sy-2&&tx==sx+1&&target!='p'&&target!='r'&&target!='q'&&target!='n'&&target!='k'&&target!='b')return true;
				else if(ty==sy-2&&tx==sx-1&&target!='p'&&target!='r'&&target!='q'&&target!='n'&&target!='k'&&target!='b')return true;
				else return false;
			}
			
				
					else 
						return false;
				}
				else
					return false;
		}
		if(source=='b')///bishop
		{
			if(abs(tx-sx)==abs(ty-sy))
			{
				if(tx>sx)///downward
				{
					
				if(ty>sy)
				{
				   int i=sx+1,j=sy+1;
				   while(i<tx)
				   {
					   j=sy+1;
					   int w=0;
					   while(j<ty)
					   {
						   int k=i-1,l=j-1;
						   if((i==k+1)&&(j==l+1))
						   {
							   if(arr[i][j]!='.')
							   return false;
							   else
								   return true;
						   }

						   j=j+1;
					   }
					   i=i+1;
				   }
				}
				else if(ty<sy)
				{
					
				   int i=sx+1,j=sy-1;
				   while(i<tx)
				   {
					   j=sy-1;
					   
					   while(j>=ty)
					   {
						   int k=i-1,l=j-1;
						   if((i==k+1)&&(j==l+1))
						   {
							   if(arr[i][j]!='.')
							   return false;
							   else
								   return true;
						   }

						   j=j-1;
					   }
					   i=i+1;
				   }
				}

				}
				else  if(sx>tx)///upward
				   {
					   int i=tx+1,j=ty+1;
				   while(i<sx)
				   {
					   j=ty;
					   while(j<sy)
					   {
						   int k=i-1,l=j-1;

						   if(i==k+1&&j==l+1)
						   {
							   if(arr[i][j]!='.')
							   return false;
							   else
								   return true;
						   }
						   j=j+1;
					   }
					   i=i+1;
				   }
				}
				else if(target=='.'&&target=='P'&&target=='N'&&target=='K'&&target=='B'&&target=='Q'&&target=='R')
					   return true;
				   else
					   return false;
			}
			else
				return false;
		}
		
		if(source=='q')
		{
		 if(abs(tx-sx) == abs(ty-sy)){ // Moving diagonally
      if(tx>sx){ // South
        int j = min(ty, sy)+1;/////j for column    i for rows
        for(int i = sx+1; i <tx; ++i){
          if(arr[i][j] != '.') return false;
          j=j+1;
        }
        return true;
      }
      if(tx<sx && ty>sy){ // North
        int j = min(ty, sy)+1;
        for(int i = sx+1; i <tx; ++i){
          if(arr[i][j] != '.') return false;
          j=j+1;
        }
        return true;
      }
    }
    if(tx==sx || ty==sy){ // Moving straight
      if(ty==sy){ // Moving vertically
        if(tx>sx){ // Downards
          for(int i = (sx+1); i < tx; ++i){
            if(arr[i][ty] != '.') return false;
          }
        } else { // Upwards
          for(int i = tx; i < (sx-1); ++i){
            if(arr[i][ty] != '.' ) return false;
          }
        }
        return true;
      }
      if(tx==sx){ // Moving horizontally
        if(ty>sy){ // Rightwards
          for(int j = (sy+1); j < tx; ++j){
            if(arr[tx][j] != '.') return false;
          }
        }
        if(ty<sy){ // Leftwards
          for(int j = ty; j < (sy-1); ++j){
            if(arr[tx][j] != '.') return false;
          }
        }
        return true;
      }
    }
    return false;
		}

		if(source=='r')///rock
		{
			 if(ty==sy){ // Moving vertically
      if(tx>sx){ // Downards
        for(int i = (sx+1); i < tx; ++i){
          if(arr[i][ty] != '.') return false;
        }
      } else { // Upwards
        for(int i = tx; i < (sx-1); ++i){
          if(arr[i][ty] != '.') return false;
        }
      }
      return true;
    }
    if(tx==sx){ // Moving horizontally
      if(ty>sy){ // Rightwards
        for(int j = (sy+1); j < tx; ++j){
          if(arr[tx][j] != '.') return false;
        }
      }
      if(ty<sy){ // Leftwards
        for(int j = ty; j < (sy-1); ++j){
          if(arr[tx][j] != '.') return false;
        }
      }
      return true;
    }
    return false;
		}
		if(source=='k')///king
		{
			if(((abs(tx-sx))==1||((abs(ty-sy))==1))&&(target=='P'||target=='N'||target=='K'||target=='B'||target=='Q'||target=='R'||target=='.'))
				return true;
			else
				return false;
		}

		}
		else
			return false;
		}
		else///for white
		{
			if(source=='P'||source=='N'||source=='R'||source=='Q'||source=='K'||source=='B' )
			{
			if(source=='P')   ////////pawn
		{
			if(sx==6&&tx==5&&sy==ty&&target=='.')return true;

			else	if(sx==6&&tx==4&&sy==ty&&target=='.')return true;
			else if(sx>6&&tx<sx-2&&tx<sx&&target=='.')return true;
			else if(sx>=6&&tx==sx-1&&ty==sy+1&&target!='.'&&target!='P'&&target!='R'&&target!='Q'&&target!='N'&&target!='K'&&target!='B')return true;
			else if(sx>=6&&tx==sx-1&&ty==sy-1&&target!='.'&&target!='P'&&target!='R'&&target!='Q'&&target!='N'&&target!='K'&&target!='B')return true;
			else   if(ty==sy && abs(tx-sx)==1 && target=='.') return true;
			else if(abs(ty-sy)==1 && abs(tx-sx)==1 && target!= '.') return true;
			if( sx==6 && abs(sx-tx)==2 && target == '.') return true;
			else return false;
		}
			if(source=='N')///////////knight
			{
				if((abs(tx-sx)==2 && abs(ty-sy)==1) || (abs(ty-sy)==2 && abs(tx-sx)==1)){
                 return true;
    }
			}

			if(source=='B')///bishop
			{
		if(target=='p'||target=='n'||target=='k'||target=='b'||target=='q'||target=='r'||target=='.')
				{
                 if(abs(tx-sx) == abs(ty-sy)){ // Moving diagonally
          if(tx>sx)//"\"down
		  {
			  j=sy+1;
          for(int i = sx+1; i < tx; i++){
           if(arr[i][j] != '.') return false;
          j=j+1;
        }
        return true;
      }
      if(tx>sx&&ty<sy){ //"/"down
        j=sy-1;
        for(int i = sx+1; i <tx; i++){
          if(arr[i][j] != '.') return false;
          j=j-1;;
        }
        return true;
      }
    }
				 if(tx<sx&&ty>sy)//upward/
	{
	    j=sy+1;
		for(int i=sx-1;i>tx;i--,j++){
			if(arr[i][j]!='.')return false;
			j=j+1;
		}
		return true;
	}

		if(tx<sx&&ty<sy)//upward"\"
		{
	    j=sy-1;
		for(int i=sx-1;i>tx;i--,j--){
			if(arr[i][j]!='.')return false;
			j=j+1;
		}
		return true;
	}

		}		
		else
			return false;
			}
			if(source=='R')/////rock
			{

		if(ty==sy){ // Moving vertically
      if(tx>sx){ // Downards
        for(int i = (sx+1); i <tx; ++i){
          if(arr[i][ty] != '.') return false;
        }
      } else { // Upwards
        for(int i = sx-1; i >tx;i--){
          if(arr[i][ty] != '.') return false;
        }
      }
      return true;
    }
    if(tx==sx){ // Moving horizontally
      if(ty>sy){ // Rightwards
        for(int j = sy+1; j < ty; j++){
          if(arr[tx][j] != '.') return false;
        }
      }
      if(ty<sy){ // Leftwards
        for(int j = ty; j >sy; j--){
          if(arr[tx][j] != '.') return false;
        }
      }
      return true;
    }
    return false;
			}

			if(source=='K')////king
			{

				if(abs(tx-sx)<=1 && abs(ty-sy)<=1) return true;
				  return false;
			}

			if(source=='Q')///queen
			{
				if(target=='p'||target=='n'||target=='k'||target=='b'||target=='q'||target=='r'||target=='.')
				{
                 if(abs(tx-sx) == abs(ty-sy)){ // Moving diagonally
          if(tx>sx)//"\"down
		  {
			  j=sy+1;
          for(int i = sx+1; i < tx; i++){
           if(arr[i][j] != '.') return false;
          j=j+1;
        }
        return true;
      }
      if(tx>sx&&ty<sy){ //"/"down
        j=sy-1;
        for(int i = sx+1; i <tx; i++){
          if(arr[i][j] != '.') return false;
          j=j-1;;
        }
        return true;
      }
    }
    if(tx==sx || ty==sy){ // Moving straight
      if(ty==sy){ // Moving vertically
        if(tx>sx){ // Downards
          for(int i = (sx+1); i <tx; i++){
            if(arr[i][ty] != '.') return false;
          }
        } else { // Upwards
          for(int i = tx; i < sx-1; i++){
            if(arr[i][ty] != '.') return false ;
          }
        }
        return true;
      }
       // Moving horizontally
        if(ty>sy){ // Rightwards
          for(int j = sy+1; j < ty; j++){
            if(arr[tx][j] != '.') return false;
          }
        }
        if(ty<sy){ // Leftwards
          for(int j =ty-1; j > sy; j--){
            if(arr[tx][j] != '.') return false;
          }
        }
        return true;
      
    }
	if(tx<sx&&ty>sy)//upward/
	{
	    j=sy+1;
		for(int i=sx-1;i>tx;i--,j++){
			if(arr[i][j]!='.')return false;
			j=j+1;
		}
		return true;
	}

		if(tx<sx&&ty<sy)//upward"\"
		{
	    j=sy-1;
		for(int i=sx-1;i>tx;i--,j--){
			if(arr[i][j]!='.')return false;
			j=j+1;
		}
		return true;
	}
    return false;

			}
				
			
				else
					return false;
			}
			}
				}
			
	}
	*/
int Check(char arr[COLSIZE][COLSIZE]){
	int ki;
	int kj;
	for(int m=0;m<COLSIZE;m++)
	for(int n=0;n<COLSIZE;n++)
	{
		if(arr[m][n]=='K')
		{
		ki=m;
		kj=n;
		}
	}
	for(int m=0;m<COLSIZE;m++)
	for(int n=0;n<COLSIZE;n++){
	if(arr[m][n]>97 || arr[m][n]<122){
		if(arr[m][n]=='p')
		{
		if(pawnfinal(arr,m,n,ki,kj))
		return 0;
		else
			return 1;
		}
		if(arr[m][n]=='k')
		{
		if(king(arr,m,n,ki,kj))
			return 0;		
		else
			return 1;
		}
		if(arr[m][n]=='n')
		{
		if(knight(arr,m,n,ki,kj))
		return 0;
		else
			return 1;
		}
		if(arr[m][n]=='q')
		{
		if(queen(arr,m,n,ki,kj))
		return 0;
		else
			return 1;
		}
		if(arr[m][n]=='b')
		{
	    if(bishop(arr,m,n,ki,kj))
		return 0;
		else
			return 1;
		}
        }
        }
	    return 1;	    
	    }

int Check2( char arr[COLSIZE][COLSIZE]){
	int ki;
	int kj;
	for(int m=0;m<COLSIZE;m++)
	for(int n=0;n<COLSIZE;n++)
	{
		if(arr[m][n]=='k')
		{
		ki=m;
		kj=n;
		}
	}
	for(int m=0;m<COLSIZE;m++)
	for(int n=0;n<COLSIZE;n++){
	if(arr[m][n]<97 || arr[m][n]>64){
		if(arr[m][n]=='P')
		{
		if(pawnfinal(arr,m,n,ki,kj))
		return 0;
		else
			return 1;

		}
		if(arr[m][n]=='K')
		{
		if(king(arr,m,n,ki,kj))
			return 0;
		else
			return 1;
	    }
		if(arr[m][n]=='N')
		{
		if(knight(arr,m,n,ki,kj))
		return 0;
		else
			return 1;
		}
		if(arr[m][n]=='Q')
		{
		if(queen(arr,m,n,ki,kj))
		return 0;
		else
			return 1;
		}
		if(arr[m][n]=='B')
		{
	    if(bishop(arr,m,n,ki,kj))
		return 0;
		else
			return 1;
		}
        }
        }
	    return 1;	    
	    }

/*int slect(char arr[][COLSIZE],int & fr,int & fc,int & tr,int & tc,int & p,char b)
{
	if(p==1){
		
	s1:cout<<"Enter player 1 your row move::";
	cin>>fr;
	cout<<endl;
	cout<<"Enter player 1 your col move::";
    cin>>fc;

	

	if(arr[fr][fc]<64 && arr[fr][fc]<97 && arr[fr][fc]!='\0'){
		cout<<"Enter your destination row::";
		   cin>>tr;
		   cout<<endl;
		cout<<"Enter your destination col::";

			cin>>tc;
		if(arr[fr][fc]=='R')
		{
			int r=rook(arr,fr,fc,tr,tc);

				if(r==1)
				{
				
				arr[fr][fc]=arr[tr][tc];
				arr[fr][fc]='.';
				}	
		
		
		}

		if(arr[fr][fc]=='P')
		{
			int P=pawnfinal(arr,fr,fc,tr,tc);

				if(P==1)
				{
				
				arr[fr][fc]=arr[tr][tc];
				arr[fr][fc]='.';
				}	
		
		
		}



	return 0;
	p++;
	}
	else
	{
	cout<<"Invalid";
	return 0;
	goto s1;}
	
}
	else
	{
	if(p==2){
		
	s2:cout<<"Enter player 2 your row move::";
	cin>>fr;
	cout<<endl;
	cout<<"Enter player 2 your col move::";
    cin>>fc;
	if(arr[fr][fc]>97 && arr[fr][fc]<121){
	cout<<"Enter your destination row::";
		   cin>>tr;
		   cout<<endl;
		cout<<"Enter your destination col::";

			cin>>tc;
		/*if(b=='r')
		{
			int r=rook(arr,fe,fc,tr,tc);

				if(r==1)
				{
				
				arr[fr][fc]=arr[tr][tc];
				arr[fr][fc]='.';
				}	
		
		
		}

		if(b=='p')
		{
			int p=pawnfinal(arr,fr,fc,tr,tc);

				if(p==1)
				{
				
				arr[fr][fc]=arr[tr][tc];
				arr[fr][fc]='.';
				}	
		
		
		}
		
		
		

		
		
		
		
	p--;
	}
	else
	{
	cout<<"Invalid";

	goto s2;}
	
}	
	
	
	}

}*/
int main(){
	char arr[8][8];
int r=8;
int c=8;
 board(arr,r,c);
 int tr,tc,fr,fc;
 bool pawnmove=true;
 
 int X,B,R,N,K,P,Q,Y,b,r1,n,k,p,q;
 
 while(1){
 
 
	 outputboard(arr,r,c);

 
		
	s1:cout<<"Enter player 1 your row move::";
	cin>>fr;
	cout<<endl;
	cout<<"Enter player 1 your col move::";
    cin>>fc;

	

	if(arr[fr][fc]<90 && arr[fr][fc]>65  )
	{
		cout<<"Enter your destination row::";
		   cin>>tr;
		   cout<<endl;
		cout<<"Enter your destination col::";
         cin>>tc;
			if(arr[tr][tc]=='.' ||(arr[tr][tc]>90  && arr[tr][tc]<121 )){
		/*if(arr[fr][fc]=='R')
		{
			 X=Check(arr);
			 R=rook(arr,fr,fc,tr,tc);

				if(R==1 && X==1)
				{
				
				arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
				outputboard(arr,r,c);
				}
				
				else
				{
				cout<<"Invalid"<<endl;
				goto s1;
				}
		
		
		}*/
		
		if(arr[fr][fc]=='P')
		{if(tr==0){
			promotionP(arr,fr,fc,tr,tc); 
		outputboard(arr,r,c);
		}
		else{
				X=Check(arr);
			P=validmove(arr,fr,fc,tr,tc,0);

				if( P==1 && X==1)
				{
				
				arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
				outputboard(arr,r,c);
				
				}
				
				else
				{
				cout<<"Invalid"<<endl;
				goto s1;
				}
		
		}
		}

			
		if(arr[fr][fc]=='R')
		{
			 X=Check(arr);
			 R=rook(arr,fr,fc,tr,tc);
			 cout<<"sdsd";
				if(R==1 && X==1)
				{
				
				arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
				 
               outputboard(arr,r,c);
				
				}
				
				else
				{
				cout<<"Invalid"<<endl;
				goto s1;
				}
		
		}
		
		if(arr[fr][fc]=='K')
		{	 X=Check(arr);
			 K=king(arr,fr,fc,tr,tc);

				if(K==1 && X==1)
				{
				
				arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
				outputboard(arr,r,c);
				
				}
				
				else
				{
				cout<<"Invalid"<<endl;
				goto s1;
				}
		
		}
		
		if(arr[fr][fc]=='N')
		{
			 X=Check(arr);
			 N=knight(arr,fr,fc,tr,tc);

				if(N==1 && X==1)
				{
				
				arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
				outputboard(arr,r,c);
				
				}
				
				else
				{
				cout<<"Invalid"<<endl;
				goto s1;
				}
		
		}
		
		if(arr[fr][fc]=='B')
		{  X=Check(arr);
			 B=bishop(arr,fr,fc,tr,tc);

				if(B==1 && X==1)
				{
				
				arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
                outputboard(arr,r,c);
				
				}
				else
				{
				cout<<"Invalid"<<endl;
				goto s1;
				}
		
		}



			}
			else
			{
				cout<<"Invalid"<<endl;
			goto s1;
			}
 
		if(arr[fr][fc]=='Q')
		{  X=Check(arr);
			 Q=queen(arr,fr,fc,tr,tc);

				if(Q==1 && X==1)
				{
				
				arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
                outputboard(arr,r,c);
				
				}
				else
				{
				cout<<"Invalid"<<endl;
				goto s1;
				}
		
		}
		
}	
		

	else
	{

	cout<<"Invalid";

	goto s1;

}
	s2:cout<<"Enter player 2 your row move::";
	cin>>fr;
	cout<<endl;
	cout<<"Enter player 2 your col move::";
    cin>>fc;
	if(arr[fr][fc]<122 && arr[fr][fc]>97){
	cout<<"Enter your destination row::";
		   cin>>tr;
		   cout<<endl;
		cout<<"Enter your destination col::";

			cin>>tc;
		if(arr[fr][fc]=='r')
		{    Y=Check2(arr);
			 r1=rook(arr,fr,fc,tr,tc);
			 Sleep(500);
			 cout<<"ssdsds";
				if(r1==1 && Y==1)
				{
				
				arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
				outputboard(arr,r,c);
				}
				
				else
				{
				cout<<"Invalid"<<endl;
				goto s2;
				}
		
		
		}

		if(arr[fr][fc]=='p'){
			if(tr==7){
			promotionp(arr,fr,fc,tr,tc);
			outputboard(arr,r,c);
			}
			else {Y=Check2(arr);
			 p=pawnmover(arr,fr,fc,tr,tc,pawnmove);

				if(p==1 && Y==1)
				{
				
				arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
				outputboard(arr,r,c);
				}
		
				else
				{
				cout<<"Invalid"<<endl;
				goto s2;
				}
			}
		}
		
		
		if(arr[fr][fc]=='n')
		{
			 Y=Check2(arr);
			 k=knight(arr,fr,fc,tr,tc);
			 
				if(k==1 && Y==1)
				{
				
					arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
				outputboard(arr,r,c);
				}
				
				else
				{
				cout<<"Invalid"<<endl;
				goto s2;
				}
		
		
		}
		if(arr[fr][fc]=='q')
		{
			 Y=Check2(arr);
			 q=queen(arr,fr,fc,tr,tc);

				if(q==1 && Y==1)
				{
				
				arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
				outputboard(arr,r,c);
				}
				
				else
				{
				cout<<"Invalid"<<endl;
				goto s2;
				}
		
		
		}
		if(arr[fr][fc]=='r')
		{
			 Y=Check2(arr);
			 r=rook(arr,fr,fc,tr,tc);

				if(r==1 && Y==1)
				{
					arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
				outputboard(arr,r,c);
				}
				
				else
				{
				cout<<"Invalid"<<endl;
				goto s2;
				}
		
		
		}
		if(arr[fr][fc]=='k')
		{
			int Y=Check2(arr);
			int k=king(arr,fr,fc,tr,tc);

				if(k==1 && Y==1)
				{
				
				arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
				outputboard(arr,r,c);
				}
				
				else
				{
				cout<<"Invalid"<<endl;
				goto s2;
				}
		
		
		}
		
		if(arr[fr][fc]=='b')
		{
			 Y=Check2(arr);
			 b=bishop(arr,fr,fc,tr,tc);

				if(b==1 && Y==1)
				{
				
					arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
				outputboard(arr,r,c);
				}
				
				else
				{
				cout<<"Invalid"<<endl;
				goto s2;
				}
		
		
		}
		




		if(arr[fr][fc]=='q')
		{
			 Y=Check2(arr);
			 q=queen(arr,fr,fc,tr,tc);

				if(q==1 && Y==1)
				{
				
					arr[tr][tc]=arr[fr][fc];
				arr[fr][fc]='.';
				outputboard(arr,r,c);
				}
				
				else
				{
				cout<<"Invalid"<<endl;
				goto s2;
				}
		
		
		}
		
	
	
	}
	else
	{
	cout<<"Invalid"<<endl;

	goto s2;
}
	
	
	
	
	}

 
 
 

 
}
