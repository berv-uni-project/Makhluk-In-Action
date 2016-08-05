all :
	g++ view/View.cpp listmakhluk/ListMakhluk.cpp makhluk/Makhluk.cpp makhluk/MakhlukAntiAir.cpp makhluk/MakhlukBurukRupa.cpp makhluk/MakhlukMaling.cpp makhluk/MakhlukMonster.cpp makhluk/MakhlukTerbang.cpp controlcommand/ControlCommand.cpp main.cpp -o ../../bin/MakhlukinAction-nonstl

DriverListMakhluk :
	g++ listmakhluk/ListMakhluk.cpp makhluk/Makhluk.cpp makhluk/MakhlukAntiAir.cpp makhluk/MakhlukBurukRupa.cpp makhluk/MakhlukMaling.cpp makhluk/MakhlukMonster.cpp makhluk/MakhlukTerbang.cpp driver/driverlistmakhluk.cpp -o ../../bin/DriverListMakhluk

ListMakhluk :
	g++ -c listmakhluk/ListMakhluk.cpp makhluk/Makhluk.cpp makhluk/MakhlukAntiAir.cpp makhluk/MakhlukBurukRupa.cpp makhluk/MakhlukMaling.cpp makhluk/MakhlukMonster.cpp makhluk/MakhlukTerbang.cpp

DriverMakhluk :
	g++ makhluk/Makhluk.cpp makhluk/MakhlukAntiAir.cpp makhluk/MakhlukBurukRupa.cpp makhluk/MakhlukMaling.cpp makhluk/MakhlukMonster.cpp makhluk/MakhlukTerbang.cpp driver/drivermakhluk.cpp -o ../../bin/DriverMakhluk

Makhluk :
	g++ -c makhluk/Makhluk.cpp makhluk/MakhlukAntiAir.cpp makhluk/MakhlukBurukRupa.cpp makhluk/MakhlukMaling.cpp makhluk/MakhlukMonster.cpp makhluk/MakhlukTerbang.cpp

View :
	g++ -c view/View.cpp
	
DriverView :
	g++ view/View.cpp driver/driverview.cpp -o ../../bin/DriverView

ControlCommand :
	g++ -c view/View.cpp listmakhluk/ListMakhluk.cpp makhluk/Makhluk.cpp makhluk/MakhlukAntiAir.cpp makhluk/MakhlukBurukRupa.cpp makhluk/MakhlukMaling.cpp makhluk/MakhlukMonster.cpp makhluk/MakhlukTerbang.cpp controlcommand/ControlCommand.cpp

DriverControlCommand :
	g++ view/View.cpp listmakhluk/ListMakhluk.cpp makhluk/Makhluk.cpp makhluk/MakhlukAntiAir.cpp makhluk/MakhlukBurukRupa.cpp makhluk/MakhlukMaling.cpp makhluk/MakhlukMonster.cpp makhluk/MakhlukTerbang.cpp controlcommand/ControlCommand.cpp driver/drivercontrolcommand.cpp -o ../../bin/DriverControlCommand

clean :
	rm *.o *.exe
