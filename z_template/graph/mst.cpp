
#include <iostream>

#define mx 50005
typedef pair<long long int,int> PII;
vector<PII>g[mx];
bool marked[mx];
long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
         
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0; i < g[x].size(); ++i)
        {
            y = g[x][i].second;
            if(marked[y] == false)
                Q.push(g[x][i]);
        }
    }
    return minimumCost;
}
long long rprim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0; i < rg[x].size(); ++i)
        {
            y = rg[x][i].second;
            if(marked[y] == false)
                Q.push(rg[x][i]);
        }
    }
    return minimumCost;
}

/*
int main()
{
    
        int n,m;
        scanf("%d%d",&n,&m);
  
        int x,y;
        long long w;
        for(int i=0;i<m;i++)
            scanf("%d%d%lld",&x,&y,&w);
         
            g[x].push_back(make_pair(w,y));
            g[y].push_back(make_pair(w,x));
           
        }
        long long  int lowcost=prim(1);
        printf("%lld",lowcost);
         
         
  
     
}
 */

template<typename T=int>
class edgeType{
private:
    char from;
    char to;
    T w;
public:
    edgeType(char a, char b, int c):from(a),to(b),w(c) {} 
    T getW() const {return w;}
    T getFrom() const {return from;}
    T getTo() const {return to;}
    bool operator < (const edgeType<T> & right) const {
        return w < right.getW();
    }
};

template<typename T>
void printMST(const std::vector<edgeType<T> > & mst) {
    for(const auto it: mst){
        std::cout<<"("<<it.getFrom()<<","<<it.getTo()<<","<<it.getW()<<") ";
    }
    std::cout<<std::endl;
}
 
int union_find(const int & from, vector<int> & arr){
    if(arr[from] == from){
        return from;
    }
    return union_find(arr[from], arr);
}

void union_set(const int & from, const int & to, vector<int> & arr){    
    arr[union_find(to, arr)] = arr[from];
}


template<typename T>
std::vector<edgeType<T> > kruskal(const std::vector<char> & nodes, std::vector<edgeType<T> > & edges){
    std::vector<edgeType<T> > mst;
    std::vector<int> arr;
    for(const auto & it: nodes){
        arr.push_back(it-'A');
    }
    std::sort(edges.begin(), edges.end());
    for(const auto & it : edges){
        int from = it.getFrom() - 'A';
        int to = it.getTo() - 'A';
        T w = it.getW();
        if( union_find(from, arr) != union_find(to, arr)){
            mst.push_back(edgeType<T>(from, to, w));
            union_set(from, to, arr);
        }
    }
    return mst;
}

int main() {    
    std::vector<char> nodes = {'A','B','C','D','E','F','G'};   
    std::vector< edgeType<int> > edges = { edgeType<int>('A', 'B', 7), edgeType<int>('A', 'D', 5),
      edgeType<int>('B', 'C', 8), edgeType<int>('B', 'D', 9), edgeType<int>('B', 'E', 7),
      edgeType<int>('C', 'E', 5), edgeType<int>('D', 'E', 15), edgeType<int>('D', 'F', 6),
      edgeType<int>('E', 'F', 8), edgeType<int>('E', 'G', 9), edgeType<int>('F', 'G', 11)};
    std::vector<edgeType<int> > mst_k = kruskal(nodes, edges);    
    std::cout<<"kruskal: ";
    printMST(mst_k);
    std::vector<edgeType<int> > mst_k = kruskal(nodes, edges);    
    return 0;
}


