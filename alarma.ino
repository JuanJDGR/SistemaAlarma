/* Materia: Sistemas Programables
 * Nombre Practica: Alarma
 * Descripcion de la practica: cuando un elemento magnetico pase por el reedswith manda una señal y da alerta una alarma, activa el led y el buzzer despues 
 * suena una cancion y la alarma vuelve a normalidad 
 * Alumna: Juan de Dios Gutierrez Ramirez 
 */

#include <LiquidCrystal.h>              // incluimos la libreria de la pantalla lcd
LiquidCrystal lcd (1,2,     4,5,6,7);   //reconocemos los pines de uso
int contacto = 8;                       //pin del reed switch
int led = 9;                            //pin del led
int spk=10;                             // altavoz a GND 
int c[5]={131,262,523,1046,2093};       // frecuencias 4 octavas de Do
int cs[5]={139,277,554,1108,2217};      // Do#
int d[5]={147,294,587,1175,2349};       // Re
int ds[5]={156,311,622,1244,2489};      // Re#
int e[5]={165,330,659,1319,2637};       // Mi
int f[5]={175,349,698,1397,2794};       // Fa
int fs[5]={185,370,740,1480,2960};      // Fa#
int g[5]={196,392,784,1568,3136};       // Sol
int gs[5]={208,415,831,1661,3322};      // Sol#
int a[5]={220,440,880,1760,3520};       // La
int as[5]={233,466,932,1866,3729};      // La#
int b[5]={247,494,988,1976,3951};       // Si

void setup() {
  pinMode(contacto, INPUT);           //reed switch entrada
  pinMode(led, OUTPUT);               //led salida
  lcd.begin(16,2);                    // Reconocemos y empezamos el LCD
}

void loop() {
  
  if(digitalRead(contacto) == HIGH){  //Si deja de detectar el imán inicia secuencia
     
    for(int i = 0; i < 10; i++){      //Secuencia para que:
      digitalWrite(led, HIGH);        //el led parpadee 10 veces y tenga pausas de 200     
      lcd.setCursor (0,0);            // (Columna fila) 
      lcd.print("Alarma activada");   // imprimimos en la pantalla la palabra alarma en la primera fila
      delay(100);
      lcd.setCursor (0,1);            // (columna fila) 
      lcd.print ("Intruso");          // imprimimos en la pantalla la palabra intruso en la seguna fila 
      delay(100);
      tone(208,415,831);               //buzzer suena 10 veces y tenga pausas de 200
      delay(200);                     //el buzzer y el led comparten el mismo pin
      digitalWrite(led, LOW);
      delay(200);
      
  }
   //harry();                          //llamamos a la funcion que toca la cancion 
  lcd.clear();
  
  }else{
    digitalWrite(led, LOW);           //condición contraria se detiene secuencia
      tone(7,0,0);
      
  }
}

void nota(int frec, int t)
{
    tone(spk,frec);                     // suena la nota frec recibida
    delay(t);                           // para despues de un tiempo t
}

void harry(){
nota(b[2], 500);                      //nota y tiempo
nota(e[3],1000); 
nota(g[3], 250);
nota(fs[3],250);
nota(e[3],1000);
nota(b[3],500);
nota(a[3],1250);
nota(fs[3],1000);    
nota(b[2], 500);
nota(e[3],1000);
nota(g[3],250);  
nota(fs[3],250);
nota(d[3],1000);
nota(e[3],500 );
nota(b[2],1000 );    
noTone(led); delay(1000);   
nota(b[2], 500);
nota(e[3],1000);
nota(g[3], 250);
nota(fs[3],250);
nota(e[3],1000);
nota(b[3],500);
nota(d[4],1000);
nota(cs[4],500);
nota(c[4],1000);
nota(a[3],500);
nota(c[4],1000);
nota(b[3],250);
nota(as[3],250);
nota(b[2],1000);
nota(g[3],500);
nota(e[3],1000);
noTone(led); 
delay(2000); 
}
