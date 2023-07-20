/* 
 * File:   main.cpp
 * Author: mlehr
 * Created on July 18, 2023, 11:25 AM
 * Purpose:  Mark Sort
 */

//System Libraries
#include <iostream>  //I/O Stream Library
#include <cstdlib>   //Random Functions
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only

//Function Prototypes
void prntAry(int [],int,int);
void fillAry(int [],int);
void swap1(int &,int &);
void swap2(int &,int &);
void smlLst(int [],int,int);
void mrkSrt3(int [],int);
void mrkSrt1(int [],int);
void copyAry(int [],int [],int);


//Execution Begins Here
int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=16000;
    int array[SIZE],brray[SIZE];
    
    //Initialize Variables
    fillAry(array,SIZE);
    copyAry(array,brray,SIZE);
    //prntAry(array,SIZE,10);
    //prntAry(brray,SIZE,10);
    
    //The Process -> Map Inputs to Outputs
    int beg=time(0);
    mrkSrt3(array,SIZE);
    int end=time(0);
    cout<<"The total time for 3 functions on "<<SIZE<<" elements = "
            <<end-beg<<" Seconds"<<endl;
    
    beg=time(0);
    mrkSrt1(brray,SIZE);
    end=time(0);
    cout<<"The total time for 1 function  on "<<SIZE<<" elements = "
            <<end-beg<<" Seconds"<<endl;
    
    //Display Inputs/Outputs
    //prntAry(array,SIZE,10);
    //prntAry(brray,SIZE,10);

    //Exit the Program
    return 0;
}

void copyAry(int a[],int b[],int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}

void mrkSrt1(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void mrkSrt3(int a[],int n){
    for(int i=0;i<n-1;i++){
        smlLst(a,n,i);
    }
}

void smlLst(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i])swap1(a[pos],a[i]);
    }
}

//Logic Swap
void swap2(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}

//Memory Swap
void swap1(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillAry(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand();//[10-99]
    }
}