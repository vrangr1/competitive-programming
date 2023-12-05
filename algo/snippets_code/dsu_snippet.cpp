#ifndef DSU_SNIPPET
#define DSU_SNIPPET
#include <iostream>
#include <vector>
template <typename type, typename = typename std::enable_if<std::is_integral<type>::value>::type>
class DSU{
private:
    const type neg = static_cast<type>(-1), z = static_cast<type>(0);
public:
    std::vector<type> parent, rank;
    DSU(type n):parent(n,neg),rank(n,z){}

    type find(type x){
        if (this->parent[x] == neg) return x;
        return this->parent[x] = this->find(this->parent[x]);
    }

    void unite(type x, type y){
        type px = this->find(x), py = this->find(py);
        if (px == py) return;
        if (this->rank[px] < this->rank[py]){
            this->rank[px] = this->rank[py];
            this->parent[px] = py;
        }
        else if (this->rank[px] > this->rank[py]){
            this->rank[py] = this->rank[px];
            this->parent[py] = px;
        }
        else{
            this->rank[px] = ++this->rank[py];
            this->parent[px] = py;
        }
    }
};
#endif