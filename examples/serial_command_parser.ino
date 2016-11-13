#include "nrf24l01_consts.h"
#include "console_interface.h"

char text[255];

void setup() {
  Serial.begin(115200);
  Serial.println("Serial command parser example.\nEnter \"help\" or commands.");
}

void loop() {
  if (parse_line()) {
    OPTIONx("readreg", 1){readreg();}
    OPTIONx("rr", 1){readreg();}
    OPTIONx("writereg", 2){writereg();}
    OPTION_OTHER{
      snprintf(text,255,"Entry %s is no valid command. Enter \"help\" for valid commands.\n",command);
      Serial.print(text);
    }
    OPTION_HELP{
      snprintf(text,255,"Help that may be relevant for commands.\n");
      Serial.print(text);
    }
  }
}

void readreg() {
  int reg = args[0];
  uint8_t data = random(255);
  snprintf(text, 255, "R: Register 0x%02X (%s): %d (0x%02X)\n", reg, regnames_zero[reg], data, data);
  Serial.print(text);
}

void writereg() {
  int reg = args[0];
  int data = args[1];
  snprintf(text, 255, "W: Register 0x%02X (%s) <-- %d (0x%02X)\n", reg, regnames_zero[reg], data, data);
  Serial.print(text);
}
