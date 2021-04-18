#include <bits/stdc++.h>

using namespace std;

class Complex{
    public:
        double real;
        double imaginary;

        Complex(){
            real=0.0;
            imaginary=0.0;
        }

        Complex(double pReal, double pImaginary){
            real=pReal;
            imaginary=pImaginary;
        }

        double norm();

};

double Complex::norm(){
    return (double)sqrt(real*real+imaginary*imaginary);
}

int main(){
    int n;
    double pReal, pImaginary, minNorm;
    int minIndex;
    vector<Complex> myNumbers;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>pReal>>pImaginary;
        myNumbers.push_back(Complex(pReal, pImaginary));
    }

    int i=0;
    minNorm=myNumbers.at(i).norm();
    minIndex=i;
    i++;

    while(i<n){
        if(myNumbers.at(i).norm()<minNorm){
            minNorm=myNumbers.at(i).norm();
            minIndex=i;
            break;
        }
        i++;

    }

    cout<<fixed<<setprecision(1)<<myNumbers.at(minIndex).real;
    cout<<" "<<fixed<<setprecision(1)<<myNumbers.at(minIndex).imaginary;

    return 0;
}
