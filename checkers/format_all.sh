for f in $(find $1 -name '*.cpp'); 
do
    echo Formatting $f ...
    "c:\Program Files\LLVM\bin\clang-format.exe" -i $f
done 