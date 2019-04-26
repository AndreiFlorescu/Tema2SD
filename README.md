Tema 2 SD: Ierarhie DNS

     _________   _________
    /\   ___  \ /\   _____\
    \ \  \__\  \\ \  \___ /
     \ \   ___  \\ \   __\
      \ \  \_/\  \\ \  \_/
       \ \__\\ \__\\ \__\
        \/__/ \/__/ \/__/
            (c) Andrei Florescu 2019

Task 1: Se citesc datele din fisier si se stocheaza intr-un vector auxiliar. 
		Acesta este parcurs si folosit pentru generarea arborelui. Dupa aceea 
		arborele este parcurs recursiv si se afiseaza pentru fiecare nod 
		nodurile copil pe care le are.

Task 2: Parcuregem arborele si updatam lista de adrese pe care l poate rezolva 
		fiecare nod de "jos in sus" (folosind recursivitate). Dupa aceea 
		parcurgem arborele si afisam pentru fiecare nod lista de adrese pe care
		le poate rezolva.

Task 3: Parcurgem fisierul users.in si stocam intr-un vector adresele nodurilor
		la care este legat fiecare user. Parcurgem querry-urile si vedem pentru
		fiecare user care este calea pe care trebuie sa o urmeze. Acest lucru 
		este realizat urcand din nodul curent in nodul parintelui pana gasim un
		nod care poate rezolva querry-ul.

Bonus:	In momentul in care cade un server updatam nodul userilor care erau 
		legati la acesta cu tatal serverului cazut. Dupa aceea, refacem 
		arborele mutand toti copii serverului cu probleme in serverul parinte 
		si schimbandu-le tatal. Serverul stricat este apoi indepartat din 
		arbore si se elibereaza memoria alocata acestuia. In urma acestor 
		operatii, arborele devine "stabil" si se pot continua querry-urile pe 
		acesta fara probleme.

Feedback:	Tema mi-a luat cateva ore sa o termin si consider ca si-a atins 
			obiectivele specificate in enunt.