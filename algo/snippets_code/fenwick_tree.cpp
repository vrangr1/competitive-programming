#ifndef FENWICK_TREE_SNIPPET
#define FENWICK_TREE_SNIPPET
#include <iostream>
#include <vector>
#include <assert.h>
template <typename type>
class fenwick_tree{
private:
    size_t n;
    std::vector<type> arr, psum;
    
    size_t get_lsetbit(int val){
        return val&(-val);
    }
public:
    fenwick_tree(int n){
        this->n = n;
        this->arr.assign(n,0);
        this->psum.assign(n+1,0);
    }
    
    void update(size_t index, type val, bool by_increment = false){
        assert(index < this->n);
        if (!by_increment)
            val -= this->arr[index];
        arr[index] += val;
        index++;
        while(index <= n){
            this->psum[index] += val;
            index += get_lsetbit(index);
        }
    }

    fenwick_tree(const std::vector<type> &arr){
        static_assert(std::is_arithmetic<type>::value,
            "Fenwick Tree type must be an arithmetic type");
        this->n = arr.size();
        this->arr.resize(arr.size());
        this->psum.assign(arr.size()+1, static_cast<type>(0));
        for(size_t i = 0; i < this->n; ++i)
            this->update(i, arr[i]);
    }

    size_t size(){
        return this->n;
    }

    type get_sum(size_t index){
        type sum = 0;
        index++;
        while (index > ((size_t)0)){
            sum += this->psum[index];
            index -= get_lsetbit(index);
        }
        return sum;
    }
};
#endif