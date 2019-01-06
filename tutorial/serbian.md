# CMake alat za kreiranje projektnih fajlova iz izvornog koda (C++)
Veliki broj projekata koji su napisani u programskom jeziku C++ pišu se sa ciljem izvršavanja na različitim operativnim sistemima. Da bi se izvorni kod ovakvih aplikacija uspešno kompilirao za odgovarajući sistem, potrebno je izvršiti određeni skup operacija za svaki sistem zasebno. U tu svrhu, koriste se različiti sistemi za prevođenje, kao što su [sistem zasnovan na Makefile datotekama](https://en.wikipedia.org/wiki/Makefile) za Unix-zasnovane operativne sisteme ili [Visual Studio alat za razvoj](https://visualstudio.microsoft.com/) za Windows operativne sisteme. 

Međutim, problem koji se sada javlja jeste što je za svaki ovakav sistem za prevođenje (a ponekad i za svaku verziju sistema) potrebno čuvati datoteke specifične za njega, kako bi se prevođenje moglo izvršiti. Na primer, za prvi spomenuti sistem potrebno je imati datoteke pod nazivom `Makefile` u projektnom direktorijumu, odnosno, za Visual Studio alat je potrebno imati razne `.sln` i `.vcproj` datoteke između ostalog. Očigledno, čuvanje ovih datoteka na sistemu za kontrolu verzija predstavlja problem jer dovodi do brzog zagađenja projektnog direktorijuma "nepotrebnim" datotekama. [CMake](https://cmake.org/) alat o kojem će biti reči u ovom članku pokušava da reši pomenute probleme tako što definiše jedan sistem, koji neće zagađivati projekat u velikoj meri, a koji služi za generisanje datoteka za pomenute sisteme za prevođenje.

Kako CMake funkcioniše? Sistem kojim CMake rukovodi se zasniva na datotekama čiji su nazivi `CMakeLists.txt`. Za svaki modul projekta se definiše po jedna datoteka ovog naziva u kojoj se nalaze direktive, napisane na specijalnom skript jeziku koji CMake razume, kojima se opisuje na koji način se generiše izvršni kod od izvornog koda. Ovaj skript jezik omogućava pisanje najrazličitijih direktiva, ali mi ćemo u ovom članku prikazati samo najosnovnije.

Napravićemo aplikaciju koja učitava JPEG fotografije u boji i od njih konstruiše crno-bele fotografije. Za ovaj zadatak ćemo koristiti neke module [biblioteke stb](https://github.com/nothings/stb/), naime `stb_image` i `stb_image_write`. Naša aplikacija će zapravo samo koristiti funkcije iz ovih biblioteka, ali poenta jeste u tome da naučimo da koristimo biblioteke "trećih lica" (engl. _third-party_) u našim aplikacijama, a ne da obrađujemo slike :) Struktura našeg projektnog direktorijuma sa opisima direktorijuma izgleda ovako:
```
cmake-tutorial/						# Koren projektnog direktorijuma
	bin/							# Izvorni kod aplikacije
	build/							# Datoteke za prevođenje
	resources/						# Resursi za testiranje rada aplikacije
		leaves.jpeg
	src/							# Izvorni kod aplikacije
		app.cpp
	thirdparty/						# Izvorni kod biblioteka trećih lica
		include/
			stb_image.h
			stb_image_write.h
		source/
			stb_image.cpp
			stb_image_write.cpp
		CMakeLists.txt				# Uputstvo za kreiranje biblioteke trećih lica
	CMakeLists.txt					# Uputstvo za kreiranje aplikacije
	build.sh						# Skript za lakše kreiranje za Linux
```

Kao što vidimo, skoro sve datoteke koje se nalaze u projektnom direktorijumu sadrže ili izvorni kod ili nekakve resurse za pokretanje aplikacije. Jedine datoteke koje ne sadrže izvorni kod su dve `CMakeLists.txt` datoteke (i jedan skript za pokretanje CMake alata za Linux radi automatizacije procesa), koje nam svakako ne đubre projekat niti smetaju sa radom.
