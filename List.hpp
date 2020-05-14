#pragma once

#include <iostream>

using namespace std;

template <typename T>
class List
{
public:
	List();
	List(T inf);

	void Add_begin(T value);
	void Add_end(T value);
	void inversion();

	template <typename T> friend ostream& operator<<(ostream& out, const List<T>& obj);

	~List();

private:
	template <typename T>
	struct List_el
	{
		T inf;
		List_el* next;
	};
	List_el<T>* Head;
	void deleteAll();
};

template<typename T>
List<T>::List()
{
	Head = NULL;
}

template<typename T>
inline List<T>::List(T inf)
{
	Head = new List_el<T>;
	Head->inf = inf;
	Head->next = NULL;
}

template<typename T>
inline void List<T>::Add_begin(T value)
{
	List_el<T>* newEl = new List_el<T>;
	newEl->inf = value;
	newEl->next = Head;
	Head = newEl;
}

template<typename T>
inline void List<T>::Add_end(T value)
{
	if (Head == NULL)
	{
		Head = new List_el<T>;
		Head->inf = value;
		Head->next = NULL;
	}
	else
	{
		List_el<T>* nel = Head;
		while (nel->next != NULL)
		{
			nel = nel->next;
		}
		nel->next = new List_el<T>;
		nel->next->inf = value;
		nel->next->next = NULL;
	}
}

template<typename T>
inline void List<T>::inversion()
{
	List<T> temp;
	while (Head != NULL)
	{
		temp.Add_begin(Head->inf);
		Head = Head->next;
	}
	this->deleteAll();
	while (temp.Head!=NULL)
	{
		this->Add_end(temp.Head->inf);
		temp.Head = temp.Head->next;
	}
}

template<typename T>
List<T>::~List()
{
	this->deleteAll();
}

template<typename T>
inline void List<T>::deleteAll()
{
	while (Head != NULL)
	{
		List_el<T>* temp = Head->next;
		delete Head;
		Head = temp;
	}
}

template<typename T>
inline ostream& operator<<(ostream& out, const List<T>& obj)
{
	List<T> temp;
	temp.Head = obj.Head;
	while (temp.Head != NULL)
	{
		out << temp.Head->inf << " ";
		temp.Head = temp.Head->next;
	}
	temp.Head = NULL;
	return out;
}
