#include<string>
#include <fstream>
#include<string.h>
#include<iostream>
#include"url.h"
using namespace std;
const int clen = 8192;
url ioreader(ifstream &fin,url url_)
{
	char iochar[clen];
	string iostring;
	while (fin.getline(iochar, clen))
	{
		iostring = iostring + string(iochar);
		strcpy(iochar, "");
	}
	url_.changehtml(iostring);
	return url_;
}
void deldust()
{	
	char dl;
	cout << "Want to Del html?Y/N" << endl;
	cin >> dl;
	if (dl == 'Y')
	{
		cout << "Del .html ing...\n";
		system("rm *.html");
	}
}