// This program uses a bubble sort to arrange an array of integers in 
// ascending order

#include<iostream>
#include<fstream>
#include<vector>
#include<cstdint>
#include<string>
#include<algorithm>
#include<cctype>
#include<set>
using namespace std;

// Matthew Sullivan

//void bubbleSortArray(vector<int>&);
void displayArray(vector<string>);
void displaySet(set<string>);

int main()
{
	uint64_t compareNum = 0;
	fstream readFile;
	readFile.open("wordlist.txt");
	vector<string> values;
	string value;
	char check;
	int lineCount = 1;
	while (readFile.peek() != EOF)
	{
		check = readFile.peek();
		if (!isalpha(check) || (check == '\n'))
			readFile.ignore();
		else
		{
			getline(readFile, value);
			for (int i = 0; i < value.size(); i++)
			{
				value[i] = tolower(value[i]);
			}
			values.push_back(value);
			//			lineCount++;
		}
	}
	readFile.close();
	vector<string> sorted;
	sort(values.begin(), values.end());
	set<string> masterList;
	vector<string> key;
	for (int i = 0; i < values.size(); i++)
	{
		masterList.insert(values[i]);
	}
	for (set<string>::iterator it = masterList.begin(); it != masterList.end(); ++it)
	{
		key.push_back(*it);
	}
	cout << "Number of unique words:" << masterList.size() << endl;
//	displaySet(masterList);
	values.pop_back();

		for (int it=0; it <key.size(); it++)
	{
		int wordCount = 0;
		for (int i = 0; i < values.size(); i++)
		{
			if (key[it] == values[i])
			{
				wordCount++;
				compareNum++;
			}
			else
				compareNum++;

		}
		if ((it < 10)|| (it > masterList.size() - 10))
			cout << key[it] << ": " << wordCount << endl;
	}
	cout << "Total comparison count: " << compareNum << endl;
////	for (set<string>::iterator it = masterList.begin(); it != masterList.end(); ++it)
//	{
//		int wordCount = 0;
//		for (int i = 0; i < values.size(); i++)
//		{
//			if (*it == values[i])
//			{
//				wordCount++;
//				compareNum++;
//			}
//			else
//				compareNum++;
//
//		}
//		if (it < masterList.begin+10 || it > masterList.end-10)
//			cout << *it << ": " << wordCount << endl;
//	}
//	cout << "Total comparison count: " << compareNum << endl;

//	displayArray(values);
//	bubbleSortArray(values);
	system("PAUSE");
	return 0;
}

void displayArray(vector<string> array)    // function heading
{							   // displays the array	
for (int i = 0; i < array.size(); i++)
{
	cout << array[i] << "  ";
}
cout << endl;
}

void displaySet(set<string> array)    // function heading
{							   // displays the array	
	for (set<string>::iterator i = array.begin(); i!=array.end(); ++i)
	{
		cout << *i << "  ";
	}
	cout << endl;
}


//void bubbleSortArray(vector<int> &array)
//{
//	uint64_t compareNum = 0;
//	uint64_t swapNum = 0;
//	int temp;
//	for (int i = 0; i <= array.size()-1; i++) {
//		for (int j = 0; j <= array.size()-1; j++) {
//			if (j == array.size() - 1)
//			{
//				break;
//			}
//			else if (array[j] > array[j + 1]) {
//				// Consider std::swap here.
//				temp = array[j + 1];
//				array[j + 1] = array[j];
//				array[j] = temp;
//				swapNum++;
//			}
//			compareNum++;
//		}
//	}
//	cout << "Comparisons: " << compareNum << endl;
//	cout << "Swaps: " << swapNum <<endl;
//}
