/*
*Author: Cory Chesebro
*Prof: Lehr
*Project: Luhn Check algorithm
*Feb 14 2018 11:54:44
*/

using namespace std;
#include <iostream>
#include <string>

bool luhnChk(string);//Luhn algorithm
void userInt();//User interface

int main(){
    userInt();//Starts user interface for program
    //cout<<luhnChk("6011846520368473")<<endl; //Used for debugging
    return 0;
}

bool luhnChk(string luhnNum){
    //Luhn algorithm used for validating credit card
    int sum = 0;//Sum of the digits after processing them
    bool c = false;//Flag for indicating odd index which dictates if number is doubled or not
    for(int i = luhnNum.length() - 1; i >= 0; i--){//Process the numbers
        int temp = luhnNum[i] - '0';//Parse the string converting chars to ints
        sum += (c)?(((temp << 1) >= 10)?((temp << 1) - 9):(temp << 1)):(temp);//If odd index & num * 2 >= 10 then subtract 9 else double num or just add num
        c = !c;//Flips flag used for finding odd index to double
    }
    if(sum % 10 == 0){//Check if the sum == 0
        return true;
    }
    else{//Return false if sum != 0
        return false;
    }
}

void userInt(){
    bool cntinue = false;
    string card = "";
    string answer = "";

    cout<<"Welcome to the Luhn Credit Card Checker"<<endl;
    cout<<"This program will take in a credit card number and check if it is valid"<<endl;
    do{
        cout<<"Enter the number you would like to validate: ";
        cin>>card;

        if(luhnChk(card)){
            cout<<"The number "<<card<<" is valid!"<<endl;
        }
        else{
            cout<<"The number "<<card<<" is not valid, make sure you type it in correctly!"<<endl;
        }
        
        cout<<"Would you like to check another number? Y/N: ";
        cin>>answer;
        
        if(!(answer == "y" && answer == "Y")){
            cntinue = false;
            cout<<"Cya later!"<<endl;
        }
    }while(cntinue);
}
