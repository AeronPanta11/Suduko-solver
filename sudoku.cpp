#include <iostream>
using namespace std;
class condition1
{
    bool check_row()
    { int arr[9][9];
       int key,row_position;
       for (int j=0;j<9;j++)
       {
            if(arr[row_position][j]!=key)
            {
                return true;
            }

        }
        return false;
       
    }
    bool check_column()
    {
        int arr[9][9];
       int key,col_position;
       for (int i=0;i<9;i++)
       {
            if(arr[i][col_position]!=key)
            {
                return true;
            }
       }
       return false;
    }
    bool check_matrix()
    { 
        int arr[9][9];
        int row,col,key;
        int row_start=row-row%3;
        int col_start=col-col%3;
      for(int i=1;i<=9;i++)
      {
        if(arr[3*(row/3)+i/3][3*(col/3)+i/3]==key)
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
    return 0;
}