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
    cout << "输入操作：";
}
void say_again(string words)
{
    cout << '\n'<<'\n'<<'\n'<<'\n';
    cout << cut << '\n';
    cout << words << '\n';
    cout << cut << '\n';
    cout << "输入操作：";
}
void Login_Window() // 主界面
{
    string words = "1.管理员登录 2.用户登录 3.退出程序";
    say(words);
    int choose = 0;
    cin >> choose;
    while (true) {
        if (choose == 1) Administrator_Model();
        else if (choose == 2) User_Model();
        else if (choose == 3) break;
        else cout << "输入错误，请重新输入";
        say_again(words);
        cin >> choose;
    }
}

void SignUp_Window() // 注册界面
{

}

void User_Model() // 用户模式登录界面
{
    string words = "1.已有账号，登录 2.还没有账号，注册一个";
    say(words);
    int choose = 0;
    cin >> choose;
    while (true)
    {
        if (choose==1)
        {
            string name;
            string password;
            cout << "请输入用户名：";
            cin >> name;
            cout << '\n';
            cout << "请输入密码：";
            cin >> password;
            if (check(name,password))
            {
                cout << "-----登录成功！-----"<<'\n';
                User_Choose();
            }
            else cout << "用户名或密码错误，自动退回上一步";
        }
        else if (choose==2) SignUp_Window();
        else if (choose==3) break;
        else cout << "输入=错误，请重新输入";
        say_again(words);
    }

}
bool check(string name, string password)
{

}

void User_Choose() // 用户选择界面
{
    string words = "1.购买商品 2.发布商品 3.查看个人信息 4.注销登录";
    say(words);
    int choose = 0;
    cin >> choose;
    while (true)
    {
        if (choose==1) Buy_Window();
        else if (choose==2) Release_Window();
        else if (choose==3) MyDetail_Window();
        else if (choose==4) break;
        else cout << "输入错误，请重新输入";
        say_again(words);
    }
}
void Administrator_Model() // 管理员模式登录界面
{

}
void Buy_Window() // 商品购买界面
{

}

void Release_Window() // 商品发布界面
{
    string words = "1.发布商品 2.查看发布商品 3.查看历史订单 4.返回用户主界面";
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
            cout << "----请填写商品的相关信息----"<<'\n';
            cout << "";
        }

    }
}

void MyDetail_Window() // 个人信息界面
{

}

void GoodsDetailS_Window() // 卖家视角商品详细界面
{

}

void GoodsDetailB_Window() // 买家视角商品详细界面
{

}

void GoodsDetailA_Window() // 管理员视角商品详细界面
{

}

void ShowUser_Window() // 用户管理界面
{

}

void ShowTransaction_Window() // 订单管理界面
{

}