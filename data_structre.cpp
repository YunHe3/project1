#include "iostream"
#include "data_structure.h"
int Goods::total_num = 1;
int User::user_num = 1;
int Transaction::tran_num=1;
float trans_F(string s) // �ַ���ת������
{
    float ans = 0;
    int len = s.length();
    int index = 0;
    while (index < len)
    {
        if (s[index] == '.')
        {
            ans += (s[index + 1] - '0') / 10.0;
            return ans;
        }
        else ans = ans * 10 + (s[index]-'0');
        index++;
    }
    return ans;
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
    this->mygood[this->r_goods++] = g;
}
string User::show_name() {
    return this->name;
}
int User::r_num() {return this->r_goods;}
void User::ShowMyGoods() {
    std::cout<<"���"<<" "<<"��Ʒ����"<<"      "<<"�۸�"<<"   "<<"���"<<" "<<"���빺�ﳵ����"<<" "<<"��Ʒ״̬";
    for(int i = 1;i<=this->r_goods;i++){
        cout<<i<<' ';
        mygood[i-1]->ShowInformation();
        cout<<'\n';
    }
}
void User::ModifyGood(int num,int choose,string re) {
    Goods*p = this->mygood[num];
    if(choose==1){
        p->Modify(trans_F(re));
    }
    else p->Modify(re);
}
void User::ShowMyGood(int num) {
    Goods*p = this->mygood[num];
    p->ShowDetail();
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
void Goods::ShowInformation() {
    string sta;
    if (this->status==1) sta = "����";
    else if(this->status==0) sta = "�Ƴ�";
    else sta = "�¼�";
    std::cout<<this->name<<out_space(10-this->name.length())
    <<this->price<<out_space(5- float_len(this->price))
    <<this->num<<out_space(3-to_string(this->num).length())
    <<this->likes_count<<out_space(8- to_string(this->likes_count).length())
    <<sta;
}
void Goods::ShowDetail() {
    std::cout<<"���кţ�"<<this->gid<<'\n'
             <<"��Ʒ���ƣ�"<<this->name<<'\n'
             <<"��Ʒ�۸�"<<this->price<<'\n'
             <<"��Ʒ������"<<this->num<<'\n'
             <<"��Ʒ�����빺�ﳵ������"<<this->likes_count<<'\n'
             <<"��Ʒ������"<<this->detail<<'\n';
}
void Goods::Modify(string re) {
    this->detail = re;
}
void Goods::Modify(float price) {
    this->price = price;
}