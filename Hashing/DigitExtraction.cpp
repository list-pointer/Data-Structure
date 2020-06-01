#include <iostream>
using namespace std;

class DigitExtraction
{
private:
    int arr[100], extract_arr[100], single_arr[100], output_array[100];
    int choice, size, noe, n;

public:
    void get()
    {
        cout << "Enter the Size of Location Array : "
             << " ";
        cin >> size;

        for (int i = 0; i < size; i++)
        {
            arr[i] = -1;
        }

        cout << "Enter the Number of locations you want to extract : "
             << " ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter Location : ";
            cin >> extract_arr[i];
        }

        cout << "How many numbers do you want to hash? : "
             << " ";
        cin >> noe;

        for (int i = 0; i < noe; i++)
        {
            cout << "Enter Element no " << i << " : ";
            cin >> choice;
            operations(choice);
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == -1)
            {
                
            }
            else
            {
                cout << i<<" : "<<arr[i] << "\t";
            }
        }
        cout << endl;
    }

    void operations(int choice)
    {
        int location;
        int key = choice;
        location = count(key);
        cout << "Location is : "<<location << endl;

        if (arr[location] == -1)
        {
            arr[location] = choice;
        }
        else
        {
            while (1)
            {
                location++;
                if (arr[location] == -1)
                {
                    arr[location] = choice;
                    break;
                }
                if (location >= size)
                {
                    location = 0;
                }
            }
        }
    }

    int count(int key)
    {
        int temp, loc, value = 0, num, count = 0;
        temp = key;

        while (temp > 0)
        {
            temp = temp / 10;
            count++;
        }


        for (int i = 0; i < count; i++)
        {
            num = key % 10;
            single_arr[i] = num;
            key = key / 10;
        }
        
        for(int k=0;k<n;k++)
        {
        	int m=extract_arr[k];
        	output_array[k]=single_arr[m-1];
		}
		
			
		int start=0;
	int end=n-1;
    while (start < end) 
    { 
        int temp = output_array[start];  
        output_array[start] = output_array[end]; 
        output_array[end] = temp; 
        start++; 
        end--; 
    } 
	
		
         for (int i = 0; i < n; i++)
         {
             value = value * 10 + output_array[i];
         }
         loc = value % size;
         return loc;
    }

};

int main()
{
    DigitExtraction d;
    d.get();
    d.display();
    return 0;
}
