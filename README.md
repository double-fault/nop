Run makefile (will take some time), then run `run.sh`. Finally can run `graph.py` to get the graph. 

Requires google benchmark https://github.com/google/benchmark

Also update `FREQ` in `graph.py` to the frequency of your cpu, in GHz - the cycles are calculated by simply multiplying the time with the freq. Might also want to change some setting to switch off cpu scaling (not that it will matter for this anyway ig).
