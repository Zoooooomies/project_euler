#include <iostream>
#include <numeric>       

using namespace std;

vector<int> fib_sequence(int limit) {
    int a = 1;
    int b = 1;
    
    vector<int> sequence = {a, b};

    while (true) {
        int new_sum = a + b;
        
        if (a + b > limit) {
            break;
        }
        
        sequence.push_back(new_sum);

        if (a > b) {
            b = new_sum;
        } else {
            a = new_sum;
        }
    }

    return sequence;
}

vector<int> remove_odds(vector<int> v) {
    vector<int> new_sequence = {};

    for (const int& i : v) {
        if (i % 2 == 0) {
            new_sequence.push_back(i);
        }
    }

    return new_sequence;
}

int main() {
    auto sequence = fib_sequence(4000000);
    auto filtered_sequence = remove_odds(sequence);
    auto result = reduce(filtered_sequence.begin(), filtered_sequence.end());

    cout << result << endl;

    return 0;
}