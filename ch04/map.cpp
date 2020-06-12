#include<vector>
#include<map>
#include<string>
#include<utility>
#include<iostream>
using std::vector, std::map, std::string, std::cout, std::endl, std::size_t;

map<string, vector<string> > adjacentWords(vector<string> words) {
    map<size_t, vector<string> > lengthMap {};
    for (const auto& word : words)
        lengthMap[word.length()].push_back(word);
}

int main() {
    vector<string> words {"foot", "fool", "food", "root", "his", "him", "vim", "he", "me"};
    map<size_t, vector<string> > lengthMap {};
    for (const auto& word : words)
        lengthMap[word.length()].push_back(word);
    for ( const auto& pair: lengthMap) {
        cout << pair.first << ": ";
    }

}

