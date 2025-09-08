# `neotest`
`neotest`是一个简易的单元测试库,它使用`C++20`语言标准编写而成.

下面是它的功能介绍.
## 引入库
```cpp
#include<neotest/neotest.h>
```
## 计时器
`neotest`库提供了一个简易的计时器类`::neotest::Timer`
来统计一段代码实际执行所用的时间.
### 使用案例
下面是`::neotest::Timer`的一个使用案例:
```cpp
::neotest::Timer timer;
timer.start();
//...这里是需要统计执行时间的代码段
timer.stop();
::std::cout<<::std::format(
    "duration ns    :{}\n"
    "duration us    :{}\n"
    "duration ms    :{}\n"
    "duration s     :{}\n"
    "duration m     :{}\n"
    "duration h     :{}\n"
    "duration string:{}\n"
    ,timer.duration_nanoseconds()
    ,timer.duration_microseconds()
    ,timer.duration_milliseconds()
    ,timer.duration_seconds()
    ,timer.duration_minutes()
    ,timer.duration_hours()
    ,timer.duration_string()
);
```
可能的输出结果如下:
```txt
duration ns    :15127566
duration us    :15127.566
duration ms    :15.127566
duration s     :0.015127566
duration m     :0.0002521261
duration h     :4.2021016666666665e-06
duration string:15 ms 127 us 566 ns
```
### 注意事项
`::neotest::Timer`类对象的`duration_*`方法的返回结果
与类对象最后一次调用`start()` `stop()`有关.

`duration_*`方法只计算最后一次调用上述两方法的时间点的差值,
即`last stop time point - last start time point`.
## 测试单元
`neotest`库提供了`NEOTEST_CASE()`宏函数用来定义一个测试单元.
```cpp
NEOTEST_CASE("hello"){
    //...这里是你的单元测试代码
}
```
注意:

请在全局作用域空间使用`NEOTEST_CASE()`来定义测试单元,
在其他作用域/命令空间/函数/类内部使用属于未定义行为.

在测试单元的内部可以除了普通的代码之外,
可以使用如下的两种表达式用于检测代码的执行结果.
### 运行时检查
`NEOTEST_RUNTIME_CHECK*`表达式用于检查一个条件表达式是否成立.

当条件表达式的结果为`false`时,会记录下相应的信息.
但不会中断当前测试单元的执行.
#### 逻辑表达式
`neotest`库提供了如下的宏函数用于检查一个逻辑表达式的结果.
```cpp
// check(condition)
NEOTEST_RUNTIME_CHECK(condition);
// check(condition_1 && condition_2)
NEOTEST_RUNTIME_CHECK_AND(condition_1,condition_2);
// check(condition_1 || condition_2)
NEOTEST_RUNTIME_CHECK_OR(condition_1,condition_2);
// check(!condition)
NEOTEST_RUNTIME_CHECK_NOT(condition);
```
#### 值比较表达式
`neotest`库提供了如下的宏函数用于检查一个值比较表达式的结果.
```cpp
// check(value_1 == value_2)
NEOTEST_RUNTIME_CHECK_EQ(value_1,value_2);
// check(value_1 != value_2)
NEOTEST_RUNTIME_CHECK_NE(value_1,value_2);
// check(value_1 > value_2)
NEOTEST_RUNTIME_CHECK_GT(value_1,value_2);
// check(value_1 >= value_2)
NEOTEST_RUNTIME_CHECK_GE(value_1,value_2);
// check(value_1 < value_2)
NEOTEST_RUNTIME_CHECK_LT(value_1,value_2);
// check(value_1 <= value_2)
NEOTEST_RUNTIME_CHECK_LE(value_1,value_2);
```
### 运行时断言
`NEOTEST_RUNTIME_ASSERT*`表达式用于检查一个条件表达式是否成立.

当条件表达式的结果为`false`时,会记录下相应的信息.
并中断当前测试单元的执行.
#### 逻辑表达式
`neotest`库提供了如下的宏函数用于检查一个逻辑表达式的结果.
```cpp
// assert(condition)
NEOTEST_RUNTIME_ASSERT(condition);
// assert(condition_1 && condition_2)
NEOTEST_RUNTIME_ASSERT_AND(condition_1,condition_2);
// assert(condition_1 || condition_2)
NEOTEST_RUNTIME_ASSERT_OR(condition_1,condition_2);
// assert(!condition)
NEOTEST_RUNTIME_ASSERT_NOT(condition);
```
#### 值比较表达式
`neotest`库提供了如下的宏函数用于检查一个值比较表达式的结果.
```cpp
// assert(value_1 == value_2)
NEOTEST_RUNTIME_ASSERT_EQ(value_1,value_2);
// assert(value_1 != value_2)
NEOTEST_RUNTIME_ASSERT_NE(value_1,value_2);
// assert(value_1 > value_2)
NEOTEST_RUNTIME_ASSERT_GT(value_1,value_2);
// assert(value_1 >= value_2)
NEOTEST_RUNTIME_ASSERT_GE(value_1,value_2);
// assert(value_1 < value_2)
NEOTEST_RUNTIME_ASSERT_LT(value_1,value_2);
// assert(value_1 <= value_2)
NEOTEST_RUNTIME_ASSERT_LE(value_1,value_2);
```
### 跳过
除了上述的两种表达式,
`neotest`还提供了`NEOTEST_SKIP()`宏函数用于在某些情况下提前跳出当前的测试单元.

`NEOTEST_SKIP()`执行时会记录相应的信息,
宏函数参数支持空输入`()`或`("")`,
或指定一个自定义原因字符串.

原因字符串支持如下的2种方式:
1. 字符串字面量
2. 可以赋值给`::std::string`的值

下面给出一个具体的使用案例:
```cpp
if(!ofs.is_open()){
    ::std::string reason={"文件打开失败"};
    ofs.close();
    NEOTEST_SKIP(reason);
}
```
### 自定义消息
`::neotest::OStringStream`
```cpp
NEOTEST_RUNTIME_CHECK(1+1!=2)
    <<"this is check msg";
    <<int{100}
    <<::std::format("fmt{}",double{0.0});
NEOTEST_RUNTIME_ASSERT(1+1==2)
    <<"this is assert msg";
    <<int{100}
    <<::std::format("fmt{}",double{0.0});
NEOTEST_SKIP("this is reason")
    <<"this is skip msg"
    <<int{100}
    <<::std::format("fmt{}",double{0.0});
```
## 测试组
`NEOTEST_GROUP`
### 测试单元成员
`NEOTEST_GROUP_ELEMENT_CASE`
### 测试单元正则表达式成员
`NEOTEST_GROUP_ELEMENT_CASE_REGEX`
## 执行测试
`::neotest::execute*`
## 测试结果
`::neotest::key_to_json`
`::neotest::value_to_json`
## 类型信息
`::neotest::type_name_of`
## 编译期检查
`NEOTEST_STATIC_CHECK*`
### 编译期值逻辑表达式
```cpp
// check(condition)
NEOTEST_STATIC_CHECK(condition);
// check(!condition)
NEOTEST_STATIC_CHECK_NOT(condition);
// check(condition_1 && condition_2)
NEOTEST_STATIC_CHECK_VALUE_AND(condition_1,condition_2);
// check(condition_1 || condition_2)
NEOTEST_STATIC_CHECK_VALUE_OR(condition_1,condition_2);
```
### 编译期值比较表达式
```cpp
// check(value_1 == value_2)
NEOTEST_STATIC_CHECK_VALUE_EQ(value_1,value_2);
// check(value_1 != value_2)
NEOTEST_STATIC_CHECK_VALUE_NE(value_1,value_2);
// check(value_1 > value_2)
NEOTEST_STATIC_CHECK_VALUE_GT(value_1,value_2);
// check(value_1 >= value_2)
NEOTEST_STATIC_CHECK_VALUE_GE(value_1,value_2);
// check(value_1 < value_2)
NEOTEST_STATIC_CHECK_VALUE_LT(value_1,value_2);
// check(value_1 <= value_2)
NEOTEST_STATIC_CHECK_VALUE_LE(value_1,value_2);
```
### 编译期类型比较表达式
```cpp
// check(true == ::std::is_same_v<value_1,value_2>)
NEOTEST_STATIC_CHECK_TYPE_EQ(value_1,value_2);
// check(false == ::std::is_same_v<value_1,value_2>)
NEOTEST_STATIC_CHECK_TYPE_NE(value_1,value_2);
```
