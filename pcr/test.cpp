#include "character.hpp"
#include<vector>
#include<iostream>

using namespace PCR;
using namespace std;

class Miyako: public Charactor {
    public:
        explicit Miyako(float h, float t)
            : Charactor(h, t) { ex(); }
        void skill(std::vector<Charactor*>& team) {
            for (auto x : team)
                x->max_hp+=1;
        }
        private:
            void ex() {  
                if (rank > 6)
                    max_hp += 1; }
};

int main() {
    Miyako miyako {2,2};
    vector<Charactor*> team { &miyako };
    cout << "max_hp: " << miyako.max_hp << endl;
    miyako.skill(team);
    cout << "skill haziduo: " << endl;
    cout << "max_hp: " << miyako.max_hp << endl;
    // cout << "max_tp: " << miyako.max_tp << endl;
}
