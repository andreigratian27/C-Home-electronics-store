Magazinul vinde doar doua produse: Frigidere si Masini de spalat.
Se vor construi urmatoarele clase:
● Produs:
○ Clasa de baza.
○ Nu vor exista instante ale clasei Produs
○ Clasa Produs va avea urmatorii membrii
■ id - intreg
■ nume - string
■ pret - double
● Frigider
○ Extinde clasa Produs
○ Are urmatorii membrii:
■ volum - intreg
■ areCongelator - bool
● MasinaDeSpalat:
○ Extinde clasa Produs
○ Are urmatorii membrii:
■ rotatiiPeMinut - intreg
■ clasaEnergetica - string
● Magazin:
○ Are urmatoarele metode
■ Magazin(int nrProduse)
● Contructor pentru clasa Magazin. Primeste ca parametru
dimensiunea magazinului(numarul maxim de produse acceptate)
■ void adaugaProdus(Produs* produs)
● Arunca MagazinPlinException in cazul in care magazinul nu mai
are spatiu pentru produs
■ void eliminaProdus(int idProdus)
● Arunca ProdusInexistentException in cazul in care produsul nu
exista
■ Produs* cautaProdus(int idProdus)
● Arunca ProdusInexistentException in cazul in care produsul nu
exista
■ int numaraMasiniDeSpalat()
● Metoda va intoarce numarul de masini de spalat din magazin
■ void scrieProduse()
● Afiseaza informatii despre produsele existente in magazin
Hint: Pentru stocarea produselor puteti folosi un vector de pointeri la tipul Produs. Puteti folosi
valoarea NULL pentru a marca pozitiile libere din magazin.
Observatie: Puteti adauga componente in plus fata de cele descrise mai sus (membrii sau
metode noi) pentru fiecare dintre clasele descrise daca le considerati utile.
Meniul va permite urmatoarele optiuni:
● A - Adauga produs (se citest detaliile de la tastatura)
● E - elimina produs (se citeste id produs de la tastatura)
● C - cauta produs (se citeste id produs de la tastatura)
● N - numara masina de spalat
● L - scrie produse
