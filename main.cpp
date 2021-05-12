#include<stdio.h>
#include <iostream>
#include <stdlib.h>
#define rows 512//行
#define cols 512//列
using namespace std;
typedef struct P
{
    unsigned char B,G,R;
}PIXEL;
typedef struct P1
{
    unsigned  char B,G,R,RES;
}TEMPLETE;
void read(){
    int i,j;
    PIXEL nowP[rows][cols];
    FILE *fp,*fout;
    fp=fopen("/Users/fengzijian/CLionProjects/BMP/material/Lenna.bmp","rb");
    fout=fopen("/Users/fengzijian/CLionProjects/BMP/material/1.txt","w");//"w"表示文本文件
    char filehead[54];
    fread(filehead,1,54,fp);
    fread(nowP,3,rows*cols,fp);
    for(i=100;i<200;i++)
    {
        for(j=100;j<200;j++)
            fprintf(fout,"(%d,%d,%d)",nowP[i][j].R,nowP[i][j].G,nowP[i][j].B);
        fprintf(fout,"\n");
    }
    fclose(fp);
    fclose(fout);
}
void write(){
    FILE *fp,*fout;
    char filehead[54];
    PIXEL nowP[512][512];
    fp=fopen("/Users/fengzijian/CLionProjects/BMP/material/Lenna.bmp","rb");
    fout=fopen("/Users/fengzijian/CLionProjects/BMP/material/Dj_1.bmp","wb");
    fread(filehead,1,54,fp);
    fread(nowP,3,512*512,fp);
    int i,j;
    for(i=200;i<300;i++)
        for(j=200;j<300;j++)
        {
            nowP[i][j].R=255;
            nowP[i][j].G=0;
            nowP[i][j].B=0;
        }
    fclose(fp);
    fwrite(filehead,54,1,fout);
    fwrite(nowP,3,512*512,fout);
    fclose(fout);
}
void expend(){
    char str[1000];
    FILE *fp,*fout;
    PIXEL nowP[rows][cols];
    PIXEL newP[rows+15][cols+20];
    char filehead[54];
    fp=fopen("/Users/fengzijian/CLionProjects/BMP/material/Lenna.bmp","rb");
    fout=fopen("/Users/fengzijian/CLionProjects/BMP/material/4.bmp","wb");
    fread(filehead,1,54,fp);
//    for(auto x:filehead)
//        cout<<itoa(x,str,16);
    filehead[18]+=20;
    filehead[22]+=15;
    fread(nowP,3,rows*cols,fp);
    int i,j;
    for(i=0;i<rows+15;i++)
        for(j=0;j<cols+20;j++)
        {
            if(i>=rows||j>=cols){
                newP[i][j].R=255;
                newP[i][j].G=0;
                newP[i][j].B=255;
            }else{
                newP[i][j].R=nowP[i][j].R;
                newP[i][j].G=nowP[i][j].G;
                newP[i][j].B=nowP[i][j].B;
            }


        }

    fclose(fp);
    fwrite(filehead,1,54,fout);
    fwrite(newP,3,(rows+15)*(cols+20),fout);
}
void lab3(){
    int row=200;
    int col=135;
    FILE *fp,*fout;
    char filehead[54];
    PIXEL nowP[200][135];
    TEMPLETE temp1[2];
    fp=fopen("/Users/fengzijian/CLionProjects/BMP/material/256.bmp","rb");
    fout=fopen("/Users/fengzijian/CLionProjects/BMP/material/fatLenna.bmp","w");//"w"表示文本文件
    fread(filehead,1,54,fp);
    fread(temp1,1,2*4,fp);
    fread(nowP,1,200/8*135,fp);
    int i ,j;
    fclose(fp);
    temp1[0].B=255;
    temp1[0].G=0;
    temp1[0].R=0;
    temp1[1].B=0;
    temp1[1].G=255;
    temp1[1].R=255;
    fwrite(filehead+20,54,1,fout);
    fwrite(temp1,2*4,1,fout);
    fwrite(nowP,3,200*135,fout);
    fclose(fout);
}

int main()
{   //read();
    //write();
    //lab3();
    expend();
}

