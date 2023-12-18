// C++ program for segmented sieve when the input number is given
#include <bits/stdc++.h>
using namespace std;
//  GetPrime function gets all the primes in the range L to sqrt of R in prime(vector) array
void GetPrimes(vector<int>& prime, int R){
    bool c[R + 1];
    memset(c, true, sizeof(c));
    // initialising all elements as true in boolean array except 0,1 position
    c[1] = false;
    c[0] = false;
    // iterate the loop from 2 till sqrt of R
    for (int i = 2; (i * i) <= R; i++){
        if (c[i] == true){
            // if it is true mark all its multiples as false
            for (int j = i * i; j <= sqrt(R); j = j + i) {
                c[j] = false;
            }
        }
    }
    // storing all the primes in given range in prime array.
    for (int i = 2; i * i <= R; i++){
        if (c[i] == true) {
            prime.push_back(i);
        }
    }
}
// A segment of  sieve used to get primes in given range[L, R]
// in segmented sieve we calculate primes in range [low,high]
// here we initially we find primes in range [2,sqrt(high)] to mark all their multiples as not prime
// then we mark all their(primes) multiples in range [low,high] as false
// this is a modified sieve of eratosthenes , in standard sieve of  eratosthenes we find prime from 1 to n(given number)
// in segmented sieve we only find primes in a given interval
void Segmented_Sieve(int L, int R){
    // a dummy array of size R-L+1 is used for tracking the prime numbers in the given range
    bool dummy[R - L + 1];
    //initialise all its elements as true
    memset(dummy, true, sizeof(dummy));
    //here dummy[0] indicates whether low is prime or not similarly dummy[1] indicates whether low+1 is prime or not
    vector<int> prime;
    GetPrimes(prime, R);
    // primes has primes in range [L,sqrt(R)]
    // dummy array to keep track of only between the given range
    // first element means L, second element means L+1 and so on. 
    // dummy has elements between L and R so size is {R-L+1}    
    for (int i : prime){
        // getting the first index for prime multiples in the given range
        int low = (L/ i);
        // here dummy[0] indicates whether L is prime or not similarly dummy[1] indicates whether low+1 is prime or not   
        if (low <= 1){
            low = i + i;
        }
        else if (L % i){
            low = (low * i) + i;
        }
        else{
            low = (low * i);
        }
        for (int j = low; j <= R; j = j + i){
            dummy[j - L] = false;
        }
    }
   
    for (int i = L; i <= R; i++){
        if (dummy[i - L] == true){
            // if it is true it is a prime number and we print as result
            cout << (i) << " ";
        }
    }
}
int main(){
    // DRIVER CODE
    // low must greater than or equal to 2
    // L is the lower limit
    // R is the upper limit
    int L = 110;
    int R = 130;
// Calling for segment of sieves to get the answer
    Segmented_Sieve(L, R);
}

