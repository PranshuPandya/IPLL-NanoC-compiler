make clean
make
./A6_36 $1 > output_quads
gcc -c A6_36_lib.c
ar -rcs libA6_36_lib.a A6_36_lib.o
gcc $1.s -L. -lA6_36_lib -no-pie -o $1
echo "Executing the program:"
./$1