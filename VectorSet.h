// VectorSet.h: interface for the VectorSet class.
//
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <assert.h>
#include<iterator>

using namespace std;
#if !defined(AFX_VECTORSET_H__16AC5202_3677_4DB2_B76D_EBEB8DD1960D__INCLUDED_)
#define AFX_VECTORSET_H__16AC5202_3677_4DB2_B76D_EBEB8DD1960D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// 用于本项目的简单集合 (相对于STL:Set而言)
// 主要用于数据量小的情况下的集合操作


template<typename T>
class VectorSet  
{
private:
	typedef vector<T> SetType;
	SetType myset;
	const string DELIMITER;
public:
	VectorSet(const string delimiter=","):
	DELIMITER(delimiter) {}

	VectorSet(const VectorSet& other): myset(other.myset), DELIMITER(other.DELIMITER) { }
	const VectorSet& operator=(const VectorSet& other) {
		if (this != &other)
			myset = other.myset;
		return (*this);
	}

	//返回索引，-1表示未找到
	size_t find(const T& ele) const {
		size_t i=0;
		size_t len = myset.size();
		for(; i<len && myset[i] != ele; ++i);
		return i<len ? i: -1;
	}
	void insert(const T& ele) {
		if (find(ele)== -1)
			myset.push_back(ele);
	}
	void push_back(const T& ele) {
		insert(ele);
	}
	void append(const T& ele) {
		insert(ele);
	}

	bool has_common(const VectorSet& other) const {
		size_t i=0;
		size_t len = myset.size();
		for(; i<len && !other.find(myset[i]); ++i);
		return i<len;
	}

	const VectorSet& operator+=(const VectorSet& other) {
		if (this == &other)
			return *this;
		size_t i=0;
		size_t len = other.size();
		for (; i<len; ++i)
		{
			insert(other[i]);
		}
		return *this;
	}

	void erase(const T& ele) {

		SetType::iterator i = myset.begin();
		SetType::iterator e = myset.end();
		for(; i!=e && (*i)!= ele; ++i);
		if (i!=e)
			myset.erase(i);
	}
	size_t size() const {
		return myset.size();
	}
	bool empty() const {
		return myset.empty();
	}

	T& operator[](size_t index) {
		return myset[index];
	}
	T& at(size_t index) {
		assert(index < size());
		return (*this)[index];
	}
	const T& operator[](size_t index) const {
		return myset[index];
	}
	const T& at(size_t index) const {
		assert(index < size());
		return (*this)[index];
	}


	friend ostream& operator<<(ostream& out, const VectorSet& vs) {
		size_t i= 0;
		size_t len= vs.size();
		for(; i<len; ++i) {
			out << vs[i];
			if (i!= len-1)
				out << vs.DELIMITER;
		}
		return out;
	}

public:
        class Iterator
        {
        public:
				size_t index;
				VectorSet<T> &outer;

				Iterator(VectorSet<T> &o,size_t i=0):outer(o),index(i){}
				~Iterator() {delete outer;}
                T& operator*(); //返回当前位置的引用
                T* operator->(); //返回指向当前元素的指针

                Iterator& operator++()				
				{//前加：指向下一位置，返回下一位置对应的迭代器
					if( (index+1) <= (this->outer.size()-1) )
					{
						++index;
						return *this;
					}
					//else
					cout<<"已经到末尾，返回末尾元素"<<endl;
					return *this;
					
				}

                Iterator operator++(int) 
				{//后加：返回当前位置对应的迭代器，指向下一位置	
					return Iterator(*this, index++); 
				}

                Iterator& operator--() 
				{//前减（含义与前加类似，只是方向相反）
					if( (index-1) >= 0)
					{
						--index;
						return *this; 
					}
					else 
					{
						cout<<"已经到头，返回第一个元素"<<endl;
						return *this;
					}
				}

                Iterator operator--(int) 
				{//后减（含义与后加类似，只是方向相反）
					
					return Iterator(*this, index--);
				}

                Iterator& operator+=(int step) 
				{//指向下step个位置
					if( (index + step) <= (this->outer.size()-1))
					{
						index += step;
						return *this;
					}
					else
					{
						cout<<"输入超长，默认指向末尾元素"<<endl;
						index = this->outer.size()-1;
						return *this;
					}
				}

                Iterator& operator-=(int step)
				{//指向上step个位置
					if( (index - step) >= 0)
					{
						index -= step;
						return *this;
					}
					else
					{
						cout<<"输入超出下限，默认指向第一个位置元素"<<endl;
						index = 0;
						return *this;
					}
				}

                bool operator==(const Iterator &other)
				{// 比较两个位置是否相同
					return (index == other.index)? 1 : 0;
				}

                bool operator<=(const Iterator &other)
				{//this位置是否位于other位置之前。
					return (index <= other.index)? 1 : 0;
				}

                bool operator<(const Iterator &other)
				{// this位置是否严格位于other位置之前。
					return (index < other.index)? 1 : 0;
				}
                bool operator>=(const Iterator &other)
				{//this位置是否位于other位置之后。
					return (index >= other.index)? 1 : 0;
				}
                bool operator>(const Iterator &other)
				{// this位置是否严格位于other位置之后。
					return (index > other.index)? 1 : 0;
				}
				
        };

};

#endif // !defined(AFX_VECTORSET_H__16AC5202_3677_4DB2_B76D_EBEB8DD1960D__INCLUDED_)
