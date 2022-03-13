#include<iostream>
#include "platform.h"
#include <map>

using namespace std;

map<string,User*> user_name; // �û�������󹹽�map
map<string,Goods*> good_name;
void pre_load() // ��������
{
    user_name.clear();
    good_name.clear();

}
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
    string words = "1.����Ա��½ 2.�û���½ 3.�˳�����";
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

void User_Model() // �û�ģʽ��½����
{
    string words = "1.�����˺ţ���½ 2.��û���˺ţ�ע��һ��";
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
                cout << "-----��½�ɹ�-----"<<'\n';
                User_Choose(user_name[name]);
            }
            else cout << "�û�������������Զ��˻���һ��";
        }
        else if (choose==2) SignUp_Window();
        else if (choose==3) break;
        else cout << "�����������������";
        say_again(words);
    }

}
bool check(string name, string password) // �û��������Ӧ���
{

}

void User_Choose(User* user) // �û�ѡ�����
{
    string words = "1.������Ʒ 2.������Ʒ 3.�鿴������Ϣ 4.ע����½";
    say(words);
    int choose = 0;
    cin >> choose;
    while (true)
    {
        if (choose==1) Buy_Window(user);
        else if (choose==2) Release_Window(user);
        else if (choose==3) MyDetail_Window(user);
        else if (choose==4) break;
        else cout << "�����������������";
        say_again(words);
    }
}
void Administrator_Model() // ����Աģʽ��½����
{

}
void Buy_Window(User* user) // ��Ʒ�������
{

}

void Release_Window(User* user) // ��Ʒ��������
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
            cout << "----����д��Ʒ�������Ϣ"<<'\n' << "��Ʒ������";
            cin >> num;
            cout << '\n' << "��Ʒ���ƣ�";
            cin >> name;
            cout << '\n' << "��Ʒ�۸�";
            cin >> price;
            cout << '\n' << "��Ʒ��ϸ��Ϣ��";
            cin >> detail;
            // ��������Ʒ
            cout<<"*********************";
            cout<<'\n'<<"��ȷ����Ʒ��Ϣ����";
            cout<<"��Ʒ���ƣ�"<<name<<'\n'<<"��Ʒ�۸�"<<price<<'\n'<<"��Ʒ������"<<num<<'\n'<<"��Ʒ��ϸ��Ϣ��"<<detail<<'\n';
            cout<<"����Ϣ��������y��ȷ�ϴ˴β�������������nȡ���˴β�����";
            char check;
            cin>>check;
            if(check=='y'){
                Goods* new_good = new Goods(num,price,name,detail,user->show_name());
                user->ReleaseGood(new_good);
                cout<<"�����ɹ�"<<'\n';
                break;
            }
            else if(check=='n'){
                cout<<"ȡ������"<<"\n";
                break;
            }
            else{
                cout<<"��Ч����"<<'\n';
                break;
            }

        }
        else if(choose==2)
        {
            user->ShowMyGoods();
            cout<<cut;
            cout<<"�������ض�����Զ���Ʒ���в�����������0�Է�����һ����";
            int sub_choose;
            cin>>sub_choose;
            if(sub_choose==0)break;
            else if (sub_choose>user->r_num()){
                cout<<"�����ڸ���Ʒ������ʧ��"<<'\n';
                break;
            }
            else{
                user->ShowMyGood(sub_choose);
                cout<<"��������Ҫ�޸ĵ�����(1.�۸� 2.����)��";
                int subsub_choose;
                cin>>subsub_choose;
                if(subsub_choose!=1&&sub_choose!=2){
                    cout<<"�������ָ�";
                    break;
                }
                cout<<"�������޸ĺ��ֵ��";
                string re;
                cin>>re;
                user->ModifyGood(sub_choose,subsub_choose,re);
                cout<<"�޸ĳɹ���";
                break;
            }
        }
        else if(choose==3)
        {

        }
        else if(choose==4) break;
        else cout<<"�����������������";
        say_again(words);
    }
}

void MyDetail_Window(User* user) // ������Ϣ����
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