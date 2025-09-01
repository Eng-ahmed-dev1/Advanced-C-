#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	////Task 1
	//int n = 100;
	//int* ptr = &n;

	//cout << "Address :" << ptr << endl;
	//cout << "Value : " << *ptr << endl;
	//// change value via dereference 
	//*ptr = 99;
	//cout << n << endl;

	////Pointer increment
	//int arr[] = { 1,3,5,7,9 };
	//int* fe = arr;
	//int res = 0;
	//for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	//{
	//	res += *(fe + i);
	//}
	//cout << res << endl;
	////Task 2 
	////Swapping using pointers
	//int x = 10; // 23
	//int y = 23; // 10
	//cout <<"Before Swaping " << x << " " << y << endl;

	//int* p1 = &x;
	//int* p2 = &y;

	//*p1 = *p1 + *p2; // 33
	//*p2 = *p1 - *p2;  // 10
	//*p1 = *p1 - *p2; //23

	//cout << "After Swaping " << x << " " << y << endl;
	////make the value double 
	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//int* ptr = arr;
	//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	cout << *(ptr + i) * 2 <<endl;
	//}

	////Task 3 
	////Pointer arithmetic challenge

	//int arr[] = { 1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10 };
	//int* ptr = arr;
	//int i = 0;
	//while (i < 10 )
	//{
	//	if (*ptr % 2 == 1 ) 
	//	{
	//		cout << "The odd numbers " << *ptr << endl;
	//	}
	//	ptr++; // خلي المؤشر يتحرك على العنصر اللي بعده
	//	i++;
	//}
	////=======================================================
	////Sum with moving pointer
	//int arr[5] = { 2,4,6,8,10 };
	//int* ptr = arr;
	//int res = 0; 
	//for (int i= 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	//{
	//	res += *ptr;
	//	ptr++;
	//}
	//cout << res << endl;
	////======================================
	////reverse the array using pointer
	//int arr[5] = { 1,2,3,4,5 };
	//int size = sizeof(arr) / sizeof(arr[0]);

	//int* ptr = &arr[size-1];
	//for (int i = size ; i >= 1; i--)
	//{
	//	cout << *ptr <<endl;
	//	ptr--;
	//}


	////======================================
	////Find the max and the min number in array using pointer
	//int arr[8] = {1,57,9,71,5,81,34,78};
	////The max number is 81 , the min number is 1
	//int s = sizeof(arr) / sizeof(arr[0]);
	//int* ptr = arr;
	//int max = *ptr;
	//int min = *ptr;

	//for (int i = 0; i < s; i++)
	//{
	//	if (*ptr > max )
	//	{
	//		max = *ptr;
	//	}
	//	if (*ptr < min)
	//	{
	//		min = *ptr;
	//	}
	//	ptr++;
	//}
	//cout << "The max value :" << max << endl;
	//cout << "The min value :" << min << endl;

}
