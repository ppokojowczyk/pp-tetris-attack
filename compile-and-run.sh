clear
cd src/
OUTFILE="tetris.bin"
rm -f $OUTFILE
echo "\033[32mCompiling $OUTFILE...\033[0m"
g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system -o $OUTFILE
if [ -f $OUTFILE ]; then
    echo "\033[32mRunning $OUTFILE...\033[0m"
    ./$OUTFILE
else
    echo "\033[31mExecutable doesn't exist.\033[0m"
fi
echo "Exit"
