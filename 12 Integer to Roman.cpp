#include <iostream>
using namespace std;

string intToRoman(int num) {
    int numeralValues[] = {1000,500,100,50,10,5,1};
    string numerals[] = {"M", "D", "C", "X", "L", "V", "I"};
    int numNumerals[7];

    // for (int i=0; i<sizeof(numeralValues)/sizeof(int); i++){
    //     int numberOfNumerals = num / numeralValues[i];
    //     numNumerals[i] = numberOfNumerals;
    //     num -= (numberOfNumerals * numeralValues[i]);
    // }
    
    // string romanNumeral = "";
    // for (int i=0; i<sizeof(numeralValues)/sizeof(int); i++){
        
    //     if (numNumerals[i] >= 4 && i < 5){
    //         romanNumeral += (numerals[i] + numerals[i-2]);
    //     }
    //     else if (numNumerals[i] >= 4 && i == 5)
    //         romanNumeral += (numerals[i] + numerals[i-1]);
    //     else{
    //         for (int j=0; j<numNumerals[i]; j++)
    //             romanNumeral += numerals[i];
    //     }
    // }

    return (romanNumeral);

}

int main(){
    cout<<intToRoman(1994);
}