#include <./algorithm>
#include <vector>

namespace skycpp
{
    template<class T>

    // 暂只考虑指针类型的处理，所以屏蔽原始结构的构造
    class Heap
    {
    private:
        Heap(){}
        ~Heap(){}
    };

    template<class T>
    class Heap <T *>
    {
    public:
        // 二元判断式，(t0 < t1) == true时为大顶堆，(t0 > t1) == true 时为小顶堆
        typedef bool(*TypeOnCompare)(T*, T*);
        Heap(TypeOnCompare onCompare = NULL): _onCompare(onCompare){}

        Heap(T* beginElement, int count, TypeOnCompare onCompare = NULL)
        : _onCompare(onCompare)
        {
            for (int i = 0; i < count; ++i)
                _dataList.push_back(&beginElement[i]);
            if (_onCompare)
                std::make_heap(_dataList.begin(), _dataList.end(), _onCompare);
            else
                std::make_heap(_dataList.begin(), _dataList.end());	
        }
        ~Heap()
        {
            typename std::vector<T*>::iterator it = _dataList.begin();
            for (; it != _dataList.end(); ++it)
                delete *it;
            _dataList.clear();            
        }

        inline void Push(T* t)
        {
            _dataList.push_back(t);
            if (_onCompare)
                std::push_heap(_dataList.begin(), _dataList.end(), _onCompare);
            else
                std::push_heap(_dataList.begin(), _dataList.end());
        }

        inline void Pop()
        {
            if (this->isEmpty())
                return;				
            if (_onCompare)
                std::pop_heap(_dataList.begin(), _dataList.end(), _onCompare);
            else
                std::pop_heap(_dataList.begin(), _dataList.end());
            _dataList.pop_back();
        }

        inline T* Top()
        {
            if (this->isEmpty())
                return NULL;
            return _dataList[0];
        }

        inline void AdjustHeap(TypeOnCompare onCompare = NULL)
        {
            _onCompare = onCompare;
            if (_onCompare)
                std::make_heap(_dataList.begin(), _dataList.end(), _onCompare);
            else
                std::make_heap(_dataList.begin(), _dataList.end());
        }
        // 堆是否为空
        inline bool isEmpty() const {return _dataList.empty();}
        // 堆大小
        inline size_t size() const {return _dataList.size();}
    protected:
        std::vector<T*> _dataList;
        TypeOnCompare _onCompare;
    };
}

