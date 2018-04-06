#ifndef WebCrawlerGlobal_2017201973
#define WebCrawlerGlobal_2017201973
#include<string>
using std::string;
static string findhref("<a href=");
static string findhttp("http://");
static string findtitle("<title>");
static string finduntitle("</title>");
static string deltitle("-");
static string deltitle2(" ");
static string findright("\"");
extern int stopdownload;
extern string downloadir;
#endif