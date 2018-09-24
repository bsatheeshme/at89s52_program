// Source: http://www.snrelectronicsblog.com/8051/8051-based-remote-for-home-appliance/
// Bootloader and Library Fnctions Starts Here //
#include <8051.h>
void setup();
void loop();
void main(){
    setup();
    while(1)loop();
}
// Bootloader and Library Fnctions Ends Here //
#define IR_PIN P3_0
void delayRC5(unsigned char p);
void processIR(unsigned char command);
__bit flipBit = 0;
__bit prevFlipBit = 0;
 
void setup(){
     
}
void loop(){
    unsigned char address = 0x00;
    unsigned char command = 0x00;
    unsigned char count=0x00;
    while(IR_PIN==1);   //Wait for first bit 
    delayRC5(7);        //Delay for 3.024ms
    flipBit=IR_PIN;     //Reading flip bit
    for(count=0;count<5;count++){
        delayRC5(4);    //Delay for 1.728ms
        address = address << 1;
        if(IR_PIN==1)
            address = address | 0x01;
    }
    for(count=0;count<6;count++){
        delayRC5(4);    //Delay for 1.728ms
        command = command << 1;
        if(IR_PIN==1)
            command = command | 0x01;
    }
    //P1 = command;
    if(address == 0x00 && flipBit != prevFlipBit){
        processIR(command);
        prevFlipBit = flipBit;
    }
}
void processIR(unsigned char command){
    if(command == 0x01){
        P1_1 = ! P1_1;
        P2_1 = ! P2_1;
    }else if(command == 0x02){
        P1_2 = ! P1_2;
        P2_2 = ! P2_2;
    }else if(command == 0x03){
        P1_3 = ! P1_3;
        P2_3 = ! P2_3;
    }else if(command == 0x04){
        P1_4 = ! P1_4;
        P2_4 = ! P2_4;
    }else if(command == 0x05){
        P1_5 = ! P1_5;
        P2_5 = ! P2_5;
    }else if(command == 0x06){
        P1_6 = ! P1_6;
        P2_6 = ! P2_6;
    }else if(command == 0x07){
        P1_7 = ! P1_7;
        P2_7 = ! P2_7;
    }
}
//delay for 432uS. For 3.024ms call 7 times and fro 1.728ms call 4 times //
void delayRC5(unsigned char r){ 
    unsigned char p;
    unsigned int q;
    for(p=0;p<r;p++)
        for(q=0;q<53;q++);   //Clock 11.0592MHz
}
