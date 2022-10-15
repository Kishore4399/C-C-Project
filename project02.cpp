#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
 
double calcul(string expression)  // 用于简单的加减乘除计算
{
	string::size_type pos;
	string::size_type lastPos;
	string::size_type fristPos;
 
	string snum2;

	while ((pos = expression.find_first_of("/*")) != string::npos)  // 判断是否含有乘除法
	{
		if ((lastPos = expression.find_last_of("+-", pos)) != string::npos || (fristPos = expression.find_first_of("+-", pos)) != string::npos)
		{
			if (lastPos == string::npos && fristPos != string::npos)
			{
				string snum1 = expression.substr(0, pos);   // 乘除法之前的表达式
				string snum2 = expression.substr(pos + 1, fristPos - pos);   // 乘除法之后的表达式
				double num1 = std::stod(snum1);
				double num2 = std::stod(snum2);
				if (expression[pos] == '*')
				{
					double res = (1.0f) * num1 * num2;
					string sres = std::to_string(res);
					expression.replace(0, fristPos - 0, sres);
					continue;
				}
				else
				{
					double res = num1 / ((1.0f)*num2);
					string sres = std::to_string(res);
					expression.replace(0, fristPos - 0, sres);
					continue;
				}
 
			}
 
			if ((fristPos = expression.find_first_of("+-", pos + 1)) == string::npos && (lastPos = expression.find_last_of("+-", pos - 1)) != string::npos)
			{
				string snum1 = expression.substr(lastPos + 1, pos);
				string snum2 = expression.substr(pos + 1, expression.size() - pos);
				double num1 = std::stod(snum1);
				double num2 = std::stod(snum2);
				if (expression[pos] == '*')
				{
					double res = (1.0f) * num1 * num2;
					string sres = std::to_string(res);
					expression.replace(lastPos + 1, expression.size() - lastPos, sres);
					continue;
				}
				else
				{
					double res = num1 / ((1.0f)*num2);
					string sres = std::to_string(res);
					expression.replace(lastPos + 1, expression.size() - lastPos, sres);
					continue;
				}
 
			}
			else
			{
				string snum1 = expression.substr(lastPos + 1, pos);
				string snum2 = expression.substr(pos + 1, fristPos - pos);
				double num1 = std::stod(snum1);
				double num2 = std::stod(snum2);
				if (expression[pos] == '*')
				{
					double res = num1 * (1.0f)* num2;
					string sres = std::to_string(res);
					expression.replace(lastPos + 1, fristPos - lastPos - 1, sres);
				}
				else
				{
					double res = num1 / ((1.0f)*num2);
					string sres = std::to_string(res);
					expression.replace(lastPos + 1, fristPos - lastPos - 1, sres);
				}
			}
 
 
		}
		else
		{
			if ((fristPos = expression.find_first_of("*/", pos + 1)) != string::npos) // 当乘除号后面还有乘除号时
			{
				string snum1 = expression.substr(0, pos);
				string snum2 = expression.substr(pos + 1, fristPos - pos);
				double num1 = std::stod(snum1);
				double num2 = std::stod(snum2);
				if (expression[pos] == '*')
				{
					double res = num1 * (1.0f)*num2;
					string sres = std::to_string(res);
					expression.replace(0, fristPos - 0, sres);
					continue;
				}
				else
				{
					double res = (1.0f)*num1 / num2;
					string sres = std::to_string(res);
					expression.replace(0, fristPos - 01, sres);
					continue;
				}
			}
			else // 当乘除号后面还有乘除号时
			{
				string snum1 = expression.substr(0, pos);
				string snum2 = expression.substr(pos + 1, expression.size() - pos);
				double num1 = std::stod(snum1);
				double num2 = std::stod(snum2);
				if (expression[pos] == '*')
				{
					double res = (1.0f)*num1 * num2;
					string sres = std::to_string(res);
					expression.replace(0, expression.size() - 0, sres);
					continue;
				}
				else
				{
					double res = (1.0f)*num1 / num2;
					string sres = std::to_string(res);
					expression.replace(0, expression.size() - 0, sres);
					continue;
				}
			}
 
		}
 
	}
 
	while ((pos = expression.find_first_of("+-")) != string::npos)
	{
		if ((fristPos = expression.find_first_of("+-", pos + 1)) != string::npos)
		{
			string snum1 = expression.substr(0, pos);
			string snum2 = expression.substr(pos + 1, fristPos - pos);
			double num1 = std::stod(snum1);
			double num2 = std::stod(snum2);
			if (expression[pos] == '+')
			{
				double res = (1.0f)*num1 + (1.0f)*num2;
				string sres = std::to_string(res);
				expression.replace(0, fristPos - 1, sres);
			}
			else
			{
				double res = (1.0f)*num1 - (1.0f)*num2;
				string sres = std::to_string(res);
				expression.replace(0, fristPos - 1, sres);
			}
		}
		else
		{
			string snum1 = expression.substr(0, pos);
			string snum2 = expression.substr(pos + 1, expression.size() - pos);
			double num1 = std::stod(snum1);
			double num2 = std::stod(snum2);
			if (expression[pos] == '+')
			{
				double res = (1.0f)*num1 + (1.0f)*num2;
				string sres = std::to_string(res);
				expression.replace(0, expression.size() - 0, sres);
			}
			else
			{
				double res = (1.0f)*num1 - (1.0f)*num2;
				string sres = std::to_string(res);
				expression.replace(0, expression.size() - 0, sres);
			}
		}
	}
	double fin = std::stod(expression);
	return fin;
}
 

 
double result(string expression)
{
	string schar;
    while (expression.find_first_of("()") != string::npos)
    {
        for (int i = 0; i != expression.size(); ++i)
	    {
            if (expression[i] != ')')
            {
                schar = schar + expression[i];
            }
            else
            {
                string::size_type left_pos = i;    // 用来定位"("
                string rchild;
                while (schar[schar.size()-1] != '(')
                {
                    left_pos -= 1;
                    rchild = schar[schar.size()-1] + rchild;
                    schar.erase(schar.size()-1);  
                }
                left_pos -= 1;
                schar = "";   // 去除"("
                double number = calcul(rchild);
                string snum = std::to_string(number);
                // 将括号里面的数计算过后替代输入的string对应的括号里的内容
                expression.replace(left_pos, (i+1)-left_pos, snum);
                break;
            }
        }
    }
    double final_result = calcul(expression);
    return final_result;
 
}

int main()
{
    cout<<"Please give us an expression:"<<endl;

    char ch[50];
    cin.getline(ch, 50);
    string str = ch;
    // 第三题 一些数学公式
    if (str.find("sqrt")!=string::npos){
        int pos_left = str.find_first_of('(');
        int pos_right = str.find_last_of(')');
        string str_out = str.substr(pos_left+1, pos_right-pos_left-1);
        cout<<sqrt(result(str_out))<<endl;
        return 0;
    }

    if (str.find("pow")!=string::npos){
        int pos_left = str.find_first_of('(');
        int pos_right = str.find_last_of(')');
        int pos_middle = str.find(',');
        string str_out = str.substr(pos_left+1, pos_right-pos_left-1);
        double number1 = result(str.substr(pos_left+1, pos_middle-pos_left-1));
        double number2 = result(str.substr(pos_middle+1, pos_right-pos_middle-1));
        cout<<pow(number1, number2)<<endl;
        return 0;
    }
 
    // 第三题 支持输入变量等式
    string::size_type pos_input;
    string var01;
    string var01_value;
    string var02;
    string var02_value;
    if((pos_input = str.find("=")) != string::npos){
        var01=str.substr(0,pos_input);
        var01_value = str.substr(pos_input+1);

        char ch02[50];
        cin.getline(ch02, 50);
        string str02 = ch02;
        var02=str02.substr(0,pos_input);
        var02_value = str02.substr(pos_input+1);

        char ch03[50];
        cin.getline(ch03, 50);
        string str03 = ch03;
        int pos_var01 = str03.find(var01);
        int pos_var02 = str03.find(var02);
        while (pos_var01!= string::npos){
            str03.replace(pos_var01, 1, var01_value);
            pos_var01 = str03.find(var01);
        }
        
        while (pos_var02 != string::npos){
            str03.replace(pos_var02, 1, var02_value);
            pos_var02 = str03.find(var02);
        }
        str = str03;
    };
    //强制使用小数,防止使用科学计数法
    cout << fixed;
    //控制显示的精度，控制小数点后面的位数。而整数太大时也会使用科学计数法，要输出完整的整数时就可以将下面改成setprecision(0)
    cout << setprecision(7);
    cout << result(str) << endl;
return 0;
}