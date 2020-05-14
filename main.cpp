#include <iostream>
#include "List.hpp"

using namespace std;

int main()
{
	List<int>* int_list = new List<int>;
	for (int i = 0; i < 5; i++)
	{
		int_list->Add_begin(i);
	}
	cout << *int_list << endl;
	int_list->inversion();
	cout << *int_list << endl;
	delete int_list;
	List<char>* char_list = new List<char>;
	for (int i = 'a'; i < 'z'; i++)
	{
		char_list->Add_end(i);
	}
	cout << *char_list << endl;
	char_list->inversion();
	cout << *char_list << endl;
	delete char_list;
}
