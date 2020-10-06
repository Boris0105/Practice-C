// example on constructors and destructors rect area: 12
#include <iostream.h> rectb area: 30
class CRectangle {
int *width, *height;
public:
//overloading
CRectangle ();
CRectangle (int,int);
~CRectangle ();
//實作內容定義在class以內的有機會被編譯器視為inline function，編譯器會自己作判斷
//inline function會直接將程式碼展開來，與macro非常類似
//程式碼很短，只有return statement，用inline較有效率
int area (void) {return (*width * *height);}
};
CRectangle::CRectangle () {
width = new int;
height = new int;
*width = 5;
*height = 6;
}
CRectangle::CRectangle (int a, int b) {
width = new int;
height = new int;
*width = a;
*height = b;
}
CRectangle::~CRectangle () {
delete width;
delete height;
}
int main () {
//若不傳參數，則不需要括弧，java則需要
CRectangle rect (3,4), rectb (5,6),rectc;
cout << "rect area: " << rect.area() << endl;
cout << "rectb area: " << rectb.area() << endl;
return 0;
}