all :
	g++ source/makhluk/Makhluk.cpp source/listmakhluk/ListMakhluk.cpp source/makhluk/MakhlukTerbang.cpp source/makhluk/MakhlukAntiAir.cpp source/makhluk/MakhlukBurukRupa.cpp source/makhluk/MakhlukMaling.cpp source/makhluk/MakhlukMonster.cpp source/controlcommand/ControlCommand.cpp source/view/View.cpp source/main.cpp -o MakhlukinAction	
Makhluk :
	g++ -c source/makhluk/Makhluk.cpp
MakhlukTerbang :
	g++ source/makhluk/Makhluk.cpp source/makhluk/MakhlukTerbang.cpp source/makhluk/drivermakhlukterbang.cpp -o drivermakhlukterbang
MakhlukAntiAir :
	g++ source/makhluk/Makhluk.cpp source/makhluk/MakhlukAntiAir.cpp source/makhluk/drivermakhlukantiair.cpp -o drivermakhlukantiair
MakhlukBurukRupa :
	g++ source/makhluk/Makhluk.cpp source/makhluk/MakhlukBurukRupa.cpp source/makhluk/drivermakhlukburukrupa.cpp -o drivermakhlukburukrupa
MakhlukMaling :
	g++ source/makhluk/Makhluk.cpp source/makhluk/MakhlukMaling.cpp source/makhluk/drivermakhlukmaling.cpp -o drivermakhlukmaling.cpp
MakhlukMonster :
	g++ source/makhluk/Makhluk.cpp source/makhluk/MakhlukMonster.cpp source/makhluk/drivermakhlukmonster.cpp -o drivermakhlukmonster.cpp
ListMakhluk :
	g++ source/makhluk/Makhluk.cpp source/listmakhluk/ListMakhluk.cpp source/makhluk/MakhlukAntiAir.cpp source/makhluk/MakhlukBurukRupa.cpp source/makhluk/MakhlukMaling.cpp source/makhluk/MakhlukMonster.cpp source/makhluk/MakhlukTerbang.cpp source/makhluk/mListMakhluk.cpp -o mListMakhluk
ControlCommand :
	g++ -c source/makhluk/Makhluk.cpp source/listmakhluk/ListMakhluk.cpp source/makhluk/MakhlukAntiAir.cpp source/makhluk/MakhlukBurukRupa.cpp source/makhluk/MakhlukMaling.cpp source/makhluk/MakhlukMonster.cpp source/makhluk/MakhlukTerbang.cpp source/controlcommand/ControlCommand.cpp source/view/View.cpp
View :
	g++ -c view/View.cpp
HimpMakhluk :
	g++ source/makhluk/Makhluk.cpp source/listmakhluk/HimpMakhluk.cpp source/listmakhluk/mHimpMakhluk.cpp source/makhluk/MakhlukAntiAir.cpp source/makhluk/MakhlukBurukRupa.cpp source/makhluk/MakhlukMaling.cpp source/makhluk/MakhlukMonster.cpp source/makhluk/MakhlukTerbang.cpp -o HimpMakhluk

clear :
	rm *.o *.exe
