#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;
/* String functions section */

//involved once you consider separators as overlapping potentially
//have to make assumption that you will use the first instance
//or split the separators themselves after being used
//this all assumes the function may be used not as one would intend it to be
//delete these or correct them
// Splits a single string on separator into a vector of strings
std::vector<std::string> Split(std::string whole, std::string separator);

//more involved due to overlapping instances of s2
//eg. ebebebe removing ebe will leave you with not seeing the next instance
//delete these or correct them
// takes two strings and returns a new string that is the result of removing all occurrences of s2 from s1.
std::string RemoveAllSubstrings(std::string s1, std::string s2);

// takes two strings and returns a new string that is the result of removing the first occurrence of s2 from s1.
std::string RemoveFirstSubstring(std::string s1, std::string s2) {
	if(size(s2)==0){return s1;}
	string s3="";
	bool match=true;

	for(int i=0;i<(int)size(s1);i++) {
		if(match&&s1[i]==s2[0]) {
			string s4="";
			s4+=s1[i];

			i++;int j=1;
			while(i<(int)size(s1)&&j<(int)size(s2)&&s1[i]==s2[j]) {
				s4+=s1[i];
				i++;j++;
			}
			if(j==(int)size(s2)) {
				match=false;
			}else {
				s3+=s4;
			}
			if(i==(int)size(s1)) {
				return s3;
			}
		}
		s3+=s1[i];
	}
	return s3;
}

/* Vector functions section */

// Joins all strings in a vector together, using the glue string in between them
std::string Join(std::vector<std::string> pieces, std::string glue) {
	if(pieces.empty()){return "";}
	string res="";
	for(int i=0;i<(int)size(pieces)-1;i++) {
		res+=pieces[i]+glue;
	}
	return res+pieces.back();
}

// takes two vectors of integers, a and b. The function then removes elements from a if they are also in b.
// If the integer is in b, but not in a, nothing happens.
std::vector<int> MatchVectors(std::vector<int> a, std::vector<int> b) {
	unordered_set<int> bset={};
	for(auto&v:b) {
		bset.insert(v);
	}
	vector<int> res={};
	for(auto&v:a) {
		if(bset.count(v)){continue;}
		res.push_back(v);
	}
	return res;
}

// divides an input integer by 2 until it is impossible to do so, then returns the final number.
// (16 = 2 * 2 * 2 * 2 * 1 -> 1, 7 -> 7, 26 = 2 * 13 -> 13, 52 = 2 * 2 * 13 -> 13)
int RemoveTwos(int original) {
	while(!(original%2)) {
		original/=2;
	}
	return original;
}

// takes a vector of integers and removes all elements evenly divisible by the passed in int
std::vector<int> MultiplesFilter(std::vector<int> vec, int divides_by) {
	vector<int> res={};

	for(auto&v:vec) {
		if(v%divides_by) {
			res.push_back(v);
		}
	}
	return res;
}

// returns a vector with true for even numbers and false for odd numbers
std::vector<bool> EvenMask(std::vector<int> vec) {
	vector<bool> res(size(vec));
	for(int i=0;i<(int)size(vec);i++) {
		if(!vec[i]%2) {
			res[i]=true;
		}
	}
	return res;
}

// returns a vector with true for odd numbers and false for even numbers
std::vector<bool> OddMask(std::vector<int> vec) {
	vector<bool> res(size(vec));
	for(int i=0;i<(int)size(vec);i++) {
		if(vec[i]%2) {
			res[i]=true;
		}
	}
	return res;
}

// Sums all numbers in a vector and returns the resulting value
int Sum(std::vector<int> nums) {
	int sum=0;
	for(auto&v:nums) {
		sum+=v;
	}
	return sum;
}

// Multiplies all numbers in a vector together and returns the resulting value
int Product(std::vector<int> nums) {
	int prod=1;
	for(auto&v:nums) {
		prod*=v;
	}
	return prod;
}

// Adds an integer n to each element of a given vector
std::vector<int> VectorPlusN(std::vector<int> vec, int n) {
	for(auto&v:vec) {
		v+=n;
	}
	return vec;
}

// Multiples an integer n with each element of a given vector
std::vector<int> VectorTimesN(std::vector<int> vec, int n) {
	for(auto&v:vec) {
		v*=n;
	}
	return vec;
}

// takes in two integers and returns a vector of size n with
// values n*1, n*2, n*3... up to n*m
std::vector<int> Multiples(int n, int m) {
	vector<int> res(n);
	for(int i=1;i<=n;i++) {
		res[i-1]=n*m;
	}
	return res;
}

// takes an integer n that is >= 0 and returns a vector of all squares up to n^n (1^1, 2^2, 3^3, .... n^n)
std::vector<int> SquaresUntil(int n) {
	vector<int> res(n);
	for(int i=1;i<=n;i++) {
		res[i-1]=i*i;
	}
	return res;
}

// takes an int, n, and returns the nth value of the fibonacci sequence (1, 1, 2, 3, 5, 8, 13, ...)
int NthFibonacci(int n) {
	if(n<=2){return 1;}
	int prev=1,curr=1;
	n-=2;

	while(n) {
		prev=curr;
		curr=curr+prev;
		n--;
	}
	return curr;
}

// returns -1 if the number is negative and 1 if positive
int Sign(int num) {
	return -1*(-1*(num>=0));
}

// takes two vectors of doubles, a and b. The function then removes elements from a if they are also in b.
// If the double is in b, but not in a, nothing happens.
std::vector<double> MatchVectors(std::vector<double> a, std::vector<double> b) {
	unordered_set<double> bset={};
	for(auto&v:b) {
		bset.insert(v);
	}
	vector<double> res={};
	for(auto&v:a) {
		if(bset.count(v)){continue;}
		res.push_back(v);
	}
	return res;
}

// takes a vector of doubles and removes all elements evenly divisible by the passed in double
std::vector<double> MultiplesFilter(std::vector<double> vec, double divides_by) {
	vector<double> res={};

	for(double v:vec) {
		double w=v;
		while(w>0) {
			w-=divides_by;
		}
		if(w==0){res.push_back(v);}
	}
	return res;
}

// returns a vector with true for numbers greater than the second parameters and false for those less than or equal to
std::vector<bool> GreaterMask(std::vector<double> nums, double greater_than) {
	vector<bool> res(size(nums));

	for(int i=0;i<(int)size(nums);i++) {
		res[i]=(nums[i]>greater_than);
	}
	return res;
}

// returns a vector with true for numbers less than the second parameters and false for those greater than or equal to
std::vector<bool> LessMask(std::vector<double> nums, double less_than) {
	vector<bool> res(size(nums));

	for(int i=0;i<(int)size(nums);i++) {
		res[i]=(nums[i]<less_than);
	}
	return res;
}

// returns a vector with true for numbers greater than the second parameters and false for those less than or equal to
std::vector<bool> GreaterMask(std::vector<int> nums, int greater_than) {
	vector<bool> res(size(nums));

	for(int i=0;i<(int)size(nums);i++) {
		res[i]=(nums[i]>greater_than);
	}
	return res;
}

// returns a vector with true for numbers less than the second parameters and false for those greater than or equal to
std::vector<bool> LessMask(std::vector<int> nums, int less_than) {
	vector<bool> res(size(nums));

	for(int i=0;i<(int)size(nums);i++) {
		res[i]=(nums[i]<less_than);
	}
	return res;
}

// Sums all numbers in a vector and returns the resulting value
double Sum(std::vector<double> nums) {
	double sum=0;
	for(auto&v:nums) {
		sum+=v;
	}
	return sum;
}

// Multiplies all numbers in a vector together and returns the resulting value
double Product(std::vector<double> nums) {
	double mult=0;
	for(auto&v:nums) {
		mult*=v;
	}
	return mult;
}

// Multiples an double n with each element of a given vector
std::vector<double> VectorTimesN(std::vector<double> vec, double n) {
	for(auto&e:vec) {
		e*=n;
	}
	return vec;
}

// takes in two doubles and returns a vector of size n with
// values n*1, n*2, n*3... up to n*m
std::vector<double> Multiples(double n, double m) {
	vector<double> res(m);

	for(int i=1;i<=m;i++) {
		res[i-1]=n*i;
	}
	return res;
}

// returns -1 if the number is negative and 1 if positive
double Sign(double num) {
	return -1*(-1*(num>=0));
}

// adds n to each element of the vector
std::vector<double> AddN(std::vector<double> vec, double n) {
	for(auto&e:vec) {
		e+=n;
	}
	return vec;
}

// adds n to each element of the vector
std::vector<std::string> AddN(std::vector<std::string> vec, std::string n) {
	for(auto&str:vec) {
		str+=n;
	}
	return vec;
}

// subtracts n to each element of the vector
std::vector<int> SubtractN(std::vector<int> vec, int n) {
	for(auto&e:vec) {
		e-=n;
	}
	return vec;
}

// subtracts n to each element of the vector
std::vector<double> SubtractN(std::vector<double> vec, double n) {
	for(auto&e:vec) {
		e-=n;
	}
	return vec;
}

// ====================================================================

// takes an int, n, and returns the factorial of that int (n!)
int Factorial(int n)
{
	if(n>1)
		return n*Factorial(n-1);
	else
		return 1;
}

// adds n to each element of the vector
std::vector<int> AddN(std::vector<int> v, int n)
{
	for(int i=0;i<(int)v.size();i++)
	{
		v[i]+=n;
	}
	return v;
}

// ====================================================================

// int main()
// {
// 	std::cout << Factorial (5) <<std::endl; // printing the value
// 	// assert(Factorial(0) == 1) // cassert
// 	std::vector<int> v{1,2,3};
// 	std::vector<int> res = AddN(v, 5);
// 	for(int i=0;i<(int)res.size();i++)
// 	{
// 		std::cout<<res[i]<<" ";
// 	}
// }
