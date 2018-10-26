/*************************************************************************
  > File Name: observer.cpp
  > Author: pengjunjie
  > Mail: 1002398145@qq.com 
  > Created Time: 2018年10月24日 星期三 17时54分36秒
 ************************************************************************/

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <functional>
using namespace std;

//抽象通知者
class Subject
{
public:
    //抽象通知者不依赖于抽象观察者，所以没有增加和减少接口
    virtual void notify() = 0;
    string message_;
};

//看股票的同事，去掉父类抽象
class StockObserver
{
public:
    StockObserver(shared_ptr<Subject>& sub, string name)
        :sub_(sub)
        ,name_(name)
    {}

    //模拟实际情况，实际类中不可能都有Observer接口，方法名也不一定相同
    void closeStockMarket()
    {
        cout << sub_->message_ << name_ << "马上关闭NBA，装做很认真工作的样子!" << endl;
    }
private:
    shared_ptr<Subject> sub_;
    string name_;
};

//看NBA的同事
class NBAObserver
{
public:
    NBAObserver(shared_ptr<Subject>& sub, string name)
        :sub_(sub)
        ,name_(name)
    {}

    void closeNBADirectSeeding()
    {
        cout << sub_->message_ << name_ << "马上关闭NBA，装做很认真工作的样子!" << endl;
    }
private:
    shared_ptr<Subject> sub_;
    string name_;
};

//具体通知者,老板
class Boss: public Subject
{
public:
    typedef function<void()> NotifyCallback;

    inline void attach(NotifyCallback cb)
    {
        list_cb_.push_back(cb);
    }
#if 0
    void detach(NotifyCallback cb)
    {
        list<NotifyCallback>::iterator iter = list_cb_.begin();
        while(iter != list_cb_.end())
        {
            if((*iter) == cb)
            {
                list_cb_.erase(cb);
            }
            ++iter;
        }
    }
#endif
    virtual void notify()
    {
        for(auto update : list_cb_)
        {
            update();
        }
    }

private:
    list<NotifyCallback> list_cb_;
};

int main()
{
    //老板
    shared_ptr<Boss> dwq = make_shared<Boss>();
    //看股票的同事
    shared_ptr<StockObserver> xs = make_shared<StockObserver>(dwq, "xiaoshuai");
    shared_ptr<StockObserver> zy = make_shared<StockObserver>(dwq, "zouyue");
    //看NBA的同事
    shared_ptr<NBAObserver> lm = make_shared<NBAObserver>(dwq, "limin");

    dwq->attach(bind(&StockObserver::closeStockMarket, xs));
    dwq->attach(bind(&StockObserver::closeStockMarket, zy));
    dwq->attach(bind(&NBAObserver::closeNBADirectSeeding, lm));

    //老板回来
    dwq->message_ = "我回来了!";
    //发出通知
    dwq->notify();
    return 0;
}
