Makhluk :
	g++ -c Makhluk.cpp
MakhlukTerbang :
	g++ Makhluk.cpp MakhlukTerbang.cpp drivermakhlukterbang.cpp -o drivermakhlukterbang
MakhlukAntiAir :
	g++ Makhluk.cpp MakhlukAntiAir.cpp drivermakhlukantiair.cpp -o drivermakhlukantiair
MakhlukBurukRupa :
	g++ Makhluk.cpp MakhlukBurukRupa.cpp drivermakhlukburukrupa.cpp -o drivermakhlukburukrupa
MakhlukMaling :
	g++ Makhluk.cpp MakhlukMaling.cpp drivermakhlukmaling.cpp -o drivermakhlukmaling.cpp
MakhlukMonster :
	g++ Makhluk.cpp MakhlukMonster.cpp drivermakhlukmonster.cpp -o drivermakhlukmonster.cpp
ListMakhluk :
	g++ Makhluk.cpp ListMakhluk.cpp MakhlukTerbang.cpp MakhlukAntiAir.cpp MakhlukAir.cpp MakhlukBurukRupa.cpp MakhlukMaling.cpp MakhlukMonster.cpp MakhlukTerbang.cpp mListMakhluk.cpp -o mListMakhluk
Petak :
	g++ Makhluk.cpp ListMakhluk.cpp MakhlukTerbang.cpp MakhlukAntiAir.cpp MakhlukAir.cpp MakhlukBurukRupa.cpp MakhlukMaling.cpp MakhlukMonster.cpp MakhlukTerbang.cpp Petak.cpp driverPetak.cpp -o driverPetak
all :
	g++ *.cpp -o main
	
clear :
	rm *.o *.exe
