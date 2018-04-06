#include"url.h"
#include"WebCrawlerGlobal.h"
#include<string>
#include <stdarg.h>
#include<iostream>
#include<vector>
using namespace std;
extern string downloadir;
url::url()
{
	host = "";
	urlname = "";
	allhtml = "";
	number = 0;
}
url::url(string host_, string url_,int id)
{
	host = host_;
	urlname = url_;
	allhtml = "";
	number = id;
	if (urlname.find(findhttp) == -1)
		urlname = host_ + "/" + urlname;
}
string url::gethost()
{
	return host;
}
string url::geturl()
{
	return urlname;
}
int url::getnumber()
{
	return number;
}
void url::changehtml(string strhtml)
{
	allhtml = strhtml;
	return;
}
ifstream url::downloadurl()
{	
	string dict("wget -q -O ");
	cout << "No:" << number << " - " << "Downloading " << urlname << "...\n";
	dict = dict + downloadir + to_string(number) + ".html" + " " + urlname;
	string reads = downloadir + to_string(number) + ".html";
	system(dict.c_str());
	ifstream fin(reads.c_str());
	return fin;
}
void url::getitle()
{
	string stringhtml = allhtml;
	ofstream ChangeInfo("ChangeInfo");
	int str_len = stringhtml.length();
	for (int i = 0; i < str_len; i++)
	{
		if (stringhtml.substr(i, findtitle.length()) == findtitle)
		{
			i += findtitle.length();
			
			for (int j = i; j<str_len; j++)
				if (stringhtml.substr(j, finduntitle.length()) == finduntitle)
				{
					string urltitle = stringhtml.substr(i, j - i) + to_string(number) + ".html";
					int findel = urltitle.find(deltitle);
					while (findel >= 0)
					{
						urltitle.erase(findel, 1);
						findel = urltitle.find(deltitle);
					}
					findel = urltitle.find(deltitle2);
					while (findel >= 0)
					{
						urltitle.erase(findel, 1);
						findel = urltitle.find(deltitle2);
					}
					string urlins = "mv " + downloadir + to_string(number) + ".html " + downloadir + urltitle;
					ChangeInfo << urltitle << endl;
					system(urlins.c_str());
					i = str_len; break;
				}
		}
	}
}
void url::getotherurl(vector<string> &vec)
{
	string stringhtml = string(allhtml);
	ofstream htmlfind("Debug");
	int str_len = stringhtml.length();
	for (int i = 0; i < str_len; i++)
	{
		if (stringhtml.substr(i, findhref.length()) == findhref)
		{
			i += findhref.length()+1;
			for (int j = i; j<str_len; j++)
				if (stringhtml.substr(j, 1) == findright)
				{
					string urlfrom = stringhtml.substr(i, j - i);
					vec.push_back(urlfrom);
					htmlfind << urlfrom << endl;
					i = j; break;
				}
		}
	}
}