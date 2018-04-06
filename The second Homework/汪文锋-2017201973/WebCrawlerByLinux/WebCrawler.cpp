#include"WebCrawler.h"
#include"WebCrawlerGlobal.h"
#include"url.h"
#include"finread.h"
#include<iostream>
#include<cstring>
#include<queue>
#include<map>
#include<vector>
#include<fstream>
using namespace std;
queue<url> que;
map<string, int> mp;
vector<string> sav;
int num = 0;
int stopdownload;
string downloadir;
void bfs(string beginurl)
{
	que.push(url(beginurl,"",++num));
	while (!que.empty())
	{
		url gurl = que.front();
		que.pop();
		vector<string> v2;
		sav.swap(v2);
		mp[gurl.geturl()]++;
		ifstream fin = gurl.downloadurl();
		gurl = ioreader(fin,gurl);
		gurl.getitle();
		gurl.getotherurl(sav);
		string ord;
		if (stopdownload != -1)
		{
			if (gurl.getnumber()%stopdownload == 0)
			{
				cout << "Pause,Want to Continue?Y/N" << endl;
				cin >> ord;
				if (ord == "N")
					return;
			}
		}
		for (int i = 0; i < sav.size(); i++)
		{
			url turl = url(gurl.gethost(), sav[i], num);
			if ((sav[i].find(gurl.gethost()) != -1 || sav[i].find(findhttp) == -1) && mp[turl.geturl()] == 0)				{
				mp[turl.geturl()]++;
			que.push(url(gurl.gethost(), sav[i], ++num));
			}
		}
	}
	cout << "The project is ending , It 's craw " << num << " webs" << endl;
}
void readurl()
{
	stopdownload = -1;
	string urlname=""; 
	string readorder;
	url beginurl;
	cout << "Welcome to use WebCrawler:" << endl;
	cout << "Want to help plz input H" << endl;
	cout << "input F to use formal http=http://info.ruc.edu.cn" << endl;
	cout << "input A to use owner http" << endl;
	cout << "input Q to quit" << endl;
	cout << "input D to Crawing" << endl;
	int numx = 0;
first:
	cin >> readorder;
	if (readorder[0] == 'Q')return;
	if (readorder[0] == 'H')
	{
		cout << "input T a,when download a webs,pause and ensure continue to download" << endl;
		cout << "input M string,change download dir" << endl;
		cout << "input X to ensure Del all html" << endl;
		readorder[0] = ' ';
		goto first;
	}
	if (readorder[0] == 'F')
	{
		beginurl = url("http://info.ruc.edu.cn", "", 0);
		cout << "Now url is http://info.ruc.edu.cn" << endl;
		goto first;
	}
	if (readorder[0] == 'A')
	{
		cin >> urlname;
		beginurl = url("urlname", "", 0);
		if (beginurl.gethost().find(findhttp) < 0)
		{
			cout << "Wrong Url,plz read again" << endl;
			beginurl = url();
		}
		cout << "Now url is "<<urlname << endl;
		goto first;
	}
	if (readorder[0] == 'D')
	{
		num = 0;
		cout << (readorder[0]=='D') << endl;
		if (beginurl.gethost().find(findhttp) >= 0&& beginurl.gethost().find(findhttp)<=unsigned(-1))
			bfs(beginurl.gethost());
		else
			cout << "No url" << endl;
		goto first;
	}
	if (readorder[0] == 'X')
	{
		deldust();
		goto first;
	}
	if (readorder[0] == 'M')
	{
		cin >> urlname;
		downloadir = urlname + "/";
		urlname = "mkdir -p " + urlname;
		system(urlname.c_str());
		goto first;
	}
	if (readorder[0] == 'T')
	{
		int rd;
		cin >> rd;
		if (rd < 1 && rd>1000000)
			cout << "Out of Range" << endl;
		else
		{
			stopdownload = rd;
			cout << "When you download " << rd << " Urls,ask continue?" << endl;
		}
		goto first;
	}
	goto first;
}