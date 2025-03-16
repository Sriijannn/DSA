#include <iostream>
//Printing sum from 0 to N
using namespace std;
void printer( int &count, int &sum, int lim){
    
    if (count <=lim){
        sum = sum + count;
        (count)++; 
        printer(count, sum, lim);
    } else{
        return;
        }
}
int main(){
    int count = 1;
    int sum=0;
    int lim = 0;
    cin >> lim;
    cout<<"Recursion Starts\n";
    printer(count, sum, lim);
    cout<<sum;
    
}