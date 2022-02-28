
// variant 3

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define _nn [[gnu::nonnull]]
#define _nl _Nullable
#define _nd [[nodiscard]]
#define _th noexcept(0)
#define _pr [[gnu::pure]]

#define _sch(x)     \
    class x final { \
    private:        \
        x() {}      \
        ~x() {}     \
    public:

typedef char* ss;
typedef char const* cs;
typedef const int ci;
typedef int* inp;

///////////////////////////////

static ci 
        ssn = 10, 
        sbf = 10, 
        stf = 64, 
        sc  = sizeof(char),
        spp = sizeof(ss);

///////////////////////////////

_sch(cl)
private:
    static inline ss* st = 0;
    static inline int sz = 0;

#   define nwc new char[sbf];

public:

    static void nt(_nn cs s) {
        int a = 0, b = 0, d = 0;
        ss c = nwc

        while ((a = s[b])) {
            if (a == ' ' or a == '\0') {
                c[d+1] = '\0';

                d = 0;
                st = (ss*) 
                    realloc(st, (sz + 1) * spp);
                
                st[sz] = c;
                sz++;

                c = nwc
            } else {
                c[d] = a;
                d++;
            }
            b++;
        }
    }

    ///////////////////////////////

    _pr _nd static ss _nl fn() {
        ss a = 0, b = 0;
        for (int i = 0, j = 0; i < sz; i++) {
            b = st[i];
            j = strlen(b);

            if (b[0] != b[j-1]) continue;

            if (!a) 
                a = b;
            else if (strlen(a) < j)
                a = b;
        }
        return a;
    }

#   undef nwc
};

///////////////////////////////

_sch(kmp)

    _pr _nd static int lst(_nn ss a, _nn ss b) {
        int c = 0;
        inp d = src(b, a, &c);
        return d ? c ? d[c-1] : -1 : 0;
    }

    _pr _nd static inp _nl src(_nn ss p, _nn ss t, inp _nl zs) {
        int m = strlen(p), n = strlen(t);
        int lps[m];
        
        inp rs = 0;
        int rsz = 0;
        if (zs) *zs = 0;

        cmp(p, m, lps);

        int i = 0, j = 0;
        while (i < n) {
            if (p[j] == t[i])
            { j++; i++; }
    
            if (j == m) {
                rs = (inp) realloc(rs, 
                   (rsz + 1) * sizeof(int));

                rs[rsz] = i - j;
                rsz++;

                j = lps[j - 1];
            } else if (i < n and p[j] != t[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }

        if (zs) *zs = rsz;
        return rs;
    }

    static void cmp(_nn ss p, int m, _nn inp lps) {
        int l = 0;
    
        lps[0] = 0;

        int i = 1;
        while (i < m) {
            if (p[i] == p[l]) {
                l++;
                lps[i] = l;
                i++;
            } else {
                if (l != 0)
                    l = lps[l - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
};

///////////////////////////////

class br {
private:
    int sz = 0;

public:
    static ci 
        alp = 26,
        wrd = 8;
    
    ///////////////////////////////

    struct nd {
        nd** cl;
        int en;

        nd(nd** _nl cl, int en = -1) :
            cl(cl ? 
                cl : 
                (nd**) calloc(alp, sizeof(nd*))
            ), 
            en(en) 
        {}
    };
    typedef nd* ndp;

    ///////////////////////////////

    const ndp rt = new nd(0, 0);

    void dd(_nn ss b) _th {
        if (strlen(b) > wrd)
            throw "0x1";

        ndp c = rt;
    
        for (int i = 0; i < strlen(b); i++) {
            int d = b[i] - 'a';

            if (!c->cl[d])
                c->cl[d] = new nd(0);
    
            c = c->cl[d];
        }
        c->en = sz;
        sz++;
    }

    _nd ss* _nl prt(int& k) {
        ss* _nl b = 0;
        k = 0;
        d(b, k);
        return b;
    }

    void d(
        ss*& b,
        int& k,
        _nn ss s = new char[wrd],
        ndp _nl a = 0,
        int j = 0
    ) {
        if (!a) a = rt;

        if (a->en != -1) {
            s[j] = '\0';
            b = (ss*) realloc(b, (k + 1) * spp);
            
            ss d = new char[j];
            for (int i = 0; i < j; i++)
                d[i] = s[i];
            d[j] = '\0';
            
            b[k] = d;
            k++;
        }
    
        for (int i = 0; i < alp; i++) {
            if (a->cl[i]) {
                s[j] = i + 'a';
                d(b, k, s, a->cl[i], j + 1);
            }
        }
    }

    _pr _nd int src(_nn ss b) {
        ndp c = rt;
        int l = strlen(b);
        int r = 0;
    
        for (int i = 0; i < l; i++) {
            int d = b[i] - 'a';

            if (!c->cl[d])
                return 0;
    
            c = c->cl[d];
        }
        return c and c->en != -1 ? c ? c->en : -1 : -1;
    }

    _pr _nd int ln()
    { return sz; }
};

///////////////////////////////

class apr {
private:
    ss aa = 0;
    br* br = 0;
    int bs = 0;

#   define bb (*br)

public:

    apr(_nn ss a, _nn class br* b) : 
        aa(a), br(b), bs(bb.ln())
    {}

    _pr _nd bool cnt(ss* _nl a = 0)
    { return a ? (*a = mmw()) : mmw(); }

    _pr _nd static float prs(_nn ss a, _nn ss b) 
    { return hdst(a, b) / strlen(a); }

    _pr _nd static bool mtc(_nn ss a, _nn ss b)
    { return prs(a, b) >= 0.5f; }

    _pr _nd ss _nl mmw() {
        int a = 0;
        ss* b = bb.prt(a);
        if (!b) return 0;

        int f = strlen(aa), e = 0, h = 0;
        for (int i = 0, c = 0, d = 0; i < a; i++) {
            ss g = b[i]; h = strlen(g);

            c = f == h and ilt(aa) ? hdst(g, aa) : f+1;
            
            if (c < d or !i) {
                d = c;
                e = c != f+1 and c ? i : -1; //br->src(g);
            }
        }
        //printf("0 | %s %d %d\n", aa, f, e);
        return e != -1 ? b[e] : 0;
    }

    _pr _nd static bool ilt(_nn ss a) {
        int b = strlen(a), c = 0, d = 1;
        for (; c < b; c++)
            d &= ilt(a[c]);
        return d;
    }

    _pr _nd static bool ilt(char a) {
        bool c = 0;
        for (char b = 'a'; b < 'z'; b++)
            c |= a == b;
        return c;
    }

    _pr _nd static int hdst(_nn ss a, _nn ss b) {
        if (strlen(a) != strlen(b)) return -1;
        int c = 0, d = 0;
        
        for (; d < strlen(a); d++) {
            if (a[d] != b[d])
                c++;
        }
        return c;
    }

    [[deprecated, gnu::unused]]
    _pr _nd static int ldst(_nn ss a, _nn ss b) {
        unsigned 
            i = 1, 
            j = 1, 
            k = strlen(a), 
            l = strlen(b);
        
        unsigned m[l+1][k+1];
        m[0][0] = 0;

        for (; i <= l; i++)
            m[i][0] = m[i-1][0] + 1;

        for (; j <= k; j++)
            m[0][j] = m[0][j-1] + 1;

        for (i = 1; i <= l; i++)
            for (j = 1; j <= k; j++)
                m[i][j] = mn(
                    m[i-1][j] + 1, 
                    m[i][j-1] + 1, 
                    m[i-1][j-1] + 
                        (a[j-1] == b[i-1] ? 0 : 1));
        return m[l][k];
    }

    _pr _nd static int mn(int a, int b, int c) _th
    { return 
        a <= b and a <= c ? a : 
            b <= a and b <= c ? b : 
                c <= a and c <= b ? c : 
                    throw "stub"; }

#   undef bb
};

///////////////////////////////

class trt {
private:
    ss* aa = 0;
    static const int cc = 2;
    inp* bb;
    ss dd = 0;
    int ee = 0;
    br* ff = 0;

public:

    trt(_nn ss a, _nn br* br) {
        dd = a;
        ff = br;

        int b = strlen(a), c = 0, f = 0, g = 0, h = 0, l = 0;
        char d = 0; ss e = 0;
        
        for (; c <= b; c++) {
            d = a[c], l = a[!c ? 0 : c-1];

            if (
                d == ' ' or 
                d == '\n' or 
                d == '\0' or
                c == b
            ) {
                if (
                    l == ' ' or 
                    l == '\n' or 
                    l == '\0' or
                    c == b
                ) continue;

                e[f] = '\0';

                ss j = new char[f];
                for (int k = 0; k < f; k++)
                    j[k] = e[k];
                j[f] = '\0';

                f = 0;

                aa = (ss*) 
                    realloc(aa, (g + 1) * spp);
                aa[g] = j;
                g++;

                free(e);
                e = 0;

                bb = (inp*) 
                    realloc(bb, g * sizeof(inp));
                inp i = new int[2];
                i[0] = h; i[1] = c;
                bb[g-1] = i;

                h = c;

                ee = g;
            } else {
                e = (ss) 
                    realloc(e, (f + 1) * sc);
                e[f] = d;
                f++;
            }
        }
        cng();
    }

    void cng() {
        int a = 0, b = 0, e = 0;
        inp d = 0;
        ss c = 0, f = 0;

        for (; a < ee; a++) {
            c = aa[a];
            d = bb[a];

            f = apr(c, ff).mmw();
            printf("7 | %s %d |%s| %d\n", c, d == 0, f, f == 0);
            if (!f) continue;

            printf(" %d %d\n", d[0], d[1]);

            for (b = d[0], e = 0; b < d[1]; b++, e++) {
                printf("   %d %d\n", b, e);
                dd[b] = f[e];
            }
        }
    }
};

///////////////////////////////

_sch(ts)

#   define sss(x) tss(#x)

    _nd _nn static ss tss(_nn cs a) {
        int b = strlen(a);
        ss d = new char[b];
        
        for (int c = 0; c < b; c++)
            d[c] = a[c];
        
        d[b] = '\0';
        return d;
    }

    static void on() {
        cl::nt("aa abcde edcba abcda ebcde" 
            "rock 0x0 0x12345 0x99990 0b111111");
        printf("%s\n", cl::fn());
    }

    static void tw() 
    { printf("%d\n", kmp::lst(
        (ss) "ABABDABACDABABCABABABABCCAACDCDABABCABAB", 
        (ss) "ABABCABAB")); }

    static void th() {
        br* br = new class br();

        ci b = 12;
        cs a[b] = {
            "short",   // 0
            "int",     // 1
            "char",    // 2
            "long",    // 3
            "unsigned",// 4
            "void",    // 5
            "return",  // 6
            "if",      // 7
            "else",    // 8
            "switch",  // 9
            "while",   // 10
            "for"      // 11
        };

        for (int i = 0; i < b; i++)
            br->dd(tss(a[i]));

        ss c = tss(
            "vold { anslgmed lf () iong swlts retunr short } ");
        trt tr(c, br);
        printf("%s\n", c);
    }
};

int main() {
    //ts::on();
    //ts::tw();
    ts::th();
    return 0;
}
