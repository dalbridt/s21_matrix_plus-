#include <iostream>
#include <string>
#include <exception>
#include "s21_matrix_oop.h"
using namespace std; 

int main(){
    
    S21Matrix matrix(5, 5);
    S21Matrix second(std::move(matrix)); 
    cout << "done" << endl ;
    return 0; 
}
