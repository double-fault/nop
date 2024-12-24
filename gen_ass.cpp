#include <bits/stdc++.h>

using namespace std;

#define ll long long

void nop(ll n) {
        while (n --) {
                printf("\tnop\n");
        }
}

void fun(ll tot) {
        printf(".global fun_%lld\n", tot);
        printf("fun_%lld:\n", tot);
        nop(tot - 1);
        puts("\tret\n");
}

int main(int argc, char **argv) {
        ll tot = 1LL << 10;
        ll mx = 1LL << 29;
        while (tot <= mx) {
                fun(tot);
                tot *= 2;
        }
        return 0;
}

