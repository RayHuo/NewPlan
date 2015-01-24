#include <vector>
#include "util.h"

using namespace std;

void print(FILE *out, const PropTerm &prop_term) {
    vector<int> id_atoms;
    for (size_t i = 0; i < prop_term.literals.size(); ++ i)
        if (prop_term.literals[i])
            id_atoms.push_back(i);
    if (id_atoms.empty())
        return ;
    fprintf(out, "%d", id_atoms[0]);
    for (size_t i = 1; i < id_atoms.size(); ++ i)
        fprintf(out, " & %d", id_atoms[i]);
    fprintf(out, "\n");
}
