compiler = g++
main_file = main.cpp
params = -lsfml-graphics -lsfml-window -lsfml-system
output_filename = pp-tetris-attack.bin

hello:
		@echo "* Building \e[32m$(output_filename)\e[0m."
		$(compiler) $(main_file) $(params) -o $(output_filename)

clean:
		@echo "* Cleaning build."
		rm -f pp-tetris.bin
