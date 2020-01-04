cd ..
make all
make install
make clean

cd ./examples
g++ progress-bar-tester.cpp "../bin/libsupersimpleprogressbar.a" -o progress_bar_test.out
./progress_bar_test.out