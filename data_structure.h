#pragma once
#include "string"
using namespace std;
class Goods // 定义商品类
{
public:
    Goods(int num, float price, string name, string detail, string release_id)
    {
        this->num = num;
        this->name = name;
        this->detail = detail;
        this->release_id = release_id;
        this->price = price;
        gid = 'M'+ to_string(total_num);

    }
	void Modify(); // 修改商品信息
	void Remove(); // 删除该商品
	void Sold(); // 出售商品并创建订单
	void Likes(); // 将商品加入购物车
private:
    static int total_num;
	int num; // 商品数量
	string gid; // 商品序列号
	string name; // 商品名称
	float price; // 价格
	string detail; // 商品的详细信息
	int status; // 标记商品状态(在售=1，移除=0，下架=-1)
	string release_id; // 发布者id
	int likes_count; // 加入购物车人数
};
class User // 定义用户类
{
public:
	void SignUp(); // 注册
	void LogOut(); // 永久注销
	void Modify(); // 实现用户信息的修改,比如密码、签名等
	void BuyGood(Goods &g); // 发布g商品
	void ReleaseGood(Goods &g); // 下架g商品
	void ShowMyGoods(); // 展示个人商品
	void ShowMyList(); // 展示个人购物车
	void Ban(); // 封禁
private:
	char uid[4] = { 'U' }; // uid
	char name[10]; // 用户名
	char password[20]; // 密码
	char phone_number[20]; // 用户联系方式
	char locate[20]; // 用户地址
	bool isbanned; // 封禁状态
	char mygoods[21][3]; // 个人商品，[有序排列][gid]
	char shoopping_list[21][3]; // 购物车
	int money; // 余额
};
class Administrator // 定义管理员类
{

};
class Transaction // 定义订单结构体
{

};
