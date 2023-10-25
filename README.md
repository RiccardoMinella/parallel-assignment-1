To run the experiments go in to the experiment folder and run the file script.sh,
it will compile and run the codes

If you compile the codes manually use the following commands then execute the files singularly:
- Serial: `gcc -o sequential source.c`
- Parallel: `gcc -O3 -march=native -o parallel source.c`
