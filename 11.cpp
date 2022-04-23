#include <iostream>
#include <ctime>
#include <algorithm>

bool is_prime ( int a , int b ) {
    if ( b == 2 ) {
        return true ;
    }
    else if ( b % 2 == 0 ) {
        return false ;
    }
    for ( int i = 3 ; i < b ; i++ ){
        if ( b % i == 0){
            return false;
        }
    }
    return true;
}

void selection_sort ( int* arr , int size , bool (*ptrf) ( int , int ) = [](int a , int b) -> bool { return a < b ; } ) { // we initialize the function argument for users who dont want to input function and want to use default selection
     for ( int i = 0 ; i < size - 1 ; i++ ){
        int max = i ;
        for ( int j = i + 1 ; j < size ; j++ ){
            if ( ptrf ( arr[max] , arr[j]) ){
                max = j ;
            }
        }
        int tmp = arr[i] ;
        arr[i] = arr[max] ; 
        arr[max] = tmp ;
    }
}

int main() {
    srand(time(0));
    int size = 0 ;
    std::cin >> size ;
    int* arr = new int [size] ;
    for ( int i = 0 ; i < size ; i++ ){
            arr[i] = 100 + (rand() % 100);
    }
    std::cout << "{" ;
    for ( int i = 0 ; i < size ; i++){
        std::cout << arr[i] << "." ;
    }
    std::cout << "}" << std::endl ;

    selection_sort(arr , size ) ; 
    for ( int i = 0 ; i < size ; i++) {
        std::cout << arr[i] << "." ;
    } 
    
    std::cout << std::endl ;

    selection_sort(arr , size , [](int a , int b)-> bool { return (b % 2 == 0); }) ; 
    for ( int i = 0 ; i < size ; i++) {
        std::cout << arr[i] << "." ;
    } 
      
    
    std::cout << std::endl ;
    
      selection_sort(arr , size , is_prime) ; 
    for ( int i = 0 ; i < size ; i++) {
        std::cout << arr[i] << "." ;
    }         
}