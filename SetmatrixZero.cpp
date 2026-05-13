#include <iostream>
#include <vector>

using namespace std;

void setRow(vector<vector<int>>&a, int i, int n){
    for(int j = 0; j < n; j ++){
        a[i][j] = -1;
    }
}

void setColoumn(vector<vector<int>>&a,int j , int m){
    for(int i = 0; i < m; i ++){
        a[i][j] = -1;
    }
}
void setMatrixZero(vector<vector<int>>&a, int m, int n){
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            if(a[i][j] == 0){
                setRow(a,i,n);
                setColoumn(a,j,m);

            }
        }
    }
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            if(a[i][j] == -1){
                a[i][j] = 0;
            }
        }
    }

}

int main(){
    int m;
    int n;

    cout << "Enter the rows and colums of the Matrix" << endl;
    cin >> m;
    cin >> n;
    vector<vector<int>>matrix(m);
    cout << "Enter the elements of the matrix"<< endl;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            cin >> matrix[i][j];
        }
    }

    setMatrixZero(matrix, m, n);
    return 0;
}






//Now for the most optimal solution 

vector<vector<int>> matrixZero(vector<vector<int>>&a,int m, int n){
    int col0 = 1;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            if(a[i][j] == 0){
                a[i][0] = 0;

                if(j != 0){
                    a[0][j] = 0;
                }else{
                    col0 = 0;
                }
            }
        }
    }
    for(int i = 1; i < m; i ++){
        for(int j = 1; j < n; j ++){
            if(a[i][j] != 0){
                if(a[i][0] == 0 || a[0][j] == 0){
                    a[i][j] = 0;
                }
            }
        }
    }
    if(a[0][0] == 0){
        for(int j = 0; j < n; j ++){
            a[0][j] = 0;
        }
    }
    if(col0 == 0){
        for(int i = 0; i < m; i ++){
            a[i][0] = 0;
        }
    }

    return a;

}














