#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.;
        if(n == 1) return x;
        double eps(1e-16);
        if(fabs(x) < eps) return 0.;
        if(fabs(x - 1.0) < eps) return 1.0;

        int n2 = n / 2;
        double res = myPow(x, n2);
        return (n % 2 == 0)? res * res : res * res * ((n > 0)? x:1 / x);
    }
};


int main(int argc, char * argv[] ) {
    if(argc <= 1){
        cout << "Input file is expected" << endl;
        return -1;
    }

    ifstream infile(argv[1]);
   
    float x; 
    int n; 
    float result;
    float ret;
    float eps(1e-16);
    Solution solution;
    while(infile.is_open() && infile.good() && !infile.eof()){
        infile >> x >> n >> result; 
        ret = solution.myPow(x, n);
        cout << "pow(" << x << ", "<< n << " ) = " << ret << " expected " << result;
        
        if( fabs(ret - result) < eps ){
            cout << " correct" << endl;
        }else{
            cout << " error" << endl; 
        }
    }

}
