
#include "stdafx.h"
#include <iostream>
#include "box.h"
#include <cmath>

//#include <windows.h>

    //display();
    //Sleep(100);
    //system(" cls ");


using namespace std;

Box::Box(int aa,int bb){
    width=aa;
    height=bb;
    sq = new char[width*height];
    setFull(' ');
}
Box::Box(int,int,int){
    int aa,bb;
    cout<<"Podaj szerokosc (~60) : ";
    cin>>aa;
    cout<<"Podaj wysokosc (~13) : ";
    cin>>bb;

    width=aa;
    height=bb;
    sq = new char[width*height];
    setFull(' ');
}
void Box::setFull(char c){
    for (int j=0;j<height;j++)
    for (int i=0;i<width;i++)
    *(sq+i+width*j)=c;
}
int Box::getWidth(){
    return width;}
int Box::getHeight(){
    return height;}
void Box::setPoint(int x,int y,char c){
    if (x>width || y>height) {
                        cout<<"ERROR - Punkt poza zakresem\n";
                        return;
                    }

    *(sq+(x-1)+width*(y-1))=c;
}
void Box::display(){
for (int i=0;i<width+2;i++)
    cout<<"-";
    cout<<endl;
for (int j=0;j<height;j++)
{       cout<<"|";
        for (int i=0;i<width;i++)
                {   cout<<*(sq+i+width*j);
                    if (i==width-1)    cout<<"|"<<endl;
                }
}
for (int i=0;i<width+2;i++)
    cout<<"-";
    cout<<endl;
}
void Box::setPointWidth(int x,char sign){
for(int i=0;i<width;i++)
    *(sq+i+width*(x-1))=sign;
}
void Box::setPointHeight(int y,char sign){
for(int i=0;i<height;i++)
    *(sq+i*width+(y-1))=sign;
}
void Box::setLine(){
this->setPointWidth(height/2+1,'-');
}
void Box::setSinus(){
for(float i=0;i<width;i++)
    {
        int heightForChart=height/2;
        double sinusValueDoub=-(sin(i/STALASINUSA)*heightForChart); /// Ten minus ciezko zrozumiec -> im wiersz w dol tym wiekszy indeks a os Y w dol maleje i tu pojawia sie rozbieznosc. Pozdrawiam z interpretacja
        int sinusValueInt=sinusValueDoub;

        sinusValueInt+=heightForChart;
        *(sq+(int)i+width*(sinusValueInt))='#';
    }
}
void Box::setFunction(double a,double b){
setLine();
float widthChart=b-a;
float widthPoint=widthChart/width;
int j=0;
int osY=1;
for(float i=a;i<b;i+=widthPoint)
    {

        int heightForChart=height/2;
        double ValueDoub=-(cos(4*i)*exp(-i)*heightForChart);
        int ValueInt=ValueDoub;
        ValueInt+=heightForChart;
        *(sq+j+width*(ValueInt))='#';

        //if ((i<0.01)&&(i>(-0.01)))        //      opcja 1
        //    setPointHeight(j,'|');
         if (osY && i>0) {                  //      opcja 2
            setPointHeight(j,'|');
            osY=0;
        }


        j++;

    }
}
Box::~Box(){
    delete[] sq;
    //cout<<"-----\ndestruktor dziala\n-----\n";
    }


