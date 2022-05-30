#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cmath>
#include <numeric>
#define PI 3.14
using namespace std;



template<class T>
void insert_sorted2(vector<int>& v, const T& insert) {

	auto t = v.begin();
	t = upper_bound(v.begin(), v.end(), insert);
	v.insert(t, insert);
	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

float calculateSignal(vector<float>& aVec, vector<int>& dVec)
{
	return 0;
}

int main()
{


	setlocale(LC_ALL, "RU");


	vector<int>VectorContain{ 1,3,5,7,9 };

	vector<int>Vec{ 4 };
	auto it = Vec.begin();


	vector<float>FVec{ 6.1 };
	auto it2 = FVec.begin();

	list<int>Page{ 8 };
	auto it3 = Page.begin();





	cout << "Vector Withot Changes :" << endl;
	insert_sorted2(VectorContain, *it);
	cout << "Vector With float vector :" << endl;
	insert_sorted2(VectorContain, *it2);
	cout << "Vector With List Container :" << endl;
	insert_sorted2(VectorContain, *it3);






	vector<float>AnalogSignal;
	for (int i = 0; i < 100; i++) {
		AnalogSignal.push_back(round(sin(5 * PI * 0.01 * (i++)) * 1000) / 10);
	}

	vector<int>DigitalSignal(AnalogSignal.begin(), AnalogSignal.end());


	cout << "\n\n" << "Analog Signals" << endl;
	copy(AnalogSignal.begin(), AnalogSignal.end(), ostream_iterator<float>{cout, ", "});
	cout << "\n\n" << "Digital Signals" << endl;
	copy(DigitalSignal.begin(), DigitalSignal.end(), ostream_iterator<int>{cout, ", "});


	cout << "\n\n" << "Calculate Signal Error :" << inner_product(AnalogSignal.begin(), AnalogSignal.end(), DigitalSignal.begin(), 0.0, plus<float>{},
		[](float a, int b)
		{
			return pow(a - b, 2);
		});
}

