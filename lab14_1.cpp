#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

double M(const double s[],int n){
    double sum = 0;
    for(int i=0; i < n; i++){
        sum += s[i];
    }
    return sum/n;
}

double SD(const double s[],int n){
    double sum = 0;
    double sd;
    for(int i = 0;i<n;i++){
        sum += pow(s[i],2);
    }
    sd = sqrt((sum/n)-(pow(M(s,n),2)));
    return sd;
}
 
double GM(const double s[],int n){
    double x = 1;
    for(int i = 0;i<n;i++){
        x *= s[i];
    }
    return pow(x,(double)1/n);
}

double HM(const double s[],int n){
    double x = 0;
    for (int i = 0; i < n; i++)
        x = x + (double)1 / s[i];
 
    return (double)n/x;
}

double Max(const double s[],int n){
    double max = s[0];
    for (int i = 0; i < n; i++)
        if(s[i]>max) max =s[i];
 
    return max;
}

double Min(const double s[],int n){
    double min = s[0];
    for (int i = 0; i < n; i++)
        if(s[i]<min) min =s[i];
 
    return min;
}

 
void stat(const double A[],int N,double B[]){
    B[0] = M(A,N);
    B[1] = SD(A,N);
    B[2] = GM(A,N);
    B[3] = HM(A,N);
    B[4] = Max(A,N);
    B[5] = Min(A,N);
}