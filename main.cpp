#include <benchmark/benchmark.h>
#include <x86intrin.h>

extern "C" void fun_1024();
extern "C" void fun_2048();
extern "C" void fun_4096();
extern "C" void fun_8192();
extern "C" void fun_16384();
extern "C" void fun_32768();
extern "C" void fun_65536();
extern "C" void fun_131072();
extern "C" void fun_262144();
extern "C" void fun_524288();
extern "C" void fun_1048576();
extern "C" void fun_2097152();
extern "C" void fun_4194304();
extern "C" void fun_8388608();
extern "C" void fun_16777216();
extern "C" void fun_33554432();
extern "C" void fun_67108864();
extern "C" void fun_134217728();
extern "C" void fun_268435456();
extern "C" void fun_536870912();

static void (*funs[])(void) = {
	fun_1024,
	fun_2048,
	fun_4096,
	fun_8192,
	fun_16384,
	fun_32768,
	fun_65536,
	fun_131072,
	fun_262144,
	fun_524288,
	fun_1048576,
	fun_2097152,
	fun_4194304,
	fun_8388608,
	fun_16777216,
	fun_33554432,
	fun_67108864,
	fun_134217728,
	fun_268435456,
	fun_536870912,

};

void BM(benchmark::State &state) {
        for (auto _ : state) {
                funs[state.range(0)](); 
        }
}

BENCHMARK(BM)->DenseRange(0, 19, 1);

BENCHMARK_MAIN();
