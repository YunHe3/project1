# project1
NJU高程project1
该项目为简略版东奥纪念品交易平台，各文件功能如下：
```
project1\data_structure.h // 自定义数据类型
project1\platform.cpp // 平台系统模块
project1\toolbox.cpp // 一些自定义功能函数，用于支持平台系统
project1\sql_interpreter.cpp // 字符串指令处理模块
project1\calculator.cpp // 简易计算器模块
```
## 自定义数据类型
### User类
普通用户类
* 拥有账号、密码、是否被封禁、个人商品（包括发布的与购买的）、购物车、余额、操作日志等数据成员
* 拥有注册、删除、修改密码、发布修改下架商品、购买商品等成员函数
```
class User
{
public:
    void SignUp(); // 注册
    void LogOut(); // 注销，永久
    void Modify(); // 实现用户信息的修改，比如密码、签名等
    void BuyGood(Goods g); // 购买g商品
    void ReleaseGood(Goods g); // 发布g商品
    void RemoveGood(Goods g); // 下架g商品
    void ShowMyGoods(); // 展示个人商品
    void ShowMyList(); // 展示个人购物车
    void Ban(); // 封禁
private:
    char uid[4]={'U'}; // uid序列号
    char name[10]; // 用户名 
    char password[20]; // 密码
    char phone_number[20]; // 用户联系方式
    char locate[20]; // 用户地址
    bool isbanned; // 封禁状态
    char mygoods[21][21]; // 个人商品
    char shoppoing_list[21][21]; // 购物车
    int money; // 余额
}
```
### Administrator类
管理员类
* 拥有账户密码(**硬编码**)、操作日志等数据成员
* 拥有下架商品、封禁用户等成员函数
```
class Administrator
{
private:
    char id[7]; // 账号
    char password[21]; // 密码
}
```
### Goods类
商品类
* 拥有序列号、商品名称、描述（卖家发布的细节信息）、状态、发布者、购买者、收藏者（加入购物车）等数据成员 
* 拥有创建商品、修改商品等成员函数
```
class Goods
{
public:
    void Release(); // 创建新商品
    void Modify(); // 修改商品信息
    void Remove(); // 删除该商品
    void Sold(); // 出售商品并创建订单
    void Likes(); // 将商品加入购物车
private:
    int num; // 商品数量
    char gid[3]={'M'}; // 商品序列号
    char name[21]; // 商品名称
    float price; // 商品价格
    char detail[100]; // 商品的详细信息
    int status; // 标记商品状态(在售、移除、下架)
    char release_id[4]; // 发布者id
    int likes_count; // 加入购物车人数
}
```
### Transaction结构
订单结构体
* 拥有商品信息，买方，卖方，交易时间等元素
```
struct Transcation
{
    char tid[4]={'T'}; // 订单id
    char gid[4]={'M'}; // 商品id
    float price; // 交易单价
    char uid_s[4]; // 卖方id
    char uid_b[4]; // 买方id
    char transcation_time[10]; // 交易时间
    int like; // 标记好评/差评
}
```

## 东奥纪念品买卖平台管理系统模块
**功能需求：**
* 管理员管理整个系统
* 用户作为买家购买他人商品
* 用户作为卖家发布自己的商品

### **流程描述：**
注意，下述所有用户与管理员的对信息的修改都需要通过sql_interpreter模块进行

首先进入**登录界面**，用户选择登录类型，输入账号密码，判断用户类型（分为管理员与普通用户）进入**普通用户模式登录**或**管理员模式登录**；或选择进入**用户注册界面**

* 判断为普通用户登录，用户可选择服务界面：**购买商品**界面或**发布商品**界面或**个人信息界面**，以及注销操作
    * 进入**发布商品界面**，展示该用户所有的发布商品（包括下架与在售的），可进行如下操作：商品的发布、下架，修改商品信息，查看已发布商品，其中商品的下架、修改在**详情界面**。
        * 进入商品的发布功能，用户输入商品的相应信息，即可完成发布，返回发布商品界面
        * 进入商品的**详情界面**，展示商品的详细信息（比如卖家留言），并可选择对商品进行下架、修改操作，结束后返回发布商品界面
            * 进入修改功能，可指定对某一信息进行修改，修改存在确定环节，结束修改后可选择是否继续修改，选择是则重新进入修改功能，否则返回
            * 下架功能也存在确定环节，可撤销此次下架

    * 进入**购买商品界面**，可进行如下操作：查看**买家商品详细信息界面**、**搜索商品界面**
        * 可通过键入商品展示的序号来进入商品详细信息界面
        * 进入搜索商品功能，可实现根据商品**名字**及**详细信息**或**发布者**的搜索，展示给用户搜索结果，跳转回上一界面，用户可再次执行同样操作
    * 进入个人信息界面，可查看历史订单与个人信息查看与修改

* 判断为管理员登录，管理员可选择服务界面：**商品管理界面**，**用户管理界面**，**订单查看界面**，以及注销操作
    * 进入**商品管理界面**，展示所有商品，可选择进入**管理员视觉商品详情界面**
    * 进入**用户管理界面**，展示所有用户
    * 进入**订单查看界面**，展示所有订单


### 接口
**注意，以下接口函数参数列表全部省略**
```
void Login_Window(); // 登录界面
void SignUp_Window(); // 用户注册界面
void User_Model(); // 用户模式登录
void Administrator_Model(); // 管理员模式登录
void Buy_Window(); // 商品购买界面
void Release_Window(); // 商品发布界面
void MyDetail_Window(); // 个人信息界面
void GoodsDetailS_window(); // 卖家视角商品详细信息界面
void GoodsDetailB_window(); // 买家视角商品详细信息界面
void GoodsDetailA_Window(); // 管理员视角商品详细信息界面
void ShowUser_Window(); // 用户管理界面
void ShowTransaction_Window(); // 订单管理界面
```
### 预设函数
```
void SearchGoods(); // 对限定条件商品进行搜索展示
void SearchUsers(); // 对限定条件用户进行搜索展示
void SearchTransaction(); // 对限定条件订单进行搜索展示

```
## 字符串指令解析及处理模块
**功能需求：**
* 接受用户在交互时给出的命令行指令
* 根据命令行指令合成字符串指令
* 操作库存/用户等文件，并返回信息至交互界面
### 指令生成函数


### 指令翻译函数


## 简易计算器模块
**功能需求**
* 接收四则运算表达式（字符串）
* 进行字符串解析并计算

**具体实现**
* 对表达式进行错误检查
  * 括号不匹配
  * 运算符使用错误（连续出现两个运算符）
  * 除零错误
  * 非法操作数
* 利用栈结构来实现表达式中缀转后缀
* 利用栈实现后缀表达式求值




