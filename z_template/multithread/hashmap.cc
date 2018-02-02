#include <thread>
#include <iostream>
#include <unistd.h>
#include<mutex>
#include<condition_variable>
#include <unordered_map>


//template<typename TK, typename TV>
//using TK = int;
//using TV = int;
class HashMap{
private:
    std::mutex mtx;
    std::condition_variable cond;
    std::unordered_map<int, int> hmap;

public:
    HashMap(){}
    void operator()() {

    }

    void operator()(int i , int j) {
	Insert(i, j);
    }

    bool Find(const int& k){
	if(hmap.find(k) != hmap.end()) return true;
	return false;
    }

    int Get(const int& k){
	int val = hmap[k];
	return val;
    }

    void Insert(const int & k, const int &v){
	//std::cout<<v<<std::endl;
	hmap[k] = v;
	//print();
    }

    void print(){
	std::cout<<"print map"<<std::endl;
	for(const auto & it : hmap){
	    std::cout<<it.first<<" : "<<it.second<<std::endl;
	}
    }

};

void func(HashMap &hm){//, int k, int v){
    std::cout<<"thread ";//<<k<<" "<<v<<std::endl;
}

int main(){
    const int NUM = 100;
    std::thread thd[NUM];
    HashMap hm;
    for(int i = 0 ; i < NUM; i++)
    {
	thd[i] = std::thread(std::ref(hm), i%10, i*100);//, i, i*100);
    }

    for(int i = 0; i< NUM; i++){
	thd[i].join();
    }

    hm.print();

    //sleep(1e6);
    return 0;
}
