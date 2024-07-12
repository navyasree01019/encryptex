#include <bits/stdc++.h>
using namespace std;
int main(){
    struct{
    double a;//refers to first number
    double b;//refers to second number
    char c;//refers to the operator used between then
    }calc;
    double output;//output of the calculation
    int flag = 0;//flag is used for 
    cout<<"Enter the calulation which is need to be performed"<<endl;
    cin>>calc.a>>calc.c>>calc.b;//inputs are taken from the user for arthematic operation
    switch(calc.c){
        case '+':
        output = calc.a+calc.b;//for addition
        break;
        case '-':
        output = calc.a-calc.b;//for subtraction
        break;
        case '*':
        output = calc.a*calc.b;//for multiplication
        break;
        case '/':
        output = calc.a/calc.b;//for division
        break;
        default:
        cout<<"Invalid operator entered";//for any other operator entered
        flag = 1;
    }
    if(flag==0){
    cout<<"The output of the calclulation is "<<output;//final output
    }
    return 0;
}