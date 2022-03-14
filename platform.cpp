#include<iostream>
#include "platform.h"
#include <map>

using namespace std;

map<string,User*> user_name; // 用户名与对象构建map
map<string,Goods*> good_name;
string what_time();
void pre_load() // 加载数据
{
    user_name.clear();
    good_name.clear();

}
bool find(string s, string aim) // 搜索
{
    if(s.find(aim)>s.length())return false;
    else return true;
}
string cut = "======================================================================================================";
void say(string words)
{
    cout << cut << '\n';
    cout << words << '\n';
    cout << cut << '\n';
    cout << "Enter your option:";
}
void say_again(string words)
{
    cout << '\n'<<'\n'<<'\n'<<'\n';
    cout << cut << '\n';
    cout << words << '\n';
    cout << cut << '\n';
    cout << "Enter your option:";
}
void Login_Window() // 主界面
{
    string words = "1.Administrator login 2.User login 3.exit";
    say(words);
    int choose = 0;
    cin >> choose;
    while (true) {
        if (choose == 1) Administrator_Model();
        else if (choose == 2) User_Model();
        else if (choose == 3) break;
        else cout << "Wrong input";
        say_again(words);
        cin >> choose;
    }
}

void SignUp_Window() // 注册界面
{

}

void User_Model() // 用户模式登陆界面
{
    string words = "1.Login 2.Register";
    say(words);
    int choose = 0;
    cin >> choose;
    while (true)
    {
        if (choose==1)
        {
            string name;
            string password;
            cout << "Enter your name:";
            cin >> name;
            cout << '\n';
            cout << "Enter your password:";
            cin >> password;
            if (check(name,password))
            {
                cout << "-----Succeed-----"<<'\n';
                User_Choose(user_name[name]);
            }
            else cout << "Wrong name or password";
        }
        else if (choose==2) SignUp_Window();
        else if (choose==3) break;
        else cout << "Wrong input";
        say_again(words);
    }

}
bool check(string name, string password) // 用户名密码对应检查
{
    if(user_name[name]){
        if(user_name[name]->show_password()==password)return true;
    }
    return false;
}

void User_Choose(User* user) // 用户选择界面
{
    string words = "1.Buy Goods 2.Release Goods 3.My information 4.Log out";
    say(words);
    int choose = 0;
    cin >> choose;
    while (true)
    {
        if (choose==1) Buy_Window(user);
        else if (choose==2) Release_Window(user);
        else if (choose==3) MyDetail_Window(user);
        else if (choose==4) break;
        else cout << "Wrong input";
        say_again(words);
    }
}
void Administrator_Model() // 管理员模式登陆界面
{

}
void Buy_Window(User* user) // 商品购买界面
{
    string words = "1.Goods list 2.Find Goods 3.My Transaction 4.Back";
    say(words);
    int choose = 0;
    cin>>choose;
    while(true)
    {
        if (choose==1) {
            cout<<"commodityID  commodityName  price  addedDate  sellerID";
            for(auto it = good_name.begin();it != good_name.end();it++){
                if(it->second->state()==1){
                    it->second->ShowInformationB();
                    cout<<'\n';
                }
            }
            cout<<cut<<'\n';
            cout<<"Enter the commodityID to Buy(or enter 0 to go back):";
            string sub_choose;
            cin>>sub_choose;
            if(sub_choose=="0") break;
            cout<<"\nEnter the amount you want to buy:";
            int buy_num;
            cin>>buy_num;
            cout<<'\n'<<cut<<'\n';
            auto it = good_name.begin();
            while(it != good_name.end()){
                if(it->second->id()==sub_choose){
                    if(it->second->stock()>buy_num){
                        it->second->Sold(user,user_name[it->second->seller()],buy_num);
                        cout<<"Success!\n";
                        cout<<"Order time:"<<what_time();
                        cout<<"\nUnit price:"<<it->second->unit_price();
                        cout<<"\nAmount:"<<buy_num;
                        cout<<"\nYour balance:";
                        user->ShowMyMoney();
                        cout<<'\n';
                        break;
                    }
                    else{
                        cout<<"Not enough";
                        break;
                    }
                }
                else{
                    cout<<"Can't find this good";
                    break;
                }
                it++;
            }
        }
        else if(choose==2){
            cout<<"Enter what you want to find:\n";
            string aim;
            cin>>aim;
            cout<<"commodityID  commodityName  price  addedDate  sellerID";
            for(auto it = good_name.begin();it != good_name.end();it++){
                if(find(it->first,aim)){
                    it->second->ShowInformationB();
                    cout<<'\n';
                }
            }
        }
        else if(choose==3){
            cout<<"orderID  commodityID  unitPrice  number  date  sellerID";
            int num = user->TranNum();
            for(int i = 0;i<num;i++){
                if(user->MyTransaction(i)->buyer()==user->show_name()){
                    user->MyTransaction(i)->ShowInformation('b');
                }
            }
        }
        else if(choose==4){
            break;
        }
        else cout<<"Wrong input";
        say_again(words);
    }

}

void Release_Window(User* user) // 商品发布界面
{
    string words = "1.Release  2.My Goods 3.My Transaction 4.Back";
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
            cout << "----Enter Good's information----"<<'\n' << "Goods amount:";
            cin >> num;
            cout << '\n' << "Goods name:";
            cin >> name;
            cout << '\n' << "Goods price:";
            cin >> price;
            cout << '\n' << "Goods' details";
            cin >> detail;
            // 创建新商品
            cout<<"*********************";
            cout<<'\n'<<"please confirm these information";
            cout<<"Goods name:"<<name<<'\n'<<"Goods price"<<price<<'\n'<<"Goods amount:"<<num<<'\n'<<"Goods' detail:"<<detail<<'\n';
            cout<<"your choice(y/n):";
            char check;
            cin>>check;
            if(check=='y'){
                Goods* new_good = new Goods(num,price,name,detail,user->show_name());
                user->ReleaseGood(new_good);
                cout<<"Success"<<'\n';
                break;
            }
            else if(check=='n'){
                cout<<"Cancel"<<"\n";
                break;
            }
            else{
                cout<<"Wrong input"<<'\n';
                break;
            }

        }
        else if(choose==2)
        {
            user->ShowMyGoods();
            cout<<cut;
            cout<<"enter a number for more details, or enter 0 to go back";
            int sub_choose;
            cin>>sub_choose;
            if(sub_choose==0)break;
            else if (sub_choose>user->r_num()){
                cout<<"wrong input"<<'\n';
                break;
            }
            else{
                user->ShowMyGood(sub_choose);
                cout<<"Enter your what you want to modify or enter -1 to remove this good or enter anything else to quit(1.price 2.detail)：";
                int subsub_choose;
                cin>>subsub_choose;
                if(subsub_choose==-1){
                    user->RemoveGoods(sub_choose);
                }
                if(subsub_choose!=1&&sub_choose!=2){
                    cout<<"Back";
                    break;
                }
                cout<<"Please enter the replace information:";
                string re;
                cin>>re;
                user->ModifyGood(sub_choose,subsub_choose,re);
                cout<<"Success";
                break;
            }
        }
        else if(choose==3)
        {
            user->ShowMyTransactionS();
        }
        else if(choose==4) break;
        else cout<<"Wrong input";
        say_again(words);
    }
}

void MyDetail_Window(User* user) // 个人信息界面
{
    string words = "1.My information  2.Modify information  3.Charge  4.Back";
    say(words);
    int choose;
    cin>>choose;
    while(true){
        if (choose==1){

        }
        else if(choose==2){

        }
        else if(choose==3){

        }
        else if(choose==4){
            break;
        }
        else cout<<"Wrong input";
        say_again(words);
    }
}
void ShowUser_Window() // 用户管理界面
{

}
void ShowTransaction_Window() // 订单管理界面
{

}