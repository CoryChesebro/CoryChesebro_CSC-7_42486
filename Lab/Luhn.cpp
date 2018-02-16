/*
*Author: Cory Chesebro
*Prof: Lehr
*Project: Luhn Check algorithm
*Feb 14 2018 11:54:44
*/

using namespace std;
#include <iostream>

bool luhnChk(string);

int main(){
    luhnChk("344053814204172");
    return 0;
}

bool luhnChk(string luhnNum){
    //Luhn algorithm used for validating credit cards
    int digLen = luhnNum.length();//Length of the the number
    int checkDig = luhnNum[digLen - 1] - '0';//Check digit to validate number
    int sum = 0;//Sum of the digits after processing them
    bool c = true;
    for(int i = digLen - 2; i >= 0; i--){//Process the numbers
        if(c){//Double every other num
            int temp = luhnNum[i] - '0';
            temp *= 2;
            if(temp >= 10){temp -= 9;}
            sum += temp;
        }
        else{//Add nums that arent doubled
            sum += luhnNum[i] - '0';
        }
        c = !c;
    }
    if((sum + checkDig) % 10 == 0){//Check the sum vs the check dig
        return true;
    }
    else{
        return false;
    }
}