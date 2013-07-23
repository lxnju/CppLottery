#ifndef ENCAPSULATE_H
#define ENCAPSULATE_H

/*
encapsulate class for the number array
*/

#include <set>
using namespace std;


class myarray{
public:
    //default constructor : lasy allocation - maybe less effeciency yet...
	myarray(int dataSize = 6): _data(NULL), _size(dataSize)
    {}
    
    myarray(set<int> intset): _size((int)intset.size())
    {
        _data = new int[_size];
        set<int>::iterator iter= intset.begin();
        for (int i = 0; i < _size; ++i, ++iter) {
            _data[i] = *iter;
        }
    }
    
    //operator =
	myarray& operator= (const myarray &rhs) 
	{
        if (this == &rhs)
            return *this;
        if (!_data)
            _data = new int[_size];
		memcpy(_data, rhs._data, _size*sizeof(int));
		return *this;
	}
    
    //copy constructor
	myarray(const myarray &rhs): _size(rhs._size)
    {
        _data = new int[_size];
		memcpy(_data, rhs._data, _size*sizeof(int));
    }
    
    //operator <
	bool operator< (const myarray &rhs) const
	{
		if (this == &rhs)
            return false;
        for (int i = 0; i < _size; ++i)
        {
            if (_data[i] < rhs._data[i])
                return true;
            else if(_data[i] > rhs._data[i])
                return false;
        }
        return false;
	}
    
    //operator ==
    bool operator== (const myarray &rhs) const
    {
        if (this == &rhs)
            return true;
        for (int i = 0;i < _size; ++i)
        {
            if (_data[i] != rhs._data[i])
                return false;
        }
        return true;
    }

    //destuctor
	~myarray() { if (_data) delete _data;}

    int getIndex(int index)
    {
        if (index < _size && _data)
            return _data[index];
        return -1;
    }
    
    bool setIndex(int index, int num)
    {
        if (index < _size)
        {
            if (!_data)
                _data = new int[_size];
            _data[index] = num;
            return true;
        }
        return false;
    }
    
    // is conflict with rhs. cnt means when conflict number is no less than cnt, return true.
    bool isConflict(myarray &rhs, int cnt)
    {
        if (cnt > _size || cnt <= 0) {
            return false;
        }
        int count = 0;
        
        for (int i = 0; i < _size; ++i) {
            for (int j = 0; j < rhs._size; ++j) {
                if (_data[i] == rhs._data[j]) {
                    ++count;
                    break;
                }
            }
            if (count >= cnt) {
                return true;
            }
        }
        return false;
    }
private:
	int *_data; // may be more easy to use a set
    int _size;
};

#endif