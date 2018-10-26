/*************************************************************************
  > File Name: hungry_type.cpp
  > Author: pengjunjie
  > Mail: 1002398145@qq.com 
  > Created Time: 2018年10月23日 星期二 17时38分07秒
 ************************************************************************/

#include <iostream>
using namespace std;

//单例模式，饿汉式
class Confing
{
public:
    static Confing *getInstance()
    {
        return p_confing_;
    }
private:
    static Confing *p_confing_;

    Confing(){}
    Confing(const Confing&){}
    ~Confing();
};

Confing* Confing::p_confing_ = new Confing;

int main()
{
    Confing* pconfing = Confing::getInstance();
    //Confing config;//error
}
