// CP2406 - Prac_09 - Samuel Barrett - 13038579

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000;
// const int MAX_N = 1000;
// const int MAX_N = 100;

vector<int> sieve_of_erastosthenes(int limit){

    // PYTHON code
    // # Initialize a boolean array "prime[0..n]" and fill all entries it as true.
    // # A value in prime[i] will finally be false if i is Not a prime, else true.
    // prime = [True for _ in range(limit + 1)]
    // p = 2
    // while p * p <= limit:
    //     # If prime[p] is not changed, then it is a prime
    //     if prime[p]:
    //         # Updating all multiples of p
    //         for i in range(p * p, limit + 1, p):
    //             prime[i] = False
    //     p += 1

    vector<bool> isPrime(limit + 1, true);

    for (int p = 2; p * p <= limit; p++){

        if (isPrime[p]){
            for (int i = p * p; i <= limit; i += p){
                isPrime[i] = false;
            }
        }
    }

    // PYTHON code
    // # Collecting all prime numbers
    // prime_numbers = [p for p in range(2, limit) if prime[p]]
    // return prime_numbers

    vector<int> primeNumbers;
    for (int i = 2; i <= limit; i++){
        if (isPrime[i]){
            primeNumbers.push_back(i);
        }
    }

    return primeNumbers;
}

bool isCircularPrime(int n, const set<int>& primes_set) {
    string s = to_string(n);
    int n_rolls = s.length() - 1;  // 0 rolls for strings like '2', '3'
    for (int i = 0; i < n_rolls; i++) {        
        // rotate(s.begin(), s.begin() + 1, s.end());  // one way to roll by one
        s += s[0];            // Append the first character to the end
        s.erase(s.begin());  // Erase the first character
        int new_n = stoi(s);  // convert new string to int
        if (primes_set.find(new_n) == primes_set.end())
        return false;
    }

    return true;
}

int main(){

    auto prime_numbers = sieve_of_erastosthenes(MAX_N);

    // Print out the primes
    for (auto& p : prime_numbers){
        cout << p << ", ";
    }
    cout << endl;

    // Put primes into a new set of ints
    set<int> primes_set;
    for (const auto& val :prime_numbers) {
        primes_set.insert(val);
    }

    int res = 0;
    for (int n : prime_numbers) {
        if (isCircularPrime(n, primes_set)) {
            res++;
            cout << "n=" << n << ", res=" << res << endl;
        }
    }

    cout << "DONE" << endl;
    cout << "Total Circular Primes: " << res << endl;
}