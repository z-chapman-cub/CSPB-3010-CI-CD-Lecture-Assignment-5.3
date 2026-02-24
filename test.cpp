#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>
using namespace std;

//My Test Cases---------------------------------------
//In order from top function in functions_to_implement.cpp downward to the original two given implementations

//STRING FUNCTIONS
//String Function 1
TEST_CASE("removing the FIRST occurrence of one string from another","RemoveFirstSubstring") {
	string s1="thereisatimeandaplaceforeverythingwithaplaceandatimeisthere";

	SECTION("substring in center") {
		string s2="place";
		string res=RemoveFirstSubstring(s1,s2);
		REQUIRE(res=="thereisatimeandaforeverythingwithaplaceandatimeisthere");
	}
	SECTION("substring at start") {
		string s2="there";
		string res=RemoveFirstSubstring(s1,s2);
		REQUIRE(res=="isatimeandaplaceforeverythingwithaplaceandatimeisthere");
	}
	SECTION("substring at end") {
		string s2="isthere";
		string res=RemoveFirstSubstring(s1,s2);
		REQUIRE(res=="thereisatimeandaplaceforeverythingwithaplaceandatime");
	}
	SECTION("substring as s1") {
		string s2="thereisatimeandaplaceforeverythingwithaplaceandatimeisthere";
		string res=RemoveFirstSubstring(s1,s2);
		REQUIRE(size(res)==0);
	}
	SECTION("empty substring") {
		string s2="";
		string res=RemoveFirstSubstring(s1,s2);
		REQUIRE(res=="thereisatimeandaplaceforeverythingwithaplaceandatimeisthere");
	}
}

//String Function 2
TEST_CASE("joining the strings in a vector into one string with glue string in between each","[Join]") {
	vector<string> pieces={"hoof","mane","legs","nostrils","tail","body","ears"};

	SECTION("testing with a glue string") {
		string glue="and";
		string res=Join(pieces,glue);
		REQUIRE(res=="hoofandmaneandlegsandnostrilsandtailandbodyandears");
	}
	SECTION("testing with empty glue string") {
		string glue="";
		string res=Join(pieces,glue);
		REQUIRE(res=="hoofmanelegsnostrilstailbodyears");
	}
	SECTION("testing with empty vector") {
		string glue="or";
		REQUIRE_NOTHROW(Join({},glue));
	}
}

//VECTOR-BASED FUNCTIONS
//Vector Function 1
TEST_CASE("remove integers in b from a but not vice versa and return a","[MatchVectors]") {
	vector<int> a={1,3,5,7,9,2,4,6,8};

	SECTION("remove a few values in a") {
		vector<int> b={3,5,7,4};
		vector<int> res=MatchVectors(a,b);
		REQUIRE(size(res)==size(a)-4);
		REQUIRE(res[1]==9);
		REQUIRE(res[3]==6);
		REQUIRE(res[4]==8);
	}
	SECTION("remove a random value in a from a") {
		srand(time(NULL));
		vector<int> b{rand()%8+1};
		vector<int> res=MatchVectors(a,b);
		REQUIRE(size(res)==size(a)-1);
	}
	SECTION("remove some values in a and some not in a") {
		vector<int> b{1,9,8,10,-2};
		vector<int> res=MatchVectors(a,b);
		REQUIRE(size(res)==size(a)-3);
		REQUIRE(res[1]==5);
		REQUIRE(res[3]==2);
		REQUIRE(res[5]==6);
	}
	SECTION("remove values not in a only") {
		vector<int> b{-5,11,-3,12};
		vector<int> res=MatchVectors(a,b);
		REQUIRE(size(res)==size(a));
	}
	SECTION("remove every value in a") {
		vector<int> b{5,4,6,8,7,9,1,3,2};
		vector<int> res=MatchVectors(a,b);
		REQUIRE(size(res)==0);
	}
	SECTION("remove every value and attempt to remove some not in a") {
		vector<int> b{5,4,-3,6,8,10,7,9,-2,1,3,2};
		REQUIRE_NOTHROW(MatchVectors(a,b));
	}
	SECTION("remove no values") {
		vector<int> b{};
		vector<int> res=MatchVectors(a,b);
		REQUIRE(size(res)==size(a));
	}
}

//Vector Function 2
TEST_CASE("subtracting values in integer vector", "[SubtractN]")
{
	std::vector<int> v{1,2,3,5,6,7,8,10};

	SECTION("subtracting five - integer"){
		int n=5;
		std::vector<int> res=SubtractN(v,n);
		srand(time(NULL));
		int r=rand()%v.size();
		REQUIRE(v.size()==res.size());
		REQUIRE(res[0]==-4);
		REQUIRE(res[v.size()-1]==5);
		REQUIRE(res[r]==v[r]-n);
	}
	SECTION("subtracting negative five - integer"){
		int n=-5;
		std::vector<int> res=SubtractN(v,n);
		srand(time(NULL));
		int r=rand()%v.size();
		REQUIRE(v.size()==res.size());
		REQUIRE(res[0]==6.0);
		REQUIRE(res[v.size()-1]==15.0);
		REQUIRE(res[r]==v[r]-n);
	}
	std::vector<double> w{1,2,3,5,6,7,8,10};

	SECTION("subtracting five - double"){
		double n=5;
		std::vector<double> res=SubtractN(w,n);
		srand(time(NULL));
		double r=rand()%w.size();
		REQUIRE(w.size()==res.size());
		REQUIRE(res[0]==-4);
		REQUIRE(res[w.size()-1]==5);
		REQUIRE(res[r]==w[r]-n);
	}
	SECTION("subtracting negative five - double"){
		double n=-5;
		std::vector<double> res=SubtractN(w,n);
		srand(time(NULL));
		double r=rand()%w.size();
		REQUIRE(w.size()==res.size());
		REQUIRE(res[0]==6);
		REQUIRE(res[w.size()-1]==15);
		REQUIRE(res[r]==w[r]-n);
	}
	SECTION("empty arg"){
		REQUIRE_NOTHROW(SubtractN({},0));
		REQUIRE_NOTHROW(SubtractN({},0.0));
	}
}

//Originally Included Test Cases---------------------------------
TEST_CASE ( "Factorials are computed", "[factorial]") // tag
{
  CHECK( Factorial(0) == 1 ); // assertion
  REQUIRE( Factorial(1) == 1 );
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE("incrementing values in integer vector", "[addN]")
{
	std::vector<int> v{1,2,3,5,6,7,8,10};

	SECTION("+ve n")
  {
		int n=5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == 6 );
		REQUIRE( res[v.size()-1] == 15 );
		REQUIRE(res[random] == v[random]+n);
	}
	SECTION("-ve n")
  {
		int n=-5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == -4 );
		REQUIRE( res[v.size()-1] == 5 );
		REQUIRE(res[random] == v[random]+n);
	}
}
