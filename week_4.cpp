#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include <algorithm>
#include <numeric>

std::ostream& operator << (std::ostream& os, std::vector<int> vec) {
	
	std::string numbers;

	for (size_t i = 0; i < vec.size(); ++i) {
		numbers +=  (' ' + std::to_string(vec[i]) + ',') ;
	}
	

	return os << "{" << numbers << " }";
}

int main() {



	using namespace std;

	srand(static_cast<unsigned int>(time(0)));


	//-------------------------------------------------------------
	const size_t N = 5;

	vector<int> v1(N);

	cout << "0. just created" << v1 << endl;

	//-------------------------------------------------------------

	for (size_t i = 0; i < v1.size(); ++i)
	{
		v1[i] = rand() % 100;

	}

	cout << "1. filled the sequence: " << v1 << endl;

	//-------------------------------------------------------------

	cout << "eneter 3 numbers " << endl;
	for (int i = 0; i < 3; ++i) {
		int a;
		cin >> a;
		v1.push_back(a);
	}

	cout << "2. added extra values: " << v1 << endl;


	//-------------------------------------------------------------
	random_device rd;
	std::mt19937 g(rd());

	shuffle(v1.begin(), v1.end(), g);
	cout << "3. shuffled the sequence: " << v1 << endl;

	//-------------------------------------------------------------



	for (auto i = v1.begin(); i < v1.end(); ++i) {


		for (auto j = v1.end() - 1; j > i; --j) {


			if (*i == *j) {

				j = v1.erase(j);

			}

		}

	}


	cout << "4. deleted duplicates: " << v1 << endl;



	//-------------------------------------------------------------
	cout << "5. number of odd numbers: " << count_if(v1.begin(), v1.end(), [](int i) {return i % 2 != 0;}) << endl;

	//-------------------------------------------------------------
	cout << "6. max: " << *max_element(v1.begin(), v1.end()) << " min: " << *min_element(v1.begin(), v1.end()) << endl;

	//-------------------------------------------------------------
	cout << "7. no " << endl;
	
	//-------------------------------------------------------------

	for (size_t i = 0; i < v1.size(); ++i) {
		v1[i] *= v1[i];
	}

	cout << "8. squares: " << v1 << endl;

	//-------------------------------------------------------------

	vector<int> v2(v1.size());

	for (size_t i = 0; i < v2.size(); ++i)
	{
		v2[i] = rand() % 100;

	}

	cout << "9. filled thesecond  sequence: " << v2 << endl;

	//-------------------------------------------------------------
	 
	std::cout << "10. sum of second sequence: " << accumulate(v2.begin(), v2.end(), 0, [](int sum, int elem) {return sum + elem;}) << endl;;

	//-------------------------------------------------------------

	for (auto i = 0; i < v2.size() / 3; i++) v2[i] = 1;

	cout << "11. replaced some first element of v2 with 1: " << v2 << endl;

	//-------------------------------------------------------------

	vector<int> v3(v1.size());
	for (auto i = 0; i < v1.size(); i++) v3[i] = -v2[i] + v1[i];

	cout << "12. v3 as th difference between v2 and v1:" << v3 << endl;

	//-------------------------------------------------------------

	for (auto i = 0; i < v1.size(); i++) 
	{
		if (v3[i] < 0) v3[i] = 0;
	};

	cout << "13. replaced negative values with 0: " << v3 << endl;

	//-------------------------------------------------------------

	v3.erase(std::remove_if(v3.begin(),
		v3.end(),
		[](int x) {return x == 0;}), v3.end());

	cout << "14. removed all 0 in v3: " << v3 << endl;

	//-------------------------------------------------------------

	for (int i = 0; i < v3.size() / 2; i++) {
		swap(v3[i], v3[v3.size() - 1 - i]);
	}

	cout << "15. reversed order of v3;" << v3 << endl;

	//-------------------------------------------------------------


	int a1 = 0;
	int a2 = 0;
	int a3 = 0;

	for (int i = 0; i < v3.size(); i++) {

		if (v3[i] > a1) {
			a1 = v3[i];
			a2 = a1;
			a3 = a2;
		}
		else if (v3[i] > a2) {
			a2 = v3[i];
			a3 = a2;
		}
		else if (v3[i] > a3) {
			a3 = v3[i];
		}
	}

	cout << "16: top-3 elements of v3:" << a3 << ' ' << a2 << ' ' << a3 << endl;

	//-------------------------------------------------------------

	sort(v1.begin(), v1.end(), [](int a, int b) {return a < b;});
	sort(v2.begin(), v2.end(), [](int a, int b) {return a < b;});

	cout << "17. \nsorted v1: " << v1 << endl << "sorted  v2" << v2 << endl;

	//-------------------------------------------------------------

	vector<int> v4(v1.size() + v2.size());
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < v1.size() && j < v2.size()) {

		if (v1[i] <= v2[j]) {
			v4[k++] = v1[i++];

		}
		else {
			v4[k++] = v2[j++];
		}

	}

	while (i < v1.size()) {
		v4[k++] = v1[i++];
	}

	while (i < v2.size()) {
		v4[k++] = v2[j++];
	}
	
	cout << "18. v4 as merged v1 and v2" << v4 << endl;

	//-------------------------------------------------------------

	auto start = find_if(v4.begin(), v4.end(), [](int elem) {return elem == 1;});
	auto end = find_if(v4.begin(), v4.end(), [](int elem) {return elem > 1;});

	cout <<"19. " << distance(v4.begin(), start) << ' ' << distance(v4.begin(), end) - 1<< endl;

	//-------------------------------------------------------------

	cout << "20.\n v1: " << v1 << "\n v2: " << v2 << "\n v3: " << v3 << "\n v4: " << v4;
}






