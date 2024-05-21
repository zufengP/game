#include "sur.h"
#include<algorithm>
//按Score排序
bool compq(const MovePosition a, const MovePosition b)
{
    return a.Score > b.Score;
}
//降序排序
void Sort(vector<MovePosition> ddd)
{
    sort(ddd.begin(), ddd.end(),compq);
}
Sur::Sur()
{
    Init();
}
void Sur::Init()
{
    //初始化棋盘
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<6;j++)
        {
            board[i][j]=1;
            board[i+2][j]=0;
            board[i+4][j]=-1;
        }
    }
    side = 1;
    count=0;
    c=1;
}
void Sur::Drawboard()
{
    setbkcolor(15);
    cleardevice();
    //绘制黄色棋盘部分
    setcolor(COLOR(255,158,53));
    setlinestyle(1,1,5);
    line(LEFT+100,TOP+100,LEFT+100,TOP+350);
    line(LEFT+350,TOP+100,LEFT+350,TOP+350);
    line(LEFT+100,TOP+100,LEFT+350,TOP+100);
    line(LEFT+100,TOP+350,LEFT+350,TOP+350);
    //绘制绿色棋盘部分
    setcolor(GREEN);
    line(LEFT+200,TOP+100,LEFT+200,TOP+350);
    line(LEFT+250,TOP+100,LEFT+250,TOP+350);
    line(LEFT+100,TOP+200,LEFT+350,TOP+200);
    line(LEFT+100,TOP+250,LEFT+350,TOP+250);
    //绘制绿色圆弧
    arc(LEFT+100,TOP+100,0,270,100);//左上
    arc(LEFT+350,TOP+100,-90,180,100);//右上
    arc(LEFT+100,TOP+350,90,360,100);//左下
    arc(LEFT+350,TOP+350,-180,90,100);//右下
    //绘制蓝色棋盘部分
    setcolor(LIGHTBLUE);
    line(LEFT+150,TOP+100,LEFT+150,TOP+350);
    line(LEFT+300,TOP+100,LEFT+300,TOP+350);
    line(LEFT+100,TOP+150,LEFT+350,TOP+150);
    line(LEFT+100,TOP+300,LEFT+350,TOP+300);
    //绘制浅蓝色圆弧
    arc(LEFT+100,TOP+100,0,270,50);//左上
    arc(LEFT+350,TOP+100,-90,180,50);//右上
    arc(LEFT+100,TOP+350,90,360,50);//左下
    arc(LEFT+350,TOP+350,-180,90,50);//右下
    //绘制棋子
    int i;
    int j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(board[i][j]==1)
            {
                setcolor(BLACK);
                setfillstyle(1,BLACK);
                fillellipse(j*50+150,i*50+150,18,18);
            }
            else if(board[i][j]==-1)
            {
                setcolor(RED);
                setfillstyle(1,RED);
                fillellipse(j*50+150,i*50+150,18,18);
            }
        }
    }
    setcolor(0);
    rectangle(570,250,630,300);
    outtextxy(585,270,"悔棋");
    setcolor(0);
    readimagefile("C:\\D\\2020\\C++\\Surakarta\\image\\5.ico",570,150,634,214);
    //readimagefile("C:\\D\\2020\\C++\\Surakarta\\image\\6.ico",570,350,634,414);
}
//复盘用的画图
void Sur::FPDraw()
{
    setbkcolor(15);
    cleardevice();
    setbkcolor(15);
    //绘制黄色棋盘部分
    setcolor(COLOR(255,158,53));
    setlinestyle(1,1,5);
    line(LEFT+100,TOP+100,LEFT+100,TOP+350);
    line(LEFT+350,TOP+100,LEFT+350,TOP+350);
    line(LEFT+100,TOP+100,LEFT+350,TOP+100);
    line(LEFT+100,TOP+350,LEFT+350,TOP+350);
    //绘制绿色棋盘部分
    setcolor(GREEN);
    line(LEFT+200,TOP+100,LEFT+200,TOP+350);
    line(LEFT+250,TOP+100,LEFT+250,TOP+350);
    line(LEFT+100,TOP+200,LEFT+350,TOP+200);
    line(LEFT+100,TOP+250,LEFT+350,TOP+250);
    //绘制绿色圆弧
    arc(LEFT+100,TOP+100,0,270,100);//左上
    arc(LEFT+350,TOP+100,-90,180,100);//右上
    arc(LEFT+100,TOP+350,90,360,100);//左下
    arc(LEFT+350,TOP+350,-180,90,100);//右下
    //绘制蓝色棋盘部分
    setcolor(LIGHTBLUE);
    line(LEFT+150,TOP+100,LEFT+150,TOP+350);
    line(LEFT+300,TOP+100,LEFT+300,TOP+350);
    line(LEFT+100,TOP+150,LEFT+350,TOP+150);
    line(LEFT+100,TOP+300,LEFT+350,TOP+300);
    //绘制浅蓝色圆弧
    arc(LEFT+100,TOP+100,0,270,50);//左上
    arc(LEFT+350,TOP+100,-90,180,50);//右上
    arc(LEFT+100,TOP+350,90,360,50);//左下
    arc(LEFT+350,TOP+350,-180,90,50);//右下
    //绘制棋子
    int i;
    int j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(board[i][j]==1)
            {
                setcolor(BLACK);
                setfillstyle(1,BLACK);
                fillellipse(j*50+150,i*50+150,18,18);
            }
            else if(board[i][j]==-1)
            {
                setcolor(RED);
                setfillstyle(1,RED);
                fillellipse(j*50+150,i*50+150,18,18);
            }
        }
    }
    readimagefile("C:\\D\\2020\\C++\\Surakarta\\image\\2.ico",550,100,614,164);
    readimagefile("C:\\D\\2020\\C++\\Surakarta\\image\\3.ico",550,200,614,264);
    readimagefile("C:\\D\\2020\\C++\\Surakarta\\image\\4.ico",550,300,614,364);
    readimagefile("C:\\D\\2020\\C++\\Surakarta\\image\\1.ico",550,400,614,464);
    readimagefile("C:\\D\\2020\\C++\\Surakarta\\image\\6.ico",550,0,614,64);
    /*setcolor(1);
    rectangle(550,100,614,164);
    rectangle(550,200,614,264);
    rectangle(550,300,614,364);
    rectangle(550,400,614,464);*/
}
bool Sur::Iswin(int board[6][6],int side)
{
    int w=0;
    int b=0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(board[i][j] == 1)
            {
                b++;
            }
            else if(board[i][j] == -1)
            {
                w++;
            }
        }
    }

    //判断输赢
    if( w == 0 && b!=0)
    {
        cout<<"Black WIN"<<endl;
        //弹出消息框
        MessageBox(NULL,"黑棋获胜","比赛",MB_OK);
        return true;
    }
    else if( b == 0 && w!=0)
    {
        cout<<"White WIN"<<endl;
        //弹出消息框
        MessageBox(NULL,"白棋获胜","比赛",MB_OK);
        return true;
    }
    else
    {
        return false;
    }
}
//判断合法
bool Sur::isLegal(int position[6][6],Position positionFrom, Position positionTo)
{
    int i,arc=0;
    int start1=-1,start2=-1,end1=-1,end2=-1;
    Node Node1[24];
    Node Node2[24];
    /*for(i=0;i<24;i++)
    {
        Node1[i].arc = NULL;
        Node1[i].color = NULL;
        Node2[i].arc = NULL;
        Node2[i].color = NULL;
    }*/
    //其中有同一个点重复标号，目的是同一个点行走方向不一样
        Node1[0].i=2;Node1[0].j=2;
		Node1[0].arc=0;
   	 	Node1[1].i=1;Node1[1].j=2;
		Node1[1].arc=0;
		Node1[2].i=0;Node1[2].j=2;
		Node1[2].arc=1;
		Node1[3].i=2;Node1[3].j=0;
		Node1[3].arc=0;
		Node1[4].i=2;Node1[4].j=1;
		Node1[4].arc=0;
		Node1[5].i=2;Node1[5].j=2;
		Node1[5].arc=0;
		Node1[6].i=2;Node1[6].j=3;
		Node1[6].arc=0;
		Node1[7].i=2;Node1[7].j=4;
		Node1[7].arc=0;
		Node1[8].i=2;Node1[8].j=5;
		Node1[8].arc=1;
		Node1[9].i=0;Node1[9].j=3;
		Node1[9].arc=0;
		Node1[10].i=1;Node1[10].j=3;
		Node1[10].arc=0;
		Node1[11].i=2;Node1[11].j=3;
		Node1[11].arc=0;
		Node1[12].i=3;Node1[12].j=3;
		Node1[12].arc=0;
		Node1[13].i=4;Node1[13].j=3;
		Node1[13].arc=0;
		Node1[14].i=5;Node1[14].j=3;
		Node1[14].arc=1;
		Node1[15].i=3;Node1[15].j=5;
		Node1[15].arc=0;
		Node1[16].i=3;Node1[16].j=4;
		Node1[16].arc=0;
		Node1[17].i=3;Node1[17].j=3;
		Node1[17].arc=0;
		Node1[18].i=3;Node1[18].j=2;
		Node1[18].arc=0;
		Node1[19].i=3;Node1[19].j=1;
		Node1[19].arc=0;
		Node1[20].i=3;Node1[20].j=0;
		Node1[20].arc=1;
	    Node1[21].i=5;Node1[21].j=2;
		Node1[21].arc=0;
		Node1[22].i=4;Node1[22].j=2;
		Node1[22].arc=0;
		Node1[23].i=3;Node1[23].j=2;
		Node1[23].arc=0;

    //由（2，2）点向上路过一圈的顺序来定义点的顺序

		Node2[0].i=1;Node2[0].j=1;
		Node2[0].arc=0;
	    Node2[1].i=0;Node2[1].j=1;
		Node2[1].arc=1;
		Node2[2].i=1;Node2[2].j=0;
		Node2[2].arc=0;
		Node2[3].i=1;Node2[3].j=1;
		Node2[3].arc=0;
		Node2[4].i=1;Node2[4].j=2;
		Node2[4].arc=0;
		Node2[5].i=1;Node2[5].j=3;
		Node2[5].arc=0;
		Node2[6].i=1;Node2[6].j=4;
		Node2[6].arc=0;
		Node2[7].i=1;Node2[7].j=5;
		Node2[7].arc=1;
		Node2[8].i=0;Node2[8].j=4;
		Node2[8].arc=0;
		Node2[9].i=1;Node2[9].j=4;
		Node2[9].arc=0;
		Node2[10].i=2;Node2[10].j=4;
		Node2[10].arc=0;
		Node2[11].i=3;Node2[11].j=4;
		Node2[11].arc=0;
		Node2[12].i=4;Node2[12].j=4;
		Node2[12].arc=0;
		Node2[13].i=5;Node2[13].j=4;
		Node2[13].arc=1;
		Node2[14].i=4;Node2[14].j=5;
		Node2[14].arc=0;
		Node2[15].i=4;Node2[15].j=4;
		Node2[15].arc=0;
		Node2[16].i=4;Node2[16].j=3;
		Node2[16].arc=0;
		Node2[17].i=4;Node2[17].j=2;
		Node2[17].arc=0;
		Node2[18].i=4;Node2[18].j=1;
		Node2[18].arc=0;
		Node2[19].i=4;Node2[19].j=0;
		Node2[19].arc=1;
		Node2[20].i=5;Node2[20].j=1;
		Node2[20].arc=0;
		Node2[21].i=4;Node2[21].j=1;
		Node2[21].arc=0;
		Node2[22].i=3;Node2[22].j=1;
		Node2[22].arc=0;
		Node2[23].i=2;Node2[23].j=1;
		Node2[23].arc=0;
    //由（1，1）点向上路过一圈的顺序来定义点的顺序

    //对棋盘位置进行分类//Node1[]为外弧连接的位置（包括直线），其arc值为逆时针是否有弧（0、1）
    //Node2[]为內弧//定义同Node1[]
    //每个有八个位置重复定义Node
    for(i=0;i<24;i++)//将内位置的"红黑无"状态标注清楚
    {
        Node1[i].color=position[Node1[i].i][Node1[i].j];//position(CurPosition)就是棋盘所在位置的状态（红方、黑方、无子）
    }
    for(i=0;i<24;i++)//将外位置的"红黑无"状态标注清楚
    {
        Node2[i].color=position[Node2[i].i][Node2[i].j];//int color
    }
    if (position[positionTo.x][positionTo.y]==0)//所下的位置没有棋子
    {
        if(abs(positionFrom.x-positionTo.x)<2 && abs(positionFrom.y-positionTo.y)<2)//普通走法，不包含吃子走法，跨度为1（包括斜向为1）
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (position[positionTo.x][positionTo.y]+position[positionFrom.x][positionFrom.y]==0)//起始位置+终止位置和为3：吃子行为
    {
        int temp;
        temp=position[positionFrom.x][positionFrom.y];//确定下棋一方
            position[positionFrom.x][positionFrom.y]=0;//将下棋初始位置置为空
            for(i=0;i<24;i++)//重新规划棋盘
            {
                Node1[i].color=position[Node1[i].i][Node1[i].j];
            }
            for(i=0;i<24;i++)
            {
                Node2[i].color=position[Node2[i].i][Node2[i].j];
            }
            for(i=0;i<24;i++)//外环
            {
                if(Node1[i].i==positionFrom.x && Node1[i].j==positionFrom.y)//起点
				{
					if(start1==-1)
					{
						start1=i;
					}
					else
					{
						start2=i;
					}
				}
				if(Node1[i].i==positionTo.x && Node1[i].j==positionTo.y)//终点
				{
					if(end1==-1)
					{
						end1=i;
					}
					else
					{
						end2=i;
					}
				}
			 }



		 //判断外环
		 if(start1 !=-1 && end1 !=-1)
		 {
			for(i=start1;i!=end1 ; i=(i+1)%24)
			{
				if(Node1[i].color!=0 && i!=start1)
				{
					arc=0;
					break;
				}
				if(Node1[i].arc==1)
				{
					arc=1;
				}

			}
			if(arc==1)
			{
				position[positionFrom.x][positionFrom.y]=temp;
                return true;
			}

			for(i=end1 ; i!=start1 ; i=(i+1)%24)
			{
				if(Node1[i].color!=0 && i!=end1)
				{
					arc=0;
					break;
				}
				if(Node1[i].arc==1)
				{
					arc=1;
				}
			}
			if(arc==1)
			{
                position[positionFrom.x][positionFrom.y]=temp;
				return true;
			}
		 }



		 if(start2!=-1&&end1!=-1)
		 {
			for(i=start2 ; i!=end1 ; i=(i+1)%24)
			{
				if((Node1[i].color!=0||start2==-1) && (i!=start2))
				{
						arc=0;
						break;
				}
				if(Node1[i].arc==1)
				{
					arc=1;
				}

			}
			if(arc==1)
			{
				position[positionFrom.x][positionFrom.y]=temp;
				return true;
			}

			for(i=end1;i!=start2;i=(i+1)%24)
			{
				if((Node1[i].color!=0||start2==-1) && (i!=end1))
				{
					arc=0;
					break;
				}
				if(Node1[i].arc==1)
				{
					arc=1;
				}

			}
			if(arc==1)
			{
				position[positionFrom.x][positionFrom.y]=temp;
				return true;
			}
		 }



		if(end2!=-1 && start1!=-1)
		{
			for(i=start1 ; i!=end2 ; i=(i+1)%24)
			{
				if((Node1[i].color!=0||end2==-1) && (i!=start1))
				{
					arc=0;
					break;
				}
				if(Node1[i].arc==1)
				{
					arc=1;
				}

			}
			if(arc==1)
			{
				position[positionFrom.x][positionFrom.y]=temp;
				return true;
			}
			for(i=end2 ; i!=start1 ; i=(i+1)%24)
			{
				if((Node1[i].color!=0||end2==-1) && (i!=end2))
				{
					arc=0;
					break;
				}
				if(Node1[i].arc==1)
				{
					arc=1;
				}

			}
			if(arc==1)
			{
				position[positionFrom.x][positionFrom.y]=temp;
				return true;
			}
		}

		if(start2!=-1&&end2!=-1)
		{
			for(i=start2 ; i!=end2 ; i=(i+1)%24)
			 {
					if((Node1[i].color!=0||start2==-1||end2==-1) && (i!=start2))
					{
						arc=0;
						break;
					}
					if(Node1[i].arc==1)
					{
						arc=1;
					}

			}
			if(arc==1)
			{
				position[positionFrom.x][positionFrom.y]=temp;
				return true;
			}

			for(i=end2 ; i!=start2 ; i=(i+1)%24)
			{
				if((Node1[i].color!=0||start2==-1||end2==-1)&& (i!=end2))
				{
					arc=0;
					break;
				}
				if(Node1[i].arc==1)
				{
					arc=1;
				}

			}
			if(arc==1)
			{
				position[positionFrom.x][positionFrom.y]=temp;
				return true;
			}
		}





		 //内环
		 start1=-1;
		 start2=-1;
		 end1=-1;
		 end2=-1;
		 for(i=0;i<24;i++)
		 {
			if(Node2[i].i==positionFrom.x && Node2[i].j==positionFrom.y)//起点
			{
				if(start1==-1)
				{
					start1=i;
				}
				else
				{
					start2=i;
				}
			}
			if(Node2[i].i==positionTo.x && Node2[i].j==positionTo.y)//终点
			{
				if(end1==-1)
				{
					end1=i;
				}
				else
				{
					end2=i;
				}
			}
		 }



		 //判断内环
		 if(start1!=-1&&end1!=-1)
		 {
			for(i=start1 ; i!=end1 ; i=(i+1)%24)
			 {
				 if((Node2[i].color!=0) && (i!=start1))
				 {
					arc=0;
					break;
				 }
				 if(Node2[i].arc==1)
					 arc=1;
			 }
			 if(arc==1)
			 {
				 position[positionFrom.x][positionFrom.y]=temp;
				 return true;
			 }

			 for(i=end1 ; i!=start1 ; i=(i+1)%24)
			 {
				 if((Node2[i].color!=0) && (i!=end1))
				 {
					arc=0;
					break;
				 }
				 if(Node2[i].arc==1)
					 arc=1;
			 }
			 if(arc==1)
			 {
				 position[positionFrom.x][positionFrom.y]=temp;
				 return true;
			 }
		 }
			 if(start2!=-1&&end1!=-1)
			 {
				for(i=start2 ; i!=end1 ; i=(i+1)%24)
				 {
					 if((Node2[i].color!=0||start2==-1) && (i!=start2))
					 {
						arc=0;
						break;
					 }
					 if(Node2[i].arc==1)
						 arc=1;
				 }
				 if(arc==1)
				 {
					 position[positionFrom.x][positionFrom.y]=temp;
					 return true;
				 }

				 for(i=end1 ; i!=start2 ; i=(i+1)%24)
				 {
					 if((Node2[i].color!=0||start2==-1) && (i!=end1))
					 {
						arc=0;
						break;
					 }
					 if(Node2[i].arc==1)
						 arc=1;
				 }
				 if(arc==1)
				 {
					 position[positionFrom.x][positionFrom.y]=temp;
					 return true;
				 }
			 }


				 if(end2!=-1&&start1!=-1)
				 {
					for(i=start1 ; i!=end2 ; i=(i+1)%24)
					 {
						 if((Node2[i].color!=0||end2==-1) && (i!=start1))
						 {
							arc=0;
							break;
						 }
						 if(Node2[i].arc==1)
							 arc=1;
					 }
					 if(arc==1)
					 {
						 position[positionFrom.x][positionFrom.y]=temp;
						 return true;
					 }
					for(i=end2 ; i!=start1 ; i=(i+1)%24)
					 {
						 if((Node2[i].color!=0||end2==-1) && (i!=end2))
						 {
							arc=0;
							break;
						 }
						 if(Node2[i].arc==1)
							 arc=1;
					 }
					 if(arc==1)
					 {
						 position[positionFrom.x][positionFrom.y]=temp;
						 return true;
					 }
				 }


				 if(start2!=-1&&end2!=-1)
				 {
					 for(i=start2 ; i!=end2 ; i=(i+1)%24)
					 {
						 if((Node2[i].color!=0||start2==-1||end2==-1) && (i!=start2))
						 {
							arc=0;
							break;
						 }
						 if(Node2[i].arc==1)
							 arc=1;
					 }
					 if(arc==1)
					 {
						 position[positionFrom.x][positionFrom.y]=temp;
						 return true;
					 }

					 for(i=end2 ; i!=start2 ; i=(i+1)%24)
					 {
						 if((Node2[i].color!=0||start2==-1||end2==-1) && (i!=end2))
						 {
							arc=0;
							break;
						 }
						 if(Node2[i].arc==1)
							 arc=1;
					 }
					 if(arc==1)
					 {
						 position[positionFrom.x][positionFrom.y]=temp;
						 return true;
					 }
				 }
			 	position[positionFrom.x][positionFrom.y]=temp;
			 	return false;
	 	}
	 	else
		{
			return false;
		}

}
void Sur::PlayManToMan()
{
    char a,b;
    Init();
    Drawboard();

    time_t now_time=time(NULL);
    tm *ltm = localtime(&now_time);
    ofstream outfile("C4.txt");
    outfile << "#" << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday
    <<"-"<<ltm->tm_hour << ":" << ltm->tm_min <<"|"<< "沈阳"<<endl;
    outfile<<"#先手方:苏1队|后手方:苏2队|后手胜"<<endl;
    outfile<<"!BBBBBB"<<endl;
    outfile<<"!BBBBBB"<<endl;
    outfile<<"!000000"<<endl;
    outfile<<"!000000"<<endl;
    outfile<<"!RRRRRR"<<endl;
    outfile<<"!RRRRRR"<<endl;
    //outfile.close();
    //生成可下位置坐标
    //vector<MovePosition> A;
    //A=GenerateMovePosition(side);
    //displayCanMove(A);
    while(1)
    {
        //判断鼠标是否按下
        if(ismouseclick(WM_LBUTTONDOWN) && side==1 && count==0)
        {
            positionFrom.y=(mousex()-125)/50;
            positionFrom.x=(mousey()-125)/50;
            //判断第一次是否为己方棋子
            if(board[positionFrom.x][positionFrom.y]==1)
            {
                count++;
            }
            Drawboard();
            clearmouseclick(WM_LBUTTONDOWN);
        }
        //判断第二次是否为可下位置
        if(ismouseclick(WM_LBUTTONDOWN)&&side==1&&count==1)
        {
            positionTo.y=(mousex()-125)/50;
            positionTo.x=(mousey()-125)/50;
            if(isLegal(board,positionFrom,positionTo))
            {
                //cout<<"OK1"<<endl;
                //空位置
                if(board[positionTo.x][positionTo.y]==0)
                {
                    //落子
                    board[positionFrom.x][positionFrom.y]=0;
                    board[positionTo.x][positionTo.y]=1;
                    a=positionFrom.y+65;
                    b=positionTo.y+65;
                    outfile<<"B"<<positionFrom.x+1<<a<<"-"<<positionTo.x+1<<b<<endl;
                    //判断输赢
                    if(Iswin(board,side))
                    {
                        break;
                    }
                    count++;
                    count=count%2;
                    side*=-1;
                    cleardevice();
                    Drawboard();
                }
                //吃棋位置
                if(board[positionTo.x][positionTo.y]==-1)
                {
                    board[positionFrom.x][positionFrom.y]=0;
                    board[positionTo.x][positionTo.y]=1;
                    count++;
                    count=count%2;
                    side*=-1;
                    cleardevice();
                    Drawboard();
                    //将数字转为字母
                    a=positionFrom.y+65;
                    b=positionTo.y+65;
                    outfile<<"B"<<positionFrom.x+1<<a<<"x"<<positionTo.x+1<<b<<endl;
                    if(Iswin(board,side))
                    {
                        break;
                    }
                }
                //A=GenerateMovePosition(side);
               // displayCanMove(A);

            }
            else
            {
                count=0;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
        //判断鼠标是否按下
        if(ismouseclick(WM_LBUTTONDOWN) && side==-1 && count==0)
        {
            positionFrom.y=(mousex()-125)/50;
            positionFrom.x=(mousey()-125)/50;
            //判断第一次是否为己方棋子
            if(board[positionFrom.x][positionFrom.y]==-1)
            {
                count++;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
        //判断第一次是否为可下棋子
        if(ismouseclick(WM_LBUTTONDOWN)&&side==-1&&count==1)
        {
            positionTo.y=(mousex()-125)/50;
            positionTo.x=(mousey()-125)/50;
            if(isLegal(board,positionFrom,positionTo))
            {
                //cout<<"OK2"<<endl;
                if(board[positionTo.x][positionTo.y]==0)
                {
                    board[positionFrom.x][positionFrom.y]=0;
                    board[positionTo.x][positionTo.y]=-1;
                     a=positionFrom.y+65;
                    b=positionTo.y+65;
                    outfile<<"R"<<positionFrom.x+1<<a<<"-"<<positionTo.x+1<<b<<endl;
                    if(Iswin(board,side))
                    {
                        break;
                    }
                    count++;
                    count=count%2;
                    side*=-1;

                    cleardevice();
                    Drawboard();
                }
                if(board[positionTo.x][positionTo.y]==1)
                {
                    board[positionFrom.x][positionFrom.y]=0;
                    board[positionTo.x][positionTo.y]=-1;
                     a=positionFrom.y+65;
                    b=positionTo.y+65;
                    outfile<<"R"<<positionFrom.x+1<<a<<"x"<<positionTo.x+1<<b<<endl;
                    cleardevice();
                    Drawboard();
                    if(Iswin(board,side))
                    {
                        break;
                    }
                    count++;
                    count=count%2;
                    side*=-1;
                }
                //A=GenerateMovePosition(side);
                //displayCanMove(A);

            }
            else
            {
                count=0;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
    outfile.close();
}
vector<MovePosition> Sur::GenerateMovePosition(int side)
{
    vector<MovePosition> chessMovePosition;//记录棋子可下位置的向量
    vector<Position> chessposition;
    MovePosition chessPos;  //由原点到目标点的下棋位置
    Position pos;
    //返回棋子数量位置向量
    /*for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(board[i][j]==side)
            {
                pos.x=i;
                pos.y=j;
                chessposition.push_back(pos);
            }
        }
    }
    //生成走子可下位置
    //正常位置
    for(int i=0;i<(int) chessposition.size();i++)
    {
        if(chessposition[i].x==0&&chessposition[i].y==0)
        {
            if(board[chessposition[i].x][chessposition[i].y+1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x;
                chessPos.To.y=chessposition[i].y+1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x+1][chessposition[i].y]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x+1;
                chessPos.To.y=chessposition[i].y;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x+1][chessposition[i].y+1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x+1;
                chessPos.To.y=chessposition[i].y+1;
                chessMovePosition.push_back(chessPos);
            }
        }//(0,0)
        else if(chessposition[i].x==5&&chessposition[i].y==5)
        {
            if(board[chessposition[i].x][chessposition[i].y-1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x;
                chessPos.To.y=chessposition[i].y-1;
                chessMovePosition.push_back(chessPos);
            }

            if(board[chessposition[i].x-1][chessposition[i].y]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x-1;
                chessPos.To.y=chessposition[i].y;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x-1][chessposition[i].y-1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x-1;
                chessPos.To.y=chessposition[i].y-1;
                chessMovePosition.push_back(chessPos);
            }

        }//(5,5)
        else if(chessposition[i].x==0&&chessposition[i].y==5)
        {
            if(board[chessposition[i].x][chessposition[i].y-1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x;
                chessPos.To.y=chessposition[i].y-1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x+1][chessposition[i].y]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x+1;
                chessPos.To.y=chessposition[i].y;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x+1][chessposition[i].y-1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x+1;
                chessPos.To.y=chessposition[i].y-1;
                chessMovePosition.push_back(chessPos);
            }
        }//(0,5)
        else if(chessposition[i].x==5&&chessposition[i].y==0)
        {
            if(board[chessposition[i].x-1][chessposition[i].y]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x-1;
                chessPos.To.y=chessposition[i].y;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x][chessposition[i].y+1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x;
                chessPos.To.y=chessposition[i].y+1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x-1][chessposition[i].y+1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x-1;
                chessPos.To.y=chessposition[i].y+1;
                chessMovePosition.push_back(chessPos);
            }
        }//(5,0)
        else if(chessposition[i].x!=0&&chessposition[i].x!=5&&chessposition[i].y==0)
        {
            if(board[chessposition[i].x-1][chessposition[i].y]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x-1;
                chessPos.To.y=chessposition[i].y;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x+1][chessposition[i].y]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x+1;
                chessPos.To.y=chessposition[i].y;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x][chessposition[i].y+1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x;
                chessPos.To.y=chessposition[i].y+1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x-1][chessposition[i].y+1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x-1;
                chessPos.To.y=chessposition[i].y+1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x+1][chessposition[i].y+1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x+1;
                chessPos.To.y=chessposition[i].y+1;
                chessMovePosition.push_back(chessPos);
            }
        }//y=0
        else if(chessposition[i].x!=0&&chessposition[i].x!=5&&chessposition[i].y==5)
        {
            if(board[chessposition[i].x-1][chessposition[i].y]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x-1;
                chessPos.To.y=chessposition[i].y;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x+1][chessposition[i].y]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x+1;
                chessPos.To.y=chessposition[i].y;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x][chessposition[i].y-1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x;
                chessPos.To.y=chessposition[i].y-1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x-1][chessposition[i].y-1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x-1;
                chessPos.To.y=chessposition[i].y-1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x+1][chessposition[i].y-1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x+1;
                chessPos.To.y=chessposition[i].y-1;
                chessMovePosition.push_back(chessPos);
            }
        }//y=5
        else if(chessposition[i].x==0&&chessposition[i].y!=5&&chessposition[i].y!=0)
        {
            if(board[chessposition[i].x][chessposition[i].y-1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x;
                chessPos.To.y=chessposition[i].y-1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x][chessposition[i].y+1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x;
                chessPos.To.y=chessposition[i].y+1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x+1][chessposition[i].y]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x+1;
                chessPos.To.y=chessposition[i].y;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x+1][chessposition[i].y-1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x+1;
                chessPos.To.y=chessposition[i].y-1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x+1][chessposition[i].y+1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x+1;
                chessPos.To.y=chessposition[i].y+1;
                chessMovePosition.push_back(chessPos);
            }
        }//x=0
        else if(chessposition[i].x==5&&chessposition[i].y!=5&&chessposition[i].y!=0)
        {
            if(board[chessposition[i].x][chessposition[i].y-1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x;
                chessPos.To.y=chessposition[i].y-1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x][chessposition[i].y+1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x;
                chessPos.To.y=chessposition[i].y+1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x-1][chessposition[i].y]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x-1;
                chessPos.To.y=chessposition[i].y;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x-1][chessposition[i].y-1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x-1;
                chessPos.To.y=chessposition[i].y-1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x-1][chessposition[i].y+1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x-1;
                chessPos.To.y=chessposition[i].y+1;
                chessMovePosition.push_back(chessPos);
            }
        }//x=5
        else
        {
            if(board[chessposition[i].x][chessposition[i].y-1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x;
                chessPos.To.y=chessposition[i].y-1;
                chessMovePosition.push_back(chessPos);
            }

            if(board[chessposition[i].x-1][chessposition[i].y]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x-1;
                chessPos.To.y=chessposition[i].y;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x][chessposition[i].y+1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x;
                chessPos.To.y=chessposition[i].y+1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x+1][chessposition[i].y]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x+1;
                chessPos.To.y=chessposition[i].y;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x-1][chessposition[i].y-1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x-1;
                chessPos.To.y=chessposition[i].y-1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x-1][chessposition[i].y+1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x-1;
                chessPos.To.y=chessposition[i].y+1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x+1][chessposition[i].y+1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x+1;
                chessPos.To.y=chessposition[i].y+1;
                chessMovePosition.push_back(chessPos);
            }
            if(board[chessposition[i].x+1][chessposition[i].y-1]==BACKGROUND)
            {
                chessPos.From.x=chessposition[i].x;
                chessPos.From.y=chessposition[i].y;
                chessPos.To.x=chessposition[i].x+1;
                chessPos.To.y=chessposition[i].y-1;
                chessMovePosition.push_back(chessPos);
            }
        }
    }
    //可吃位置
    for(int k=0;k< (int) chessposition.size();k++)
    {
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
                if(board[i][j] == -side )
                {
                    Position W,B;
                    B.x=i;
                    B.y=j;
                    W.x=chessposition[k].x;
                    W.y=chessposition[k].y;
                    if(isLegal(board,W,B))
                    {
                        chessPos.From.x=chessposition[k].x;
                        chessPos.From.y=chessposition[k].y;
                        chessPos.To.x=i;
                        chessPos.To.y=j;
                        chessMovePosition.push_back(chessPos);
                    }
                }
            }
        }
    }*/
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(board[i][j] == side )
            {
                if(i+1<6 && board[i+1][j]==0)
                {
                    chessPos.From.x=i;
                    chessPos.From.y=j;
                    chessPos.To.x=i+1;
                    chessPos.To.y=j;
                    chessMovePosition.push_back(chessPos);

                }
                if(i-1>=0 && board[i-1][j]==0)
                {
                    chessPos.From.x=i;
                    chessPos.From.y=j;
                    chessPos.To.x=i-1;
                    chessPos.To.y=j;
                    chessMovePosition.push_back(chessPos);

                }
                if(j+1<6 && board[i][j+1]==0)
                {
                    chessPos.From.x=i;
                    chessPos.From.y=j;
                    chessPos.To.x=i;
                    chessPos.To.y=j+1;
                    chessMovePosition.push_back(chessPos);

                }
                if(j-1>=0 && board[i][j-1]==0)
                {
                    chessPos.From.x=i;
                    chessPos.From.y=j;
                    chessPos.To.x=i;
                    chessPos.To.y=j-1;
                    chessMovePosition.push_back(chessPos);

                }
                if(i-1>=0 && j-1>=0 && board[i-1][j-1]==0)
                {
                    chessPos.From.x=i;
                    chessPos.From.y=j;
                    chessPos.To.x=i-1;
                    chessPos.To.y=j-1;
                    chessMovePosition.push_back(chessPos);

                }
                if(j+1<6 && i+1<6 && board[i+1][j+1]==0)
                {
                    chessPos.From.x=i;
                    chessPos.From.y=j;
                    chessPos.To.x=i+1;
                    chessPos.To.y=j+1;
                    chessMovePosition.push_back(chessPos);

                }
                if(i-1>=0 && j+1<6 && board[i-1][j+1]==0)
                {
                    chessPos.From.x=i;
                    chessPos.From.y=j;
                    chessPos.To.x=i-1;
                    chessPos.To.y=j+1;
                    chessMovePosition.push_back(chessPos);

                }
                if(i+1<6 && j-1>=0 && board[i+1][j-1]==0)
                {
                    chessPos.From.x=i;
                    chessPos.From.y=j;
                    chessPos.To.x=i+1;
                    chessPos.To.y=j-1;
                    chessMovePosition.push_back(chessPos);

                }
                for(int k=0;k<6;k++)
                {
                    for(int m=0;m<6;m++)
                    {
                        if(board[k][m] == -side)
                        {
                            Position W,B;
                            B.x=i;
                            B.y=j;
                            W.x=k;
                            W.y=m;
                            if(isLegal(board,B,W))
                            {
                                chessPos.From.x=i;
                                chessPos.From.y=j;
                                chessPos.To.x=k;
                                chessPos.To.y=m;
                                chessMovePosition.push_back(chessPos);
                            }
                        }
                    }
                }
            }
        }
    }
    return chessMovePosition;
}
void Sur::displayCanMove(vector<MovePosition> vec)
{
    //输出可下位置起始坐标
    for(int i=0;i< (int) vec.size();i++)
    {
        cout<<vec[i].From.x<<" "<<vec[i].From.y<<endl;
        cout<<vec[i].To.x<<" "<<vec[i].To.y<<endl;
        cout<<endl;
    }
}
int Sur::Value1(int board[6][6],int side)
{
    int num1=0;
    int num2=0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(board[i][j] == 1 )
            {
                num1++;
            }
            if(board[i][j] == -1 )
            {
                num2++;
            }
        }
    }
    if(side == 1)
    {
        return (num1-num2)*1000;
    }
    else
    {
        return (num2-num1)*1000;
    }
}
int Sur::Value2(int board[6][6],int side)
{
    int V2=0;
    int temp1[6][6]={
    {5,30,20,20,30,5},
    {30,70,50,50,70,30},
    {20,50,60,60,50,20},
    {20,50,60,60,50,20},
    {30,70,50,50,70,30},
    {5,30,20,20,30,5}};
    int temp2[6][6]={
    {5,30,20,20,30,5},
    {30,60,50,50,60,30},
    {20,50,60,60,50,20},
    {20,50,60,60,50,20},
    {30,60,50,50,60,30},
    {5,30,25,25,30,5}};
    int temp3[6][6]={
    {5,35,20,20,35,5},
    {35,50,70,70,50,35},
    {20,70,60,60,70,20},
    {20,70,60,60,70,20},
    {35,50,70,70,50,35},
    {5,35,20,20,35,5}};
    int n=0;
    //判断当前棋盘棋子数量
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(board[i][j] !=0)
            {
                n++;
            }
        }
    }
    //数量大于18情况
    if( n >= 18 )
    {
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
                if(board[i][j]==side)
                {
                    V2+=temp1[i][j];
                }
            }
        }
    }



    //数量在8到18情况
    else if(n>8 && n<18)
    {
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
                if(board[i][j]==side)
                {
                    V2+=temp2[i][j];
                }

            }
        }
    }
		//其他情况
    else
    {
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
                if(board[i][j]==side)
                {
                    V2+=temp3[i][j];
                }
            }
        }
    }
    return V2;
}
int Sur::Value3(int position[6][6],int side)
{
		int sumBlackIn=0;
		int sumWhiteIn=0;
		int sumBlackOut=0;
		int sumWhiteOut=0;
		int sumBlackDouble=0;
		int sumWhiteDouble=0;
		int sumArc=0;
		if(position[0][0]!=0)
		{
			sumArc++;
		}
		//
		if(position[0][5]!=0)
		{
			sumArc++;
		}
		//
		if(position[5][0]!=0)
		{
			sumArc++;
		}
		//
		if(position[5][5]!=0)
		{
			sumArc++;
		}
		//
		if(position[1][1]==1)
		{
			sumBlackIn++;
		}
		if(position[1][1]==-1)
		{
			sumWhiteIn++;
		}
		//
		if(position[1][4]==1)
		{
			sumBlackIn++;
		}
		if(position[1][4]==-1)
		{
			sumWhiteIn++;
		}
		//
		if(position[4][1]==1)
		{
			sumBlackIn++;
		}
		if(position[4][4]==-1)
		{
			sumWhiteIn++;
		}
		//
		if(position[2][2]==1)
		{
			sumBlackOut++;
		}
		if(position[2][2]==-1)
		{
			sumWhiteOut++;
		}
		//
		if(position[2][3]==1)
		{
			sumBlackOut++;
		}
		if(position[2][3]==-1)
		{
			sumWhiteOut++;
		}
		//
		if(position[3][2]==1)
		{
			sumBlackOut++;
		}
		if(position[3][2]==-1)
		{
			sumWhiteOut++;
		}
		//
		if(position[3][3]==1)
		{
			sumBlackOut++;
		}
		if(position[3][3]==-1)
		{
			sumWhiteOut++;
		}
		//
		if(position[1][2]==1)
		{
			sumBlackDouble++;
		}
		if(position[1][2]==-1)
		{
			sumWhiteDouble++;
		}
		//
		if(position[1][3]==1)
		{
			sumBlackDouble++;
		}
		if(position[1][3]==-1)
		{
			sumWhiteDouble++;
		}
		//
		if(position[2][1]==1)
		{
			sumBlackDouble++;
		}
		if(position[2][1]==-1)
		{
			sumWhiteDouble++;
		}
		//
		if(position[2][4]==1)
		{
			sumBlackDouble++;
		}
		if(position[2][4]==-1)
		{
			sumWhiteDouble++;
		}
		//
		if(position[3][1]==1)
		{
			sumBlackDouble++;
		}
		if(position[3][1]==-1)
		{
			sumWhiteDouble++;
		}
		//
		if(position[3][4]==1)
		{
			sumBlackDouble++;
		}
		if(position[3][4]==-1)
		{
			sumWhiteDouble++;
		}
		//
		if(position[4][2]==1)
		{
			sumBlackDouble++;
		}
		if(position[4][2]==-1)
		{
			sumWhiteDouble++;
		}
		//
		if(position[4][3]==1)
		{
			sumBlackDouble++;
		}
		if(position[4][3]==-1)
		{
			sumWhiteDouble++;
		}
		if (side==1)
			return (sumBlackOut-sumWhiteOut)*2+(sumBlackIn-sumWhiteIn)*(6+(sumArc)*1)+(sumBlackDouble-sumWhiteDouble)*3;
		else
			return (sumWhiteOut-sumBlackOut)*2+(sumWhiteIn-sumBlackIn)*(6+(sumArc)*1)+(sumWhiteDouble-sumBlackDouble)*3;
}
int Sur::Value5(int position[6][6],int side)
{
		int Cur[6][6] ;//构造虚拟棋盘

		int flag=1,i,j,m,n;
		int sumStateBlack=0;//吃
		int sumStateRed=0;
		for (i=0;i<6;i++)
		{
			for (j=0;j<6;j++)
			{
				Cur[i][j]=position[i][j];
			}
		}
		for (i=0;i<6;i++)
		{
			for (j=0;j<6;j++)
			{
				if(Cur[i][j]!=0)
				{
					for (m=0;m<6;m++)
					{
						for(n=0;n<6;n++)//遍历所有走法
						{
						    Position W,B;
                            B.x=i;
                            B.y=j;
                            W.x=m;
                            W.y=n;
							if((isLegal(position,B,W)) && (position[m][n]+position[i][j]==0))
							{
								if(position[i][j]==1 && side==1)//black
								{
									sumStateBlack+=3;
								}
								else if(position[i][j]==1 && side !=1)
								{
									sumStateBlack++;
								}
								else if(position[i][j]==-1 && side ==1)//red
								{
									sumStateRed++;
								}
								else if(position[i][j]==-1 && side!=1)
								{
									sumStateRed+=3;
								}
								if((!isLegal(position,W,B)))
								{
									if(position[i][j]==1)//black
									{
										sumStateBlack=sumStateBlack+5;
									}
									else if(position[i][j]==-1)//red
									{
										sumStateRed=sumStateRed+5;
									}
								}
							}
						}
					}
				}
			}
		}
		if (side == 1)
        {
            return (sumStateBlack-sumStateRed)*20;
        }

		else
        {
            return (sumStateRed-sumStateBlack)*20;
        }

}
int Sur::Valuation(int position[6][6],int side)
{
    	int redchess= 0;
		int blackchess = 0;
		for(int i = 0;i<6;i++)
		{
			for(int j =0; j<6;j++)
			{
				if(position[i][j]==1)
                {
                    blackchess++;
                }
				if(position[i][j]==-1)
                {
                    redchess++;
                }

			}
		}
		if(side == 1)
		{
		    //当黑子大于白子且黑子大于6时，位置较为重要
			if((blackchess>redchess)&& blackchess>6)
			{
				return Value1(position,side)+Value2(position,side)+Value3(position,side)+Value5(position,side)-Value2(position,-side);
			}
            //其他棋子和被吃情况比较重要
			else
			{
				return Value1(position,side)+Value5(position,side);
			}
		}
		else
		{
			if((redchess>blackchess)&&redchess>6)
			{
				return Value1(position,side)+Value2(position,side)+Value3(position,side)+Value5(position,side)-Value2(position,-side);
			}
			else
			{
				return Value1(position,side)+Value5(position,side);
			}
		}
}
int Sur::AlphaBeta(int depth,int alpha,int beta,int side)
{
    vector<MovePosition> vecpos=GenerateMovePosition(side);

    int xFrom;
    int yFrom;
    int xTo;
    int yTo;
    /*if(IsGameOver(board,depth) != 0)
    {
        return IsGameOver(board,depth);
    }*/
    if(depth==0||vecpos.size()==0)
    {
        side=-side;
        return Valuation(board,-side);
    }
    int g;
    int m=0;//m为标记值(m为0则走子，为1则吃子)

    for(int i=0;i<(int) vecpos.size();i++)
    {
        if(board[vecpos[i].To.x][vecpos[i].To.y]==-side)
        {
            m=1;
        }
        board[vecpos[i].From.x][vecpos[i].From.y]=0;
        board[vecpos[i].To.x][vecpos[i].To.y]=side;

        g=-AlphaBeta(depth-1,-beta,-alpha,-side);
        //还原棋盘
        if(m==1)
        {
            board[vecpos[i].To.x][vecpos[i].To.y]=-side;
            board[vecpos[i].From.x][vecpos[i].From.y]=side;
        }
        else
        {
            board[vecpos[i].To.x][vecpos[i].To.y]=0;
            board[vecpos[i].From.x][vecpos[i].From.y]=side;
        }
        m=0;//重置
        if(g>=beta)
        {
            return beta;
        }
        if(g>alpha)
        {
            alpha=g;
            xTo=vecpos[i].To.x;
            yTo=vecpos[i].To.y;
            xFrom=vecpos[i].From.x;
            yFrom=vecpos[i].From.y;
        }
    }
    bestPosition.From.x=xFrom;
    bestPosition.From.y=yFrom;
    bestPosition.To.x=xTo;
    bestPosition.To.y=yTo;
    return alpha;

}
int Sur::PVS(int depth,int alpha,int beta,int side)
{
    int score;
    int val;
    int m=0;
    int current;
    if(IsGameOver(board,depth) != 0)
    {
        return IsGameOver(board,depth);
    }
    score = hash.LookUpHashTable(alpha,beta,depth,(MaxDepth-depth)%2);
    if(score !=66666)
    {
        return score;
    }
    vector<MovePosition> vec = GenerateMovePosition(side);
    if(depth == 0 || vec.size() == 0)
    {
        score = Valuation(board,side);
        hash.EnterHashTable(exact,score,depth,(MaxDepth-depth)%2);
        return score;
    }
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].Score=GetHistoryScore(vec[i]);
        //vec[i].Score=-Valuation(board,-side);

    }
    Sort(vec);
    hash.Hash_MakeMove(vec[0],board,side);
    if(board[vec[0].To.x][vec[0].To.y]==-side)
    {
            m=1;
    }
    board[vec[0].From.x][vec[0].From.y]=0;
    board[vec[0].To.x][vec[0].To.y]=side;
    current=-PVS(depth-1,-beta,-alpha,-side);
    hash.Hash_UnMakeMove(vec[0],board,side);
    if(m==1)
    {
        board[vec[0].To.x][vec[0].To.y]=-side;
        board[vec[0].From.x][vec[0].From.y]=side;
        m=0;//重置
    }
    else
    {
        board[vec[0].To.x][vec[0].To.y]=0;
        board[vec[0].From.x][vec[0].From.y]=side;
    }
    for(int i = 1;i < vec.size();i++)
    {
        hash.Hash_MakeMove(vec[i],board,side);
        if(board[vec[i].To.x][vec[i].To.y]==-side)
        {
            m=1;
        }
        board[vec[i].From.x][vec[i].From.y]=0;
        board[vec[i].To.x][vec[i].To.y]=side;
        score=-PVS(depth-1,-alpha-1,-alpha,-side);
        if(score >alpha && score<beta)
        {
            score=-PVS(depth-1,-beta,-alpha,-side);
        }
        hash.Hash_UnMakeMove(vec[i],board,side);
        if(m==1)
        {
            board[vec[i].To.x][vec[i].To.y]=-side;
            board[vec[i].From.x][vec[i].From.y]=side;
            m=0;//重置
        }
        else
        {
            board[vec[i].To.x][vec[i].To.y]=0;
            board[vec[i].From.x][vec[i].From.y]=side;
        }

        if (score >= current)
        {
            current=score;
            bestPosition=vec[i];
            if(score >= alpha)
            {
                alpha=score;
            }
            if(score >=beta)
            {
                break;
            }
        }


    }
    return current;

}
int Sur::AlphaBeta_Hash(int depth,int alpha,int beta,int side)
{
    bool Found = false;
    int score;
    int val;
    int m=0;
    //判断当前棋局是否结束
    /*if(IsGameOver(board,depth) != 0)
    {
        return IsGameOver(board,depth);//使用之后会出现残局不吃子情况
    }*/
    //在开局库中查找当前棋盘的Hash值
    score = hash.LookUpHashTable(alpha,beta,depth,(MaxDepth-depth)%2);
    if(score !=66666)
    {
        return score;
    }
    //生成可下位置
    vector<MovePosition> vec = GenerateMovePosition(side);
    if(depth == 0 || vec.size() == 0)
    {
        score = Valuation(board,side);
        //当前节点插入Hash表
        hash.EnterHashTable(exact,score,depth,(MaxDepth-depth)%2);
        return score;
    }
    //遍历所有得分
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].Score=GetHistoryScore(vec[i]);
    }
    //排序
    Sort(vec);
    //标志最佳走法
    int bestmove=-1;
    int eval_is_exact = 0;
    //遍历当前棋局所有走法
    for(int i = 0;i < vec.size();i++)
    {
        //根根据走法更新棋盘数组，生成第i个棋局
        hash.Hash_MakeMove(vec[i],board,side);
        if(board[vec[i].To.x][vec[i].To.y]==-side)
        {
            //判断是否吃子的标志
            m=1;
        }
        //cout<<vec[i].From.x<<vec[i].From.y<<vec[i].To.x<<vec[i].To.y<<endl;
        board[vec[i].From.x][vec[i].From.y]=0;
        board[vec[i].To.x][vec[i].To.y]=side;
        //进行下一层搜素
        if(Found)
        {
            val = -AlphaBeta_Hash(depth - 1,-alpha - 1,-alpha,-side);
            if((val > alpha) && (val < beta))
            {
                val = -AlphaBeta_Hash(depth - 1,-beta,-alpha,-side);
            }
        }
        else
        {
            val = -AlphaBeta_Hash(depth - 1,-beta,-alpha,-side);
        }
        //恢复第i个棋局
        hash.Hash_UnMakeMove(vec[i],board,side);
        if(m==1)
        {
            board[vec[i].To.x][vec[i].To.y]=-side;
            board[vec[i].From.x][vec[i].From.y]=side;
        }
        else
        {
            board[vec[i].To.x][vec[i].To.y]=0;
            board[vec[i].From.x][vec[i].From.y]=side;
        }
        m=0;//重置
        if(val > alpha)
        {
            alpha = val;
            Found = true;
            eval_is_exact = 1;
            if(depth==MaxDepth)
            {
                bestPosition= vec[i];

            }
            bestmove=i;
        }
        if(alpha > beta)
        {
            bestmove=i;
            hash.EnterHashTable(lower,val,depth,(MaxDepth-depth)%2);
            return alpha;
        }
    }
    //最佳走法储存
    if(bestmove != -1)
    {
        EnterHistoryScore(vec[bestmove],depth);
    }
    if(eval_is_exact)
    {
        hash.EnterHashTable(exact,alpha,depth,(MaxDepth-depth)%2);
    }
    else
    {
        hash.EnterHashTable(upper,alpha,depth,(MaxDepth-depth)%2);
    }
    return alpha;
}
void Sur::PlayComputerToMan()
{
    int H=0;
    int m=0;
    stack<MovePosition> sk;//数组栈储存信息
    MovePosition move;//储存行走路径
    Init();
    Drawboard();

    char a,b;
    //打印棋谱固定内容
    time_t now_time=time(NULL);
    tm *ltm = localtime(&now_time);
    ofstream outfile("2021省赛棋谱\\A1-B4.txt");
    outfile << "#" << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday
    <<"-"<<ltm->tm_hour << ":" << ltm->tm_min <<"|"<< "沈阳"<<endl;
    outfile<<"#先手方:A1|后手方:B4|先手胜"<<endl;
    outfile<<"!BBBBBB"<<endl;
    outfile<<"!BBBBBB"<<endl;
    outfile<<"!000000"<<endl;
    outfile<<"!000000"<<endl;
    outfile<<"!RRRRRR"<<endl;
    outfile<<"!RRRRRR"<<endl;
    while(1)
    {
        //悔棋，两步
        if(ismouseclick(WM_LBUTTONDOWN))
        {

            if(mousex()>=570 && mousex()<=630 &&mousey()>=250 && mousey()<=300 )
            {
                //释放顶栈
                move=sk.top();
                sk.pop();
                //判断是否吃子
                if(move.To.k == 1)
                {
                    board[move.From.x][move.From.y]=-side;
                    board[move.To.x][move.To.y]=side;
                }
                else
                {
                    board[move.From.x][move.From.y]=-side;
                    board[move.To.x][move.To.y]=0;
                }
                side *=-1;
                move=sk.top();
                sk.pop();
                //判断是否吃子
                if(move.To.k == 1)
                {
                    board[move.From.x][move.From.y]=-side;
                    board[move.To.x][move.To.y]=side;
                }
                else
                {
                    board[move.From.x][move.From.y]=-side;
                    board[move.To.x][move.To.y]=0;
                }
                cleardevice();
                Drawboard();
                side *=-1;

            }
            else if(mousex()>=570 && mousex()<=634 &&mousey()>=150 && mousey()<=214 )
            {
                outfile.close();
                MessageBox(NULL,"保存成功","比赛",MB_OK);
                break;
            }
        }
        if(side == 1 )
        {
            SearchAGoodMove(board,3,side);
            Fmore();
            cout<<" "<<bestPosition.From.x<<" "<<bestPosition.From.y<<bestPosition.To.x<<" "<<bestPosition.To.y<<endl;
            //getBestRandPosition();
            a=bestPosition.From.y+65;
            b=bestPosition.To.y+65;
            if(board[bestPosition.To.x][bestPosition.To.y] != 0)
            {
                bestPosition.To.k=1;
                outfile<<"B"<<bestPosition.From.x+1<<a<<"x"<<bestPosition.To.x+1<<b<<endl;
            }
            else
            {
                bestPosition.To.k=0;
                outfile<<"B"<<bestPosition.From.x+1<<a<<"-"<<bestPosition.To.x+1<<b<<endl;
            }
            sk.push(bestPosition);
            board[bestPosition.From.x][bestPosition.From.y]=0;
            board[bestPosition.To.x][bestPosition.To.y]=side;
            cleardevice();
            Drawboard();
            setcolor(RGB(255, 140 ,105));
            //画出移动位置
            rectangle(bestPosition.From.y*50+130,bestPosition.From.x*50+130
            ,bestPosition.From.y*50+170,bestPosition.From.x*50+170);
            rectangle(bestPosition.To.y*50+130,bestPosition.To.x*50+130
            ,bestPosition.To.y*50+170,bestPosition.To.x*50+170);
            if(Iswin(board,side))
            {
                break;
            }
            side *=-1;

        }
        else if(side == -1)
        {
            if(ismouseclick(WM_LBUTTONDOWN) && side==-1 && count==0)
            {
                positionFrom.y=(mousex()-125)/50;
                positionFrom.x=(mousey()-125)/50;
                if(board[positionFrom.x][positionFrom.y]==-1)
                {
                    count++;
                }
                clearmouseclick(WM_LBUTTONDOWN);
            }
            if(ismouseclick(WM_LBUTTONDOWN)&&side==-1&&count==1)
            {
                positionTo.y=(mousex()-125)/50;
                positionTo.x=(mousey()-125)/50;
                if(isLegal(board,positionFrom,positionTo))
                {
                    //cout<<"OK2"<<endl;
                    if(board[positionTo.x][positionTo.y]==0)
                    {
                        move.From.x=positionFrom.x;
                        move.From.y=positionFrom.y;
                        move.To.x=positionTo.x;
                        move.To.y=positionTo.y;
                        move.To.k=0;
                        sk.push(move);
                        board[positionFrom.x][positionFrom.y]=0;
                        board[positionTo.x][positionTo.y]=-1;
                        a=positionFrom.y+65;
                        b=positionTo.y+65;
                        outfile<<"R"<<positionFrom.x+1<<a<<"-"<<positionTo.x+1<<b<<endl;
                        count++;
                        count=count%2;
                        side*=-1;
                        if(Iswin(board,side))
                        {
                            break;
                        }


                        cleardevice();
                       Drawboard();
                    }
                    if(board[positionTo.x][positionTo.y]==1)
                    {
                        move.From.x=positionFrom.x;
                        move.From.y=positionFrom.y;
                        move.To.x=positionTo.x;
                        move.To.y=positionTo.y;
                        move.To.k=1;
                        board[positionFrom.x][positionFrom.y]=0;
                        board[positionTo.x][positionTo.y]=-1;
                        a=positionFrom.y+65;
                        b=positionTo.y+65;
                        outfile<<"R"<<positionFrom.x+1<<a<<"x"<<positionTo.x+1<<b<<endl;
                        sk.push(move);
                        cleardevice();
                        Drawboard();
                        if(Iswin(board,side))
                        {
                            break;
                        }
                        count++;
                        count=count%2;
                        side*=-1;


                    }
                }
                else
                {
                    count=0;
                }
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
    }
    outfile.close();
    MessageBox(NULL,"保存已保存","比赛",MB_OK);
    //Game();
}
void Sur::PlayManToComputer()
{

    int m=0;
    char a,b;
    stack<MovePosition> sk;
    MovePosition move;
    Init();
    Drawboard();

    //打印棋谱固定内容
    time_t now_time=time(NULL);
    tm *ltm = localtime(&now_time);
    ofstream outfile("2021省赛棋谱\\B4-A1.txt");
    outfile << "#" << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday
    <<"-"<<ltm->tm_hour << ":" << ltm->tm_min <<"|"<< "沈阳"<<endl;
    outfile<<"#先手方:B4|后手方:A1|后手胜"<<endl;
    outfile<<"!BBBBBB"<<endl;
    outfile<<"!BBBBBB"<<endl;
    outfile<<"!000000"<<endl;
    outfile<<"!000000"<<endl;
    outfile<<"!RRRRRR"<<endl;
    outfile<<"!RRRRRR"<<endl;
    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if(mousex()>=570 && mousex()<=630 &&mousey()>=250 && mousey()<=300 )
            {
                move=sk.top();
                sk.pop();
                if(move.To.k == 1)
                {
                    board[move.From.x][move.From.y]=-side;
                    board[move.To.x][move.To.y]=side;
                }
                else
                {
                    board[move.From.x][move.From.y]=-side;
                    board[move.To.x][move.To.y]=0;
                }
                side *=-1;
                move=sk.top();
                sk.pop();
                if(move.To.k == 1)
                {
                    board[move.From.x][move.From.y]=-side;
                    board[move.To.x][move.To.y]=side;
                }
                else
                {
                    board[move.From.x][move.From.y]=-side;
                    board[move.To.x][move.To.y]=0;
                }
                cleardevice();
                Drawboard();
                side *=-1;

            }
            else if(mousex()>=570 && mousex()<=634 &&mousey()>=150 && mousey()<=214 )
            {
                outfile.close();
                MessageBox(NULL,"保存成功","比赛",MB_OK);
                break;
            }
        }
        if(side == -1 )
        {
            //g=AlphaBeta(3,-1000,1000,side);
            if(m<500000)
            {
                SearchAGoodMove(board,3,side);
                m++;
            }
            else
            {
                SearchAGoodMove(board,5,side);
                m++;
            }
            More();
            cout<<" "<<bestPosition.To.x<<" "<<bestPosition.To.y;
            //getBestRandPosition();
            a=bestPosition.From.y+65;
            b=bestPosition.To.y+65;
            if(board[bestPosition.To.x][bestPosition.To.y] != 0)
            {
                bestPosition.To.k=1;
                outfile<<"R"<<bestPosition.From.x+1<<a<<"x"<<bestPosition.To.x+1<<b<<endl;
            }
            else
            {
                bestPosition.To.k=0;
                outfile<<"R"<<bestPosition.From.x+1<<a<<"-"<<bestPosition.To.x+1<<b<<endl;
            }
            sk.push(bestPosition);
            board[bestPosition.From.x][bestPosition.From.y]=0;
            board[bestPosition.To.x][bestPosition.To.y]=side;
            cleardevice();
            Drawboard();
            setcolor(RGB(127 ,255, 212));
            //画出移动位置
             rectangle(bestPosition.From.y*50+130,bestPosition.From.x*50+130
            ,bestPosition.From.y*50+170,bestPosition.From.x*50+170);
            rectangle(bestPosition.To.y*50+130,bestPosition.To.x*50+130
            ,bestPosition.To.y*50+170,bestPosition.To.x*50+170);
            if(Iswin(board,side))
            {
                break;
            }
            side *=-1;

        }
        if(ismouseclick(WM_LBUTTONDOWN) && side==1 && count==0)
        {
            positionFrom.y=(mousex()-125)/50;
            positionFrom.x=(mousey()-125)/50;
            if(board[positionFrom.x][positionFrom.y]==1)
            {
                count++;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
        if(ismouseclick(WM_LBUTTONDOWN)&&side==1&&count==1)
        {
            positionTo.y=(mousex()-125)/50;
            positionTo.x=(mousey()-125)/50;
            if(isLegal(board,positionFrom,positionTo))
            {
                //cout<<"OK2"<<endl;
                if(board[positionTo.x][positionTo.y]==0)
                {
                    move.From.x=positionFrom.x;
                    move.From.y=positionFrom.y;
                    move.To.x=positionTo.x;
                    move.To.y=positionTo.y;
                    move.To.k=0;
                    sk.push(move);
                    board[positionFrom.x][positionFrom.y]=0;
                    board[positionTo.x][positionTo.y]=1;
                    a=positionFrom.y+65;
                    b=positionTo.y+65;
                    outfile<<"B"<<positionFrom.x+1<<a<<"-"<<positionTo.x+1<<b<<endl;
                    count++;
                    count=count%2;
                    side*=-1;
                    if(Iswin(board,side))
                    {
                        break;
                    }


                    cleardevice();
                    Drawboard();
                }
                if(board[positionTo.x][positionTo.y]==-1)
                {
                    move.From.x=positionFrom.x;
                    move.From.y=positionFrom.y;
                    move.To.x=positionTo.x;
                    move.To.y=positionTo.y;
                    move.To.k=1;
                    sk.push(move);
                    board[positionFrom.x][positionFrom.y]=0;
                    board[positionTo.x][positionTo.y]=1;
                    a=positionFrom.y+65;
                    b=positionTo.y+65;
                    outfile<<"B"<<positionFrom.x+1<<a<<"x"<<positionTo.x+1<<b<<endl;
                    cleardevice();
                    Drawboard();
                    if(Iswin(board,side))
                    {
                        break;
                    }
                    count++;
                    count=count%2;
                    side*=-1;


                }
            }
            else
            {
                count=0;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
    outfile.close();
    MessageBox(NULL,"保存已保存","比赛",MB_OK);
   //Game();
}
void Sur::Fupan()
{
    Init();
    FPDraw();
    //stack<MovePosition> sk;
    vector<MovePosition> chessMovePosition;
    MovePosition move;
    char szFile[MAX_PATH] = {0};
	if(FileDialog(szFile))
	{
	    //puts(szFile);
	}
	FILE *file=fopen(szFile,"r");
	//将文件内容存到字符数组
    char a[600]="\0";
    if(file == NULL)
    {
        cout<<"open error!"<<endl;
    }
    int i=0;
    char c;
    while((c= fgetc(file)) != EOF)
    {
        a[i]=c;
        i++;
    }
    //快速打谱一遍，将信息存到向量内部
    for(int i=0;i< (int) sizeof(a);i++)
    {
        if((a[i] == 'B' )&& (a[i+1]=='1' || a[i+1]=='2' || a[i+1]=='3' || a[i+1]=='4' || a[i+1]=='5' || a[i+1]=='6'))
        {
            cout<<"黑方下棋"<<"("<<a[i+1]<<","<<a[i+2]<<")"<<"->"<<"("<<a[i+4]<<","<<a[i+5]<<")"<<endl;
            move.From.x=a[i+1]-'0'-1;
            move.From.y=a[i+2]-65;
            move.To.x=a[i+4]-'0'-1;
            move.To.y=a[i+5]-65;
            if(board[a[i+4]-'0'-1][a[i+5]-65] != BACKGROUND)
            {
                move.To.k=1;
            }
            else
            {
                move.To.k=0;
            }
            chessMovePosition.push_back(move);
            board[a[i+1]-'0'-1][a[i+2]-65]=0;
            board[a[i+4]-'0'-1][a[i+5]-65]=side;
            cleardevice();
            FPDraw();
            if(Iswin(board,side))
            {
                break;
            }
            side *=-1;
        }
        if((a[i] == 'R') && (a[i+1]=='1' || a[i+1]=='2' || a[i+1]=='3' || a[i+1]=='4' || a[i+1]=='5' || a[i+1]=='6'))
        {
            cout<<"红方下棋"<<"("<<a[i+1]<<","<<a[i+2]<<")"<<"->"<<"("<<a[i+4]<<","<<a[i+5]<<")"<<endl;
            move.From.x=a[i+1]-'0'-1;
            move.From.y=a[i+2]-65;
            move.To.x=a[i+4]-'0'-1;
            move.To.y=a[i+5]-65;
            if(board[a[i+4]-'0'-1][a[i+5]-65] != BACKGROUND)
            {
                move.To.k=1;
            }
            else
            {
                move.To.k=0;
            }
            chessMovePosition.push_back(move);
            board[a[i+1]-'0'-1][a[i+2]-65]=0;
            board[a[i+4]-'0'-1][a[i+5]-65]=side;
            cleardevice();
            FPDraw();
            if(Iswin(board,side))
            {
                break;
            }
            side *=-1;
        }
    }
    int m1=0;
    for(int k=0;i<2;i++)
    {
        for(int j=0;j<6;j++)
        {
            if((board[k][j]=1) && (board[k+2][j]==0) && (board[k+4][j] == -1))
            {
                m1=1;
            }
            else
            {
                m1=0;
            }
        }
    }
    if(m1 !=0 )
    {
        MessageBox(NULL,"格式有误","打谱",MB_OK);
    }
    Init();
    FPDraw();

    i=0;

    while(i< (int) chessMovePosition.size())
    {
        if(ismouseclick(WM_LBUTTONDOWN) && mousex()>=550 && mousex()<=614   && mousey()>=100 && mousey()<=164)
        {
            setcolor(0);
            outtextxy(20,20,"暂停");
            clearmouseclick(WM_LBUTTONDOWN);
            while(1)
            {
                //开始事件
                if(ismouseclick(WM_LBUTTONDOWN) && mousex()>=550 && mousex()<=614   && mousey()>=200 && mousey()<=264)
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    break;
                }
                //后退
                if(ismouseclick(WM_LBUTTONDOWN) && mousex()>=550 && mousex()<=614   && mousey()>=300 && mousey()<=364)
                {
                        i--;
                        //判断是否吃子
                        if(chessMovePosition[i].To.k == 1)
                        {
                            board[chessMovePosition[i].From.x][chessMovePosition[i].From.y]=-side;
                            board[chessMovePosition[i].To.x][chessMovePosition[i].To.y]=side;
                            side =-side;
                            cleardevice();
                            FPDraw();
                            setcolor(RGB(255, 140 ,105));
                            //画出移动位置
                            rectangle(chessMovePosition[i].From.y*50+130,chessMovePosition[i].From.x*50+130
                            ,chessMovePosition[i].From.y*50+170,chessMovePosition[i].From.x*50+170);
                            rectangle(chessMovePosition[i].To.y*50+130,chessMovePosition[i].To.x*50+130
                            ,chessMovePosition[i].To.y*50+170,chessMovePosition[i].To.x*50+170);

                        }
                        //正常悔棋
                        else
                        {

                            board[chessMovePosition[i].From.x][chessMovePosition[i].From.y]=-side;
                            board[chessMovePosition[i].To.x][chessMovePosition[i].To.y]=0;
                            side *=-1;
                            cleardevice();
                            FPDraw();
                            setcolor(RGB(255, 140 ,105));
                            //画出移动位置
                            rectangle(chessMovePosition[i].From.y*50+130,chessMovePosition[i].From.x*50+130
                            ,chessMovePosition[i].From.y*50+170,chessMovePosition[i].From.x*50+170);
                            rectangle(chessMovePosition[i].To.y*50+130,chessMovePosition[i].To.x*50+130
                            ,chessMovePosition[i].To.y*50+170,chessMovePosition[i].To.x*50+170);
                            //i--;

                        }
                        if(i < 0)
                        {
                            i=0;
                            Init();
                            FPDraw();
                            side=1;
                        }

                    clearmouseclick(WM_LBUTTONDOWN);
                }
                //前进一步
                if(ismouseclick(WM_LBUTTONDOWN) && mousex()>=550 && mousex()<=614   && mousey()>=400 && mousey()<=464)
                {
                    if(side == 1 && i<(int) chessMovePosition.size())
                    {
                        board[chessMovePosition[i].From.x][chessMovePosition[i].From.y]=0;
                        board[chessMovePosition[i].To.x][chessMovePosition[i].To.y]=side;

                        cleardevice();
                        FPDraw();
                        setcolor(RGB(255, 140 ,105));
                        //画出移动位置
                        rectangle(chessMovePosition[i].From.y*50+130,chessMovePosition[i].From.x*50+130
                        ,chessMovePosition[i].From.y*50+170,chessMovePosition[i].From.x*50+170);
                        rectangle(chessMovePosition[i].To.y*50+130,chessMovePosition[i].To.x*50+130
                        ,chessMovePosition[i].To.y*50+170,chessMovePosition[i].To.x*50+170);
                        side *=-1;
                        i++;

                    }
                    else if(side == -1 && i<(int) chessMovePosition.size())
                    {
                        board[chessMovePosition[i].From.x][chessMovePosition[i].From.y]=0;
                        board[chessMovePosition[i].To.x][chessMovePosition[i].To.y]=side;

                        cleardevice();
                        FPDraw();
                        setcolor(RGB(127 ,255, 212));
                        rectangle(chessMovePosition[i].From.y*50+130,chessMovePosition[i].From.x*50+130
                        ,chessMovePosition[i].From.y*50+170,chessMovePosition[i].From.x*50+170);
                        rectangle(chessMovePosition[i].To.y*50+130,chessMovePosition[i].To.x*50+130
                        ,chessMovePosition[i].To.y*50+170,chessMovePosition[i].To.x*50+170);

                        side *=-1;
                        i++;
                    }
                    else
                    {
                        i--;
                        side*=-1;
                        FPDraw();
                    }
                    clearmouseclick(WM_LBUTTONDOWN);
                }
                //回到主界面
                if(ismouseclick(WM_LBUTTONDOWN) && mousex()>=550 && mousex()<=614 && mousey()>=0 && mousey()<=64)
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    Game();
                }

            }
        }
        if(ismouseclick(WM_LBUTTONDOWN) && mousex()>=550 && mousex()<=614 && mousey()>=0 && mousey()<=64)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            Game();
        }
        if(side == 1 && i<(int) chessMovePosition.size())
        {
                board[chessMovePosition[i].From.x][chessMovePosition[i].From.y]=0;
                board[chessMovePosition[i].To.x][chessMovePosition[i].To.y]=side;
                side *=-1;
                cleardevice();
                i++;
                FPDraw();
                setcolor(RGB(255, 140 ,105));
                rectangle(chessMovePosition[i-1].From.y*50+130,chessMovePosition[i-1].From.x*50+130
                ,chessMovePosition[i-1].From.y*50+170,chessMovePosition[i-1].From.x*50+170);
                rectangle(chessMovePosition[i-1].To.y*50+130,chessMovePosition[i-1].To.x*50+130
                ,chessMovePosition[i-1].To.y*50+170,chessMovePosition[i-1].To.x*50+170);
                //Drawboard();
                Sleep(2000);


        }
        else if(side == -1 && i<(int) chessMovePosition.size())
        {
                board[chessMovePosition[i].From.x][chessMovePosition[i].From.y]=0;
                board[chessMovePosition[i].To.x][chessMovePosition[i].To.y]=side;
                side *=-1;
                cleardevice();
                i++;
                FPDraw();
                setcolor(RGB(127 ,255, 212));
                rectangle(chessMovePosition[i-1].From.y*50+130,chessMovePosition[i-1].From.x*50+130
                ,chessMovePosition[i-1].From.y*50+170,chessMovePosition[i-1].From.x*50+170);
                rectangle(chessMovePosition[i-1].To.y*50+130,chessMovePosition[i-1].To.x*50+130
                ,chessMovePosition[i-1].To.y*50+170,chessMovePosition[i-1].To.x*50+170);
                Sleep(2000);
        }
        if(i == (int) chessMovePosition.size())
        {
            i--;
            side*=-1;
            FPDraw();
        }
    }
    fclose(file);
}
int Sur::FileDialog(char *path)
{
    OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn); // 结构大小
    ofn.lpstrFile = path; // 路径
    ofn.nMaxFile = MAX_PATH; // 路径大小
    ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0"; // 文件类型
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	return GetOpenFileName(&ofn);
}
MovePosition Sur::SearchAGoodMove(int board[6][6],int depth,int side)
{
    /*for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            CurPosition[i][j]=board[i][j];
        }
    }*/
    for(int i = 0;i<36;i++)
    {
        for(int j =0;j<36;j++)
        {
            m_HistoryTable[i][j]=0;
        }
    }
    MaxDepth=depth;
    hash.CalculateInitHashKey(board);
    //ResetHistoryTable();
    AlphaBeta_Hash(depth,-20000,20000,side);
    //PVS(depth,-20000,20000,side);
    //AlphaBeta(depth,-20000,20000,side);
    return bestPosition;
}
int Sur::IsGameOver(int position[6][6],int nDepth)//未结束返回0，结束返回极大/极小值
{
		int i,j;
		boolean RedWin=true;
		boolean BlackWin=true;
		for (i=0;i<6;i++)
		{
			for (j=0;j<6;j++)
			{
				if(position[i][j]==1)
				RedWin=false;
				if(position[i][j]==-1)
				BlackWin=false;
			}
		}
		//i=(m_nMaxDepth-nDepth+1)%2;
		if (RedWin)
		{
			if((MaxDepth-nDepth+1)%2==1)
				return 19990+nDepth;
			else
				return -19990-nDepth;
		}
		if (BlackWin)
		{
			if((MaxDepth-nDepth+1)%2==1)
				return -19990-nDepth;
			else
				return 19990+nDepth;
		}
		return 0;
}
//输出历史得分
int Sur::GetHistoryScore(MovePosition move)
{
    int nFrom,nTo;
    nFrom=move.From.x*6+move.From.y;
    nTo=move.To.x*6+move.To.y;
    return m_HistoryTable[nFrom][nTo];
}
//储存历史得分
void Sur::EnterHistoryScore(MovePosition move,int depth)
{
    int nFrom,nTo;
    nFrom=move.From.x*6+move.From.y;
    nTo=move.To.x*6+move.To.y;
    m_HistoryTable[nFrom][nTo] += 2<<depth;//增量2^(depth)
}
void Sur::Game()
{
    readimagefile("C:\\D\\2020\\C++\\Surakarta\\image\\Sur.jpg",0,0,700,600);
    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {

            if(mousex()>=270 && mousex()<=400 && mousey()>=150 && mousey()<=200 )
            {
                clearmouseclick(ismouseclick(WM_LBUTTONDOWN));
                PlayManToComputer();

            }
            else if(mousex()>=270 && mousex()<=400 &&mousey()>=260 && mousey()<=310)
            {
                clearmouseclick(ismouseclick(WM_LBUTTONDOWN));
                PlayComputerToMan();

            }
            else if(mousex()>=260 && mousex()<=400 &&mousey()>=350 && mousey()<=410)
            {
                clearmouseclick(ismouseclick(WM_LBUTTONDOWN));
                Fupan();
            }
        }
        clearmouseclick(ismouseclick(WM_LBUTTONDOWN));
    }
}
bool Sur::isInit()
{
    int k=0;
    for(int i=4;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(board[i][j] != -1)
            {
                k=1;
            }
        }
    }
    if(k == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void Sur::More()
{
    if(board[0][0]== 1 && board[0][3] == 1 && board[0][5] ==1
       && board[1][3] == -1 && board[5][0] ==-1 && board[5][3] ==1
       && board[5][4] == -1 && board[5][5] ==-1)
    {
        bestPosition.From.x=5;
        bestPosition.From.y=4;
        bestPosition.To.x=4;
        bestPosition.To.y=3;
    }
    if(board[0][1]== 1 && board[0][2]== 1 && board[0][3] == 1 && board[1][0] ==1 && board[1][1] ==1
        && board[1][2]== 1 && board[1][3] == 1 && board[2][1]== 1  && board[2][3]== 1 &&
        board[2][5]== 1 && board[3][4]== 1 && board[5][0] ==-1 && board[4][1] ==-1
       && board[5][3] == 0 && board[4][4]== -1 && board[5][5] ==-1 )
    {
        bestPosition.From.x=4;
        bestPosition.From.y=4;
        bestPosition.To.x=3;
        bestPosition.To.y=5;
    }
    /*if( board[3][4]== 0&&bestPosition.From.x==3 && bestPosition.From.y==2 && ((bestPosition.To.x==2 &&
        bestPosition.To.y==2)|| (bestPosition.To.x==3 && bestPosition.To.y==3)))
       {
            bestPosition.From.x=4;
            bestPosition.From.y=4;
            bestPosition.To.x=3;
            bestPosition.To.y=4;
       }
       if(board[5][5]== -1&&board[3][4]== -1&&bestPosition.From.x==3 && bestPosition.From.y==2 && ((bestPosition.To.x==2 &&
        bestPosition.To.y==2)|| (bestPosition.To.x==3 && bestPosition.To.y==3)))
       {
            bestPosition.From.x=5;
            bestPosition.From.y=5;
            bestPosition.To.x=4;
            bestPosition.To.y=4;
       }*/
}
void Sur::Fmore()
{
    if( board[0][0]== 1 && board[0][2]==1 && board[0][3] == 1 && board[0][4] ==1 && board[0][5] ==1
       && board[1][2] == 1 && board[1][3] == 1 && board[1][5] == 1 && board[2][0]==1
      && board[2][2]==1 && board[1][4]==1 && board[3][2]==-1 && board[3][3]== -1
       && board[5][5]== 0)
      {
        bestPosition.From.x=1;
        bestPosition.From.y=4;
        bestPosition.To.x=2;
        bestPosition.To.y=4;
      }
      if( board[0][0]== 1 && board[0][2]==1 && board[0][3] == 1 && board[0][4] ==1 && board[0][5] ==1
       && board[1][2] == 1 && board[1][3] == 1 && board[1][5] == 1 && board[2][0]==1
      && board[2][2]==1 && board[2][4]==1 && board[3][2]==-1 && board[3][3]== -1
       && board[5][0]== -1)
      {
        bestPosition.From.x=0;
        bestPosition.From.y=5;
        bestPosition.To.x=1;
        bestPosition.To.y=4;
      }
      if( board[0][0]== 1 && board[0][2]==1 && board[0][3] == 1 && board[0][4] ==1 && board[1][4] ==1
       && board[1][2] == 1 && board[1][3] == 1 && board[1][5] == 1 && board[2][0]==1
      && board[2][2]==1 && board[2][4]==1 && board[3][2]==-1 && board[3][3]== -1
       && board[3][4]== -1 && board[4][3]==-1 && board[5][2]==0)
      {
        bestPosition.From.x=1;
        bestPosition.From.y=3;
        bestPosition.To.x=2;
        bestPosition.To.y=3;
      }
      if(board[1][1]==1 && board[1][4]== 1 && board [0][4]==1 && board[1][5]==1
         && bn()==4)
         {
            bestPosition.From.x=0;
            bestPosition.From.y=4;
            bestPosition.To.x=1;
            bestPosition.To.y=3;
         }
    if( board[0][0]==0 && board[0][2]== 1 && board[0][3]==1 && board[0][4] == 1 && board[1][1] ==1 && board[1][4] ==1
       && board[1][2] == 1 && board[2][0] == 1 && board[1][5] == 1 && board[2][2]==1
      && board[2][3]==1 && board[2][4]==1 && board[3][2]==-1 && board[3][3]== -1
       && board[3][4]== -1 && board[3][5]== -1 && board[4][0]==-1 && board[5][1]==-1)
      {
        bestPosition.From.x=0;
        bestPosition.From.y=4;
        bestPosition.To.x=1;
        bestPosition.To.y=3;
      }
}
int Sur::bn()
{
    int Bn=0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(board[i][j]==1)
            {
                Bn++;
            }
        }
    }
    return Bn;
}
