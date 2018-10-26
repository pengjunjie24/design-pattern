/*************************************************************************
  > File Name: promotion.cpp
  > Author: pengjunjie
  > Mail: 1002398145@qq.com 
  > Created Time: 2018年10月19日 星期五 19时04分30秒
 ************************************************************************/

#include <iostream>
#include <memory>
#include <string>
using namespace std;

//实现商品促销的代码
class CashSuper
{
public:
    virtual double acceptCash(double money) = 0;
};

//正常收费类
class CashNormal: public CashSuper
{
public:
    virtual double acceptCash(double money)
    {
        return money;
    }
};

//打折收费类
class CashRebate: public CashSuper
{
public:
    CashRebate(double money_rebate)
        :money_rebate_(money_rebate)
    {}

    virtual double acceptCash(double money)
    {
        return money * money_rebate_;
    }

private:
    double money_rebate_;
};

//返利收费类
class CashReturn: public CashSuper
{
public:
    CashReturn(double money_condition, double money_return)
        :money_condition_(money_condition)
        ,money_return_(money_return)
    {}

    virtual double acceptCash(double money)
    {
        double result = money;
        if(money > money_condition_)
        {
            result = money - money / money_condition_ * money_return_;
        }
        return result;
    }
private:
    double money_condition_;
    double money_return_;
};

//上下文
class CashContext
{
public:
    CashContext(string cash_strategy)
    {
        if(cash_strategy == "正常收费")
        {
            cs_ = make_shared<CashNormal>();
        }
        else if(cash_strategy == "打折收费")
        {
            double money_rebate = 0.7;
            cs_ = make_shared<CashRebate>(money_rebate);
        }
        else if(cash_strategy == "返利收费")
        {
            double money_condition = 300;
            double money_return = 100;
            cs_ = make_shared<CashReturn>(money_condition, money_return);
        }
        else
        {
            cout << "no cash strtegy" << endl;
        }
    }

    double getResult(double money)
    {
        return cs_->acceptCash(money);
    }

private:
    std::shared_ptr<CashSuper> cs_;
};

int main()
{
    std::shared_ptr<CashContext> cc = NULL;
    string cash_strategy = "打折收费"; 
    cc = make_shared<CashContext>(cash_strategy);//策略模式和简单工厂模式相结合,客户只需要认识一个类CashContext就行了,简单工厂模式需要让客户知道CashContext和CashFactory
    cout << "最终价格:" << cc->getResult(1000) << endl;;
}
