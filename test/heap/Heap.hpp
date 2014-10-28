#include <./algorithm>
#include <vector>

namespace skycpp
{
    template<class T>
    class Heap
    {
    };
    template<class T>
	class Heap <T *>
	{
	public:
		typedef bool(*TypeOnCompare)(T*, T*);
		Heap(TypeOnCompare onCompare = NULL): _onCompare(onCompare){}
		Heap(T* beginElement, int count, TypeOnCompare onCompare = NULL)
		: _onCompare(onCompare)
		{
			for (int i = 0; i < count; ++i)
			{
				_dataList.push_back(&beginElement[i]);
			}
			if (count > 1)
			{
				if (_onCompare)
                    std::make_heap(_dataList.begin(), _dataList.end(), _onCompare);
				else
					std::make_heap(_dataList.begin(), _dataList.end());				
			}
		}
		~Heap(){}
		
		void Push(T* t)
		{
			_dataList.push_back(t);
			if (_onCompare)
				std::push_heap(_dataList.begin(), _dataList.end(), _onCompare);
			else
				std::push_heap(_dataList.begin(), _dataList.end());
		}
		
		void Pop()
		{
			if (!_dataList.size())
				return;				
			if (_onCompare)
				std::pop_heap(_dataList.begin(), _dataList.end(), _onCompare);
			else
				std::pop_heap(_dataList.begin(), _dataList.end());
            _dataList.pop_back();
		}

		T* Top()
		{
			if (!_dataList.size())
				return NULL;
			return _dataList[0];
		}
	protected:
        std::vector<T*> _dataList;
		TypeOnCompare _onCompare;
	};
}
