
#include "config_header.h"

//DIRECTIVES SECTION
#define _XTAL_FREQ 16000000

//DATA TYPES SECTION

//ISR for high priority
__interrupt( high_priority ) void high_isr( void ){
    Nop( ); //Function to consume one Instruction Cycle
}
//ISR for low priority
__interrupt( low_priority ) void low_isr( void ){
    Nop( ); //Function to consume one Instruction Cycle
}
//FUNCTIONS DELCARATION
void delay (void); 
void portsInit( void ); //ports function is declared
     //delay function
//MAIN SECTION
void main( void ) {
    //CONFIGURATIONS
    portsInit();
    //INFINITE CYCLE
    while( 1 ){
        //Set las entradas para hacer las lecturas de la primera fila (123A)
        LATBbits.LATB0 = 0;
        LATBbits.LATB1 = 1;
        LATBbits.LATB2 = 1;
        LATBbits.LATB3 = 1;
        
        if (PORTBbits.RB4 == 0){ //Presionada la tecla 1
            
            LATD = (LATD << 4);  //Correr el valor actual del least significant nibble al most significant
            LATD = LATD | 1;     //Mascara OR usada para escribir el valor en el least significant nibble sin tocar el segundo nibble
            delay();
            
        }
        else if (PORTBbits.RB5 == 0){ //Presionada la tecla 2
            
            LATD = (LATD << 4);
            LATD = LATD | 2;
            delay();
             
        }
        else if (PORTBbits.RB6 == 0){ //Presionada la tecla 3
            LATD = (LATD << 4);      
            LATD = LATD | 3;
            
             delay();
        }
        else if (PORTBbits.RB7 == 0){ //Presionada la tecla A
            LATD = (LATD << 4);      
            LATD = LATD | 10;
             delay();
        }
        
       //Set las entradas para hacer las lecturas de la segunda fila (456B)
        LATBbits.LATB0 = 1;
        LATBbits.LATB1 = 0;
        LATBbits.LATB2 = 1;
        LATBbits.LATB3 = 1;
        if (PORTBbits.RB4 == 0){ //Presionada la tecla 4
            LATD = (LATD << 4);
            LATD = LATD | 4;
             delay();
        }
        else if (PORTBbits.RB5 == 0){ //Presionada la tecla 5
            LATD = (LATD << 4);
            LATD = LATD | 5;
             delay();
        }
        else if (PORTBbits.RB6 == 0){ //Presionada la tecla 6
            LATD = (LATD << 4);
            LATD = LATD | 6;
             delay();
        }
        else if (PORTBbits.RB7 == 0){ //Presionada la tecla B
            LATD = (LATD << 4);
            LATD = LATD | 11;
             delay();
        }
        
        //Set las entradas para hacer las lecturas de la tercera fila (789C)
        LATBbits.LATB0 = 1;
        LATBbits.LATB1 = 1;
        LATBbits.LATB2 = 0;
        LATBbits.LATB3 = 1;
        if (PORTBbits.RB4 == 0){ //Presionada la tecla 7
            LATD = (LATD << 4);
            LATD = LATD | 7;
             delay();
        }
        else if (PORTBbits.RB5 == 0){ //Presionada la tecla 8
            LATD = (LATD << 4);
            LATD = LATD | 8;
             delay();
        }
        else if (PORTBbits.RB6 == 0){ //Presionada la tecla 9
            LATD = (LATD << 4);
            LATD = LATD | 9;
             delay();
        }
        else if (PORTBbits.RB7 == 0){ //Presionada la tecla C
            LATD = (LATD << 4);
            LATD = LATD | 12;
             delay();
        }
        
        //Set las entradas para hacer las lecturas de la cuarta fila (*0#D)
        LATBbits.LATB0 = 1;
        LATBbits.LATB1 = 1;
        LATBbits.LATB2 = 1;
        LATBbits.LATB3 = 0;
        if (PORTBbits.RB4 == 0){ //Presionada la tecla * = 13
            LATD = (LATD << 4);
            LATD = LATD | 13;
             delay();
        }
        else if (PORTBbits.RB5 == 0){ //Presionada la tecla 0
            LATD = (LATD << 4);
            LATD = LATD | 0;
             delay();
        }
        else if (PORTBbits.RB6 == 0){ //Presionada la tecla # = 14
            LATD = (LATD << 4);
            LATD = LATD | 14;
             delay();
        }
        else if (PORTBbits.RB7 == 0){ //Presionada la tecla D = 15
            LATD = (LATD << 4);
            LATD = LATD | 15;
             delay();
        }
    }
}

void delay (void){
    for (int i=0; i<10; i++)
        __delay_ms (10);
}

// FUNCTIONS SECTION
void portsInit( void ) {
    ANSELB = 0;          // PortB pins digital
    TRISB = 0b11110000;   // RB0-RB3 outputs RB4-RB7 inputs
    WPUB = 0b11110000;    // Pull up resistor connected
    INTCON2bits.RBPU = 0; // Pull-UP Enable 
    ANSELD = 0;           // PortD pins digital
    TRISD = 0;            // PortD pins outputs
    LATD = 0;             // Clear binary counter
    
}
