/*************************************************************************
  > File Name: promotion.cpp
  > Author: pengjunjie
  > Mail: 1002398145@qq.com 
  > Created Time: 2018年10月19日 星期五 19时04分30秒
 ************************************************************************/

#include <iostream>
using namespace std;

//实现商品促销的代码
class CashSuper
{
public:
    virtual double acceptCash() = 0;
};

class CashNormal: public CashSuper
{
public:
    virtual double acceptCash(double money)
    {
        return money;
    }
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

class CashReturn: public CashSuper
{
public:
    CashReturn(double money_condition, double money_return)
        :money_return_(money_return)
        ,money_condition(money_condition)
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
