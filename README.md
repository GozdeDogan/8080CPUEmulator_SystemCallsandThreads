/******************************************************************************/
/* Gozde DOGAN - 131044019
/* CSE312 - Homework2
/*
/* 20 Nisan 2018
/*
/* Kisa odev aciklamasi
/*
/******************************************************************************/

Thread class'i yazildigi icin makefile'i ona gore duzenledim, o sekilde atiyorum.
Benim gonderdigim makefile'i calistirmak isteiyorsaniz elinizdeki makefile'da;
	DEPS = Thread.h gtuos.h memory.h 8080emuCPP.h memoryBase.h Thread.cpp gtuos.cpp 8080emu.cpp
seklinde duzeltme yapabilirsiniz.


ONEMLI:
make yapildiginde memory.h da cstdlib kutuphanesi tanimlanmadigi icin malloc kullanimina hata veriyor.
Bu nedenle memory.h ve MemoryBase.h kutuphaneleri de dosyanin icinde gonderildi.
Eger bu sekilde calistirmak istemiyorsaniz elinizdeki memory.h kutuphanesine
	#include <cstdlib> 
seklinde C'nin standart kutuphanesini eklemelisiniz.
Bu sekilde duzeltme yaptiginizda calisacaktir.


F1.asm, F2.asm, F3.asm, F4.asm, F5.asm, P1.asm, P2.asm, P3.asm, P4.asm, P5.asm yazildi.


F1.asm -> 
		Sayilari 0 dan baslayip 50 ye kadar yaziyor. (50 dahil)
		PRINT_B kullanildi
		(510 cycle surecektir.)

F2.asm ->
		1'den 100'e kadar sayilari toplayip ekrana yaziyor.
		Sadece PRINT_B kullanildi.
		(10 cycle surecektir.)

F3.asm ->
		50'den 100' kadar olan sayilari (100 dahil) ekrana yaziyor.
		PRINT_B kullanildi.
		(510 cycle surecektir.)

F4.asm ->
		dw ile tanimlanan arrayi siralamaya calisiyor.
		Array elemanlari random olarak uretildi. 
		Siralanmis arrayi PRINT_STR ile ekrana yaziyor.
		(Sort islemi 1250 cycle surecektir.)


F5.asm ->
		50 random sayi uretilir ve ardindan siralanir. 
		Klavyeden okunan sayi Search algoritmasi ile bu dizi de aranir. 
		Eleman bulunursa index'i, bulunamazsa hata mesaji ekrana yazilir.
		(NOT: index yazilirken index'in 2 kati seklinde yaziliyor)
		(Cycle sayisi eleman bulundugu zaman 1480 cikacaktir. 
		Bulunmadigi zaman ise 1470 cikacaktir.)


P1.asm, P2.asm, P3.asm, P4.asm, P5.asm istenilenlere uymaya calisarak implement etmeye calistim. 
Iclerinde thread system call'llari kullanildigi icin cycle sayilari da ona gore cikacaktir.

ASM dosyalari bir folder icinde bulunmaktadir. 
!! Ama .com uzantili dosyalar programlarin bulundugu klasor de yer almalidir !!

Odev denenmesi istenilen linux surumunde segment fault yememiştir. 
Butun asm dosyalari calistirilip denendi. Hepsi sonlandi.

