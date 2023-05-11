#include <iostream>
using namespace std;

int zan[28];
int n;
int i;
int mov_count;
int cmp_count;



	
void input()
{
    while (true)
    {
        cout << "enter the number of elements in the array: ";
        cin >> n;
        if ((n > 0) && (n <= 28))
            break;
        else
            cout << "\nMaksimum panjang array adalah 28" << endl;
    }

    cout << "\n===================" << endl;
    cout << "\nEnter Array Element" << endl;
    cout << "\n===================" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> zan[i];

    }
}

void q_sort(int low, int high) {     
    int pivot, i, mf; 
    if (low > high)
        return;

    pivot = zan[low];									

    i = low + 1;										
    mf = high;											

    while (i <= mf) {									
        
        while ((zan[i] <= pivot) && (i <= high)) {		
            i++;
            cmp_count++;								
        }
        
        while ((zan[mf] > pivot) && (mf >= low)) {		
            mf--;
            cmp_count++;								
        }
        cmp_count++;

        if (i < mf) { 		

            swap(i, mf);
            mov_count++;
        }
    }
    
    if (low < mf) {													
        
        swap(low, mf);
        mov_count++;
    }
    
    q_sort(low, mf - 1);												

}


void LinearSearch()
{
    char ch;
    int comparison;

    do
    {
        cout << "\nEnter the element you want to search: ";
        int item;

        comparison = 0;
        for (i = 0; i < n; i++)
        {
            comparison++;
            if (zan[i] == item)
            {
                cout << "\n" << item << " found " << (i + 1) << endl;
                break;
            }
        }

        if (i == n)
            cout << "\n" << item << " not found in the array\n";
        cout << "\Number of comparison: " << comparison << endl;

        cout << "\nComparison search (y/n): ";
        cin >> ch >> ch;
    } while ((ch == 'y') || (ch == 'y'));

}

void display() {
    cout << "n\n\Number of comparison";
    cout << "Sorted Array";
    cout << "\n----------" << endl;

    for (int i = 0; i < n; i++) {
        cout << zan[i] << " ";
    }

    cout << "\n\nNumber of Comparasions: " << cmp_count << endl;
    cout << "Number of data movements: " << mov_count << endl;
}



int main()
{
    input();
    LinearSearch();
    display();
}






