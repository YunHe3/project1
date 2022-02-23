#include <map>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int pri(char ch) // 优先级判断
{
	if (ch == '+' || ch == '-') return 2;
	else return 1;
}
float trans_F(string s) // 字符串转浮点数
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
string trans_S(string s) // 字符串形式浮点数，保留一位小数
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '.') return s.substr(0, i+2);
	}
	return s;
}
float cal_tool(float num1, float num2, char ch) // 微型计算单元
{
	if (ch == '+')return num1 + num2;
	if (ch == '-')return num1 - num2;
	if (ch == '/')return num1 / num2;
	if (ch == '*')return num1 * num2;
}
string check(string expression) // 圆括号检查
{
	int count = 0;
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '(')count++;
		else if (expression[i] == ')')count--;
	}
	if (count == 0)
	{
		return expression + "#";
	}
	return "False";
}
string trans_RPN(string expression) // 中缀转后缀
{
	string ans = "";
	stack<char>  p;
	int index = 0;
	char ch = expression[index];
	do {
		index++;
		if (ch <= '9' && ch >= '0' || ch == '.') ans += ch; // 操作数或小数点
		else if (ch == '(') p.push('('); // 左括号
		else if (ch == ')') // 右括号
		{
			while (p.top() != '(')
			{
				ans += p.top();
				p.pop();
			}
			p.pop();
		}
		else // 运算符
		{
			ans += " ";
			while (true)
			{
				if (p.empty() || p.top() == '(' || pri(ch) < pri(p.top()))
				{
					p.push(ch);
					break;
				}
				else
				{
					ans += p.top();
					p.pop();
				}
			}
		}
		ch = expression[index];
	} while (ch != '#');
	while (!p.empty()) {
		ans += p.top();
		p.pop();
	}
	ans += "#";
	return ans;
}
string calculator(string expression)
{
	stack<float> num; // 数字栈
	int index = 0;
	string nums = "";
	char next_ch = ' ';
	char ch = expression[index];
	do 
	{
		index++;
		if (ch <= '9' && ch >= '0' || ch=='.') // 判断为数字
		{
			nums = "";
			if (ch == '.')nums = "0.";
			nums += ch;
			next_ch = expression[index];
			while (next_ch == '.' || next_ch >= '0' && next_ch <= '9')
			{
				ch = expression[index++];
				nums += ch;
				next_ch = expression[index];
			}
			num.push(trans_F(nums));
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			float num1 = 0;
			float num2 = 0;
			num2 = num.top();
			num.pop();
			if (num.empty()) // 参数缺少情况
			{
				if (ch == '-')
				{
					num1 = 0;
				}
				else return "运算符误用";
			}
			num1 = num.top();
			num.pop();
			if (ch == '/' && num2 == 0) return "除零错误";
			num.push(cal_tool(num1,num2,ch));
		}
		ch = expression[index];
	} while (ch!='#');
	float ans = num.top();
	num.pop();
	if (num.empty())return trans_S(to_string(ans));
	else return "操作符误用";
}
string solve(string expression) // 对外接口
{
	string s = check(expression);
	if (s=="False")return "圆括号匹配错误";
	else return calculator(trans_RPN(s));
}
/*
string calculator(string expression) // 后缀形式表达式求值
{
	// 该函数需修改，目前思路是写一个拆分函数，一个处理函数
	float num1 = 0;
	float num2 = 0;
	int index = 0;
	bool flag = true; // 标记表达式是否合法
	string wrong = ""; // 非法信息
	char ch = expression[index];
	if (ch <= '9' && ch >= '0') // 遇到第一个数字，记入num1
	{
		float num1 = ch - '0';
		int num = 0;
		char next_ch = expression[++index];
		while (next_ch != ' ' && next_ch != '#') // 直到下一个数字
		{
			if (next_ch == '.') // 判定下一个是小数点，此数字是浮点数
			{
				num = expression[++index] - '0';
				num1 += num / 10.0;
				break;
			}
			else if (next_ch <= '9' && next_ch >= '0')
			{
				num = next_ch - '0';
				num1 = num1 * 10 + num;
			}
			next_ch = expression[index++];
		}
	}
	while (expression[index] == ' ')index++;
	ch = expression[index];
	while (ch != '#') // 主循环
	{
		index++;
		if (ch == '-') num1 = -num1;
		else if (ch <= '9' && ch >= '0')
		{
			float num2 = ch - '0';
			int num = 0;
			char next_ch = expression[index++];
			while (next_ch != ' ' && next_ch != '#') // 直到下一个数字
			{
				num = next_ch - '0';
				if (next_ch == '.') // 判定下一个是小数点，此数字是浮点数
				{
					num2 += num / 10.0;
				}
				else if (next_ch <= '9' && next_ch >= '0')
				{
					num2 = num2 * 10 + num;
				}
				next_ch = expression[index++];
			}
		}
		else
		{
			flag = false;
			wrong = "操作符使用错误";
			break;
		}
		while (expression[index] == ' ')index++;
		if (ch == '-') num1 -= num2;
		else if (ch == '+') num1 += num2;
		else if (ch == '/')
		{
			if (num2 == 0)
			{
				flag = false;
				wrong = "除零错误";
				break;
			}
			else num1 /= num2;
		}
		else if (ch == '*') num1 *= num2;
		ch = expression[index];
	}
	if (!flag) return wrong;
	return to_string(num1);
}
*/
