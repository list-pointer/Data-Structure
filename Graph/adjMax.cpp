#include <iostream>
#include <stdlib.h>

using namespace std;

class AdjacencyMatrix
{
    private :
        int adjarr[10][10];
        int vertex,edge,choice,edge1,edge2;
    public :
    AdjacencyMatrix()
    {
        for(int j=0;j<vertex;j++)
        {
            for(int z=0;z<vertex;z++)
            {
                adjarr[j][z]=0;
            }
        }
    }

    void get()
    {
            do
			{
				cout<<"0.Exit\n01.Enter Data \n02.Display Adjacency Array \n";
				cout<<"Enter Your Choice : "<<" ";
                cin>>choice;
				switch(choice)
				{
                    case 0:
                    break;

					case 1:
						EnterData();
						break;

					case 2:
						display();
						break;

					default:
					    cout<<"invalid input"<<endl<<endl;
				}
			}while(choice!=0);
    }

    void EnterData()
    {
        cout<<endl<<endl;
        cout<<"Enter Number of Vertex : ";
        cin>>vertex;
        cout<<"Enter Number of Edge : ";
        cin>>edge;

        for(int i=0;i<edge;i++)
        {
            cout<<"Enter vertex that has an edge : ";
            cin>>edge1;
            cin>>edge2;
            adjarr[edge1][edge2]=1;
            adjarr[edge2][edge1]=1;
        }
        cout<<endl<<endl;
    }

    void display()
    {
        cout<<endl<<endl;
        cout<<"Adjacency Matrix : ";
        cout<<endl<<endl;
        for(int j=0;j<vertex;j++)
        {
            for(int z=0;z<vertex;z++)
            {
                cout<<"     "<<adjarr[j][z]<<" ";
            }
            cout<<endl<<endl;
        }
        cout<<endl<<endl;
    }
    
};
int main()
{
    AdjacencyMatrix d;
    d.get();
    return 0;
}