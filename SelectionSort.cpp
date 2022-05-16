#include <iostream>
using namespace std;

void SelectionSort(int myarr[])
{
    for (int i = 0; i < 4; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (myarr[j] < myarr[minIndex])

            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = myarr[minIndex];
            myarr[minIndex] = myarr[i];
            myarr[i] = temp;
        }
    }
}

int main()
{

    int myarr[5];
    cout << "Enter Any Random Elements :" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> myarr[i];
    }

    cout << "Unsorted Array" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myarr[i]<<" ";
    }
    cout<<endl;

    SelectionSort(myarr);

    cout << "Sorted Array" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myarr[i]<<" ";
    }
}