#include<iostream>
#include<string>
#include "platform.h"

using namespace std;
string cut = "======================================================================================================";
void say(string words)
{
    cout << cut << '\n';
    cout << words << '\n';
    cout << cut << '\n';
    cout << "���������";
}
void say_again(string words)
{
    cout << '\n'<<'\n'<<'\n'<<'\n';
    cout << cut << '\n';
    cout << words << '\n';
    cout << cut << '\n';
    cout << "���������";
}
void Login_Window() // ������
{
    string words = "1.����Ա��¼ 2.�û���¼ 3.�˳�����";
    say(words);
    int choose = 0;
    cin >> choose;
    while (true) {
        if (choose == 1) Administrator_Model();
        else if (choose == 2) User_Model();
        else if (choose == 3) break;
        else cout << "�����������������";
        say_again(words);
        cin >> choose;
    }
}

void SignUp_Window() // ע�����
{

}

void User_Model() // �û�ģʽ��¼����
{
    string words = "1.�����˺ţ���¼ 2.��û���˺ţ�ע��һ��";
    say(words);
    int choose = 0;
    cin >> choose;
    while (true)
    {
        if (choose==1)
        {
            string name;
            string password;
            cout << "�������û�����";
            cin >> name;
            cout << '\n';
            cout << "���������룺";
            cin >> password;
            if (check(name,password))
            {
                cout << "-----��¼�ɹ���-----"<<'\n';
                User_Choose();
            }
            else cout << "�û�������������Զ��˻���һ��";
        }
        else if (choose==2) SignUp_Window();
        else if (choose==3) break;
        else cout << "����=��������������";
        say_again(words);
    }

}
bool check(string name, string password)
{

}

void User_Choose() // �û�ѡ�����
{
    string words = "1.������Ʒ 2.������Ʒ 3.�鿴������Ϣ 4.ע����¼";
    say(words);
    int choose = 0;
    cin >> choose;
    while (true)
    {
        if (choose==1) Buy_Window();
        else if (choose==2) Release_Window();
        else if (choose==3) MyDetail_Window();
        else if (choose==4) break;
        else cout << "�����������������";
        say_again(words);
    }
}
void Administrator_Model() // ����Աģʽ��¼����
{

}
void Buy_Window() // ��Ʒ�������
{

}

void Release_Window() // ��Ʒ��������
{
    string words = "1.������Ʒ 2.�鿴������Ʒ 3.�鿴��ʷ���� 4.�����û�������";
    say(words);
    int choose = 0;
    cin >> choose;
    while(true)
    {
        if(choose==1)
        {
            string name,detail;
            float price;
            int num;
            cout << "----����д��Ʒ�������Ϣ----"<<'\n';
            cout << "";
        }

    }
}

void MyDetail_Window() // ������Ϣ����
{

}

void GoodsDetailS_Window() // �����ӽ���Ʒ��ϸ����
{

}

void GoodsDetailB_Window() // ����ӽ���Ʒ��ϸ����
{

}

void GoodsDetailA_Window() // ����Ա�ӽ���Ʒ��ϸ����
{

}

void ShowUser_Window() // �û��������
{

}

void ShowTransaction_Window() // �����������
{

}