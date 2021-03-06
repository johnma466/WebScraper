#include <iostream>
#include "scraper.h"

using namespace std;
static bool forever = true;


int main(int argc, char *argv[])
{
    char ch;
    unordered_map<std::string, WebTitle> webSites;
    const char * attrTime[] = { "class",
                  "cluster"};

    const char * attrEspn[] = { "class",
                  "contentItem__titleWrapper"};

    const char * attrFoxNews[] = { "class",
                  "content" };

    const char * attrNBCNews[] = { "class",
                  "info___1Xmsp pt5 pt0 ph5 pl4-m"};

    webSites.insert({
                        {"www.time.mk", WebTitle(  std::string("div") , attrTime )},
                         {"www.espn.com", WebTitle(  std::string("div"), attrEspn )},
                         {"www.foxnews.com", WebTitle(  std::string("div"), attrFoxNews )},
                         {"www.nbcnews.com", WebTitle(  std::string("div"), attrNBCNews )}
                    }
    );

    Scraper sc(webSites);

    while (forever) {

        cerr << "press e to exit ===>";
        cin >> ch;

        switch (ch) {
            case 's':
                sc.startScraping();
            break;

            case 'h':
            {
                string webSite;
                cin >> webSite;
                try {
                      cerr << "WebSite: " << webSite  << "\nHeadLine news => " << sc.getHeadline(webSite) << endl;
                } catch (out_of_range &e) {
                    cerr << e.what() << endl;
                }
            }
            break;

            case 'e':
                forever = false;
                break;
        }
    }

    return 0;
}
