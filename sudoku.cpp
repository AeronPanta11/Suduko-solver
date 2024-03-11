#include <iostream>
using namespace std;
class condition1
{
    int arr[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                     {5, 2, 0, 0, 0, 0, 0, 0, 0},
                     {0, 8, 7, 0, 0, 0, 0, 3, 1},
                     {0, 0, 3, 0, 1, 0, 0, 8, 0},
                     {9, 0, 0, 8, 6, 3, 0, 0, 5},
                     {0, 5, 0, 0, 9, 0, 6, 0, 0},
                     {1, 3, 0, 0, 0, 0, 2, 5, 0},
                     {0, 0, 0, 0, 0, 0, 0, 7, 4},
                     {0, 0, 5, 2, 0, 6, 3, 0, 0}};

public:
    int safe(int key,int i,int j)
    {
        if (check_row(key,i) && check_column(key,j) && check_matrix(key,i,j))
        {
            return key;
        }
        else
        {
            while (key != 9)
            {
                safe(key + 1,i,j);
            }
        }
    }
    void start()
    {

        int  key = 1;

        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                if (arr[i][j] == 0)
                {
                    int safe_value = safe(key,i,j);
                    arr[i][j] = safe_value;
                }
            }
        }
        cout<<endl<<"***************************final solution is**********************************"<<endl;
          for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                
                cout<<arr[i][j];
            }
        }
    }

    bool check_row(int key,int i)
    {
        int arr[9][9];
        int  row_position=i;
        for (int j = 0; j < 9; j++)
        {
            if (arr[row_position][j] != key)
            {
                return true;
            }
        }
        return false;
    }
    bool check_column(int key,int j)
    {
        int arr[9][9];
        int  col_position=j;
        for (int i = 0; i < 9; i++)
        {
            if (arr[i][col_position] != key)
            {
                return true;
            }
        }
        return false;
    }
    bool check_matrix(int key,int i,int j)
    {
        int arr[9][9];
       int row=i;
       int col=j;
        int row_start = row - row % 3;
        int col_start = col - col % 3;
        for (int i = 1; i <= 9; i++)
        {
            if (arr[3 * (row / 3) + i / 3][3 * (col / 3) + i / 3] == key)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    condition1 c1;
    c1.start();
    return 0;
}