#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<stdio.h>
using namespace std;

bool cmp(const char a, const char b){
    return ( (a == b) && (a == ' '));
}

vector <string> split(string s)
{
    string :: iterator sit = unique(s.begin(), s.end(), cmp);
    s.erase(sit, s.end());
    if (s[0] == ' ')
        s.erase(0, 1);
    if (*(s.end() - 2) == '.')
        s.erase(s.find(".") - 1, 1);
    cout << s;
    if (*(s.end() - 2) == '.')
        s.erase(s.find("."), 1);
    vector <string> v;
    while (s.size()) {
        v.push_back(s.substr(0, s.find(' ')));
        s.erase(0, s.find(' ') + 1);
    }
    cout << endl;
    return v;
}
string uniq(vector <string> v)
{
	string str;
	vector <string> :: iterator it;
	it = v.begin();
    while (it != v.end()){
        if (*it == *(v.end() - 1))
            v.erase(it);
            else
                it++;
    }
    for ( it = v.begin(); it != v.end(); it++)
        str+=*it+=" ";
    return str;
}

string samelit(vector <string> v)
{
	string str, tmp;
	vector <string> :: iterator it;
    it = v.begin();
    while (it != v.end()){
        if (*it == *(v.end() - 1))
            v.erase(it);
            else
                it++;
    }
	for ( it = v.begin(); it != v.end(); it++){
        tmp=*(it);
        tmp.erase(tmp.end()-1);
        str+=tmp+=" ";
    }
    return str;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    vector <string> v_str;
    cout<<"Программа делает следующие действия"<<endl<<"1)Удаляет лишние пробелы."<<endl<<"2)Печатает слова этой строки, не совпадающие с последним словом"<<endl<< "3)Удалив последнюю букву слов, печатает эти слова."<<endl;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    getline(cin, str);
    str.push_back(' ');
    cout <<"1)";
    v_str = split(str);
    cout <<"2)";
    cout<<uniq(v_str);
    cout << endl;
    cout <<"3)";
    cout<<samelit(v_str);
    cout <<endl;
    return 0;
}
