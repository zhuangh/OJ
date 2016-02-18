token_bucket:
	g++ -o token_bucket -std=c++11 tokenbucket.cpp  -lpthread  
file_dup:
	g++ -o fdup -std=c++11 file_dup.cpp md5.cpp -lpthread -lcrypto 
#file_dup_old:
	#g++ -o fdup_old -std=c++11 file_dup_old.cpp -lcrypto  

clean:
	rm token_bucket fdup

run:
	./token_bucket

all:
	make 
	make run

