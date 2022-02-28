
// variant 8

#include <cstdio>
#include <cstdlib>
#include <stack>
#include "../a.h"

using namespace std;

namespace aab {

const unsigned ln = 4;

struct pt {
    const int e, n;
    pt(int e, int n) : e(e), n(n) {}
};

const pt mt[ln][ln] = {
        { pt(5, 0), pt(7, 0), pt(8, 0), pt(0, 0) },
        { pt(3, 5), pt(2, 6), pt(5, 7), pt(0, 6) },
        { pt(5, 2), pt(7, 4), pt(9, 5), pt(0, 4) },
        { pt(4, 3), pt(6, 2), pt(7, 5), pt(0, 2) }
};

const int lg = ln - 1;

const char ee = 'e';
const char nn = 'n';
const char nl = '_';

struct nd {
    char wh;
    unsigned x, y;
    nd** ns;
    unsigned nl;
    nd* pr = 0;
    int lv = 0;

    nd(char wh, unsigned y, unsigned x, nd* pr, int lv)
        : wh(wh), y(y), x(x), ns(0), nl(0), pr(pr), lv(lv)
    {}

    nd* dd(nd* a) {
        ns = (nd**) realloc(ns, sizeof(nd*) * ++nl);
        ns[nl - 1] = a;
        return this;
    }

    void prt(unsigned& b, unsigned a = 0) const {
        if (wh != nl) {
            for (unsigned i = 0; i < a; i++)
                printf("  ");
            printf("%c\n", wh);

            if (!nl) b++;
        }
        for (unsigned i = 0; i < nl; i++)
            ns[i]->prt(b, wh != nl ? a + 1 : a);
    }

    nd* fnd(unsigned _y, unsigned _x) {
        if (_y == y and _x == x) return this;
        nd* b = 0;
        for (unsigned i = 0; i < nl; i++)
            b = ns[i]->fnd(_y, _x);
        return b;
    }

    unsigned cnt() {
        unsigned a = 0;
        nd* b = this;

        while (b->pr) {
            printf("%c(%d %d)_%d     ", b->wh, b->y, b->x, b->lv);
            a += b->lv;
            b = b->pr;
        }
        return a;
    }

    void shp(unsigned& a, unsigned b = 0) {
        if (pr and !nl) {
            b = cnt();
            printf("\n");

            if (b < a)
                a = b;
        }
        for (unsigned i = 0; i < nl; i++)
            ns[i]->shp(a);
    }
};

stack<unsigned> st;

void prc(nd*& n, unsigned& c, char d, int y = lg, int x = 0, unsigned* s = 0) {
    if (!s) s = new unsigned();

    int vl = d == ee ? mt[y][x - 1].e : mt[y + 1][x].n;
    (*s) += vl;

    if (d != nl) c++;
    printf("%d %d %c, %u %d %u\n", y, x, d, c, vl, !st.empty() ? st.top() : 0);
    if (d == nl) printf("%u\n", *s);

    if (!n) {
        if (d != nl) throw 1;
        n = new nd(d, y, x, 0, vl);
    } else {
        nd* a = 0;
        if (d == ee)
            a = n->fnd(y, x - 1);
        else
            a = n->fnd(y + 1, x);

        if (!a) a = n;
        a->dd(new nd(d, y, x, a, vl));
    }

    if (y == 0 and x == lg) {
        printf("= %u %u\n", *s, st.top());
        *s = 0;
        return;
    }

    st.push(*s);

    if (x < lg)
        prc(n, c, ee, y, x + 1, s);

    if (y > 0)
        prc(n, c, nn, y - 1, x, s);

    st.pop();
}

};

void lnch15() {
    using namespace aab;
    unsigned c = 0;
    nd* a = 0;
    prc(a, c, nl);

    printf("#-----\n");

    unsigned d = 0;
    a->prt(d);
    printf("%u\n", d);

    d = 1 << 31;
    a->shp(d);
    printf("%u\n", d);
}
