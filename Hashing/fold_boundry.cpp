#include <iostream>
#include <math.h>
#include<cmath>
using namespace std;

class Hash
{
    int arry[1000];
    int final[1000];
    int no_ele, size,divs, div_size;

public:
    Hash(int n, int s)
    {
        no_ele = n;
        size = s;

        for (int i = 0; i < s; i++)
            final[i] = -1;
    }

    void getdata()
    {
        cout << "*********************************\n";
        for (int i = 0; i < no_ele; i++)
        {
            cout << "Enter element : ";
            cin >> arry[i];
            if(arry[i]<0)
            {
                cout<<"\n----- Numbers cannot be negative -----\n";
                cout<<"Enter a positive number : ";
                cin>>arry[i];
            }
        }
    }

    int linear_probing(int index)
    {
        while (final[index] != -1)
        {
            index++;
            if (index == size)
                index = 0;
        }
        return index;
    }

    //HASHING FUNCTION
    void fold_boundry()
    {
        cout << "*********************************\n";
        int index;
        for (int i = 0; i < no_ele; i++)
        {
            cout<<"\n--- Element "<<i+1<<" ---";
            if (i > size - 1)
            {
                cout << "\n--- " << arry[i] << " cannot be stored as all locations are full ---\n";
            }
            else
            {
                index = divide(arry[i]);
                cout << "\nLocation = " << index << "\n";
                if (final[index] == -1)
                    final[index] = arry[i];
                else
                {
                    modulo_division(index, i);
                }
            }
        }
    }

    void modulo_division(int index, int i)
    {
        index = index % size;
        if (final[index] != -1)
            index = linear_probing(index);
        final[index] = arry[i];
        cout << "Location after Modulo-Division = " << index << "\n";
        cout << "****************\n";
    }

    //Functions for fold boundry
    int cnt(int n)
    {
        int temp = n, count = 0;
        while (temp > 0)
        {
            count++;
            temp /= 10;
        }
        return count;
    }

    int large(int a[])
    {
        int big = a[0];
        for (int i = 1; i < divs; i++)
        {
            if (big < a[i])
                big = a[i];
        }
        return big;
    }

    int rev(int n)
    {
        int r = 0;
        while (n > 0)
        {
            r = (r * 10) + (n % 10);
            n /= 10;
        }
    }

    int rev_arr(int n)
    {
        int r = 0;
        while (n > 0)
        {
            r = (r * 10) + (n % 10);
            n /= 10;
        }
        if (cnt(r) == 1)
            return r * 10;
        else
            return r;
    }

    int divide(int n)
    {
        int a_size = cnt(n), temp = n;
        div_size = cnt(size-1);
        int temp_size = a_size;
        int arr[a_size];
        int r;

        while (temp_size > 0) 
        {
            arr[temp_size - 1] = temp % 10;
            temp /= 10;
            temp_size--;
        }

        cout << "\nDivided element : " << endl; 
        for (int i = 0; i < a_size; i++)
            cout << arr[i] << "\t";

        divs =ceil((float) cnt(n) / cnt(size - 1)); 

        int diffrent[divs];
        temp_size = divs - 1;
        int count = 0;
        temp = 0;

        for (int i = a_size - 1; i >= 0; i--)
        {
            temp = arr[i] + temp * 10;
            diffrent[temp_size] = temp;
            count++;
            if (count == div_size)
            {
                temp_size--;
                count = 0;
                temp = 0;
            }
        }

        if(div_size>1)
        {
            for (int i = 0; i < divs; i++)
            {
                if (i != 0)
                {
                    if (i != divs - 1)
                        diffrent[i] = rev_arr(diffrent[i]);
                }
            }
        }
        
        if(diffrent[0]<10)
            diffrent[0]*=10;

        //cout<<"\n\n+++++++ Last element : "<<diffrent[divs]
        if(diffrent[divs-1]<10)
            diffrent[divs-1]*=10;

        cout << "\n\nDiffrentiated elements : \n";
        for (int i = 0; i < divs; i++)
            cout << diffrent[i] << "  ";

        cout << "\n****************";
        return without_carry(diffrent);
    }

    int without_carry(int arr[])
    {
        int cn = cnt(large(arr)), add = 0, divisor = 1;
        
        for (int i = 0; i < divs; i++)
        {
            add = add + arr[i];
        }

        while (cn > 0)
        {
            divisor = divisor * 10;
            cn--;
        }

        cout<<"\nAdd with carry = "<<add;
        cout<<"\nAdd withiut carry ="<<add%divisor;
        return add % divisor;
    }

    void showdata()
    {
        cout << "\nStored elements : \n";
        for (int i = 0; i < size; i++)
        {
            if (final[i] != -1)
                cout << "| " << i << " | " << final[i] << " |\n";
        }
        cout << endl;
    }
};

int main()
{
    int no_ele, size;
    cout << "\n\nEnter No. of loactions : ";
    cin >> size;
    cout << "Enter no of elements : ";
    cin >> no_ele;

    Hash h(no_ele, size);
    h.getdata();
    h.fold_boundry();
    h.showdata();
}