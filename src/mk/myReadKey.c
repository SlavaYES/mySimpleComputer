#include "myReadKey.h"

struct termios new_term_state;
struct termios termState;
struct termios origin;

int compare(char *buf, char *sym) {
    if (strncmp(buf, sym, 1) == 0) {
        return 1;
    } else return 0;
}

int rk_readKey(enum Key *key) {

    int term = open(TERM, O_RDWR);
    char buf[8];
    
    
    buf[7] = 0;
    tcgetattr(0, &origin);
    //rk_myTermRegime(&new_term_state, 0, 0, 1, 0, 1);
    new_term_state = termState;
    rk_myTermRegime(&new_term_state, 0, 1, 1, 0, 0);

    int num = read(term, &buf, 4);
    
    if (num < 0) {
        FILE *file = fopen("globalhs.txt", "wt");
        putc('N', file);
        fclose(file);
    }   else {
        FILE *file = fopen("globalht.txt", "wt");
        putc('Y', file);
        fprintf(file, "%s", buf);
        fclose(file);
    }
    
    *key = NONE;
    if (compare(buf, "l")) { *key = KLOAD; }
    if (compare(buf, "s")) { *key = SAVE; }
    if (compare(buf, "r")) { *key = RUN; }
    if (compare(buf, "t")) { *key = STEP; }
    if (compare(buf, "i")) { *key = RESET; }
    if (compare(buf, "q")) { *key = EXIT; }
    if (compare(buf, "a")) { *key = F5; }
    if (compare(buf, "c")) { *key = F6; }
    if (strcmp(buf, "\E[15~") == 0) { *key = F5; }
    if (strcmp(buf, "\E[17~") == 0) { *key = F6; }
    if (strcmp(buf, "\E[A") == 0) { *key = UP; }
    if (strcmp(buf, "\E[B") == 0) { *key = DOWN; }
    if (strcmp(buf, "\E[C") == 0) { *key = RIGHT; }
    if (strcmp(buf, "\E[D") == 0) { *key = LEFT; }
    if (strcmp(buf, "m") == 0) { *key = CONS; }

    //tcsetattr(0, TCSANOW, &origin);
    rk_myTermRegime(&new_term_state, 1, 0, 0, 1, 1);
    close(term);
    return 0;
}

int rk_myTermSave(struct termios *termState) {
    return tcgetattr(0, termState);
}

int rk_myTermRestore(struct termios *currState) {
    return tcsetattr(0, TCSADRAIN, &termState);
}

int rk_myTermRegime(struct termios *currState, int regime, 
                    int vtime, int vmin, int echo, int sigint) {
	if (regime < 0 || regime > 1 || 
            echo < 0 || echo > 1 || 
            sigint < 0 || sigint > 1) return -1;

	struct termios newTermState = *currState;

    if (regime == 1) {
        newTermState.c_lflag |= ICANON;
    } else {
        newTermState.c_lflag &= ~ICANON;
    }
    if (echo == 1) {
        newTermState.c_lflag |= ECHO;
    } else {
        newTermState.c_lflag &= ~ECHO;
    }
    if (sigint == 1) {
        newTermState.c_lflag |= ISIG;
    } else {
        newTermState.c_lflag &= ~ISIG;
    }
    newTermState.c_cc [VMIN]  = vmin;
    newTermState.c_cc [VTIME] = vtime;
	tcsetattr(0, TCSADRAIN, &newTermState);

	return 0;
}

void termInit() {
    rk_myTermSave(&termState);
}