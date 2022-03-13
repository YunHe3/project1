#include<iostream>
#include "platform.h"
#include <map>

using namespace std;

map<string,User*> user_name; // 用户名与对象构建map
map<string,Goods*> good_name;
void pre_load() // 加载数据
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
    string words = "1.管理员登陆 2.用户登陆 3.退出程序";
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

void User_Model() // 用户模式登陆界面
{
    string words = "1.已有账号，登陆 2.还没有账号，注册一个";
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
                cout << "-----登陆成功-----"<<'\n';
                User_Choose(user_name[name]);
            }
            else cout << "用户名或密码错误，自动退回上一步";
        }
        else if (choose==2) SignUp_Window();
        else if (choose==3) break;
        else cout << "输入错误，请重新输入";
        say_again(words);
    }

}
bool check(string name, string password) // 用户名密码对应检查
{

}

void User_Choose(User* user) // 用户选择界面
{
    string words = "1.购买商品 2.发布商品 3.查看个人信息 4.注销登陆";
    say(words);
    int choose = 0;
    cin >> choose;
    while (true)
    {
        if (choose==1) Buy_Window(user);
        else if (choose==2) Release_Window(user);
        else if (choose==3) MyDetail_Window(user);
        else if (choose==4) break;
        else cout << "输入错误，请重新输入";
        say_again(words);
    }
}
void Administrator_Model() // 管理员模式登陆界面
{

}
void Buy_Window(User* user) // 商品购买界面
{

}

void Release_Window(User* user) // 商品发布界面
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
            cout << "----请填写商品的相关信息"<<'\n' << "商品数量：";
            cin >> num;
            cout << '\n' << "商品名称：";
            cin >> name;
            cout << '\n' << "商品价格：";
            cin >> price;
            cout << '\n' << "商品详细信息：";
            cin >> detail;
            // 创建新商品
            cout<<"*********************";
            cout<<'\n'<<"请确认商品信息无误";
            cout<<"商品名称："<<name<<'\n'<<"商品价格："<<price<<'\n'<<"商品数量："<<num<<'\n'<<"商品详细信息："<<detail<<'\n';
            cout<<"若信息无误，输入y来确认此次操作，否则输入n取消此次操作：";
            char check;
            cin>>check;
            if(check=='y'){
                Goods* new_good = new Goods(num,price,name,detail,user->show_name());
                user->ReleaseGood(new_good);
                cout<<"发布成功"<<'\n';
                break;
            }
            else if(check=='n'){
                cout<<"取消发布"<<"\n";
                break;
            }
            else{
                cout<<"无效操作"<<'\n';
                break;
            }

        }
        else if(choose==2)
        {
            user->ShowMyGoods();
            cout<<cut;
            cout<<"可输入特定序号以对商品进行操作，或输入0以返回上一界面";
            int sub_choose;
            cin>>sub_choose;
            if(sub_choose==0)break;
            else if (sub_choose>user->r_num()){
                cout<<"不存在该商品，操作失败"<<'\n';
                break;
            }
            else{
                user->ShowMyGood(sub_choose);
                cout<<"请输入需要修改的属性(1.价格 2.描述)：";
                int subsub_choose;
                cin>>subsub_choose;
                if(subsub_choose!=1&&sub_choose!=2){
                    cout<<"输入错误指令！";
                    break;
                }
                cout<<"请输入修改后的值：";
                string re;
                cin>>re;
                user->ModifyGood(sub_choose,subsub_choose,re);
                cout<<"修改成功！";
                break;
            }
        }
        else if(choose==3)
        {

        }
        else if(choose==4) break;
        else cout<<"输入错误，请重新输入";
        say_again(words);
    }
}

void MyDetail_Window(User* user) // 个人信息界面
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