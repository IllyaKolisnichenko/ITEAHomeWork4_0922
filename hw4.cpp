
#include <iostream>
using namespace std;
int main()
{
int M{},N{},i{},j{};
int k = 1;
cout<<"Enter M: ";
cin >> M;
cout<<"Enter N: ";
cin >> N; 
int arr[M][N];

for ( i = 0; i < M; i++)
{

		
		if (i % 2 == 0) 
        {
			for ( j = 0; j < N; j++)
            {
				 arr[i][j]=k;
                 k++;
                 
            }
            
			
		}
		else 
        {
			for ( j = N - 1; j >= 0; j--)
            {
                arr[i][j]=k;
                k++;
			   
               
            }
            
        }
}

for(int i = 0; i < M; ++i) 
{
    for(int j = 0; j < M; ++j) 
    {
        cout.width(M);
        cout << arr[i][j];
    }
    cout << endl;
}
	return 0;
}
