#pragma once
#include "string"
using namespace std;
class Goods // 商品类
{
public:
    Goods(int num, float price, string name, string detail, string release_id)
    {
        this->num = num;
        this->name = name;
        this->detail = detail;
        this->release_id = release_id;
        this->price = price;
        gid = 'M'+ to_string(total_num++);
        status = 1;
        likes_count = 0;
    }
	void Modify(string); // 修改商品detail信息
    void Modify(float ); // 修改商品价格信息
	void Remove(); // 删除该商品
	void Sold(); // 出售商品并创建订单
	void Likes(); // 将商品加入购物车
    void ShowInformation(); // 展示商品基本信息
    void ShowDetail(); // 展示商品所有信息
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
};
class User // 用户类
{
public:
    User(string na,string pw,string pn, string lo)
    {
            name = na;
            password = pw;
            phone_number = pn;
            locate = lo;
            uid = 'U'+ to_string(user_num++);
            isbanned = false;
            r_goods = 0;
            b_goods = 0;

    }
    string show_name();
    int r_num();
	void SignUp(); // 注册
	void LogOut(); // 永久注销
	void Modify(); // 用户信息修改
	void BuyGood(Goods* g); // 购买g商品
	void ReleaseGood(Goods* g); // 发布g商品
    void ModifyGood(int num,int choose,string re); // 修改个人发布商品中第num个商品的信息
	void ShowMyGoods(); // 展示个人商品
    void ShowMyGood(int num); //展示个人发布商品中第num个商品第信息，包括详情
	void ShowMyList(); // 展示个人购物车
	void Ban(); // 封禁
    void ShowMyMoney(); // 显示余额
private:
    static int user_num;
	string uid; // uid
	string name; // 用户名
	string password; // 密码
	string phone_number; // 用户联系方式
	string locate; // 用户地址
	bool isbanned; // 封禁状态
	Goods* mygood[20]; // 个人发布的商品
	Goods* shoopping_list[20]; // 购物车
	int money; // 余额
    int r_goods; // 发布商品数
    int b_goods; // 购买商品数
};
class Administrator // 管理员类
{

};
class Transaction // 订单类
{
public:
    Transaction(string uid_s,string uid_b,string gid,float price){
        tid = 'T'+ to_string(tran_num++);
        this->gid = gid;
        this->price = price;
        this->uid_b = uid_b;
        this->uid_s = uid_s;
        this->like = 0;
    }
private:
    static int tran_num;
    string tid; // 订单id
    string gid; // 商品id
    float price; // 交易单价
    string uid_s; // 卖方id
    string uid_b; // 买方id
    string transaction_time; // 交易时间
    int like; // 标记好评/差评
};
