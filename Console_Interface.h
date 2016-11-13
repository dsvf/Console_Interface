// console_interface:
// A collection of macros and helper functions to easily create an interactive serial session
// -> Define serial commands with the OPTION() and OPTIONx() macros
// -> Automatic help string generated

// OPTION macro: generate a new command option with the given string "NAME" (i.e. OPTION("write"))
// If the command is "help", prints the command name
// If the option_triggered-variable is set, skip the following block.
// If the command is equal to the given string, set the option_triggered-variable
// and execute the block that follows the macro.
#define OPTION(NAME) if(strcasecmp(command,"help")==0){\
    Serial.println(NAME);}\
  if (!option_triggered && (option_triggered = (strcasecmp(command, NAME) == 0)))

// OPTIONx macro: generate a new command option with the given string "NAME" which accepts n arguments (i.e. OPTIONx("write", 2))
// If the command is "help", prints the command name and the number of arguments expected (No checking!)
// If the option_triggered-variable is set, skip the following block.
// If the command is equal to the given string, set the option_triggered-variable
// and execute the block that follows the macro.
#define OPTIONx(NAME, N) if(strcasecmp(command,"help")==0){\
    Serial.print(NAME);for(int i=0;i<N;i++){Serial.print(" #int");}Serial.println();}\
  if (!option_triggered && (option_triggered = (strcasecmp(command, NAME) == 0)))

// OPTION_HELP macro: execute additional code if help is requested:
#define OPTION_HELP if(strcasecmp(command,"help")==0)

// Catch-all case if no option has triggered on a command.
// Example: OPTION_OTHER{Serial.println("Invalid command!");
#define OPTION_OTHER if(!option_triggered)

// Command names should be 19 letters or less.
#define CMDLEN 20
extern char command[CMDLEN];

// Commands can only have 6 or less arguments
#define NARGSMAX 6
extern int args[NARGSMAX];

// Commands+arguments should be shorter than 80 letters
#define LINELEN 80
// line buffer collects serial characters until a \n is detected
extern char line[LINELEN];

// counting the number of characters in the current line buffer:
extern unsigned char counter;

// TRUE if an option has matched, FALSE if not.
extern unsigned char option_triggered;

bool parse_line();
bool RETURN_FALSE();