#include <iostream>
#include <vector>

/*

This program can solve the games passwords and morse code in "Keep talking and nobody explodes" 

problem is i dont even know the game anymore

*/

// Function Declarations
// IO
void print1DVector(std::vector<std::string>);
void print2DVector(std::vector<std::vector<std::string>>);
std::vector<std::string> getInput();

// PW
std::vector<std::string> calculatePW(std::vector<std::string>); 

// Morse Code
std::vector<std::vector<std::string>> calculateMorseCode(std::vector<std::string>);


// Variables
std::vector<std::string> pwWords = {
	"about",    "after",    "again",	"below",	"could",
	"every",	"first",	"found",	"great",	"house",
	"large",	"learn",	"never",	"other",	"place",
	"plant",	"point",	"right",	"small",	"sound",
	"spell",	"still",	"study",	"their",	"there",
	"these",	"thing",	"think",	"three",	"water",
	"where",	"which",	"world",	"would",	"write" 
};

std::vector<std::vector<std::string>> morseCodeWords = {

	{"shell",  "3.505"},
	{"halls",  "3.515"},
	{"slick",  "3.522"},
	{"trick",  "3.532"},
	{"boxes",  "3.535"},
	{"leaks",  "3.542"},
	{"strobe", "3.545"},
	{"bistro", "3.552"},
	{"flick",  "3.555"},
	{"bombs",  "3.565"},
	{"break",  "3.572"},
	{"brick",  "3.575"},
	{"steak",  "3.582"},
	{"sting",  "3.592"},
	{"vector", "3.595"},
	{"beats",  "3.600"}

}; 

std::vector<std::vector<std::string>> morseCodeAlphabet = {

	{".-",   "a"},
	{"-...", "b"},
	{"-.-.", "c"},
	{"-..",  "d"},
	{".",    "e"},
	{"..-.", "f"},
	{"--.",  "g"},
	{"....", "h"},
	{"..",   "i"},
	{".---", "j"},
	{"-.-",  "k"},
	{".-..", "l"},
	{"--",   "m"},
	{"-.",   "n"},
	{"---",  "o"},
	{".--.", "p"},
	{"--.-", "q"},
	{".-.",  "r"},
	{"...",  "s"},
	{"-",    "t"},
	{"..-",  "u"},
	{"...-", "v"},
	{".--",  "w"},
	{"-..-", "x"},
	{"-.--", "y"},
	{"--..", "z"}

};




// Functions
int main() {

	char input = ' '; 

	while (input != 'x' && input != '0') {
		std::cout << "\n\n\n1 = Password\n2 = Morse Code\n0 = exit\n\n";
		std::cin >> input;

		if (input == '1') {
			std::vector<std::string> inp = getInput();
			print1DVector(calculatePW(inp));
		}

		if (input == '2') {
			std::vector<std::string> inp = getInput();
			print2DVector(calculateMorseCode(inp));
		}

	}


	return 0;
}


// Output
void print1DVector(std::vector<std::string> v) {
	std::cout << std::endl;

	std::cout << "Size: " << v.size() << std::endl << "Output: "; 

	for (std::string s : v) {
		std::cout << s << "  "; 
	}
	std::cout << std::endl; 
}

void print2DVector(std::vector<std::vector<std::string>> v2) {

	std::cout << "Size: " << v2.size() << std::endl << "\nOutput: "; 

	for (std::vector<std::string> v : v2) {
		std::cout << std::endl; 
		for (std::string s : v) {
			std::cout << s << " - "; 
		}
	}
	std::cout << std::endl; 
}



// Input
std::vector<std::string> getInput() {

	std::cout << std::endl; 

	std::vector<std::string> inp;
	bool running = true;

	while (running) {
		inp.push_back("");
		std::cout << "Input: ";
		std::cin >> inp[inp.size() - 1];

		if (inp[inp.size() - 1] == "xxx") {
			running = false;
			inp.pop_back();
		}
	}

	std::cout << "\nVector2D Size: " << inp.size() << "\n" << std::endl;

	return inp; 
}


// Password
std::vector<std::string> calculatePW(std::vector<std::string> inp) {

	std::vector<std::string> words = pwWords;

	for (int i = 0; i < inp.size(); i++) {
		for (int i2 = 0; i2 < words.size(); i2++) {
			bool valid = false;
			for (int i3 = 0; i3 < inp[i].size(); i3++) {
				if (words[i2][i] == inp[i][i3]) {
					valid = true;
				}
			}

			if (!valid) {
				words.erase(words.begin() + i2);
				i2--;
			}

		}
	}

	return words;
}


// Morse Code
std::vector<std::vector<std::string>> calculateMorseCode(std::vector<std::string> inp) {
	
	std::vector<std::string> out; 
	std::string building = "";

	for (int i = 0; i < inp.size(); i++) {
		for (int i2 = 0; i2 < morseCodeAlphabet.size(); i2++) {
			if (morseCodeAlphabet[i2][0] == inp[i]) {
				building += morseCodeAlphabet[i2][1]; 
				break; 
			}
		}
	}

	//std::cout << building << "  <- Building  " << std::endl; 

	std::vector<std::vector<std::string>> copy = morseCodeWords; 

	for (int i = 0; i < building.size(); i++) {
		for (int i2 = 0; i2 < copy.size(); i2++) {
			if (building[i] != copy[i2][0][i]) {
				copy.erase(copy.begin() + i2); 
				i2--; 
			}
		}
	}


	return copy; 
}

/*

morseCodeAlphabet durch unordered map erstezen

*/