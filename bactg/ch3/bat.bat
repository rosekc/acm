:again
python Uva11107_gen.py
A.exe < in.txt > out1.txt
B.exe < in.txt > out2.txt

fc out1.txt out2.txt > nul
if not errorlevel 1 goto again