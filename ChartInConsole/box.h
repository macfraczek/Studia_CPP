#include <iostream>
#define STALASINUSA 2

using namespace std;

class Box{
    int width,height;
    char *sq=NULL;
public:
    Box(int =30,int =10);               /// box ustawiany na sztywno
    Box(int,int,int);                   /// 3 zmienne zeby nie zepsuc konstrunktora z inicjalizacja domyslna    -> tu program pyta o pole
    void display();
    void setFull(char);
    int getWidth();
    int getHeight();
    void setPoint(int,int,char);
    void setPointWidth(int,char);
    void setPointHeight(int,char);
    void setLine();
    void setSinus();                    /// sinus na cale pole
    void setFunction(double,double);    /// 2 zmienne to poczatek i koniec przedzialu
    ~Box();
};
