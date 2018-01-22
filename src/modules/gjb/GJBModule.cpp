#include "GJBModule.h"
#include "Rule_1_1_1.h"
#include "Rule_1_1_2.h"
#include "Rule_1_1_4.h"
#include "Rule_1_1_6.h"
#include "Rule_1_1_7.h"
#include "Rule_1_1_8.h"
#include "Rule_1_1_9.h"
#include "Rule_1_1_10.h"
#include "Rule_1_1_15.h"
#include "Rule_1_1_16.h"
#include "Rule_1_1_17.h"
#include "Rule_1_1_21.h"
#include "Rule_1_1_22.h"
#include "Rule_1_2_1.h"
#include "Rule_1_2_2.h"
#include "Rule_1_2_3.h"
#include "Rule_1_2_4.h"
#include "Rule_1_2_8.h"
#include "Rule_1_2_9.h"
#include "Rule_3_1_1.h"
#include "Rule_3_1_2.h"
#include "Rule_3_1_3.h"
#include "Rule_3_1_4.h"
#include "Rule_3_1_5.h"
#include "Rule_3_1_6.h"
#include "Rule_3_1_7.h"
#include "Rule_3_1_8.h"
#include "Rule_4_1_2.h"
#include "Rule_4_1_3.h"
#include "Rule_5_1_1.h"
#include "Rule_5_1_2.h"
#include "Rule_6_1_1.h"
#include "Rule_6_1_3.h"
#include "Rule_6_1_4.h"
#include "Rule_6_1_5.h"
#include "Rule_6_1_6.h"
#include "Rule_6_1_7.h"
#include "Rule_6_1_11.h"
#include "Rule_6_1_12.h"
#include "Rule_6_1_15.h"
#include "Rule_6_1_16.h"
#include "Rule_6_1_17.h"
#include "Rule_6_1_18.h"
#include "Rule_8_1_1.h"
#include "Rule_11_1_1.h"
#include "Rule_11_1_2.h"
#include "Rule_12_1_1.h"
#include "Rule_13_1_1.h"
#include "Rule_13_1_2.h"
#include "Rule_13_1_4.h"
#include "Rule_14_1_1.h"
#include "Rule_14_1_2.h"
#include "Rule_14_1_3.h"

using namespace clang;

namespace clang {
namespace crulet {
namespace GJB {

void GJBModule::registerCheckers(){
  this->registerChecker<Rule_1_1_1>("GJB-rule-1.1.1", "过程名禁止被重用");
  // this->registerChecker<Rule_1_1_2>("GJB-rule-1.1.2", "标号名禁止被重用");
  this->registerChecker<Rule_1_1_4>("GJB-rule-1.1.4", "禁止声明多重标号");
  this->registerChecker<Rule_1_1_6>("GJB-rule-1.1.6", "在过程声明中必须对参数说明");
  this->registerChecker<Rule_1_1_7>("GJB-rule-1.1.7", "禁止过程参数只有类型没有标识符");
  this->registerChecker<Rule_1_1_8>("GJB-rule-1.1.8", "禁止在过程参数中使用省略号");
  this->registerChecker<Rule_1_1_9>("GJB-rule-1.1.9", "禁止重新定义使用C或C++的关键字");
  this->registerChecker<Rule_1_1_10>("GJB-rule-1.1.10", "禁止过程或函数中的参数表为空");
  this->registerChecker<Rule_1_1_15>("GJB-rule-1.1.15", "字符型变量必须明确定义是有符号还是无符号");
  this->registerChecker<Rule_1_1_16>("GJB-rule-1.1.16", "禁止对一个名字重新定义");
  this->registerChecker<Rule_1_1_17>("GJB-rule-1.1.17", "用typedef自定义的类型禁止被重新定义");
  this->registerChecker<Rule_1_1_21>("GJB-rule-1.1.21", "禁止结构体声明不完整");
  this->registerChecker<Rule_1_1_22>("GJB-rule-1.1.22", "禁止参数的声明形式上不一致");

  this->registerChecker<Rule_1_2_1>("GJB-rule-1.2.1", "推荐对基本类型进行typedef");
  this->registerChecker<Rule_1_2_2>("GJB-rule-1.2.2", "建议不使用函数类型作为参数");
  this->registerChecker<Rule_1_2_3>("GJB-rule-1.2.3", "建议函数参数不超过20个");
  this->registerChecker<Rule_1_2_4>("GJB-rule-1.2.4", "建议在结构体中谨慎使用位域");
  this->registerChecker<Rule_1_2_8>("GJB-rule-1.2.8", "建议谨慎使用union类型");
  this->registerChecker<Rule_1_2_9>("GJB-rule-1.2.9", "建议在结构体中谨慎使用无名位域");

  this->registerChecker<Rule_3_1_1>("GJB-rule-3.1.1", "禁止条件判别成立时相应分支无执行语句");
  this->registerChecker<Rule_3_1_2>("GJB-rule-3.1.2", "在if...else if语句中必须使用else分支");
  this->registerChecker<Rule_3_1_3>("GJB-rule-3.1.3", "禁止条件判别的else分支无可执行语句");
  this->registerChecker<Rule_3_1_4>("GJB-rule-3.1.4", "在switch语句中必须有default语句");
  this->registerChecker<Rule_3_1_5>("GJB-rule-3.1.5", "禁止使用空switch语句");
  this->registerChecker<Rule_3_1_6>("GJB-rule-3.1.6", "禁止switch语句中只包含default语句");
  this->registerChecker<Rule_3_1_7>("GJB-rule-3.1.7", "禁止switch的case语句不是由break终止");
  this->registerChecker<Rule_3_1_8>("GJB-rule-3.1.8", "禁止switch的case语句中无任何可执行的语句");

  this->registerChecker<Rule_4_1_2>("GJB-rule-4.1.2", "禁止指针的指针超过两级");
  this->registerChecker<Rule_4_1_3>("GJB-rule-4.1.3", "禁止将过程声明为指针类型");

  this->registerChecker<Rule_5_1_1>("GJB-rule-5.1.1", "禁止直接从过程中跳出");
  this->registerChecker<Rule_5_1_2>("GJB-rule-5.1.2", "禁止使用goto语句");

  this->registerChecker<Rule_6_1_1>("GJB-rule-6.1.1", "禁止在非赋值表达式中出现赋值操作符");
  this->registerChecker<Rule_6_1_3>("GJB-rule-6.1.3", "禁止对有符号类型进行移位操作");
  this->registerChecker<Rule_6_1_4>("GJB-rule-6.1.4", "对变量进行移位运算必须保证不会产生溢出");
  this->registerChecker<Rule_6_1_5>("GJB-rule-6.1.5", "禁止给无符号变量赋负值");
  this->registerChecker<Rule_6_1_6>("GJB-rule-6.1.6", "有符号类型的位长度必须大于等于两位");
  // this->registerChecker<Rule_6_1_7>("GJB-rule-6.1.7", "位的定义必须是有符号整数或无符号整数");
  this->registerChecker<Rule_6_1_11>("GJB-rule-6.1.11", "禁止对常数值做逻辑非的运算");
  this->registerChecker<Rule_6_1_12>("GJB-rule-6.1.12", "禁止对有符号类型进行移位操作");
  this->registerChecker<Rule_6_1_15>("GJB-rule-6.1.15", "禁止在逻辑表达式中使用赋值操作符");
  this->registerChecker<Rule_6_1_16>("GJB-rule-6.1.16", "禁止赋值操作符与\"&&\"或\"||\"连用");
  this->registerChecker<Rule_6_1_17>("GJB-rule-6.1.17", "禁止位操作符带有布尔型的操作数");
  this->registerChecker<Rule_6_1_18>("GJB-rule-6.1.18", "禁止位操作符作用于布尔值");

  this->registerChecker<Rule_8_1_1>("GJB-rule-8.1.1", "禁止单独使用小写字母\"l\"或大写字母\"O\"作为变量名");

  this->registerChecker<Rule_11_1_1>("GJB-rule-11.1.1", "禁止使用不合适的循环变量类型");
  this->registerChecker<Rule_11_1_2>("GJB-rule-11.1.2", "循环变量必须是局部声明的");

  this->registerChecker<Rule_12_1_1>("GJB-rule-12.1.1", "禁止对指针变量使用强制类型转换赋值");

  this->registerChecker<Rule_13_1_1>("GJB-rule-13.1.1", "枚举元素的初始化必须完整");
  this->registerChecker<Rule_13_1_2>("GJB-rule-13.1.2", "结构体变量初始化的类型必须一致");
  // this->registerChecker<Rule_13_1_4>("GJB-rule-13.1.4", "变量使用前必须被赋过值");

  this->registerChecker<Rule_14_1_1>("GJB-rule-14.1.1", "禁止对实数类型的量做是否相等的比较");
  this->registerChecker<Rule_14_1_2>("GJB-rule-14.1.2", "禁止逻辑判别的表达式不是逻辑表达式");
  this->registerChecker<Rule_14_1_3>("GJB-rule-14.1.3", "switch语句中的表达式禁止是逻辑表达式");
}

} // namespace GJB
} // namespace crulet
} // namespace clang
