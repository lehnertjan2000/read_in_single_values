#include <iostream>
#include <exception>
#include <string>

// print some error message
void error(std::string message){
    std::cout << message << "\n";
    return;
}

// separate out the code for recovering after
// seeing a “bad” (i.e., unexpected) character
void skip_to_int()
{
    if (std::cin.fail()) {
        std::cin.clear();  // we found something that wasn’t an integer
                           // we’d like to look at the characters
        for (char ch; std::cin>>ch; ) { // throw away non-digits                
            if (isdigit(ch) || ch=='-') {
                std::cin.unget(); // put the digit back,
                                  // so that we can read the number
                return;
            }
        }
    }
    error("no input"); // eof or bad: give up
}


// get integer from input
int get_int()
{
    int n = 0;
    while (true) {
        if (std::cin >> n) return n;
        std::cout << "Sorry, that was not a number; please try again\n";
        skip_to_int();
    }
}

// use above get_int method in a certain range
int get_int(int low, int high)
{
    std::cout << "Please enter an integer in the range "
            << low << " to " << high << " (inclusive):\n";
    while (true) {
        int n = get_int();
        if (low<=n && n<=high) return n;
            std::cout << "Sorry "
            << n << " is not in the [" << low << ':' << high
            << "] range; please try again\n";
    }
}


int main(){
    int i = 0;
    i = get_int(1, 10);
    return 0;
}