# `neotest`
`neotest`是一个简易的单元测试库.

`neotest`库使用`C++20`语言标准编写,
只使用`C++20`标准库功能完成实现.

## 依赖
`neotest`库只依赖`C++20`标准库,无其他第三方库依赖.
### 编译器扩展
`neotest`库中使用了如下的编译器扩展功能,在此列出:

`MSVC`编译器:`_MSC_VER`,`__COUNTER__`,`__FUNCSIG__`

其他编译器:`__COUNTER__`
## 快速使用
### 引入库
```cpp
#include<neotest/neotest.h>
```
### 计时器
`neotest`库提供了一个简易的计时器类`::neotest::Timer`
来统计一段代码实际执行所用的时间.
#### 基本使用案例
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
#### 累加计时功能
```cpp
::neotest::Timer timer;
timer.start();
//...需要计时的代码段1
timer.stop();
//...do something
timer.start();
//...需要计时的代码段2
timer.stop();
//打印计时结果(代码段1和2的总计执行时间)
::std::cout<<timer.duration_string();
```
#### 重置计时功能
```cpp
::neotest::Timer timer;
timer.start();
//...需要计时的代码段1
timer.stop();
//...do something
timer.start();
//清空之前的计时结果(不改变计时器状态)
//此语句放在上一行的`timer.start()`之前,实际效果是一样的
timer.reset();
//...需要计时的代码段2
timer.stop();
//打印计时结果(代码段2的执行时间)
::std::cout<<timer.duration_string();
```
### 测试单元
`neotest`库提供了`NEOTEST_CASE()`宏函数用来定义一个测试单元.

#### 定义
`NEOTEST_CASE()`支持字符串字面量/原始字面量来表示一个测试单元的名称.

同样的`NEOTEST_CASE()`也支持空字符串作为测试单元的名称.
```cpp
NEOTEST_CASE("hello"){
    //...这里是你的单元测试代码
}
NEOTEST_CASE(R"("hello world!")"){//<=>NEOTEST_CASE("\"hello world!\"")
    //...这里是你的单元测试代码
}
NEOTEST_CASE(""){
    //...这里是你的单元测试代码
}
```
在测试单元的内部可以除了普通的代码之外,
可以使用`neotest`库提供的多种表达式用于检测代码的执行结果.
#### 未定义行为
###### 在非全局作用域定义`NEOTEST_CASE`
请在全局作用域使用`NEOTEST_CASE()`来定义测试单元.

在其他作用域,例如命令空间/函数/类内部定义`NEOTEST_CASE`属于未定义行为.
###### 给`NEOTEST_CASE`添加函数修饰符
下面是一个错误的使用案例:
```cpp
inline static constexpr NEOTEST_CASE("ha ha!")noexcept{
    //...
}
```
###### 定义重名的`NEOTEST_CASE`
下面是一个错误的使用案例:
```cpp
NEOTEST_CASE("foo"){
    //...
}
NEOTEST_CASE("foo"){//可能会引发编译失败,类型重定义错误
    //...
}
```
#### 执行测试单元
###### 方式一:先执行测试,后自定义测试结果导出格式
`neotest`库提供了如下的函数来查找/执行测试单元.
```cpp
namespace neotest{

//通过名称来查找并执行测试单元
::neotest::ExecuteCaseInfo execute_case(
    ::std::string_view case_name
)noexcept;

//通过正则表达式匹配符合条件测试单元的名称并执行这些测试单元
::std::vector<::neotest::ExecuteCaseInfo> execute_case(
    ::std::regex const& case_name_regex
)noexcept;

//通过名称/正则表达式的序列组合来查找并顺序执行一个测试单元序列
::std::vector<::neotest::ExecuteCaseInfo> execute_case(
    ::std::vector<std::variant<std::string_view,::std::regex>> const&
        case_name_list
)noexcept;
::std::vector<::neotest::ExecuteCaseInfo> execute_case(
    ::std::initializer_list<std::variant<std::string_view,::std::regex>>
        case_name_list
)noexcept;

//按照测试单元的定义顺序,顺序执行所有的测试单元
::std::vector<::neotest::ExecuteCaseInfo> execute_case_all(void)noexcept;

}//namespace neotest
```
函数的返回值类型为`::neotest::ExecuteCaseInfo`或者相关的序列类型.

`ExecuteCaseInfo`类提供了丰富的成员读取接口,用来自定义测试结果导出格式.

当然`neotest`库也提供了默认的导出接口`::neotest::to_json()`,
可以用它来导出`ExecuteCaseInfo`和它的序列类型到`::std::string`类型的`JSON`.

###### 方式二:执行测试并直接导出为`JSON`
`neotest`库为了简化测试结果导出过程,
为方式一的每个函数接口提供了相应的衍生函数接口.
命名格式为:

`execute_case*` `->` `execute_case*_to_json`

`execute_case*_to_json`函数接口的返回值类型为`::std::string`.

调用`execute_case*_to_json`函数接口会执行测试单元并导出为`JSON`,
存放到`::std::string`返回结果中.
#### 运行时检查
`NEOTEST_RUNTIME_CHECK*`表达式用于检查一个条件表达式是否成立.

当条件表达式的结果为`false`时,会记录下相应的信息.
但不会中断当前测试单元的执行.
###### 逻辑表达式
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
###### 值比较表达式
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
###### 如何获得测试结果
如果`NEOTEST_RUNTIME_CHECK*`表达式是定义在`NEOTEST_CASE(){}`定义范围内的,
`neotest`库提供了`execute_*`函数来进行`NEOTEST_CASE`/`NEOTEST_GROUP`的执行,
并返回记录执行结果信息的`ExecuteCaseInfo`/`ExecuteGroupInfo`类对象.

之后使用`::neotest::to_json()`将类对象转换成`::std::string`类型的`JSON`.

然后就可以配合`IO`流/文件流进行测试结果的终端打印/写入文件等操作.

当然为了简化这个繁琐的测试结果导出过程,`neotest`库提供了`execute_*_to_json`函数
来进行一步到位的`JSON`导出.

同样地`NEOTEST_RUNTIME_CHECK*`表达式也支持单独使用,
如果检查失败,测试结果会在执行时,在终端显示检查失败的错误信息,
并且不会阻断程序的继续执行.

###### 自定义消息和自定义类型信息
```cpp
NEOTEST_CASE("mytest"){
    NEOTEST_RUNTIME_CHECK(1+1!=2)<<int{1}<<'+'<<int{1}<<"!=2?";
    NEOTEST_RUNTIME_CHECK_AND(true,false)<<::std::format("check {} && {}",true,false);
    NEOTEST_RUNTIME_CHECK_OR(false,false)<<"this is msg";
    NEOTEST_RUNTIME_CHECK_NOT(true)<<"";
    NEOTEST_RUNTIME_CHECK_EQ(1,2)<<"1 == 2?";
    NEOTEST_RUNTIME_CHECK_NE(1,1)<<"1 != 1?";
    NEOTEST_RUNTIME_CHECK_GT(1,2)<<"1 > 2?";
    NEOTEST_RUNTIME_CHECK_GE(1,2)<<"1 >= 2?";
    NEOTEST_RUNTIME_CHECK_LT(2,1)<<"1 < 2?";
    NEOTEST_RUNTIME_CHECK_LE(2,1)<<"1 <= 2?";
}
```
`NEOTEST_RUNTIME_CHECK*`宏的自定义类型信息功能依赖于`::neotest::OStringStream`,
`::neotest::OStringStream`的实现又依赖于`::std::ostringstream`.

然而`::std::ostringstream`并不支持所有类型的类型信息到字符串的转化,
因此`neotest`库提供了如下的解决方案来实现对自定义类型信息的支持:

如果要让`::neotest::OStringStream`支持自定义类型的信息,
可以自定义`::neotest::OStringStream`的运算符`<<`重载函数.

下面是一个具体的例子:
```cpp
struct Person{
    ::std::string_view name;
    short age;
};
::neotest::OStringStream&
operator<<(::neotest::OStringStream& oss,Person const& p)noexcept{
    return oss<<::std::format("Person{{name:{},age:{}}}",p.name,p.age);
}
NEOTEST_CASE("test.PersonCmp.RuntimeCheckFailed"){
    Person p1{"Tom",20};
    Person p2{"Jerry",10};
    Person p3{"Tom",20};
    NEOTEST_RUNTIME_CHECK(p1!=p3);
    NEOTEST_RUNTIME_CHECK(p1==p2);
    NEOTEST_RUNTIME_CHECK_NOT(p1==p3);
    NEOTEST_RUNTIME_CHECK_NOT(p1!=p2);
    NEOTEST_RUNTIME_CHECK_EQ(p1,p2);
    NEOTEST_RUNTIME_CHECK_NE(p1,p3);
}
```
可能的测试导出结果:
```txt
{
    "case name":"test.PersonCmp.RuntimeCheckFailed",
    "duration ns":16853,
    "duration string":"16 us 853 ns",
    "runtime check total":6,
    "runtime check passed":0,
    "runtime check failed":6,
    "runtime check passed rate":0,
    "runtime assert total":0,
    "runtime assert passed":0,
    "runtime assert failed":0,
    "runtime assert passed rate":1,
    "is passed":false,
    "is failed":true,
    "is skipped":false,
    "is undefined":false,
    "runtime check failed errors":[
        {
            "file":"neotest/tests/sample7.h",
            "line":"43",
            "info":"(true) == (p1!=p3)"
        },
        {
            "file":"neotest/tests/sample7.h",
            "line":"44",
            "info":"(true) == (p1==p2)"
        },
        {
            "file":"neotest/tests/sample7.h",
            "line":"45",
            "info":"(false) == (p1==p3)"
        },
        {
            "file":"neotest/tests/sample7.h",
            "line":"46",
            "info":"(false) == (p1!=p2)"
        },
        {
            "file":"neotest/tests/sample7.h",
            "line":"47",
            "info":"(Person{name:Tom,age:20}) == (Person{name:Jerry,age:10})"
        },
        {
            "file":"neotest/tests/sample7.h",
            "line":"48",
            "info":"(Person{name:Tom,age:20}) != (Person{name:Tom,age:20})"
        }
    ]
}
```
###### 单独使用(脱离`NEOTEST_CASE(){}`定义范围)
`NEOTEST_RUNTIME_CHECK*`表达式支持脱离`NEOTEST_CASE(){}`定义范围,
在其他语句块内进行使用.

检查结果会在表达式执行时结算,
如果检查失败,会在终端显示检查失败的错误信息,
但不会阻断当前程序的继续执行.

下面是一个具体的案例:
```cpp
void my_test_func(void)noexcept{
    NEOTEST_RUNTIME_CHECK(1+1!=2)<<"this is msg";
}
int main(void){
    my_test_func();
    return 0;
}
```
可能的输出结果:
```txt
{
    "file":"neotest/tests/sample10.h",
    "line":"8",
    "info":"(true) == (1+1!=2)",
    "msg":"this is msg"
}
```
#### 运行时断言
`NEOTEST_RUNTIME_ASSERT*`表达式用于检查一个条件表达式是否成立.

当条件表达式的结果为`false`时,会记录下相应的信息.
并中断当前测试单元的执行.
###### 逻辑表达式
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
###### 值比较表达式
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
###### 如何获得测试结果
和`NEOTEST_RUNTIME_CHECK*`类似,
如果`NEOTEST_RUNTIME_ASSERT*`表达式是定义在`NEOTEST_CASE(){}`定义范围内的,
按照之前介绍的使用`neotest`库提供的`execute_*`/`execute_*_to_json`函数
等方式导出测试结果.

同样地`NEOTEST_RUNTIME_ASSERT*`表达式也支持单独使用,
如果断言失败,测试结果会在执行时,抛出`::neotest::RuntimeAssertFailedException`异常,
如果没有捕获此异常,会在终端显示断言失败的错误信息,并阻断当前程序的执行.

###### 自定义消息和自定义类型信息
与`NEOTEST_RUNTIME_CHECK*`类似,
`NEOTEST_RUNTIME_ASSERT*`也支持自定义消息和自定义类型信息功能,不再赘述.
```cpp
NEOTEST_CASE("mytest"){
    NEOTEST_RUNTIME_ASSERT(1+1!=2)<<int{1}<<'+'<<int{1}<<"!=2?";
    NEOTEST_RUNTIME_ASSERT_AND(true,false)<<::std::format("assert {} && {}",true,false);
    NEOTEST_RUNTIME_ASSERT_OR(false,false)<<"this is msg";
    NEOTEST_RUNTIME_ASSERT_NOT(true)<<"";
    NEOTEST_RUNTIME_ASSERT_EQ(1,2)<<"1 == 2?";
    NEOTEST_RUNTIME_ASSERT_NE(1,1)<<"1 != 1?";
    NEOTEST_RUNTIME_ASSERT_GT(1,2)<<"1 > 2?";
    NEOTEST_RUNTIME_ASSERT_GE(1,2)<<"1 >= 2?";
    NEOTEST_RUNTIME_ASSERT_LT(2,1)<<"1 < 2?";
    NEOTEST_RUNTIME_ASSERT_LE(2,1)<<"1 <= 2?";
}
```
###### 单独使用(脱离`NEOTEST_CASE(){}`定义范围)
`NEOTEST_RUNTIME_ASSERT*`表达式支持脱离`NEOTEST_CASE(){}`定义范围,
在其他语句块中使用,
测试结果会在执行时进行结算.

如果断言失败,会抛出`::neotest::RuntimeAssertFailedException`异常,
如果没有捕获此异常,会在终端显示断言失败的错误信息,并阻断当前程序的执行.
```cpp
void my_test_func(void)noexcept{
    NEOTEST_RUNTIME_ASSERT(1+1!=2)<<"this is msg";
}
int main(void){
    my_test_func();
    return 0;
}
```
可能的输出结果:
```txt
terminate called after throwing an instance of 'neotest::RuntimeAssertFailedException'
  what():  [FILE] neotest/tests/sample10.h [LINE] 12 [INFO] (true) == (1+1!=2) [MSG] this is msg
Aborted
```
#### 跳过
除了上述的两种表达式,
`neotest`还提供了`NEOTEST_SKIP()`宏函数用于在某些情况下提前跳出当前的测试单元.

注意:`NEOTEST_SKIP()`不支持脱离`NEOTEST_CASE(){}`定义范围单独使用.

`NEOTEST_SKIP()`执行时会记录相应的信息,
宏函数参数支持空输入`()`或`("")`,
或指定一个自定义原因字符串.

原因字符串支持如下的2种方式:
1. 字符串字面量
2. 可以赋值给`::std::string`的值

下面给出一个具体的使用案例:
```cpp
NEOTEST_CASE("test_file"){
    ::std::ofstream ofs("input.txt");
    if(!ofs.is_open()){
        ::std::string_view reason={"文件打开失败"};
        NEOTEST_SKIP(reason);
    }
    //...文件测试代码
}
```
###### 自定义消息和自定义类型信息
与`NEOTEST_RUNTIME_CHECK*`/`NEOTEST_RUNTIME_ASSERT*`类似,
`NEOTEST_SKIP`也支持自定义消息和自定义类型信息功能,不再赘述.
```cpp
NEOTEST_SKIP("this is reason")
    <<"this is skip msg"
    <<int{100}
    <<::std::format("fmt{}",double{0.0});
```
### 测试组
`neotest`库提供了`NEOTEST_GROUP`来组合零个或多个`NEOTEST_CASE`.

使用`NEOTEST_GROUP`比使用单个或多个`NEOTEST_CASE`来说,
有如下优势:
1. 指定`NEOTEST_CASE`成员的执行顺序
2. 可以使用正则表达式匹配符合的`NEOTEST_CASE`作为成员
3. 允许重复的`NEOTEST_CASE`成员
#### 定义
`NEOTEST_GROUP()`支持字符串字面量/原始字面量来表示一个测试单元的名称.

同样的`NEOTEST_GROUP()`也支持空字符串作为测试单元的名称.
```cpp
NEOTEST_GROUP("hello"){
    //...这里是你的单元测试代码
}
NEOTEST_GROUP(R"("hello world!")"){//<=>NEOTEST_GROUP("\"hello world!\"")
    //...这里是你的单元测试代码
}
NEOTEST_GROUP(""){
    //...这里是你的单元测试代码
}
```
###### 添加测试单元成员
在测试组的内部,
使用`neotest`库提供的`NEOTEST_GROUP_ELEMENT_CASE*`表达式添加测试单元成员.

注意:`NEOTEST_GROUP_ELEMENT_CASE*()`的输入参数只能使用字符串字面量/原始字面量.
```cpp
//通过测试单元的名称添加进组
NEOTEST_GROUP_ELEMENT_CASE(case_name_literal);
//通过正则表达式匹配查找符合要求的测试单元添加进组
NEOTEST_GROUP_ELEMENT_CASE_REGEX(case_name_pattern_literal);
```
下面是一个具体的使用案例:
```cpp
NEOTEST_GROUP("test Person"){
    NEOTEST_GROUP_ELEMENT_CASE("test Person name");
    NEOTEST_GROUP_ELEMENT_CASE("test Person age");
    NEOTEST_GROUP_ELEMENT_CASE_REGEX(R"(^test Person .*)");
}
```
#### 未定义行为
###### 在非全局作用域定义`NEOTEST_GROUP`
请在全局作用域使用`NEOTEST_GROUP()`来定义测试单元.

在其他作用域,例如命令空间/函数/类内部定义`NEOTEST_GROUP`属于未定义行为.
###### 给`NEOTEST_CASE`添加函数修饰符
下面是一个错误的使用案例:
```cpp
inline static constexpr NEOTEST_GROUP("ha ha!")noexcept{
    //...
}
```
###### 定义重名的`NEOTEST_GROUP`
下面是一个错误的使用案例:
```cpp
NEOTEST_GROUP("foo"){
    //...
}
NEOTEST_GROUP("foo"){//可能会引发编译失败,类型重定义错误
    //...
}
```
###### 在`NEOTEST_GROUP(){}`定义范围内书写无关语句(非添加测试单元成员语句)
下面是一个错误的使用案例:
```cpp
NEOTEST_GROUP("foo"){
    ::std::cout<<"hello world\n";
}
```
#### 执行测试组
###### 方式一:先执行测试,后自定义测试结果导出格式
`neotest`库提供了如下的函数来查找/执行测试组.
```cpp
namespace neotest{

//通过名称来查找并执行测试组
::neotest::ExecuteGroupInfo execute_group(
    ::std::string_view group_name
)noexcept;

//通过正则表达式匹配符合条件测试组的名称并执行这些测试组
::std::vector<::neotest::ExecuteGroupInfo> execute_group(
    ::std::regex const& group_name_regex
)noexcept;

//通过名称/正则表达式的序列组合来查找并顺序执行一个测试组序列
::std::vector<::neotest::ExecuteGroupInfo> execute_group(
    ::std::vector<std::variant<std::string_view,::std::regex>> const&
        group_name_list
)noexcept;
::std::vector<::neotest::ExecuteGroupInfo> execute_group(
    ::std::initializer_list<std::variant<std::string_view,::std::regex>>
        group_name_list
)noexcept;

//按照测试组的定义顺序,顺序执行所有的测试组
::std::vector<::neotest::ExecuteGroupInfo> execute_group_all(void)noexcept;

}//namespace neotest
```
函数的返回值类型为`::neotest::ExecuteGroupInfo`或者相关的序列类型.

`ExecuteGroupInfo`类提供了丰富的成员读取接口,用来自定义测试结果导出格式.

当然`neotest`库也提供了默认的导出接口`::neotest::to_json()`,
可以用它来导出`ExecuteGroupInfo`和它的序列类型到`::std::string`类型的`JSON`.

###### 方式二:执行测试并直接导出为`JSON`
`neotest`库为了简化测试结果导出过程,
为方式一的每个函数接口提供了相应的衍生函数接口.
命名格式为:

`execute_group*` `->` `execute_group*_to_json`

`execute_group*_to_json`函数接口的返回值类型为`::std::string`.

调用`execute_group*_to_json`函数接口会执行测试组并导出为`JSON`,
存放到`::std::string`返回结果中.
### 类型信息
#### 得到类型的编译期类型名字符串
`neotest`提供`::neotest::type_name_of`来取得类型的名称字符串.

返回值是`constexpr ::std::string_view`类型.
```cpp
::std::cout
    <<::neotest::type_name_of<int const volatile &>()
    <<::std::endl;
//output:"int const volatile &"
```
#### 得到变量的编译期类型名称字符串
同样地`neotest`为变量也提供了类型名的导出.

`neotest`库提供`NEOTEST_TYPE_NAME_OF_VARIABLE`来取得变量的真实类型名称字符串.

返回值是`constexpr ::std::string_view`类型.
```cpp
int const volatile num;
int const volatile& ref=num;
::std::cout
    <<NEOTEST_TYPE_NAME_OF_VARIABLE(ref)
    <<::std::endl;
//output:"int const volatile &"
```
### 编译期检查
为了支持测试模板元编程代码段的功能,
`neotest`库提供了`static_assert`之外的另一种有效的编译期检测手段.

`neotest`库提供`NEOTEST_STATIC_CHECK*`表达式用于进行编译期静态检查,

与`static_assert`不同的是,
`NEOTEST_STATIC_CHECK*(false)`不会导致编译失败,
而是在编译时显示警告信息,
然后继续执行编译.

下面是一个具体的案例:
```txt
NEOTEST_STATIC_CHECK(100==200);
```
如下是测试此语句时`GCC`编译器编译过程中显示的警告信息:

```txt
neotest/tests/sample6.h: In lambda function:
neotest/include/neotest/static_check.hpp:87:25: warning:
‘constexpr bool neotest::detail::StaticCheck<File__,Line__,Info__>::operator()
(neotest::detail::Bool<false>) const [
    with File__ = neotest::detail::File<
        neotest::StaticString<neotest::StaticCStr<char, 41>{
            "neotest/tests/sample6.h"
        }>
    >;
    Line__ = neotest::detail::Line<34>;
    Info__ = neotest::detail::Info<
        neotest::StaticString<neotest::StaticCStr<char, 21>{
            "(true) == (100==200)"
        }>
    >
]’
is deprecated: ::neotest::static_check(false) [-Wdeprecated-declarations]
   87 |             static_check(result) \
      |             ~~~~~~~~~~~~^~~~~~~~
neotest/tests/sample6.h:34:1: note: in expansion of macro ‘NEOTEST_STATIC_CHECK’
   34 | NEOTEST_STATIC_CHECK(100==200);
      | ^~~~~~~~~~~~~~~~~~~~
neotest/include/neotest/static_check.hpp:24:20: note: declared here
   24 |     constexpr bool operator()(::neotest::detail::Bool<false>)const noexcept{
      |                    ^~~~~~~~
```
#### `NEOTEST_STATIC_CHECK*`语句的使用范围
```cpp
//在全局作用域使用
NEOTEST_STATIC_CHECK("global scope",false);

void sample5_func(void)noexcept{
    //在函数内部使用
    NEOTEST_STATIC_CHECK("function scope",false);
}

class Sample5_Class{
    //在类内部使用
    NEOTEST_STATIC_CHECK("class scope",false);
};
```
#### 编译期值逻辑表达式
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
#### 编译期值比较表达式
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
#### 编译期类型比较表达式
检查两个类型的异同(类型包含可能存在的`cv ref`修饰符).
```cpp
// check(true == ::std::is_same_v<value_1,value_2>)
NEOTEST_STATIC_CHECK_TYPE_EQ(value_1,value_2);
// check(false == ::std::is_same_v<value_1,value_2>)
NEOTEST_STATIC_CHECK_TYPE_NE(value_1,value_2);
```
一个具体的使用案例:
```cpp
NEOTEST_STATIC_CHECK_TYPE_EQ(int,double); //false
NEOTEST_STATIC_CHECK_TYPE_EQ(int,int const); //false
NEOTEST_STATIC_CHECK_TYPE_EQ(int,int volatile); //false
NEOTEST_STATIC_CHECK_TYPE_EQ(int,int&); //false
NEOTEST_STATIC_CHECK_TYPE_EQ(int,int&&); //false
NEOTEST_STATIC_CHECK_TYPE_NE(int,int); //false
```
