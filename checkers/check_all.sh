IFS=$'\n';
for f in $(find $1 -name '*.cpp'); 
do
    echo Checking $f ...
    grep "using namespace" "$f" && echo "'using namespace' directive detected!"
    grep "#define" "$f" && echo "A macro detected!"
    clang-tidy --warnings-as-errors=* -checks=-*,modernize-loop-convert "$f" -- -std=c++17 -I/usr/include/c++/7 -I/usr/include/x86_64-linux-gnu/c++/7
done

read -n 1 -s -r -p "Press any key to continue"
