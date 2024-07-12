#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    int a;//Refers to the number guessed by the user
    int lb;//Refers to the lower boundary or the starting point of the guess
    int ub;//Refers to the upper boundary or the ending point of the guess
    cout<<"Enter the lower boundary of the guess"<<endl;
    cin>>lb;
    cout<<"Enter the upper boundary of the guess"<<endl;
    cin>>ub;
    srand(time(0)); 
    int k = (rand() % (ub - lb + 1)) + lb;//K refers tho the random number generated in the given range
    cout << "Guess the number between "<<lb<<"and "<<ub<<endl;
    while (true) {
        cin >> a;//The guess is taken from the user
        if (k > a) {
            //If the guess is higher than the number generated 
            cout << "Guess higher" << endl;
        } else if (k < a) {
            //If the guess is lower than the number generated
            cout << "Guess lower" << endl;
        } else {
            //If user guesses it correct
            cout << "Yeah! you got it " << endl;
            break;
        }
    }

    return 0;
}