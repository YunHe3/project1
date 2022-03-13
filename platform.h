#pragma once
#include <iostream>
#include <string>
#include "data_structure.h"
void Login_Window();
void SignUp_Window();
void User_Model();
void Administrator_Model();
void Buy_Window(User*);
void Release_Window(User*);
void MyDetail_Window(User*);
void GoodsDetailS_Window();
void GoodsDetailB_Window();
void GoodsDetailA_Window();
void ShowUser_Window();
void ShowTransaction_Window();
void User_Choose(User*);
bool check(std::string name,std::string password);