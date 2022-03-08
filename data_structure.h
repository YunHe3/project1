#pragma once
#include "string"
using namespace std;
class Goods // ������Ʒ��
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
	void Modify(); // �޸���Ʒ��Ϣ
	void Remove(); // ɾ������Ʒ
	void Sold(); // ������Ʒ����������
	void Likes(); // ����Ʒ���빺�ﳵ
private:
    static int total_num;
	int num; // ��Ʒ����
	string gid; // ��Ʒ���к�
	string name; // ��Ʒ����
	float price; // �۸�
	string detail; // ��Ʒ����ϸ��Ϣ
	int status; // �����Ʒ״̬(����=1���Ƴ�=0���¼�=-1)
	string release_id; // ������id
	int likes_count; // ���빺�ﳵ����
};
class User // �����û���
{
public:
	void SignUp(); // ע��
	void LogOut(); // ����ע��
	void Modify(); // ʵ���û���Ϣ���޸�,�������롢ǩ����
	void BuyGood(Goods &g); // ����g��Ʒ
	void ReleaseGood(Goods &g); // �¼�g��Ʒ
	void ShowMyGoods(); // չʾ������Ʒ
	void ShowMyList(); // չʾ���˹��ﳵ
	void Ban(); // ���
private:
	char uid[4] = { 'U' }; // uid
	char name[10]; // �û���
	char password[20]; // ����
	char phone_number[20]; // �û���ϵ��ʽ
	char locate[20]; // �û���ַ
	bool isbanned; // ���״̬
	char mygoods[21][3]; // ������Ʒ��[��������][gid]
	char shoopping_list[21][3]; // ���ﳵ
	int money; // ���
};
class Administrator // �������Ա��
{

};
class Transaction // ���嶩���ṹ��
{

};
