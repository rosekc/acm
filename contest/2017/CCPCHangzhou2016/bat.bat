:again
python F_gen.py > in.txt
F.exe < in.txt > out1.txt
F_c.exe < in.txt > out2.txt

fc out1.txt out2.txt > nul
if not errorlevel 1 goto again