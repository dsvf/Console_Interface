const char regnames[][11] = {
  "NRF_CONFIG","EN_AA     ","EN_RXADDR ","SETUP_AW  ","SETUP_RETR",
  "RF_CH     ","RF_SETUP  ","NRF_STATUS","OBSERVE_TX","CD        ",
  "RX_ADDR_P0","RX_ADDR_P1","RX_ADDR_P2","RX_ADDR_P3","RX_ADDR_P4",
  "RX_ADDR_P5","TX_ADDR   ","RX_PW_P0  ","RX_PW_P1  ","RX_PW_P2  ",
  "RX_PW_P3  ","RX_PW_P4  ","RX_PW_P5  ","FIFO_STATS","DYNPD     ",
  "FEATURE   "};

const char regnames_zero[][11] = {
  "NRF_CONFIG","EN_AA\0\0\0\0\0","EN_RXADDR\0","SETUP_AW\0\0","SETUP_RETR",
  "RF_CH\0\0\0\0\0","RF_SETUP\0\0","NRF_STATUS","OBSERVE_TX","CD\0\0\0\0\0\0\0\0",
  "RX_ADDR_P0","RX_ADDR_P1","RX_ADDR_P2","RX_ADDR_P3","RX_ADDR_P4",
  "RX_ADDR_P5","TX_ADDR\0\0\0","RX_PW_P0\0\0","RX_PW_P1\0\0","RX_PW_P2\0\0",
  "RX_PW_P3\0\0","RX_PW_P4\0\0","RX_PW_P5\0\0","FIFO_STATS","DYNPD\0\0\0\0\0",
  "FEATURE\0\0\0"};

const uint8_t NRF_CONFIG = 0x00;
const uint8_t EN_AA = 0x01;
const uint8_t EN_RXADDR = 0x02;
const uint8_t SETUP_AW = 0x03;
const uint8_t SETUP_RETR = 0x04;
const uint8_t RF_CH = 0x05;
const uint8_t RF_SETUP = 0x06;
const uint8_t NRF_STATUS = 0x07;
const uint8_t OBSERVE_TX = 0x08;
const uint8_t CD = 0x09;
const uint8_t RX_ADDR_P0 = 0x0A;
const uint8_t RX_ADDR_P1 = 0x0B;
const uint8_t RX_ADDR_P2 = 0x0C;
const uint8_t RX_ADDR_P3 = 0x0D;
const uint8_t RX_ADDR_P4 = 0x0E;
const uint8_t RX_ADDR_P5 = 0x0F;
const uint8_t TX_ADDR = 0x10;
const uint8_t RX_PW_P0 = 0x11;
const uint8_t RX_PW_P1 = 0x12;
const uint8_t RX_PW_P2 = 0x13;
const uint8_t RX_PW_P3 = 0x14;
const uint8_t RX_PW_P4 = 0x15;
const uint8_t RX_PW_P5 = 0x16;
const uint8_t FIFO_STATUS = 0x17;
const uint8_t DYNPD = 0x1C;
const uint8_t FEATURE = 0x1D;
