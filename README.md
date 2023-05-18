# Krizic Kruzic simulator


Ovo je jednostavan Tik Tak Toe simulator napisan u C-u koji se može igrati u sučelju naredbenog retka. Igru mogu igrati dva igrača koji naizmjence označavaju svoj simbol na mreži 3x3. Igrač koji uspije postaviti tri svoje oznake u vodoravni, okomiti ili dijagonalni red pobjeđuje u igri.

## TODO

- [x] Implement the game logic
- [ ] Add input validation
- [ ] Add a scoring system
- [ ] Implement a computer opponent
- [ ] Add a multiplayer mode
- [ ] Add save/load functionality
  

## Kako igrati

1. Prevedite program koristeći C kompajler kao što je `gcc` ili `visual studio`.
2. Pokrenite prevedenu izvršnu datoteku u sučelju naredbenog retka.
3. Slijedite upute za igranje igre.

#
## Faks TODO

### Obvezni koncepti:

- [ ] 1. Odabir konkretnih primitivnih tipova podataka za rad s cjelobrojnim i realnim konstantama.
- [x] 2. Odabir konkretnih složenih tipova podataka za rad sa specifičnim objektima.
- [x] 3. Primjena typedef sa strukturama i unijama, po potrebi s enum tipovima podataka tamo gdje
treba.
- [x] 4. Imenovanje identifikatora (varijabli, konstanti, polja, funkcija, pokazivača…) – upotreba
camelCase, PascalCase i snake_case konzistento kroz cijeli projekt.
- [ ] 5. Primjena ključne riječi static za globalne i lokalne varijable.
- [x] 6. Organizacija izvornog kôda.
- [ ] 7. Ako su funkcije jednostavne koristiti makro funkcije ili inline funkcije.
- [ ] 8. Izbornik/podizbornici.
- [x] 9. Generalno upotreba pokazivača tamo gdje su potrebni.
- [x] 10. Generalno upotreba struktura i funkcija.
- [ ] 11. Zaštita parametara kod svih funkcija.
- [ ] 12. Koristiti statički zauzeta polja.
- [x] 13. Koristiti dinamičko zauzimanje memorije za bilo koji tip podatka, osobito za složene tipove
podataka.
- [x] 14. Koristiti funkcije malloc(), calloc(), realloc(), free() – neku od njih, ako ne i sve.
- [x] 15. Sigurno brisanje memorije koja je dinamički zauzeta, anuliranje memorijskog prostora, provjera
pokazivača kako se ne bi dogodila pogreška double free() i anuliranje svih pokazivača koji su bili
usmjereni na memorijski prostor koji se dinamički zauzeo.
- [ ] 16. Datoteke, koristiti tekstualnu ili binarnu, provjera pokazivača i zatvaranje datoteke.
- [ ] 17. Koristiti funkcije fseek(), ftell(), rewind(), ovisno o potrebi – neku od njih ako ne sve.
- [ ] 18. Koristiti funkcije remove(), rename(), po potrebi implementirati funkciju za kopiranje datoteka.
- [ ] 19. Upravljati s pogreškama, errno, perror(), strerror(), feof(), ferror() – neku od njih ako ne sve.
- [ ] 20. Sortiranje – pokušati koristiti ugrađenu qsort() funkciju.
- [ ] 21. Pretraživanje – pokušati koristiti ugrađenu bsearch() funkciju.

### Dopunski koncepti:
- [ ] 1. Primjena rekurzija.
- [ ] 2. Pokazivači na funkcije.
- [ ] 3. Jednostruko ili dvostruko povezani popis.
