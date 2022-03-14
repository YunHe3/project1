#include "iostream"
#include "data_structure.h"
#include "calculator.h"
#include "ctime"
int Goods::total_num = 1;
int User::user_num = 1;
int Transaction::tran_num=1;
string what_time()
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    string time_now;
    time_now = to_string(1900+ltm->tm_year)+"-"+ to_string(1+ltm->tm_mon)+"-"+ to_string(ltm->tm_mday);
    return time_now;
}
string out_space(int n)
{
    string space;
    for(int i = 0; i < n; i++) space += ' ';
    return space;
}
int float_len(float num)
{
    int len = 1;
    while(num>1)
    {
        num = num/10;
        len++;
    }
    return len;
}
void Transaction::ShowInformation(char ch) {
    cout<<this->gid<<out_space(5-this->gid.length())
    <<this->tid<<out_space(5-this->tid.length())
    <<this->price<<out_space(8- float_len(this->price))
    <<this->num<<out_space(3-num/10)
    <<this->transaction_time<<out_space(14);
    if(ch=='s')cout<<this->uid_b;
    else cout<<this->uid_s;

}

string Transaction::seller() {
    return this->uid_s;
}
string Transaction::buyer() {
    return this->uid_b;
}
Transaction::Transaction(string uid_s, string uid_b, string gid, float price, int num) {
        tid = 'T'+ to_string(tran_num++);
        this->gid = gid;
        this->price = price;
        this->uid_b = uid_b;
        this->uid_s = uid_s;
        this->like = 0;
        this->num = num;
        this->transaction_time = what_time();
}
User::User(string na, string pw, string pn, string lo) {
        name = na;
        password = pw;
        phone_number = pn;
        locate = lo;
        uid = 'U'+ to_string(user_num++);
        banned = false;
        r_goods = 0;
        b_goods = 0;
        t_num = 0;
}
void User::SignUp()
{

}
void User::LogOut()
{

}
void User::Modify()
{

}
void User::ReleaseGood(Goods *g) {
    this->my_good[this->r_goods++] = g;

}
void User::SellGood(Goods *g, int num) {
    this->money -= g->unit_price()*num;
}
void User::BuyGood(Goods *g, int num) {
    this->money += g->unit_price()*num;
}
string User::show_name() {
    return this->name;
}
string User::show_password() {
    return this->password;
}
int User::TranNum() {
    return this->t_num;
}
Transaction* User::MyTransaction(int num) {
    return this->my_transaction[num];
}
int User::r_num() {return this->r_goods;}
void User::ShowMyGoods() {
    std::cout<<"   "<<"Good name"<<"      "<<"Price"<<"   "<<"Stock"<<" "<<"Likes"<<" "<<"Good State";
    for(int i = 1;i<=this->r_goods;i++){
        cout<<i<<out_space(2-i/10);
        my_good[i-1]->ShowInformation();
        cout<<'\n';
    }
}
void User::ModifyGood(int num,int choose,string re) {
    Goods*p = this->my_good[num];
    if(choose==1){
        p->Modify(trans_F(re));
    }
    else p->Modify(re);
}
void User::ShowMyGood(int num) {
    Goods*p = this->my_good[num];
    p->ShowDetail();
}
void User::RemoveGoods(int num) {
    this->my_good[num]->S_Remove();
}
void User::ShowMyTransactionS() {
    cout<<"Tid  Gid  Price  num  Time          Buyer\n";
    for(int i = 1;i<=this->t_num;i++){
        cout<<i<<' ';
        my_transaction[i-1]->ShowInformation('s');
        cout<<'\n';
    }
}
string Transaction::orderID() {
    return this->tid;
}
Goods::Goods(int num, float price, string name, string detail, string release_id)
{
    this->num = num;
    this->name = name;
    this->detail = detail;
    this->release_id = release_id;
    this->price = price;
    status = 1;
    likes_count = 0;
    re_time = what_time();
    if(total_num>=10) gid = 'M' + to_string(total_num++);
    else gid = "M0" + to_string(total_num++);
}
int Goods::state() {
    return this->status;
}
string Goods::id(){
    return this->gid;
}
int Goods::stock() {
    return this->num;
}
void User::AddOrder(Transaction *t) {
    this->my_transaction[this->t_num++] = t;
}
void Goods::Sold(User* buyer, User* seller,int num) {
    buyer->BuyGood(this,num);
    seller->SellGood(this,num);
    this->num -= num;
    Transaction* new_t;
    *new_t = Transaction(seller->show_name(),buyer->show_name(),this->gid,this->price,num);
    buyer->AddOrder(new_t);
    seller->AddOrder(new_t);
}
void Goods::ShowInformation() {
    string sta;
    if (this->status==1) sta = "on sale";
    else if(this->status==0) sta = "been remove";
    else sta = "off the shelve";
    std::cout<<this->name<<out_space(12-this->name.length())
    <<this->price<<out_space(8- float_len(this->price))
    <<this->num<<out_space(6-to_string(this->num).length())
    <<this->likes_count<<out_space(6- to_string(this->likes_count).length())
    <<sta;
}
string Goods::seller() {
    return this->release_id;
}
float Goods::unit_price() {
    return this->price;
}
void Goods::ShowInformationB() {
    std::cout<<this->gid<<out_space(10)
    <<this->name<<out_space(15-this->name.length())
    <<this->price<<out_space(8- float_len(this->price))
    <<this->re_time<<" "
    <<this->release_id;
}
void Goods::ShowDetail() {
    std::cout<<"gid£º"<<this->gid<<'\n'
             <<"Good name£º"<<this->name<<'\n'
             <<"Price£º"<<this->price<<'\n'
             <<"Good num£º"<<this->num<<'\n'
             <<"Likes£º"<<this->likes_count<<'\n'
             <<"Detail£º"<<this->detail<<'\n';
}
void Goods::Modify(string re) {
    this->detail = re;
}
void Goods::Modify(float price) {
    this->price = price;
}
void Goods::S_Remove() {
    this->status = -1;
}