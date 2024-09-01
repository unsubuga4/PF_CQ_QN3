#include <iostream>

using namespace std;

// Function to calculate the sum from 'first' to  the'last' inclusive
int sum_from_to(int first, int last) {
    int sum = 0;
    for (int i = first; i <= last; ++i) { //i is pre-decremented (incremented before being used or outputed)
        sum += i; // sum = sum + i
    }
    return sum;
}

// Helper function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to reduce a fraction
int reduce(int &num, int &denom) {
    if (num <= 0 || denom <= 0) {
        return 0; // Failure to reduce
    }

    int divisor = gcd(num, denom);
    num /= divisor; // num =num/divisor
    denom /= divisor; // denom = denom/divisor
    return 1; // Successfully reduced
}

int main()
{
    // Test sum_from_to function
    int first, last;
    cout<<"Enter the First Value"<<endl;
    cin>>first;
    cout<<"Enter the Last Value"<<endl;
    cin>>last;
    cout << "Sum from " << first << " to " << last << " is: " << sum_from_to(first, last) << endl;

    // Test reduce function
    int num, denom;
    cout<<"Enter the Numerator"<<endl;
    cin>>num;
    cout<<"Enter the Denominator"<<endl;
    cin>>denom;
    cout <<"The original fraction is "<<num <<"/"<< denom<<endl;
    if (reduce(num, denom)) {
        cout << "The original fraction is reduced to: " << num << "/" << denom << endl;
    } else {
        cout << "Failed to reduce the fraction." <<endl;
    }


    return 0;
}
