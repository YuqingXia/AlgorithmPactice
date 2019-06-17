#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	deque< int > dq;

    size_t max_idx(0);
    int max_val(arr[0]);
    dq.push_back(arr[0]);
    if(k==1) cout << arr[0] << " "; 

    for(int i=1; i<n; ++i){
        if(dq.size() > k-1){
            dq.pop_front();
            --max_idx;
            if(max_idx < 0){ //max value moved out
                max_idx = dq.size(); //
            }
        }

        if(dq.size() == k){
            cout << max_val << " ";
        }

        dq.push_back(arr[i]);

        if(arr[i] >= max_val){
            max_val = arr[i];
            max_idx = dq.size() - 1;
        }
        
        
    }

    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

