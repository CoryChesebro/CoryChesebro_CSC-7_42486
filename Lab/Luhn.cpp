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
    cout<<luhnChk("6011846520368473")<<endl;
    return 0;
}

bool luhnChk(string luhnNum){
    //Luhn algorithm used for validating credit card
    int sum = 0;//Sum of the digits after processing them
    bool c = false;
    for(int i = luhnNum.length() - 1; i >= 0; i--){//Process the numbers
        int temp = luhnNum[i] - '0';//Parse the string converting them to ints
        sum += (c)?(((temp << 1) >= 10)?((temp << 1) - 9):(temp << 1)):(temp);//If odd index & num * 2 >= 10 then subtract 9 else double num or just add num
        c = !c;//Flips flag used for finding odd index to double
    }
    if(sum % 10 == 0){//Check if the sum == 0
        cout<<"PASS"<<endl;
        return true;
    }
    else{//Return false if sum != 0
        cout<<"FAIL"<<endl;
        return false;
    }
}