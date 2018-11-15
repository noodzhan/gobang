#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include <iostream>
#include <string>



//画自己的棋子圆圈
void draw_circle1(int x,int y,int r){
    setcolor(YELLOW);

    circle(x,y,r);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(x,y,YELLOW);
}
//画敌方棋子X
void draw_circle2(int x,int y,int r){
    setcolor(YELLOW);
    circle(x,y,r);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(x,y,YELLOW);

}
//画棋盘
void draw_pane(){
    //rectangle(150,100,450,400);
    line(250,100,250,400);
    line(350,100,350,400);
    line(150,200,450,200);
    line(150,300,450,300);
}
//判断符合三子是否能连成直线
bool reg(int a[3][3],int er){
    for(int i=0;i<3;i++)
        if(a[i][0]==a[i][1]&&a[i][1]==a[i][2]&&a[i][0]==er)
            return true;
    for(int i=0;i<3;i++)
        if(a[0][i]==a[1][i]&&a[1][i]==a[2][i]&&a[0][i]==er)
            return true;
    if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[0][0]==er)
        return true;

    if(a[2][0]==a[1][1]&&a[1][1]==a[0][2]&&a[2][0]==er)
        return true;

    return false;
}

bool notwin(int a[3][3]){
    int temp=0;
    if(!reg(a,1)&&!reg(a,2)){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(a[i][j]!=0)
                    temp++;
    }
    if(temp==9)
        return true;


}

void showInfo(int er){
    cleardevice();
    setfont(50,0,"幼圆");
    char success1[]="Blue is win";
    char success2[]="Green is win";
    char success3[]="Not Winner";

    switch(er){
case 1:
        setcolor(BLUE);
        outtextxy(240,240,success1);
        break;
case 2:
        setcolor(GREEN);
        outtextxy(240,240,success2);
        break;
case 3:
        setcolor(RED);
        outtextxy(240,240,success3);
        break;
    }

}

int main()
{
    initgraph(640,480);
    setcolor(YELLOW);


    mouse_msg msg = {0};

    //存放自己的棋子，我这里设计的是圆圈
    int x_left[1000],y_left[1000];
    int x_right[1000],y_right[1000];
    memset(x_left,0,1000);
    memset(y_left,0,1000);
    memset(x_right,0,1000);
    memset(y_right,0,1000);

    int data[3][3]={
        {0,0,0},{0,0,0},{0,0,0}
    };


    int i=0;//这个变量是存放记录棋子的个数
    int j=0;


    for ( ; is_run(); delay_fps(80))
	{


        //获取鼠标的信息
		while (mousemsg())
		{
			msg = getmouse();

			int press_left= msg.is_left();
            int press_right= msg.is_right();

            if(press_left==1){
                x_left[i]=msg.x;
                y_left[i]=msg.y;
                i++;

            }
            if(press_right==1){
                x_right[j]=msg.x;
                y_right[j]=msg.y;
                j++;

            }


		}

		cleardevice();
		draw_pane();
#if 0
		//界面左上角的信息
		xyprintf(0, 0, "x = %10d  y = %10d",
			msg.x, msg.y, msg.wheel);

		xyprintf(0, 20, "left  = %d mid   = %d right = %d",
			 msg.is_left(),
			 msg.is_mid(),
			 msg.is_right());


        xyprintf(0,40,"left=%d",i);

        xyprintf(0,60,"right=%d",j);
#endif

        for(int k=0;k<i;k+=2){
            if(x_left[k]!=0&&y_left[k]!=0){
                draw_circle1(x_left[k],y_left[k],30);
                if( x_left[k]<250&& x_left[k]>150&& y_left[k]<200&& y_left[k]>100)
                    data[0][0]=1;
                else if( x_left[k]<350&& x_left[k]>250&& y_left[k]<200&& y_left[k]>100)
                    data[0][1]=1;
                else if( x_left[k]<450&& x_left[k]>350&& y_left[k]<200&& y_left[k]>100)
                    data[0][2]=1;
                else if( x_left[k]<250&& x_left[k]>150&& y_left[k]<300&& y_left[k]>200)
                    data[1][0]=1;
                else if( x_left[k]<350&& x_left[k]>250&& y_left[k]<300&& y_left[k]>200)
                    data[1][1]=1;
                else if( x_left[k]<450&& x_left[k]>350&& y_left[k]<300&& y_left[k]>200)
                    data[1][2]=1;
                else if( x_left[k]<250&& x_left[k]>150&& y_left[k]<400&& y_left[k]>300)
                    data[2][0]=1;
                else if( x_left[k]<350&& x_left[k]>250&& y_left[k]<400&& y_left[k]>300)
                    data[2][1]=1;
                else if( x_left[k]<450&& x_left[k]>350&& y_left[k]<400&& y_left[k]>300)
                    data[2][2]=1;
            }

        }


        //画出绿色的圈
        for(int k=0;k<j;k+=2){
            if(x_right[k]!=0&&y_right[k]!=0){
                draw_circle2(x_right[k],y_right[k],30);
                if( x_right[k]<250&& x_right[k]>150&& y_right[k]<200&& y_right[k]>100)
                    data[0][0]=2;
                else if( x_right[k]<350&& x_right[k]>250&& y_right[k]<200&& y_right[k]>100)
                    data[0][1]=2;
                else if( x_right[k]<450&& x_right[k]>350&& y_right[k]<200&& y_right[k]>100)
                    data[0][2]=2;
                else if( x_right[k]<250&& x_right[k]>150&& y_right[k]<300&& y_right[k]>200)
                    data[1][0]=2;
                else if( x_right[k]<350&& x_right[k]>250&& y_right[k]<300&& y_right[k]>200)
                    data[1][1]=2;
                else if( x_right[k]<450&& x_right[k]>350&& y_right[k]<300&& y_right[k]>200)
                    data[1][2]=2;
                else if( x_right[k]<250&& x_right[k]>150&& y_right[k]<400&& y_right[k]>300)
                    data[2][0]=2;
                else if( x_right[k]<350&& x_right[k]>250&& y_right[k]<400&& y_right[k]>300)
                    data[2][1]=2;
                else if( x_right[k]<450&& x_right[k]>350&& y_right[k]<400&& y_right[k]>300)
                    data[2][2]=2;
            }

        }



        //分析规则
        if(reg(data,1)){
            showInfo(1);
        }else if(reg(data,2)){
            showInfo(2);
        }else if(notwin(data)){
            showInfo(3);
        }







#if 0
        //打印data数组的数据
        int t1=0;
        for(int l=0;l<3;l++){
            for(int q=0;q<3;q++){
                xyprintf(0,80+t1,"data[%d][%d]=%d ",l,q,data[l][q]);
                t1+=30;
            }
        }


#endif




    }
    getch();

    return 0;
}

