# ArduinoDisco

Lingue disponibili:

[![it](https://img.shields.io/badge/lang-it-green.svg)](https://github.com/Xxyuri2005xX/ArduinoDisco/blob/master/README.it.md)
[![en](https://img.shields.io/badge/lang-en-red.svg)](https://github.com/Xxyuri2005xX/ArduinoDisco/blob/master/README.en.md)
---

![ItFlag](https://user-images.githubusercontent.com/84080587/194774644-66c6fa81-5d29-4b5c-a49f-c68afc953cde.png)

il seguente progetto riguarda la realizzazione di una discoteca intelligente che adatta la sua pista in base al numero di persone.
Le variabili e i commenti del progetto sono tutte in italiano.

lo sketch arduino (da caricare attraverso il suo IDE) sarà disponibile in 2 versioni (riconoscibili dal tag "- iso"): 
- Italiano - IT
- Inglese - EN

## Progetto Tinkercad

![Tinkercad](https://user-images.githubusercontent.com/84080587/194775403-9f35a7ad-79f5-4fea-b5dc-288bc9b9d3bb.PNG)

## Prossimamente
- ArduinoDisco v2
- ArduinoDisco v3

Caratteristiche delle versioni:
|  | ArduinoDisco v1 | ArduinoDisco v2 | ArduinoDisco v3 |
| --------------- | --------------- | --------------- | --------------- |
| Supporto Web:| ❌ | ❔ | ✅ |
| Rilascio: | 09/10/2022  | PRESTO  | N/A |
| Lettura musica:| ❌ | ✅ | ✅ |
| Conteggio persone aggiornato:| ❌ | ✅ | ✅ |

Legenda:
- ❌: No
- ❔: In valutazione
- ✅: Si

## FAQ
Qui potete trovare alcune domande frequenti.

## Implementazione di più led

Per implementare nuovi led RGB all'interno del progetto è necessario seguire i seguenti step:
- Implementare il nuovo led nel circuito (**!SONO NECESSARI 3 PIN MUNITI DI PWM PER IL FUNZIONAMENTO E UN COLLEGAMENTO AI 5V/MASSA IN BASE AL TIPO DI LED USATO**), per capire come collegare il led è sufficiente osservare lo schema tinkercad riportato sopra
- Successivamente prendere il seguente pezzo di codice e inserirlo tra le variabili dell'ultimo led RGB (nel caso del codice caricato qui su github led 2) e le altre variabili con questo frammento di codice in cui `X` rappresenta il numero identificativo del led (1,2,3,etc) e `x` il pin PWM (11,10,9,etc):
  ```yml
  //led rgb X
  int redX = x;
  int blueX = x;
  int greenX = x;
  ```
- Successivamente bisogna dichiarare i 3 nuovi pin come OUTPUT nel setup dello sketch, quindi è necessario incollare il seguente frammento di codice sotto l'ultimo pinMode che dichiara OUTPUT prima di quelli di input, in cui X è il numero identificativo assegnato sopra:
  ```yml
  pinMode(redX, OUTPUT);
  pinMode(blueX, OUTPUT);
  pinMode(greenX, OUTPUT);
  ```
  - Uno degli ultimi step riguarda l'utilizzo del led nella funzione e la sua eventuale attivazione se si volesse usare con un numero x di persone. In questo caso Per implementare l'abilitazione del led è sufficiente trovare la parentesi graffa dell'ultimo if per il controllo del numero di persone (prima anche di quella di chiusura del loop e prima del sistema di debug) e inserire questo frammento di codice in cui `y` è il numero di persone che si desidera e `X` è il numero identificativo (vedi sopra):
  ```yml
  if(persone>=y) {
      rgbLedDisplay(redX, blueX, greenX, 
                  random(256), random(256), random(256));
    }
  ```
**!Nel caso si volesse implementare il led insieme ad un altro è sufficiente copiare la funzione senza l'if, si avvisa inoltre di NON cambiare gli ultimi 3 parametri che sono dei random number generator che creano numeri compresi tra 0 e 255 in modo da far cambiare colore al led in automatico**
