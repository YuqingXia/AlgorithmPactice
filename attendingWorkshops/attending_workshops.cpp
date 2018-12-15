#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


struct Workshop {
    int start_time;
    int duration;
    int end_time;
	static bool start_time_compare(Workshop * w1, Workshop * w2){
		return w1 -> start_time < w2 -> start_time;
	}
};


struct Available_Workshops {
    int n;
    vector<Workshop *> workshops;
	
	~Available_Workshops(){
		for(auto p : this -> workshops) delete p;
		workshops.clear();
	}
};


Available_Workshops * initialize(int * start_time, int * duration, int n){
	Available_Workshops * ptr = new Available_Workshops();
	ptr -> n = n;
	ptr -> workshops.resize(n);

	for(size_t i = 0; i < n; ++i){
		Workshop * p = new Workshop();
		p -> start_time = start_time[i];
		p -> duration = duration[i];
		p -> end_time = p -> start_time + p -> duration;
		ptr -> workshops[i] = p;	
	}

	sort( (ptr -> workshops).begin(), (ptr -> workshops).end(), Workshop::start_time_compare);

	return ptr;	
}


int CalculateMaxWorkshops(Available_Workshops * ptr){
	int max_workshop(0);
	
	if(ptr -> n == 0) return max_workshop;
	
	auto prev_workshop = ptr -> workshops.begin();
	auto next_workshop = ptr -> workshops.begin();
	auto end_workshop = ptr -> workshops.end();

    ++max_workshop;
	++next_workshop;

	while(next_workshop != end_workshop){
		if( (*prev_workshop) -> end_time <= (*next_workshop) -> start_time){
			//add currernt workshop
			++max_workshop;
			prev_workshop = next_workshop;
		}else if( (*prev_workshop) -> end_time <= (*next_workshop) -> end_time){
			//discard current workshop	
			;
		}else{
			//replace previous workshop with current one
			prev_workshop = next_workshop;
		}
		
		++next_workshop;
	}
	
	return max_workshop;
}


int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;

	delete[] start_time;
	delete[] duration;

    return 0;
}
