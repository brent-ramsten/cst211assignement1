/*
Brent Ramsten

cst211

assignment #1
*/
#include "exception.h"




#ifndef  array_H
#define  array_H


#define  ERR_MEM_ALLOC      2
#define  ERR_OUT_OF_BOUNDS  3

template<class T>
class Array
{
	
public:
	Array();
	~Array();
	
	
	Array(int length, int startIndex = 0);
	Array(const Array &dataSet);

	Array &operator=(Array &dataSet);
	T &operator[](int index);


	
	
	int getStartIndex() { return m_start_index; }
	void setStartIndex(int start_index);
	
	
	int getLength() { return m_length; }
	void setLength(int length);

private:
	int m_length;
	int m_start_index;
	T *m_values;
	
};

template<class T>
Array<T>::Array()
{
}


//the below comment establishes all the m_variables with the construction of the constructor so it is unnecessary to do inside it 
//: m_length(length), m_start_index(startIndex), m_values(new  T[m_length - 1])
//if m_values is not properly 
template<class T>
Array<T>::Array(int length, int startIndex) :
m_length(length),
m_start_index(startIndex),
m_values(new  T[m_length - 1])
{
	
		if (!m_values)
		{
			//cout << "thrown allocation error\n";
			//exit(EXIT_FAILURE);
			
				Exception<char>('a');
			
			

		}
	


}


//resets the start index
template<class T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;

}


//resets the length by moving the array into a temporary location
//then deleting the current array and replacing it with the contents of the temporary array
template<class T>
void Array<T>::setLength(int length)
{
	T *temporay = new T[length - 1];
	for (int i = 0; i < length; i++)
	{
		temporay[i] = m_values[i];
	}

	m_length = length;
	delete[] m_values;
	m_values = new T[m_length - 1];
	for (int i = 0; i < m_length; i++)
	{
		m_values[i] = temporay[i];
	}
	//this then destroys the temporary data
	delete[] temporay;
}





//this takes both of the array objects from the Array classes
//then it deletes the first object and replaces it with the rhs object
template<class T>
Array<T> &Array<T>::operator=(Array<T> &dataSet)
{
	delete[] m_values;
	m_values = dataSet.m_values;
	return *this;
}



template<class T>
T &Array<T>::operator[](int index)
{
	//what i assume exception class is supposed to do

		if (0 > ( index - getStartIndex() ) || getLength() <= index)
		{
			//cout << "outisde bounds error";
			//exit(EXIT_FAILURE);
			Exception<char>('b');
		}
	
	//end check

	//this uses the start index to get the appropriate index from the m_values array object
	index -= getStartIndex();
	return m_values[index];
}


//when the Array class hits the destructor it deletes the dynamic memory
template<class T>
Array<T>::~Array()
{
	delete[]  m_values;
}



#endif