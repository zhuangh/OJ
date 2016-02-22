#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <set>
#include <vector>

#include <curl/curl.h>
#include <htmlcxx/html/ParserDom.h>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace htmlcxx;
using namespace boost::algorithm;

size_t write_to_string(void *ptr, size_t size, size_t count, void *stream) {
    ((string*)stream)->append((char*)ptr, 0, size*count);
    return size*count;
}

class Page {
public:
    string url;
    string body;

    Page (string url, string body) {
	this->url = url;
	this->body = body;
    }

    set<string> getUniqWords() {
	set<string> uniqueWords;
	vector<string> allWords;
	split(allWords, body, is_space());
	vector<string>::iterator it = allWords.begin();
	vector<string>::iterator end = allWords.end();
	for(; it != end; ++it) {
	    uniqueWords.insert(*it);
	}
	return uniqueWords;
    }

    int countUniqWords() {
	return getUniqWords().size();
    }
};

string getPageContent(string url) {
    string content = "";
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);
	res = curl_easy_perform(curl);

	curl_easy_cleanup(curl);
    }
    return content;
}

set<string> getLinks(string html) {
    set<string> links;

    HTML::ParserDom parser;
    tree<HTML::Node> dom = parser.parseTree(html);

    tree<HTML::Node>::iterator it = dom.begin();
    tree<HTML::Node>::iterator end = dom.end();

    for (; it != end; ++it) {
	if (it->tagName() == "a") {
	    it->parseAttributes();
	    string link = it->attribute("href").second;
	    links.insert(link);
	}
    }

    return links;
}

list<Page> crawl(string startUrl, int depth) {
    list<Page> pages;
    queue<string> unvisited;
    unvisited.push(startUrl);

    while (!unvisited.empty()) {
	string link = unvisited.front();
	unvisited.pop();
	string html = getPageContent(link);
	if (unvisited.size() < depth){
	    set<string> links = getLinks(html);
	    set<string>::iterator it = links.begin();
	    set<string>::iterator end = links.end();
	    for (; it != end; ++it) {
		unvisited.push(*it);
	    }
	}
	string body = html;
	Page *page = new Page(link, body);
	pages.push_back(*page);
	if(pages.size() >= depth) {
	    break;
	}

    }
    return pages;
}

int main(void) {
    int n = 10;
    //string url = "https://www.messagexchange.com";
    string url = "http://cs.ucsd.edu/~hazhuang";

    list<Page> pages = crawl(url, n);
    list<Page>::iterator it = pages.begin();
    list<Page>::iterator end = pages.end();
    set<string> totalUniqWords;
    for (; it != end; ++it) {
	cout << it->url <<", " << it->countUniqWords() << endl;

	set<string> uniqueWordsPerPage = it->getUniqWords();
	set<string>::iterator j;
	for (j = uniqueWordsPerPage.begin(); j != uniqueWordsPerPage.end(); ++j) {
	    totalUniqWords.insert(*j);
	}
    }

    cout << "total, " << totalUniqWords.size() << endl;
    return 0;
}

