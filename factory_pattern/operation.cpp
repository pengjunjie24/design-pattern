/*************************************************************************
  > File Name: operation.h
  > Author: pengjunjie
  > Mail: 1002398145@qq.com 
  > Created Time: 2018年10月16日 星期二 20时14分37秒
 ************************************************************************/

#include <iostream>
#include <memory>
#include <string>

//计算器功能,简单工厂模式
class AbstractCaculator
{
public:
    AbstractCaculator(int left, int right)
        :left_(left)
        ,right_(right)
    {}
    AbstractCaculator()
    {}
    virtual ~AbstractCaculator()
    {}

    void setLeft(double left) {left_ = left;}
    void setRight(double right) {right_ = right;}
    
    virtual double getResult() = 0;

protected:
    double left_ = 0;
    double right_ = 0;
};

class PulsCaculator: public AbstractCaculator
{
public:
    virtual double getResult()
    {
        return left_ + right_;
    }
};

class SubCaculator: public AbstractCaculator
{
public:
    virtual double getResult()
    {
        return left_ - right_;
    }
};

class MulCaculator: public AbstractCaculator
{
public:
    virtual double getResult()
    {
        return left_ * right_;
    }
};

class DivCaculator: public AbstractCaculator
{
public:
    virtual double getResult()
    {
        if(right_ == 0)
        {
            std::cout << "right is not zero" << std::endl;
            return 0;
        }
        return left_ / right_;
    }
};

class CaculatorFactory
{
public:
    std::shared_ptr<AbstractCaculator> createCaculator(const std::string& operate)
    {
        std::shared_ptr<AbstractCaculator> cal = NULL;
        if(operate == "+")
        {
            cal = std::make_shared<PulsCaculator>();
        }
        else if(operate == "-")
        {
            cal = std::make_shared<SubCaculator>();
        }
        else if(operate == "*")
        {
            cal = std::make_shared<MulCaculator>();
        }
        else if(operate == "/")
        {
            cal = std::make_shared<DivCaculator>();
        }
        return cal;
    }
};

int main()
{
    std::shared_ptr<CaculatorFactory> factory = std::make_shared<CaculatorFactory>();
    
    std::shared_ptr<AbstractCaculator>cal = factory->createCaculator("+");
    cal->setLeft(1.4);
    cal->setRight(3.3);
    std::cout << "result: " << cal->getResult() << std::endl;
}
