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
using namespace std;

class Observer;

//抽象通知者
class Subject
{
public:
    virtual void attach(shared_ptr<Observer>& observer) = 0;
    virtual void detach(shared_ptr<Observer>& observer) = 0;
    virtual void notify() = 0;

    string message_;
protected:
    list<shared_ptr<Observer>> observers_;
};


//抽象观察者
class Observer
{
public:
    Observer(shared_ptr<Subject>& sub)
        :sub_(sub)
    {}
    virtual void update() = 0;

protected:
    shared_ptr<Subject> sub_;
};

//具体观察者,看股票
class StockObserver: public Observer
{
public:
    StockObserver(shared_ptr<Subject>& sub, string name)
        :Observer(sub)
        ,name_(name)
    {}

    virtual void update()
    {
        cout << name_ << " 收到消息:" << sub_->message_ << endl;
        if(sub_->message_ == "梁所长来了!")
        {
            cout << "我马上关闭股票，装做很认真工作的样子!" << endl;
        }
    }
private:
    string name_;
};

//具体观察者,看NBA
class NBAObserver: public Observer
{
public:
    NBAObserver(shared_ptr<Subject>& sub, string name)
        :Observer(sub)
        ,name_(name)
    {}

    virtual void update()
    {
        cout << name_ << " 收到消息:" << sub_->message_ << endl;
        if(sub_->message_ == "梁所长来了!")
        {
            cout << "我马上关闭NBA，装做很认真工作的样子!" << endl;
        }
    }
private:
    string name_;
};


//具体通知者,秘书
class Secretary: public Subject
{
public:
    virtual void attach(shared_ptr<Observer>& observer)
    {
        observers_.push_back(observer);
    }

    virtual void detach(shared_ptr<Observer>& observer)
    {
        list<shared_ptr<Observer>>::iterator iter = observers_.begin();
        while(iter != observers_.end())
        {
            if((*iter) == observer)
            {
                observers_.erase(iter);
            }
            ++iter;
        }
    }

    virtual void notify()
    {
        list<shared_ptr<Observer>>::iterator iter = observers_.begin();
        while(iter != observers_.end())
        {
            (*iter)->update();
            ++iter;
        }
    }

};

int main()
{
    shared_ptr<Subject> dwq = make_shared<Secretary>();
    shared_ptr<Observer> xs = make_shared<NBAObserver>(dwq, "xiaoshuai");
    shared_ptr<Observer> zy = make_shared<NBAObserver>(dwq, "zouyue");
    shared_ptr<Observer> lm = make_shared<StockObserver>(dwq, "limin");

    dwq->attach(xs);
    dwq->attach(zy);
    dwq->attach(lm);

    dwq->message_ = "去吃饭啊!";
    dwq->notify();
    cout << endl;
    dwq->message_ = "梁所长来了!";
    dwq->notify();
    return 0;

}
