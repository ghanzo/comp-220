#include <iostream>
#include "DynamicArray.h"

using namespace std;


int main() {

	//using Dynamicarray works as a tracker
	DynamicArray<double> instance(100);
	DynamicArray<int> tracker(1);

	char buf[100];
	char buf2[100];
	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		cout << "Enter Dynamicarray position, then value | 'q' or 'Q' to quit" << endl;

		cin >> buf;
		if (buf[0] == 'q' || buf[0] == 'Q')break;
		cin >> buf2;
		if (buf2[0] == 'q' || buf2[0] == 'Q')break;

		if (atoi(buf) >= 0)
		{ //tracker needs 2 grow when Dynamicarray grows
			if (instance.capacity() > tracker.capacity())
				tracker[instance.capacity()];

			instance[atoi(buf)] = atof(buf2);
			tracker[atoi(buf)] = 1;
		}
	}

	//UNIQUE VALUE OUTPUT
	for (int i = 0; i < instance.capacity(); i++)
		if (tracker[i] > 0) count++;//count needs own loop to display before displaying values
	cout << endl << "There are " << count << " unique values." << endl << endl;

	//INDEX PAIR OUTPUT
	cout << "The index value pairs are..." << endl;
	for (int i = 0; i < instance.capacity(); i++)
		if (tracker[i] > 0)
			cout << "instance[" << i << "] = " << instance[i] << endl;
	cout << endl;

	//INDEX SEARCH
	char buf3[100];
	for (int i = 0; i < instance.capacity(); i++)
	{
		cout << "Enter Dynamicarray position to see if in use | 'q' or 'Q' to quit" << endl;

		cin >> buf3;
		if (buf3[0] == 'q' || buf3[0] == 'Q')break;

		if (atoi(buf3) > 0 && tracker[atoi(buf3)] != 0)
			cout << "Found - instance[" << atoi(buf3) << "] = " << instance[atoi(buf3)] << endl << endl;
		else cout << "Not found" << endl;
	}

	cout << "Thank you" << endl;

	return 0;
}
