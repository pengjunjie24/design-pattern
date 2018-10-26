/*************************************************************************
  > File Name: lazy_singleton.cpp
  > Author: pengjunjie
  > Mail: 1002398145@qq.com 
  > Created Time: 2018年10月23日 星期二 18时18分37秒
 ************************************************************************/

#include <iostream>
#include <mutex>
using namespace std;

//懒汉式单例
class Singleton
{
public:
    Singleton* getInstance()
    {
        if(instance_ == NULL)
        {
            //如果有多个线程进入到这一步，只能有一个线程进入创建
            lock_guard<mutex> lck(mutex_);
            if(instance_ == NULL)
            {
                instance_ = new Singleton();
            }
        }
        return instance_;
    }

private:
    Singleton(){}
    Singleton(const Singleton&){}

    Singleton* instance_;
    static std::mutex mutex_;
};

std::mutex Singleton::mutex_;

int main()
{

}
