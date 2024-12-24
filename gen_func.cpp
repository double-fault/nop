#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll st = 1LL << 10;
const ll ed = 1LL << 29;
vector<ll> sizes = {8};

void func_dec() {
        for (auto &s: sizes) {
                ll cur = st;
                while (cur <= ed) {
                        printf("extern \"C\" void fun_%lld();\n", cur);
                        cur *= 2;
                }
                puts("");
        }
}

void func_pointers() {
        printf("static void (*funs[])(void) = {\n");
        for (auto &s: sizes) {
                ll cur = st;
                while (cur <= ed) {
                        printf("\tfun_%lld,\n", cur);
                        cur *= 2;
                }
                puts("");
        }
        puts("};");
}

int main(int argc, char **argv) {
        func_dec();
        func_pointers();
        return 0;
}

