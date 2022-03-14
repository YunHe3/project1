#pragma once
#include "string"
using namespace std;
class User;
class Goods // ��Ʒ��
{
public:
    Goods(int num, float price, string name, string detail, string release_id);
    void S_Remove();
	void Modify(string); // �޸���Ʒdetail��Ϣ
    void Modify(float ); // �޸���Ʒ�۸���Ϣ
	void Remove(); // ɾ������Ʒ
	void Sold(User* ,User*,int); // ������Ʒ����������
	void Likes(); // ����Ʒ���빺�ﳵ
    void ShowInformation(); // չʾ��Ʒ������Ϣ
    void ShowDetail(); // չʾ��Ʒ������Ϣ
    int state(); // ������Ʒ״̬
    void ShowInformationB(); // ����ӽ���Ʒ��Ϣ
    string id();
    int stock(); // ���ؿ��
    float unit_price(); // ���ص���
    string seller();
private:
    static int total_num;
	int num; // ��Ʒ����
	string gid; // ��Ʒ���к�
	string name; // ��Ʒ����
	float price; // �۸�
	string detail; // ��Ʒ��ϸ��Ϣ
	int status; // ��Ʒ״̬������=1���Ƴ�=0���¼�=-1��
	string release_id; // ������id
	int likes_count; // ���빺�ﳵ����
    string re_time; // �ϼ�ʱ��
};
class Transaction // ������
{
public:
    Transaction(string uid_s,string uid_b,string gid,float price,int num);
    void ShowInformation(char );
    string seller();
    string buyer();
    string orderID();
private:
    static int tran_num;
    string tid; // ����id
    string gid; // ��Ʒid
    float price; // ���׵���
    string uid_s; // ����id
    string uid_b; // ��id
    int num; // ��������
    string transaction_time; // ����ʱ��
    int like; // ��Ǻ���/����
};
class User // �û���
{
public:
    User(string na,string pw,string pn, string lo);
    string show_name();
    string show_password();
    int r_num();
	void SignUp(); // ע��
	void LogOut(); // ����ע��
	void Modify(); // �û���Ϣ�޸�
	void BuyGood(Goods* g,int ); // ����g��Ʒ
	void ReleaseGood(Goods* g); // ����g��Ʒ
    void SellGood(Goods* g,int ); // ����g��Ʒ
    void ModifyGood(int num,int choose,string re); // �޸ĸ��˷�����Ʒ�е�num����Ʒ����Ϣ
	void ShowMyGoods(); // չʾ������Ʒ
    void ShowMyGood(int num); //չʾ���˷�����Ʒ�е�num����Ʒ����Ϣ����������
    void ShowMyTransactionS();
    void ShowMyTransactionB();
	void ShowMyList(); // չʾ���˹��ﳵ
	void Ban(); // ���
    void ShowMyMoney(); // ��ʾ���
    void RemoveGoods(int num);
    void AddOrder(Transaction*);
    int TranNum();
    Transaction* MyTransaction(int );
private:
    static int user_num;
	string uid; // uid
	string name; // �û���
	string password; // ����
	string phone_number; // �û���ϵ��ʽ
	string locate; // �û���ַ
	bool banned; // ���״̬
	Goods* my_good[20]; // ���˷�������Ʒ
	Goods* shopping_list[20]; // ���ﳵ
    Transaction* my_transaction[100];
	int money; // ���
    int r_goods; // ������Ʒ��
    int b_goods; // ������Ʒ��
    int t_num; // ��������
};
class Administrator // ����Ա��
{

};

