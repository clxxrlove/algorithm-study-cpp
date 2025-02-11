//
//  main.cpp
//  1152
//
//  Created by 정지용 on 12/30/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

string ltrim(const string& s) {
    auto start = find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    });
    return string(start, s.end());
}

string rtrim(const string& s) {
    auto end = find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base();
    return string(s.begin(), end);
}

vector<string> split(const string& s, string delimiter) {
    vector<string> result;
    
    size_t start = 0;
    size_t end = s.find(delimiter);
    
    while (end != string::npos) {
        result.push_back(s.substr(start, end - start));
        start = end + delimiter.size();
        end = s.find(delimiter, start);
    }
    
    result.push_back(s.substr(start));
    
    return result;
}

int main(int argc, const char * argv[]) {
    string input;
    getline(cin, input);
    
    cout << split(ltrim(rtrim(input)), " ").size();
    
    return 0;
}
