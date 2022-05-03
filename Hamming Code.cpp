#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

int main ()
{
  int a, b, c[30], d, r = 1, d1; 
  
  cout << " Enter the No of Data Bits you want to Enter : ";
  cin >> a;

while (a + r + 1 > pow (2, r)){
      r++;
}

cout << "No of data bits to be added " << r << " : Total Bits :" << a + r << endl;
cout << " Enter the Data Bits One by One :" << endl;
for (int i = 1; i <= a; ++i)
    cin >> c[i];
cout << endl << " Data bits entered : ";
for (int i = 1; i <= a; ++i)
    cout << c[i] << " ";
cout << endl;

int data[a + r+1];
  d = 0;
  d1 = 1;
for (int i = 1; i <= a + r; ++i){
    if ((i) == pow (2, d)){
   		data[i] = 0;
   		++d;
  	}
    else{
   		data[i] = c[d1];
   		++d1;
	}
}

d1 = 0;
  int min, max = 0, parity, s, j;

/*Parity Bit Calculation */
for (int i = 1; i <= a + r; i = pow (2, d1)){
    ++d1;
    parity = 0;
    j = i;
    s = i;
    min = 1;
    max = i;
    for (j; j <= a + r;){
   		for (s = j; max >= min && s <= a + r; ++min, ++s){
       		if (data[s] == 1)
  			parity++;
     	}
   		j = s + i;
   		min = 1; 	
 	}
    if (parity % 2 == 0){ // Even Parity
 		data[i] = 0;
	}else{
   		data[i] = 1;
 	}
}
cout << endl << " Hamming codeword bits for even parity are : ";
for (int i = 1; i <= a + r; ++i)
    cout << data[i] << " ";
cout << endl << endl;



//receiver side
cout<<"Enter the received data : \n";
int receivedData[a+r+1];
for(int i=1; i<=a+r; i++){
	cin>>receivedData[i];
}
int paritybits[r];
int p=r-1;
d1=0;
for (int i = 1; i <= a + r; i = pow (2, d1)){
    ++d1;
    parity = 0;
    j = i;
    s = i;
    min = 1;
    max = i;
    for (j; j <= a + r;){
   		for (s = j; max >= min && s <= a + r; ++min, ++s){
       		if (receivedData[s] == 1)
  			parity++;
     	}
   		j = s + i;
   		min = 1; 	
 	}
    if (parity % 2 == 0){ // Even Parity
 		paritybits[p] = 0;
 		p--;
	}else{
   		paritybits[p] = 1;
   		p--;
 	}
}
cout<<"\nThe parity bits in sequence are :  ";
for(int i=0; i<r; i++){
	cout<<paritybits[i];
}
cout<<"\nEnter the binary number (parity bits in sequence) : ";
int num;
cin>>num;
int binarynum=binaryToDecimal(num);
cout<<"\nThe decimal number corresponding to the parity bits is : ";
cout << binarynum << endl;
if(binarynum==0){
	cout<<"\nThere is no error in the message.\n";
}else{
	cout<<"The error is at bit positon : "<<binarynum;
	if(receivedData[binarynum]==0)receivedData[binarynum]=1;
	else receivedData[binarynum]=0;
	cout<<"\nThe correct message is:  ";
	for(int i=1; i<=a+r; i++){
		cout<<receivedData[i]<<" ";
	}
}
cout<<"\n\n";


}
