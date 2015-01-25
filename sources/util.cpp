#include <vector>
#include "util.h"
#include "atoms.h"

using namespace std;

void print(FILE *out, const PropTerm &prop_term, bool print_new_line) {
    vector<int> id_atoms;
    for (size_t i = 0; i < prop_term.literals.size(); ++ i)
        if (prop_term.literals[i])
            id_atoms.push_back(i);
    if (id_atoms.empty())
        return ;
    fprintf(out, "(%s%s", (id_atoms[0] % 2 ? "~" : ""),
            Atoms::instance().get_atom_string(id_atoms[0] / 2 + 1).c_str());
    for (size_t i = 1; i < id_atoms.size(); ++ i)
        fprintf(out, " & %s%s", (id_atoms[i] % 2 ? "~" : ""),
                Atoms::instance().get_atom_string(id_atoms[i] / 2 + 1).c_str());
    fprintf(out, ")");
    if (print_new_line)
        fprintf(out, "\n");
}

void print(FILE *out, const PropDNF &prop_dnf, bool print_new_line) {
    if (prop_dnf.prop_terms.empty())
        return ;
    fprintf(out, "( ");
    print(out, *prop_dnf.prop_terms.begin());
    for (list<PropTerm>::const_iterator it = (++ prop_dnf.prop_terms.begin());
            it != prop_dnf.prop_terms.end(); ++ it) {
        fprintf(out, " | ");
        print(out, *it);
    }
    fprintf(out, " )");
    if (print_new_line)
        fprintf(out, "\n");
}

void print(FILE *out, const EpisTerm &epis_term, bool print_new_line) {
    fprintf(out, "K");
    print(out, epis_term.pos_propDNF);
    if (! epis_term.neg_propDNFs.empty()) {
        for (list<PropDNF>::const_iterator it = epis_term.neg_propDNFs.begin();
                it != epis_term.neg_propDNFs.end(); ++ it) {
            fprintf(out, " | ~K~");
            print(out, *it);
        }
    }
    if (print_new_line)
        fprintf(out, "\n");
}

void print(FILE *out, const EpisDNF &dnf) {
    for (list<EpisTerm>::const_iterator it = dnf.epis_terms.begin();
            it != dnf.epis_terms.end(); ++ it) {
        print(out, *it, true);
    }
}