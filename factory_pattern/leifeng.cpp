/*************************************************************************
  > File Name: leifeng.cpp
  > Author: pengjunjie
  > Mail: 1002398145@qq.com 
  > Created Time: 2018年10月23日 星期二 10时31分43秒
 ************************************************************************/


#include <string>
#include <memory>
#include <iostream>
using namespace std;

//雷锋
class LeiFeng
{
public:
    virtual void sweep()
    {
        cout << "扫地" << endl;
    }
    virtual void wash()
    {
        cout << "洗衣" << endl;
    }
    virtual void buyRice()
    {
        cout << "买米" << endl;
    }
};

//学雷锋的大学生
class Undergraduate: public LeiFeng
{
public:
    virtual void sweep()
    {
        cout << "大学生扫地" << endl;
    }
    virtual void wash()
    {
        cout << "大学生洗衣" << endl;
    }
    virtual void buyRice()
    {
        cout << "大学生买米" << endl;
    }
};

//社区志愿者
class Volunteer: public LeiFeng
{
public:
    virtual void sweep()
    {
        cout << "志愿者扫地" << endl;
    }
    virtual void wash()
    {
        cout << "志愿者洗衣" << endl;
    }
    virtual void buyRice()
    {
        cout << "志愿者买米" << endl;
    }
};

#if 0
//简单工厂类
class SimpleFactory
{
public:
    shared_ptr<LeiFeng> createLeiFeng(string type)
    {
        shared_ptr<LeiFeng> result = NULL;
        //FIXME: 添加新的种类需要修改简单工厂的代码
        if(type == "学雷锋的大学生")
        {
            result = make_shared<Undergraduate>();
        }
        else if(type == "社区志愿者")
        {
            result = make_shared<Volunteer>();
        }
        else
        {
            cout << "no type" << endl;
        }
        return result;
    }
};

int main()
{
    SimpleFactory factory;
    //FIXME: 如果要修改为社区志愿者,则三句都需要修改
    shared_ptr<LeiFeng> student1 = factory.createLeiFeng("学雷锋的大学生");
    student1->buyRice();

    shared_ptr<LeiFeng> student2 = factory.createLeiFeng("学雷锋的大学生");
    student2->sweep();

    shared_ptr<LeiFeng> student3 = factory.createLeiFeng("学雷锋的大学生");
    student3->wash();
}
#endif

//雷锋工厂
class IFactory
{
public:
    virtual shared_ptr<LeiFeng> createLeiFeng() = 0;
};

//学雷锋的大学生工厂
class UndergraduateFactory: public IFactory
{
public:
    virtual shared_ptr<LeiFeng> createLeiFeng()
    {
        return make_shared<Undergraduate>();
    }
};

//社区志愿者工厂
class VolunteerFactory: public IFactory
{
public:
    virtual shared_ptr<LeiFeng> createLeiFeng()
    {
        return make_shared<Volunteer>();
    }
};

int main()
{
    //将大学生修改为志愿者只需修改一处
    shared_ptr<IFactory> factory = make_shared<UndergraduateFactory>();
    shared_ptr<LeiFeng> student  = factory->createLeiFeng();

    student->buyRice();
    student->sweep();
    student->wash();
}
