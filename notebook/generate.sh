#!/bin/sh
python script.py
pdflatex out.tex
pdflatex out.tex
cp out.pdf team-notebook.pdf 
rm out*
atril team-notebook.pdf
