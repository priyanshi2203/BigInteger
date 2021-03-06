#include<iostream>
//initialisation of library
#include "BigInteger.h"
using namespace std;

int main()
{
    /********declaration of variables*********/
    BigInteger n1;                                             //n1 defined with value 0
    BigInteger n2(123);                                        //n2 defined with value int value
    BigInteger n3((long long int)1234567898765432);            //n3 defined with value long long int value
    BigInteger n4("7832467326423873423435");                   //n4 defined with string value
    BigInteger n5(n3);                                         //n5 defined with values of n3

    /********Converting to BigNumbers*********/
    int num1 = -321;
    long long int num2 = -9876543219876543;
    string str1 = "-2112321321321312421534365777";
    BigInteger n6 = to_Big(num1);                              //converting int to BigInteger
    BigInteger n7 = to_Big(num2);                              //converting long long int to BigInteger
    BigInteger n8 = to_Big(str1);                              //converting string to BigInteger

    /********user Input*********/
    BigInteger n9;
    cout<<"Enter the value for n9: ";
    cin>>n9;                                                     //Taking input from user

    cout<<"n1: "<<n1<<endl;                                      /**           Printing Values        **/
    cout<<"n2: "<<n2<<endl;                                      /**           Printing Values        **/
    cout<<"n3: "<<n3<<endl;                                      /**           Printing Values        **/
    cout<<"n4: "<<n4<<endl;                                      /**           Printing Values        **/
    cout<<"n5: "<<n5<<endl;                                      /**           Printing Values        **/
    cout<<"n6: "<<n6<<endl;                                      /**           Printing Values        **/
    cout<<"n7: "<<n7<<endl;                                      /**           Printing Values        **/
    cout<<"n8: "<<n8<<endl;                                      /**           Printing Values        **/

    /********Arithmatic Operations*********/
    cout<<"Addition: "<<n1+n2<<endl;                             //Addition
    cout<<"Subtraction: "<<n2-n1<<endl;                          //subtraction
    cout<<"Multiplication: "<<n1*n2<<endl;                       //Multiplication
    cout<<"Division: "<<n4/n2<<endl;                             //Division

    cout<<"n2 + 5: "<<n2+5<<endl;
    cout<<"n2 - 5: "<<n2-5<<endl;
    cout<<"n2 * 5: "<<n2*5<<endl;
    cout<<"n2 / 5: "<<n2/5<<endl;

    cout<<"5 + n2: "<<5+n2<<endl;
    cout<<"5 - n2: "<<5-n2<<endl;
    cout<<"5 * n2: "<<5*n2<<endl;
    cout<<"5 / n2: "<<5/n2<<endl;


    /******** other Operations *********/

    //unary operations
    cout<<"PreIncrement: "<<++n2<<endl;
    cout<<"PreDecrement: "<<--n2<<endl;
    cout<<"PostIncrement: "<<n2++<<endl;
    cout<<"PostDecrement: "<<n2--<<endl;

    //equality check
    cout<<"Check n3 != n5: "<<(bool)(n3 != n5)<<endl;              //Checking if value of both are different
    cout<<"Check n3 == n5: "<<(bool)(n3 == n5)<<endl;              //Checking if value of both are same

    n3 += n2;
    cout<<"n3 += n2: "<<n3<<endl;

    n3 -= n2;
    cout<<"n3 -= n2: "<<n3<<endl;

    n3 *= n2;
    cout<<"n3 *= n2: "<<n3<<endl;

    n3 /= n2;
    cout<<"n3 /= n2: "<<n3<<endl;


    /********Functions*********/

    cout<<"Maximum: "<<maxBig(n1, n2)<<endl;                               //Maximum of two Numbers
    cout<<"Minimum: "<<minBig(n1, n2)<<endl;                               //Minimum of two Numbers
    cout<<"absolute: "<<absBig(n1)<<" "<<absBig(n2)<<endl;                //Absolute value of a number
    cout<<"Factorial: "<<factBig(n1)<<" "<<factBig(n2)<<endl;             //Factorial of a number
    cout<<"Reverse: "<<revBig(n3)<<endl;                                   //Reverse a number
    cout<<"Counting the occurance of a digit: "<<countBig(n9,6)<<endl;     //Counting the occurance of a digit
    cout<<"Erasing all occurance of a digit: "<<eraseBig(n9,4)<<endl;      //Erasing all occurances of a digit
    cout<<"isPaliBig: "<<(bool)isPaliBig(n9)<<endl;                       //Checking if a number is palindrome
    cout<<"sorting the digits: "<<sortBig(n9)<<endl;                       //sort the digits of a number
    cout<<"Finds power: "<<powBig(n3, n2)<<endl;                           //finds x to the power y, where x and y is any int. Returns Integer value in form of string

    return 0;
}