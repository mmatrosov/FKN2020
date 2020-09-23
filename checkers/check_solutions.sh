for f in $(find $1 -name '*.cpp'); 
do
    echo Checking $f ...
    clang-tidy --warnings-as-errors=* -checks=-*,modernize-loop-convert $f -- -std=c++17 -I/usr/include/c++/7 -I/usr/include/x86_64-linux-gnu/c++/7
done
