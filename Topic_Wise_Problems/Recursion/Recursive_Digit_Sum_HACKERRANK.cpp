#include<iostream>
#include<string>
using namespace std;

#define ul unsigned long long

int super_digit(string str)
{
    int sum = 0;
    for(int i=0; i<str.length(); i++) {
        sum += str[i] - '0';
    }
    if((sum/10) >= 1) {
        sum = super_digit(to_string(sum));
    }
    return sum;
}

int main()
{
    int k;
    ul temp=0;
    char ch;
    while(ch != 32) {
        scanf("%c",&ch);
        if(ch<48 || ch>57) 
            break;
        
        temp += ch-'0';
    }
    cin>>k;
    temp *= k;
    cout<<super_digit(to_string(temp))<<endl;
}