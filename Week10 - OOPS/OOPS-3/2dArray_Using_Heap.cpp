#include <iostream>
using namespace std;
int main() {
        int row = 5;
        int col = 3;
        //creation
        int** arr = new int*[5];
        for(int i=0; i<row; i++) {
                arr[i] = new int[col];
        }
        //putting values in 2D array
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                arr[i][j] = 9;
            }
        }
        //printing
        for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                        cout << arr[i][j] <<" ";
                }
                cout << endl;
        }
        //de-allocate
        for(int i=0; i<row; i++) {
            delete []arr[i];
        }
        delete []arr;
        return 0;
}