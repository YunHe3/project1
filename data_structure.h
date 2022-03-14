#pragma once
#include "string"
using namespace std;
class User;
class Goods // 商品类
{
public:
    Goods(int num, float price, string name, string detail, string release_id);
    void S_Remove();
	void Modify(string); // 修改商品detail信息
    void Modify(float ); // 修改商品价格信息
	void Remove(); // 删除该商品
	void Sold(User* ,User*,int); // 出售商品并创建订单
	void Likes(); // 将商品加入购物车
    void ShowInformation(); // 展示商品基本信息
    void ShowDetail(); // 展示商品所有信息
    int state(); // 返回商品状态
    void ShowInformationB(); // 买家视角商品信息
    string id();
    int stock(); // 返回库存
    float unit_price(); // 返回单价
    string seller();
private:
    static int total_num;
	int num; // 商品数量
	string gid; // 商品序列号
	string name; // 商品名称
	float price; // 价格
	string detail; // 商品详细信息
	int status; // 商品状态（在售=1，移除=0，下架=-1）
	string release_id; // 发布者id
	int likes_count; // 加入购物车人数
    string re_time; // 上架时间
};
class Transaction // 订单类
{
public:
    Transaction(string uid_s,string uid_b,string gid,float price,int num);
    void ShowInformation(char );
    string seller();
    string buyer();
    string orderID();
private:
    static int tran_num;
    string tid; // 订单id
    string gid; // 商品id
    float price; // 交易单价
    string uid_s; // 卖方id
    string uid_b; // 买方id
    int num; // 交易数量
    string transaction_time; // 交易时间
    int like; // 标记好评/差评
};
class User // 用户类
{
public:
    User(string na,string pw,string pn, string lo);
    string show_name();
    string show_password();
    int r_num();
	void SignUp(); // 注册
	void LogOut(); // 永久注销
	void Modify(); // 用户信息修改
	void BuyGood(Goods* g,int ); // 购买g商品
	void ReleaseGood(Goods* g); // 发布g商品
    void SellGood(Goods* g,int ); // 出售g商品
    void ModifyGood(int num,int choose,string re); // 修改个人发布商品中第num个商品的信息
	void ShowMyGoods(); // 展示个人商品
    void ShowMyGood(int num); //展示个人发布商品中第num个商品第信息，包括详情
    void ShowMyTransactionS();
    void ShowMyTransactionB();
	void ShowMyList(); // 展示个人购物车
	void Ban(); // 封禁
    void ShowMyMoney(); // 显示余额
    void RemoveGoods(int num);
    void AddOrder(Transaction*);
    int TranNum();
    Transaction* MyTransaction(int );
private:
    static int user_num;
	string uid; // uid
	string name; // 用户名
	string password; // 密码
	string phone_number; // 用户联系方式
	string locate; // 用户地址
	bool banned; // 封禁状态
	Goods* my_good[20]; // 个人发布的商品
	Goods* shopping_list[20]; // 购物车
    Transaction* my_transaction[100];
	int money; // 余额
    int r_goods; // 发布商品数
    int b_goods; // 购买商品数
    int t_num; // 订单数量
};
class Administrator // 管理员类
{

};

