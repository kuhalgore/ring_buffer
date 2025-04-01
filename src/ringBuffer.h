#include <array>

template <typename T, size_t N> 
class RingBuffer
{
    
    std::array<T, N> buffer{};
    size_t pos = 0;
    size_t oldestElemPos = 0;
    
    public:
    size_t size(){
        if(oldestElemPos <= pos)
            return (pos-oldestElemPos)%N;
        else
            return N;
    }
    
    T& getCurrElement(){
        return buffer[pos];
    }
    
    T& geOldestElement(){
        return buffer[oldestElemPos];
    }
    
    void insert(T &&arg){
        //insert at position % N
        decltype(auto) newPos = (pos+1)%N;
        if( newPos == oldestElemPos)
        {
            ++oldestElemPos;
        }
        pos = newPos;
        buffer[pos] = std::forward<T>(arg);
    }
    
};