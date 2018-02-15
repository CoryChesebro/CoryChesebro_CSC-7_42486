/*
*Author: Cory Chesebro
*Prof: Lehr
*Project: Luhn Check algorithm
*Feb 14 2018 11:54:44
*/

//!!!NOT COMPLETE STILL NEED DEBUGGIN!!!//


using namespace std;

#include <iostream>
#include <string>

bool luhnChk(string);

int main(){
    string luhns [5] = {"4929946198011268",
                        "4716741636331460",
                        "4716876088801956",
                        "4539540810780582",
                        "4539730731077115"};
    for(int i = 0; i < 5; i ++){
        cout<<luhnChk(luhns[i])<<endl;

    }
    return 0;
}

bool luhnChk(string luhnNum){
    //Luhn algorithm used for validating credit cards
    short digLen = luhnNum.length();//Length of the the number
    short checkDig = luhnNum[digLen - 1] - '0';//Check digit to validate number
    short sum = 0;//Sum of the digits after processing them
    for(int i = digLen - 2; i > 0; i -= 1){//Process the numbers
        if(i % 2){//Double every other num
            int temp = luhnNum[i] - '0';
            temp *= 2;
            if(temp >= 10){temp - 9;}
            sum += temp;
        }
        else{//Add nums that arent doubled
            sum += luhnNum[i];
        }
    }
    if(sum % 10 == checkDig){//Check the sum vs the check dig
        return true;
    }
    else{
        return false;
    }
}