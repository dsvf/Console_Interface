#include "console_interface.h"
#include "Arduino.h"

char command[CMDLEN];
int args[NARGSMAX];
char line[LINELEN];
unsigned char counter = 0;
unsigned char option_triggered = 0;

// Grab serial data into a line buffer, wait for \n, tokenize and parse the line buffer
// into *command and args[]
bool parse_line() {
  if (Serial.available()) {
    line[counter] = Serial.read();
    if (counter == LINELEN - 1) {
      // Prohibit buffer overflows:
      // Cancel char collecting after LINELEN chars:
      Serial.println(F("Error: Line too long! Please retry."));
      counter = 0;
      memset(line, 0, LINELEN);
      return false;
    }
    // Gulp potential \r characters (MS Windows may send these)
    if (line[counter] == '\r') {
      line[counter] = '\0';
    }
    // Gulp the \n character, handle the line buffer, reset the line:
    if (line[counter] == '\n') {
      line[counter] = '\0';
      // Tokenize line buffer.
      // Pattern: command args0 args1 ...
      char *ptr = strtok(line, " ");
      // 1: copy sommand to "command" variable
      // TODO: this may not be necessary? It might be enough to set command = line, since strtok null-terminates the line
      // Well, this is necessary as long I clear the line buffer at the end of this function.
      // Also, strNcpy limits buffer overflow exploitation.
      strncpy(command, ptr, CMDLEN);
      ptr = strtok(NULL, " ");
      // Loop over the tokenizer output and grab (up to) 6 variables:
      for (int i = 0; i < NARGSMAX; i++) {
        if (ptr != NULL) {
          // Parsing with strtol:
          // Allows long datatypes, positive and negative numbers, and hex/decimal/octal numbers.
          args[i] = strtol(ptr, NULL, 0);
          ptr = strtok(NULL, " ");
        } else {
          // In case we want to store the number of arguments, read nargs here from the loop variable i
          // (Check for off-by-one errors)
          break;
        }
      }
      // "Arm" the option_triggered variable:
      option_triggered = 0;
      // If the command is "help", print the start of the Help string:
      if (strcasecmp(command, "help") == 0) {
        Serial.println("Available commands: ");
        // "help" is a valid command, so do not print "invalid command" at the end:
        option_triggered = 1;
      }
      // Clear the line, just in case...
      memset(line, 0, LINELEN);
      // Reset the counter:
      counter = 0;
      // "return true" signals to the loop that it can execute the OPTION handlers:
      return true;
    }
    counter++;
    return false;
  }
}