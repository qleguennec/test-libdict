echo "#define PRE \\" > test.h
find ~ -type f -printf '\tTEST("%i", "%f"); \\\n' >> test.h
