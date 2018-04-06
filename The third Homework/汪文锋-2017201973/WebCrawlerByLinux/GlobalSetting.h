#ifndef WebCrawlerGlobal_2017201973
#define WebCrawlerGlobal_2017201973
#include<string>
using std::string;
class GlobalSetting
{
	public:
		string findhref;
		int hreflen;
		string findhttp;
		int httplen;
		string findtitle;
		int titlelen;
		string finduntitle;
		int untitlelen;
		WebCrawlerGlobal();
};
#endif