Popescu Ionut-Teodor 311CC
                          *2048*
        Am inceput prin creerea unei ferestre pentru meniu si am adaugat la
    coordonatele potrivite butoanele new game resume si quit Functia principala
    este game unde se intampla majoritatea jocului,si este apelata in functia
    menu in care reprezentam optiunile si daca sunt selectate. 
        Cat timp nu se apasa enter,adica nu s a selectat o optiune ,ramanem in 
    meniu.daca position este 2 folosim atributul sa adaugam efectul de 
    inversare a culorii de la scris cu cea de fundal ca sa reprezentam ce 
    este selectat in momentul respectiv.
        De asemenea functia Arrow verifica ce optiune este selectata si ii pune 
    o sageata in dreapta.Am folosit si atributele pentru a da un fel de 
    highlight la elementele pe care este cursorul.Am pus si conditii ca sa ne 
    intoarcem la primul sau ultimul element din meniu daca se da sageata in jos 
    la ultimul elemnet sau sageata in sus la primul.
        In meniu verificam ce pozitie avem dupa ce se da enter ,iar daca aceasta 
    este 6 terminam programul.In schimb daca este 2 inseamna ca initializam cu 0
    scorul total si momentan si am luat o variabila care ne indica daca s-a 
    inceput un joc nou pentru a verifica daca se poate folosii varianta resume 
    care initial nu este disponibila.
        In fuctia game verificam daca s a selectat resume si daca s a pornit 
    anterior un new game,iar daca avem un resume valid folosim o alta variabila 
    prin care vom da skip la o parte din codul care ar trebui rulat pentru new 
    game ,cum ar fii generarea a 2 numere random in pozitii random si schimbam 
    valoarea lui position la 2 ,ca si cand am rula new game.Creeam tabla de joc,
    iar apoi ii dam lui aux valori de la 0 la 3 pentru a selecta random prima 
    pozitie adica ii generam random x-ul si y-ul si initializam matricea cu 0.
    Transformama coordonatele in cele potrivite pentru tabla de joc si afisam 
    numarul.Pentru a genera a 2-a pozitie random folosim un vector in care vom 
    retine coordonatele celulelor libere prima data y apoi x in fuctia check 
    unde retinem si cate perechi sunt in size deoarece vom folosii un vector ca 
    sa generam o pereche random.
        Dupa afisarea tuturor ferestrelor ce contin informatii, folosim un while
    in care afisam timpul in real time si apelam functia timeskip ca sa primim
    o tasta valida sau daca nu se apasa nicio tasta in 10 secunde se va face o 
    miscare automata.De asemena am luat un goto mai jos care se va intoarce la 
    loopstart daca se apasa alta tasta decat cele menite sa fie apasate.
          Daca se foloseste sageata in sus atunci luam un for pentru a trece 
    prin toate coloanele si plecam de la i=1 ca sa putem folosi i-1.Initializam
    vectorul de coord cu -1 ca sa fie diferit de coordonatele care vor fi
    retinute.Adaugam in vectorul acesta ,in functie de ce miscare se foloseste, 
    i-ul sau j-ul celulei in care am imbinat 2 dintre ele si verificam la 
    fiecare imbinare daca a mai fost imbinata inainte si astfel evitam 
    imbinarile multiple in aceeasi celula.Algoritmul de  keyup e pe aceeasi idee 
    cu celelalte mutari.Cat timp n am iesit din coordonatel matricei cautam 
    prima celula diferita de 0 sau iesim din while daca nu exista.Dupa care cat 
    timp i-ul macar a doua pozitie ,si elementul de dinainte este 0 sau este
    egal cu el le mutam corespunzator.Avem si through care verifica daca mutarea 
    este posibila si scorul care se mareste cand se imbina 2 celule.De asemenea 
    daca a mai fost imbinata anterior folosim goto sa trecem de while.
            Folosim variabila through ca sa verificam daca mutarea a facut ceva,
    adica daca a fost valida,iar daca nu ,nu genream alt element si trecem la
    urmatoarea mutare care este pe acelasi principiu cu cea de mai sus.De 
    asemnea verificam daca s a ajuns la 2048 sau daca mai este vreo miscare
    posibila.
            In functia checkgame verificam in primul rand daca tabla este plina 
    adica nu avem valori de 0 si daca este plina verificam daca vreuna dintre 
    miscari elibereaza macar o celula,iar daca nu transmitem gameover ca fiind 1 
    in game.
            In functia bestmove folosim aceleasi mutari ca in game ,dar le facem
    pe rand si retinem dupa fiecare mutare cate casute au eliberat ,si cea care 
    are cele mai multe casute libere este cea mai buna si transmisa,iar daca 
    niciuna nu este mai buna,generam una random.
            In functia timeskip verificam daca trec 10 secunde de la ultima 
    tasta apasata sau daca se apasa trimitem input-ul in game.Ne folosim de 
    difftime unde calculam diferenta dintre start time si end time care e 
    actualizat in continuu in while.Am folosit nodelay pentru a trece prin 
    comada wgetch aceasta nemaiblocand programul.Daca trec 10 secunde atunci 
    generam cea mai buna mutare.
            Mai sunt funciile de afisare care folosesc ca atribute culori.La 
    functia unde afisez elementel din tabala am folosit un switch pentru a 
    personaliza fiecare numar cu o culoare.Si pentru functia care afiseaza 
    timpul curent am folosit structura tm si localtime .
