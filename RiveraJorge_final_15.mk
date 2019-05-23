RiveraJorge_final_15.pdf: plot.py datos.txt
				python plot.py
datos.txt: RiveraJorge.cpp
				g++ RiveraJorge.cpp
				./a.out
