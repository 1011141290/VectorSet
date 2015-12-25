
#include "VectorSet.h"


template<typename T>
//返回当前位置的引用
T& VectorSet<T>::Iterator::operator*()
{
	if(index >= 0 && index < outer.size())
		return (this->outer.at(this->index));
	else
	{
		cout<<"当前元素不存在"<<endl;
		exit(1);
	}
}

template<typename T>
//返回指向当前元素的指针
T* VectorSet<T>::Iterator::operator->()
{
	if(index >= 0 && index < outer.size())
		return &(this->outer.at(this->index));
	else
	{
		cout<<"当前元素不存在"<<endl;
		exit(1);
	}
}

/*template<typename T>
//前加：指向下一位置，返回下一位置对应的迭代器
typename VectorSet<T>::Iterator& VectorSet<T>::Iterator::operator++()
{
	return Iterator(*this, ++index);
}

template<typename T>
//后加：返回当前位置对应的迭代器，指向下一位置
VectorSet<T>::Iterator VectorSet<T>::Iterator::operator++(int i)
{
	
	return Iterator(*this, index++); 
}

template<typename T>
//前减（含义与前加类似，只是方向相反）
VectorSet<T>::Iterator& VectorSet<T>::Iterator::operator--()
{
	return Iterator(*this, --index);
}

template<typename T>
//后减（含义与后加类似，只是方向相反）
VectorSet<T>::Iterator VectorSet<T>::Iterator::operator--(int i)
{
	return Iterator(*this, index--);
}

template<typename T>
//指向下step个位置
VectorSet<T>::Iterator& VectorSet<T>::Iterator::operator+=(int step)
{
	return Iterator(*this, index + step);
}

template<typename T>
//指向上step个位置
VectorSet<T>::Iterator& VectorSet<T>::Iterator::operator-=(int step)
{
	return Iterator(*this, index - step)
}

template<typename T>
// 比较两个位置是否相同
bool VectorSet<T>::Iterator::operator==(const Iterator &other)
{
	return (index == other.index)? 1 : 0;
}

template<typename T>
//this位置是否位于other位置之前。
bool VectorSet<T>::Iterator::operator<=(const Iterator &other)
{
	return (index <= other.index)? 1 : 0;
}

template<typename T>
// this位置是否严格位于other位置之前
bool VectorSet<T>::Iterator::operator<(const Iterator &other)
{
	return (index < other.index);
}

template<typename T>
//this位置是否位于other位置之后
bool VectorSet<T>::Iterator::operator>=(const Iterator &other)
{
	return (index >= other.index);
}

template<typename T>
// this位置是否严格位于other位置之后
bool VectorSet<T>::Iterator::operator>(const Iterator &other)
{
	return (index > other.index);
}*/

int main(void)
{
  VectorSet<int> *vec = new VectorSet<int>();

  VectorSet<int>::Iterator *iterator =new VectorSet<int>::Iterator(*vec,0);
  VectorSet<int>::Iterator *iterator_tmp =new VectorSet<int>::Iterator(*vec,4);

  for(int i=0;i<10;i++)
  vec->insert(i);
  cout<<"输出数组长度："<<endl;
  cout<<vec->size()<<endl;

  int i = iterator->operator*();
  cout<<"返回当前位置的引用 :"<<i<<endl;

  int *j = iterator->operator->();
  cout<<"返回指向当前元素的指针 :"<<*j<<endl;
  
  cout<<"前加：指向下一位置，返回下一位置对应的迭代器 :"<<endl;
  iterator = &(iterator->operator++());
  cout<<"当前位置："<<iterator->index<<endl<<"当前元素："<<iterator->operator*()<<endl;

  cout<<"后加：返回当前位置对应的迭代器，指向下一位置:"<<endl;
  //iterator = &(iterator->operator++());

  cout<<"前减：指向上一位置，返回上一位置对应的迭代器 :"<<endl;
  iterator = &(iterator->operator--());
  cout<<"当前位置："<<iterator->index<<endl<<"当前元素："<<iterator->operator*()<<endl;

  cout<<"指向下3个位置 :"<<endl;
  iterator = &(iterator->operator+=(3));
  cout<<"当前位置："<<iterator->index<<endl<<"当前元素："<<iterator->operator*()<<endl;

  cout<<"指向上3个位置 :"<<endl;
  iterator = &(iterator->operator-=(3));
  cout<<"当前位置："<<iterator->index<<endl<<"当前元素："<<iterator->operator*()<<endl;

  cout<<"比较两个位置是否相同 :"<<endl;
  cout<<"位置是否相同："<<((iterator->operator==(*iterator_tmp) == 1)?"是":"否")<<endl;

  cout<<"this位置是否位于other位置之前 :"<<endl;
  cout<<"位置是否在前："<<((iterator->operator<=(*iterator_tmp) == 1)?"是":"否")<<endl;

  cout<<"this位置是否严格位于other位置之前 :"<<endl;
  cout<<"位置是否严格在前："<<((iterator->operator<(*iterator_tmp) == 1)?"是":"否")<<endl;

  cout<<"this位置是否位于other位置之后 :"<<endl;
  cout<<"位置是否在后："<<((iterator->operator>=(*iterator_tmp) == 1)?"是":"否")<<endl;

  cout<<"this位置是否严格位于other位置之后 :"<<endl;
  cout<<"位置是否严格在后："<<((iterator->operator>(*iterator_tmp) == 1)?"是":"否")<<endl;
  
return 0;
}
