//Find pairs in an integer array whose sum is equal to 10 (bonus: do it in linear time)
//restriction: range 0 and 10 inclusive and can be repeated
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

void checkSum(std::vector<int> temparr, int exists[11])
{
	for (int i = 0; i < temparr.size(); i++)		
	{
		exists[temparr[i]]++;				//populate the value as index array from given array
		//for (int j = 0; j < 11; j++)
		//{
		//	std::cout << exists[j] << " ";
		//}
		//std::cout << std::endl;
	}
	bool anyExist = false;
	for (int i = 0; i < 6; i++)	//only need to check half the range (up through value 5), the other half already sums to 10
	{
		int complement = 10 - i;
		if (exists[i] > 0 && exists[complement]>0)		//check the index and the complement of the index of the values to see if they are both present
		{
			std::cout << i << " + " << complement << " sums to 10" << std::endl;
			anyExist = true;
		}
	}
	if (!anyExist)
	{
		std::cout << "There are no integer pairs in this array that sum to 10" << std::endl;
	}
}

int main()
{

	char cont = 'y';
	do {
		std::vector <int> arr;
		srand(time(NULL));
		int numExists[11] = { 0 };		//number of times the values appear in the array, index is the value
		int size;
		std::cout << "Enter array size: " << std::endl;
		std::cin >> size;
		std::cout << "The array is as follows: " << std::endl;
		for (int i = 0; i <size; i++)
		{
			arr.push_back(rand() % 11+0);		//rand 0 to 10 inclusive, populate initial array
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		//for (int j = 0; j < 11; j++)
		//{
		//	std::cout << numExists[j] << " ";
		//}
		//std::cout << std::endl;

		checkSum(arr, numExists);
		std::cout << "ReRun?" << std::endl;
		std::cin >> cont;
	} while (cont == 'y' || cont == 'Y');
}


//things i learned: can't use sizeof without #include<array> or else it goes beyond end of array sometimes