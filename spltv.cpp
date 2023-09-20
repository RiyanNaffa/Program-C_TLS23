#include<iostream>
using namespace std;

float matrix[3][4];

void MatrixInput(){
    cout << "======SELAMAT DATANG DI PROGRAM PENYELESAIAN SPLTV======\n";
    cout << "Contoh: 5x + 9y - z = 10 diinputkan 5 9 -1 10\n\n";
    cout << "Masukkan nilai-nilai persamaan: \n";
    for(int i = 0; i<3; i++){           // perulangan input
        for(int j = 0; j<4; j++){
            cin >> matrix[i][j];
        }
    }
}

void PivotCheck(int row){               // fungsi untuk cek apakah ada 0 di pivot
    int j = -1;
    while(matrix[row][row]==0){
        j++;
        if(j == row) continue;
        for(int i = 0; i<4; i++){
            int temp = matrix[row][i];
            matrix[row][i] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

float SetMultiplier(int row, int column){   // fungsi untuk set nilai l
    return (matrix[row][column]/matrix[column][column]);
}

void MatrixOperation(int i, int j){         // fungsi upper triangular matrix
    float l = SetMultiplier(i,j);
    for(int column = 0; column<4; column++){
        matrix[i][column] -= (l*matrix[j][column]);
    }
}

int main(){
    MatrixInput();                          // panggil fungsi input
    for(int i = 1; i<3; i++){
        for(int j = 0; j<i; j++){
            PivotCheck(j);                  // lakukan iterasi untuk setiap
            MatrixOperation(i,j);           // elemen yg akan dibuat 0
        }
    }
    // menyelesaikan nilai variabel x, y, z
    float z = matrix[2][3]/matrix[2][2];
    float y = (matrix[1][3]-(matrix[1][2]*z))/matrix[1][1];
    float x = (matrix[0][3]-(matrix[0][2]*z)-(matrix[0][1]*y))/matrix[0][0];
    if(!(x==x)) cout << "Persamaan tidak dapat diselesaikan\n";
    // jika x adalah NaN, maka tidak ditemukan hasilnya
    else cout << "Hasilnya adalah: x = " << x << ", y = " << y << ", dan z = " << z << endl;
    return 0;
}