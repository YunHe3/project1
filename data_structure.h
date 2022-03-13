#pragma once
#include "string"
using namespace std;
class Goods // ��Ʒ��
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
	void Modify(string); // �޸���Ʒdetail��Ϣ
    void Modify(float ); // �޸���Ʒ�۸���Ϣ
	void Remove(); // ɾ������Ʒ
	void Sold(); // ������Ʒ����������
	void Likes(); // ����Ʒ���빺�ﳵ
    void ShowInformation(); // չʾ��Ʒ������Ϣ
    void ShowDetail(); // չʾ��Ʒ������Ϣ
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
};
class User // �û���
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
	void SignUp(); // ע��
	void LogOut(); // ����ע��
	void Modify(); // �û���Ϣ�޸�
	void BuyGood(Goods* g); // ����g��Ʒ
	void ReleaseGood(Goods* g); // ����g��Ʒ
    void ModifyGood(int num,int choose,string re); // �޸ĸ��˷�����Ʒ�е�num����Ʒ����Ϣ
	void ShowMyGoods(); // չʾ������Ʒ
    void ShowMyGood(int num); //չʾ���˷�����Ʒ�е�num����Ʒ����Ϣ����������
	void ShowMyList(); // չʾ���˹��ﳵ
	void Ban(); // ���
    void ShowMyMoney(); // ��ʾ���
private:
    static int user_num;
	string uid; // uid
	string name; // �û���
	string password; // ����
	string phone_number; // �û���ϵ��ʽ
	string locate; // �û���ַ
	bool isbanned; // ���״̬
	Goods* mygood[20]; // ���˷�������Ʒ
	Goods* shoopping_list[20]; // ���ﳵ
	int money; // ���
    int r_goods; // ������Ʒ��
    int b_goods; // ������Ʒ��
};
class Administrator // ����Ա��
{

};
class Transaction // ������
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
    string tid; // ����id
    string gid; // ��Ʒid
    float price; // ���׵���
    string uid_s; // ����id
    string uid_b; // ��id
    string transaction_time; // ����ʱ��
    int like; // ��Ǻ���/����
};
