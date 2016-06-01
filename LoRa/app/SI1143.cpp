/*
 * SI1143.cpp
 *
 *  Created on: 18.05.2016
 *      Author: Adrian
 */

#include "SI1143.h"

SI1143::SI1143(I2C_RT* i2c) {
	setI2C(i2c);
}

SI1143::~SI1143() {
	// TODO Auto-generated destructor stub
}

void SI1143::init(){
	uint8_t writeValue = PARAM_WR;
	//	//Si114xWriteToRegister( si114x_handle, 0x08, 0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,0x08,false,&writeValue,1);
	//
	//
	//	//    Si114xWriteToRegister( si114x_handle, 0x09, 0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,0x09,false,&writeValue,1);
	//
	//
	//
	//
	//
	//	osDelay(50);
	//	//	  retval+=Si114xWriteToRegister(si114x_handle, REG_MEAS_RATE,  0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,MEAS_RATE,false,&writeValue,1);
	//	//	  retval+=Si114xWriteToRegister(si114x_handle, REG_ALS_RATE,   0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,ALS_RATE,false,&writeValue,1);
	//	//	  retval+=Si114xPauseAll(si114x_handle);
	//	//
	//	//
	//	//	  // The clearing of the registers could be redundant, but it is okay.
	//	//	  // This is to make sure that these registers are cleared.
	//	//	  retval+=Si114xWriteToRegister(si114x_handle, REG_MEAS_RATE,  0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,MEAS_RATE,false,&writeValue,1);
	//	//	  retval+=Si114xWriteToRegister(si114x_handle, REG_IRQ_ENABLE, 0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,IRQ_ENABLE,false,&writeValue,1);
	//	//	  retval+=Si114xWriteToRegister(si114x_handle, REG_IRQ_MODE1,  0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,IRQ_MODE1,false,&writeValue,1);
	//	//	  retval+=Si114xWriteToRegister(si114x_handle, REG_IRQ_MODE2,  0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,IRQ_MODE2,false,&writeValue,1);
	//	//	  retval+=Si114xWriteToRegister(si114x_handle, REG_INT_CFG  ,  0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,INT_CFG,false,&writeValue,1);
	//	//	  retval+=Si114xWriteToRegister(si114x_handle, REG_IRQ_STATUS, 0xFF);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,IRQ_STATUS,false,&writeValue,1);
	//	//
	//	//	  // Perform the Reset Command
	//	//	  retval+=Si114xWriteToRegister(si114x_handle, REG_COMMAND, 1);
	//	writeValue=0x01;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,COMMAND,false,&writeValue,1);
	//
	//	// Delay for 10 ms. This delay is needed to allow the Si114x
	//
	//	// to perform internal reset sequence.
	//	osDelay(10);
	//	// Write Hardware Key
	//	//	  retval+=Si114xWriteToRegister(si114x_handle, REG_HW_KEY, HW_KEY_VAL0);
	//	writeValue=0x17;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,HW_KEY,false,&writeValue,1);
	//
	//
	//
	//
	//
	//
	//	//    Si114xWriteToRegister( si114x_handle, 0x07, 0x17);
	//	writeValue=0x17;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,0x07,false,&writeValue,1);
	//	//    Si114xWriteToRegister( si114x_handle, REG_PS_LED21, 0x06);
	//	writeValue=0x66;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PS_LED21,false,&writeValue,1);
	//	//Si114xWriteToRegister( si114x_handle, REG_PS_LED3, 0x06);
	//	writeValue=0x06;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PS_LED3,false,&writeValue,1);
	//	//    Si114xParamSet( si114x_handle, PARAM_PS_ADC_GAIN, 0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_PS_ADC_GAIN,false,&writeValue,1);
	//	//    Si114xParamSet( si114x_handle, PARAM_PS_ADC_MISC, 0x04);
	//	writeValue=0x04;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_PS_ADC_MISC,false,&writeValue,1);
	//	//    Si114xParamSet( si114x_handle, PARAM_PSLED12_SELECT, 0x01);
	//	writeValue=0x01;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_PSLED12_SELECT,false,&writeValue,1);
	//	//    Si114xParamSet( si114x_handle, PARAM_PS1_ADC_MUX, 0x03);
	//	writeValue=0x03;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_PS1_ADCMUX,false,&writeValue,1);
	//	//    Si114xParamSet( si114x_handle, PARAM_PS2_ADC_MUX, 0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_PS2_ADCMUX,false,&writeValue,1);
	//	//    Si114xParamSet( si114x_handle, PARAM_PS3_ADC_MUX, 0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_PS3_ADCMUX,false,&writeValue,1);
	//	//    Si114xParamSet( si114x_handle, PARAM_ALSVIS_ADC_MISC, 0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_ALSVIS_ADC_MISC,false,&writeValue,1);
	//	//    Si114xParamSet( si114x_handle, PARAM_ALSVIS_ADC_GAIN, 0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_ALSVIS_ADC_GAIN,false,&writeValue,1);
	//	//    Si114xParamSet( si114x_handle, PARAM_ALSIR_ADC_MISC, 0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_ALSIR_ADC_MISC,false,&writeValue,1);
	//	//    Si114xParamSet( si114x_handle, PARAM_ALSIR_ADC_GAIN, 0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_ALSIR_ADC_GAIN,false,&writeValue,1);
	//	//    Si114xParamSet( si114x_handle, PARAM_IR_ADC_MUX, 0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_ALS_IR_ADCMUX,false,&writeValue,1);
	//	//    Si114xParamSet( si114x_handle, PARAM_CH_LIST, 0x31);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_CH_LIST,false,&writeValue,1);
	//	//    Si114xWriteToRegister( si114x_handle, REG_INT_CFG, 0x01);
	//	writeValue=0x01;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,INT_CFG,false,&writeValue,1);
	//	//    Si114xWriteToRegister( si114x_handle, REG_IRQ_ENABLE, 0x1d);
	//	writeValue=0x1d;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,IRQ_ENABLE,false,&writeValue,1);
	//	//    Si114xWriteToRegister( si114x_handle, REG_IRQ_MODE1, 0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,IRQ_MODE1,false,&writeValue,1);
	//	//    Si114xWriteToRegister( si114x_handle, REG_IRQ_MODE2, 0x00);
	//	writeValue=0x00;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,IRQ_MODE2,false,&writeValue,1);
	//	//    Si114xWriteToRegister( si114x_handle, REG_MEAS_RATE, 0x94);
	//	writeValue=0x94;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,MEAS_RATE,false,&writeValue,1);
	//	//    Si114xWriteToRegister( si114x_handle, REG_ALS_RATE, 0x08);
	//	writeValue=0x08;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,ALS_RATE,false,&writeValue,1);
	//	//    Si114xWriteToRegister( si114x_handle, REG_PS_RATE, 0x08);
	//	writeValue=0x08;
	//	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PS_RATE,false,&writeValue,1);
	writeValue=0x0b;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,COMMAND,false,&writeValue,1);

	writeValue=0x01;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,COMMAND,false,&writeValue,1);

	writeValue=0x00;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,INT_CFG,false,&writeValue,1);

	writeValue=0x00;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,IRQ_ENABLE,false,&writeValue,1);

	writeValue=0x00;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,IRQ_MODE1,false,&writeValue,1);

	writeValue=0x00;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,IRQ_MODE2,false,&writeValue,1);

	writeValue=0x17;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,HW_KEY,false,&writeValue,1);
	// LED 12
	writeValue=0xff;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,0x0f,false,&writeValue,1);
	// LED 3
	writeValue=0x0f;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,0x10,false,&writeValue,1);

	writeValue=0x07;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_CH_LIST,false,&writeValue,1);

	writeValue=0x10;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_PS_ADC_COUNTER,false,&writeValue,1);

	writeValue=0x00;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_ALSVIS_ADC_COUNTER,false,&writeValue,1);

	writeValue=0x00;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PARAM_ALSIR_ADC_COUNTER,false,&writeValue,1);

	writeValue=0x17;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,HW_KEY,false,&writeValue,1);

	writeValue=0x10;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,IRQ_ENABLE,false,&writeValue,1);

	writeValue=0x01;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,INT_CFG,false,&writeValue,1);

	writeValue=0x10;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,IRQ_ENABLE,false,&writeValue,1);

	writeValue=0x00 + (0x0<<4) + (0x0<<6);
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,IRQ_MODE1,false,&writeValue,1);

	writeValue=0x00;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,IRQ_MODE2,false,&writeValue,1);

	writeValue=0x80;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,MEAS_RATE,false,&writeValue,1);

	writeValue=0x08;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,PS_RATE,false,&writeValue,1);

	writeValue=0x08;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,ALS_RATE,false,&writeValue,1);

	writeValue=0x0F;
	i2c->write_RT(SI1143_DEFAULT_ADDRESS,COMMAND,false,&writeValue,1);
}

void SI1143::setI2C(I2C_RT* i2c){
	this->i2c = i2c;
}

int SI1143::getProximity(){
	uint8_t xProximityHighByte;
	uint8_t xProximityLowByte;
	uint8_t writeValue = PS_FORCE_cmd;

	i2c->write_RT(SI1143_DEFAULT_ADDRESS,COMMAND,false,&writeValue,1);
	osDelay(5);
	i2c->read_RT(SI1143_DEFAULT_ADDRESS,PS1_DATA0,false,
			&xProximityHighByte,1);

	i2c->read_RT(SI1143_DEFAULT_ADDRESS,PS1_DATA1,false,
			&xProximityLowByte,1);

	i2c->write_RT(SI1143_DEFAULT_ADDRESS,COMMAND,false,&writeValue,1);
	osDelay(5);
	i2c->read_RT(SI1143_DEFAULT_ADDRESS,PS2_DATA1,false,
			&xProximityHighByte,1);

	i2c->read_RT(SI1143_DEFAULT_ADDRESS,PS2_DATA0,false,
			&xProximityLowByte,1);

	i2c->write_RT(SI1143_DEFAULT_ADDRESS,COMMAND,false,&writeValue,1);
	osDelay(5);
	i2c->read_RT(SI1143_DEFAULT_ADDRESS,PS3_DATA1,false,
			&xProximityHighByte,1);

	i2c->read_RT(SI1143_DEFAULT_ADDRESS,PS3_DATA0,false,
			&xProximityLowByte,1);

	uint16_t Proximity = ((uint16_t)xProximityHighByte<<8)|((uint16_t)xProximityLowByte);

	return Proximity;

}
int SI1143::getLight(){
	uint8_t xLightHighByte;
	uint8_t xLightLowByte;

	i2c->read_RT(SI1143_DEFAULT_ADDRESS,ALS_VIS_DATA1,false,
			&xLightHighByte,1);

	i2c->read_RT(SI1143_DEFAULT_ADDRESS,ALS_VIS_DATA0,false,
			&xLightLowByte,1);

	uint16_t Proximity = ((uint16_t)xLightHighByte<<8)|((uint16_t)xLightLowByte);

	return Proximity;

}

int SI1143::getValue(){
	uint8_t Value;


	i2c->read_RT(SI1143_DEFAULT_ADDRESS,PS_LED21,false,
			&Value,1);


	return Value;

}
///**
// * @author Guillermo A Torijano
// *
// * @section LICENSE
// *
// * Permission is hereby granted, free of charge, to any person obtaining a copy
// * of this software and associated documentation files (the "Software"), to deal
// * in the Software without restriction, including without limitation the rights
// * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// * copies of the Software, and to permit persons to whom the Software is
// * furnished to do so, subject to the following conditions:
// *
// * The above copyright notice and this permission notice shall be included in
// * all copies or substantial portions of the Software.
// *
// * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// * THE SOFTWARE.
// *
// * @section DESCRIPTION
// *
// * Parallax SI1143 Gesture Sensor.
// *
// * Datasheet:
// *
// * http://www.silabs.com/Support%20Documents/TechnicalDocs/Si114x.pdf
// */
//
//#include "SI1143.h"
//
//SI1143::SI1143(I2C* comm)
//{
//    wait_ms(30);
//
//    //on = new DigitalOut(vcc);
////    en = new DigitalOut(enable);
////
////    on->write(0);
////    en->write(0);
//    wait_ms(30);
//
//    adrs = IR_ADDRESS;
//    i2c_ = comm;
//
//    //restart(offset);
//}
//
//void SI1143::restart(char offset)
//{
//    //DigitalOut l3(LED3);
//  //  l3 = 0;
//
//    wait_ms(30);
//    //on->write(1);
//    wait_ms(30);
//    //en->write(1);
//    wait_ms(30);
//
//    //printf("%d\r\n",adrs);
//
//    command(RESET);
////    l3 = 1;
//    wait_ms(30);
//    //Do this because you have to
//    write_reg(HW_KEY,HW_KEY_VAL0);
//    //Give new address
//    write_reg(PARAM_WR, adrs + offset);
//    //write_reg(PARAM_WR, ALS_IR_TASK + ALS_VIS_TASK + PS1_TASK + PS2_TASK + PS3_TASK);
//    command(PARAM_SET + (I2C_ADDR & 0x1F));
//
//    //set new address
//    command(BUSADDR);
//
//    adrs = adrs + offset;
//
//    // Setting up LED Power to FULL JUICE
//    write_reg(PS_LED21,0xCC); // Was 0x0A
//    write_reg(PS_LED3,0x00);
//
//    //Activate ALS_IR, ALS_VIS, and PS1
//    write_reg(PARAM_WR, ALS_IR_TASK + ALS_VIS_TASK + PS1_TASK + PS2_TASK);
//    //write_reg(PARAM_WR, ALS_IR_TASK + ALS_VIS_TASK + PS1_TASK + PS2_TASK + PS3_TASK);
//    command(PARAM_SET + (CHLIST & 0x1F));
//
//    /*
//    // Set PS_RANGE to high signal range
//    write_reg(PARAM_WR, 0x04); // 0x24 for high signal, 0x04 for normal
//    command(PARAM_SET + (PS_ADC_MISC & 0x1F));
//    */
//    //Set PS_ADC_COUNTER to lower time between ADC samples
//    write_reg(PARAM_WR, 0x07);
//    command(PARAM_SET + (PS_ADC_COUNTER & 0x1F));
//
//    //Turn up the juice on PS ACD GAIN!
//    write_reg(PARAM_WR, 0x00);
//    command(PARAM_SET + (PS_ADC_GAIN & 0x1F));
//
//
//    write_reg(INT_CFG,0x01); // Configure Interrupts
//    write_reg(IRQ_ENABLE,0x0C); // Enable PS1 (0x04) Enable PS1 & PS2 (0x0C)
//    write_reg(IRQ_MODE1,0);
//    write_reg(IRQ_MODE2,0);
//
//    write_reg(MEAS_RATE,0xA0); //0x84 - wakes up every 10 ms
//    write_reg(PS_RATE,0x08); //0x8 - wakes up every time measurement clock wakes up
//
//    //write_reg(PS_ADC_MISC,0x24);
//    //write_reg(PS1_ADCMUX,0x03);
//}
//
//void SI1143::command(char cmd)
//{
//    int val;
// //   DigitalOut l2(LED2);
//
//    val = read_reg(RESPONSE,1);
//    while(val!=0)
//    {
//        write_reg(COMMAND,NOP);
//        val = read_reg(RESPONSE,1);
//        //l2 = 1;
//    }
////    l2 = 0;
//    do{
//        write_reg(COMMAND,cmd);
//        if(cmd==RESET) break;
//        val = read_reg(RESPONSE,1);
//    }while(val==0);
//}
//
//char SI1143::read_reg(/*unsigned*/ char address, int num_data) // Read a register
//{
//    char tx[1];
//    char rx[1];
//
//    //i2c_->start();
//    tx[0] = address;
//    i2c_->write((adrs << 1) & 0xFE, tx, num_data);
//    wait_ms(1);
//    //i2c_->stop();
//
//    //i2c_->start();
//    i2c_->read((adrs << 1) | 0x01, rx, num_data);
//    wait_ms(1);
//    //i2c_->stop();
//
//    return rx[0];
//}
//
//void SI1143::write_reg(char address, char num_data) // Write a resigter
//{
//    char tx[2];
//
//    //i2c_->start();
//    tx[0] = address;
//    tx[1] = num_data;
//    i2c_->write((adrs << 1) & 0xFE, tx, 2);
//    wait_ms(1);
//    //i2c_->stop();
//}
//
//void SI1143::bias(int ready, int repeat)
//{
//    wait(ready);
//    //bias1 = get_ps1(repeat);
//    bias1 = 0;
//    bias2 = 0;
//    bias3 = get_ps3(repeat);
//}
//
//int SI1143::get_ps1(int repeat) // Read the data for the first LED (Used in forced mode)
//{
//    int stack = 0;
//
//    command(PSALS_FORCE);
//
//    for(int r=repeat; r>0; r=r-1)
//    {
//        LowB = read_reg(PS1_DATA0,1);
//        HighB = read_reg(PS1_DATA1,1);
//        stack = stack + (HighB * 256) + LowB;
//    }
//    PS1 = stack / repeat;
//
//    if(PS1 > bias1)
//        PS1 = PS1 - bias1;
//    else
//        PS1 = 0;
//
//    return PS1;
//}
//
//void SI1143::start_ps_auto()
//{
//    command(PS_AUTO);
//}
//
//int SI1143::read_ps1() // Read the data for the first LED (Used in autonomous mode)
//{
//
//
//    LowB = read_reg(PS1_DATA0,1);
//    HighB = read_reg(PS1_DATA1,1);
//    PS1 = (HighB * 256) + LowB;
//
//    if(PS1 > bias1)
//        PS1 = PS1 - bias1;
//    else
//        PS1 = 0;
//
//    return PS1;
//}
//
//int SI1143::get_ps2(int repeat) // Read the data for the second LED
//{
//    int stack = 0;
//
//    command(PSALS_FORCE);
//
//    for(int r=repeat; r>0; r=r-1)
//    {
//        LowB = read_reg(PS2_DATA0,1);
//        HighB = read_reg(PS2_DATA1,1);
//        stack = stack + (HighB * 256) + LowB;
//    }
//    PS2 = stack / repeat;
//
//    if(PS2 > bias2)
//        PS2 = PS2 - bias2;
//    else
//        PS2 = 0;
//
//    return PS2;
//}
//
//int SI1143::read_ps2() // Read the data for the first LED (Used in autonomous mode)
//{
//
//    LowB = read_reg(PS2_DATA0,1);
//    HighB = read_reg(PS2_DATA1,1);
//    PS2 = (HighB * 256) + LowB;
//
//    if(PS2 > bias2)
//        PS2 = PS2 - bias2;
//    else
//        PS2 = 0;
//
//    return PS2;
//}
//
//int SI1143::get_ps3(int repeat) // Read the data for the third LED
//{
//    int stack = 0;
//
//    command(PSALS_FORCE);
//
//    for(int r=repeat; r>0; r=r-1)
//    {
//        LowB = read_reg(PS3_DATA0,1);
//        HighB = read_reg(PS3_DATA1,1);
//        stack = stack + (HighB * 256) + LowB;
//    }
//    PS3 = stack / repeat;
//
//    if(PS3 > bias3)
//        PS3 = PS3 - bias3;
//    else
//        PS3 = 0;
//
//    return PS3;
//}
//
//int SI1143::get_vis(int repeat) // Read the data for ambient light
//{
//    int stack = 0;
//
//    command(PSALS_FORCE);
//
//    for(int r=repeat; r>0; r=r-1)
//    {
//        LowB = read_reg(ALS_VIS_DATA0,1);
//        HighB = read_reg(ALS_VIS_DATA1,1);
//        VIS = stack + (HighB * 256) + LowB;
//    }
//    VIS = stack / repeat;
//
//    return VIS;
//}
//
//int SI1143::get_ir(int repeat) // Read the data for infrared light
//{
//    int stack = 0;
//
//    command(PSALS_FORCE);
//
//    for(int r=repeat; r>0; r=r-1)
//    {
//        LowB = read_reg(ALS_IR_DATA0,1);
//        HighB = read_reg(ALS_IR_DATA1,1);
//        IR = stack + (HighB * 256) + LowB;
//    }
//    IR = stack / repeat;
//
//    return IR;
//}
//
//void SI1143::clear_int() // Clear Interrupt register when an interrupt occurs.
//{
//    write_reg(IRQ_STATUS, 0x3F); // Writes one to every interrupt status, thereby clearing them
//}
//
//char SI1143::read_PSint() // Clear Interrupt register when an interrupt occurs.
//{
//    char tmp;
//    char res;
//
////    DigitalOut led3a(LED3);
////    DigitalOut led4a(LED4);
//
//    tmp = read_reg(IRQ_STATUS, 1); // Reads iterrupt register
//    if( (tmp & 0x0C) == 0x0C ){
//        res = INT_PS12;
//    }
//    else if( (tmp & 0x0C) == 0x04 ){
//        res = INT_PS1;
//    }
//    else if( (tmp & 0x0C) == 0x08 ){
//        res = INT_PS2;
//    }
//    else {
//        res = 0;
//    }
//    return res;
//
//}


