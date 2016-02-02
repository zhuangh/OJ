#include <utility>
#include <string.h>
#include <stdio.h>
//using namespace std;

class String{
public:
    String():data_(new char[1]){
	*data_='\0';
    }
    String(const char * str):data_(new char [strlen(str)+1]){
	strcpy(data_, str);
    }
    String( const String & str) : data_(new char [str.size()+1]){
	strcpy(data_, str.c_str());
    }

    ~String(){
	delete [] data_;
    }

    String & operator = ( String rhs){
//	strcpy(data_,str.c_str());
	swap(rhs);
	return *this;
    }

    String & operator = ( String && rhs){
//	strcpy(data_,str.c_str());
	swap(rhs);
	return *this;
    }

    String(String && rhs):data_(rhs.data_){
	rhs.data_ = nullptr;
    }

    const char * c_str() const {
	return data_;
    }
    size_t size() const{
	return strlen(data_);
    }
    void swap(String & rhs){
	std::swap(data_, rhs.data_);
    }

private:
    char * data_;
};

int main(){
    String s0;
    String s1("hello");
    String s2(s1);
    String s3 = s1;
 //   cout<<s1.c_str()<<endl;
    printf("%s\n",s1.c_str());
    printf("%s\n",s2.c_str());
    printf("%s\n",s3.c_str());
    return 0;
}
