#include <iostream>
#include <string>
using std::string;

class ElectricPot
{
private:
    int size;
    string color;
public:
    //Note: 我們不必自己定義copy constructor
    ElectricPot(int _size, string _color);
    void cook();
};

ElectricPot::ElectricPot(int _size, string _color){
    size = _size;
    color = _color;
}

//這邊改寫cook函數，讓電鍋可印出大小、顏色資訊
void ElectricPot::cook()
{
    std::cout << "本電鍋的大小為: "<< size << std::endl;
    std::cout << "我是 "<< color <<" 顏色的電鍋，我正在煮飯"<<std::endl;
}

int main()
{
    ElectricPot p1(20, "yellow"); //創建一個ElectricPot物件p1，大小20，顏色"yellow"
    ElectricPot p2(p1); //拷貝建構子，將p1的值複製給p2
    p1.cook();
    p2.cook();
    return 0;
}
