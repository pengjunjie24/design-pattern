/*************************************************************************
  > File Name: give_gift.cpp
  > Author: pengjunjie
  > Mail: 1002398145@qq.com 
  > Created Time: 2018年10月22日 星期一 21时30分56秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <memory>
using namespace std;

//代理模式,送礼物
class GiveGift
{
public:
    virtual void giveDolls() = 0;
    virtual void giveFlowers() = 0;
    virtual void giveChocolate() = 0;
};

//被追求者类
class SchoolGirl
{
public:
    inline void setName(string name)
    {
        name_ = name;
    }
    inline string getName()
    {
        return name_;
    }
private:
    string name_;
};

//追求者类
class Pursuit: public GiveGift
{
public:
    Pursuit(SchoolGirl mm): mm_(mm)
    {}

    virtual void giveDolls()
    {
        cout << mm_.getName() << "送你洋娃娃" << endl;
    }
    virtual void giveFlowers()
    {
        cout << mm_.getName() << "送你鲜花" << endl;
    }
    virtual void giveChocolate()
    {
        cout << mm_.getName() << "送你巧克力" << endl;
    }
private:
    SchoolGirl mm_;
};

//代理类
class Proxy: public GiveGift
{
public:
    Proxy(SchoolGirl mm): gg_(mm)
    {}

    virtual void giveDolls()
    {
        gg_.giveDolls();
    }
    virtual void giveFlowers()
    {
        gg_.giveFlowers();
    }
    virtual void giveChocolate()
    {
        gg_.giveChocolate();
    }
    
private:
    Pursuit gg_;
};

int main()
{
    SchoolGirl jiaojiao;
    jiaojiao.setName("李娇娇");

    shared_ptr<Proxy> daili = make_shared<Proxy>(jiaojiao);

    daili->giveDolls();
    daili->giveFlowers();
    daili->giveChocolate();
}
