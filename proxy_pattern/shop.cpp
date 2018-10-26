/*************************************************************************
  > File Name: shop.cpp
  > Author: pengjunjie
  > Mail: 1002398145@qq.com 
  > Created Time: 2018年10月23日 星期二 09时55分39秒
 ************************************************************************/

#include <iostream>
#include <memory>
#include <string>
using namespace std;
//海外代购，用代理模式实现
//商品类
class Item
{
public:
    Item(string kind)
        :kind_(kind)
    {}

    string getKind()
    {
        return kind_;
    }
private:
    string kind_;//商品种类
};

//抽象购物方式
class Shopping
{
public:
    virtual void buy(Item& item) = 0;
};

//美国购买
class UsaShopping: public Shopping
{
public:
    virtual void buy(Item& item)
    {
        cout << "去美国购物，买了" << item.getKind() << endl;
    }
};

//日本购买
class JanpanShopping: public Shopping
{
public:
    virtual void buy(Item& item)
    {
        cout << "去日本购物，买了" << item.getKind() << endl;
    }
};

class OverSeaProxy: public Shopping
{
public:
    OverSeaProxy(shared_ptr<Shopping>& shopping)
        :shopping_(shopping)
    {}

    //代理模式关键
    virtual void buy(Item& item)
    {
        shopping_->buy(item);
    }

private:
    shared_ptr<Shopping> shopping_;
};

int main()
{
    Item shoes("shoes");
    shared_ptr<Shopping> usa_shopping = make_shared<UsaShopping>();
    shared_ptr<Shopping> proxy = make_shared<OverSeaProxy>(usa_shopping);
    proxy->buy(shoes);

    cout << "-----------------" << endl;
    shared_ptr<Shopping> japan_shopping = make_shared<JanpanShopping>();
    shared_ptr<Shopping> j_proxy = make_shared<OverSeaProxy>(japan_shopping);
    j_proxy->buy(shoes);
}
