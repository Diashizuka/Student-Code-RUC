#ifndef finread_2017201973
#define finread_2017201973
#include<string>
#include<string.h>
#include<fstream>
#include"url.h"
using std::string;
using std::fstream;
url ioreader(ifstream &fin,url url_);//读取文件
void deldust();//删除所有html文件
#endif